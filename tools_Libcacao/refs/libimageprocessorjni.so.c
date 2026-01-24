typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long    undefined8;
typedef unsigned short    word;
typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; // Exception Handler Frame Header Version
    dwfenc eh_frame_pointer_encoding; // Exception Handler Frame Pointer Encoding
    dwfenc eh_frame_desc_entry_count_encoding; // Encoding of # of Exception Handler FDEs
    dwfenc eh_frame_table_encoding; // Exception Handler Table Encoding
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
    dword initial_loc; // Initial Location
    dword data_loc; // Data location
};

typedef enum __priority_which {
    PRIO_PROCESS=0,
    PRIO_PGRP=1,
    PRIO_USER=2
} __priority_which;

typedef enum __priority_which __priority_which_t;

typedef ulong size_t;

typedef uint __id_t;

typedef __id_t id_t;

typedef union pthread_mutex_t pthread_mutex_t, *Ppthread_mutex_t;

typedef struct __pthread_mutex_s __pthread_mutex_s, *P__pthread_mutex_s;

typedef struct __pthread_internal_list __pthread_internal_list, *P__pthread_internal_list;

typedef struct __pthread_internal_list __pthread_list_t;

struct __pthread_internal_list {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
};

struct __pthread_mutex_s {
    int __lock;
    uint __count;
    int __owner;
    uint __nusers;
    int __kind;
    int __spins;
    __pthread_list_t __list;
};

union pthread_mutex_t {
    struct __pthread_mutex_s __data;
    char __size[40];
    long __align;
};

typedef union pthread_mutexattr_t pthread_mutexattr_t, *Ppthread_mutexattr_t;

union pthread_mutexattr_t {
    char __size[4];
    int __align;
};

typedef union pthread_cond_t pthread_cond_t, *Ppthread_cond_t;

typedef struct _struct_16 _struct_16, *P_struct_16;

struct _struct_16 {
    int __lock;
    uint __futex;
    ulonglong __total_seq;
    ulonglong __wakeup_seq;
    ulonglong __woken_seq;
    void *__mutex;
    uint __nwaiters;
    uint __broadcast_seq;
};

union pthread_cond_t {
    struct _struct_16 __data;
    char __size[48];
    longlong __align;
};

typedef ulong pthread_t;

typedef union pthread_attr_t pthread_attr_t, *Ppthread_attr_t;

union pthread_attr_t {
    char __size[56];
    long __align;
};

typedef struct _jmethodID _jmethodID, *P_jmethodID;

struct _jmethodID { // PlaceHolder Structure
};

typedef struct _jstring _jstring, *P_jstring;

struct _jstring { // PlaceHolder Structure
};

typedef struct _JNIEnv _JNIEnv, *P_JNIEnv;

struct _JNIEnv { // PlaceHolder Structure
};

typedef undefined Cacao_Err_t;

typedef struct _jobject _jobject, *P_jobject;

struct _jobject { // PlaceHolder Structure
};

typedef struct BurstCallback BurstCallback, *PBurstCallback;

struct BurstCallback { // PlaceHolder Structure
};

typedef struct SnapshotReadyCallback SnapshotReadyCallback, *PSnapshotReadyCallback;

struct SnapshotReadyCallback { // PlaceHolder Structure
};

typedef struct BurstShotFinishCallback BurstShotFinishCallback, *PBurstShotFinishCallback;

struct BurstShotFinishCallback { // PlaceHolder Structure
};

typedef struct VideoStartRecCallback VideoStartRecCallback, *PVideoStartRecCallback;

struct VideoStartRecCallback { // PlaceHolder Structure
};

typedef struct VideoStartSuperSlowRecCallback VideoStartSuperSlowRecCallback, *PVideoStartSuperSlowRecCallback;

struct VideoStartSuperSlowRecCallback { // PlaceHolder Structure
};

typedef struct SnapshotCallback SnapshotCallback, *PSnapshotCallback;

struct SnapshotCallback { // PlaceHolder Structure
};

typedef struct VideoFinishCallback VideoFinishCallback, *PVideoFinishCallback;

struct VideoFinishCallback { // PlaceHolder Structure
};

typedef struct BurstShotPrepareCallback BurstShotPrepareCallback, *PBurstShotPrepareCallback;

struct BurstShotPrepareCallback { // PlaceHolder Structure
};

typedef struct VideoPrepareCallback VideoPrepareCallback, *PVideoPrepareCallback;

struct VideoPrepareCallback { // PlaceHolder Structure
};

typedef struct SnapshotFreeCallback SnapshotFreeCallback, *PSnapshotFreeCallback;

struct SnapshotFreeCallback { // PlaceHolder Structure
};

typedef struct VideoPrepareSuperSlowCallback VideoPrepareSuperSlowCallback, *PVideoPrepareSuperSlowCallback;

struct VideoPrepareSuperSlowCallback { // PlaceHolder Structure
};

typedef struct BypassCameraContext BypassCameraContext, *PBypassCameraContext;

struct BypassCameraContext { // PlaceHolder Structure
};

typedef struct ObjectBase ObjectBase, *PObjectBase;

struct ObjectBase { // PlaceHolder Structure
};

typedef undefined DataSpace;

typedef undefined ImageSize;

typedef struct ProcessCtrlSuperSlowMode ProcessCtrlSuperSlowMode, *PProcessCtrlSuperSlowMode;

struct ProcessCtrlSuperSlowMode { // PlaceHolder Structure
};

typedef undefined ImageFormat;

typedef struct ProcessConfigBase ProcessConfigBase, *PProcessConfigBase;

struct ProcessConfigBase { // PlaceHolder Structure
};

typedef struct ProcessCtrlResult ProcessCtrlResult, *PProcessCtrlResult;

struct ProcessCtrlResult { // PlaceHolder Structure
};

typedef struct ProcessCtrlDynamicParameterConfig ProcessCtrlDynamicParameterConfig, *PProcessCtrlDynamicParameterConfig;

struct ProcessCtrlDynamicParameterConfig { // PlaceHolder Structure
};

typedef struct ProcessCtrlMode ProcessCtrlMode, *PProcessCtrlMode;

struct ProcessCtrlMode { // PlaceHolder Structure
};

typedef struct ProcessCtrlParam ProcessCtrlParam, *PProcessCtrlParam;

struct ProcessCtrlParam { // PlaceHolder Structure
};

typedef struct ProcessResultBase ProcessResultBase, *PProcessResultBase;

struct ProcessResultBase { // PlaceHolder Structure
};

typedef struct Caps Caps, *PCaps;

struct Caps { // PlaceHolder Structure
};

typedef struct ImageBuf ImageBuf, *PImageBuf;

struct ImageBuf { // PlaceHolder Structure
};

typedef struct ProcessParamBase ProcessParamBase, *PProcessParamBase;

struct ProcessParamBase { // PlaceHolder Structure
};

typedef struct ProcessCtrlVideoRecParam ProcessCtrlVideoRecParam, *PProcessCtrlVideoRecParam;

struct ProcessCtrlVideoRecParam { // PlaceHolder Structure
};

typedef struct CameraIndex CameraIndex, *PCameraIndex;

struct CameraIndex { // PlaceHolder Structure
};

typedef struct SerializedData SerializedData, *PSerializedData;

struct SerializedData { // PlaceHolder Structure
};

typedef struct SortedVectorImpl SortedVectorImpl, *PSortedVectorImpl;

struct SortedVectorImpl { // PlaceHolder Structure
};

typedef struct VectorImpl VectorImpl, *PVectorImpl;

struct VectorImpl { // PlaceHolder Structure
};

typedef struct SortedVector<android::key_value_pair_t<ANativeWindowBuffer*,imageprocessor::BurstSnapshotBuffer*>> SortedVector<android::key_value_pair_t<ANativeWindowBuffer*,imageprocessor::BurstSnapshotBuffer*>>, *PSortedVector<android::key_value_pair_t<ANativeWindowBuffer*,imageprocessor::BurstSnapshotBuffer*>>;

struct SortedVector<android::key_value_pair_t<ANativeWindowBuffer*,imageprocessor::BurstSnapshotBuffer*>> { // PlaceHolder Structure
};

typedef struct SortedVector<android::key_value_pair_t<void*,imageprocessor::BurstSnapshotBuffer*>> SortedVector<android::key_value_pair_t<void*,imageprocessor::BurstSnapshotBuffer*>>, *PSortedVector<android::key_value_pair_t<void*,imageprocessor::BurstSnapshotBuffer*>>;

struct SortedVector<android::key_value_pair_t<void*,imageprocessor::BurstSnapshotBuffer*>> { // PlaceHolder Structure
};

typedef struct SortedVector<android::key_value_pair_t<int,imageprocessor::BurstSnapshotBuffer*>> SortedVector<android::key_value_pair_t<int,imageprocessor::BurstSnapshotBuffer*>>, *PSortedVector<android::key_value_pair_t<int,imageprocessor::BurstSnapshotBuffer*>>;

struct SortedVector<android::key_value_pair_t<int,imageprocessor::BurstSnapshotBuffer*>> { // PlaceHolder Structure
};

typedef struct Vector<cacao::ImageBuf*> Vector<cacao::ImageBuf*>, *PVector<cacao::ImageBuf*>;

struct Vector<cacao::ImageBuf*> { // PlaceHolder Structure
};

typedef struct Surface Surface, *PSurface;

struct Surface { // PlaceHolder Structure
};

typedef struct sp sp, *Psp;

struct sp { // PlaceHolder Structure
};

typedef struct SortedVector<android::key_value_pair_t<int,cacao::ProcessCtrlResult*>> SortedVector<android::key_value_pair_t<int,cacao::ProcessCtrlResult*>>, *PSortedVector<android::key_value_pair_t<int,cacao::ProcessCtrlResult*>>;

struct SortedVector<android::key_value_pair_t<int,cacao::ProcessCtrlResult*>> { // PlaceHolder Structure
};

typedef struct Vector<imageprocessor::VideoThreadCommand> Vector<imageprocessor::VideoThreadCommand>, *PVector<imageprocessor::VideoThreadCommand>;

struct Vector<imageprocessor::VideoThreadCommand> { // PlaceHolder Structure
};

typedef struct Elf64_Dyn_AARCH64 Elf64_Dyn_AARCH64, *PElf64_Dyn_AARCH64;

typedef enum Elf64_DynTag_AARCH64 {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_XHASH=1879047924,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf64_DynTag_AARCH64;

struct Elf64_Dyn_AARCH64 {
    enum Elf64_DynTag_AARCH64 d_tag;
    qword d_val;
};

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType_AARCH64 {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_AARCH64_ATTRIBUTES=1879048195
} Elf_SectionHeaderType_AARCH64;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_AARCH64 sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[16];
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; // location to apply the relocation action
    qword r_info; // the symbol table index and the type of relocation
    qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

typedef enum Elf_ProgramHeaderType_AARCH64 {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482,
    PT_AARCH64_ARCHEXT=1879048192
} Elf_ProgramHeaderType_AARCH64;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType_AARCH64 p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

typedef struct ElfNote_8_4 ElfNote_8_4, *PElfNote_8_4;

struct ElfNote_8_4 {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[8]; // Vendor name
    byte description[4]; // Blob value
};



undefined1 DAT_000301e8;
undefined4 DAT_00030010;
undefined ~BypassCameraContext;
undefined8 _edata;
pointer PTR_LOOP_00030000;
undefined DAT_00012e70;
undefined DAT_00011739;
Elf64_Sym[257] __DT_SYMTAB;
pointer PTR_~ProcessResultBase_0002eeb8;
undefined DAT_0002ef00;
pointer PTR_~ProcessResultBase_0002ef38;
undefined DAT_0002ef98;
undefined DAT_00011898;
undefined DAT_0001190f;
undefined8 gJavaVMPointer;
undefined DAT_000119e2;
undefined DAT_00011b8c;
pointer PTR_do_destroy_0002f060;
pointer PTR_do_destroy_0002f090;
pointer PTR_~ProcessResultBase_0002f0c0;
undefined DAT_0002f130;
pointer PTR_~SortedVector_0002f168;
pointer PTR_~SortedVector_0002f1c0;
pointer PTR_do_destroy_0002efd0;
pointer PTR_do_destroy_0002f000;
pointer PTR_do_destroy_0002f030;
pointer PTR_~ProcessResultBase_0002f218;
undefined DAT_0002f268;
pointer PTR_~ProcessResultBase_0002f2a0;
undefined DAT_0002f2f0;
pointer PTR_~ProcessResultBase_0002f328;
undefined DAT_0002f380;
pointer PTR_~Vector_0002f3b8;
pointer PTR_do_destroy_0002f408;
pointer PTR_do_destroy_0002f438;
pointer PTR_do_destroy_0002f468;
pointer PTR_do_destroy_0002f498;
pointer PTR_do_destroy_0002f4c8;
undefined BypassCameraVideo_thread;
pointer PTR_~Vector_0002f580;
undefined DAT_000301f8;
undefined DAT_00030228;
pointer PTR_~ProcessResultBase_0002f4f8;
undefined DAT_0002f548;
pointer PTR_~ProcessCtrlVideoRecParam_0002f5d0;
undefined DAT_0002f628;
pointer PTR_~SortedVector_0002f660;
pointer PTR_~SortedVector_0002f6b8;
pointer PTR_do_destroy_0002f710;

void FUN_000083c0(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



void __register_atfork(void)

{
  __register_atfork();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessFactory::createProcess(void)

{
  createProcess();
  return;
}



undefined8 BypassCameraPhoto_initialize(long *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = BypassCameraPhoto_initialize(param_1,param_2,param_3);
  return uVar1;
}



void BypassCameraVideo_initialize(long *param_1,undefined8 param_2,void *param_3)

{
  BypassCameraVideo_initialize(param_1,param_2,param_3);
  return;
}



undefined8 BypassCameraBurst_initialize(long *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = BypassCameraBurst_initialize(param_1,param_2,param_3);
  return uVar1;
}



void __android_log_print(void)

{
  __android_log_print();
  return;
}



void __cxa_guard_acquire(void)

{
  __cxa_guard_acquire();
  return;
}



void __cxa_atexit(void)

{
  __cxa_atexit();
  return;
}



void __cxa_guard_release(void)

{
  __cxa_guard_release();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
  int iVar1;
  
  iVar1 = pthread_mutex_init(__mutex,__mutexattr);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memset(__s,__c,__n);
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::decStrong(void *param_1)

{
  decStrong(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::sp_report_race(void)

{
  sp_report_race();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_destroy(__mutex);
  return iVar1;
}



void BypassCameraPhoto_finalize(long *param_1,undefined8 param_2,long *param_3)

{
  BypassCameraPhoto_finalize(param_1,param_2,param_3);
  return;
}



void BypassCameraVideo_finalize(long *param_1,undefined8 param_2,long param_3)

{
  BypassCameraVideo_finalize(param_1,param_2,param_3);
  return;
}



void BypassCameraBurst_finalize(long *param_1,undefined8 param_2,long param_3)

{
  BypassCameraBurst_finalize(param_1,param_2,param_3);
  return;
}



undefined4
BypassCameraPhoto_changeToPhotoMode
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  uVar1 = BypassCameraPhoto_changeToPhotoMode
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return uVar1;
}



undefined4
BypassCameraVideo_changeToVideoMode
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,ulong param_4,long param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  uVar1 = BypassCameraVideo_changeToVideoMode
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return uVar1;
}



int BypassCameraPhoto_prepareSnapshot
              (long *param_1,undefined8 param_2,long param_3,undefined8 param_4,int param_5)

{
  int iVar1;
  
  iVar1 = BypassCameraPhoto_prepareSnapshot(param_1,param_2,param_3,param_4,param_5);
  return iVar1;
}



undefined4
BypassCameraVideo_changeToSuperSlowMode
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  
  uVar1 = BypassCameraVideo_changeToSuperSlowMode
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10);
  return uVar1;
}



undefined8
BypassCameraPhoto_requestSnapshotReady(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = BypassCameraPhoto_requestSnapshotReady(param_1,param_2,param_3);
  return uVar1;
}



void BypassCameraBurst_requestSnapshot
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long *param_4,
               undefined8 param_5,undefined8 *param_6,char param_7,char param_8,char param_9,
               undefined8 param_10,char param_11,int param_12,char param_13,int param_14,
               char param_15,undefined4 param_16,undefined4 param_17,undefined4 param_18,
               undefined4 param_19,char param_20,uint param_21)

{
  BypassCameraBurst_requestSnapshot
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
             param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,
             param_20,param_21);
  return;
}



undefined8
BypassCameraPhoto_requestSnapshotFree(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = BypassCameraPhoto_requestSnapshotFree(param_1,param_2,param_3);
  return uVar1;
}



undefined4
BypassCameraVideo_prepareVideoRecording
          (long *param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  uVar1 = BypassCameraVideo_prepareVideoRecording
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return uVar1;
}



undefined4
BypassCameraVideo_prepareSuperSlowRecording
          (long *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  
  uVar1 = BypassCameraVideo_prepareSuperSlowRecording(param_1,param_2,param_3,param_4);
  return uVar1;
}



undefined8 BypassCameraVideo_startVideoRecording(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = BypassCameraVideo_startVideoRecording(param_1,param_2,param_3);
  return uVar1;
}



undefined8
BypassCameraVideo_startSuperSlowRecording(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = BypassCameraVideo_startSuperSlowRecording(param_1,param_2,param_3);
  return uVar1;
}



undefined8 BypassCameraVideo_stopVideoRecording(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = BypassCameraVideo_stopVideoRecording(param_1,param_2,param_3);
  return uVar1;
}



undefined8
BypassCameraPhoto_prepareBurstShot(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = BypassCameraPhoto_prepareBurstShot(param_1,param_2,param_3);
  return uVar1;
}



undefined8
BypassCameraPhoto_finishBurstShot(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = BypassCameraPhoto_finishBurstShot(param_1,param_2,param_3);
  return uVar1;
}



void * __thiscall cacao::ObjectBase::operator_new(ObjectBase *this,ulong param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(this,param_1);
  return pvVar1;
}



void __thiscall cacao::ObjectBase::ObjectBase(ObjectBase *this)

{
  ObjectBase(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlCapsFactory::getCaps(CameraIndex *param_1,Caps *param_2)

{
  getCaps(param_1,param_2);
  return;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = strcmp(__s1,__s2);
  return iVar1;
}



void __thiscall cacao::ObjectBase::~ObjectBase(ObjectBase *this)

{
  ~ObjectBase(this);
  return;
}



void __thiscall cacao::ObjectBase::operator_delete(ObjectBase *this,void *param_1)

{
  operator_delete(this,param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memcpy(__dest,__src,__n);
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ObjectBase::dump(uint param_1)

{
  dump(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock(__mutex);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * operator_new(ulong param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



void __thiscall
android::SortedVectorImpl::SortedVectorImpl(SortedVectorImpl *this,ulong param_1,uint param_2)

{
  SortedVectorImpl(this,param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_unlock(__mutex);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::SortedVectorImpl::indexOf(void *param_1)

{
  indexOf(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void operator_delete(void *param_1)

{
  operator_delete(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::SortedVectorImpl::remove(void *param_1)

{
  remove(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::clear(void)

{
  clear();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::finish_vector(void)

{
  finish_vector();
  return;
}



void __thiscall android::SortedVectorImpl::~SortedVectorImpl(SortedVectorImpl *this)

{
  ~SortedVectorImpl(this);
  return;
}



void BypassCameraBurstBufferManager_deleteBuffers(long param_1)

{
  BypassCameraBurstBufferManager_deleteBuffers(param_1);
  return;
}



void BypassCameraBurstBufferManager_finalizeSurface(long param_1)

{
  BypassCameraBurstBufferManager_finalizeSurface(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * strncpy(char *__dest,char *__src,size_t __n)

{
  char *pcVar1;
  
  pcVar1 = strncpy(__dest,__src,__n);
  return pcVar1;
}



undefined4 BypassCameraBurstBufferManager_dequeueBuffer(long param_1,long *param_2)

{
  undefined4 uVar1;
  
  uVar1 = BypassCameraBurstBufferManager_dequeueBuffer(param_1,param_2);
  return uVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::SortedVectorImpl::add(void *param_1)

{
  add(param_1);
  return;
}



void __thiscall android::VectorImpl::VectorImpl(VectorImpl *this,ulong param_1,uint param_2)

{
  VectorImpl(this,param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::insertAt(void *param_1,ulong param_2,ulong param_3)

{
  insertAt(param_1,param_2,param_3);
  return;
}



void BypassCameraBurstBufferManager_initializeSurface
               (long *param_1,undefined8 param_2,int param_3,long param_4)

{
  BypassCameraBurstBufferManager_initializeSurface(param_1,param_2,param_3,param_4);
  return;
}



int BypassCameraBurstBufferManager_createBuffers(long param_1)

{
  int iVar1;
  
  iVar1 = BypassCameraBurstBufferManager_createBuffers(param_1);
  return iVar1;
}



void getJNIEnv(void)

{
  getJNIEnv();
  return;
}



void BypassCameraBurstBufferManager_queueBuffer(long param_1,undefined4 *param_2)

{
  BypassCameraBurstBufferManager_queueBuffer(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * memmove(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memmove(__dest,__src,__n);
  return pvVar1;
}



void __thiscall android::VectorImpl::~VectorImpl(VectorImpl *this)

{
  ~VectorImpl(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



int __thiscall
imageprocessor::SnapshotReadyCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  int iVar1;
  
  iVar1 = onHandleResult(param_1_00,param_2);
  return iVar1;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



int __thiscall
imageprocessor::SnapshotCallback::onHandleProgress(undefined8 param_1_00,long *param_2)

{
  int iVar1;
  
  iVar1 = onHandleProgress(param_1_00,param_2);
  return iVar1;
}



void __thiscall
imageprocessor::SnapshotCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  onHandleResult(param_1_00,param_2);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



int __thiscall
imageprocessor::SnapshotFreeCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  int iVar1;
  
  iVar1 = onHandleResult(param_1_00,param_2);
  return iVar1;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



int __thiscall
imageprocessor::BurstShotPrepareCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  int iVar1;
  
  iVar1 = onHandleResult(param_1_00,param_2);
  return iVar1;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



int __thiscall
imageprocessor::BurstShotFinishCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  int iVar1;
  
  iVar1 = onHandleResult(param_1_00,param_2);
  return iVar1;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
android::SortedVector<>::do_copy(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_copy(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_splat
          (undefined8 param_1_00,undefined4 *param_2,undefined4 *param_3,ulong param_4)

{
  do_splat(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_move_forward
          (undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_forward(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_move_forward
          (undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_forward(param_1_00,param_2,param_3,param_4);
  return;
}



int __thiscall android::SortedVector<>::do_compare(undefined8 param_1_00,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = do_compare(param_1_00,param_2,param_3);
  return iVar1;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
android::SortedVector<>::do_copy(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_copy(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_splat
          (undefined8 param_1_00,undefined4 *param_2,undefined4 *param_3,ulong param_4)

{
  do_splat(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_move_forward
          (undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_forward(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_move_forward
          (undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_forward(param_1_00,param_2,param_3,param_4);
  return;
}



int __thiscall android::SortedVector<>::do_compare(undefined8 param_1_00,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = do_compare(param_1_00,param_2,param_3);
  return iVar1;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
android::Vector<>::do_copy(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_copy(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::Vector<>::do_splat
          (undefined8 param_1_00,undefined8 *param_2,undefined8 *param_3,ulong param_4)

{
  do_splat(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::Vector<>::do_move_backward(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_backward(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::Vector<>::do_move_backward(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_backward(param_1_00,param_2,param_3,param_4);
  return;
}



void __errno(void)

{
  __errno();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_attr_init(pthread_attr_t *__attr)

{
  int iVar1;
  
  iVar1 = pthread_attr_init(__attr);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_attr_setdetachstate(pthread_attr_t *__attr,int __detachstate)

{
  int iVar1;
  
  iVar1 = pthread_attr_setdetachstate(__attr,__detachstate);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
  int iVar1;
  
  iVar1 = pthread_create(__newthread,__attr,__start_routine,__arg);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::push(void *param_1)

{
  push(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_cond_signal(pthread_cond_t *__cond)

{
  int iVar1;
  
  iVar1 = pthread_cond_signal(__cond);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_join(pthread_t __th,void **__thread_return)

{
  int iVar1;
  
  iVar1 = pthread_join(__th,__thread_return);
  return iVar1;
}



void getSurface(long *param_1,undefined8 param_2)

{
  getSurface(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::incStrong(void *param_1)

{
  incStrong(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Surface::getIGraphicBufferProducer(void)

{
  getIGraphicBufferProducer();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IInterface::asBinder(sp *param_1)

{
  asBinder(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int setpriority(__priority_which_t __which,id_t __who,int __prio)

{
  int iVar1;
  
  iVar1 = setpriority(__which,__who,__prio);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_cond_wait(pthread_cond_t *__cond,pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_cond_wait(__cond,__mutex);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::removeItemsAt(ulong param_1,ulong param_2)

{
  removeItemsAt(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void pthread_exit(void *__retval)

{
                    // WARNING: Subroutine does not return
  pthread_exit(__retval);
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoPrepareCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  onHandleResult(param_1_00,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoFinishCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  onHandleResult(param_1_00,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  onHandleResult(param_1_00,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoPrepareSuperSlowCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  onHandleResult(param_1_00,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartSuperSlowRecCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  onHandleResult(param_1_00,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



void __thiscall android::Vector<>::do_construct(undefined8 param_1_00,void *param_2,long param_3)

{
  do_construct(param_1_00,param_2,param_3);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
android::Vector<>::do_move_backward
          (undefined8 param_1_00,undefined4 *param_2,undefined4 *param_3,ulong param_4)

{
  do_move_backward(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::Vector<>::do_splat
          (undefined8 param_1_00,undefined4 *param_2,undefined4 *param_3,ulong param_4)

{
  do_splat(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::Vector<>::do_move_forward
          (undefined8 param_1_00,undefined8 *param_2,ulong param_3,ulong param_4)

{
  do_move_forward(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::Vector<>::do_move_backward
          (undefined8 param_1_00,undefined4 *param_2,undefined4 *param_3,ulong param_4)

{
  do_move_backward(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall android::Surface::Surface(Surface *this,sp *param_1,bool param_2)

{
  Surface(this,param_1,param_2);
  return;
}



void cacao::ProcessFactory::getJpegBufferSize(void)

{
  getJpegBufferSize();
  return;
}



void __thiscall cacao::ImageBuf::ImageBuf(void)

{
  ImageBuf();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
android::SortedVector<>::do_copy(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_copy(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_splat
          (undefined8 param_1_00,undefined8 *param_2,undefined8 *param_3,ulong param_4)

{
  do_splat(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_move_forward
          (undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_forward(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_move_forward
          (undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_forward(param_1_00,param_2,param_3,param_4);
  return;
}



int __thiscall
android::SortedVector<>::do_compare(undefined8 param_1_00,ulong *param_2,ulong *param_3)

{
  int iVar1;
  
  iVar1 = do_compare(param_1_00,param_2,param_3);
  return iVar1;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
android::SortedVector<>::do_copy(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_copy(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_splat
          (undefined8 param_1_00,undefined8 *param_2,undefined8 *param_3,ulong param_4)

{
  do_splat(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_move_forward
          (undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_forward(param_1_00,param_2,param_3,param_4);
  return;
}



void __thiscall
android::SortedVector<>::do_move_forward
          (undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  do_move_forward(param_1_00,param_2,param_3,param_4);
  return;
}



int __thiscall
android::SortedVector<>::do_compare(undefined8 param_1_00,ulong *param_2,ulong *param_3)

{
  int iVar1;
  
  iVar1 = do_compare(param_1_00,param_2,param_3);
  return iVar1;
}



void BypassCameraBurstBufferManager_createBufVector(long param_1,long *param_2,uint param_3)

{
  BypassCameraBurstBufferManager_createBufVector(param_1,param_2,param_3);
  return;
}



void BypassCameraBurstBufferManager_dump(long param_1)

{
  BypassCameraBurstBufferManager_dump(param_1);
  return;
}



void BypassCameraBurstBufferManager_cancelBuffers(long param_1,long param_2,uint param_3)

{
  BypassCameraBurstBufferManager_cancelBuffers(param_1,param_2,param_3);
  return;
}



void BypassCameraBurstBufferManager_cancelAllBuffer(long param_1,long param_2)

{
  BypassCameraBurstBufferManager_cancelAllBuffer(param_1,param_2);
  return;
}



void android::SortedVector<>::do_destroy(void)

{
  do_destroy();
  return;
}



void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  ~VideoStartRecCallback(this);
  return;
}



void __thiscall imageprocessor::BurstCallback::onHandleProgress(undefined8 param_1_00,long *param_2)

{
  onHandleProgress(param_1_00,param_2);
  return;
}



void __thiscall imageprocessor::BurstCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  onHandleResult(param_1_00,param_2);
  return;
}



void __on_dlclose(void)

{
  __cxa_finalize(0x30000);
  return;
}



int pthread_atfork(__prepare *__prepare,__parent *__parent,__child *__child)

{
  int iVar1;
  
  iVar1 = __register_atfork((int)__prepare,__parent,__child,0x30000);
  return iVar1;
}



undefined8 Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeIsDebugable(void)

{
  return 0;
}



undefined8 *
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeInitialize
          (long *param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  if (((DAT_000301e8 & 1) == 0) && (iVar1 = __cxa_guard_acquire(&DAT_000301e8), iVar1 != 0)) {
    imageprocessor::BypassCameraContext::BypassCameraContext((BypassCameraContext *)&_edata);
    __cxa_atexit(imageprocessor::BypassCameraContext::~BypassCameraContext,&_edata,
                 &PTR_LOOP_00030000);
    __cxa_guard_release(&DAT_000301e8);
  }
  if (_edata != 0) {
    imageprocessor::BypassCamera_finalize(param_1,param_2,&_edata);
  }
  _edata = cacao::ProcessFactory::createProcess();
  if (_edata == 0) {
    pcVar3 = "%s: Create bypass camera process failed.";
  }
  else {
    DAT_00030010 = param_3;
    uVar2 = BypassCameraPhoto_initialize(param_1,param_2,0x30008);
    if ((int)uVar2 == 0) {
      iVar1 = BypassCameraVideo_initialize(param_1,param_2,&_edata);
      if ((iVar1 == 0) &&
         (uVar2 = BypassCameraBurst_initialize(param_1,param_2,0x30008), (int)uVar2 == 0)) {
        return &_edata;
      }
      pcVar3 = "%s: initialize video failed.";
    }
    else {
      pcVar3 = "%s: initialize photo failed.";
    }
  }
  __android_log_print(6,0,pcVar3,"BypassCamera_initialize");
  imageprocessor::BypassCamera_finalize(param_1,param_2,&_edata);
  __android_log_print(6,0,"%s: initialize failed.",
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeInitialize"
                     );
  return (undefined8 *)0xffffffffffffffff;
}



// imageprocessor::BypassCameraContext::BypassCameraContext()

ulong __thiscall imageprocessor::BypassCameraContext::BypassCameraContext(BypassCameraContext *this)

{
  uint uVar1;
  ulong uVar2;
  long *plVar3;
  void *pvVar4;
  
  pthread_mutex_init((pthread_mutex_t *)(this + 0x90),(pthread_mutexattr_t *)0x0);
  *(undefined8 *)(this + 0x160) = 0;
  memset(this + 0xc0,0,0x81);
  plVar3 = *(long **)(this + 0x160);
  if (plVar3 != (long *)0x0) {
    android::RefBase::decStrong((void *)((long)plVar3 + *(long *)(*plVar3 + -0x18)));
  }
  if (plVar3 != *(long **)(this + 0x160)) {
    android::sp_report_race();
  }
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined8 *)(this + 0x154) = 0;
  *(undefined8 *)(this + 0x14c) = 0;
  *(undefined8 *)(this + 0x144) = 0;
  this[0x168] = (BypassCameraContext)0x0;
  *(undefined8 *)(this + 0x16c) = 0x400000000;
  *(undefined8 *)(this + 0x180) = 0;
  *(undefined8 *)(this + 0x188) = 0;
  *(undefined8 *)(this + 0x178) = 0;
  *(undefined8 *)(this + 0x1a0) = 0;
  uVar1 = pthread_mutex_init((pthread_mutex_t *)(this + 0x1a8),(pthread_mutexattr_t *)0x0);
  uVar2 = (ulong)uVar1;
  *(undefined8 *)(this + 400) = 0;
  *(undefined8 *)(this + 0x198) = 0;
  pvVar4 = *(void **)(this + 0x1a0);
  if (pvVar4 != (void *)0x0) {
    uVar2 = android::RefBase::decStrong(pvVar4);
  }
  if (pvVar4 != *(void **)(this + 0x1a0)) {
    uVar2 = android::sp_report_race();
  }
  *(undefined8 *)(this + 0x1a0) = 0;
  this[0x1d0] = (BypassCameraContext)0x0;
  *(undefined4 *)(this + 0x1d8) = 0;
  *(undefined4 *)(this + 0x1d4) = 0;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0xffffffff;
  return uVar2;
}



// imageprocessor::BypassCameraContext::~BypassCameraContext()

int __thiscall imageprocessor::BypassCameraContext::~BypassCameraContext(BypassCameraContext *this)

{
  int iVar1;
  long *plVar2;
  
  pthread_mutex_destroy((pthread_mutex_t *)(this + 0x1a8));
  if (*(void **)(this + 0x1a0) != (void *)0x0) {
    android::RefBase::decStrong(*(void **)(this + 0x1a0));
  }
  plVar2 = *(long **)(this + 0x160);
  if (plVar2 != (long *)0x0) {
    android::RefBase::decStrong((void *)((long)plVar2 + *(long *)(*plVar2 + -0x18)));
  }
  iVar1 = pthread_mutex_destroy((pthread_mutex_t *)(this + 0x90));
  return iVar1;
}



// imageprocessor::BypassCamera_finalize(_JNIEnv*, _jobject*, imageprocessor::BypassCameraContext*)

void imageprocessor::BypassCamera_finalize(long *param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  
  BypassCameraPhoto_finalize(param_1,param_2,param_3);
  BypassCameraVideo_finalize(param_1,param_2,(long)param_3);
  BypassCameraBurst_finalize(param_1,param_2,(long)param_3);
  if ((long *)*param_3 != (long *)0x0) {
    iVar1 = (**(code **)(*(long *)*param_3 + 0x20))();
    if (iVar1 != 0) {
      __android_log_print(6,0,"%s: cacao stop() ret=%d","BypassCamera_finalize",iVar1);
    }
    if ((long *)*param_3 != (long *)0x0) {
      (**(code **)(*(long *)*param_3 + 8))();
    }
    *param_3 = 0;
  }
  return;
}



void Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeFinalize
               (long *param_1,undefined8 param_2,long *param_3)

{
  if (param_3 != (long *)0xffffffffffffffff) {
    imageprocessor::BypassCamera_finalize(param_1,param_2,param_3);
    return;
  }
  __android_log_print(6,0,"%s: Navtive bypass camera is already finalized or not initialized yet.",
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeFinalize"
                     );
  return;
}



int Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeChangeToPhotoMode
              (undefined8 param_1,undefined8 param_2,long *param_3,int param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    if (param_4 == 0) {
      *(undefined4 *)((long)param_3 + 0xc) = 0;
      iVar1 = BypassCameraPhoto_changeToPhotoMode
                        (param_1,param_2,param_3,param_5,param_6,param_7,param_8,param_9);
      if (iVar1 == 0) {
        return 0;
      }
      __android_log_print(6,0,"%s: change to photo mode failed.",
                          "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeChangeToPhotoMode"
                         );
      return iVar1;
    }
    __android_log_print(6,0,"%s: Failed convert photo mode. Unexpected mode : %d",
                        "BypassCamera_convertPhotoMode",param_4);
    pcVar2 = "%s: convert photo mode failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeChangeToPhotoMode"
                     );
  return -1;
}



int Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeChangeToVideoMode
              (undefined8 param_1,undefined8 param_2,long *param_3,uint param_4,ulong param_5,
              ulong param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    if (param_4 < 5) {
      *(undefined4 *)((long)param_3 + 0xc) = *(undefined4 *)(&DAT_00012e70 + (long)(int)param_4 * 4)
      ;
      iVar1 = BypassCameraVideo_changeToVideoMode
                        (param_1,param_2,param_3,param_5 & 0xffffffff,param_6 & 0xffffffff,param_7,
                         param_8,param_9);
      if (iVar1 == 0) {
        return 0;
      }
      __android_log_print(6,0,"%s: change to video mode nfailed.",
                          "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeChangeToVideoMode"
                         );
      return iVar1;
    }
    __android_log_print(6,0,"%s: Failed convert video mode. Unexpected mode : %d",
                        "BypassCamera_convertVideoMode",param_4);
    pcVar2 = "%s: convert video mode failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeChangeToVideoMode"
                     );
  return -1;
}



undefined4
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestPrepareSnapshot
          (long *param_1,undefined8 param_2,long *param_3,undefined8 param_4,int param_5)

{
  int iVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    iVar1 = BypassCameraPhoto_prepareSnapshot(param_1,param_2,(long)param_3,param_4,param_5);
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = "%s: Prepare snapshot failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestPrepareSnapshot"
                     );
  return 0xffffffff;
}



int Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeChangeToSuperSlowMode
              (undefined8 param_1,undefined8 param_2,long *param_3,int param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
              undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else {
    if (*param_3 != 0) {
      if (param_4 == 0) {
        uVar3 = 4;
      }
      else {
        if (param_4 != 1) {
          __android_log_print(6,0,"%s: Failed convert super slow mode. Unexpected mode : %d",
                              "BypassCamera_convertSuperSlowMode",param_4);
          pcVar2 = "%s: convert super slow mode failed.";
          goto LAB_0000952c;
        }
        uVar3 = 5;
      }
      *(undefined4 *)((long)param_3 + 0xc) = uVar3;
      iVar1 = BypassCameraVideo_changeToSuperSlowMode
                        (param_1,param_2,param_3,param_5,param_6,param_7,param_8,param_9,param_10,
                         param_11);
      if (iVar1 == 0) {
        return 0;
      }
      __android_log_print(6,0,"%s: change to super slow mode failed.",
                          "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeChangeToSuperSlowMode"
                         );
      return iVar1;
    }
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
LAB_0000952c:
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeChangeToSuperSlowMode"
                     );
  return -1;
}



undefined8
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestSnapshotReady
          (undefined8 param_1,undefined8 param_2,long *param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    uVar1 = BypassCameraPhoto_requestSnapshotReady(param_1,param_2,param_3);
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    pcVar2 = "%s: Request snapshot ready failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestSnapshotReady"
                     );
  return 0xffffffff;
}



undefined8
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestSnapshot
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,long *param_4,undefined8 param_5
          ,long *param_6,char param_7,char param_8,char param_9,undefined8 param_10,char param_11,
          int param_12,char param_13,int param_14,char param_15,undefined4 param_16,
          undefined4 param_17,undefined4 param_18,undefined4 param_19,char param_20,uint param_21)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_6 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_6 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    uVar1 = BypassCameraBurst_requestSnapshot
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12,param_13,param_14,param_15,param_16,param_17,
                       param_18,param_19,param_20,param_21);
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    pcVar2 = "%s: Request burst shot failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestSnapshot"
                     );
  return 0xffffffff;
}



undefined4
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeGetLatestRequestId
          (undefined8 param_1,undefined8 param_2,long *param_3)

{
  if (*param_3 != 0) {
    return (int)param_3[7];
  }
  __android_log_print(6,0,
                      "%s: Navtive bypass camera context is already finalized or not initialized yet."
                      ,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeGetLatestRequestId"
                     );
  return 0xffffffff;
}



undefined8
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestSnapshotFree
          (undefined8 param_1,undefined8 param_2,long *param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    uVar1 = BypassCameraPhoto_requestSnapshotFree(param_1,param_2,param_3);
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    pcVar2 = "%s: Request snapshot free failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestSnapshotFree"
                     );
  return 0xffffffff;
}



undefined4
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestPrepareVideoRecording
          (long *param_1,undefined8 param_2,long *param_3,undefined8 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    iVar1 = BypassCameraVideo_prepareVideoRecording
                      (param_1,param_2,(long)param_3,param_4,param_5,param_6,param_7);
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = "%s: Prepare video recording failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestPrepareVideoRecording"
                     );
  return 0xffffffff;
}



undefined4
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestPrepareSuperSlowRecording
          (long *param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  int iVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    iVar1 = BypassCameraVideo_prepareSuperSlowRecording(param_1,param_2,(long)param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = "%s: Prepare super slow recording failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestPrepareSuperSlowRecording"
                     );
  return 0xffffffff;
}



undefined8
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestStartVideoRecording
          (undefined8 param_1,undefined8 param_2,long *param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    uVar1 = BypassCameraVideo_startVideoRecording(param_1,param_2,(long)param_3);
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    pcVar2 = "%s: Start video recording failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestStartVideoRecording"
                     );
  return 0xffffffff;
}



undefined8
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestStartSuperSlowRecording
          (undefined8 param_1,undefined8 param_2,long *param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    uVar1 = BypassCameraVideo_startSuperSlowRecording(param_1,param_2,(long)param_3);
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    pcVar2 = "%s: Start super slow recording failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestStartSuperSlowRecording"
                     );
  return 0xffffffff;
}



undefined8
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestStopVideoRecording
          (undefined8 param_1,undefined8 param_2,long *param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Navtive bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    uVar1 = BypassCameraVideo_stopVideoRecording(param_1,param_2,(long)param_3);
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    pcVar2 = "%s: Stop video recording failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestStopVideoRecording"
                     );
  return 0xffffffff;
}



undefined8
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestPrepareBurstShot
          (undefined8 param_1,undefined8 param_2,long *param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Native bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    uVar1 = BypassCameraPhoto_prepareBurstShot(param_1,param_2,param_3);
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    pcVar2 = "%s: failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestPrepareBurstShot"
                     );
  return 0xffffffff;
}



undefined8
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestFinishBurstShot
          (undefined8 param_1,undefined8 param_2,long *param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_3 == (long *)0xffffffffffffffff) {
    pcVar2 = "%s: Native bypass camera context is already finalized or not initialized yet.";
  }
  else if (*param_3 == 0) {
    pcVar2 = "%s: Cacao process is already finalized or not initialized yet.";
  }
  else {
    uVar1 = BypassCameraPhoto_finishBurstShot(param_1,param_2,param_3);
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    pcVar2 = "%s: failed.";
  }
  __android_log_print(6,0,pcVar2,
                      "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeRequestFinishBurstShot"
                     );
  return 0xffffffff;
}



int Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeGetCaps
              (long *param_1,ulong param_2,int param_3,undefined8 param_4,undefined8 param_5,
              undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  int iVar2;
  ObjectBase *this;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ObjectBase *pOVar18;
  ObjectBase *pOVar19;
  undefined4 local_6c;
  long local_68;
  
  lVar1 = tpidr_el0;
  local_68 = *(long *)(lVar1 + 0x28);
  this = cacao::ObjectBase::operator_new((ObjectBase *)&__DT_SYMTAB[0xd5].st_size,param_2);
  memset(this,0,0x2640);
  cacao::ObjectBase::ObjectBase(this);
  *(undefined **)(this + 8) = &DAT_0002ef00;
  *(undefined ***)this = &PTR__ProcessResultBase_0002eeb8;
  if (param_3 == 1) {
    local_6c = 1;
LAB_00009a40:
    iVar2 = cacao::ProcessCtrlCapsFactory::getCaps((CameraIndex *)&local_6c,(Caps *)this);
    if (iVar2 < 0) goto LAB_00009dac;
    uVar3 = (**(code **)(*param_1 + 0xf8))(param_1,param_4);
    uVar4 = (**(code **)(*param_1 + 0x108))(param_1,uVar3,"setVideoStabilizationMode",&DAT_00011739)
    ;
    uVar5 = (**(code **)(*param_1 + 0x108))(param_1,uVar3,"setSuperSlowMode",&DAT_00011739);
    uVar6 = (**(code **)(*param_1 + 0x108))(param_1,uVar3,"setClimaxRecognitionMode",&DAT_00011739);
    uVar7 = (**(code **)(*param_1 + 0x108))(param_1,uVar3,"setBurstMode",&DAT_00011739);
    uVar8 = (**(code **)(*param_1 + 0x108))(param_1,uVar3,"addSuperSlowFrameNum",&DAT_00011739);
    uVar9 = (**(code **)(*param_1 + 0x108))(param_1,uVar3,"addHighFrameRateSupportedInfo","(III)V");
    uVar10 = (**(code **)(*param_1 + 0x108))(param_1,uVar3,"addSteadyShotSupportedInfo","(III)V");
    uVar11 = (**(code **)(*param_1 + 0x108))
                       (param_1,uVar3,"addIntelligentActiveSupportedInfo","(III)V");
    uVar12 = (**(code **)(*param_1 + 0x108))(param_1,uVar3,"addSuperSlowSupportedInfo","(III)V");
    lVar13 = (**(code **)(*param_1 + 0x108))(param_1,uVar3,"setVideoHdrMode",&DAT_00011739);
    lVar14 = (**(code **)(*param_1 + 0x78))(param_1);
    if (lVar14 != 0) {
      (**(code **)(*param_1 + 0x88))(param_1);
    }
    _JNIEnv::CallVoidMethod
              (param_1,param_4,uVar4,(ulong)*(uint *)(this + 0x10),param_5,param_6,param_7,param_8);
    _JNIEnv::CallVoidMethod
              (param_1,param_4,uVar5,(ulong)*(uint *)(this + 0x1220),param_5,param_6,param_7,param_8
              );
    _JNIEnv::CallVoidMethod
              (param_1,param_4,uVar6,(ulong)*(uint *)(this + 0x1a28),param_5,param_6,param_7,param_8
              );
    _JNIEnv::CallVoidMethod
              (param_1,param_4,uVar7,(ulong)*(uint *)(this + 0x1a2c),param_5,param_6,param_7,param_8
              );
    if (lVar13 != 0) {
      _JNIEnv::CallVoidMethod
                (param_1,param_4,lVar13,(ulong)*(uint *)(this + 0x1a30),param_5,param_6,param_7,
                 param_8);
    }
    if (*(int *)(this + 0xc1c) != 0) {
      uVar17 = 0;
      pOVar18 = this + 0xc24;
      pOVar19 = this + 0x1020;
      do {
        _JNIEnv::CallVoidMethod
                  (param_1,param_4,uVar9,(ulong)*(uint *)(pOVar18 + -4),(ulong)*(uint *)pOVar18,
                   (ulong)*(uint *)pOVar19,param_7,param_8);
        uVar17 = uVar17 + 1;
        pOVar18 = pOVar18 + 8;
        pOVar19 = pOVar19 + 4;
      } while (uVar17 < *(uint *)(this + 0xc1c));
    }
    if (*(int *)(this + 0x14) != 0) {
      uVar17 = 0;
      pOVar18 = this + 0x1c;
      pOVar19 = this + 0x418;
      do {
        _JNIEnv::CallVoidMethod
                  (param_1,param_4,uVar10,(ulong)*(uint *)(pOVar18 + -4),(ulong)*(uint *)pOVar18,
                   (ulong)*(uint *)pOVar19,param_7,param_8);
        uVar17 = uVar17 + 1;
        pOVar18 = pOVar18 + 8;
        pOVar19 = pOVar19 + 4;
      } while (uVar17 < *(uint *)(this + 0x14));
    }
    if (*(int *)(this + 0x618) != 0) {
      uVar17 = 0;
      pOVar18 = this + 0x620;
      pOVar19 = this + 0xa1c;
      do {
        _JNIEnv::CallVoidMethod
                  (param_1,param_4,uVar11,(ulong)*(uint *)(pOVar18 + -4),(ulong)*(uint *)pOVar18,
                   (ulong)*(uint *)pOVar19,param_7,param_8);
        uVar17 = uVar17 + 1;
        pOVar18 = pOVar18 + 8;
        pOVar19 = pOVar19 + 4;
      } while (uVar17 < *(uint *)(this + 0x618));
    }
    if (*(int *)(this + 0x1224) != 0) {
      uVar17 = 0;
      pOVar19 = this + 0x1628;
      pOVar18 = this + 0x122c;
      do {
        uVar15 = (ulong)*(uint *)pOVar18;
        uVar16 = (ulong)*(uint *)pOVar19;
        _JNIEnv::CallVoidMethod
                  (param_1,param_4,uVar12,(ulong)*(uint *)(pOVar18 + -4),uVar15,uVar16,param_7,
                   param_8);
        _JNIEnv::CallVoidMethod
                  (param_1,param_4,uVar8,(ulong)*(uint *)(pOVar19 + 0x200),uVar15,uVar16,param_7,
                   param_8);
        uVar17 = uVar17 + 1;
        pOVar18 = pOVar18 + 8;
        pOVar19 = pOVar19 + 4;
      } while (uVar17 < *(uint *)(this + 0x1224));
    }
  }
  else {
    if (param_3 == 0) {
      local_6c = 0;
      goto LAB_00009a40;
    }
    iVar2 = -0x67;
LAB_00009dac:
    if (this == (ObjectBase *)0x0) goto LAB_00009dcc;
  }
  (**(code **)(*(long *)this + 8))(this);
LAB_00009dcc:
  if (*(long *)(lVar1 + 0x28) != local_68) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return iVar2;
}



// _JNIEnv::CallVoidMethod(_jobject*, _jmethodID*, ...)

void _JNIEnv::CallVoidMethod
               (long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,...)

{
  long lVar1;
  long lVar2;
  undefined1 auStack_a0 [8];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined1 *local_70;
  undefined1 **ppuStack_68;
  undefined1 *puStack_60;
  undefined8 uStack_58;
  
  lVar1 = tpidr_el0;
  lVar2 = *(long *)(lVar1 + 0x28);
  puStack_60 = auStack_a0;
  ppuStack_68 = &local_70;
  uStack_58 = 0xffffff80ffffffd8;
  local_98 = param_4;
  local_90 = param_5;
  uStack_88 = param_6;
  local_80 = param_7;
  uStack_78 = param_8;
  local_70 = (undefined1 *)register0x00000008;
  (**(code **)(*param_1 + 0x1f0))();
  if (*(long *)(lVar1 + 0x28) == lVar2) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



undefined8
Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeSetConfig
          (long *param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined **local_60;
  undefined *puStack_58;
  undefined4 local_50;
  long local_48;
  
  lVar1 = tpidr_el0;
  local_48 = *(long *)(lVar1 + 0x28);
  lVar3 = (**(code **)(*param_1 + 0xf8))(param_1,param_4);
  if (lVar3 == 0) {
    pcVar6 = "%s: Failed get object class BypassCameraParameters.";
    goto LAB_0000a0b4;
  }
  lVar3 = (**(code **)(*param_1 + 0x2f0))(param_1,lVar3,&DAT_00011898,"Ljava/util/Map;");
  if (lVar3 != 0) {
    lVar4 = (**(code **)(*param_1 + 0x30))(param_1,"java/util/Map");
    if (lVar4 == 0) {
      pcVar6 = "%s: Failed find class java/util/Map.";
    }
    else {
      lVar3 = (**(code **)(*param_1 + 0x2f8))(param_1,param_4,lVar3);
      if (lVar3 == 0) {
        pcVar6 = "%s: Failed get object field for java/util/Map.";
      }
      else {
        lVar4 = (**(code **)(*param_1 + 0x108))
                          (param_1,lVar4,&DAT_0001190f,"(Ljava/lang/Object;)Ljava/lang/Object;");
        if (lVar4 != 0) {
          cacao::ObjectBase::ObjectBase((ObjectBase *)&local_60);
          local_50 = 0;
          local_60 = &PTR__ProcessResultBase_0002ef38;
          puStack_58 = &DAT_0002ef98;
          uVar5 = (**(code **)(*param_1 + 0x538))(param_1,"climax-recognition");
          lVar3 = _JNIEnv::CallObjectMethod
                            (param_1,lVar3,lVar4,uVar5,param_5,param_6,param_7,param_8);
          (**(code **)(*param_1 + 0xb8))(param_1,uVar5);
          if (lVar3 == 0) {
LAB_0000a128:
            (**(code **)(*(long *)*param_3 + 0x28))((long *)*param_3,&local_60);
            uVar5 = 0;
          }
          else {
            pcVar6 = (char *)(**(code **)(*param_1 + 0x548))(param_1,lVar3,0);
            iVar2 = strcmp(pcVar6,"on");
            if (iVar2 == 0) {
              local_50 = 2;
LAB_0000a10c:
              (**(code **)(*param_1 + 0x550))(param_1,lVar3,pcVar6);
              goto LAB_0000a128;
            }
            iVar2 = strcmp(pcVar6,"auto");
            if (iVar2 == 0) {
              local_50 = 1;
              goto LAB_0000a10c;
            }
            iVar2 = strcmp(pcVar6,"off");
            if (iVar2 == 0) {
              local_50 = 0;
              goto LAB_0000a10c;
            }
            __android_log_print(6,0,"%s: Invalid climax recognition value. val: %s",
                                "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeSetConfig"
                                ,pcVar6);
            (**(code **)(*param_1 + 0x550))(param_1,lVar3,pcVar6);
            uVar5 = 0xffffffff;
          }
          cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_60);
          goto LAB_0000a0cc;
        }
        pcVar6 = "%s: Failed get method id for java/util/Map.get(Object).";
      }
    }
LAB_0000a0b4:
    __android_log_print(6,0,pcVar6,
                        "Java_com_sonymobile_imageprocessor_bypasscamera2_BypassCamera_nativeSetConfig"
                       );
  }
  uVar5 = 0xffffffff;
LAB_0000a0cc:
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return uVar5;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// _JNIEnv::CallObjectMethod(_jobject*, _jmethodID*, ...)

void _JNIEnv::CallObjectMethod
               (long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,...)

{
  long lVar1;
  long lVar2;
  undefined1 auStack_a0 [8];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined1 *local_70;
  undefined1 **ppuStack_68;
  undefined1 *puStack_60;
  undefined8 uStack_58;
  
  lVar1 = tpidr_el0;
  lVar2 = *(long *)(lVar1 + 0x28);
  puStack_60 = auStack_a0;
  ppuStack_68 = &local_70;
  uStack_58 = 0xffffff80ffffffd8;
  local_98 = param_4;
  local_90 = param_5;
  uStack_88 = param_6;
  local_80 = param_7;
  uStack_78 = param_8;
  local_70 = (undefined1 *)register0x00000008;
  (**(code **)(*param_1 + 0x118))();
  if (*(long *)(lVar1 + 0x28) == lVar2) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// cacao::ProcessResultBase::~ProcessResultBase()

void __thiscall cacao::ProcessResultBase::~ProcessResultBase(ProcessResultBase *this)

{
  cacao::ObjectBase::~ObjectBase((ObjectBase *)this);
  return;
}



undefined8 JNI_OnLoad(undefined8 param_1)

{
  gJavaVMPointer = param_1;
  return 0x10006;
}



void getJNIEnv(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = tpidr_el0;
  local_28 = *(long *)(lVar1 + 0x28);
  local_30 = 0;
  uVar3 = 0;
  if ((gJavaVMPointer != (long *)0x0) &&
     (iVar2 = (**(code **)(*gJavaVMPointer + 0x30))(gJavaVMPointer,&local_30,0x10006),
     uVar3 = local_30, iVar2 != 0)) {
    uVar3 = 0;
  }
  if (*(long *)(lVar1 + 0x28) != local_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail(uVar3);
  }
  return;
}



void getSurface(long *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x30))(param_1,"android/view/Surface");
  uVar1 = (**(code **)(*param_1 + 0xa8))(param_1,uVar1);
  uVar1 = (**(code **)(*param_1 + 0x2f0))(param_1,uVar1,"mNativeObject",&DAT_000119e2);
                    // WARNING: Could not recover jumptable at 0x0000a300. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(*param_1 + 0x328))(param_1,param_2,uVar1);
  return;
}



// cacao::ProcessCtrlSuperSlowMode::~ProcessCtrlSuperSlowMode()

void __thiscall
cacao::ProcessCtrlSuperSlowMode::~ProcessCtrlSuperSlowMode(ProcessCtrlSuperSlowMode *this)

{
  void *extraout_x1;
  
  cacao::ObjectBase::~ObjectBase((ObjectBase *)this);
  cacao::ObjectBase::operator_delete((ObjectBase *)this,extraout_x1);
  return;
}



// cacao::Caps::getClassName() const

undefined * cacao::Caps::getClassName(void)

{
  return &DAT_00011b8c;
}



// non-virtual thunk to cacao::Caps::getSerializedSize() const

undefined8 __thiscall cacao::Caps::getSerializedSize(void)

{
  return 0x262c;
}



// cacao::Caps::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall cacao::Caps::serialize(Caps *this,long param_1)

{
  void *__dest;
  undefined8 uVar1;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x188) == 0)) ||
     ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 0x262c)) {
    uVar1 = 0xffffff99;
  }
  else {
    __dest = (void *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    memcpy(__dest,this + 0x10,0xc0c);
    memcpy((void *)((long)__dest + 0xc0c),this + 0xc1c,0x604);
    memcpy((void *)((long)__dest + 0x1210),this + 0x1220,0x808);
    *(undefined4 *)((long)__dest + 0x1a18) = *(undefined4 *)(this + 0x1a28);
    *(undefined4 *)((long)__dest + 0x1a1c) = *(undefined4 *)(this + 0x1a2c);
    memcpy((void *)((long)__dest + 0x1a20),this + 0x1a30,0xc0c);
    uVar1 = 0;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x262c;
  }
  return uVar1;
}



// cacao::Caps::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall cacao::Caps::deserialize(Caps *this,long param_1)

{
  void *__src;
  undefined8 uVar1;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x188) == 0)) ||
     ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 0x262c)) {
    uVar1 = 0xffffff99;
  }
  else {
    __src = (void *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    memcpy(this + 0x10,__src,0xc0c);
    memcpy(this + 0xc1c,(void *)((long)__src + 0xc0c),0x604);
    memcpy(this + 0x1220,(void *)((long)__src + 0x1210),0x808);
    *(undefined4 *)(this + 0x1a28) = *(undefined4 *)((long)__src + 0x1a18);
    *(undefined4 *)(this + 0x1a2c) = *(undefined4 *)((long)__src + 0x1a1c);
    memcpy(this + 0x1a30,(void *)((long)__src + 0x1a20),0xc0c);
    uVar1 = 0;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x262c;
  }
  return uVar1;
}



// non-virtual thunk to cacao::ProcessCtrlSuperSlowMode::~ProcessCtrlSuperSlowMode()

void __thiscall
cacao::ProcessCtrlSuperSlowMode::~ProcessCtrlSuperSlowMode(ProcessCtrlSuperSlowMode *this)

{
  cacao::ObjectBase::~ObjectBase((ObjectBase *)(this + -8));
  return;
}



// non-virtual thunk to cacao::ProcessCtrlSuperSlowMode::~ProcessCtrlSuperSlowMode()

void __thiscall
cacao::ProcessCtrlSuperSlowMode::~ProcessCtrlSuperSlowMode(ProcessCtrlSuperSlowMode *this)

{
  void *extraout_x1;
  
  cacao::ObjectBase::~ObjectBase((ObjectBase *)(this + -8));
  cacao::ObjectBase::operator_delete((ObjectBase *)(this + -8),extraout_x1);
  return;
}



// non-virtual thunk to cacao::Caps::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall cacao::Caps::serialize(Caps *this,long param_1)

{
  void *__dest;
  undefined8 uVar1;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x188) == 0)) ||
     ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 0x262c)) {
    uVar1 = 0xffffff99;
  }
  else {
    __dest = (void *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    memcpy(__dest,this + 8,0xc0c);
    memcpy((void *)((long)__dest + 0xc0c),this + 0xc14,0x604);
    memcpy((void *)((long)__dest + 0x1210),this + 0x1218,0x808);
    *(undefined4 *)((long)__dest + 0x1a18) = *(undefined4 *)(this + 0x1a20);
    *(undefined4 *)((long)__dest + 0x1a1c) = *(undefined4 *)(this + 0x1a24);
    memcpy((void *)((long)__dest + 0x1a20),this + 0x1a28,0xc0c);
    uVar1 = 0;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x262c;
  }
  return uVar1;
}



// non-virtual thunk to cacao::Caps::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall cacao::Caps::deserialize(Caps *this,long param_1)

{
  void *__src;
  undefined8 uVar1;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x188) == 0)) ||
     ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 0x262c)) {
    uVar1 = 0xffffff99;
  }
  else {
    __src = (void *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    memcpy(this + 8,__src,0xc0c);
    memcpy(this + 0xc14,(void *)((long)__src + 0xc0c),0x604);
    memcpy(this + 0x1218,(void *)((long)__src + 0x1210),0x808);
    *(undefined4 *)(this + 0x1a20) = *(undefined4 *)((long)__src + 0x1a18);
    *(undefined4 *)(this + 0x1a24) = *(undefined4 *)((long)__src + 0x1a1c);
    memcpy(this + 0x1a28,(void *)((long)__src + 0x1a20),0xc0c);
    uVar1 = 0;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x262c;
  }
  return uVar1;
}



// cacao::ProcessCtrlDynamicParameterConfig::getClassName() const

char * cacao::ProcessCtrlDynamicParameterConfig::getClassName(void)

{
  return "ProcessCtrlDynamicParameterConfig";
}



// cacao::ProcessCtrlDynamicParameterConfig::getConfigId() const

undefined8 cacao::ProcessCtrlDynamicParameterConfig::getConfigId(void)

{
  return 0x65;
}



// cacao::ProcessCtrlDynamicParameterConfig::clone() const

ObjectBase * cacao::ProcessCtrlDynamicParameterConfig::clone(long param_1,ulong param_2)

{
  undefined4 uVar1;
  ObjectBase *this;
  
  this = cacao::ObjectBase::operator_new((ObjectBase *)0x18,param_2);
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  cacao::ObjectBase::ObjectBase(this);
  *(undefined4 *)(this + 0x10) = uVar1;
  *(undefined **)(this + 8) = &DAT_0002ef98;
  *(undefined ***)this = &PTR__ProcessResultBase_0002ef38;
  return this;
}



// cacao::ProcessCtrlDynamicParameterConfig::copy(cacao::ProcessConfigBase const*)

void __thiscall
cacao::ProcessCtrlDynamicParameterConfig::copy(ProcessCtrlDynamicParameterConfig *this,long param_1)

{
  if (param_1 != 0) {
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  }
  return;
}



// non-virtual thunk to cacao::ProcessCtrlDynamicParameterConfig::getSerializedSize() const

undefined8 __thiscall cacao::ProcessCtrlDynamicParameterConfig::getSerializedSize(void)

{
  return 4;
}



// cacao::ProcessCtrlDynamicParameterConfig::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall
cacao::ProcessCtrlDynamicParameterConfig::serialize
          (ProcessCtrlDynamicParameterConfig *this,long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) != 0) {
    uVar1 = *(uint *)(param_1 + 400);
    uVar2 = 0xffffff99;
    if ((uVar1 <= *(uint *)(param_1 + 0x184)) && (uVar1 + 4 <= *(uint *)(param_1 + 0x184))) {
      uVar2 = 0;
      *(undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1) = *(undefined4 *)(this + 0x10);
      *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 4;
    }
    return uVar2;
  }
  return 0xffffff99;
}



// cacao::ProcessCtrlDynamicParameterConfig::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall
cacao::ProcessCtrlDynamicParameterConfig::deserialize
          (ProcessCtrlDynamicParameterConfig *this,long param_1)

{
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) != 0) {
    if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 4) {
      return 0xffffff99;
    }
    *(undefined4 *)(this + 0x10) =
         *(undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 4;
    return 0;
  }
  return 0xffffff99;
}



// non-virtual thunk to
// cacao::ProcessCtrlDynamicParameterConfig::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall
cacao::ProcessCtrlDynamicParameterConfig::serialize
          (ProcessCtrlDynamicParameterConfig *this,long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) != 0) {
    uVar1 = *(uint *)(param_1 + 400);
    uVar2 = 0xffffff99;
    if ((uVar1 <= *(uint *)(param_1 + 0x184)) && (uVar1 + 4 <= *(uint *)(param_1 + 0x184))) {
      uVar2 = 0;
      *(undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1) = *(undefined4 *)(this + 8);
      *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 4;
    }
    return uVar2;
  }
  return 0xffffff99;
}



// non-virtual thunk to
// cacao::ProcessCtrlDynamicParameterConfig::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall
cacao::ProcessCtrlDynamicParameterConfig::deserialize
          (ProcessCtrlDynamicParameterConfig *this,long param_1)

{
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) != 0) {
    if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 4) {
      return 0xffffff99;
    }
    *(undefined4 *)(this + 8) =
         *(undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 4;
    return 0;
  }
  return 0xffffff99;
}



undefined8 BypassCameraPhoto_initialize(long *param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  ObjectBase *pOVar2;
  SortedVectorImpl *pSVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong extraout_x1;
  ulong extraout_x1_00;
  ulong extraout_x1_01;
  ulong extraout_x1_02;
  
  pthread_mutex_lock((pthread_mutex_t *)(param_3 + 0x90));
  *(undefined1 *)(param_3 + 0xb8) = 1;
  puVar1 = operator_new(8);
  *puVar1 = &PTR_do_destroy_0002efd0;
  *(undefined8 **)(param_3 + 0x20) = puVar1;
  pOVar2 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1);
  cacao::ObjectBase::ObjectBase(pOVar2);
  *(long *)(pOVar2 + 0x18) = param_3;
  *(undefined8 *)(pOVar2 + 0x30) = 0;
  *(undefined8 *)(pOVar2 + 0x10) = 0xffffffff00000000;
  *(undefined8 *)(pOVar2 + 0x24) = 0;
  *(undefined4 *)(pOVar2 + 0x2c) = 0xffffffff;
  *(undefined4 *)(pOVar2 + 0x38) = 0xffff0000;
  pOVar2[0x3c] = (ObjectBase)0xff;
  *(undefined **)(pOVar2 + 8) = &DAT_0002f130;
  *(undefined ***)pOVar2 = &PTR__ProcessResultBase_0002f0c0;
  *(ObjectBase **)(param_3 + 0x28) = pOVar2;
  *(undefined4 *)(pOVar2 + 0x20) = 0;
  puVar1 = operator_new(8);
  *puVar1 = &PTR_do_destroy_0002f000;
  *(undefined8 **)(param_3 + 0x30) = puVar1;
  puVar1 = operator_new(8);
  *puVar1 = &PTR_do_destroy_0002f060;
  *(undefined8 **)(param_3 + 0x58) = puVar1;
  pOVar2 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1_00);
  cacao::ObjectBase::ObjectBase(pOVar2);
  *(undefined8 *)(pOVar2 + 0x10) = 0xffffffff00000000;
  *(undefined **)(pOVar2 + 8) = &DAT_0002f130;
  *(undefined ***)pOVar2 = &PTR__ProcessResultBase_0002f0c0;
  *(long *)(pOVar2 + 0x18) = param_3;
  *(undefined8 *)(pOVar2 + 0x30) = 0;
  *(undefined4 *)(pOVar2 + 0x38) = 0xffff0000;
  pOVar2[0x3c] = (ObjectBase)0xff;
  *(undefined8 *)(pOVar2 + 0x28) = 0xffffffff00000000;
  *(undefined8 *)(pOVar2 + 0x20) = 0;
  *(ObjectBase **)(param_3 + 0x60) = pOVar2;
  puVar1 = operator_new(8);
  *puVar1 = &PTR_do_destroy_0002f090;
  *(undefined8 **)(param_3 + 0x68) = puVar1;
  pOVar2 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1_01);
  cacao::ObjectBase::ObjectBase(pOVar2);
  *(undefined8 *)(pOVar2 + 0x10) = 0xffffffff00000000;
  *(long *)(pOVar2 + 0x18) = param_3;
  *(undefined **)(pOVar2 + 8) = &DAT_0002f130;
  *(undefined ***)pOVar2 = &PTR__ProcessResultBase_0002f0c0;
  *(undefined8 *)(pOVar2 + 0x30) = 0;
  *(undefined4 *)(pOVar2 + 0x38) = 0xffff0000;
  pOVar2[0x3c] = (ObjectBase)0xff;
  *(undefined8 *)(pOVar2 + 0x28) = 0xffffffff00000000;
  *(undefined8 *)(pOVar2 + 0x20) = 0;
  *(ObjectBase **)(param_3 + 0x70) = pOVar2;
  puVar1 = operator_new(8);
  *puVar1 = &PTR_do_destroy_0002f030;
  *(undefined8 **)(param_3 + 0x48) = puVar1;
  pOVar2 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1_02);
  cacao::ObjectBase::ObjectBase(pOVar2);
  *(undefined8 *)(pOVar2 + 0x10) = 0xffffffff00000000;
  *(long *)(pOVar2 + 0x18) = param_3;
  *(undefined **)(pOVar2 + 8) = &DAT_0002f130;
  *(undefined ***)pOVar2 = &PTR__ProcessResultBase_0002f0c0;
  *(undefined8 *)(pOVar2 + 0x24) = 0;
  *(undefined4 *)(pOVar2 + 0x2c) = 0xffffffff;
  *(undefined8 *)(pOVar2 + 0x30) = 0;
  *(undefined4 *)(pOVar2 + 0x38) = 0xffff0000;
  pOVar2[0x3c] = (ObjectBase)0xff;
  *(ObjectBase **)(param_3 + 0x50) = pOVar2;
  *(undefined4 *)(pOVar2 + 0x20) = 1;
  *(undefined4 *)(param_3 + 0x38) = 0;
  pSVar3 = operator_new(0x30);
  android::SortedVectorImpl::SortedVectorImpl(pSVar3,0x10,7);
  *(undefined8 *)(pSVar3 + 0x28) = 0;
  *(undefined ***)pSVar3 = &PTR__SortedVector_0002f168;
  *(SortedVectorImpl **)(param_3 + 0x40) = pSVar3;
  pSVar3 = operator_new(0x30);
  android::SortedVectorImpl::SortedVectorImpl(pSVar3,0x10,7);
  *(undefined8 *)(pSVar3 + 0x28) = 0;
  *(undefined ***)pSVar3 = &PTR__SortedVector_0002f1c0;
  *(SortedVectorImpl **)(param_3 + 0x88) = pSVar3;
  uVar4 = (**(code **)(*param_1 + 0x30))
                    (param_1,"com/sonymobile/imageprocessor/bypasscamera2/BypassCamera");
  uVar5 = (**(code **)(*param_1 + 0x108))(param_1,uVar4,"callbackFromNative","(IIIZZZIII)V");
  (**(code **)(*param_1 + 0xb8))(param_1,uVar4);
  uVar4 = (**(code **)(*param_1 + 0xa8))(param_1,param_2);
  *(undefined8 *)(param_3 + 0x10) = uVar4;
  *(undefined8 *)(param_3 + 0x18) = uVar5;
  pthread_mutex_unlock((pthread_mutex_t *)(param_3 + 0x90));
  return 0;
}



void BypassCameraPhoto_finalize(long *param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  void *pvVar5;
  long *plVar6;
  SortedVectorImpl *pSVar7;
  ulong uVar8;
  
  lVar1 = tpidr_el0;
  lVar4 = *(long *)(lVar1 + 0x28);
  if (*(int *)((long)param_3 + 0x1d4) != 0) {
    __android_log_print(5,0,"%s: wrong mDequeueCounter=%d","BypassCameraPhoto_finalize");
  }
  if (((long *)*param_3 != (long *)0x0) &&
     (iVar2 = (**(code **)(*(long *)*param_3 + 0x20))(), iVar2 != 0)) {
    __android_log_print(6,0,"%s: stop cacao ret=%d","BypassCameraPhoto_finalize",iVar2);
  }
  pthread_mutex_lock((pthread_mutex_t *)(param_3 + 0x12));
  *(undefined1 *)(param_3 + 0x17) = 0;
  if (param_3[2] != 0) {
    (**(code **)(*param_1 + 0xb0))(param_1);
    param_3[2] = 0;
  }
  if ((long *)param_3[4] != (long *)0x0) {
    (**(code **)(*(long *)param_3[4] + 8))();
  }
  param_3[4] = 0;
  if ((long *)param_3[5] != (long *)0x0) {
    (**(code **)(*(long *)param_3[5] + 8))();
  }
  param_3[5] = 0;
  if ((long *)param_3[6] != (long *)0x0) {
    (**(code **)(*(long *)param_3[6] + 8))();
  }
  param_3[6] = 0;
  if ((long *)param_3[9] != (long *)0x0) {
    (**(code **)(*(long *)param_3[9] + 8))();
  }
  param_3[9] = 0;
  if ((long *)param_3[10] != (long *)0x0) {
    (**(code **)(*(long *)param_3[10] + 8))();
  }
  param_3[10] = 0;
  if ((long *)param_3[0xb] != (long *)0x0) {
    (**(code **)(*(long *)param_3[0xb] + 8))();
  }
  param_3[0xb] = 0;
  if ((long *)param_3[0xc] != (long *)0x0) {
    (**(code **)(*(long *)param_3[0xc] + 8))();
  }
  param_3[0xc] = 0;
  if ((long *)param_3[0xd] != (long *)0x0) {
    (**(code **)(*(long *)param_3[0xd] + 8))();
  }
  param_3[0xd] = 0;
  if ((long *)param_3[0xe] != (long *)0x0) {
    (**(code **)(*(long *)param_3[0xe] + 8))();
  }
  pvVar5 = (void *)param_3[8];
  param_3[0xe] = 0;
  if (pvVar5 != (void *)0x0) {
    if (*(long *)((long)pvVar5 + 0x10) != 0) {
      uVar8 = 0;
      do {
        lVar3 = android::SortedVectorImpl::indexOf(pvVar5);
        if (lVar3 < 0) {
          plVar6 = *(long **)((long)pvVar5 + 0x28);
        }
        else {
          plVar6 = *(long **)(*(long *)((long)pvVar5 + 8) + lVar3 * 0x10 + 8);
        }
        if (plVar6 != (long *)0x0) {
          pvVar5 = (void *)(**(code **)(*plVar6 + 0x40))(plVar6);
          if (pvVar5 != (void *)0x0) {
            operator_delete(pvVar5);
          }
          (**(code **)(*plVar6 + 8))(plVar6);
          android::SortedVectorImpl::remove((void *)param_3[8]);
        }
        pvVar5 = (void *)param_3[8];
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(ulong *)((long)pvVar5 + 0x10));
    }
    android::VectorImpl::clear();
    pSVar7 = (SortedVectorImpl *)param_3[8];
    if (pSVar7 != (SortedVectorImpl *)0x0) {
      *(undefined ***)pSVar7 = &PTR__SortedVector_0002f168;
      android::VectorImpl::finish_vector();
      android::SortedVectorImpl::~SortedVectorImpl(pSVar7);
      operator_delete(pSVar7);
    }
    param_3[8] = 0;
  }
  pvVar5 = (void *)param_3[0x11];
  if (pvVar5 != (void *)0x0) {
    if (*(long *)((long)pvVar5 + 0x10) != 0) {
      uVar8 = 0;
      do {
        lVar3 = android::SortedVectorImpl::indexOf(pvVar5);
        if (lVar3 < 0) {
          pvVar5 = *(void **)((long)pvVar5 + 0x28);
        }
        else {
          pvVar5 = *(void **)(*(long *)((long)pvVar5 + 8) + lVar3 * 0x10 + 8);
        }
        if (pvVar5 != (void *)0x0) {
          operator_delete(pvVar5);
          android::SortedVectorImpl::remove((void *)param_3[0x11]);
        }
        pvVar5 = (void *)param_3[0x11];
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(ulong *)((long)pvVar5 + 0x10));
    }
    android::VectorImpl::clear();
    pSVar7 = (SortedVectorImpl *)param_3[0x11];
    if (pSVar7 != (SortedVectorImpl *)0x0) {
      *(undefined ***)pSVar7 = &PTR__SortedVector_0002f1c0;
      android::VectorImpl::finish_vector();
      android::SortedVectorImpl::~SortedVectorImpl(pSVar7);
      operator_delete(pSVar7);
    }
    param_3[0x11] = 0;
  }
  BypassCameraBurstBufferManager_deleteBuffers((long)param_3);
  BypassCameraBurstBufferManager_finalizeSurface((long)param_3);
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_3 + 0x12));
  if (*(long *)(lVar1 + 0x28) == lVar4) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(iVar2);
}



undefined4
BypassCameraPhoto_changeToPhotoMode
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined **local_e0;
  undefined *puStack_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 local_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined **local_a0;
  undefined *puStack_98;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  long local_68;
  
  lVar2 = tpidr_el0;
  local_68 = *(long *)(lVar2 + 0x28);
  iVar3 = (**(code **)(*(long *)*param_3 + 0x20))();
  if ((iVar3 == 0) ||
     (__android_log_print(6,0,"%s: stop cacao ret=%d","BypassCameraPhoto_changeToPhotoMode",iVar3),
     iVar3 != -0x6e)) {
    *(undefined4 *)(param_3 + 0xf) = param_4;
    *(undefined4 *)((long)param_3 + 0x7c) = param_5;
    *(undefined4 *)(param_3 + 0x10) = param_6;
    *(undefined4 *)((long)param_3 + 0x84) = param_7;
    __android_log_print(3,0,"[Debug] %s: burstNum=%d","BypassCameraPhoto_changeToPhotoMode",param_8)
    ;
    *(undefined4 *)(param_3 + 0x2e) = param_8;
    cacao::ObjectBase::ObjectBase((ObjectBase *)&local_a0);
    local_90 = 0;
    uStack_8c = 0xffffffff;
    uStack_88 = 0;
    uStack_84 = 0;
    uStack_80 = 0;
    uStack_7c = 0;
    uStack_78 = 0;
    uStack_74 = 0;
    local_a0 = &PTR__ProcessResultBase_0002f218;
    puStack_98 = &DAT_0002f268;
    uStack_70 = 0;
    uVar4 = *(undefined4 *)(param_3 + 1);
    uVar1 = *(undefined4 *)((long)param_3 + 0xc);
    cacao::ObjectBase::ObjectBase((ObjectBase *)&local_e0);
    uStack_b4 = 0;
    uStack_b0 = 0;
    local_e0 = &PTR__ProcessResultBase_0002f2a0;
    puStack_d8 = &DAT_0002f2f0;
    uStack_74 = 0;
    uStack_70 = 0;
    local_d0 = uVar1;
    local_cc = uVar4;
    uStack_c8 = param_4;
    uStack_c4 = param_5;
    uStack_c0 = param_6;
    local_bc = param_7;
    uStack_b8 = param_8;
    local_90 = uVar1;
    uStack_8c = uVar4;
    uStack_88 = param_4;
    uStack_84 = param_5;
    uStack_80 = param_6;
    uStack_7c = param_7;
    uStack_78 = param_8;
    cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_e0);
    iVar3 = (**(code **)(*(long *)*param_3 + 0x18))((long *)*param_3,&local_a0);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      __android_log_print(6,0,"%s: Start bypass camera process failed. ERR=%d",
                          "BypassCameraPhoto_changeToPhotoMode",iVar3);
      uVar4 = 0xffffffff;
    }
    cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_a0);
  }
  else {
    uVar4 = 0xfffffffe;
  }
  if (*(long *)(lVar2 + 0x28) == local_68) {
    return uVar4;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



undefined8
BypassCameraPhoto_requestSnapshotReady(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  undefined **local_1a0;
  undefined *puStack_198;
  undefined4 local_190;
  undefined2 local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined2 local_168;
  undefined1 local_67;
  undefined8 local_60;
  undefined1 local_58;
  undefined4 local_54;
  undefined1 local_50;
  undefined8 local_4c;
  undefined8 local_44;
  undefined1 local_3c;
  long local_38;
  
  lVar1 = tpidr_el0;
  local_38 = *(long *)(lVar1 + 0x28);
  cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1a0);
  local_188 = 0;
  local_67 = 0;
  local_1a0 = &PTR__ProcessResultBase_0002f328;
  puStack_198 = &DAT_0002f380;
  local_60 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_168 = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_170 = 0;
  local_44 = 0;
  local_4c = 0;
  local_3c = 0;
  local_190 = 0;
  (**(code **)(*(long *)*param_3 + 0x40))((long *)*param_3,&local_1a0,0,param_3[4],param_3[5]);
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_1a0);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return 0;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// imageprocessor::BypassCameraPhoto_requestSnapshot(_JNIEnv*, _jobject*,
// imageprocessor::BypassCameraContext*, unsigned char, unsigned char, double, double, double,
// unsigned char, _jstring*, unsigned char, int, unsigned char, int, unsigned char, int, int, int,
// int, unsigned char)

undefined4
imageprocessor::BypassCameraPhoto_requestSnapshot
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,long *param_4,
          undefined8 param_5_00,undefined8 *param_6,char param_7,char param_8,char param_9,
          undefined8 param_10,char param_11,int param_12,char param_13,int param_14,char param_15,
          undefined4 param_16,undefined4 param_17,undefined4 param_18,undefined4 param_19,
          char param_20)

{
  long lVar1;
  int iVar2;
  char *__src;
  undefined8 *puVar3;
  VectorImpl *this;
  ObjectBase *this_00;
  ulong extraout_x1;
  ulong uVar4;
  undefined4 uVar5;
  long local_360;
  undefined1 auStack_354 [4];
  undefined4 local_350;
  ObjectBase *local_348;
  undefined1 local_340;
  undefined1 local_33f;
  undefined8 local_338;
  undefined8 uStack_330;
  undefined8 local_328;
  undefined1 local_320;
  char acStack_31f [256];
  undefined1 local_21f;
  long local_218;
  bool local_210;
  undefined4 local_20c;
  undefined1 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined1 local_1f4;
  undefined **local_1f0;
  undefined *puStack_1e8;
  undefined4 local_1e0;
  undefined2 local_1d8 [4];
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined2 local_1b8;
  undefined1 local_b7;
  undefined8 local_b0;
  undefined1 local_a8;
  undefined4 local_a4;
  undefined1 local_a0;
  undefined8 local_9c;
  undefined8 local_94;
  undefined1 local_8c;
  long local_88;
  
  lVar1 = tpidr_el0;
  local_88 = *(long *)(lVar1 + 0x28);
  pthread_mutex_lock((pthread_mutex_t *)(param_6 + 0x12));
  *(int *)(param_6 + 7) = *(int *)(param_6 + 7) + 1;
  cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1f0);
  local_340 = param_7 != '\0';
  local_33f = param_8 != '\0';
  local_1f0 = &PTR__ProcessResultBase_0002f328;
  local_320 = param_9 != '\0';
  puStack_1e8 = &DAT_0002f380;
  local_1d8[0] = 0;
  local_b7 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_1c8 = 0;
  uStack_1c0 = 0;
  local_1b8 = 0;
  local_1d0 = 0;
  local_94 = 0;
  local_9c = 0;
  local_8c = 0;
  local_1e0 = 4;
  local_338 = param_1;
  uStack_330 = param_2;
  local_328 = param_3;
  __src = (char *)(**(code **)(*param_4 + 0x548))(param_4,param_10,auStack_354);
  memset(acStack_31f,0,0x100);
  strncpy(acStack_31f,__src,0xff);
  (**(code **)(*param_4 + 0x550))(param_4,param_10,__src);
  local_210 = param_13 != '\0';
  if (param_13 == '\0') goto LAB_0000b370;
  if (param_14 < 0xb4) {
    if (param_14 == 0) {
      local_20c = 0;
      goto LAB_0000b370;
    }
    if (param_14 == 0x5a) {
      local_20c = 1;
      goto LAB_0000b370;
    }
  }
  else {
    if (param_14 == 0xb4) {
      local_20c = 2;
      goto LAB_0000b370;
    }
    if (param_14 == 0x10e) {
      local_20c = 3;
      goto LAB_0000b370;
    }
  }
  local_210 = false;
LAB_0000b370:
  local_21f = param_11 != '\0';
  local_218 = (long)param_12;
  local_208 = param_15 != '\0';
  local_204 = param_16;
  local_1f4 = param_20 != '\0';
  local_200 = param_17;
  local_1fc = param_18;
  local_1f8 = param_19;
  memcpy(local_1d8,&local_340,0x150);
  local_360 = 0;
  iVar2 = BypassCameraBurstBufferManager_dequeueBuffer((long)param_6,&local_360);
  if (iVar2 == 0) {
    __android_log_print(6,0,"%s: dequeueBuffer ok.","BypassCameraPhoto_requestSnapshot");
    local_350 = *(undefined4 *)(param_6 + 7);
    local_348 = (ObjectBase *)local_360;
    android::SortedVectorImpl::add((void *)param_6[0x11]);
    puVar3 = operator_new(0x18);
    *puVar3 = param_6;
    this = operator_new(0x28);
    android::VectorImpl::VectorImpl(this,8,7);
    uVar4 = *(ulong *)(this + 0x10);
    *(undefined ***)this = &PTR__Vector_0002f3b8;
    puVar3[1] = this;
    android::VectorImpl::insertAt(this,local_360 + 8,uVar4);
    *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(param_6 + 7);
    this_00 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1);
    cacao::ObjectBase::ObjectBase(this_00);
    *(undefined8 **)(this_00 + 0x18) = puVar3;
    *(undefined8 *)(this_00 + 0x10) = 0xffffffff00000000;
    *(undefined8 *)(this_00 + 0x30) = 0;
    *(undefined **)(this_00 + 8) = &DAT_0002f130;
    *(undefined ***)this_00 = &PTR__ProcessResultBase_0002f0c0;
    *(undefined4 *)(this_00 + 0x38) = 0xffff0000;
    this_00[0x3c] = (ObjectBase)0xff;
    *(undefined8 *)(this_00 + 0x28) = 0xffffffff00000000;
    *(undefined8 *)(this_00 + 0x20) = 0;
    local_350 = *(undefined4 *)(param_6 + 7);
    local_348 = this_00;
    android::SortedVectorImpl::add((void *)param_6[8]);
    (**(code **)(*(long *)*param_6 + 0x40))
              ((long *)*param_6,&local_1f0,puVar3[1],param_6[6],this_00);
    uVar5 = 0;
    *(undefined4 *)(local_360 + 0x18) = 2;
    *(undefined4 *)(local_360 + 0x1c) = *(undefined4 *)((long)param_6 + 0x16c);
  }
  else {
    __android_log_print(6,0,"%s: dequeueBuffer failed.","BypassCameraPhoto_requestSnapshot");
    uVar5 = 0xffffffff;
  }
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_1f0);
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_6 + 0x12));
  if (*(long *)(lVar1 + 0x28) != local_88) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail(iVar2);
  }
  return uVar5;
}



undefined8
BypassCameraPhoto_requestSnapshotFree(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  undefined **local_1a0;
  undefined *puStack_198;
  undefined4 local_190;
  undefined2 local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined2 local_168;
  undefined1 local_67;
  undefined8 local_60;
  undefined1 local_58;
  undefined4 local_54;
  undefined1 local_50;
  undefined8 local_4c;
  undefined8 local_44;
  undefined1 local_3c;
  long local_38;
  
  lVar1 = tpidr_el0;
  local_38 = *(long *)(lVar1 + 0x28);
  cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1a0);
  local_188 = 0;
  local_67 = 0;
  local_1a0 = &PTR__ProcessResultBase_0002f328;
  puStack_198 = &DAT_0002f380;
  local_60 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_168 = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_170 = 0;
  local_44 = 0;
  local_4c = 0;
  local_3c = 0;
  local_190 = 1;
  (**(code **)(*(long *)*param_3 + 0x40))((long *)*param_3,&local_1a0,0,param_3[9],param_3[10]);
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_1a0);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return 0;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



int BypassCameraPhoto_prepareSnapshot
              (long *param_1,undefined8 param_2,long param_3,undefined8 param_4,int param_5)

{
  int iVar1;
  
  if (*(int *)(param_3 + 0x1d4) != 0) {
    __android_log_print(5,0,"%s: wrong mDequeueCounter=%d","BypassCameraPhoto_prepareSnapshot");
  }
  iVar1 = BypassCameraBurstBufferManager_initializeSurface(param_1,param_4,param_5,param_3);
  if (iVar1 == 0) {
    iVar1 = BypassCameraBurstBufferManager_createBuffers(param_3);
    if (iVar1 == 0) {
      return 0;
    }
    __android_log_print(6,0,"%s: createBuffers() failed.","BypassCameraPhoto_prepareSnapshot");
    BypassCameraBurstBufferManager_deleteBuffers(param_3);
  }
  else {
    __android_log_print(6,0,"%s: initializeSurface() failed.","BypassCameraPhoto_prepareSnapshot");
  }
  BypassCameraBurstBufferManager_finalizeSurface(param_3);
  return iVar1;
}



undefined8
BypassCameraPhoto_prepareBurstShot(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  undefined **local_1a0;
  undefined *puStack_198;
  undefined4 local_190;
  undefined2 local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined2 local_168;
  undefined1 local_67;
  undefined8 local_60;
  undefined1 local_58;
  undefined4 local_54;
  undefined1 local_50;
  undefined8 local_4c;
  undefined8 local_44;
  undefined1 local_3c;
  long local_38;
  
  lVar1 = tpidr_el0;
  local_38 = *(long *)(lVar1 + 0x28);
  cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1a0);
  local_188 = 0;
  local_67 = 0;
  local_1a0 = &PTR__ProcessResultBase_0002f328;
  puStack_198 = &DAT_0002f380;
  local_60 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_168 = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_170 = 0;
  local_44 = 0;
  local_4c = 0;
  local_3c = 0;
  local_190 = 6;
  (**(code **)(*(long *)*param_3 + 0x40))((long *)*param_3,&local_1a0,0,param_3[0xb],param_3[0xc]);
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_1a0);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return 0;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



undefined8
BypassCameraPhoto_finishBurstShot(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  undefined **local_1a0;
  undefined *puStack_198;
  undefined4 local_190;
  undefined2 local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined2 local_168;
  undefined1 local_67;
  undefined8 local_60;
  undefined1 local_58;
  undefined4 local_54;
  undefined1 local_50;
  undefined8 local_4c;
  undefined8 local_44;
  undefined1 local_3c;
  long local_38;
  
  lVar1 = tpidr_el0;
  local_38 = *(long *)(lVar1 + 0x28);
  cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1a0);
  local_188 = 0;
  local_67 = 0;
  local_1a0 = &PTR__ProcessResultBase_0002f328;
  puStack_198 = &DAT_0002f380;
  local_60 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_168 = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_170 = 0;
  local_44 = 0;
  local_4c = 0;
  local_3c = 0;
  local_190 = 7;
  (**(code **)(*(long *)*param_3 + 0x40))((long *)*param_3,&local_1a0,0,param_3[0xd],param_3[0xe]);
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_1a0);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return 0;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// imageprocessor::SnapshotReadyCallback::SnapshotReadyCallback()

void __thiscall
imageprocessor::SnapshotReadyCallback::SnapshotReadyCallback(SnapshotReadyCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002efd0;
  return;
}



// android::SortedVector<android::key_value_pair_t<int, cacao::ProcessCtrlResult*>
// >::do_destroy(void*, unsigned long) const

void android::SortedVector<>::do_destroy(void)

{
  return;
}



// imageprocessor::VideoStartRecCallback::~VideoStartRecCallback()

void __thiscall
imageprocessor::VideoStartRecCallback::~VideoStartRecCallback(VideoStartRecCallback *this)

{
  operator_delete(this);
  return;
}



// imageprocessor::SnapshotReadyCallback::onHandleResult(cacao::ProcessResultBase const*)

int __thiscall
imageprocessor::SnapshotReadyCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  lVar3 = (**(code **)(*param_2 + 0x40))(param_2);
  pthread_mutex_lock((pthread_mutex_t *)(lVar3 + 0x90));
  if (*(char *)(lVar3 + 0xb8) == '\0') goto LAB_0000ba68;
  iVar1 = (**(code **)(*param_2 + 0x20))(param_2);
  if (iVar1 == 0) {
    if ((int)param_2[5] == 0) {
      __android_log_print(6,0,"%s: SnapshotReady AF failed.","onHandleResult");
      uVar6 = 0;
      uVar7 = 0;
      if ((char)param_2[7] == '\0') goto LAB_0000ba08;
LAB_0000b9d8:
      uVar6 = uVar7;
      uVar7 = 1;
    }
    else {
      uVar6 = 1;
      uVar7 = uVar6;
      if ((char)param_2[7] != '\0') goto LAB_0000b9d8;
LAB_0000ba08:
      __android_log_print(6,0,"%s: SnapshotReady Burst is not available.","onHandleResult");
      uVar7 = 0;
    }
    uVar8 = (uint)*(byte *)((long)param_2 + 0x3a);
    uVar9 = (uint)*(byte *)((long)param_2 + 0x3b);
    uVar10 = (uint)*(byte *)((long)param_2 + 0x3c);
    uVar5 = (uint)*(byte *)((long)param_2 + 0x39);
  }
  else {
    uVar2 = (**(code **)(*param_2 + 0x20))(param_2);
    __android_log_print(6,0,"%s: SnapshotReady failed. ERR=%d","onHandleResult",uVar2);
    uVar5 = 0;
    uVar7 = 0;
    uVar6 = 0;
    uVar8 = 0xff;
    uVar9 = 0xff;
    uVar10 = 0xff;
  }
  plVar4 = (long *)getJNIEnv();
  _JNIEnv::CallVoidMethod
            (plVar4,*(undefined8 *)(lVar3 + 0x10),*(undefined8 *)(lVar3 + 0x18),10,0,1,(ulong)uVar6,
             (ulong)uVar7,uVar5,uVar8,uVar9,uVar10);
LAB_0000ba68:
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(lVar3 + 0x90));
  return iVar1;
}



// imageprocessor::SnapshotCallback::SnapshotCallback()

void __thiscall imageprocessor::SnapshotCallback::SnapshotCallback(SnapshotCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f000;
  return;
}



// imageprocessor::SnapshotCallback::onHandleProgress(cacao::ProcessResultBase const*)

int __thiscall
imageprocessor::SnapshotCallback::onHandleProgress(undefined8 param_1_00,long *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  long *plVar4;
  uint uVar5;
  long lVar6;
  
  plVar4 = (long *)(**(code **)(*param_2 + 0x40))(param_2);
  lVar6 = *plVar4;
  pthread_mutex_lock((pthread_mutex_t *)(lVar6 + 0x90));
  if (*(char *)(lVar6 + 0xb8) == '\0') goto LAB_0000bb70;
  iVar2 = (**(code **)(*param_2 + 0x20))(param_2);
  if (iVar2 == 0) {
    if ((int)param_2[5] == 0) {
      __android_log_print(6,0,"%s: SnapshotReady AF failed.","onHandleProgress");
      goto LAB_0000bb24;
    }
    uVar5 = 1;
  }
  else {
    uVar3 = (**(code **)(*param_2 + 0x20))(param_2);
    __android_log_print(6,0,"%s: Snapshot failed. ERR=%d","onHandleProgress",uVar3);
LAB_0000bb24:
    uVar5 = 0;
  }
  uVar1 = *(uint *)(plVar4 + 2);
  plVar4 = (long *)getJNIEnv();
  _JNIEnv::CallVoidMethod
            (plVar4,*(undefined8 *)(lVar6 + 0x10),*(undefined8 *)(lVar6 + 0x18),0x14,(ulong)uVar1,1,
             (ulong)uVar5,0,0,0xff,0xff,0xff);
LAB_0000bb70:
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(lVar6 + 0x90));
  return iVar2;
}



// imageprocessor::SnapshotCallback::onHandleResult(cacao::ProcessResultBase const*)

void __thiscall
imageprocessor::SnapshotCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  undefined4 *puVar6;
  long lVar7;
  undefined8 *puVar8;
  long lVar9;
  void *pvVar10;
  
  lVar2 = tpidr_el0;
  lVar7 = *(long *)(lVar2 + 0x28);
  plVar4 = (long *)(**(code **)(*param_2 + 0x40))(param_2);
  lVar9 = *plVar4;
  pthread_mutex_lock((pthread_mutex_t *)(lVar9 + 0x90));
  if (*(char *)(lVar9 + 0xb8) != '\0') {
    pvVar10 = *(void **)(lVar9 + 0x88);
    uVar1 = *(uint *)(plVar4 + 2);
    lVar5 = android::SortedVectorImpl::indexOf(pvVar10);
    if (lVar5 < 0) {
      puVar8 = (undefined8 *)((long)pvVar10 + 0x28);
    }
    else {
      puVar8 = (undefined8 *)(*(long *)((long)pvVar10 + 8) + lVar5 * 0x10 + 8);
    }
    puVar6 = (undefined4 *)*puVar8;
    puVar6[6] = 3;
    BypassCameraBurstBufferManager_queueBuffer(lVar9,puVar6);
    android::SortedVectorImpl::remove(*(void **)(lVar9 + 0x88));
    pvVar10 = *(void **)(lVar9 + 0x40);
    lVar5 = android::SortedVectorImpl::indexOf(pvVar10);
    if (lVar5 < 0) {
      puVar8 = (undefined8 *)((long)pvVar10 + 0x28);
    }
    else {
      puVar8 = (undefined8 *)(*(long *)((long)pvVar10 + 8) + lVar5 * 0x10 + 8);
    }
    plVar4 = (long *)*puVar8;
    pvVar10 = (void *)(**(code **)(*plVar4 + 0x40))(plVar4);
    if (*(long **)((long)pvVar10 + 8) != (long *)0x0) {
      (**(code **)(**(long **)((long)pvVar10 + 8) + 8))();
    }
    if (pvVar10 != (void *)0x0) {
      operator_delete(pvVar10);
    }
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 8))(plVar4);
    }
    android::SortedVectorImpl::remove(*(void **)(lVar9 + 0x40));
    plVar4 = (long *)getJNIEnv();
    _JNIEnv::CallVoidMethod
              (plVar4,*(undefined8 *)(lVar9 + 0x10),*(undefined8 *)(lVar9 + 0x18),0x15,(ulong)uVar1,
               1,0,0,0,0xff,0xff,0xff);
  }
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)(lVar9 + 0x90));
  if (*(long *)(lVar2 + 0x28) == lVar7) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(iVar3);
}



// imageprocessor::SnapshotFreeCallback::SnapshotFreeCallback()

void __thiscall
imageprocessor::SnapshotFreeCallback::SnapshotFreeCallback(SnapshotFreeCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f030;
  return;
}



// imageprocessor::SnapshotFreeCallback::onHandleResult(cacao::ProcessResultBase const*)

int __thiscall
imageprocessor::SnapshotFreeCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  
  lVar2 = (**(code **)(*param_2 + 0x40))(param_2);
  pthread_mutex_lock((pthread_mutex_t *)(lVar2 + 0x90));
  if (*(char *)(lVar2 + 0xb8) != '\0') {
    plVar3 = (long *)getJNIEnv();
    _JNIEnv::CallVoidMethod
              (plVar3,*(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18),0x1e,0,0,0,0,0,
               0xff,0xff,0xff);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(lVar2 + 0x90));
  return iVar1;
}



// imageprocessor::BurstShotPrepareCallback::BurstShotPrepareCallback()

void __thiscall
imageprocessor::BurstShotPrepareCallback::BurstShotPrepareCallback(BurstShotPrepareCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f060;
  return;
}



// imageprocessor::BurstShotPrepareCallback::onHandleResult(cacao::ProcessResultBase const*)

int __thiscall
imageprocessor::BurstShotPrepareCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  
  lVar3 = (**(code **)(*param_2 + 0x40))(param_2);
  pthread_mutex_lock((pthread_mutex_t *)(lVar3 + 0x90));
  if (*(char *)(lVar3 + 0xb8) != '\0') {
    iVar1 = (**(code **)(*param_2 + 0x20))(param_2);
    if (iVar1 != 0) {
      uVar2 = (**(code **)(*param_2 + 0x20))(param_2);
      __android_log_print(6,0,"%s: PrepareBurstShot failed. ERR=%d","onHandleResult",uVar2);
    }
    plVar4 = (long *)getJNIEnv();
    _JNIEnv::CallVoidMethod
              (plVar4,*(undefined8 *)(lVar3 + 0x10),*(undefined8 *)(lVar3 + 0x18),0x28,0,1,0,
               (ulong)(iVar1 == 0),0,0xff,0xff,0xff);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(lVar3 + 0x90));
  return iVar1;
}



// imageprocessor::BurstShotFinishCallback::BurstShotFinishCallback()

void __thiscall
imageprocessor::BurstShotFinishCallback::BurstShotFinishCallback(BurstShotFinishCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f090;
  return;
}



// imageprocessor::BurstShotFinishCallback::onHandleResult(cacao::ProcessResultBase const*)

int __thiscall
imageprocessor::BurstShotFinishCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  
  lVar2 = (**(code **)(*param_2 + 0x40))(param_2);
  pthread_mutex_lock((pthread_mutex_t *)(lVar2 + 0x90));
  if (*(char *)(lVar2 + 0xb8) != '\0') {
    plVar3 = (long *)getJNIEnv();
    _JNIEnv::CallVoidMethod
              (plVar3,*(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18),0x32,0,0,0,0,0,
               0xff,0xff,0xff);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(lVar2 + 0x90));
  return iVar1;
}



// cacao::ProcessCtrlResult::getClassName() const

char * cacao::ProcessCtrlResult::getClassName(void)

{
  return "ProcessCtrlResult";
}



// cacao::ProcessResultBase::getResult() const

undefined4 __thiscall cacao::ProcessResultBase::getResult(ProcessResultBase *this)

{
  return *(undefined4 *)(this + 0x10);
}



// cacao::ProcessResultBase::setResult(Cacao_Err_t)

void __thiscall cacao::ProcessResultBase::setResult(ProcessResultBase *this,undefined4 param_1)

{
  *(undefined4 *)(this + 0x10) = param_1;
  return;
}



// cacao::ProcessResultBase::getProgress() const

undefined4 __thiscall cacao::ProcessResultBase::getProgress(ProcessResultBase *this)

{
  return *(undefined4 *)(this + 0x14);
}



// cacao::ProcessResultBase::setProgress(int)

void __thiscall cacao::ProcessResultBase::setProgress(ProcessResultBase *this,undefined4 param_1)

{
  *(undefined4 *)(this + 0x14) = param_1;
  return;
}



// cacao::ProcessResultBase::getUserData() const

undefined8 __thiscall cacao::ProcessResultBase::getUserData(ProcessResultBase *this)

{
  return *(undefined8 *)(this + 0x18);
}



// non-virtual thunk to cacao::ProcessCtrlResult::getSerializedSize() const

undefined8 __thiscall cacao::ProcessCtrlResult::getSerializedSize(void)

{
  return 0x28;
}



// cacao::ProcessCtrlResult::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall cacao::ProcessCtrlResult::serialize(ProcessCtrlResult *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) == 0) {
    return 0xffffff99;
  }
  if (*(uint *)(param_1 + 0x184) < *(uint *)(param_1 + 400) + 8) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
  *puVar2 = *(undefined4 *)(this + 0x10);
  puVar2[1] = *(undefined4 *)(this + 0x14);
  uVar1 = *(int *)(param_1 + 400) + 8;
  *(uint *)(param_1 + 400) = uVar1;
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)uVar1 + 0x20) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
  *puVar2 = *(undefined4 *)(this + 0x20);
  puVar2[1] = *(undefined4 *)(this + 0x24);
  puVar2[2] = *(undefined4 *)(this + 0x28);
  puVar2[3] = *(undefined4 *)(this + 0x2c);
  puVar2[4] = *(undefined4 *)(this + 0x30);
  puVar2[5] = *(undefined4 *)(this + 0x34);
  *(ProcessCtrlResult *)(puVar2 + 6) = this[0x38];
  *(ProcessCtrlResult *)((long)puVar2 + 0x19) = this[0x39];
  *(ProcessCtrlResult *)((long)puVar2 + 0x1a) = this[0x3a];
  *(ProcessCtrlResult *)((long)puVar2 + 0x1b) = this[0x3b];
  *(ProcessCtrlResult *)(puVar2 + 7) = this[0x3c];
  *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x20;
  return 0;
}



// cacao::ProcessCtrlResult::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall cacao::ProcessCtrlResult::deserialize(ProcessCtrlResult *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) == 0) {
    return 0xffffff99;
  }
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 8) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
  *(undefined4 *)(this + 0x10) = *puVar2;
  *(undefined4 *)(this + 0x14) = puVar2[1];
  uVar1 = *(int *)(param_1 + 400) + 8;
  *(uint *)(param_1 + 400) = uVar1;
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)uVar1 + 0x20) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
  *(undefined4 *)(this + 0x20) = *puVar2;
  *(undefined4 *)(this + 0x24) = puVar2[1];
  *(undefined4 *)(this + 0x28) = puVar2[2];
  *(undefined4 *)(this + 0x2c) = puVar2[3];
  *(undefined4 *)(this + 0x30) = puVar2[4];
  *(undefined4 *)(this + 0x34) = puVar2[5];
  this[0x38] = *(ProcessCtrlResult *)(puVar2 + 6);
  this[0x39] = *(ProcessCtrlResult *)((long)puVar2 + 0x19);
  this[0x3a] = *(ProcessCtrlResult *)((long)puVar2 + 0x1a);
  this[0x3b] = *(ProcessCtrlResult *)((long)puVar2 + 0x1b);
  this[0x3c] = *(ProcessCtrlResult *)(puVar2 + 7);
  *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x20;
  return 0;
}



// non-virtual thunk to cacao::ProcessCtrlResult::serialize(cacao::ISerialize::SerializedData*)
// const

undefined8 __thiscall cacao::ProcessCtrlResult::serialize(ProcessCtrlResult *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) == 0) {
    return 0xffffff99;
  }
  if (*(uint *)(param_1 + 0x184) < *(uint *)(param_1 + 400) + 8) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
  *puVar2 = *(undefined4 *)(this + 8);
  puVar2[1] = *(undefined4 *)(this + 0xc);
  uVar1 = *(int *)(param_1 + 400) + 8;
  *(uint *)(param_1 + 400) = uVar1;
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)uVar1 + 0x20) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
  *puVar2 = *(undefined4 *)(this + 0x18);
  puVar2[1] = *(undefined4 *)(this + 0x1c);
  puVar2[2] = *(undefined4 *)(this + 0x20);
  puVar2[3] = *(undefined4 *)(this + 0x24);
  puVar2[4] = *(undefined4 *)(this + 0x28);
  puVar2[5] = *(undefined4 *)(this + 0x2c);
  *(ProcessCtrlResult *)(puVar2 + 6) = this[0x30];
  *(ProcessCtrlResult *)((long)puVar2 + 0x19) = this[0x31];
  *(ProcessCtrlResult *)((long)puVar2 + 0x1a) = this[0x32];
  *(ProcessCtrlResult *)((long)puVar2 + 0x1b) = this[0x33];
  *(ProcessCtrlResult *)(puVar2 + 7) = this[0x34];
  *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x20;
  return 0;
}



// non-virtual thunk to cacao::ProcessCtrlResult::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall cacao::ProcessCtrlResult::deserialize(ProcessCtrlResult *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) == 0) {
    return 0xffffff99;
  }
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 8) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
  *(undefined4 *)(this + 8) = *puVar2;
  *(undefined4 *)(this + 0xc) = puVar2[1];
  uVar1 = *(int *)(param_1 + 400) + 8;
  *(uint *)(param_1 + 400) = uVar1;
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)uVar1 + 0x20) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
  *(undefined4 *)(this + 0x18) = *puVar2;
  *(undefined4 *)(this + 0x1c) = puVar2[1];
  *(undefined4 *)(this + 0x20) = puVar2[2];
  *(undefined4 *)(this + 0x24) = puVar2[3];
  *(undefined4 *)(this + 0x28) = puVar2[4];
  *(undefined4 *)(this + 0x2c) = puVar2[5];
  this[0x30] = *(ProcessCtrlResult *)(puVar2 + 6);
  this[0x31] = *(ProcessCtrlResult *)((long)puVar2 + 0x19);
  this[0x32] = *(ProcessCtrlResult *)((long)puVar2 + 0x1a);
  this[0x33] = *(ProcessCtrlResult *)((long)puVar2 + 0x1b);
  this[0x34] = *(ProcessCtrlResult *)(puVar2 + 7);
  *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x20;
  return 0;
}



// android::SortedVector<android::key_value_pair_t<int, cacao::ProcessCtrlResult*>
// >::~SortedVector()

void __thiscall android::SortedVector<>::~SortedVector(SortedVector<> *this)

{
  *(undefined ***)this = &PTR__SortedVector_0002f168;
  android::VectorImpl::finish_vector();
  android::SortedVectorImpl::~SortedVectorImpl((SortedVectorImpl *)this);
  return;
}



// android::SortedVector<android::key_value_pair_t<int, cacao::ProcessCtrlResult*>
// >::~SortedVector()

void __thiscall android::SortedVector<>::~SortedVector(SortedVector<> *this)

{
  *(undefined ***)this = &PTR__SortedVector_0002f168;
  android::VectorImpl::finish_vector();
  android::SortedVectorImpl::~SortedVectorImpl((SortedVectorImpl *)this);
  operator_delete(this);
  return;
}



// android::SortedVector<android::key_value_pair_t<int, cacao::ProcessCtrlResult*> >::do_copy(void*,
// void const*, unsigned long) const

void __thiscall
android::SortedVector<>::do_copy(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  memcpy(param_2,param_3,param_4 << 4);
  return;
}



// android::SortedVector<android::key_value_pair_t<int, imageprocessor::BurstSnapshotBuffer*>
// >::do_splat(void*, void const*, unsigned long) const

void __thiscall
android::SortedVector<>::do_splat
          (undefined8 param_1_00,undefined4 *param_2,undefined4 *param_3,ulong param_4)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  
  uVar2 = param_4 - 1;
  if ((long)param_4 < 1) {
    if (param_4 == 0) {
      return;
    }
  }
  else if (3 < (long)param_4) {
    uVar1 = *param_3;
    uVar4 = *(undefined8 *)(param_3 + 2);
    if ((param_3 + 4 <= param_2) || (param_2 + param_4 * 4 <= param_3)) {
      uVar7 = 0;
      uVar6 = uVar2 - (param_4 & 3);
      puVar3 = param_2 + 8;
      do {
        uVar8 = uVar7 | 3;
        puVar3[-8] = uVar1;
        puVar3[-4] = uVar1;
        *puVar3 = uVar1;
        puVar3[4] = uVar1;
        *(undefined8 *)(puVar3 + -6) = uVar4;
        *(undefined8 *)(puVar3 + -2) = uVar4;
        *(undefined8 *)(puVar3 + 2) = uVar4;
        *(undefined8 *)(puVar3 + 6) = uVar4;
        uVar7 = uVar7 + 4;
        puVar3 = puVar3 + 0x10;
      } while (uVar8 != uVar6);
      lVar5 = uVar6 + 1;
      if ((long)uVar2 < lVar5) {
        return;
      }
      if (1 < (param_4 & 3)) {
        param_2[lVar5 * 4] = uVar1;
        uVar7 = lVar5 * 0x10;
        lVar5 = uVar6 + 3;
        param_2[uVar6 * 4 + 8] = uVar1;
        *(undefined8 *)((long)param_2 + (uVar7 | 8)) = uVar4;
        *(undefined8 *)((long)param_2 + (uVar6 * 0x10 + 0x20 | 8)) = uVar4;
        if ((long)uVar2 < lVar5) {
          return;
        }
      }
      param_2[lVar5 * 4] = uVar1;
      *(undefined8 *)((long)param_2 + (lVar5 << 4 | 8U)) = uVar4;
      return;
    }
  }
  uVar7 = param_4 & 7;
  if (6 < uVar2) {
    lVar5 = param_4 - uVar7;
    puVar3 = param_2;
    do {
      lVar5 = lVar5 + -8;
      *puVar3 = *param_3;
      *(undefined8 *)(puVar3 + 2) = *(undefined8 *)(param_3 + 2);
      puVar3[4] = *param_3;
      *(undefined8 *)(puVar3 + 6) = *(undefined8 *)(param_3 + 2);
      puVar3[8] = *param_3;
      *(undefined8 *)(puVar3 + 10) = *(undefined8 *)(param_3 + 2);
      puVar3[0xc] = *param_3;
      *(undefined8 *)(puVar3 + 0xe) = *(undefined8 *)(param_3 + 2);
      puVar3[0x10] = *param_3;
      *(undefined8 *)(puVar3 + 0x12) = *(undefined8 *)(param_3 + 2);
      puVar3[0x14] = *param_3;
      *(undefined8 *)(puVar3 + 0x16) = *(undefined8 *)(param_3 + 2);
      puVar3[0x18] = *param_3;
      *(undefined8 *)(puVar3 + 0x1a) = *(undefined8 *)(param_3 + 2);
      puVar3[0x1c] = *param_3;
      param_2 = puVar3 + 0x20;
      *(undefined8 *)(puVar3 + 0x1e) = *(undefined8 *)(param_3 + 2);
      puVar3 = param_2;
    } while (lVar5 != 0);
  }
  for (; uVar7 != 0; uVar7 = uVar7 - 1) {
    *param_2 = *param_3;
    *(undefined8 *)(param_2 + 2) = *(undefined8 *)(param_3 + 2);
    param_2 = param_2 + 4;
  }
  return;
}



// android::SortedVector<android::key_value_pair_t<ANativeWindowBuffer*,
// imageprocessor::BurstSnapshotBuffer*> >::do_move_forward(void*, void const*, unsigned long) const

void __thiscall
android::SortedVector<>::do_move_forward
          (undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  memmove(param_2,param_3,param_4 << 4);
  return;
}



// android::SortedVector<android::key_value_pair_t<int, cacao::ProcessCtrlResult*>
// >::do_compare(void const*, void const*) const

int __thiscall android::SortedVector<>::do_compare(undefined8 param_1_00,int *param_2,int *param_3)

{
  return (uint)(*param_3 < *param_2) - (uint)(*param_2 < *param_3);
}



// android::SortedVector<android::key_value_pair_t<int, imageprocessor::BurstSnapshotBuffer*>
// >::~SortedVector()

void __thiscall android::SortedVector<>::~SortedVector(SortedVector<> *this)

{
  *(undefined ***)this = &PTR__SortedVector_0002f1c0;
  android::VectorImpl::finish_vector();
  android::SortedVectorImpl::~SortedVectorImpl((SortedVectorImpl *)this);
  return;
}



// android::SortedVector<android::key_value_pair_t<int, imageprocessor::BurstSnapshotBuffer*>
// >::~SortedVector()

void __thiscall android::SortedVector<>::~SortedVector(SortedVector<> *this)

{
  *(undefined ***)this = &PTR__SortedVector_0002f1c0;
  android::VectorImpl::finish_vector();
  android::SortedVectorImpl::~SortedVectorImpl((SortedVectorImpl *)this);
  operator_delete(this);
  return;
}



// cacao::ProcessCtrlMode::getClassName() const

char * cacao::ProcessCtrlMode::getClassName(void)

{
  return "ProcessCtrlMode";
}



// non-virtual thunk to cacao::ProcessCtrlMode::getSerializedSize() const

undefined8 __thiscall cacao::ProcessCtrlMode::getSerializedSize(void)

{
  return 0x24;
}



// cacao::ProcessCtrlMode::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall cacao::ProcessCtrlMode::serialize(ProcessCtrlMode *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) == 0) {
    return 0xffffff99;
  }
  if (*(uint *)(param_1 + 0x184) < *(uint *)(param_1 + 400) + 4) {
    return 0xffffff99;
  }
  *(undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400)) =
       *(undefined4 *)(this + 0x10);
  uVar1 = *(int *)(param_1 + 400) + 4;
  *(uint *)(param_1 + 400) = uVar1;
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)uVar1 + 0x20) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
  *puVar2 = *(undefined4 *)(this + 0x14);
  *(undefined8 *)(puVar2 + 1) = *(undefined8 *)(this + 0x18);
  *(undefined8 *)(puVar2 + 3) = *(undefined8 *)(this + 0x20);
  puVar2[5] = *(undefined4 *)(this + 0x28);
  puVar2[6] = *(undefined4 *)(this + 0x2c);
  puVar2[7] = *(undefined4 *)(this + 0x30);
  *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x20;
  return 0;
}



// cacao::ProcessCtrlMode::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall cacao::ProcessCtrlMode::deserialize(ProcessCtrlMode *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) == 0) {
    return 0xffffff99;
  }
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 4) {
    return 0xffffff99;
  }
  *(undefined4 *)(this + 0x10) =
       *(undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
  uVar1 = *(int *)(param_1 + 400) + 4;
  *(uint *)(param_1 + 400) = uVar1;
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)uVar1 + 0x20) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
  *(undefined4 *)(this + 0x14) = *puVar2;
  *(undefined8 *)(this + 0x18) = *(undefined8 *)(puVar2 + 1);
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(puVar2 + 3);
  *(undefined4 *)(this + 0x28) = puVar2[5];
  *(undefined4 *)(this + 0x2c) = puVar2[6];
  *(undefined4 *)(this + 0x30) = puVar2[7];
  *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x20;
  return 0;
}



// non-virtual thunk to cacao::ProcessCtrlMode::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall cacao::ProcessCtrlMode::serialize(ProcessCtrlMode *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) == 0) {
    return 0xffffff99;
  }
  if (*(uint *)(param_1 + 0x184) < *(uint *)(param_1 + 400) + 4) {
    return 0xffffff99;
  }
  *(undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400)) =
       *(undefined4 *)(this + 8);
  uVar1 = *(int *)(param_1 + 400) + 4;
  *(uint *)(param_1 + 400) = uVar1;
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)uVar1 + 0x20) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
  *puVar2 = *(undefined4 *)(this + 0xc);
  *(undefined8 *)(puVar2 + 1) = *(undefined8 *)(this + 0x10);
  *(undefined8 *)(puVar2 + 3) = *(undefined8 *)(this + 0x18);
  puVar2[5] = *(undefined4 *)(this + 0x20);
  puVar2[6] = *(undefined4 *)(this + 0x24);
  puVar2[7] = *(undefined4 *)(this + 0x28);
  *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x20;
  return 0;
}



// non-virtual thunk to cacao::ProcessCtrlMode::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall cacao::ProcessCtrlMode::deserialize(ProcessCtrlMode *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 0xffffff99;
  }
  if (*(long *)(param_1 + 0x188) == 0) {
    return 0xffffff99;
  }
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 4) {
    return 0xffffff99;
  }
  *(undefined4 *)(this + 8) =
       *(undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
  uVar1 = *(int *)(param_1 + 400) + 4;
  *(uint *)(param_1 + 400) = uVar1;
  if ((ulong)*(uint *)(param_1 + 0x184) < (ulong)uVar1 + 0x20) {
    return 0xffffff99;
  }
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
  *(undefined4 *)(this + 0xc) = *puVar2;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(puVar2 + 1);
  *(undefined8 *)(this + 0x18) = *(undefined8 *)(puVar2 + 3);
  *(undefined4 *)(this + 0x20) = puVar2[5];
  *(undefined4 *)(this + 0x24) = puVar2[6];
  *(undefined4 *)(this + 0x28) = puVar2[7];
  *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x20;
  return 0;
}



// cacao::ProcessCtrlSnapShotMode::getClassName() const

char * cacao::ProcessCtrlSnapShotMode::getClassName(void)

{
  return "ProcessCtrlSnapShotMode";
}



// cacao::ProcessCtrlParam::getClassName() const

char * cacao::ProcessCtrlParam::getClassName(void)

{
  return "ProcessCtrlParam";
}



// cacao::ProcessCtrlParam::clone() const

ObjectBase * cacao::ProcessCtrlParam::clone(long param_1,ulong param_2)

{
  ObjectBase *this;
  
  this = cacao::ObjectBase::operator_new((ObjectBase *)0x168,param_2);
  cacao::ObjectBase::ObjectBase(this);
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined **)(this + 8) = &DAT_0002f380;
  *(undefined ***)this = &PTR__ProcessResultBase_0002f328;
  *(undefined2 *)(this + 0x18) = 0;
  this[0x139] = (ObjectBase)0x0;
  *(undefined8 *)(this + 0x140) = 0;
  this[0x148] = (ObjectBase)0x0;
  *(undefined4 *)(this + 0x14c) = 0;
  this[0x150] = (ObjectBase)0x0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined2 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x15c) = 0;
  *(undefined8 *)(this + 0x154) = 0;
  this[0x164] = (ObjectBase)0x0;
  if ((this != (ObjectBase *)0x0) && (param_1 != 0)) {
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    memcpy(this + 0x18,(void *)(param_1 + 0x18),0x150);
  }
  return this;
}



// cacao::ProcessCtrlParam::copy(cacao::ProcessParamBase const*)

void __thiscall cacao::ProcessCtrlParam::copy(ProcessCtrlParam *this,long param_1)

{
  if (param_1 != 0) {
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    memcpy(this + 0x18,(void *)(param_1 + 0x18),0x150);
    return;
  }
  return;
}



// non-virtual thunk to cacao::ProcessCtrlParam::getSerializedSize() const

undefined8 __thiscall cacao::ProcessCtrlParam::getSerializedSize(void)

{
  return 0x158;
}



// cacao::ProcessCtrlParam::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall cacao::ProcessCtrlParam::serialize(ProcessCtrlParam *this,long param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x188) != 0)) {
    uVar2 = *(uint *)(param_1 + 400);
    if ((uVar2 <= *(uint *)(param_1 + 0x184)) &&
       ((ulong)uVar2 + 0x158 <= (ulong)*(uint *)(param_1 + 0x184))) {
      puVar1 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar2);
      *puVar1 = *(undefined4 *)(this + 0x10);
      memcpy(puVar1 + 2,this + 0x18,0x150);
      *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x158;
      return 0;
    }
  }
  return 0xffffff99;
}



// cacao::ProcessCtrlParam::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall cacao::ProcessCtrlParam::deserialize(ProcessCtrlParam *this,long param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x188) == 0)) ||
     ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 0x158)) {
    uVar2 = 0xffffff99;
  }
  else {
    puVar1 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    *(undefined4 *)(this + 0x10) = *puVar1;
    memcpy(this + 0x18,puVar1 + 2,0x150);
    uVar2 = 0;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x158;
  }
  return uVar2;
}



// non-virtual thunk to cacao::ProcessCtrlParam::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall cacao::ProcessCtrlParam::serialize(ProcessCtrlParam *this,long param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x188) != 0)) {
    uVar2 = *(uint *)(param_1 + 400);
    if ((uVar2 <= *(uint *)(param_1 + 0x184)) &&
       ((ulong)uVar2 + 0x158 <= (ulong)*(uint *)(param_1 + 0x184))) {
      puVar1 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar2);
      *puVar1 = *(undefined4 *)(this + 8);
      memcpy(puVar1 + 2,this + 0x10,0x150);
      *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x158;
      return 0;
    }
  }
  return 0xffffff99;
}



// non-virtual thunk to cacao::ProcessCtrlParam::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall cacao::ProcessCtrlParam::deserialize(ProcessCtrlParam *this,long param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x188) == 0)) ||
     ((ulong)*(uint *)(param_1 + 0x184) < (ulong)*(uint *)(param_1 + 400) + 0x158)) {
    uVar2 = 0xffffff99;
  }
  else {
    puVar1 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    *(undefined4 *)(this + 8) = *puVar1;
    memcpy(this + 0x10,puVar1 + 2,0x150);
    uVar2 = 0;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 0x158;
  }
  return uVar2;
}



// android::Vector<cacao::ImageBuf*>::~Vector()

void __thiscall android::Vector<>::~Vector(Vector<> *this)

{
  *(undefined ***)this = &PTR__Vector_0002f3b8;
  android::VectorImpl::finish_vector();
  android::VectorImpl::~VectorImpl((VectorImpl *)this);
  return;
}



// android::Vector<cacao::ImageBuf*>::~Vector()

void __thiscall android::Vector<>::~Vector(Vector<> *this)

{
  *(undefined ***)this = &PTR__Vector_0002f3b8;
  android::VectorImpl::finish_vector();
  android::VectorImpl::~VectorImpl((VectorImpl *)this);
  operator_delete(this);
  return;
}



// android::Vector<cacao::ImageBuf*>::do_copy(void*, void const*, unsigned long) const

void __thiscall
android::Vector<>::do_copy(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  memcpy(param_2,param_3,param_4 << 3);
  return;
}



// android::Vector<cacao::ImageBuf*>::do_splat(void*, void const*, unsigned long) const

void __thiscall
android::Vector<>::do_splat
          (undefined8 param_1_00,undefined8 *param_2,undefined8 *param_3,ulong param_4)

{
  ulong uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  
  uVar3 = (uint)param_4;
  uVar1 = param_4 - 1;
  if ((long)param_4 < 1) {
    if (param_4 == 0) {
      return;
    }
  }
  else if ((0xf < (long)param_4) &&
          ((uVar4 = *param_3, param_3 + 1 <= param_2 || (param_2 + param_4 <= param_3)))) {
    uVar8 = 0;
    uVar7 = uVar1 - (param_4 & 0xf);
    puVar2 = param_2 + 8;
    do {
      uVar9 = uVar8 | 0xf;
      puVar2[-7] = uVar4;
      puVar2[-8] = uVar4;
      puVar2[-5] = uVar4;
      puVar2[-6] = uVar4;
      puVar2[-3] = uVar4;
      puVar2[-4] = uVar4;
      puVar2[-1] = uVar4;
      puVar2[-2] = uVar4;
      puVar2[1] = uVar4;
      *puVar2 = uVar4;
      puVar2[3] = uVar4;
      puVar2[2] = uVar4;
      puVar2[5] = uVar4;
      puVar2[4] = uVar4;
      puVar2[7] = uVar4;
      puVar2[6] = uVar4;
      uVar8 = uVar8 + 0x10;
      puVar2 = puVar2 + 0x10;
    } while (uVar9 != uVar7);
    lVar5 = uVar7 + 1;
    if ((long)uVar1 < lVar5) {
      return;
    }
    if ((uVar3 >> 3 & 1) != 0) {
      puVar2 = param_2 + lVar5;
      lVar5 = uVar7 + 9;
      puVar2[1] = uVar4;
      *puVar2 = uVar4;
      puVar2[3] = uVar4;
      puVar2[2] = uVar4;
      puVar2[5] = uVar4;
      puVar2[4] = uVar4;
      puVar2[7] = uVar4;
      puVar2[6] = uVar4;
      if ((long)uVar1 < lVar5) {
        return;
      }
    }
    if ((uVar3 >> 2 & 1) != 0) {
      puVar2 = param_2 + lVar5;
      lVar5 = lVar5 + 4;
      puVar2[1] = uVar4;
      *puVar2 = uVar4;
      puVar2[3] = uVar4;
      puVar2[2] = uVar4;
      if ((long)uVar1 < lVar5) {
        return;
      }
    }
    lVar6 = lVar5;
    if ((uVar3 >> 1 & 1) != 0) {
      lVar6 = lVar5 + 2;
      (param_2 + lVar5)[1] = uVar4;
      param_2[lVar5] = uVar4;
      if ((long)uVar1 < lVar6) {
        return;
      }
    }
    param_2[lVar6] = uVar4;
    return;
  }
  uVar8 = param_4 & 7;
  if (6 < uVar1) {
    lVar5 = param_4 - uVar8;
    puVar2 = param_2;
    do {
      lVar5 = lVar5 + -8;
      *puVar2 = *param_3;
      puVar2[1] = *param_3;
      puVar2[2] = *param_3;
      puVar2[3] = *param_3;
      puVar2[4] = *param_3;
      puVar2[5] = *param_3;
      puVar2[6] = *param_3;
      param_2 = puVar2 + 8;
      puVar2[7] = *param_3;
      puVar2 = param_2;
    } while (lVar5 != 0);
  }
  for (; uVar8 != 0; uVar8 = uVar8 - 1) {
    *param_2 = *param_3;
    param_2 = param_2 + 1;
  }
  return;
}



// android::Vector<cacao::ImageBuf*>::do_move_backward(void*, void const*, unsigned long) const

void __thiscall
android::Vector<>::do_move_backward(undefined8 param_1_00,void *param_2,void *param_3,long param_4)

{
  memmove(param_2,param_3,param_4 << 3);
  return;
}



void BypassCameraVideo_initialize(long *param_1,undefined8 param_2,void *param_3)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  ObjectBase *pOVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  VectorImpl *this;
  undefined4 *puVar7;
  ulong extraout_x1;
  ulong extraout_x1_00;
  ulong extraout_x1_01;
  ulong extraout_x1_02;
  ulong extraout_x1_03;
  char *pcVar8;
  undefined4 uVar9;
  pthread_attr_t pStack_90;
  long local_58;
  
  lVar1 = tpidr_el0;
  local_58 = *(long *)(lVar1 + 0x28);
  *(undefined **)((long)param_3 + 0x128) = &DAT_000301f8;
  *(undefined **)((long)param_3 + 0x130) = &DAT_00030228;
  puVar3 = operator_new(8);
  *puVar3 = &PTR_do_destroy_0002f408;
  *(undefined8 **)((long)param_3 + 0xd0) = puVar3;
  pOVar4 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1);
  cacao::ObjectBase::ObjectBase(pOVar4);
  *(void **)(pOVar4 + 0x18) = param_3;
  *(undefined8 *)(pOVar4 + 0x30) = 0;
  *(undefined8 *)(pOVar4 + 0x10) = 0xffffffff00000000;
  *(undefined4 *)(pOVar4 + 0x38) = 0xffff0000;
  pOVar4[0x3c] = (ObjectBase)0xff;
  *(undefined **)(pOVar4 + 8) = &DAT_0002f130;
  *(undefined ***)pOVar4 = &PTR__ProcessResultBase_0002f0c0;
  *(undefined8 *)(pOVar4 + 0x28) = 0xffffffff00000000;
  *(undefined8 *)(pOVar4 + 0x20) = 0;
  *(ObjectBase **)((long)param_3 + 0xd8) = pOVar4;
  puVar3 = operator_new(8);
  *puVar3 = &PTR_do_destroy_0002f438;
  *(undefined8 **)((long)param_3 + 0xe0) = puVar3;
  pOVar4 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1_00);
  cacao::ObjectBase::ObjectBase(pOVar4);
  *(undefined8 *)(pOVar4 + 0x10) = 0xffffffff00000000;
  *(void **)(pOVar4 + 0x18) = param_3;
  *(undefined **)(pOVar4 + 8) = &DAT_0002f130;
  *(undefined ***)pOVar4 = &PTR__ProcessResultBase_0002f0c0;
  *(undefined8 *)(pOVar4 + 0x30) = 0;
  *(undefined4 *)(pOVar4 + 0x38) = 0xffff0000;
  pOVar4[0x3c] = (ObjectBase)0xff;
  *(undefined8 *)(pOVar4 + 0x28) = 0xffffffff00000000;
  *(undefined8 *)(pOVar4 + 0x20) = 0;
  *(ObjectBase **)((long)param_3 + 0xe8) = pOVar4;
  puVar3 = operator_new(8);
  *puVar3 = &PTR_do_destroy_0002f468;
  *(undefined8 **)((long)param_3 + 0xf0) = puVar3;
  pOVar4 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1_01);
  cacao::ObjectBase::ObjectBase(pOVar4);
  *(undefined8 *)(pOVar4 + 0x10) = 0xffffffff00000000;
  *(void **)(pOVar4 + 0x18) = param_3;
  *(undefined **)(pOVar4 + 8) = &DAT_0002f130;
  *(undefined ***)pOVar4 = &PTR__ProcessResultBase_0002f0c0;
  *(undefined8 *)(pOVar4 + 0x30) = 0;
  *(undefined4 *)(pOVar4 + 0x38) = 0xffff0000;
  pOVar4[0x3c] = (ObjectBase)0xff;
  *(undefined8 *)(pOVar4 + 0x28) = 0xffffffff00000000;
  *(undefined8 *)(pOVar4 + 0x20) = 0;
  *(ObjectBase **)((long)param_3 + 0xf8) = pOVar4;
  puVar3 = operator_new(8);
  *puVar3 = &PTR_do_destroy_0002f498;
  *(undefined8 **)((long)param_3 + 0x100) = puVar3;
  pOVar4 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1_02);
  cacao::ObjectBase::ObjectBase(pOVar4);
  *(undefined8 *)(pOVar4 + 0x10) = 0xffffffff00000000;
  *(void **)(pOVar4 + 0x18) = param_3;
  *(undefined **)(pOVar4 + 8) = &DAT_0002f130;
  *(undefined ***)pOVar4 = &PTR__ProcessResultBase_0002f0c0;
  *(undefined8 *)(pOVar4 + 0x30) = 0;
  *(undefined4 *)(pOVar4 + 0x38) = 0xffff0000;
  pOVar4[0x3c] = (ObjectBase)0xff;
  *(undefined8 *)(pOVar4 + 0x28) = 0xffffffff00000000;
  *(undefined8 *)(pOVar4 + 0x20) = 0;
  *(ObjectBase **)((long)param_3 + 0x108) = pOVar4;
  puVar3 = operator_new(8);
  *puVar3 = &PTR_do_destroy_0002f4c8;
  *(undefined8 **)((long)param_3 + 0x110) = puVar3;
  pOVar4 = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1_03);
  cacao::ObjectBase::ObjectBase(pOVar4);
  *(undefined8 *)(pOVar4 + 0x10) = 0xffffffff00000000;
  *(void **)(pOVar4 + 0x18) = param_3;
  *(undefined8 *)(pOVar4 + 0x30) = 0;
  *(undefined **)(pOVar4 + 8) = &DAT_0002f130;
  *(undefined ***)pOVar4 = &PTR__ProcessResultBase_0002f0c0;
  *(undefined4 *)(pOVar4 + 0x38) = 0xffff0000;
  pOVar4[0x3c] = (ObjectBase)0xff;
  *(undefined8 *)(pOVar4 + 0x28) = 0xffffffff00000000;
  *(undefined8 *)(pOVar4 + 0x20) = 0;
  *(ObjectBase **)((long)param_3 + 0x118) = pOVar4;
  uVar5 = (**(code **)(*param_1 + 0x30))
                    (param_1,"com/sonymobile/imageprocessor/bypasscamera2/BypassCamera");
  uVar6 = (**(code **)(*param_1 + 0x108))(param_1,uVar5,"callbackFromNativeVideo",&DAT_00011739);
  (**(code **)(*param_1 + 0xb8))(param_1,uVar5);
  uVar5 = (**(code **)(*param_1 + 0xa8))(param_1,param_2);
  *(undefined8 *)((long)param_3 + 0xc0) = uVar5;
  *(undefined8 *)((long)param_3 + 200) = uVar6;
  this = operator_new(0x28);
  android::VectorImpl::VectorImpl(this,4,0);
  *(undefined ***)this = &PTR__Vector_0002f580;
  *(VectorImpl **)((long)param_3 + 0x120) = this;
  if (*(char *)((long)param_3 + 0x140) == '\0') {
    puVar7 = (undefined4 *)__errno();
    *puVar7 = 0;
    iVar2 = pthread_attr_init(&pStack_90);
    if (iVar2 == 0) {
      *puVar7 = 0;
      iVar2 = pthread_attr_setdetachstate(&pStack_90,0);
      if (iVar2 == 0) {
        *(undefined1 *)((long)param_3 + 0x140) = 0;
        *puVar7 = 0;
        iVar2 = pthread_create((pthread_t *)((long)param_3 + 0x138),&pStack_90,
                               imageprocessor::BypassCameraVideo_thread,param_3);
        if (iVar2 == 0) {
          *(undefined1 *)((long)param_3 + 0x140) = 1;
          uVar9 = 0;
          goto LAB_0000d1bc;
        }
        uVar9 = *puVar7;
        pcVar8 = "%s: pthread_create() failed. ERR=%d";
      }
      else {
        uVar9 = *puVar7;
        pcVar8 = "%s: pthread_attr_setdetachstate() failed. ERR=%d";
      }
    }
    else {
      uVar9 = *puVar7;
      pcVar8 = "%s: pthread_attr_init() failed. ERR=%d";
    }
    __android_log_print(6,0,pcVar8,"BypassCameraVideo_createThread",uVar9);
  }
  else {
    __android_log_print(6,0,"%s: thread is already started.","BypassCameraVideo_createThread");
  }
  __android_log_print(6,0,"%s: createThread() failed.","BypassCameraVideo_initialize");
  uVar9 = 0xffffffff;
LAB_0000d1bc:
  if (*(long *)(lVar1 + 0x28) == local_58) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar9);
}



void BypassCameraVideo_finalize(long *param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  char *pcVar7;
  long lVar8;
  
  lVar1 = tpidr_el0;
  lVar8 = *(long *)(lVar1 + 0x28);
  if (*(char *)(param_3 + 0x140) == '\0') {
    pcVar6 = "%s: thread is already stopped.";
    pcVar7 = "BypassCameraVideo_deleteThread";
    uVar4 = 3;
  }
  else {
    pthread_mutex_lock(*(pthread_mutex_t **)(param_3 + 0x130));
    android::VectorImpl::push(*(void **)(param_3 + 0x120));
    pthread_cond_signal(*(pthread_cond_t **)(param_3 + 0x128));
    iVar2 = pthread_mutex_unlock(*(pthread_mutex_t **)(param_3 + 0x130));
    puVar3 = (undefined4 *)__errno(iVar2);
    *puVar3 = 0;
    iVar2 = pthread_join(*(pthread_t *)(param_3 + 0x138),(void **)0x0);
    if (iVar2 == 0) {
      *(undefined1 *)(param_3 + 0x140) = 0;
      lVar5 = *(long *)(param_3 + 0x120);
      goto joined_r0x0000d2d0;
    }
    __android_log_print(6,0,"%s: pthread_join() failed. ERR=%d","BypassCameraVideo_deleteThread",
                        *puVar3);
    pcVar6 = "%s: deleteThread() failed.";
    pcVar7 = "BypassCameraVideo_finalize";
    uVar4 = 6;
    *(undefined1 *)(param_3 + 0x140) = 0;
  }
  __android_log_print(uVar4,0,pcVar6,pcVar7);
  lVar5 = *(long *)(param_3 + 0x120);
joined_r0x0000d2d0:
  if (lVar5 != 0) {
    if (*(long *)(lVar5 + 0x10) != 0) {
      __android_log_print(3,0,"%s: remain[%d]","BypassCameraVideo_deleteRequestBuffer");
    }
    android::VectorImpl::clear();
    if (*(long **)(param_3 + 0x120) != (long *)0x0) {
      (**(code **)(**(long **)(param_3 + 0x120) + 8))();
    }
    *(undefined8 *)(param_3 + 0x120) = 0;
  }
  if (*(long *)(param_3 + 0xc0) != 0) {
    (**(code **)(*param_1 + 0xb0))(param_1);
    *(undefined8 *)(param_3 + 0xc0) = 0;
  }
  if (*(long **)(param_3 + 0xd0) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0xd0) + 8))();
  }
  *(undefined8 *)(param_3 + 0xd0) = 0;
  if (*(long **)(param_3 + 0xd8) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0xd8) + 8))();
  }
  *(undefined8 *)(param_3 + 0xd8) = 0;
  if (*(long **)(param_3 + 0xe0) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0xe0) + 8))();
  }
  *(undefined8 *)(param_3 + 0xe0) = 0;
  if (*(long **)(param_3 + 0xe8) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0xe8) + 8))();
  }
  *(undefined8 *)(param_3 + 0xe8) = 0;
  if (*(long **)(param_3 + 0xf0) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0xf0) + 8))();
  }
  *(undefined8 *)(param_3 + 0xf0) = 0;
  if (*(long **)(param_3 + 0xf8) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0xf8) + 8))();
  }
  *(undefined8 *)(param_3 + 0xf8) = 0;
  if (*(long **)(param_3 + 0x100) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0x100) + 8))();
  }
  *(undefined8 *)(param_3 + 0x100) = 0;
  if (*(long **)(param_3 + 0x108) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0x108) + 8))();
  }
  *(undefined8 *)(param_3 + 0x108) = 0;
  if (*(long **)(param_3 + 0x110) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0x110) + 8))();
  }
  *(undefined8 *)(param_3 + 0x110) = 0;
  if (*(long **)(param_3 + 0x118) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0x118) + 8))();
  }
  *(undefined8 *)(param_3 + 0x118) = 0;
  if (*(long *)(lVar1 + 0x28) == lVar8) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



undefined4
BypassCameraVideo_changeToVideoMode
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,ulong param_4,long param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined **local_90;
  undefined *puStack_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  ulong local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  long local_58;
  
  lVar2 = tpidr_el0;
  local_58 = *(long *)(lVar2 + 0x28);
  uVar4 = *(undefined4 *)(param_3 + 1);
  uVar1 = *(undefined4 *)((long)param_3 + 0xc);
  *(undefined4 *)((long)param_3 + 0x144) = param_6;
  *(undefined4 *)(param_3 + 0x29) = param_7;
  *(undefined4 *)(param_3 + 0x2e) = 1;
  cacao::ObjectBase::ObjectBase((ObjectBase *)&local_90);
  local_90 = &PTR__ProcessResultBase_0002f218;
  puStack_88 = &DAT_0002f268;
  local_68 = 1;
  local_80 = uVar1;
  uStack_7c = uVar4;
  local_78 = param_4 & 0xffffffff | param_5 << 0x20;
  uStack_70 = CONCAT44(param_7,param_6);
  local_60 = param_8;
  iVar3 = (**(code **)(*(long *)*param_3 + 0x20))();
  if ((iVar3 == 0) ||
     (__android_log_print(6,0,"%s: cacao stop() ret=%d","BypassCameraVideo_changeToVideoMode",iVar3)
     , iVar3 != -0x6e)) {
    iVar3 = (**(code **)(*(long *)*param_3 + 0x18))((long *)*param_3,&local_90);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      __android_log_print(6,0,"%s: cacao start() failed. ERR=%d",
                          "BypassCameraVideo_changeToVideoMode",iVar3);
      uVar4 = 0xffffffff;
    }
  }
  else {
    uVar4 = 0xfffffffe;
  }
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_90);
  if (*(long *)(lVar2 + 0x28) == local_58) {
    return uVar4;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



undefined4
BypassCameraVideo_changeToSuperSlowMode
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined **local_e0;
  undefined *puStack_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 local_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined **local_a0;
  undefined *puStack_98;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  long local_68;
  
  lVar2 = tpidr_el0;
  local_68 = *(long *)(lVar2 + 0x28);
  *(undefined4 *)((long)param_3 + 0x14c) = param_10;
  cacao::ObjectBase::ObjectBase((ObjectBase *)&local_a0);
  local_90 = 0;
  uStack_8c = 0xffffffff;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  local_a0 = &PTR__ProcessResultBase_0002f218;
  puStack_98 = &DAT_0002f268;
  uStack_70 = 0;
  uVar4 = *(undefined4 *)(param_3 + 1);
  uVar1 = *(undefined4 *)((long)param_3 + 0xc);
  cacao::ObjectBase::ObjectBase((ObjectBase *)&local_e0);
  uStack_b8 = 1;
  uStack_b4 = param_9;
  local_e0 = &PTR__ProcessResultBase_0002f4f8;
  puStack_d8 = &DAT_0002f548;
  uStack_74 = param_9;
  uStack_78 = 1;
  local_d0 = uVar1;
  local_cc = uVar4;
  uStack_c8 = param_4;
  uStack_c4 = param_5;
  uStack_c0 = param_6;
  local_bc = param_7;
  uStack_b0 = param_8;
  local_90 = uVar1;
  uStack_8c = uVar4;
  uStack_88 = param_4;
  uStack_84 = param_5;
  uStack_80 = param_6;
  uStack_7c = param_7;
  uStack_70 = param_8;
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_e0);
  iVar3 = (**(code **)(*(long *)*param_3 + 0x20))();
  if ((iVar3 == 0) ||
     (__android_log_print(6,0,"%s: cacao stop() ret=%d","BypassCameraVideo_changeToSuperSlowMode",
                          iVar3), iVar3 != -0x6e)) {
    iVar3 = (**(code **)(*(long *)*param_3 + 0x18))((long *)*param_3,&local_a0);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      __android_log_print(6,0,"%s: cacao start() failed. ERR=%d",
                          "BypassCameraVideo_changeToSuperSlowMode",iVar3);
      uVar4 = 0xffffffff;
    }
  }
  else {
    uVar4 = 0xfffffffe;
  }
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_a0);
  if (*(long *)(lVar2 + 0x28) == local_68) {
    return uVar4;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



undefined4
BypassCameraVideo_prepareVideoRecording
          (long *param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  long lVar1;
  long *plVar2;
  undefined4 uVar3;
  long *plVar4;
  long *local_80;
  long *local_78;
  long *local_70;
  void *local_68;
  undefined4 local_60;
  long local_58;
  
  lVar1 = tpidr_el0;
  local_58 = *(long *)(lVar1 + 0x28);
  local_60 = 0;
  local_68 = (void *)getSurface(param_1,param_4);
  if ((local_68 == (void *)0x0) || (android::RefBase::incStrong(local_68), local_68 == (void *)0x0))
  {
    __android_log_print(6,0,"%s: Could not retrieve native Surface from surface.",
                        "BypassCameraVideo_prepareVideoRecording");
    uVar3 = 0xffffffff;
  }
  else {
    android::Surface::getIGraphicBufferProducer();
    if (local_70 == (long *)0x0) {
      __android_log_print(6,0,"%s: Could not retrieve IGraphicBufferProducer from surface.",
                          "BypassCameraVideo_prepareVideoRecording");
      uVar3 = 0xffffffff;
    }
    else {
      local_80 = local_70;
      android::RefBase::incStrong((void *)((long)local_70 + *(long *)(*local_70 + -0x18)));
      android::IInterface::asBinder((sp *)&local_80);
      if (local_80 != (long *)0x0) {
        android::RefBase::decStrong((void *)((long)local_80 + *(long *)(*local_80 + -0x18)));
      }
      plVar2 = local_78;
      if (local_78 == (long *)0x0) {
        __android_log_print(6,0,"%s: Could not retrieve IBinder from surface.",
                            "BypassCameraVideo_prepareVideoRecording");
        uVar3 = 0xffffffff;
      }
      else {
        plVar4 = *(long **)(param_3 + 0x160);
        android::RefBase::incStrong((void *)((long)local_78 + *(long *)(*local_78 + -0x18)));
        if (plVar4 != (long *)0x0) {
          android::RefBase::decStrong((void *)((long)plVar4 + *(long *)(*plVar4 + -0x18)));
        }
        if (plVar4 != *(long **)(param_3 + 0x160)) {
          android::sp_report_race();
        }
        *(long **)(param_3 + 0x160) = plVar2;
        *(undefined4 *)(param_3 + 0x150) = param_5;
        *(undefined4 *)(param_3 + 0x154) = param_6;
        *(undefined4 *)(param_3 + 0x158) = param_7;
        pthread_mutex_lock(*(pthread_mutex_t **)(param_3 + 0x130));
        android::VectorImpl::push(*(void **)(param_3 + 0x120));
        pthread_cond_signal(*(pthread_cond_t **)(param_3 + 0x128));
        pthread_mutex_unlock(*(pthread_mutex_t **)(param_3 + 0x130));
        uVar3 = 0;
      }
      if (local_78 != (long *)0x0) {
        android::RefBase::decStrong((void *)((long)local_78 + *(long *)(*local_78 + -0x18)));
      }
    }
    if (local_70 != (long *)0x0) {
      android::RefBase::decStrong((void *)((long)local_70 + *(long *)(*local_70 + -0x18)));
    }
  }
  if (local_68 != (void *)0x0) {
    android::RefBase::decStrong(local_68);
  }
  if (*(long *)(lVar1 + 0x28) != local_58) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return uVar3;
}



undefined4
BypassCameraVideo_prepareSuperSlowRecording
          (long *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  long *plVar2;
  undefined4 uVar3;
  long *plVar4;
  long *local_70;
  long *local_68;
  long *local_60;
  void *local_58;
  undefined4 local_50;
  long local_48;
  
  lVar1 = tpidr_el0;
  local_48 = *(long *)(lVar1 + 0x28);
  local_50 = 4;
  local_58 = (void *)getSurface(param_1,param_4);
  if ((local_58 == (void *)0x0) || (android::RefBase::incStrong(local_58), local_58 == (void *)0x0))
  {
    __android_log_print(6,0,"%s: Could not retrieve native Surface from surface.",
                        "BypassCameraVideo_prepareSuperSlowRecording");
    uVar3 = 0xffffffff;
  }
  else {
    android::Surface::getIGraphicBufferProducer();
    if (local_60 == (long *)0x0) {
      __android_log_print(6,0,"%s: Could not retrieve IGraphicBufferProducer from surface.",
                          "BypassCameraVideo_prepareSuperSlowRecording");
      uVar3 = 0xffffffff;
    }
    else {
      local_70 = local_60;
      android::RefBase::incStrong((void *)((long)local_60 + *(long *)(*local_60 + -0x18)));
      android::IInterface::asBinder((sp *)&local_70);
      if (local_70 != (long *)0x0) {
        android::RefBase::decStrong((void *)((long)local_70 + *(long *)(*local_70 + -0x18)));
      }
      plVar2 = local_68;
      if (local_68 == (long *)0x0) {
        __android_log_print(6,0,"%s: Could not retrieve IBinder from surface.",
                            "BypassCameraVideo_prepareSuperSlowRecording");
        uVar3 = 0xffffffff;
      }
      else {
        plVar4 = *(long **)(param_3 + 0x160);
        android::RefBase::incStrong((void *)((long)local_68 + *(long *)(*local_68 + -0x18)));
        if (plVar4 != (long *)0x0) {
          android::RefBase::decStrong((void *)((long)plVar4 + *(long *)(*plVar4 + -0x18)));
        }
        if (plVar4 != *(long **)(param_3 + 0x160)) {
          android::sp_report_race();
        }
        *(long **)(param_3 + 0x160) = plVar2;
        pthread_mutex_lock(*(pthread_mutex_t **)(param_3 + 0x130));
        android::VectorImpl::push(*(void **)(param_3 + 0x120));
        pthread_cond_signal(*(pthread_cond_t **)(param_3 + 0x128));
        pthread_mutex_unlock(*(pthread_mutex_t **)(param_3 + 0x130));
        uVar3 = 0;
      }
      if (local_68 != (long *)0x0) {
        android::RefBase::decStrong((void *)((long)local_68 + *(long *)(*local_68 + -0x18)));
      }
    }
    if (local_60 != (long *)0x0) {
      android::RefBase::decStrong((void *)((long)local_60 + *(long *)(*local_60 + -0x18)));
    }
  }
  if (local_58 != (void *)0x0) {
    android::RefBase::decStrong(local_58);
  }
  if (*(long *)(lVar1 + 0x28) != local_48) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return uVar3;
}



undefined8 BypassCameraVideo_startVideoRecording(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = tpidr_el0;
  lVar3 = *(long *)(lVar1 + 0x28);
  pthread_mutex_lock(*(pthread_mutex_t **)(param_3 + 0x130));
  android::VectorImpl::push(*(void **)(param_3 + 0x120));
  pthread_cond_signal(*(pthread_cond_t **)(param_3 + 0x128));
  iVar2 = pthread_mutex_unlock(*(pthread_mutex_t **)(param_3 + 0x130));
  if (*(long *)(lVar1 + 0x28) == lVar3) {
    return 0;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(iVar2);
}



undefined8
BypassCameraVideo_startSuperSlowRecording(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = tpidr_el0;
  lVar3 = *(long *)(lVar1 + 0x28);
  pthread_mutex_lock(*(pthread_mutex_t **)(param_3 + 0x130));
  android::VectorImpl::push(*(void **)(param_3 + 0x120));
  pthread_cond_signal(*(pthread_cond_t **)(param_3 + 0x128));
  iVar2 = pthread_mutex_unlock(*(pthread_mutex_t **)(param_3 + 0x130));
  if (*(long *)(lVar1 + 0x28) == lVar3) {
    return 0;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(iVar2);
}



undefined8 BypassCameraVideo_stopVideoRecording(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = tpidr_el0;
  lVar3 = *(long *)(lVar1 + 0x28);
  pthread_mutex_lock(*(pthread_mutex_t **)(param_3 + 0x130));
  android::VectorImpl::push(*(void **)(param_3 + 0x120));
  pthread_cond_signal(*(pthread_cond_t **)(param_3 + 0x128));
  iVar2 = pthread_mutex_unlock(*(pthread_mutex_t **)(param_3 + 0x130));
  if (*(long *)(lVar1 + 0x28) == lVar3) {
    return 0;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(iVar2);
}



// imageprocessor::VideoPrepareCallback::VideoPrepareCallback()

void __thiscall
imageprocessor::VideoPrepareCallback::VideoPrepareCallback(VideoPrepareCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f408;
  return;
}



// imageprocessor::VideoPrepareCallback::onHandleResult(cacao::ProcessResultBase const*)

void __thiscall
imageprocessor::VideoPrepareCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  plVar2 = (long *)getJNIEnv();
  _JNIEnv::CallVoidMethod
            (plVar2,*(undefined8 *)(lVar1 + 0xc0),*(undefined8 *)(lVar1 + 200),2,param_5,param_6,
             param_7,param_8);
  return;
}



// imageprocessor::VideoFinishCallback::VideoFinishCallback()

void __thiscall imageprocessor::VideoFinishCallback::VideoFinishCallback(VideoFinishCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f438;
  return;
}



// imageprocessor::VideoFinishCallback::onHandleResult(cacao::ProcessResultBase const*)

void __thiscall
imageprocessor::VideoFinishCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  plVar2 = *(long **)(lVar1 + 0x160);
  if (plVar2 != (long *)0x0) {
    android::RefBase::decStrong((void *)((long)plVar2 + *(long *)(*plVar2 + -0x18)));
  }
  if (plVar2 != *(long **)(lVar1 + 0x160)) {
    android::sp_report_race();
  }
  *(undefined8 *)(lVar1 + 0x160) = 0;
  plVar2 = (long *)getJNIEnv();
  _JNIEnv::CallVoidMethod
            (plVar2,*(undefined8 *)(lVar1 + 0xc0),*(undefined8 *)(lVar1 + 200),1,param_5,param_6,
             param_7,param_8);
  return;
}



// imageprocessor::VideoStartRecCallback::VideoStartRecCallback()

void __thiscall
imageprocessor::VideoStartRecCallback::VideoStartRecCallback(VideoStartRecCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f468;
  return;
}



// imageprocessor::VideoStartRecCallback::onHandleResult(cacao::ProcessResultBase const*)

void __thiscall
imageprocessor::VideoStartRecCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  plVar2 = (long *)getJNIEnv();
  _JNIEnv::CallVoidMethod
            (plVar2,*(undefined8 *)(lVar1 + 0xc0),*(undefined8 *)(lVar1 + 200),0,param_5,param_6,
             param_7,param_8);
  return;
}



// imageprocessor::VideoPrepareSuperSlowCallback::VideoPrepareSuperSlowCallback()

void __thiscall
imageprocessor::VideoPrepareSuperSlowCallback::VideoPrepareSuperSlowCallback
          (VideoPrepareSuperSlowCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f498;
  return;
}



// imageprocessor::VideoPrepareSuperSlowCallback::onHandleResult(cacao::ProcessResultBase const*)

void __thiscall
imageprocessor::VideoPrepareSuperSlowCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  plVar2 = (long *)getJNIEnv();
  _JNIEnv::CallVoidMethod
            (plVar2,*(undefined8 *)(lVar1 + 0xc0),*(undefined8 *)(lVar1 + 200),4,param_5,param_6,
             param_7,param_8);
  return;
}



// imageprocessor::VideoStartSuperSlowRecCallback::VideoStartSuperSlowRecCallback()

void __thiscall
imageprocessor::VideoStartSuperSlowRecCallback::VideoStartSuperSlowRecCallback
          (VideoStartSuperSlowRecCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f4c8;
  return;
}



// imageprocessor::VideoStartSuperSlowRecCallback::onHandleResult(cacao::ProcessResultBase const*)

void __thiscall
imageprocessor::VideoStartSuperSlowRecCallback::onHandleResult
          (undefined8 param_1_00,long *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  plVar2 = (long *)getJNIEnv();
  _JNIEnv::CallVoidMethod
            (plVar2,*(undefined8 *)(lVar1 + 0xc0),*(undefined8 *)(lVar1 + 200),3,param_5,param_6,
             param_7,param_8);
  return;
}



// cacao::ProcessCtrlSuperSlowMode::getClassName() const

char * cacao::ProcessCtrlSuperSlowMode::getClassName(void)

{
  return "ProcessCtrlSuperSlowMode";
}



// android::Vector<imageprocessor::VideoThreadCommand>::~Vector()

void __thiscall android::Vector<>::~Vector(Vector<> *this)

{
  *(undefined ***)this = &PTR__Vector_0002f580;
  android::VectorImpl::finish_vector();
  android::VectorImpl::~VectorImpl((VectorImpl *)this);
  return;
}



// android::Vector<imageprocessor::VideoThreadCommand>::~Vector()

void __thiscall android::Vector<>::~Vector(Vector<> *this)

{
  *(undefined ***)this = &PTR__Vector_0002f580;
  android::VectorImpl::finish_vector();
  android::VectorImpl::~VectorImpl((VectorImpl *)this);
  operator_delete(this);
  return;
}



// android::Vector<imageprocessor::VideoThreadCommand>::do_construct(void*, unsigned long) const

void __thiscall android::Vector<>::do_construct(undefined8 param_1_00,void *param_2,long param_3)

{
  if (param_3 != 0) {
    memset(param_2,0xff,param_3 << 2);
    return;
  }
  return;
}



// android::Vector<imageprocessor::VideoThreadCommand>::do_move_backward(void*, void const*,
// unsigned long) const

void __thiscall
android::Vector<>::do_move_backward
          (undefined8 param_1_00,undefined4 *param_2,undefined4 *param_3,ulong param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  
  uVar2 = (uint)param_4;
  if ((long)param_4 < 0x10) {
    if (param_4 == 0) {
      return;
    }
  }
  else if ((param_3 + param_4 <= param_2) || (param_2 + param_4 <= param_3)) {
    lVar3 = param_4 - 1;
    uVar9 = 0;
    uVar4 = lVar3 - (param_4 & 0xf);
    puVar5 = (undefined8 *)(param_3 + 8);
    puVar8 = (undefined8 *)(param_2 + 8);
    do {
      uVar11 = puVar5[-4];
      uVar13 = puVar5[-1];
      uVar12 = puVar5[-2];
      uVar15 = puVar5[1];
      uVar14 = *puVar5;
      uVar17 = puVar5[3];
      uVar16 = puVar5[2];
      uVar10 = uVar9 | 0xf;
      uVar9 = uVar9 + 0x10;
      puVar8[-3] = puVar5[-3];
      puVar8[-4] = uVar11;
      puVar8[-1] = uVar13;
      puVar8[-2] = uVar12;
      puVar8[1] = uVar15;
      *puVar8 = uVar14;
      puVar8[3] = uVar17;
      puVar8[2] = uVar16;
      puVar5 = puVar5 + 8;
      puVar8 = puVar8 + 8;
    } while (uVar10 != uVar4);
    lVar6 = uVar4 + 1;
    if (lVar3 < lVar6) {
      return;
    }
    lVar7 = lVar6;
    if ((uVar2 >> 3 & 1) != 0) {
      uVar11 = *(undefined8 *)(param_3 + lVar6);
      uVar13 = *(undefined8 *)((long)(param_3 + uVar4 + 5) + 8);
      uVar12 = *(undefined8 *)(param_3 + uVar4 + 5);
      lVar7 = uVar4 + 9;
      *(undefined8 *)((long)(param_2 + lVar6) + 8) = *(undefined8 *)((long)(param_3 + lVar6) + 8);
      *(undefined8 *)(param_2 + lVar6) = uVar11;
      *(undefined8 *)((long)(param_2 + uVar4 + 5) + 8) = uVar13;
      *(undefined8 *)(param_2 + uVar4 + 5) = uVar12;
      if (lVar3 < lVar7) {
        return;
      }
    }
    lVar6 = lVar7;
    if ((uVar2 >> 2 & 1) != 0) {
      uVar11 = *(undefined8 *)(param_3 + lVar7);
      lVar6 = lVar7 + 4;
      *(undefined8 *)((long)(param_2 + lVar7) + 8) = *(undefined8 *)((long)(param_3 + lVar7) + 8);
      *(undefined8 *)(param_2 + lVar7) = uVar11;
      if (lVar3 < lVar6) {
        return;
      }
    }
    lVar7 = lVar6;
    if ((uVar2 >> 1 & 1) != 0) {
      lVar7 = lVar6 + 2;
      *(undefined8 *)(param_2 + lVar6) = *(undefined8 *)(param_3 + lVar6);
      if (lVar3 < lVar7) {
        return;
      }
    }
    param_2[lVar7] = param_3[lVar7];
    return;
  }
  uVar9 = param_4 & 7;
  if (6 < param_4 - 1) {
    lVar3 = param_4 - uVar9;
    do {
      lVar3 = lVar3 + -8;
      *param_2 = *param_3;
      param_2[1] = param_3[1];
      param_2[2] = param_3[2];
      param_2[3] = param_3[3];
      param_2[4] = param_3[4];
      param_2[5] = param_3[5];
      param_2[6] = param_3[6];
      puVar1 = param_3 + 7;
      param_3 = param_3 + 8;
      param_2[7] = *puVar1;
      param_2 = param_2 + 8;
    } while (lVar3 != 0);
  }
  for (; uVar9 != 0; uVar9 = uVar9 - 1) {
    *param_2 = *param_3;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  }
  return;
}



// android::Vector<imageprocessor::VideoThreadCommand>::do_splat(void*, void const*, unsigned long)
// const

void __thiscall
android::Vector<>::do_splat
          (undefined8 param_1_00,undefined4 *param_2,undefined4 *param_3,ulong param_4)

{
  undefined4 uVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 uVar10;
  
  uVar3 = (uint)param_4;
  uVar2 = param_4 - 1;
  if ((long)param_4 < 1) {
    if (param_4 == 0) {
      return;
    }
  }
  else if ((0xf < (long)param_4) &&
          ((uVar1 = *param_3, param_3 + 1 <= param_2 || (param_2 + param_4 <= param_3)))) {
    uVar8 = 0;
    uVar10 = CONCAT44(uVar1,uVar1);
    uVar7 = uVar2 - (param_4 & 0xf);
    puVar5 = (undefined8 *)(param_2 + 8);
    do {
      uVar9 = uVar8 | 0xf;
      puVar5[-3] = uVar10;
      puVar5[-4] = CONCAT44(uVar1,uVar1);
      puVar5[-1] = uVar10;
      puVar5[-2] = CONCAT44(uVar1,uVar1);
      puVar5[1] = uVar10;
      *puVar5 = CONCAT44(uVar1,uVar1);
      puVar5[3] = uVar10;
      puVar5[2] = CONCAT44(uVar1,uVar1);
      uVar8 = uVar8 + 0x10;
      puVar5 = puVar5 + 8;
    } while (uVar9 != uVar7);
    lVar4 = uVar7 + 1;
    if ((long)uVar2 < lVar4) {
      return;
    }
    if ((uVar3 >> 3 & 1) != 0) {
      puVar5 = (undefined8 *)(param_2 + lVar4);
      lVar4 = uVar7 + 9;
      puVar5[1] = uVar10;
      *puVar5 = CONCAT44(uVar1,uVar1);
      puVar5[3] = uVar10;
      puVar5[2] = CONCAT44(uVar1,uVar1);
      if ((long)uVar2 < lVar4) {
        return;
      }
    }
    lVar6 = lVar4;
    if ((uVar3 >> 2 & 1) != 0) {
      lVar6 = lVar4 + 4;
      *(undefined8 *)((long)(param_2 + lVar4) + 8) = uVar10;
      *(ulong *)(param_2 + lVar4) = CONCAT44(uVar1,uVar1);
      if ((long)uVar2 < lVar6) {
        return;
      }
    }
    lVar4 = lVar6;
    if ((uVar3 >> 1 & 1) != 0) {
      lVar4 = lVar6 + 2;
      *(ulong *)(param_2 + lVar6) = CONCAT44(uVar1,uVar1);
      if ((long)uVar2 < lVar4) {
        return;
      }
    }
    param_2[lVar4] = uVar1;
    return;
  }
  uVar8 = param_4 & 7;
  if (6 < uVar2) {
    lVar4 = param_4 - uVar8;
    do {
      lVar4 = lVar4 + -8;
      *param_2 = *param_3;
      param_2[1] = *param_3;
      param_2[2] = *param_3;
      param_2[3] = *param_3;
      param_2[4] = *param_3;
      param_2[5] = *param_3;
      param_2[6] = *param_3;
      param_2[7] = *param_3;
      param_2 = param_2 + 8;
    } while (lVar4 != 0);
  }
  for (; uVar8 != 0; uVar8 = uVar8 - 1) {
    *param_2 = *param_3;
    param_2 = param_2 + 1;
  }
  return;
}



// android::Vector<imageprocessor::VideoThreadCommand>::do_move_forward(void*, void const*, unsigned
// long) const

void __thiscall
android::Vector<>::do_move_forward
          (undefined8 param_1_00,undefined8 *param_2,ulong param_3,ulong param_4)

{
  undefined8 *puVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined4 *puVar5;
  ulong uVar6;
  long lVar7;
  undefined4 *puVar8;
  ulong uVar9;
  undefined4 *puVar10;
  undefined8 *puVar11;
  ulong uVar12;
  undefined8 uVar13;
  
  if ((long)param_4 < 4) {
    if (param_4 == 0) {
      return;
    }
  }
  else {
    lVar2 = param_4 * 4;
    if (((undefined8 *)(param_3 + lVar2) <= param_2) || ((ulong)((long)param_2 + lVar2) <= param_3))
    {
      lVar4 = param_4 - 1;
      uVar9 = 0;
      lVar3 = lVar2 + -4;
      puVar11 = (undefined8 *)(((long)param_2 + lVar2) - 8);
      uVar6 = lVar4 - (param_4 & 3);
      puVar1 = (undefined8 *)(param_3 + lVar2);
      do {
        uVar13 = puVar1[-2];
        uVar12 = uVar9 | 3;
        uVar9 = uVar9 + 4;
        *puVar11 = puVar1[-1];
        puVar11[-1] = uVar13;
        puVar11 = puVar11 + -2;
        puVar1 = puVar1 + -2;
      } while (uVar12 != uVar6);
      lVar2 = uVar6 + 1;
      if (lVar4 < lVar2) {
        return;
      }
      if (1 < (param_4 & 3)) {
        lVar2 = uVar6 + 3;
        lVar7 = lVar3 - (uVar6 * 4 + 8);
        uVar13 = *(undefined8 *)(param_3 + lVar7);
        *(int *)((long)param_2 + (lVar3 - (uVar6 * 4 + 4))) = (int)((ulong)uVar13 >> 0x20);
        *(int *)((long)param_2 + lVar7) = (int)uVar13;
        if (lVar4 < lVar2) {
          return;
        }
      }
      lVar3 = lVar3 + lVar2 * -4;
      *(undefined4 *)((long)param_2 + lVar3) = *(undefined4 *)(param_3 + lVar3);
      return;
    }
  }
  puVar5 = (undefined4 *)(param_3 + param_4 * 4);
  puVar10 = (undefined4 *)((long)param_2 + param_4 * 4);
  uVar9 = param_4 & 7;
  if (6 < param_4 - 1) {
    lVar2 = param_4 - uVar9;
    puVar8 = puVar10;
    do {
      lVar2 = lVar2 + -8;
      puVar8[-1] = puVar5[-1];
      puVar8[-2] = puVar5[-2];
      puVar8[-3] = puVar5[-3];
      puVar8[-4] = puVar5[-4];
      puVar8[-5] = puVar5[-5];
      puVar8[-6] = puVar5[-6];
      puVar8[-7] = puVar5[-7];
      puVar5 = puVar5 + -8;
      puVar10 = puVar8 + -8;
      puVar8[-8] = *puVar5;
      puVar8 = puVar10;
    } while (lVar2 != 0);
  }
  for (; uVar9 != 0; uVar9 = uVar9 - 1) {
    puVar10 = puVar10 + -1;
    puVar5 = puVar5 + -1;
    *puVar10 = *puVar5;
  }
  return;
}



// imageprocessor::BypassCameraVideo_thread(void*)

void imageprocessor::BypassCameraVideo_thread(undefined8 *param_1)

{
  ulong uVar1;
  long *plVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  undefined **local_1e0;
  undefined *puStack_1d8;
  undefined4 local_1d0;
  undefined2 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined2 local_1a8;
  undefined1 local_a7;
  undefined8 local_a0;
  undefined1 local_98;
  undefined4 local_94;
  undefined1 local_90;
  undefined8 local_8c;
  undefined8 uStack_84;
  undefined1 local_7c;
  long *local_78;
  undefined8 local_70;
  
  setpriority(PRIO_PROCESS,0,-0x14);
LAB_0000e3b0:
  do {
    pthread_mutex_lock((pthread_mutex_t *)param_1[0x26]);
    while (uVar1 = param_1[0x24], *(long *)(uVar1 + 0x10) == 0) {
      pthread_cond_wait((pthread_cond_t *)param_1[0x25],(pthread_mutex_t *)param_1[0x26]);
    }
    uVar6 = **(undefined4 **)(uVar1 + 8);
    android::VectorImpl::removeItemsAt(uVar1,0);
    pthread_mutex_unlock((pthread_mutex_t *)param_1[0x26]);
    switch(uVar6) {
    case 0:
      cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1e0);
      local_1e0 = &PTR__ProcessCtrlVideoRecParam_0002f5d0;
      puStack_1d8 = &DAT_0002f628;
      local_1c8 = 0;
      local_a7 = 0;
      local_a0 = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_1a8 = 0;
      local_1b8 = 0;
      uStack_1b0 = 0;
      local_1c0 = 0;
      local_7c = 0;
      local_8c = 0;
      uStack_84 = 0;
      local_78 = (long *)0x0;
      local_1d0 = 10;
      if (((*(int *)(param_1 + 0x2a) == 0) || (*(int *)((long)param_1 + 0x154) == 0)) ||
         (*(int *)(param_1 + 0x2b) == 0)) {
        uVar7 = 0x104;
        if (*(int *)(param_1 + 0x29) * *(int *)((long)param_1 + 0x144) < 0xe1000) {
          uVar7 = 0x102;
        }
      }
      else {
        uVar7 = 0x12060000;
      }
      local_70 = (ulong)uVar7;
      (**(code **)(*(long *)*param_1 + 0x48))
                ((long *)*param_1,&local_1e0,param_1 + 0x2c,param_1[0x1a],param_1[0x1b]);
      goto LAB_0000e658;
    case 1:
      cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1e0);
      local_1d0 = 0xb;
      plVar2 = (long *)*param_1;
      uVar4 = param_1[0x1e];
      uVar5 = param_1[0x1f];
      break;
    case 2:
      cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1e0);
      local_1d0 = 0xc;
      plVar2 = (long *)*param_1;
      uVar4 = param_1[0x1c];
      uVar5 = param_1[0x1d];
      break;
    case 3:
                    // WARNING: Subroutine does not return
      BypassCameraVideo_threadFinishThread();
    case 4:
      cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1e0);
      local_1d0 = 10;
      uVar6 = 0x103;
      if (0xe0fff < *(int *)(param_1 + 0x29) * *(int *)((long)param_1 + 0x144)) {
        uVar6 = 0x104;
      }
      local_70 = CONCAT44(*(undefined4 *)((long)param_1 + 0x14c),uVar6);
      plVar2 = (long *)*param_1;
      uVar4 = param_1[0x20];
      uVar5 = param_1[0x21];
      pcVar8 = *(code **)(*plVar2 + 0x48);
      puVar3 = param_1 + 0x2c;
      goto LAB_0000e650;
    case 5:
      cacao::ObjectBase::ObjectBase((ObjectBase *)&local_1e0);
      local_1d0 = 0xd;
      plVar2 = (long *)*param_1;
      uVar4 = param_1[0x22];
      uVar5 = param_1[0x23];
      break;
    default:
      goto switchD_0000e3fc_default;
    }
    local_70 = 0;
    pcVar8 = *(code **)(*plVar2 + 0x40);
    puVar3 = (undefined8 *)0x0;
LAB_0000e650:
    puStack_1d8 = &DAT_0002f628;
    local_1e0 = &PTR__ProcessCtrlVideoRecParam_0002f5d0;
    local_78 = (long *)0x0;
    local_7c = 0;
    uStack_84 = 0;
    local_8c = 0;
    local_90 = 0;
    local_94 = 0;
    local_98 = 0;
    local_a0 = 0;
    local_a7 = 0;
    local_1a8 = 0;
    uStack_1b0 = 0;
    local_1b8 = 0;
    local_1c0 = 0;
    local_1c8 = 0;
    (*pcVar8)(plVar2,&local_1e0,puVar3,uVar4,uVar5);
LAB_0000e658:
    puStack_1d8 = &DAT_0002f628;
    local_1e0 = &PTR__ProcessCtrlVideoRecParam_0002f5d0;
    if (local_78 != (long *)0x0) {
      android::RefBase::decStrong((void *)((long)local_78 + *(long *)(*local_78 + -0x18)));
    }
    cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_1e0);
  } while( true );
switchD_0000e3fc_default:
  __android_log_print(6,0,"%s: unexpected command[%d]","BypassCameraVideo_thread",uVar6);
  goto LAB_0000e3b0;
}



// imageprocessor::BypassCameraVideo_threadFinishThread(imageprocessor::BypassCameraContext*)

void imageprocessor::BypassCameraVideo_threadFinishThread(void)

{
  __android_log_print(3,0,"%s: thread exit.","BypassCameraVideo_threadFinishThread");
                    // WARNING: Subroutine does not return
  pthread_exit((void *)0x0);
}



// cacao::ProcessCtrlVideoRecParam::~ProcessCtrlVideoRecParam()

void __thiscall
cacao::ProcessCtrlVideoRecParam::~ProcessCtrlVideoRecParam(ProcessCtrlVideoRecParam *this)

{
  long *plVar1;
  
  plVar1 = *(long **)(this + 0x168);
  *(undefined **)(this + 8) = &DAT_0002f628;
  *(undefined ***)this = &PTR__ProcessCtrlVideoRecParam_0002f5d0;
  if (plVar1 != (long *)0x0) {
    android::RefBase::decStrong((void *)((long)plVar1 + *(long *)(*plVar1 + -0x18)));
  }
  cacao::ObjectBase::~ObjectBase((ObjectBase *)this);
  return;
}



// cacao::ProcessCtrlVideoRecParam::~ProcessCtrlVideoRecParam()

void __thiscall
cacao::ProcessCtrlVideoRecParam::~ProcessCtrlVideoRecParam(ProcessCtrlVideoRecParam *this)

{
  void *extraout_x1;
  long *plVar1;
  
  plVar1 = *(long **)(this + 0x168);
  *(undefined **)(this + 8) = &DAT_0002f628;
  *(undefined ***)this = &PTR__ProcessCtrlVideoRecParam_0002f5d0;
  if (plVar1 != (long *)0x0) {
    android::RefBase::decStrong((void *)((long)plVar1 + *(long *)(*plVar1 + -0x18)));
  }
  cacao::ObjectBase::~ObjectBase((ObjectBase *)this);
  cacao::ObjectBase::operator_delete((ObjectBase *)this,extraout_x1);
  return;
}



// cacao::ProcessCtrlVideoRecParam::getClassName() const

char * cacao::ProcessCtrlVideoRecParam::getClassName(void)

{
  return "ProcessCtrlVideoRecParam";
}



// cacao::ProcessCtrlVideoRecParam::clone() const

ObjectBase * cacao::ProcessCtrlVideoRecParam::clone(long param_1,ulong param_2)

{
  ObjectBase *this;
  long *plVar1;
  long *plVar2;
  
  this = cacao::ObjectBase::operator_new((ObjectBase *)0x178,param_2);
  cacao::ObjectBase::ObjectBase(this);
  *(undefined2 *)(this + 0x18) = 0;
  this[0x139] = (ObjectBase)0x0;
  *(undefined8 *)(this + 0x140) = 0;
  this[0x148] = (ObjectBase)0x0;
  *(undefined4 *)(this + 0x14c) = 0;
  this[0x150] = (ObjectBase)0x0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined2 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x15c) = 0;
  *(undefined8 *)(this + 0x154) = 0;
  this[0x164] = (ObjectBase)0x0;
  *(undefined8 *)(this + 0x168) = 0;
  *(undefined8 *)(this + 0x170) = 0;
  *(undefined **)(this + 8) = &DAT_0002f628;
  *(undefined ***)this = &PTR__ProcessCtrlVideoRecParam_0002f5d0;
  *(undefined4 *)(this + 0x10) = 0xe;
  if ((this != (ObjectBase *)0x0) && (param_1 != 0)) {
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    memcpy(this + 0x18,(void *)(param_1 + 0x18),0x150);
    plVar2 = *(long **)(this + 0x168);
    plVar1 = *(long **)(param_1 + 0x168);
    if (plVar1 != (long *)0x0) {
      android::RefBase::incStrong((void *)((long)plVar1 + *(long *)(*plVar1 + -0x18)));
    }
    if (plVar2 != (long *)0x0) {
      android::RefBase::decStrong((void *)((long)plVar2 + *(long *)(*plVar2 + -0x18)));
    }
    if (plVar2 != *(long **)(this + 0x168)) {
      android::sp_report_race();
    }
    *(long **)(this + 0x168) = plVar1;
    *(undefined4 *)(this + 0x170) = *(undefined4 *)(param_1 + 0x170);
    *(undefined4 *)(this + 0x174) = *(undefined4 *)(param_1 + 0x174);
  }
  return this;
}



// cacao::ProcessCtrlVideoRecParam::copy(cacao::ProcessParamBase const*)

void __thiscall cacao::ProcessCtrlVideoRecParam::copy(ProcessCtrlVideoRecParam *this,long param_1)

{
  long *plVar1;
  long *plVar2;
  
  if (param_1 != 0) {
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    memcpy(this + 0x18,(void *)(param_1 + 0x18),0x150);
    plVar2 = *(long **)(this + 0x168);
    plVar1 = *(long **)(param_1 + 0x168);
    if (plVar1 != (long *)0x0) {
      android::RefBase::incStrong((void *)((long)plVar1 + *(long *)(*plVar1 + -0x18)));
    }
    if (plVar2 != (long *)0x0) {
      android::RefBase::decStrong((void *)((long)plVar2 + *(long *)(*plVar2 + -0x18)));
    }
    if (plVar2 != *(long **)(this + 0x168)) {
      android::sp_report_race();
    }
    *(long **)(this + 0x168) = plVar1;
    *(undefined4 *)(this + 0x170) = *(undefined4 *)(param_1 + 0x170);
    *(undefined4 *)(this + 0x174) = *(undefined4 *)(param_1 + 0x174);
  }
  return;
}



// non-virtual thunk to cacao::ProcessCtrlVideoRecParam::getSerializedSize() const

undefined8 __thiscall cacao::ProcessCtrlVideoRecParam::getSerializedSize(void)

{
  return 0x160;
}



// cacao::ProcessCtrlVideoRecParam::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall
cacao::ProcessCtrlVideoRecParam::serialize(ProcessCtrlVideoRecParam *this,long param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x188) != 0)) {
    uVar2 = *(uint *)(param_1 + 400);
    if ((uVar2 <= *(uint *)(param_1 + 0x184)) &&
       ((ulong)uVar2 + 0x158 <= (ulong)*(uint *)(param_1 + 0x184))) {
      puVar1 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar2);
      *puVar1 = *(undefined4 *)(this + 0x10);
      memcpy(puVar1 + 2,this + 0x18,0x150);
      uVar2 = *(int *)(param_1 + 400) + 0x158;
      *(uint *)(param_1 + 400) = uVar2;
      if ((ulong)uVar2 + 4 <= (ulong)*(uint *)(param_1 + 0x184)) {
        puVar1 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar2);
        *puVar1 = *(undefined4 *)(this + 0x170);
        puVar1[1] = *(undefined4 *)(this + 0x174);
        *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 8;
        return 0;
      }
    }
  }
  return 0xffffff99;
}



// cacao::ProcessCtrlVideoRecParam::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall
cacao::ProcessCtrlVideoRecParam::deserialize(ProcessCtrlVideoRecParam *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (((param_1 != 0) && (*(long *)(param_1 + 0x188) != 0)) &&
     ((ulong)*(uint *)(param_1 + 400) + 0x158 <= (ulong)*(uint *)(param_1 + 0x184))) {
    puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    *(undefined4 *)(this + 0x10) = *puVar2;
    memcpy(this + 0x18,puVar2 + 2,0x150);
    uVar1 = *(int *)(param_1 + 400) + 0x158;
    *(uint *)(param_1 + 400) = uVar1;
    if ((ulong)uVar1 + 8 <= (ulong)*(uint *)(param_1 + 0x184)) {
      puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
      *(undefined4 *)(this + 0x170) = *puVar2;
      *(undefined4 *)(this + 0x174) = puVar2[1];
      *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 8;
      return 0;
    }
  }
  return 0xffffff99;
}



// non-virtual thunk to cacao::ProcessCtrlVideoRecParam::~ProcessCtrlVideoRecParam()

void __thiscall
cacao::ProcessCtrlVideoRecParam::~ProcessCtrlVideoRecParam(ProcessCtrlVideoRecParam *this)

{
  long *plVar1;
  
  *(undefined **)this = &DAT_0002f628;
  *(undefined ***)(this + -8) = &PTR__ProcessCtrlVideoRecParam_0002f5d0;
  plVar1 = *(long **)(this + 0x160);
  if (plVar1 != (long *)0x0) {
    android::RefBase::decStrong((void *)((long)plVar1 + *(long *)(*plVar1 + -0x18)));
  }
  cacao::ObjectBase::~ObjectBase((ObjectBase *)(this + -8));
  return;
}



// non-virtual thunk to cacao::ProcessCtrlVideoRecParam::~ProcessCtrlVideoRecParam()

void __thiscall
cacao::ProcessCtrlVideoRecParam::~ProcessCtrlVideoRecParam(ProcessCtrlVideoRecParam *this)

{
  void *extraout_x1;
  long *plVar1;
  ObjectBase *this_00;
  
  this_00 = (ObjectBase *)(this + -8);
  *(undefined **)this = &DAT_0002f628;
  *(undefined ***)this_00 = &PTR__ProcessCtrlVideoRecParam_0002f5d0;
  plVar1 = *(long **)(this + 0x160);
  if (plVar1 != (long *)0x0) {
    android::RefBase::decStrong((void *)((long)plVar1 + *(long *)(*plVar1 + -0x18)));
  }
  cacao::ObjectBase::~ObjectBase(this_00);
  cacao::ObjectBase::operator_delete(this_00,extraout_x1);
  return;
}



// non-virtual thunk to
// cacao::ProcessCtrlVideoRecParam::serialize(cacao::ISerialize::SerializedData*) const

undefined8 __thiscall
cacao::ProcessCtrlVideoRecParam::serialize(ProcessCtrlVideoRecParam *this,long param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x188) != 0)) {
    uVar2 = *(uint *)(param_1 + 400);
    if ((uVar2 <= *(uint *)(param_1 + 0x184)) &&
       ((ulong)uVar2 + 0x158 <= (ulong)*(uint *)(param_1 + 0x184))) {
      puVar1 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar2);
      *puVar1 = *(undefined4 *)(this + 8);
      memcpy(puVar1 + 2,this + 0x10,0x150);
      uVar2 = *(int *)(param_1 + 400) + 0x158;
      *(uint *)(param_1 + 400) = uVar2;
      if ((ulong)uVar2 + 4 <= (ulong)*(uint *)(param_1 + 0x184)) {
        puVar1 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar2);
        *puVar1 = *(undefined4 *)(this + 0x168);
        puVar1[1] = *(undefined4 *)(this + 0x16c);
        *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 8;
        return 0;
      }
    }
  }
  return 0xffffff99;
}



// non-virtual thunk to
// cacao::ProcessCtrlVideoRecParam::deserialize(cacao::ISerialize::SerializedData*)

undefined8 __thiscall
cacao::ProcessCtrlVideoRecParam::deserialize(ProcessCtrlVideoRecParam *this,long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (((param_1 != 0) && (*(long *)(param_1 + 0x188) != 0)) &&
     ((ulong)*(uint *)(param_1 + 400) + 0x158 <= (ulong)*(uint *)(param_1 + 0x184))) {
    puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(param_1 + 400));
    *(undefined4 *)(this + 8) = *puVar2;
    memcpy(this + 0x10,puVar2 + 2,0x150);
    uVar1 = *(int *)(param_1 + 400) + 0x158;
    *(uint *)(param_1 + 400) = uVar1;
    if ((ulong)uVar1 + 8 <= (ulong)*(uint *)(param_1 + 0x184)) {
      puVar2 = (undefined4 *)(*(long *)(param_1 + 0x188) + (ulong)uVar1);
      *(undefined4 *)(this + 0x168) = *puVar2;
      *(undefined4 *)(this + 0x16c) = puVar2[1];
      *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 8;
      return 0;
    }
  }
  return 0xffffff99;
}



// WARNING: Removing unreachable block (ram,0x0000eddc)
// WARNING: Removing unreachable block (ram,0x0000edf4)

void BypassCameraBurstBufferManager_initializeSurface
               (long *param_1,undefined8 param_2,int param_3,long param_4)

{
  Surface *pSVar1;
  long lVar2;
  long *plVar3;
  void *pvVar4;
  ulong uVar5;
  ulong uVar6;
  char *pcVar7;
  ulong uVar8;
  void *pvVar9;
  Surface *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  long *local_60;
  long *local_58;
  void *local_50;
  long local_48;
  
  lVar2 = tpidr_el0;
  local_48 = *(long *)(lVar2 + 0x28);
  local_70 = 0;
  uStack_68 = 0;
  *(int *)(param_4 + 0x1d8) = param_3;
  local_58 = (long *)0x0;
  local_50 = (void *)0x0;
  local_78 = (Surface *)0x0;
  pvVar4 = (void *)getSurface(param_1,param_2);
  pvVar9 = local_50;
  if (pvVar4 != (void *)0x0) {
    android::RefBase::incStrong(pvVar4);
  }
  if (pvVar9 != (void *)0x0) {
    android::RefBase::decStrong(pvVar9);
  }
  if (pvVar9 != local_50) {
    android::sp_report_race();
  }
  local_50 = pvVar4;
  if (pvVar4 == (void *)0x0) {
    pcVar7 = "%s: android_view_Surface_getSurface() failed.";
LAB_0000ee1c:
    __android_log_print(6,0,pcVar7,"BypassCameraBurstBufferManager_createNativeSurface");
  }
  else {
    android::Surface::getIGraphicBufferProducer();
    plVar3 = local_58;
    if (local_58 != (long *)0x0) {
      android::RefBase::decStrong((void *)((long)local_58 + *(long *)(*local_58 + -0x18)));
    }
    if (plVar3 != local_58) {
      android::sp_report_race();
    }
    local_58 = local_60;
    if (local_60 == (long *)0x0) {
      pcVar7 = "%s: getIGraphicBufferProducer() failed.";
      goto LAB_0000ee1c;
    }
    local_78 = operator_new(0x2500);
    android::Surface::Surface(local_78,(sp *)&local_58,false);
    android::RefBase::incStrong(local_78);
  }
  if (local_58 != (long *)0x0) {
    android::RefBase::decStrong((void *)((long)local_58 + *(long *)(*local_58 + -0x18)));
  }
  if (local_50 != (void *)0x0) {
    android::RefBase::decStrong(local_50);
  }
  pvVar9 = *(void **)(param_4 + 0x1a0);
  if (pvVar9 != (void *)0x0) {
    android::RefBase::decStrong(pvVar9);
  }
  if (pvVar9 != *(void **)(param_4 + 0x1a0)) {
    android::sp_report_race();
  }
  *(Surface **)(param_4 + 0x1a0) = local_78;
  if (local_78 == (Surface *)0x0) {
    __android_log_print(6,0,"%s: android_view_Surface_getSurface() failed.",
                        "BypassCameraBurstBufferManager_initializeSurface");
  }
  else {
    pSVar1 = local_78 + 0x10;
    uVar5 = (**(code **)(local_78 + 0xa8))(pSVar1,0xd,4);
    uVar8 = uVar5 & 0xffffffff;
    if ((int)uVar5 == 0) {
      uVar5 = (**(code **)(local_78 + 0xa8))(pSVar1,0x1e,0x20023);
      uVar8 = uVar5 & 0xffffffff;
      if ((int)uVar5 == 0) {
        uVar5 = (**(code **)(local_78 + 0xa8))(pSVar1,10,1);
        uVar8 = uVar5 & 0xffffffff;
        if ((int)uVar5 == 0) {
          uVar5 = (**(code **)(local_78 + 0xa8))(pSVar1,6,0);
          uVar8 = uVar5 & 0xffffffff;
          if ((int)uVar5 == 0) {
            uVar5 = (**(code **)(local_78 + 0xa0))(pSVar1,2,&uStack_68);
            uVar8 = uVar5 & 0xffffffff;
            if ((int)uVar5 == 0) {
              uVar5 = (**(code **)(local_78 + 0xa0))(pSVar1,3,(long)&uStack_68 + 4);
              uVar8 = uVar5 & 0xffffffff;
              if ((int)uVar5 == 0) {
                uVar5 = (**(code **)(local_78 + 0xa0))(pSVar1,0xc,&local_50);
                uVar8 = uVar5 & 0xffffffff;
                if ((int)uVar5 == 0) {
                  uVar5 = (**(code **)(local_78 + 0xa0))(pSVar1,0,(long)&local_70 + 4);
                  uVar8 = uVar5 & 0xffffffff;
                  if ((int)uVar5 == 0) {
                    uVar5 = (**(code **)(local_78 + 0xa0))(pSVar1,1,&local_70);
                    uVar8 = uVar5 & 0xffffffff;
                    if ((int)uVar5 == 0) {
                      uVar5 = cacao::ProcessFactory::getJpegBufferSize
                                        (CONCAT44((undefined4)local_70,local_70._4_4_));
                      uVar8 = uVar5 & 0xffffffff;
                      __android_log_print(3,0,"[Debug] %s cacao::ImageBuf::getJpegBufferSize()=%d",
                                          "BypassCameraBurstBufferManager_getJpegBufferSize",uVar8);
                      if ((int)uVar5 == 0) {
                        pcVar7 = "%s: getJpegBufferSize() failed. ERR=%d";
                      }
                      else {
                        __android_log_print(3,0,"%s: maxSize: %d",
                                            "BypassCameraBurstBufferManager_initializeSurface");
                        uVar6 = (**(code **)(local_78 + 0xa8))(pSVar1,4,(long)param_3);
                        uVar8 = uVar6 & 0xffffffff;
                        if ((int)uVar6 == 0) {
                          uVar5 = (**(code **)(local_78 + 0xa8))(pSVar1,8,uVar5 & 0xffffffff,1);
                          uVar8 = uVar5 & 0xffffffff;
                          if ((int)uVar5 == 0) goto LAB_0000f038;
                          pcVar7 = "%s: native_window_set_buffers_dimensions() failed. ERR=%d";
                        }
                        else {
                          pcVar7 = "%s: native_window_set_buffer_count() failed. ERR=%d";
                        }
                      }
                    }
                    else {
                      pcVar7 = "%s: anw->query(HEIGHT) failed. ERR=%d";
                    }
                  }
                  else {
                    pcVar7 = "%s: anw->query(WIDTH) failed. ERR=%d";
                  }
                }
                else {
                  pcVar7 = "%s: anw->query(NATIVE_WINDOW_DEFAULT_DATASPACE) failed. ERR=%d";
                }
              }
              else {
                pcVar7 = "%s: anw->query(MIN_UNDEQUEUED_BUFFERS) failed. ERR=%d";
              }
            }
            else {
              pcVar7 = "%s: anw->query(NATIVE_WINDOW_FORMAT) failed. ERR=%d";
            }
          }
          else {
            pcVar7 = "%s: native_window_set_buffers_transform() failed. ERR=%d";
          }
        }
        else {
          pcVar7 = "%s: native_window_set_scaling_mode() failed. ERR=%d";
        }
      }
      else {
        pcVar7 = "%s: native_window_set_usage() failed. ERR=%d";
      }
    }
    else {
      pcVar7 = "%s: native_window_api_connect() failed. ERR=%d";
    }
    __android_log_print(6,0,pcVar7,"BypassCameraBurstBufferManager_initializeSurface",uVar8);
  }
  uVar5 = 0xffffffff;
LAB_0000f038:
  if (*(long *)(lVar2 + 0x28) != local_48) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail(uVar5);
  }
  return;
}



void BypassCameraBurstBufferManager_finalizeSurface(long param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  void *pvVar4;
  
  lVar3 = *(long *)(param_1 + 0x1a0);
  plVar1 = (long *)(param_1 + 0x1a0);
  if (lVar3 == 0) {
    __android_log_print(6,0,"%s: Surface is not initialized.",
                        "BypassCameraBurstBufferManager_finalizeSurface");
    lVar3 = *plVar1;
    if (lVar3 == 0) goto LAB_0000f1b8;
  }
  iVar2 = (**(code **)(lVar3 + 0xa8))(lVar3 + 0x10,0xe,4);
  if (iVar2 != 0) {
    __android_log_print(6,0,"%s: native_window_api_disconnect() failed. ERR=%d",
                        "BypassCameraBurstBufferManager_finalizeSurface",iVar2);
  }
  if ((void *)*plVar1 != (void *)0x0) {
    android::RefBase::decStrong((void *)*plVar1);
    *plVar1 = 0;
  }
LAB_0000f1b8:
  pvVar4 = (void *)*plVar1;
  if (pvVar4 != (void *)0x0) {
    android::RefBase::decStrong(pvVar4);
  }
  if (pvVar4 != (void *)*plVar1) {
    android::sp_report_race();
  }
  *plVar1 = 0;
  return;
}



int BypassCameraBurstBufferManager_createBuffers(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 *puVar5;
  SortedVectorImpl *pSVar6;
  ImageBuf *pIVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  long lVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  void *pvVar15;
  undefined1 auVar16 [16];
  long local_98;
  undefined4 local_8c;
  long local_88;
  undefined4 *puStack_80;
  long local_78;
  
  lVar4 = tpidr_el0;
  local_78 = *(long *)(lVar4 + 0x28);
  BypassCameraBurstBufferManager_deleteBuffers(param_1);
  pSVar6 = operator_new(0x30);
  android::SortedVectorImpl::SortedVectorImpl(pSVar6,0x10,7);
  *(undefined8 *)(pSVar6 + 0x28) = 0;
  *(undefined ***)pSVar6 = &PTR__SortedVector_0002f660;
  *(SortedVectorImpl **)(param_1 + 400) = pSVar6;
  pSVar6 = operator_new(0x30);
  android::SortedVectorImpl::SortedVectorImpl(pSVar6,0x10,7);
  *(undefined8 *)(pSVar6 + 0x28) = 0;
  *(undefined ***)pSVar6 = &PTR__SortedVector_0002f6b8;
  *(SortedVectorImpl **)(param_1 + 0x198) = pSVar6;
  local_8c = 0;
  local_98 = 0;
  lVar1 = 0;
  if (*(long *)(param_1 + 0x1a0) != 0) {
    lVar1 = *(long *)(param_1 + 0x1a0) + 0x10;
  }
  __android_log_print(3,0,"[Debug] %s bufCount: %d","BypassCameraBurstBufferManager_createBuffers",
                      *(undefined4 *)(param_1 + 0x1d8));
  if (*(int *)(param_1 + 0x1d8) < 1) {
    iVar11 = 0;
  }
  else {
    iVar11 = 0;
    do {
      auVar16 = (**(code **)(lVar1 + 0xa8))(lVar1,&local_98,&local_8c);
      if (auVar16._0_4_ != 0) {
        __android_log_print(6,0,"%s: dequeueBuffer() failed. ERR=%d",
                            "BypassCameraBurstBufferManager_createBuffers",
                            auVar16._0_8_ & 0xffffffff);
        iVar11 = -1;
        goto LAB_0000f444;
      }
      puVar8 = (undefined4 *)(param_1 + 0x80);
      puVar5 = (undefined4 *)(param_1 + 0x84);
      if (*(int *)(param_1 + 0xc) != 0) {
        puVar8 = (undefined4 *)(param_1 + 0x144);
        puVar5 = (undefined4 *)(param_1 + 0x148);
      }
      uVar2 = *puVar8;
      uVar3 = *puVar5;
      pIVar7 = cacao::ObjectBase::operator_new((ObjectBase *)0x38,auVar16._8_8_);
      cacao::ImageBuf::ImageBuf(pIVar7,*(undefined8 *)(local_98 + 0x60),CONCAT44(uVar3,uVar2),1,0);
      __android_log_print(3,0,"[Debug] %s create ImageBuf[%d] ImageSize: %dx%d",
                          "BypassCameraBurstBufferManager_createBuffers",iVar11,uVar2,uVar3);
      puVar8 = operator_new(0x20);
      *(undefined8 *)(puVar8 + 6) = 0xffffffff00000000;
      *(ImageBuf **)(puVar8 + 2) = pIVar7;
      *(long *)(puVar8 + 4) = local_98;
      *puVar8 = local_8c;
      uVar9 = (**(code **)(*(long *)pIVar7 + 0x20))(pIVar7);
      __android_log_print(3,0,
                          "[Debug] %s ImageBuf: %x, ImageBuf->getNative():%x, pAndroidNativeBufferT: %x"
                          ,"BypassCameraBurstBufferManager_createBuffers",pIVar7,uVar9,local_98);
      local_88 = local_98;
      puStack_80 = puVar8;
      android::SortedVectorImpl::add(*(void **)(param_1 + 400));
      pvVar15 = *(void **)(param_1 + 0x198);
      local_88 = (**(code **)(*(long *)pIVar7 + 0x20))(pIVar7);
      puStack_80 = puVar8;
      android::SortedVectorImpl::add(pvVar15);
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(param_1 + 0x1d8));
    iVar11 = 0;
  }
LAB_0000f444:
  __android_log_print(3,0,"[Debug] %s dequeueAllEnd","BypassCameraBurstBufferManager_createBuffers")
  ;
  __android_log_print(3,0,"[Debug] cancelBuffer in");
  lVar10 = *(long *)(param_1 + 400);
  lVar12 = *(long *)(lVar10 + 0x10);
  if (lVar12 != 0) {
    lVar13 = 0;
    lVar14 = 8;
    while( true ) {
      puVar8 = *(undefined4 **)(*(long *)(lVar10 + 8) + lVar14);
      (**(code **)(lVar1 + 0xb8))(lVar1,*(undefined8 *)(puVar8 + 4),*puVar8);
      lVar13 = lVar13 + 1;
      if (lVar13 == lVar12) break;
      lVar10 = *(long *)(param_1 + 400);
      lVar14 = lVar14 + 0x10;
    }
  }
  __android_log_print(3,0,"[Debug] cancelBuffer end");
  if (iVar11 == 0) {
    *(undefined1 *)(param_1 + 0x1d0) = 1;
  }
  if (*(long *)(lVar4 + 0x28) == local_78) {
    return iVar11;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Removing unreachable block (ram,0x0000f55c)

void BypassCameraBurstBufferManager_deleteBuffers(long param_1)

{
  long lVar1;
  ulong uVar2;
  int *piVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar1 = *(long *)(param_1 + 400);
  *(undefined1 *)(param_1 + 0x1d0) = 0;
  if (lVar1 == 0) goto LAB_0000f6b4;
  uVar2 = *(ulong *)(lVar1 + 0x10);
  if (uVar2 != 0) {
    if (uVar2 == 1) {
      lVar4 = 0;
    }
    else {
      lVar5 = 0;
      lVar4 = 0;
      lVar6 = uVar2 - (uVar2 & 1);
      do {
        piVar3 = *(int **)(*(long *)(lVar1 + 8) + lVar5 + 8);
        __android_log_print(3,0,"[Debug] %s info. anb(%p) fence(%d)",
                            "BypassCameraBurstBufferManager_deleteBuffers",
                            *(undefined8 *)(piVar3 + 4),*piVar3);
        if (*(long **)(piVar3 + 2) != (long *)0x0) {
          (**(code **)(**(long **)(piVar3 + 2) + 8))();
        }
        piVar3[2] = 0;
        piVar3[3] = 0;
        if (*piVar3 != -1) {
          close(*piVar3);
        }
        operator_delete(piVar3);
        piVar3 = *(int **)(*(long *)(*(long *)(param_1 + 400) + 8) + lVar5 + 0x18);
        __android_log_print(3,0,"[Debug] %s info. anb(%p) fence(%d)",
                            "BypassCameraBurstBufferManager_deleteBuffers",
                            *(undefined8 *)(piVar3 + 4),*piVar3);
        if (*(long **)(piVar3 + 2) != (long *)0x0) {
          (**(code **)(**(long **)(piVar3 + 2) + 8))();
        }
        piVar3[2] = 0;
        piVar3[3] = 0;
        if (*piVar3 != -1) {
          close(*piVar3);
        }
        operator_delete(piVar3);
        lVar1 = *(long *)(param_1 + 400);
        lVar4 = lVar4 + 2;
        lVar6 = lVar6 + -2;
        lVar5 = lVar5 + 0x20;
      } while (lVar6 != 0);
      if ((uVar2 & 1) == 0) goto LAB_0000f6ac;
    }
    piVar3 = *(int **)(*(long *)(lVar1 + 8) + lVar4 * 0x10 + 8);
    __android_log_print(3,0,"[Debug] %s info. anb(%p) fence(%d)",
                        "BypassCameraBurstBufferManager_deleteBuffers",*(undefined8 *)(piVar3 + 4),
                        *piVar3);
    if (*(long **)(piVar3 + 2) != (long *)0x0) {
      (**(code **)(**(long **)(piVar3 + 2) + 8))();
    }
    piVar3[2] = 0;
    piVar3[3] = 0;
    if (*piVar3 != -1) {
      close(*piVar3);
    }
    operator_delete(piVar3);
  }
LAB_0000f6ac:
  android::VectorImpl::clear();
  *(undefined8 *)(param_1 + 400) = 0;
LAB_0000f6b4:
  if (*(long *)(param_1 + 0x198) != 0) {
    android::VectorImpl::clear();
    *(undefined8 *)(param_1 + 0x198) = 0;
  }
  return;
}



void BypassCameraBurstBufferManager_createBufVector(long param_1,long *param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  VectorImpl *this;
  undefined8 uVar4;
  long *plVar5;
  int iVar6;
  uint uVar7;
  long local_50;
  long local_48;
  
  lVar1 = tpidr_el0;
  local_48 = *(long *)(lVar1 + 0x28);
  *param_2 = 0;
  local_50 = 0;
  this = operator_new(0x28);
  android::VectorImpl::VectorImpl(this,8,7);
  *(undefined ***)this = &PTR__Vector_0002f3b8;
  *param_2 = (long)this;
  __android_log_print(3,0,"[Debug] %s dequeueBuffer start: %d",
                      "BypassCameraBurstBufferManager_createBufVector",param_3);
  if ((int)param_3 < 1) {
    __android_log_print(3,0,"[Debug] %s dequeueBuffer end buffers: %d",
                        "BypassCameraBurstBufferManager_createBufVector",0);
  }
  else {
    uVar7 = param_3 & 3;
    iVar6 = 0;
    if (2 < param_3 - 1) {
      iVar3 = param_3 - uVar7;
      do {
        iVar2 = BypassCameraBurstBufferManager_dequeueBuffer(param_1,&local_50);
        if (iVar2 == 0) {
          android::VectorImpl::insertAt((void *)*param_2,local_50 + 8,*(ulong *)(*param_2 + 0x10));
          iVar6 = iVar6 + 1;
        }
        iVar2 = BypassCameraBurstBufferManager_dequeueBuffer(param_1,&local_50);
        if (iVar2 == 0) {
          android::VectorImpl::insertAt((void *)*param_2,local_50 + 8,*(ulong *)(*param_2 + 0x10));
          iVar6 = iVar6 + 1;
        }
        iVar2 = BypassCameraBurstBufferManager_dequeueBuffer(param_1,&local_50);
        if (iVar2 == 0) {
          android::VectorImpl::insertAt((void *)*param_2,local_50 + 8,*(ulong *)(*param_2 + 0x10));
          iVar6 = iVar6 + 1;
        }
        iVar2 = BypassCameraBurstBufferManager_dequeueBuffer(param_1,&local_50);
        if (iVar2 == 0) {
          android::VectorImpl::insertAt((void *)*param_2,local_50 + 8,*(ulong *)(*param_2 + 0x10));
          iVar6 = iVar6 + 1;
        }
        iVar3 = iVar3 + -4;
      } while (iVar3 != 0);
    }
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      while (iVar3 = BypassCameraBurstBufferManager_dequeueBuffer(param_1,&local_50), iVar3 != 0) {
        uVar7 = uVar7 - 1;
        if (uVar7 == 0) goto LAB_0000f878;
      }
      android::VectorImpl::insertAt((void *)*param_2,local_50 + 8,*(ulong *)(*param_2 + 0x10));
      iVar6 = iVar6 + 1;
    }
LAB_0000f878:
    __android_log_print(3,0,"[Debug] %s dequeueBuffer end buffers: %d",
                        "BypassCameraBurstBufferManager_createBufVector",iVar6);
    if (0 < iVar6) {
      plVar5 = (long *)**(undefined8 **)(*param_2 + 8);
      uVar4 = (**(code **)(*plVar5 + 0x20))(plVar5);
      __android_log_print(3,0,"[Debug] %s request: ImageBuf: %p, getNative: %p",
                          "BypassCameraBurstBufferManager_createBufVector",plVar5,uVar4);
      goto LAB_0000f920;
    }
  }
  __android_log_print(6,0,"%s: Could not get free buffers.",
                      "BypassCameraBurstBufferManager_createBufVector");
LAB_0000f920:
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



undefined4 BypassCameraBurstBufferManager_dequeueBuffer(long param_1,long *param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  undefined4 uVar6;
  void *pvVar7;
  undefined8 local_68;
  undefined4 local_5c;
  undefined8 local_58;
  long local_48;
  
  lVar1 = tpidr_el0;
  local_48 = *(long *)(lVar1 + 0x28);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x1a8));
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    __android_log_print(5,0,"%s: buffer is not available.",
                        "BypassCameraBurstBufferManager_dequeueBuffer");
  }
  local_68 = 0;
  lVar4 = *(long *)(param_1 + 0x1a0);
  if (lVar4 == 0) {
    __android_log_print(6,0,"%s: pBurstSurface NULL. failed.",
                        "BypassCameraBurstBufferManager_dequeueBuffer");
  }
  else {
    __android_log_print(3,0,"[Debug] %s dequeueBuffer in",
                        "BypassCameraBurstBufferManager_dequeueBuffer");
    iVar2 = (**(code **)(lVar4 + 0xb8))(lVar4 + 0x10,&local_68,&local_5c);
    __android_log_print(3,0,"[Debug] %s dequeueBuffer out",
                        "BypassCameraBurstBufferManager_dequeueBuffer");
    __android_log_print(3,0,"[Debug] %s dequeueBuffer info. pAndroidNativeBufferT(%p) fence(%d)",
                        "BypassCameraBurstBufferManager_dequeueBuffer",local_68,local_5c);
    if (iVar2 == 0) {
      pvVar7 = *(void **)(param_1 + 400);
      local_58 = local_68;
      lVar4 = android::SortedVectorImpl::indexOf(pvVar7);
      if (lVar4 < 0) {
        plVar5 = (long *)((long)pvVar7 + 0x28);
      }
      else {
        plVar5 = (long *)(*(long *)((long)pvVar7 + 8) + lVar4 * 0x10 + 8);
      }
      lVar4 = *plVar5;
      *param_2 = lVar4;
      if (lVar4 != 0) {
        *(undefined4 *)(lVar4 + 0x18) = 1;
        *(int *)(param_1 + 0x1d4) = *(int *)(param_1 + 0x1d4) + 1;
        uVar3 = (**(code **)(**(long **)(*param_2 + 8) + 0x38))();
        __android_log_print(3,0,"[Debug] %s use ImageBuf ImageSize: %dx%d",
                            "BypassCameraBurstBufferManager_dequeueBuffer",uVar3 & 0xffffffff,
                            uVar3 >> 0x20);
        uVar6 = 0;
        goto LAB_0000fb60;
      }
      __android_log_print(6,0,
                          "%s: Error. not find dequeuedBuffer in Map. pAndroidNativeBufferT(%p) fence(%d)"
                          ,"BypassCameraBurstBufferManager_dequeueBuffer",local_68,local_5c);
    }
    else if (iVar2 == -0x13) {
      __android_log_print(3,0,"%s: the consumer disconnected surface.",
                          "BypassCameraBurstBufferManager_dequeueBuffer");
      *(undefined1 *)(param_1 + 0x1d0) = 0;
    }
    else {
      __android_log_print(6,0,"%s: anw->dequeueBuffer() failed. ERR=%d",
                          "BypassCameraBurstBufferManager_dequeueBuffer",iVar2);
    }
  }
  uVar6 = 0xffffffff;
LAB_0000fb60:
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x1a8));
  if (*(long *)(lVar1 + 0x28) != local_48) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail(iVar2);
  }
  return uVar6;
}



void BypassCameraBurstBufferManager_queueBuffer(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    __android_log_print(5,0,"%s: buffer is not available.",
                        "BypassCameraBurstBufferManager_queueBuffer");
  }
  lVar2 = *(long *)(param_1 + 0x1a0);
  if (lVar2 == 0) {
    __android_log_print(6,0,"%s: burst surface null.","BypassCameraBurstBufferManager_queueBuffer");
    return;
  }
  __android_log_print(3,0,"[Debug] %s queueBuffer info. anb(%p) fence(%d)",
                      "BypassCameraBurstBufferManager_queueBuffer",*(undefined8 *)(param_2 + 4),
                      *param_2);
  iVar1 = (**(code **)(lVar2 + 0xc0))(lVar2 + 0x10,*(undefined8 *)(param_2 + 4),*param_2);
  if (iVar1 != 0) {
    __android_log_print(6,0,"%s: queueing buffer failed. ERR=%d",
                        "BypassCameraBurstBufferManager_queueBuffer",iVar1);
  }
  param_2[6] = 4;
  *(int *)(param_1 + 0x1d4) = *(int *)(param_1 + 0x1d4) + -1;
  return;
}



void BypassCameraBurstBufferManager_cancelBuffer(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    __android_log_print(5,0,"%s: buffer is not available.",
                        "BypassCameraBurstBufferManager_cancelBuffer");
  }
  lVar2 = *(long *)(param_1 + 0x1a0);
  if (lVar2 == 0) {
    __android_log_print(6,0,"%s: burst surface null.","BypassCameraBurstBufferManager_cancelBuffer")
    ;
    return;
  }
  iVar1 = (**(code **)(lVar2 + 200))(lVar2 + 0x10,*(undefined8 *)(param_2 + 4),*param_2);
  if (iVar1 != 0) {
    __android_log_print(6,0,"%s: cancel buffer. ERR=%d",
                        "BypassCameraBurstBufferManager_cancelBuffer",iVar1);
  }
  *(undefined8 *)(param_2 + 6) = 0xffffffff00000000;
  *(int *)(param_1 + 0x1d4) = *(int *)(param_1 + 0x1d4) + -1;
  return;
}



void BypassCameraBurstBufferManager_cancelBuffers(long param_1,long param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 in_x7;
  long lVar5;
  undefined8 *puVar6;
  long lVar7;
  ulong uVar8;
  void *pvVar9;
  undefined4 *puVar10;
  long *plVar11;
  
  lVar7 = tpidr_el0;
  lVar5 = *(long *)(lVar7 + 0x28);
  if (*(long *)(param_1 + 0x1a0) == 0) {
    __android_log_print(6,0,"%s: burst surface null.","BypassCameraBurstBufferManager_cancelBuffers"
                       );
    lVar7 = *(long *)(lVar7 + 0x28);
  }
  else {
    if (*(long *)(param_2 + 0x10) != 0) {
      uVar8 = 0;
      do {
        pvVar9 = *(void **)(param_1 + 0x198);
        uVar2 = (**(code **)(**(long **)(*(long *)(param_2 + 8) + uVar8 * 8) + 0x20))();
        lVar3 = android::SortedVectorImpl::indexOf(pvVar9);
        if (lVar3 < 0) {
          puVar6 = (undefined8 *)((long)pvVar9 + 0x28);
        }
        else {
          puVar6 = (undefined8 *)(*(long *)((long)pvVar9 + 8) + lVar3 * 0x10 + 8);
        }
        puVar10 = (undefined4 *)*puVar6;
        plVar11 = *(long **)(*(long *)(param_2 + 8) + uVar8 * 8);
        uVar4 = (**(code **)(*plVar11 + 0x20))(plVar11);
        __android_log_print(3,0,"[Debug] %s ImageBuf:%p, getNative:%p, BurstSnapshotBuffer:%p",
                            "BypassCameraBurstBufferManager_cancelBuffers",plVar11,uVar4,puVar10,
                            in_x7,lVar7,uVar2);
        if ((uint)uVar8 < param_3) {
          __android_log_print(3,0,"[Debug] %s waiting result (%d)",
                              "BypassCameraBurstBufferManager_cancelBuffers",uVar8);
        }
        else {
          __android_log_print(3,0,"[Debug] %s canceled (%d)",
                              "BypassCameraBurstBufferManager_cancelBuffers",uVar8);
          __android_log_print(3,0,"[Debug] %s cancelBuffer info. anb(%p) fence(%d)",
                              "BypassCameraBurstBufferManager_cancelBuffers",
                              *(undefined8 *)(puVar10 + 4),*puVar10);
          if (*(char *)(param_1 + 0x1d0) == '\0') {
            __android_log_print(5,0,"%s: buffer is not available.",
                                "BypassCameraBurstBufferManager_cancelBuffer");
          }
          lVar3 = *(long *)(param_1 + 0x1a0);
          if (lVar3 == 0) {
            __android_log_print(6,0,"%s: burst surface null.",
                                "BypassCameraBurstBufferManager_cancelBuffer");
          }
          else {
            iVar1 = (**(code **)(lVar3 + 200))(lVar3 + 0x10,*(undefined8 *)(puVar10 + 4),*puVar10);
            if (iVar1 != 0) {
              __android_log_print(6,0,"%s: cancel buffer. ERR=%d",
                                  "BypassCameraBurstBufferManager_cancelBuffer",iVar1);
            }
            *(undefined8 *)(puVar10 + 6) = 0xffffffff00000000;
            *(int *)(param_1 + 0x1d4) = *(int *)(param_1 + 0x1d4) + -1;
          }
        }
        uVar8 = (ulong)((uint)uVar8 + 1);
      } while (uVar8 < *(ulong *)(param_2 + 0x10));
    }
    lVar7 = *(long *)(lVar7 + 0x28);
  }
  if (lVar7 != lVar5) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void BypassCameraBurstBufferManager_cancelAllBuffer(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined8 *puVar8;
  void *pvVar9;
  long lVar10;
  long lVar11;
  
  lVar2 = tpidr_el0;
  lVar5 = *(long *)(lVar2 + 0x28);
  lVar6 = *(long *)(param_1 + 0x1a0);
  lVar1 = lVar6 + 0x10;
  if (lVar6 == 0) {
    __android_log_print(6,0,"%s: burst surface null.",
                        "BypassCameraBurstBufferManager_cancelAllBuffer");
  }
  else {
    uVar7 = *(ulong *)(param_2 + 0x10);
    if ((int)uVar7 != 0) {
      lVar10 = 0;
      if ((uVar7 & 0xffffffff) != 1) {
        lVar11 = (uVar7 & 0xffffffff) - (uVar7 & 1);
        do {
          pvVar9 = *(void **)(param_1 + 0x198);
          (**(code **)(**(long **)(*(long *)(param_2 + 8) + lVar10 * 8) + 0x20))();
          lVar4 = android::SortedVectorImpl::indexOf(pvVar9);
          if (lVar4 < 0) {
            puVar8 = (undefined8 *)((long)pvVar9 + 0x28);
          }
          else {
            puVar8 = (undefined8 *)(*(long *)((long)pvVar9 + 8) + lVar4 * 0x10 + 8);
          }
          iVar3 = (**(code **)(lVar6 + 200))
                            (lVar1,*(undefined8 *)((undefined4 *)*puVar8 + 4),*(undefined4 *)*puVar8
                            );
          if (iVar3 != 0) {
            __android_log_print(6,0,"%s: cancel buffer. ERR=%d",
                                "BypassCameraBurstBufferManager_cancelAllBuffer",iVar3);
          }
          pvVar9 = *(void **)(param_1 + 0x198);
          (**(code **)(**(long **)(*(long *)(param_2 + 8) + lVar10 * 8 + 8) + 0x20))();
          lVar4 = android::SortedVectorImpl::indexOf(pvVar9);
          if (lVar4 < 0) {
            puVar8 = (undefined8 *)((long)pvVar9 + 0x28);
          }
          else {
            puVar8 = (undefined8 *)(*(long *)((long)pvVar9 + 8) + lVar4 * 0x10 + 8);
          }
          iVar3 = (**(code **)(lVar6 + 200))
                            (lVar1,*(undefined8 *)((undefined4 *)*puVar8 + 4),*(undefined4 *)*puVar8
                            );
          if (iVar3 != 0) {
            __android_log_print(6,0,"%s: cancel buffer. ERR=%d",
                                "BypassCameraBurstBufferManager_cancelAllBuffer",iVar3);
          }
          lVar11 = lVar11 + -2;
          lVar10 = lVar10 + 2;
        } while (lVar11 != 0);
      }
      if ((uVar7 & 1) != 0) {
        pvVar9 = *(void **)(param_1 + 0x198);
        (**(code **)(**(long **)(*(long *)(param_2 + 8) + lVar10 * 8) + 0x20))();
        lVar10 = android::SortedVectorImpl::indexOf(pvVar9);
        if (lVar10 < 0) {
          puVar8 = (undefined8 *)((long)pvVar9 + 0x28);
        }
        else {
          puVar8 = (undefined8 *)(*(long *)((long)pvVar9 + 8) + lVar10 * 0x10 + 8);
        }
        iVar3 = (**(code **)(lVar6 + 200))
                          (lVar1,*(undefined8 *)((undefined4 *)*puVar8 + 4),*(undefined4 *)*puVar8);
        if (iVar3 != 0) {
          __android_log_print(6,0,"%s: cancel buffer. ERR=%d",
                              "BypassCameraBurstBufferManager_cancelAllBuffer",iVar3);
        }
      }
    }
  }
  if (*(long *)(lVar2 + 0x28) != lVar5) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void BypassCameraBurstBufferManager_dump(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  __android_log_print(3,0,"[Debug] %s mDequeueCounter=%d","BypassCameraBurstBufferManager_dump",
                      *(undefined4 *)(param_1 + 0x1d4));
  lVar1 = *(long *)(param_1 + 400);
  if ((lVar1 != 0) && (lVar3 = *(long *)(lVar1 + 0x10), lVar3 != 0)) {
    lVar2 = 0;
    lVar4 = 8;
    while( true ) {
      lVar1 = *(long *)(*(long *)(lVar1 + 8) + lVar4);
      __android_log_print(3,0,"[Debug] %s info[%02d]. status=%d, request id=%d",
                          "BypassCameraBurstBufferManager_dump",lVar2,*(undefined4 *)(lVar1 + 0x18),
                          *(undefined4 *)(lVar1 + 0x1c));
      lVar2 = lVar2 + 1;
      if (lVar2 == lVar3) break;
      lVar1 = *(long *)(param_1 + 400);
      lVar4 = lVar4 + 0x10;
    }
  }
  return;
}



// android::SortedVector<android::key_value_pair_t<ANativeWindowBuffer*,
// imageprocessor::BurstSnapshotBuffer*> >::~SortedVector()

void __thiscall android::SortedVector<>::~SortedVector(SortedVector<> *this)

{
  *(undefined ***)this = &PTR__SortedVector_0002f660;
  android::VectorImpl::finish_vector();
  android::SortedVectorImpl::~SortedVectorImpl((SortedVectorImpl *)this);
  return;
}



// android::SortedVector<android::key_value_pair_t<ANativeWindowBuffer*,
// imageprocessor::BurstSnapshotBuffer*> >::~SortedVector()

void __thiscall android::SortedVector<>::~SortedVector(SortedVector<> *this)

{
  *(undefined ***)this = &PTR__SortedVector_0002f660;
  android::VectorImpl::finish_vector();
  android::SortedVectorImpl::~SortedVectorImpl((SortedVectorImpl *)this);
  operator_delete(this);
  return;
}



// android::SortedVector<android::key_value_pair_t<ANativeWindowBuffer*,
// imageprocessor::BurstSnapshotBuffer*> >::do_splat(void*, void const*, unsigned long) const

void __thiscall
android::SortedVector<>::do_splat
          (undefined8 param_1_00,undefined8 *param_2,undefined8 *param_3,ulong param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  
  uVar5 = (uint)param_4;
  uVar3 = param_4 - 1;
  if ((long)param_4 < 1) {
    if (param_4 == 0) {
      return;
    }
  }
  else if (0xf < (long)param_4) {
    uVar1 = *param_3;
    uVar2 = param_3[1];
    if ((param_3 + 2 <= param_2) || (param_2 + param_4 * 2 <= param_3)) {
      uVar8 = 0;
      uVar7 = uVar3 - (param_4 & 0xf);
      puVar4 = param_2 + 0x10;
      do {
        puVar4[-0x10] = uVar1;
        puVar4[-0xf] = uVar2;
        puVar4[-0xe] = uVar1;
        puVar4[-0xd] = uVar2;
        puVar4[-0xc] = uVar1;
        puVar4[-0xb] = uVar2;
        puVar4[-10] = uVar1;
        puVar4[-9] = uVar2;
        puVar4[-8] = uVar1;
        puVar4[-7] = uVar2;
        puVar4[-6] = uVar1;
        puVar4[-5] = uVar2;
        puVar4[-4] = uVar1;
        puVar4[-3] = uVar2;
        puVar4[-2] = uVar1;
        puVar4[-1] = uVar2;
        uVar9 = uVar8 | 0xf;
        *puVar4 = uVar1;
        puVar4[1] = uVar2;
        puVar4[2] = uVar1;
        puVar4[3] = uVar2;
        puVar4[4] = uVar1;
        puVar4[5] = uVar2;
        puVar4[6] = uVar1;
        puVar4[7] = uVar2;
        puVar4[8] = uVar1;
        puVar4[9] = uVar2;
        puVar4[10] = uVar1;
        puVar4[0xb] = uVar2;
        uVar8 = uVar8 + 0x10;
        puVar4[0xc] = uVar1;
        puVar4[0xd] = uVar2;
        puVar4[0xe] = uVar1;
        puVar4[0xf] = uVar2;
        puVar4 = puVar4 + 0x20;
      } while (uVar9 != uVar7);
      lVar6 = uVar7 + 1;
      if ((long)uVar3 < lVar6) {
        return;
      }
      if ((uVar5 >> 3 & 1) != 0) {
        puVar4 = param_2 + lVar6 * 2;
        lVar6 = uVar7 + 9;
        *puVar4 = uVar1;
        puVar4[1] = uVar2;
        puVar4[2] = uVar1;
        puVar4[3] = uVar2;
        puVar4[4] = uVar1;
        puVar4[5] = uVar2;
        puVar4[6] = uVar1;
        puVar4[7] = uVar2;
        puVar4[8] = uVar1;
        puVar4[9] = uVar2;
        puVar4[10] = uVar1;
        puVar4[0xb] = uVar2;
        puVar4[0xc] = uVar1;
        puVar4[0xd] = uVar2;
        puVar4[0xe] = uVar1;
        puVar4[0xf] = uVar2;
        if ((long)uVar3 < lVar6) {
          return;
        }
      }
      if ((uVar5 >> 2 & 1) != 0) {
        puVar4 = param_2 + lVar6 * 2;
        lVar6 = lVar6 + 4;
        *puVar4 = uVar1;
        puVar4[1] = uVar2;
        puVar4[2] = uVar1;
        puVar4[3] = uVar2;
        puVar4[4] = uVar1;
        puVar4[5] = uVar2;
        puVar4[6] = uVar1;
        puVar4[7] = uVar2;
        if ((long)uVar3 < lVar6) {
          return;
        }
      }
      if ((uVar5 >> 1 & 1) != 0) {
        puVar4 = param_2 + lVar6 * 2;
        lVar6 = lVar6 + 2;
        *puVar4 = uVar1;
        puVar4[1] = uVar2;
        puVar4[2] = uVar1;
        puVar4[3] = uVar2;
        if ((long)uVar3 < lVar6) {
          return;
        }
      }
      param_2[lVar6 * 2] = uVar1;
      *(undefined8 *)((long)param_2 + (lVar6 << 4 | 8U)) = uVar2;
      return;
    }
  }
  uVar8 = param_4 & 7;
  if (6 < uVar3) {
    lVar6 = param_4 - uVar8;
    puVar4 = param_2;
    do {
      lVar6 = lVar6 + -8;
      *puVar4 = *param_3;
      puVar4[1] = param_3[1];
      puVar4[2] = *param_3;
      puVar4[3] = param_3[1];
      puVar4[4] = *param_3;
      puVar4[5] = param_3[1];
      puVar4[6] = *param_3;
      puVar4[7] = param_3[1];
      puVar4[8] = *param_3;
      puVar4[9] = param_3[1];
      puVar4[10] = *param_3;
      puVar4[0xb] = param_3[1];
      puVar4[0xc] = *param_3;
      puVar4[0xd] = param_3[1];
      puVar4[0xe] = *param_3;
      param_2 = puVar4 + 0x10;
      puVar4[0xf] = param_3[1];
      puVar4 = param_2;
    } while (lVar6 != 0);
  }
  for (; uVar8 != 0; uVar8 = uVar8 - 1) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2 = param_2 + 2;
  }
  return;
}



// android::SortedVector<android::key_value_pair_t<void*, imageprocessor::BurstSnapshotBuffer*>
// >::do_compare(void const*, void const*) const

int __thiscall
android::SortedVector<>::do_compare(undefined8 param_1_00,ulong *param_2,ulong *param_3)

{
  return (uint)(*param_3 < *param_2) - (uint)(*param_2 < *param_3);
}



// android::SortedVector<android::key_value_pair_t<void*, imageprocessor::BurstSnapshotBuffer*>
// >::~SortedVector()

void __thiscall android::SortedVector<>::~SortedVector(SortedVector<> *this)

{
  *(undefined ***)this = &PTR__SortedVector_0002f6b8;
  android::VectorImpl::finish_vector();
  android::SortedVectorImpl::~SortedVectorImpl((SortedVectorImpl *)this);
  return;
}



// android::SortedVector<android::key_value_pair_t<void*, imageprocessor::BurstSnapshotBuffer*>
// >::~SortedVector()

void __thiscall android::SortedVector<>::~SortedVector(SortedVector<> *this)

{
  *(undefined ***)this = &PTR__SortedVector_0002f6b8;
  android::VectorImpl::finish_vector();
  android::SortedVectorImpl::~SortedVectorImpl((SortedVectorImpl *)this);
  operator_delete(this);
  return;
}



undefined8 BypassCameraBurst_initialize(long *param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  *(undefined1 *)(param_3 + 0x168) = 1;
  *(undefined4 *)(param_3 + 0x16c) = 0;
  puVar1 = operator_new(8);
  *puVar1 = &PTR_do_destroy_0002f710;
  *(undefined8 **)(param_3 + 0x188) = puVar1;
  uVar2 = (**(code **)(*param_1 + 0x30))
                    (param_1,"com/sonymobile/imageprocessor/bypasscamera2/BypassCamera");
  uVar3 = (**(code **)(*param_1 + 0x108))(param_1,uVar2,"callbackFromNative","(IIIZZZIII)V");
  (**(code **)(*param_1 + 0xb8))(param_1,uVar2);
  uVar2 = (**(code **)(*param_1 + 0xa8))(param_1,param_2);
  *(undefined8 *)(param_3 + 0x178) = uVar2;
  *(undefined8 *)(param_3 + 0x180) = uVar3;
  return 0;
}



void BypassCameraBurst_finalize(long *param_1,undefined8 param_2,long param_3)

{
  if (*(int *)(param_3 + 0x1d4) != 0) {
    __android_log_print(5,0,"%s: wrong mDequeueCounter=%d","BypassCameraBurst_finalize");
  }
  *(undefined1 *)(param_3 + 0x168) = 0;
  if (*(long *)(param_3 + 0x178) != 0) {
    (**(code **)(*param_1 + 0xb0))(param_1);
    *(undefined8 *)(param_3 + 0x178) = 0;
  }
  if (*(long **)(param_3 + 0x188) != (long *)0x0) {
    (**(code **)(**(long **)(param_3 + 0x188) + 8))();
  }
  *(undefined8 *)(param_3 + 0x188) = 0;
  return;
}



void BypassCameraBurst_requestSnapshot
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long *param_4,
               undefined8 param_5,undefined8 *param_6,char param_7,char param_8,char param_9,
               undefined8 param_10,char param_11,int param_12,char param_13,int param_14,
               char param_15,undefined4 param_16,undefined4 param_17,undefined4 param_18,
               undefined4 param_19,char param_20,uint param_21)

{
  long lVar1;
  char *__src;
  undefined8 *puVar2;
  ObjectBase *this;
  long lVar3;
  ulong extraout_x1;
  void *pvVar4;
  ulong uVar5;
  long *plVar6;
  undefined8 uVar7;
  code *pcVar8;
  long local_488;
  undefined8 local_480;
  undefined1 auStack_470 [336];
  undefined **local_320;
  undefined *puStack_318;
  undefined4 local_310;
  undefined1 auStack_308 [336];
  undefined1 local_1b8;
  undefined1 local_1b7;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined1 local_198;
  char acStack_197 [256];
  undefined1 local_97;
  long local_90;
  bool local_88;
  undefined4 local_84;
  undefined1 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 local_6c;
  long local_68;
  
  local_1b8 = param_7 != '\0';
  local_1b7 = param_8 != '\0';
  local_198 = param_9 != '\0';
  lVar1 = tpidr_el0;
  local_68 = *(long *)(lVar1 + 0x28);
  *(int *)((long)param_6 + 0x16c) = *(int *)((long)param_6 + 0x16c) + 1;
  local_488 = 0;
  local_1b0 = param_1;
  local_1a8 = param_2;
  local_1a0 = param_3;
  __src = (char *)(**(code **)(*param_4 + 0x548))(param_4,param_10,&local_320);
  memset(acStack_197,0,0x100);
  strncpy(acStack_197,__src,0xff);
  (**(code **)(*param_4 + 0x550))(param_4,param_10,__src);
  local_88 = param_13 != '\0';
  if (param_13 != '\0') {
    if (param_14 < 0xb4) {
      if (param_14 == 0) {
        local_84 = 0;
        goto LAB_00010844;
      }
      if (param_14 == 0x5a) {
        local_84 = 1;
        goto LAB_00010844;
      }
    }
    else {
      if (param_14 == 0xb4) {
        local_84 = 2;
        goto LAB_00010844;
      }
      if (param_14 == 0x10e) {
        local_84 = 3;
        goto LAB_00010844;
      }
    }
  }
  local_88 = false;
LAB_00010844:
  local_97 = param_11 != '\0';
  local_90 = (long)param_12;
  local_80 = param_15 != '\0';
  local_78 = param_17;
  local_6c = param_20 != '\0';
  local_7c = param_16;
  local_74 = param_18;
  local_70 = param_19;
  BypassCameraBurstBufferManager_createBufVector((long)param_6,&local_488,param_21);
  if (local_488 == 0) {
    __android_log_print(6,0,"%s: createBurstBufArray() failed.","BypassCameraBurst_requestSnapshot")
    ;
    uVar7 = 0xffffffff;
  }
  else {
    memcpy(auStack_470,&local_1b8,0x150);
    cacao::ObjectBase::ObjectBase((ObjectBase *)&local_320);
    local_320 = &PTR__ProcessResultBase_0002f328;
    puStack_318 = &DAT_0002f380;
    local_310 = 4;
    memcpy(auStack_308,auStack_470,0x150);
    lVar3 = local_488;
    puVar2 = operator_new(0x20);
    *puVar2 = param_6;
    puVar2[1] = 0;
    puVar2[2] = lVar3;
    *(undefined4 *)(puVar2 + 3) = *(undefined4 *)((long)param_6 + 0x16c);
    plVar6 = (long *)*param_6;
    uVar7 = param_6[0x31];
    pcVar8 = *(code **)(*plVar6 + 0x40);
    this = cacao::ObjectBase::operator_new((ObjectBase *)0x40,extraout_x1);
    cacao::ObjectBase::ObjectBase(this);
    *(undefined8 **)(this + 0x18) = puVar2;
    *(undefined8 *)(this + 0x10) = 0xffffffff00000000;
    *(undefined **)(this + 8) = &DAT_0002f130;
    *(undefined ***)this = &PTR__ProcessResultBase_0002f0c0;
    *(undefined8 *)(this + 0x30) = 0;
    *(undefined4 *)(this + 0x38) = 0xffff0000;
    *(undefined8 *)(this + 0x28) = 0xffffffff00000000;
    *(undefined8 *)(this + 0x20) = 0;
    this[0x3c] = (ObjectBase)0xff;
    (*pcVar8)(plVar6,&local_320,lVar3,uVar7,this);
    if (*(long *)(local_488 + 0x10) != 0) {
      uVar5 = 0;
      do {
        pvVar4 = (void *)param_6[0x33];
        local_480 = (**(code **)(**(long **)(*(long *)(local_488 + 8) + uVar5 * 8) + 0x20))();
        lVar3 = android::SortedVectorImpl::indexOf(pvVar4);
        if (lVar3 < 0) {
          plVar6 = (long *)((long)pvVar4 + 0x28);
        }
        else {
          plVar6 = (long *)(*(long *)((long)pvVar4 + 8) + lVar3 * 0x10 + 8);
        }
        lVar3 = *plVar6;
        uVar5 = uVar5 + 1;
        *(undefined4 *)(lVar3 + 0x18) = 2;
        *(undefined4 *)(lVar3 + 0x1c) = *(undefined4 *)((long)param_6 + 0x16c);
      } while (uVar5 < *(ulong *)(local_488 + 0x10));
    }
    BypassCameraBurstBufferManager_dump((long)param_6);
    cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_320);
    uVar7 = 0;
  }
  if (*(long *)(lVar1 + 0x28) == local_68) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar7);
}



// imageprocessor::BurstCallback::BurstCallback()

void __thiscall imageprocessor::BurstCallback::BurstCallback(BurstCallback *this)

{
  *(undefined ***)this = &PTR_do_destroy_0002f710;
  return;
}



// imageprocessor::BurstCallback::onHandleProgress(cacao::ProcessResultBase const*)

void __thiscall imageprocessor::BurstCallback::onHandleProgress(undefined8 param_1_00,long *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  long lVar10;
  void *pvVar11;
  undefined4 *puVar12;
  
  lVar4 = tpidr_el0;
  lVar8 = *(long *)(lVar4 + 0x28);
  plVar6 = (long *)(**(code **)(*param_2 + 0x40))(param_2);
  lVar10 = *plVar6;
  uVar1 = *(uint *)(plVar6 + 3);
  if (*(char *)(lVar10 + 0x168) == '\0') {
    __android_log_print(6,0,"%s: already finalized or not initialized yet: requestId=%d",
                        "onHandleProgress",uVar1);
  }
  if (*(int *)((long)param_2 + 0x24) == 1) {
    __android_log_print(3,0,"[Debug] onHandleProgress progressType: ProgressType_Frame");
    iVar5 = (**(code **)(*param_2 + 0x20))(param_2);
    iVar3 = *(int *)((long)param_2 + 0x2c);
    pvVar11 = *(void **)(lVar10 + 0x198);
    plVar6 = *(long **)(*(long *)(plVar6[2] + 8) + (long)iVar3 * 8);
    (**(code **)(*plVar6 + 0x20))(plVar6);
    lVar7 = android::SortedVectorImpl::indexOf(pvVar11);
    if (lVar7 < 0) {
      puVar9 = (undefined8 *)((long)pvVar11 + 0x28);
    }
    else {
      puVar9 = (undefined8 *)(*(long *)((long)pvVar11 + 8) + lVar7 * 0x10 + 8);
    }
    puVar12 = (undefined4 *)*puVar9;
    puVar12[6] = 3;
    __android_log_print(3,0,"[Debug] onHandleProgress bufIndex: %d, pBurstSnapshotBuffer: %x",iVar3,
                        puVar12);
    if (iVar5 == 0) {
      BypassCameraBurstBufferManager_queueBuffer(lVar10,puVar12);
    }
    else {
      __android_log_print(3,0,"[Debug] %s: error %d","onHandleProgress",iVar5);
    }
  }
  else if (*(int *)((long)param_2 + 0x24) == 0) {
    lVar7 = param_2[5];
    uVar2 = *(uint *)((long)param_2 + 0x34);
    __android_log_print(3,0,
                        "[Debug] onHandleProgress ProgressType_Ready: bufferNum: %d, captureNum: %d"
                        ,*(undefined4 *)(plVar6[2] + 0x10),uVar2);
    BypassCameraBurstBufferManager_cancelBuffers(lVar10,plVar6[2],uVar2);
    plVar6 = (long *)getJNIEnv();
    _JNIEnv::CallVoidMethod
              (plVar6,*(undefined8 *)(lVar10 + 0x178),*(undefined8 *)(lVar10 + 0x180),0x14,
               (ulong)uVar1,(ulong)uVar2,(ulong)((int)lVar7 != 0),0,0,0xff,0xff,0xff);
  }
  else {
    __android_log_print(3,0,"[Debug] onHandleProgress %d");
  }
  if (*(long *)(lVar4 + 0x28) == lVar8) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// imageprocessor::BurstCallback::onHandleResult(cacao::ProcessResultBase const*)

void __thiscall imageprocessor::BurstCallback::onHandleResult(undefined8 param_1_00,long *param_2)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  
  plVar3 = (long *)(**(code **)(*param_2 + 0x40))(param_2);
  lVar5 = *plVar3;
  uVar1 = *(uint *)(plVar3 + 3);
  iVar2 = (**(code **)(*param_2 + 0x20))(param_2);
  plVar4 = (long *)getJNIEnv();
  _JNIEnv::CallVoidMethod
            (plVar4,*(undefined8 *)(lVar5 + 0x178),*(undefined8 *)(lVar5 + 0x180),0x15,(ulong)uVar1,
             0xffffffff,0,0,0,0xff,0xff,0xff);
  if (iVar2 == 0) {
    __android_log_print(3,0,"%s: burst callback result success","onHandleResult");
    lVar5 = plVar3[2];
  }
  else {
    __android_log_print(6,0,"%s: burst callback result ERR=%d","onHandleResult",iVar2);
    BypassCameraBurstBufferManager_cancelAllBuffer(lVar5,plVar3[2]);
    lVar5 = plVar3[2];
  }
  if (lVar5 != 0) {
    android::VectorImpl::clear();
    if ((long *)plVar3[2] != (long *)0x0) {
      (**(code **)(*(long *)plVar3[2] + 8))();
    }
  }
  operator_delete(plVar3);
                    // WARNING: Could not recover jumptable at 0x00010dcc. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(*param_2 + 8))(param_2);
  return;
}


