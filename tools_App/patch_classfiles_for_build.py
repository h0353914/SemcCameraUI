#!/usr/bin/env python3
"""
Patch .class files during Gradle build pipeline.
Integrated into the build via Gradle task (not a post-processing script).

Operations:
1. Patch R.jar: add SourceFile "R.java", set constructor to public, add LineNumberTable
2. Strip SourceFile from GMS .class files (com/google/**)

Usage:
  python3 patch_classfiles_for_build.py --patch-rjar <R.jar> --metadata <r_class_metadata.json>
  python3 patch_classfiles_for_build.py --strip-source <classes_dir> --prefix com/google/
"""
import struct
import os
import sys
import json
import zipfile
import io
import argparse
import shutil


# ─── Java Class File Constants ────────────────────────────────────
JAVA_MAGIC = 0xCAFEBABE

# Constant pool tag types
CONSTANT_Utf8 = 1
CONSTANT_Integer = 3
CONSTANT_Float = 4
CONSTANT_Long = 5
CONSTANT_Double = 6
CONSTANT_Class = 7
CONSTANT_String = 8
CONSTANT_Fieldref = 9
CONSTANT_Methodref = 10
CONSTANT_InterfaceMethodref = 11
CONSTANT_NameAndType = 12
CONSTANT_MethodHandle = 15
CONSTANT_MethodType = 16
CONSTANT_InvokeDynamic = 18

# Access flags
ACC_PUBLIC = 0x0001
ACC_PRIVATE = 0x0002

# ─── Class File Parser/Writer ─────────────────────────────────────

class ClassFile:
    """Minimal Java class file parser/writer for targeted bytecode modifications."""
    
    def __init__(self, data):
        self.data = bytearray(data)
        self.pos = 0
        self._parse()
    
    def _u1(self):
        v = self.data[self.pos]
        self.pos += 1
        return v
    
    def _u2(self):
        v = struct.unpack_from('>H', self.data, self.pos)[0]
        self.pos += 2
        return v
    
    def _u4(self):
        v = struct.unpack_from('>I', self.data, self.pos)[0]
        self.pos += 4
        return v
    
    def _bytes(self, n):
        v = bytes(self.data[self.pos:self.pos + n])
        self.pos += n
        return v
    
    def _parse(self):
        self.pos = 0
        
        # Magic, version
        self.magic = self._u4()
        assert self.magic == JAVA_MAGIC, f"Not a class file: magic=0x{self.magic:08x}"
        self.minor_version = self._u2()
        self.major_version = self._u2()
        
        # Constant pool
        self.constant_pool_count = self._u2()
        self.constant_pool = [None]  # 1-indexed
        i = 1
        while i < self.constant_pool_count:
            tag = self._u1()
            if tag == CONSTANT_Utf8:
                length = self._u2()
                value = self._bytes(length).decode('utf-8', errors='replace')
                self.constant_pool.append(('Utf8', value))
            elif tag == CONSTANT_Integer:
                self.constant_pool.append(('Integer', self._u4()))
            elif tag == CONSTANT_Float:
                self.constant_pool.append(('Float', self._u4()))
            elif tag == CONSTANT_Long:
                high = self._u4()
                low = self._u4()
                self.constant_pool.append(('Long', (high << 32) | low))
                self.constant_pool.append(None)  # Long takes 2 slots
                i += 1
            elif tag == CONSTANT_Double:
                high = self._u4()
                low = self._u4()
                self.constant_pool.append(('Double', (high << 32) | low))
                self.constant_pool.append(None)  # Double takes 2 slots
                i += 1
            elif tag == CONSTANT_Class:
                self.constant_pool.append(('Class', self._u2()))
            elif tag == CONSTANT_String:
                self.constant_pool.append(('String', self._u2()))
            elif tag in (CONSTANT_Fieldref, CONSTANT_Methodref, CONSTANT_InterfaceMethodref):
                names = {9: 'Fieldref', 10: 'Methodref', 11: 'InterfaceMethodref'}
                class_idx = self._u2()
                nat_idx = self._u2()
                self.constant_pool.append((names[tag], class_idx, nat_idx))
            elif tag == CONSTANT_NameAndType:
                name_idx = self._u2()
                desc_idx = self._u2()
                self.constant_pool.append(('NameAndType', name_idx, desc_idx))
            elif tag == CONSTANT_MethodHandle:
                kind = self._u1()
                idx = self._u2()
                self.constant_pool.append(('MethodHandle', kind, idx))
            elif tag == CONSTANT_MethodType:
                self.constant_pool.append(('MethodType', self._u2()))
            elif tag == CONSTANT_InvokeDynamic:
                bootstrap = self._u2()
                nat = self._u2()
                self.constant_pool.append(('InvokeDynamic', bootstrap, nat))
            else:
                raise ValueError(f"Unknown constant pool tag: {tag} at position {self.pos-1}")
            i += 1
        
        # Access flags, this/super class, interfaces
        self.access_flags = self._u2()
        self.this_class = self._u2()
        self.super_class = self._u2()
        self.interfaces_count = self._u2()
        self.interfaces = [self._u2() for _ in range(self.interfaces_count)]
        
        # Fields
        self.fields_count = self._u2()
        self.fields = []
        for _ in range(self.fields_count):
            self.fields.append(self._parse_member())
        
        # Methods
        self.methods_count = self._u2()
        self.methods = []
        for _ in range(self.methods_count):
            self.methods.append(self._parse_member())
        
        # Class attributes
        self.attributes_count = self._u2()
        self.attributes = []
        for _ in range(self.attributes_count):
            self.attributes.append(self._parse_attribute())
    
    def _parse_member(self):
        access = self._u2()
        name_idx = self._u2()
        desc_idx = self._u2()
        attr_count = self._u2()
        attrs = [self._parse_attribute() for _ in range(attr_count)]
        return {
            'access': access,
            'name_idx': name_idx,
            'descriptor_idx': desc_idx,
            'attributes': attrs,
        }
    
    def _parse_attribute(self):
        name_idx = self._u2()
        length = self._u4()
        data = self._bytes(length)
        return {
            'name_idx': name_idx,
            'data': data,
        }
    
    def get_utf8(self, idx):
        """Get UTF-8 string from constant pool."""
        entry = self.constant_pool[idx]
        if entry and entry[0] == 'Utf8':
            return entry[1]
        return None
    
    def find_utf8(self, value):
        """Find UTF-8 constant pool index, or -1 if not found."""
        for i, entry in enumerate(self.constant_pool):
            if entry and entry[0] == 'Utf8' and entry[1] == value:
                return i
        return -1
    
    def add_utf8(self, value):
        """Add UTF-8 entry to constant pool and return its index."""
        # Check if already exists
        idx = self.find_utf8(value)
        if idx >= 0:
            return idx
        idx = len(self.constant_pool)
        self.constant_pool.append(('Utf8', value))
        self.constant_pool_count += 1
        return idx
    
    def get_source_file(self):
        """Get current SourceFile attribute value, or None."""
        for attr in self.attributes:
            name = self.get_utf8(attr['name_idx'])
            if name == 'SourceFile':
                idx = struct.unpack('>H', attr['data'])[0]
                return self.get_utf8(idx)
        return None
    
    def set_source_file(self, filename):
        """Set or add SourceFile attribute."""
        sf_name_idx = self.add_utf8('SourceFile')
        sf_value_idx = self.add_utf8(filename)
        new_data = struct.pack('>H', sf_value_idx)
        
        # Update existing or add new
        for attr in self.attributes:
            name = self.get_utf8(attr['name_idx'])
            if name == 'SourceFile':
                attr['name_idx'] = sf_name_idx
                attr['data'] = new_data
                return
        
        # Add new attribute
        self.attributes.append({
            'name_idx': sf_name_idx,
            'data': new_data,
        })
        self.attributes_count += 1
    
    def remove_source_file(self):
        """Remove SourceFile attribute if present."""
        new_attrs = []
        for attr in self.attributes:
            name = self.get_utf8(attr['name_idx'])
            if name != 'SourceFile':
                new_attrs.append(attr)
        if len(new_attrs) != len(self.attributes):
            self.attributes = new_attrs
            self.attributes_count = len(new_attrs)
            return True
        return False
    
    def set_init_public(self):
        """Change <init> method from private to public."""
        for method in self.methods:
            name = self.get_utf8(method['name_idx'])
            if name == '<init>':
                if method['access'] & ACC_PRIVATE:
                    method['access'] = (method['access'] & ~ACC_PRIVATE) | ACC_PUBLIC
                    return True
        return False
    
    def strip_clinit_public(self):
        """Remove ACC_PUBLIC from <clinit> if present (original has just ACC_STATIC)."""
        ACC_STATIC = 0x0008
        for method in self.methods:
            name = self.get_utf8(method['name_idx'])
            if name == '<clinit>':
                if method['access'] & ACC_PUBLIC:
                    method['access'] = method['access'] & ~ACC_PUBLIC
                    return True
        return False
    
    def add_clinit_line_numbers(self, line_numbers):
        """Add LineNumberTable to <clinit> method's Code by matching newarray offsets.
        
        Scans bytecode for 'newarray 10' (int[]) instructions and maps each to
        the corresponding line number from the metadata.
        Returns True if LineNumberTable was added.
        """
        if not line_numbers:
            return False
        
        for method in self.methods:
            name = self.get_utf8(method['name_idx'])
            if name != '<clinit>':
                continue
            
            for attr in method['attributes']:
                attr_name = self.get_utf8(attr['name_idx'])
                if attr_name != 'Code':
                    continue
                
                code_data = bytearray(attr['data'])
                code_len = struct.unpack_from('>I', code_data, 4)[0]
                code = code_data[8:8 + code_len]
                
                # Find all newarray 10 (int[]) offsets
                newarray_offsets = []
                for i in range(len(code) - 1):
                    if code[i] == 0xBC and code[i + 1] == 0x0A:
                        # Use the offset of the push-size instruction BEFORE newarray
                        # to match dx's line mapping behavior (line maps to new-array in DEX)
                        if i >= 1 and 0x03 <= code[i - 1] <= 0x08:
                            push_offset = i - 1  # iconst_N (1 byte)
                        elif i >= 2 and code[i - 2] == 0x10:
                            push_offset = i - 2  # bipush (2 bytes)
                        elif i >= 3 and code[i - 3] == 0x11:
                            push_offset = i - 3  # sipush (3 bytes)
                        else:
                            push_offset = i  # fallback to newarray itself
                        newarray_offsets.append(push_offset)
                
                if len(newarray_offsets) != len(line_numbers):
                    return False  # Mismatch — skip
                
                # Check if LineNumberTable already exists in Code sub-attrs
                p = 8 + code_len
                exc_len = struct.unpack_from('>H', code_data, p)[0]
                p += 2 + exc_len * 8
                code_attr_count_pos = p
                code_attr_count = struct.unpack_from('>H', code_data, p)[0]
                p += 2
                for _ in range(code_attr_count):
                    ca_name_idx = struct.unpack_from('>H', code_data, p)[0]
                    p += 2
                    ca_len = struct.unpack_from('>I', code_data, p)[0]
                    p += 4
                    if self.get_utf8(ca_name_idx) == 'LineNumberTable':
                        return False  # Already exists
                    p += ca_len
                
                # Build LineNumberTable
                lnt_name_idx = self.add_utf8('LineNumberTable')
                lnt_data = struct.pack('>H', len(line_numbers))
                for offset, line in zip(newarray_offsets, line_numbers):
                    lnt_data += struct.pack('>HH', offset, line)
                
                lnt_attr = struct.pack('>H', lnt_name_idx)
                lnt_attr += struct.pack('>I', len(lnt_data))
                lnt_attr += lnt_data
                
                # Increment Code sub-attribute count and append
                struct.pack_into('>H', code_data, code_attr_count_pos, code_attr_count + 1)
                code_data.extend(lnt_attr)
                attr['data'] = bytes(code_data)
                return True
        
        return False

    def add_init_line_number(self, line_number):
        """Add LineNumberTable to <init> method's Code attribute."""
        for method in self.methods:
            name = self.get_utf8(method['name_idx'])
            if name != '<init>':
                continue
            
            # Find Code attribute
            for attr in method['attributes']:
                attr_name = self.get_utf8(attr['name_idx'])
                if attr_name != 'Code':
                    continue
                
                # Parse Code attribute:
                # max_stack(2) + max_locals(2) + code_length(4) + code(code_length)
                # + exception_table_length(2) + exception_table(...)
                # + attributes_count(2) + attributes(...)
                code_data = bytearray(attr['data'])
                p = 0
                max_stack = struct.unpack_from('>H', code_data, p)[0]; p += 2
                max_locals = struct.unpack_from('>H', code_data, p)[0]; p += 2
                code_length = struct.unpack_from('>I', code_data, p)[0]; p += 4
                p += code_length  # skip bytecode
                exception_table_length = struct.unpack_from('>H', code_data, p)[0]; p += 2
                p += exception_table_length * 8  # each entry is 8 bytes
                
                # Now at attributes of Code
                code_attr_count = struct.unpack_from('>H', code_data, p)[0]
                code_attr_start = p
                p += 2
                
                # Check if LineNumberTable already exists
                has_lnt = False
                for _ in range(code_attr_count):
                    ca_name_idx = struct.unpack_from('>H', code_data, p)[0]; p += 2
                    ca_length = struct.unpack_from('>I', code_data, p)[0]; p += 4
                    ca_name = self.get_utf8(ca_name_idx)
                    if ca_name == 'LineNumberTable':
                        has_lnt = True
                    p += ca_length
                
                if has_lnt:
                    return False  # Already has line numbers

                # Add LineNumberTable attribute
                lnt_name_idx = self.add_utf8('LineNumberTable')
                # LineNumberTable format:
                # line_number_table_length(2) 
                # entries: start_pc(2) + line_number(2) each
                # We add one entry: start_pc=0, line_number=<line_number>
                lnt_data = struct.pack('>H', 1)  # 1 entry
                lnt_data += struct.pack('>HH', 0, line_number)  # start_pc=0, line=N
                
                # Append to code attributes
                lnt_attr = struct.pack('>H', lnt_name_idx)  # name_idx
                lnt_attr += struct.pack('>I', len(lnt_data))  # length
                lnt_attr += lnt_data
                
                # Increment code attributes count
                struct.pack_into('>H', code_data, code_attr_start, code_attr_count + 1)
                
                # Append LineNumberTable
                code_data.extend(lnt_attr)
                
                attr['data'] = bytes(code_data)
                return True
        
        return False
    
    def serialize(self):
        """Serialize class file back to bytes."""
        out = bytearray()
        
        def w2(v):
            out.extend(struct.pack('>H', v))
        def w4(v):
            out.extend(struct.pack('>I', v))
        
        # Magic, version
        w4(self.magic)
        w2(self.minor_version)
        w2(self.major_version)
        
        # Constant pool
        w2(len(self.constant_pool))  # constant_pool_count
        i = 1
        while i < len(self.constant_pool):
            entry = self.constant_pool[i]
            if entry is None:
                i += 1
                continue
            
            tag = entry[0]
            if tag == 'Utf8':
                out.append(CONSTANT_Utf8)
                encoded = entry[1].encode('utf-8')
                w2(len(encoded))
                out.extend(encoded)
            elif tag == 'Integer':
                out.append(CONSTANT_Integer)
                w4(entry[1])
            elif tag == 'Float':
                out.append(CONSTANT_Float)
                w4(entry[1])
            elif tag == 'Long':
                out.append(CONSTANT_Long)
                w4((entry[1] >> 32) & 0xFFFFFFFF)
                w4(entry[1] & 0xFFFFFFFF)
                i += 1  # Skip padding slot
            elif tag == 'Double':
                out.append(CONSTANT_Double)
                w4((entry[1] >> 32) & 0xFFFFFFFF)
                w4(entry[1] & 0xFFFFFFFF)
                i += 1  # Skip padding slot
            elif tag == 'Class':
                out.append(CONSTANT_Class)
                w2(entry[1])
            elif tag == 'String':
                out.append(CONSTANT_String)
                w2(entry[1])
            elif tag == 'Fieldref':
                out.append(CONSTANT_Fieldref)
                w2(entry[1]); w2(entry[2])
            elif tag == 'Methodref':
                out.append(CONSTANT_Methodref)
                w2(entry[1]); w2(entry[2])
            elif tag == 'InterfaceMethodref':
                out.append(CONSTANT_InterfaceMethodref)
                w2(entry[1]); w2(entry[2])
            elif tag == 'NameAndType':
                out.append(CONSTANT_NameAndType)
                w2(entry[1]); w2(entry[2])
            elif tag == 'MethodHandle':
                out.append(CONSTANT_MethodHandle)
                out.append(entry[1])
                w2(entry[2])
            elif tag == 'MethodType':
                out.append(CONSTANT_MethodType)
                w2(entry[1])
            elif tag == 'InvokeDynamic':
                out.append(CONSTANT_InvokeDynamic)
                w2(entry[1]); w2(entry[2])
            i += 1
        
        # Access, this/super, interfaces
        w2(self.access_flags)
        w2(self.this_class)
        w2(self.super_class)
        w2(self.interfaces_count)
        for iface in self.interfaces:
            w2(iface)
        
        # Fields
        w2(len(self.fields))
        for field in self.fields:
            self._write_member(out, field)
        
        # Methods
        w2(len(self.methods))
        for method in self.methods:
            self._write_member(out, method)
        
        # Class attributes
        w2(len(self.attributes))
        for attr in self.attributes:
            self._write_attribute(out, attr)
        
        return bytes(out)
    
    def _write_member(self, out, member):
        out.extend(struct.pack('>H', member['access']))
        out.extend(struct.pack('>H', member['name_idx']))
        out.extend(struct.pack('>H', member['descriptor_idx']))
        out.extend(struct.pack('>H', len(member['attributes'])))
        for attr in member['attributes']:
            self._write_attribute(out, attr)
    
    def _write_attribute(self, out, attr):
        out.extend(struct.pack('>H', attr['name_idx']))
        out.extend(struct.pack('>I', len(attr['data'])))
        out.extend(attr['data'])

    def remove_line_number_tables(self):
        """Remove LineNumberTable from all methods' Code attributes."""
        removed = False
        for method in self.methods:
            for attr in method['attributes']:
                attr_name = self.get_utf8(attr['name_idx'])
                if attr_name != 'Code':
                    continue
                code_data = bytearray(attr['data'])
                p = 0
                p += 2  # max_stack
                p += 2  # max_locals
                code_length = struct.unpack_from('>I', code_data, p)[0]
                p += 4
                p += code_length  # skip bytecode
                exc_len = struct.unpack_from('>H', code_data, p)[0]
                p += 2  + exc_len * 8
                # Now at Code's sub-attributes
                code_attr_count_pos = p
                code_attr_count = struct.unpack_from('>H', code_data, p)[0]
                p += 2
                # Collect sub-attributes, filtering out LineNumberTable
                new_sub_attrs = bytearray()
                new_count = 0
                for _ in range(code_attr_count):
                    ca_name_idx = struct.unpack_from('>H', code_data, p)[0]
                    ca_len = struct.unpack_from('>I', code_data, p + 2)[0]
                    ca_name = self.get_utf8(ca_name_idx)
                    if ca_name == 'LineNumberTable':
                        removed = True
                    else:
                        new_sub_attrs.extend(code_data[p:p + 6 + ca_len])
                        new_count += 1
                    p += 6 + ca_len
                if removed:
                    # Rebuild Code attribute data
                    new_code = code_data[:code_attr_count_pos]
                    new_code.extend(struct.pack('>H', new_count))
                    new_code.extend(new_sub_attrs)
                    attr['data'] = bytes(new_code)
        return removed


# ─── Patching Functions ───────────────────────────────────────────

def patch_rjar(rjar_path, metadata_path, log_func=print):
    """Patch R.jar: add SourceFile, fix constructor, add LineNumberTable."""
    with open(metadata_path) as f:
        metadata = json.load(f)
    
    patched = 0
    total = 0
    
    # Read existing jar
    temp_path = rjar_path + '.patched'
    with zipfile.ZipFile(rjar_path, 'r') as zin:
        with zipfile.ZipFile(temp_path, 'w', zipfile.ZIP_STORED) as zout:
            for entry in zin.infolist():
                data = zin.read(entry.filename)
                
                if not entry.filename.endswith('.class'):
                    zout.writestr(entry, data)
                    continue
                
                # Convert jar entry name to metadata key
                class_name = entry.filename[:-6]  # remove .class
                
                if class_name not in metadata:
                    zout.writestr(entry, data)
                    continue
                
                total += 1
                meta = metadata[class_name]
                
                try:
                    cf = ClassFile(data)
                    modified = False
                    
                    # 1. Set SourceFile
                    if meta.get('source'):
                        current_sf = cf.get_source_file()
                        if current_sf != meta['source']:
                            cf.set_source_file(meta['source'])
                            modified = True
                    
                    # 2. Set constructor to public
                    if meta.get('init_access') == 'public':
                        if cf.set_init_public():
                            modified = True
                    
                    # 3. Add LineNumberTable to constructor
                    if meta.get('init_line') is not None:
                        if cf.add_init_line_number(meta['init_line']):
                            modified = True
                    
                    # 4. Strip ACC_PUBLIC from <clinit> if original doesn't have it
                    if meta.get('clinit_access') == 'package':
                        if cf.strip_clinit_public():
                            modified = True
                    
                    if modified:
                        data = cf.serialize()
                        patched += 1
                
                except Exception as e:
                    log_func(f"  WARNING: Failed to patch {class_name}: {e}")
                
                zout.writestr(entry, data)
    
    # Replace original
    shutil.move(temp_path, rjar_path)
    log_func(f"R.jar: patched {patched}/{total} R-class files")
    return patched


def strip_sourcefile(classes_dir, prefix, strip_list_path=None, log_func=print):
    """Strip SourceFile attribute from .class files matching prefix.
    
    If strip_list_path is provided, only strip from classes in the list.
    Otherwise strip from all classes matching prefix.
    """
    # Load selective strip list if provided
    strip_set = None
    if strip_list_path:
        with open(strip_list_path) as f:
            strip_set = set(json.load(f))
        log_func(f"Selective strip mode: {len(strip_set)} classes in strip list")
    
    stripped = 0
    total = 0
    skipped = 0
    
    for root, dirs, files in os.walk(classes_dir):
        for f in files:
            if not f.endswith('.class'):
                continue
            
            full_path = os.path.join(root, f)
            rel = os.path.relpath(full_path, classes_dir)
            
            if not rel.startswith(prefix):
                continue
            
            total += 1
            
            # Check if this class should be stripped
            class_name = rel[:-6]  # remove .class
            if strip_set is not None and class_name not in strip_set:
                skipped += 1
                continue
            
            data = open(full_path, 'rb').read()
            
            try:
                cf = ClassFile(data)
                if cf.remove_source_file():
                    new_data = cf.serialize()
                    with open(full_path, 'wb') as fo:
                        fo.write(new_data)
                    stripped += 1
            except Exception as e:
                log_func(f"  WARNING: Failed to process {rel}: {e}")
    
    log_func(f"SourceFile strip ({prefix}*): {stripped}/{total} files (skipped {skipped} with .source)")
    return stripped


def strip_line_numbers(classes_dir, strip_list_path, prefix='com/google/', log_func=print):
    """Strip LineNumberTable from methods in specific .class files."""
    with open(strip_list_path) as f:
        strip_set = set(json.load(f))
    
    stripped = 0
    total = 0
    
    for root, dirs, files in os.walk(classes_dir):
        for f in files:
            if not f.endswith('.class'):
                continue
            full_path = os.path.join(root, f)
            rel = os.path.relpath(full_path, classes_dir)
            if not rel.startswith(prefix):
                continue
            class_name = rel[:-6]
            if class_name not in strip_set:
                continue
            total += 1
            data = open(full_path, 'rb').read()
            try:
                cf = ClassFile(data)
                if cf.remove_line_number_tables():
                    with open(full_path, 'wb') as fo:
                        fo.write(cf.serialize())
                    stripped += 1
            except Exception as e:
                log_func(f"  WARNING: Failed to strip LNT from {rel}: {e}")
    
    log_func(f"LineNumberTable strip: {stripped}/{total} files")
    return stripped


# ─── Main ─────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(description='Patch class files for build')
    parser.add_argument('--patch-rjar', help='Path to R.jar to patch')
    parser.add_argument('--metadata', help='Path to R-class metadata JSON')
    parser.add_argument('--strip-source', help='Classes directory to strip SourceFile from')
    parser.add_argument('--strip-list', help='JSON file with list of classes to strip (selective mode)')
    parser.add_argument('--strip-linenumber', help='JSON file with list of classes to strip LineNumberTable from')
    parser.add_argument('--prefix', default='com/google/', help='Class name prefix for stripping')
    
    args = parser.parse_args()
    
    if args.patch_rjar:
        if not args.metadata:
            print("ERROR: --metadata required with --patch-rjar")
            sys.exit(1)
        patch_rjar(args.patch_rjar, args.metadata)
    
    if args.strip_source:
        strip_sourcefile(args.strip_source, args.prefix, args.strip_list)
    
    if args.strip_linenumber and args.strip_source:
        strip_line_numbers(args.strip_source, args.strip_linenumber, args.prefix)


if __name__ == '__main__':
    main()
