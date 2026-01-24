typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef pointer pointer __((offset(0xb0)));

typedef pointer pointer __((offset(0x94)));

typedef pointer pointer __((offset(0xc)));

typedef pointer pointer __((offset(0x38)));

typedef pointer pointer __((offset(0x30)));

typedef pointer pointer __((offset(0x60)));

typedef pointer pointer __((offset(0x4c)));

typedef pointer pointer __((offset(0x68)));

typedef pointer pointer __((offset(0xac)));

typedef pointer pointer __((offset(0x6c)));

typedef pointer pointer __((offset(0xa0)));

typedef pointer pointer __((offset(0x9c)));

typedef pointer pointer __((offset(0x98)));

typedef pointer pointer __((offset(0x90)));

typedef pointer pointer __((offset(0x34)));

typedef pointer pointer __((offset(0x40)));

typedef pointer pointer __((offset(0x48)));

typedef pointer pointer __((offset(0x3c)));

typedef pointer pointer __((offset(0x108)));

typedef pointer pointer __((offset(0x58)));

typedef pointer pointer __((offset(0x2c)));

typedef pointer pointer __((offset(0x50)));

typedef pointer pointer __((offset(0x5c)));

typedef pointer pointer __((offset(0x78)));

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef longlong __quad_t;

typedef __quad_t __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE *_chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t *_lock;
    __off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
    int _mode;
    char _unused2[40];
};

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    int _pos;
};

typedef struct ICacao ICacao, *PICacao;

struct ICacao { // PlaceHolder Class Structure
};

typedef struct sp<android::IBinder::DeathRecipient> sp<android::IBinder::DeathRecipient>, *Psp<android::IBinder::DeathRecipient>;

struct sp<android::IBinder::DeathRecipient> { // PlaceHolder Class Structure
};

typedef struct ICacaoService ICacaoService, *PICacaoService;

struct ICacaoService { // PlaceHolder Class Structure
};

typedef struct sp<android::ICacaoService> sp<android::ICacaoService>, *Psp<android::ICacaoService>;

struct sp<android::ICacaoService> { // PlaceHolder Class Structure
};

typedef struct sp<android::IInterface> sp<android::IInterface>, *Psp<android::IInterface>;

struct sp<android::IInterface> { // PlaceHolder Class Structure
};

typedef struct sp<android::IMemoryHeap> sp<android::IMemoryHeap>, *Psp<android::IMemoryHeap>;

struct sp<android::IMemoryHeap> { // PlaceHolder Class Structure
};

typedef struct BpInterface<android::ICacao> BpInterface<android::ICacao>, *PBpInterface<android::ICacao>;

struct BpInterface<android::ICacao> { // PlaceHolder Class Structure
};

typedef struct _IO_FILE FILE;

typedef int __pid_t;

typedef uint __useconds_t;

typedef struct __pthread_internal_slist __pthread_internal_slist, *P__pthread_internal_slist;

struct __pthread_internal_slist {
    struct __pthread_internal_slist *__next;
};

typedef union pthread_mutex_t pthread_mutex_t, *Ppthread_mutex_t;

typedef struct __pthread_mutex_s __pthread_mutex_s, *P__pthread_mutex_s;

typedef union _union_13 _union_13, *P_union_13;

typedef struct __pthread_internal_slist __pthread_slist_t;

union _union_13 {
    int __spins;
    __pthread_slist_t __list;
};

struct __pthread_mutex_s {
    int __lock;
    uint __count;
    int __owner;
    int __kind;
    uint __nusers;
    union _union_13 field5_0x14;
};

union pthread_mutex_t {
    struct __pthread_mutex_s __data;
    char __size[24];
    long __align;
};

typedef union pthread_mutexattr_t pthread_mutexattr_t, *Ppthread_mutexattr_t;

union pthread_mutexattr_t {
    char __size[4];
    int __align;
};

typedef struct __func<cacao::ImageBuf::flushCache()::$_3,std::allocator<cacao::ImageBuf::flushCache()::$_3>,void(android::hardware::graphics::mapper::V2_0::Error,android::hardware::hidl_handle_const&)> __func<cacao::ImageBuf::flushCache()::$_3,std::allocator<cacao::ImageBuf::flushCache()::$_3>,void(android::hardware::graphics::mapper::V2_0::Error,android::hardware::hidl_handle_const&)>, *P__func<cacao::ImageBuf::flushCache()::$_3,std::allocator<cacao::ImageBuf::flushCache()::$_3>,void(android::hardware::graphics::mapper::V2_0::Error,android::hardware::hidl_handle_const&)>;

struct __func<cacao::ImageBuf::flushCache()::$_3,std::allocator<cacao::ImageBuf::flushCache()::$_3>,void(android::hardware::graphics::mapper::V2_0::Error,android::hardware::hidl_handle_const&)> { // PlaceHolder Class Structure
};

typedef struct __func<cacao::ImageBuf::clearCache()::$_2,std::allocator<cacao::ImageBuf::clearCache()::$_2>,void(android::hardware::graphics::mapper::V2_0::Error,void*)> __func<cacao::ImageBuf::clearCache()::$_2,std::allocator<cacao::ImageBuf::clearCache()::$_2>,void(android::hardware::graphics::mapper::V2_0::Error,void*)>, *P__func<cacao::ImageBuf::clearCache()::$_2,std::allocator<cacao::ImageBuf::clearCache()::$_2>,void(android::hardware::graphics::mapper::V2_0::Error,void*)>;

struct __func<cacao::ImageBuf::clearCache()::$_2,std::allocator<cacao::ImageBuf::clearCache()::$_2>,void(android::hardware::graphics::mapper::V2_0::Error,void*)> { // PlaceHolder Class Structure
};

typedef struct __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1,std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1>,void(android::hardware::graphics::mapper::V2_0::Error,unsigned_int,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)> __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1,std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1>,void(android::hardware::graphics::mapper::V2_0::Error,unsigned_int,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)>, *P__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1,std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1>,void(android::hardware::graphics::mapper::V2_0::Error,unsigned_int,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)>;

struct __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1,std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1>,void(android::hardware::graphics::mapper::V2_0::Error,unsigned_int,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)> { // PlaceHolder Class Structure
};

typedef struct __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE<android::hardware::graphics::mapper::V2_0::Error,unsigned_int,android::hardware::hidl_vec<android::hardware::hidl_handle>>(android::hardware::graphics::mapper::V2_0::Error_const&,unsigned_int_const&,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)const::{lambda(auto:2,auto:3)#1},std::allocator<std::allocator>,void(android::hardware::graphics::mapper::V2_0::Error,void*)> __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE<android::hardware::graphics::mapper::V2_0::Error,unsigned_int,android::hardware::hidl_vec<android::hardware::hidl_handle>>(android::hardware::graphics::mapper::V2_0::Error_const&,unsigned_int_const&,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)const::{lambda(auto:2,auto:3)#1},std::allocator<std::allocator>,void(android::hardware::graphics::mapper::V2_0::Error,void*)>, *P__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE<android::hardware::graphics::mapper::V2_0::Error,unsigned_int,android::hardware::hidl_vec<android::hardware::hidl_handle>>(android::hardware::graphics::mapper::V2_0::Error_const&,unsigned_int_const&,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)const::{lambda(auto:2,auto:3)#1},std::allocator<std::allocator>,void(android::hardware::graphics::mapper::V2_0::Error,void*)>;

struct __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE<android::hardware::graphics::mapper::V2_0::Error,unsigned_int,android::hardware::hidl_vec<android::hardware::hidl_handle>>(android::hardware::graphics::mapper::V2_0::Error_const&,unsigned_int_const&,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)const::{lambda(auto:2,auto:3)#1},std::allocator<std::allocator>,void(android::hardware::graphics::mapper::V2_0::Error,void*)> { // PlaceHolder Class Structure
};

typedef struct UnwindCursor<libunwind::LocalAddressSpace,libunwind::Registers_arm> UnwindCursor<libunwind::LocalAddressSpace,libunwind::Registers_arm>, *PUnwindCursor<libunwind::LocalAddressSpace,libunwind::Registers_arm>;

struct UnwindCursor<libunwind::LocalAddressSpace,libunwind::Registers_arm> { // PlaceHolder Class Structure
};

typedef struct Registers_arm Registers_arm, *PRegisters_arm;

struct Registers_arm { // PlaceHolder Class Structure
};

typedef struct dl_phdr_info dl_phdr_info, *Pdl_phdr_info;

struct dl_phdr_info { // PlaceHolder Structure
};

typedef struct _Unwind_Control_Block _Unwind_Control_Block, *P_Unwind_Control_Block;

struct _Unwind_Control_Block { // PlaceHolder Structure
};

typedef struct unw_proc_info_t unw_proc_info_t, *Punw_proc_info_t;

struct unw_proc_info_t { // PlaceHolder Structure
};

typedef struct native_handle native_handle, *Pnative_handle;

struct native_handle { // PlaceHolder Structure
};

typedef struct unw_context_t unw_context_t, *Punw_context_t;

struct unw_context_t { // PlaceHolder Structure
};

typedef struct unw_cursor_t unw_cursor_t, *Punw_cursor_t;

struct unw_cursor_t { // PlaceHolder Structure
};

typedef struct function<void(android::hardware::graphics::mapper::V2_0::Error,void*)> function<void(android::hardware::graphics::mapper::V2_0::Error,void*)>, *Pfunction<void(android::hardware::graphics::mapper::V2_0::Error,void*)>;

struct function<void(android::hardware::graphics::mapper::V2_0::Error,void*)> { // PlaceHolder Structure
};


// WARNING! conflicting data type names: /Demangler/std/string - /string

typedef struct __base __base, *P__base;

struct __base { // PlaceHolder Structure
};

typedef struct __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_0,std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_0>,void(android::hardware::graphics::mapper::V2_0::Error,android::hardware::hidl_vec<unsigned_int>const&)> __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_0,std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_0>,void(android::hardware::graphics::mapper::V2_0::Error,android::hardware::hidl_vec<unsigned_int>const&)>, *P__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_0,std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_0>,void(android::hardware::graphics::mapper::V2_0::Error,android::hardware::hidl_vec<unsigned_int>const&)>;

struct __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_0,std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_0>,void(android::hardware::graphics::mapper::V2_0::Error,android::hardware::hidl_vec<unsigned_int>const&)> { // PlaceHolder Structure
};

typedef struct __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error_const&,unsigned_int_const&,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)const::{lambda(auto:2,auto:3)#1},std::allocator<std::allocator>,void(android::hardware::graphics::mapper::V2_0::Error,void*)> __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error_const&,unsigned_int_const&,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)const::{lambda(auto:2,auto:3)#1},std::allocator<std::allocator>,void(android::hardware::graphics::mapper::V2_0::Error,void*)>, *P__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error_const&,unsigned_int_const&,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)const::{lambda(auto:2,auto:3)#1},std::allocator<std::allocator>,void(android::hardware::graphics::mapper::V2_0::Error,void*)>;

struct __func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,unsigned_int,cacao::ImageFormat,cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error_const&,unsigned_int_const&,android::hardware::hidl_vec<android::hardware::hidl_handle>const&)const::{lambda(auto:2,auto:3)#1},std::allocator<std::allocator>,void(android::hardware::graphics::mapper::V2_0::Error,void*)> { // PlaceHolder Structure
};

typedef undefined DataSpace;

typedef undefined ImageSize;

typedef struct ICBProcessEventListener ICBProcessEventListener, *PICBProcessEventListener;

struct ICBProcessEventListener { // PlaceHolder Structure
};

typedef struct SharedBuffer SharedBuffer, *PSharedBuffer;

struct SharedBuffer { // PlaceHolder Structure
};

typedef undefined ImageFormat;

typedef struct ProcessConfigBase ProcessConfigBase, *PProcessConfigBase;

struct ProcessConfigBase { // PlaceHolder Structure
};

typedef struct ICBProcessResultListener ICBProcessResultListener, *PICBProcessResultListener;

struct ICBProcessResultListener { // PlaceHolder Structure
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

typedef struct ProcessModeBase ProcessModeBase, *PProcessModeBase;

struct ProcessModeBase { // PlaceHolder Structure
};

typedef struct ObjectBase ObjectBase, *PObjectBase;

struct ObjectBase { // PlaceHolder Structure
};

typedef struct ProcessParamBase ProcessParamBase, *PProcessParamBase;

struct ProcessParamBase { // PlaceHolder Structure
};

typedef struct CameraIndex CameraIndex, *PCameraIndex;

struct CameraIndex { // PlaceHolder Structure
};

typedef undefined SerializedData;

typedef struct BnInterface<android::ICacaoClient> BnInterface<android::ICacaoClient>, *PBnInterface<android::ICacaoClient>;

struct BnInterface<android::ICacaoClient> { // PlaceHolder Structure
};

typedef struct sp<android::Cacao::DeathNotifier> sp<android::Cacao::DeathNotifier>, *Psp<android::Cacao::DeathNotifier>;

struct sp<android::Cacao::DeathNotifier> { // PlaceHolder Structure
};

typedef struct BpCacaoService BpCacaoService, *PBpCacaoService;

struct BpCacaoService { // PlaceHolder Structure
};

typedef struct sp<android::IMemory> sp<android::IMemory>, *Psp<android::IMemory>;

struct sp<android::IMemory> { // PlaceHolder Structure
};

typedef struct IBinder IBinder, *PIBinder;

struct IBinder { // PlaceHolder Structure
};

typedef struct sp sp, *Psp;

struct sp { // PlaceHolder Structure
};

typedef struct BnCacaoService BnCacaoService, *PBnCacaoService;

struct BnCacaoService { // PlaceHolder Structure
};

typedef struct Vector Vector, *PVector;

struct Vector { // PlaceHolder Structure
};

typedef struct MemoryHeapBase MemoryHeapBase, *PMemoryHeapBase;

struct MemoryHeapBase { // PlaceHolder Structure
};

typedef struct Parcel Parcel, *PParcel;

struct Parcel { // PlaceHolder Structure
};

typedef struct BnInterface<android::ICacaoProcessCallback> BnInterface<android::ICacaoProcessCallback>, *PBnInterface<android::ICacaoProcessCallback>;

struct BnInterface<android::ICacaoProcessCallback> { // PlaceHolder Structure
};

typedef struct Mutex Mutex, *PMutex;

struct Mutex { // PlaceHolder Structure
};

typedef struct VectorImpl VectorImpl, *PVectorImpl;

struct VectorImpl { // PlaceHolder Structure
};

typedef struct RefBase RefBase, *PRefBase;

struct RefBase { // PlaceHolder Structure
};

typedef struct Vector<cacao::ImageBuf*> Vector<cacao::ImageBuf*>, *PVector<cacao::ImageBuf*>;

struct Vector<cacao::ImageBuf*> { // PlaceHolder Structure
};

typedef struct ICacaoClient ICacaoClient, *PICacaoClient;

struct ICacaoClient { // PlaceHolder Structure
};

typedef struct BpCacaoClient BpCacaoClient, *PBpCacaoClient;

struct BpCacaoClient { // PlaceHolder Structure
};

typedef struct BpCacao BpCacao, *PBpCacao;

struct BpCacao { // PlaceHolder Structure
};

typedef struct BnCacao BnCacao, *PBnCacao;

struct BnCacao { // PlaceHolder Structure
};

typedef struct BpRefBase BpRefBase, *PBpRefBase;

struct BpRefBase { // PlaceHolder Structure
};

typedef struct Cacao Cacao, *PCacao;

struct Cacao { // PlaceHolder Structure
};

typedef struct String16 String16, *PString16;

struct String16 { // PlaceHolder Structure
};

typedef struct ICacaoProcessCallback ICacaoProcessCallback, *PICacaoProcessCallback;

struct ICacaoProcessCallback { // PlaceHolder Structure
};

typedef struct BBinder BBinder, *PBBinder;

struct BBinder { // PlaceHolder Structure
};

typedef struct BnInterface<android::ICacaoService> BnInterface<android::ICacaoService>, *PBnInterface<android::ICacaoService>;

struct BnInterface<android::ICacaoService> { // PlaceHolder Structure
};

typedef struct MemoryBase MemoryBase, *PMemoryBase;

struct MemoryBase { // PlaceHolder Structure
};

typedef struct BnCacaoClient BnCacaoClient, *PBnCacaoClient;

struct BnCacaoClient { // PlaceHolder Structure
};

typedef struct wp wp, *Pwp;

struct wp { // PlaceHolder Structure
};

typedef struct BpCacaoProcessCallback BpCacaoProcessCallback, *PBpCacaoProcessCallback;

struct BpCacaoProcessCallback { // PlaceHolder Structure
};

typedef struct sp<android::ICacaoProcessCallback> sp<android::ICacaoProcessCallback>, *Psp<android::ICacaoProcessCallback>;

struct sp<android::ICacaoProcessCallback> { // PlaceHolder Structure
};

typedef struct BnCacaoProcessCallback BnCacaoProcessCallback, *PBnCacaoProcessCallback;

struct BnCacaoProcessCallback { // PlaceHolder Structure
};

typedef struct IInterface IInterface, *PIInterface;

struct IInterface { // PlaceHolder Structure
};

typedef struct BnInterface<android::ICacao> BnInterface<android::ICacao>, *PBnInterface<android::ICacao>;

struct BnInterface<android::ICacao> { // PlaceHolder Structure
};

typedef struct wp<android::IBinder::DeathRecipient> wp<android::IBinder::DeathRecipient>, *Pwp<android::IBinder::DeathRecipient>;

struct wp<android::IBinder::DeathRecipient> { // PlaceHolder Structure
};

typedef struct DeathRecipient DeathRecipient, *PDeathRecipient;

struct DeathRecipient { // PlaceHolder Structure
};

typedef struct DeathNotifier DeathNotifier, *PDeathNotifier;

struct DeathNotifier { // PlaceHolder Structure
};

typedef struct CacaoClient CacaoClient, *PCacaoClient;

struct CacaoClient { // PlaceHolder Structure
};

typedef struct CacaoProcessCallback CacaoProcessCallback, *PCacaoProcessCallback;

struct CacaoProcessCallback { // PlaceHolder Structure
};

typedef struct hidl_vec hidl_vec, *Phidl_vec;

struct hidl_vec { // PlaceHolder Structure
};

typedef struct hidl_handle hidl_handle, *Phidl_handle;

struct hidl_handle { // PlaceHolder Structure
};

typedef struct hidl_vec<unsigned_int> hidl_vec<unsigned_int>, *Phidl_vec<unsigned_int>;

struct hidl_vec<unsigned_int> { // PlaceHolder Structure
};

typedef struct return_status return_status, *Preturn_status;

struct return_status { // PlaceHolder Structure
};

typedef struct Error Error, *PError;

struct Error { // PlaceHolder Structure
};

typedef struct UnwindInfoSections UnwindInfoSections, *PUnwindInfoSections;

struct UnwindInfoSections { // PlaceHolder Structure
};

typedef struct AbstractUnwindCursor AbstractUnwindCursor, *PAbstractUnwindCursor;

struct AbstractUnwindCursor { // PlaceHolder Structure
};

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

typedef enum Elf_SectionHeaderType_ARM {
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
    SHT_ARM_EXIDX=1879048193,
    SHT_ARM_PREEMPTMAP=1879048194,
    SHT_ARM_ATTRIBUTES=1879048195,
    SHT_ARM_DEBUGOVERLAY=1879048196,
    SHT_ARM_OVERLAYSECTION=1879048197
} Elf_SectionHeaderType_ARM;

struct Elf32_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_ARM sh_type;
    dword sh_flags;
    dword sh_addr;
    dword sh_offset;
    dword sh_size;
    dword sh_link;
    dword sh_info;
    dword sh_addralign;
    dword sh_entsize;
};

typedef enum Elf32_DynTag_ARM {
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
} Elf32_DynTag_ARM;

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
};

typedef struct Elf32_Phdr Elf32_Phdr, *PElf32_Phdr;

typedef enum Elf_ProgramHeaderType_ARM {
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
    PT_ARM_EXIDX=1879048192
} Elf_ProgramHeaderType_ARM;

struct Elf32_Phdr {
    enum Elf_ProgramHeaderType_ARM p_type;
    dword p_offset;
    dword p_vaddr;
    dword p_paddr;
    dword p_filesz;
    dword p_memsz;
    dword p_flags;
    dword p_align;
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[16];
};

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

typedef struct Elf32_Dyn_ARM Elf32_Dyn_ARM, *PElf32_Dyn_ARM;

struct Elf32_Dyn_ARM {
    enum Elf32_DynTag_ARM d_tag;
    dword d_val;
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
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
    dword e_entry;
    dword e_phoff;
    dword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

typedef struct ElfNote_8_4 ElfNote_8_4, *PElfNote_8_4;

struct ElfNote_8_4 {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[8]; // Vendor name
    byte description[4]; // Blob value
};



undefined4 descriptor;
pointer __((offset(0xc))) VTT;
undefined4 mServiceLock;
undefined4 mService;
undefined4 mDeathNotifier;
undefined4 __stack_chk_guard;
undefined4 mServicePid;
pointer PTR_~Cacao_00017fe4;
undefined4 mMapper;
undefined DAT_000187f4;
undefined DAT_00018818;
undefined ~String16;
undefined DAT_00019000;
undefined ~sp;
undefined4 mAllocator;
pointer __((offset(0xc))) PTR_construction-vtable[12]_000167e8;
pointer __((offset(0xc))) PTR_construction-vtable[12]_00016e30;
pointer __((offset(0xc))) PTR_construction-vtable[12]_0001746c;
pointer __((offset(0xc))) PTR_construction-vtable[12]_00017b38;
pointer PTR_~Vector+1_00017cfc;
pointer __((offset(0xc))) PTR_construction-vtable[12]_00017dd8;
pointer PTR_~AbstractUnwindCursor+1_000186f4;
pointer __((offset(0xc))) PTR_construction-vtable[12]_00017f3c;
pointer PTR_~AbstractUnwindCursor_00018728;
pointer PTR_~ImageBuf_00018740;
undefined DAT_00018788;
undefined DAT_000187ac;
undefined DAT_000187d0;
undefined DAT_0001883c;
undefined DAT_0001902c;
undefined DAT_00014ec2;

void __cxa_atexit(void)

{
  __cxa_atexit();
  return;
}



void __register_atfork(void)

{
  __register_atfork();
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::incStrong(void *param_1)

{
  incStrong(param_1);
  return;
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



void __thiscall android::RefBase::RefBase(RefBase *this)

{
  RefBase(this);
  return;
}



void __thiscall android::IInterface::IInterface(IInterface *this)

{
  IInterface(this);
  return;
}



void __thiscall android::BpRefBase::BpRefBase(BpRefBase *this,sp *param_1)

{
  BpRefBase(this,param_1);
  return;
}



void __thiscall android::IInterface::~IInterface(IInterface *this)

{
  ~IInterface(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::checkInterface(IBinder *param_1)

{
  checkInterface(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readStrongBinder(void)

{
  readStrongBinder();
  return;
}



void __thiscall android::ICacaoClient::asInterface(ICacaoClient *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IInterface::asBinder(sp *param_1)

{
  asBinder(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeStrongBinder(sp *param_1)

{
  writeStrongBinder(param_1);
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::onTransact(uint param_1,Parcel *param_2,Parcel *param_3,uint param_4)

{
  onTransact(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readInt32(void)

{
  readInt32();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IMemory::asInterface(sp *param_1)

{
  asInterface(param_1);
  return;
}



void __aeabi_memclr4(void)

{
  __aeabi_memclr4();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readFileDescriptor(void)

{
  readFileDescriptor();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IMemory::size(void)

{
  size();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IMemory::pointer(void)

{
  pointer();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeInt32(int param_1)

{
  writeInt32(param_1);
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl
android::BnCacaoService::onTransact(int *param_1,Parcel *param_2,IBinder *param_3,sp *param_4)

{
  onTransact(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::String16::size(void)

{
  size();
  return;
}



void strzcmp16(void)

{
  strzcmp16();
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __thiscall android::BpRefBase::~BpRefBase(BpRefBase *this)

{
  ~BpRefBase(this);
  return;
}



void __thiscall android::RefBase::~RefBase(RefBase *this)

{
  ~RefBase(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void operator_delete(void *param_1)

{
  operator_delete(param_1);
  return;
}



void __thiscall android::Parcel::Parcel(Parcel *this)

{
  Parcel(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeInterfaceToken(String16 *param_1)

{
  writeInterfaceToken(param_1);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __thiscall android::ICacao::asInterface(ICacao *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



void __thiscall android::Parcel::~Parcel(Parcel *this)

{
  ~Parcel(this);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeFileDescriptor(int param_1,bool param_2)

{
  writeFileDescriptor(param_1,param_2);
  return;
}



void __thiscall android::String16::String16(String16 *this,char *param_1)

{
  String16(this,param_1);
  return;
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __cxa_pure_virtual(void)

{
  __cxa_pure_virtual();
  return;
}



undefined4 * __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  return &ICacaoService::descriptor;
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::onFirstRef(void)

{
  onFirstRef();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::onLastStrongRef(void *param_1)

{
  onLastStrongRef(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::onIncStrongAttempted(uint param_1,void *param_2)

{
  onIncStrongAttempted(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::onLastWeakRef(void *param_1)

{
  onLastWeakRef(param_1);
  return;
}



void __thiscall android::IInterface::~IInterface(IInterface *this)

{
  ~IInterface(this);
  return;
}



void __thiscall android::IInterface::~IInterface(IInterface *this)

{
  ~IInterface(this);
  return;
}



void android::IInterface::~IInterface(void)

{
  ~IInterface();
  return;
}



void android::IInterface::~IInterface(void)

{
  ~IInterface();
  return;
}



BnInterface<> * __thiscall android::BnInterface<>::onAsBinder(BnInterface<> *this)

{
  return this + 4;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::isBinderAlive(void)

{
  isBinderAlive();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::pingBinder(void)

{
  pingBinder();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::dump(int param_1,Vector *param_2)

{
  dump(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::transact(uint param_1,Parcel *param_2,Parcel *param_3,uint param_4)

{
  transact(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::linkToDeath(sp *param_1,void *param_2,uint param_3)

{
  linkToDeath(param_1,param_2,param_3);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::unlinkToDeath(wp *param_1,void *param_2,uint param_3,wp *param_4)

{
  unlinkToDeath(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IBinder::checkSubclass(void *param_1)

{
  checkSubclass(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::attachObject
               (void *param_1,void *param_2,void *param_3,
               _func_void_void_ptr_void_ptr_void_ptr *param_4)

{
  attachObject(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::findObject(void *param_1)

{
  findObject(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::detachObject(void *param_1)

{
  detachObject(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::localBinder(void)

{
  localBinder();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IBinder::remoteBinder(void)

{
  remoteBinder();
  return;
}



void __thiscall android::BnCacaoService::onTransact(BnCacaoService *this)

{
  Parcel *in_r1;
  IBinder *in_r2;
  sp *in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IBinder::queryLocalInterface(String16 *param_1)

{
  queryLocalInterface(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::getInterfaceDescriptor(void)

{
  getInterfaceDescriptor();
  return;
}



void __thiscall android::BBinder::~BBinder(BBinder *this)

{
  ~BBinder(this);
  return;
}



void __thiscall android::BBinder::~BBinder(BBinder *this)

{
  ~BBinder(this);
  return;
}



void android::BBinder::~BBinder(void)

{
  ~BBinder();
  return;
}



void android::BBinder::~BBinder(void)

{
  ~BBinder();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IBinder::localBinder(void)

{
  localBinder();
  return;
}



void __thiscall android::IBinder::~IBinder(IBinder *this)

{
  ~IBinder(this);
  return;
}



void __thiscall android::IBinder::~IBinder(IBinder *this)

{
  ~IBinder(this);
  return;
}



void android::IBinder::~IBinder(void)

{
  ~IBinder();
  return;
}



void android::IBinder::~IBinder(void)

{
  ~IBinder();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BpRefBase::onFirstRef(void)

{
  onFirstRef();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BpRefBase::onLastStrongRef(void *param_1)

{
  onLastStrongRef(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BpRefBase::onIncStrongAttempted(uint param_1,void *param_2)

{
  onIncStrongAttempted(param_1,param_2);
  return;
}



void android::BpRefBase::onFirstRef(void)

{
  onFirstRef();
  return;
}



void android::BpRefBase::onLastStrongRef(void)

{
  onLastStrongRef();
  return;
}



void android::BpRefBase::onIncStrongAttempted(void)

{
  onIncStrongAttempted();
  return;
}



void __thiscall android::BpRefBase::~BpRefBase(BpRefBase *this)

{
  ~BpRefBase(this);
  return;
}



void __thiscall android::BpRefBase::~BpRefBase(BpRefBase *this)

{
  ~BpRefBase(this);
  return;
}



void android::BpRefBase::~BpRefBase(void)

{
  ~BpRefBase();
  return;
}



void android::BpRefBase::~BpRefBase(void)

{
  ~BpRefBase();
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

undefined4 __cdecl
android::BnCacaoProcessCallback::onTransact
          (int *param_1,Parcel *param_2,IBinder *param_3,uint param_4)

{
  undefined4 uVar1;
  
  uVar1 = onTransact(param_1,param_2,param_3,param_4);
  return uVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void native_handle_close(void)

{
  native_handle_close();
  return;
}



void native_handle_delete(void)

{
  native_handle_delete();
  return;
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



undefined4 * __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  return &ICacaoProcessCallback::descriptor;
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



BnInterface<> * __thiscall android::BnInterface<>::onAsBinder(BnInterface<> *this)

{
  return this + 4;
}



void __thiscall android::BnCacaoProcessCallback::onTransact(BnCacaoProcessCallback *this)

{
  Parcel *in_r1;
  IBinder *in_r2;
  uint in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl
android::BnCacaoClient::onTransact(int *param_1,Parcel *param_2,IBinder *param_3,uint param_4)

{
  onTransact(param_1,param_2,param_3,param_4);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



undefined4 * __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  return &ICacaoClient::descriptor;
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



BnInterface<> * __thiscall android::BnInterface<>::onAsBinder(BnInterface<> *this)

{
  return this + 4;
}



void __thiscall android::BnCacaoClient::onTransact(BnCacaoClient *this)

{
  Parcel *in_r1;
  IBinder *in_r2;
  uint in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __thiscall android::VectorImpl::VectorImpl(VectorImpl *this,uint param_1,uint param_2)

{
  VectorImpl(this,param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readUint32(void)

{
  readUint32();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readNativeHandle(void)

{
  readNativeHandle();
  return;
}



void * __thiscall cacao::ObjectBase::operator_new(ObjectBase *this)

{
  void *pvVar1;
  
  pvVar1 = operator_new(this);
  return pvVar1;
}



ImageBuf * __thiscall
cacao::ImageBuf::ImageBuf
          (ImageBuf *this,undefined4 param_1,int param_2,uint param_3,undefined4 param_4,int param_5
          )

{
  ImageBuf *pIVar1;
  
  pIVar1 = ImageBuf(this,param_1,param_2,param_3,param_4,param_5);
  return pIVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::insertAt(void *param_1,uint param_2,uint param_3)

{
  insertAt(param_1,param_2,param_3);
  return;
}



void __thiscall
android::ICacaoProcessCallback::asInterface(ICacaoProcessCallback *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



void __thiscall android::VectorImpl::VectorImpl(VectorImpl *this,VectorImpl *param_1)

{
  VectorImpl(this,param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::finish_vector(void)

{
  finish_vector();
  return;
}



void __thiscall android::VectorImpl::~VectorImpl(VectorImpl *this)

{
  ~VectorImpl(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::write(void *param_1,uint param_2)

{
  write(param_1,param_2);
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readIntPtr(void)

{
  readIntPtr();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

undefined4 __cdecl
android::BnCacao::onTransact(int *param_1,Parcel *param_2,IBinder *param_3,ImageBuf **param_4)

{
  undefined4 uVar1;
  
  uVar1 = onTransact(param_1,param_2,param_3,param_4);
  return uVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeUint32(uint param_1)

{
  writeUint32(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeNativeHandle(native_handle *param_1)

{
  writeNativeHandle(param_1);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __aeabi_memcpy(void)

{
  __aeabi_memcpy();
  return;
}



void __aeabi_memmove(void)

{
  __aeabi_memmove();
  return;
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



undefined4 * __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  return &ICacao::descriptor;
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



BnInterface<> * __thiscall android::BnInterface<>::onAsBinder(BnInterface<> *this)

{
  return this + 4;
}



void __thiscall android::BnCacao::onTransact(BnCacao *this)

{
  Parcel *in_r1;
  IBinder *in_r2;
  ImageBuf **in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  return;
}



void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  return;
}



void __thiscall
android::Vector<>::do_copy(undefined4 param_1_00,undefined4 param_2,undefined4 param_3,int param_4)

{
  __aeabi_memcpy(param_2,param_3,param_4 << 2);
  return;
}



void __thiscall
android::Vector<>::do_splat
          (undefined4 param_1_00,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  for (; param_4 != 0; param_4 = param_4 + -1) {
    *param_2 = *param_3;
    param_2 = param_2 + 1;
  }
  return;
}



void __thiscall
android::Vector<>::do_move_backward
          (undefined4 param_1_00,undefined4 param_2,undefined4 param_3,int param_4)

{
  __aeabi_memmove(param_2,param_3,param_4 << 2);
  return;
}



void __thiscall
android::Vector<>::do_move_backward
          (undefined4 param_1_00,undefined4 param_2,undefined4 param_3,int param_4)

{
  __aeabi_memmove(param_2,param_3,param_4 << 2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_destroy(__mutex);
  return iVar1;
}



void __thiscall android::ICacaoClient::ICacaoClient(ICacaoClient *this,int *param_1)

{
  ICacaoClient(this,param_1);
  return;
}



void __thiscall android::BBinder::BBinder(BBinder *this)

{
  BBinder(this);
  return;
}



void __thiscall android::BBinder::~BBinder(BBinder *this)

{
  ~BBinder(this);
  return;
}



void __thiscall android::ICacaoProcessCallback::~ICacaoProcessCallback(ICacaoProcessCallback *this)

{
  ~ICacaoProcessCallback(this);
  return;
}



void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this,int *param_1)

{
  ~CacaoProcessCallback(this,param_1);
  return;
}



void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this);
  return;
}



void __thiscall android::ICacaoClient::ICacaoClient(ICacaoClient *this,int *param_1)

{
  ICacaoClient(this,param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
  int iVar1;
  
  iVar1 = pthread_mutex_init(__mutex,__mutexattr);
  return iVar1;
}



void __thiscall android::ICacaoProcessCallback::~ICacaoProcessCallback(ICacaoProcessCallback *this)

{
  ~ICacaoProcessCallback(this);
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this,int *param_1)

{
  ~CacaoClient(this,param_1);
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock(__mutex);
  return iVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_unlock(__mutex);
  return iVar1;
}



wp<> * __thiscall android::wp<>::wp<>(wp<> *this,int *param_1)

{
  wp<> *pwVar1;
  
  pwVar1 = wp<>(this,param_1);
  return pwVar1;
}



wp<> * __thiscall android::wp<>::~wp(wp<> *this)

{
  wp<> *pwVar1;
  
  pwVar1 = ~wp(this);
  return pwVar1;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::createWeak(void *param_1)

{
  createWeak(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::weakref_type::decWeak(void *param_1)

{
  decWeak(param_1);
  return;
}



undefined4 cacao::ProcessFactory::createEvent(void)

{
  undefined4 uVar1;
  
  uVar1 = createEvent();
  return uVar1;
}



void __android_log_print(void)

{
  __android_log_print();
  return;
}



void __aeabi_memclr8(void)

{
  __aeabi_memclr8();
  return;
}



void __thiscall android::Cacao::CacaoClient::allocMemory(CacaoClient *this,uint param_1)

{
  allocMemory(this,param_1);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::CacaoClient::makeSerializedData(int *param_1,int param_2)

{
  makeSerializedData(param_1,param_2);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void __thiscall
android::MemoryHeapBase::MemoryHeapBase
          (MemoryHeapBase *this,uint param_1,uint param_2,char *param_3)

{
  MemoryHeapBase(this,param_1,param_2,param_3);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __thiscall
android::MemoryBase::MemoryBase(MemoryBase *this,sp *param_1,int param_2,uint param_3)

{
  MemoryBase(this,param_1,param_2,param_3);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



int __thiscall android::Cacao::CacaoClient::start(CacaoClient *this,int *param_1)

{
  int iVar1;
  
  iVar1 = start(this,param_1);
  return iVar1;
}



int __thiscall android::Cacao::CacaoClient::stop(CacaoClient *this)

{
  int iVar1;
  
  iVar1 = stop(this);
  return iVar1;
}



CacaoProcessCallback * __thiscall
android::Cacao::CacaoProcessCallback::CacaoProcessCallback
          (CacaoProcessCallback *this,undefined4 param_1,undefined4 param_2)

{
  CacaoProcessCallback *pCVar1;
  
  pCVar1 = CacaoProcessCallback(this,param_1,param_2);
  return pCVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __aeabi_memcpy8(void)

{
  __aeabi_memcpy8();
  return;
}



int __thiscall
android::Cacao::CacaoClient::process(CacaoClient *this,int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = process(this,param_1,param_2,param_3);
  return iVar1;
}



int __thiscall
android::Cacao::CacaoClient::processAsync
          (CacaoClient *this,int *param_1,int param_2,undefined *param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = processAsync(this,param_1,param_2,param_3,param_4);
  return iVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



wp<> * __thiscall android::wp<>::wp<>(wp<> *this,int *param_1)

{
  wp<> *pwVar1;
  
  pwVar1 = wp<>(this,param_1);
  return pwVar1;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void android::Cacao::getService(void)

{
  getService();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ProcessState::self(void)

{
  self();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ProcessState::startThreadPool(void)

{
  startThreadPool();
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = getpid();
  return _Var1;
}



uint __thiscall android::Cacao::connect(Cacao *this)

{
  uint uVar1;
  
  uVar1 = connect(this);
  return uVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::defaultServiceManager(void)

{
  defaultServiceManager();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int usleep(__useconds_t __useconds)

{
  int iVar1;
  
  iVar1 = usleep(__useconds);
  return iVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __thiscall android::String16::~String16(String16 *this)

{
  ~String16(this);
  return;
}



void __thiscall android::ICacaoService::asInterface(ICacaoService *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



CacaoClient * __thiscall android::Cacao::CacaoClient::CacaoClient(CacaoClient *this)

{
  CacaoClient *pCVar1;
  
  pCVar1 = CacaoClient(this);
  return pCVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



undefined4 __thiscall android::Cacao::CacaoClient::connect(CacaoClient *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = connect(this,param_1);
  return uVar1;
}



void __thiscall android::Cacao::disconnect(Cacao *this)

{
  disconnect(this);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



void __thiscall android::Cacao::CacaoClient::disconnect(CacaoClient *this)

{
  disconnect(this);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



CacaoProcessCallback * __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x18));
  return this;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl
android::Cacao::CacaoProcessCallback::notifyProgress
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar2 = *(int **)(param_1 + 0x10);
  piVar1 = *(int **)(param_1 + 0x14);
  uStack_8 = param_3;
  uStack_4 = param_4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x2c))(piVar1,&uStack_8);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,*(undefined4 *)(param_1 + 0x14));
  }
  return;
}



void __thiscall
android::Cacao::CacaoProcessCallback::notifyResult
          (CacaoProcessCallback *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar2 = *(int **)(this + 0x10);
  piVar1 = *(int **)(this + 0x14);
  uStack_8 = param_2;
  uStack_4 = param_3;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x2c))(piVar1,&uStack_8);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,*(undefined4 *)(this + 0x14));
  }
  return;
}



void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this + -4,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  return;
}



void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this + -4);
  return;
}



void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  int iVar1;
  
  iVar1 = ~CacaoProcessCallback(this + *(int *)(*(int *)this + -0xc),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x18));
  return;
}



void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this + *(int *)(*(int *)this + -0xc));
  return;
}



CacaoClient * __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x28));
  return this;
}



void __thiscall android::Cacao::CacaoClient::notifyEvent(CacaoClient *this)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(this + 0x20);
  if (piVar2 != (int *)0x0) {
    piVar1 = (int *)cacao::ProcessFactory::createEvent();
    if (piVar1 == (int *)0x0) {
      __android_log_print(6,"CacaoClient","could not call the callback");
    }
    else {
      (**(code **)(*piVar1 + 0x18))(piVar1,*(undefined4 *)(this + 0x24));
      (**(code **)(*piVar2 + 8))(piVar2,piVar1);
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return;
}



void __thiscall android::Cacao::CacaoClient::binderDied(void)

{
  __android_log_print(5,"CacaoClient","client binder died");
  return;
}



undefined4 __thiscall
android::Cacao::CacaoClient::subscribeEvents
          (CacaoClient *this,undefined4 param_1,undefined4 param_2)

{
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  *(undefined4 *)(this + 0x20) = param_1;
  *(undefined4 *)(this + 0x24) = param_2;
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  return 0;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -4,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x24));
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -4);
  return;
}



void __thiscall android::Cacao::CacaoClient::binderDied(void)

{
  __android_log_print(5,"CacaoClient","client binder died");
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -0x10,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x18));
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -0x10);
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -0x14,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -0x14);
  return;
}



undefined4 __thiscall
android::Cacao::CacaoClient::subscribeEvents
          (CacaoClient *this,undefined4 param_1,undefined4 param_2)

{
  pthread_mutex_lock((pthread_mutex_t *)(this + 8));
  *(undefined4 *)(this + 0xc) = param_1;
  *(undefined4 *)(this + 0x10) = param_2;
  pthread_mutex_unlock((pthread_mutex_t *)(this + 8));
  return 0;
}



void __thiscall android::Cacao::CacaoClient::start(CacaoClient *this)

{
  int *in_r1;
  
  start(this + -0x14,in_r1);
  return;
}



void __thiscall android::Cacao::CacaoClient::stop(CacaoClient *this)

{
  stop(this + -0x14);
  return;
}



void __thiscall android::Cacao::CacaoClient::setConfig(CacaoClient *this)

{
  int *in_r1;
  
  setConfig(this + -0x14,in_r1);
  return;
}



void __thiscall android::Cacao::CacaoClient::getConfig(CacaoClient *this)

{
  int *in_r1;
  
  getConfig(this + -0x14,in_r1);
  return;
}



void __thiscall android::Cacao::CacaoClient::process(CacaoClient *this)

{
  int *in_r1;
  undefined4 in_r2;
  int *in_r3;
  
  process(this + -0x14,in_r1,in_r2,in_r3);
  return;
}



void __thiscall android::Cacao::CacaoClient::processAsync(CacaoClient *this)

{
  int *in_r1;
  int in_r2;
  undefined *in_r3;
  int *in_stack_00000000;
  
  processAsync(this + -0x14,in_r1,in_r2,in_r3,in_stack_00000000);
  return;
}



void __thiscall android::Cacao::CacaoClient::processAsyncWithBinder(CacaoClient *this)

{
  int *in_r1;
  undefined4 in_r2;
  int in_r3;
  int *in_stack_00000000;
  
  processAsyncWithBinder(this + -0x14,in_r1,in_r2,in_r3,in_stack_00000000);
  return;
}



void __thiscall android::Cacao::CacaoClient::cancel(CacaoClient *this)

{
  undefined4 in_r1;
  
  cancel(this + -0x14,in_r1);
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  int iVar1;
  
  iVar1 = ~CacaoClient(this + *(int *)(*(int *)this + -0xc),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x28));
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + *(int *)(*(int *)this + -0xc));
  return;
}



void android::Cacao::DeathNotifier::binderDied(void)

{
  code *pcVar1;
  wp<> awStack_38 [8];
  sp<> asStack_30 [4];
  int *piStack_2c;
  int iStack_28;
  
  iStack_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)&mServiceLock);
  if (mService != 0) {
    sp<>::sp<>(asStack_30,&mService);
    android::IInterface::asBinder((sp *)&piStack_2c);
    pcVar1 = *(code **)(*piStack_2c + 0x1c);
    wp<>::wp<>(awStack_38,&mDeathNotifier);
    (*pcVar1)(piStack_2c,awStack_38,0,0,0);
    wp<>::~wp(awStack_38);
    sp<>::~sp((sp<> *)&piStack_2c);
    sp<>::~sp((sp<> *)asStack_30);
    sp<>::clear((sp<> *)&mDeathNotifier);
  }
  sp<>::clear((sp<> *)&mService);
  mServicePid = 0;
  __android_log_print(5,"CacaoClient","service died");
  pthread_mutex_unlock((pthread_mutex_t *)&mServiceLock);
  if (__stack_chk_guard != iStack_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



DeathNotifier * __thiscall android::Cacao::DeathNotifier::~DeathNotifier(DeathNotifier *this)

{
  *(undefined4 *)this = 0x17f8c;
  *(undefined4 *)(this + 4) = 0x17fb4;
  android::RefBase::~RefBase((RefBase *)(this + 4));
  return this;
}



void __thiscall android::Cacao::DeathNotifier::~DeathNotifier(DeathNotifier *this)

{
  *(undefined4 *)this = 0x17f8c;
  *(undefined4 *)(this + 4) = 0x17fb4;
  android::RefBase::~RefBase((RefBase *)(this + 4));
  operator_delete(this);
  return;
}



void __thiscall android::Cacao::DeathNotifier::~DeathNotifier(DeathNotifier *this)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)this + -0xc);
  *(undefined4 *)(this + iVar1) = 0x17f8c;
  *(undefined4 *)(this + iVar1 + 4) = 0x17fb4;
  android::RefBase::~RefBase((RefBase *)(this + iVar1 + 4));
  return;
}



void __thiscall android::Cacao::DeathNotifier::~DeathNotifier(DeathNotifier *this)

{
  DeathNotifier *pDVar1;
  
  pDVar1 = this + *(int *)(*(int *)this + -0xc);
  *(undefined4 *)(this + *(int *)(*(int *)this + -0xc)) = 0x17f8c;
  *(undefined4 *)(pDVar1 + 4) = 0x17fb4;
  android::RefBase::~RefBase((RefBase *)(pDVar1 + 4));
  operator_delete(pDVar1);
  return;
}



Cacao * __thiscall android::Cacao::~Cacao(Cacao *this)

{
  *(undefined ***)this = &PTR__Cacao_00017fe4;
  disconnect(this);
  sp<>::~sp((sp<> *)(this + 4));
  return this;
}



void __thiscall android::Cacao::~Cacao(Cacao *this)

{
  *(undefined ***)this = &PTR__Cacao_00017fe4;
  disconnect(this);
  sp<>::~sp((sp<> *)(this + 4));
  operator_delete(this);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::subscribeEvents(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010ba2. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x20))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::start(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010baa. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x24))();
  return;
}



void __thiscall android::Cacao::stop(Cacao *this)

{
                    // WARNING: Could not recover jumptable at 0x00010bb2. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(this + 4) + 0x28))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::setConfig(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bba. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x2c))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::getConfig(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bc2. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x30))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::process(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bce. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x34))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::processAsync(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bda. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x38))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::processAsyncWithBinder(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010be6. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x3c))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::cancel(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bee. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x40))();
  return;
}



void PAL_MemAllocEx(void)

{
  PAL_MemAllocEx();
  return;
}



void PAL_MemFreeEx(void)

{
  PAL_MemFreeEx();
  return;
}



void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  ~AbstractUnwindCursor();
  return;
}



void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  return;
}



void __thiscall cacao::SharedBuffer::incRefCnt(SharedBuffer *this)

{
  incRefCnt(this);
  return;
}



int __thiscall cacao::SharedBuffer::decRefCnt(SharedBuffer *this)

{
  int iVar1;
  
  iVar1 = decRefCnt(this);
  return iVar1;
}



void __thiscall cacao::ObjectBase::ObjectBase(ObjectBase *this)

{
  ObjectBase(this);
  return;
}



SharedBuffer * cacao::SharedBuffer::create(void)

{
  SharedBuffer *pSVar1;
  
  pSVar1 = create();
  return pSVar1;
}



undefined4 cacao::ImageBuf::getMapper(void)

{
  undefined4 uVar1;
  
  uVar1 = getMapper();
  return uVar1;
}



undefined4 cacao::ImageBuf::getAllocator(void)

{
  undefined4 uVar1;
  
  uVar1 = getAllocator();
  return uVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::graphics::mapper::V2_0::IMapper::getService(string *param_1,bool param_2)

{
  getService(param_1,param_2);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::graphics::allocator::V2_0::IAllocator::getService
               (string *param_1,bool param_2)

{
  getService(param_1,param_2);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



void __thiscall android::hardware::details::return_status::~return_status(return_status *this)

{
  ~return_status(this);
  return;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void operator_delete__(void *param_1)

{
  operator_delete__(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

undefined4 __cdecl cacao::SharedBuffer::release(SharedBuffer *param_1)

{
  undefined4 uVar1;
  
  uVar1 = release(param_1);
  return uVar1;
}



ImageBuf * __thiscall cacao::ImageBuf::~ImageBuf(ImageBuf *this)

{
  ImageBuf *pIVar1;
  
  pIVar1 = ~ImageBuf(this);
  return pIVar1;
}



void __thiscall cacao::ObjectBase::operator_delete(ObjectBase *this)

{
  operator_delete(this);
  return;
}



undefined4 __thiscall cacao::ImageBuf::isValid(ImageBuf *this)

{
  undefined4 uVar1;
  
  uVar1 = isValid(this);
  return uVar1;
}



void __thiscall android::hardware::hidl_handle::hidl_handle(hidl_handle *this)

{
  hidl_handle(this);
  return;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



void __thiscall android::hardware::hidl_handle::~hidl_handle(hidl_handle *this)

{
  ~hidl_handle(this);
  return;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * operator_new__(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new__(param_1);
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::hidl_handle::getNativeHandle(void)

{
  getNativeHandle();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int dup(int __fd)

{
  int iVar1;
  
  iVar1 = dup(__fd);
  return iVar1;
}



void __thiscall cacao::ImageBuf::~ImageBuf(ImageBuf *this)

{
  ImageBuf *this_00;
  
  this_00 = ~ImageBuf(this);
  ObjectBase::operator_delete((ObjectBase *)this_00);
  return;
}



undefined4 __thiscall cacao::ImageBuf::getBufSize(ImageBuf *this)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 == 0) {
    __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","getBufSize");
    return 0;
  }
  return *(undefined4 *)(this + 0x14);
}



int __thiscall cacao::ImageBuf::getBufAddress(ImageBuf *this)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 == 0) {
    __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","getBufAddress");
    return 0;
  }
  if (*(int *)(this + 0x10) == 0) {
    (**(code **)(*(int *)this + 0x28))(this);
    return *(int *)(this + 0x10);
  }
  return *(int *)(this + 0x10);
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ImageBuf::getImageSize(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + 8);
  *param_1 = *(undefined4 *)(param_2 + 4);
  param_1[1] = uVar1;
  return;
}



bool __thiscall cacao::ImageBuf::getDirtyFlag(ImageBuf *this)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 != 0) {
    return this[0x21] != (ImageBuf)0x0;
  }
  return false;
}



void __thiscall cacao::ImageBuf::setDirtyFlag(ImageBuf *this,ImageBuf param_2)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 == 0) {
    __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","setDirtyFlag");
    return;
  }
  this[0x21] = param_2;
  return;
}



void __thiscall cacao::ImageBuf::clearCache(ImageBuf *this)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int iStack_6c;
  int aiStack_68 [5];
  undefined1 uStack_54;
  hidl_handle ahStack_50 [16];
  undefined *puStack_40;
  undefined4 *puStack_3c;
  int *piStack_38;
  function<> *pfStack_30;
  int iStack_24;
  
  iStack_24 = __stack_chk_guard;
  iStack_6c = 0;
  iVar1 = isValid(this);
  if ((iVar1 == 0) || (mMapper == (int *)0x0)) {
    __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","clearCache");
    iStack_6c = -0x65;
  }
  else {
    uStack_70 = 0;
    uStack_78 = *(undefined4 *)(this + 4);
    uStack_74 = *(undefined4 *)(this + 8);
    uVar3 = *(undefined4 *)(this + 0xc);
    uStack_80 = 0;
    uStack_7c = 0;
    uVar2 = android::hardware::hidl_handle::hidl_handle(ahStack_50);
    piStack_38 = &iStack_6c;
    puStack_3c = &uStack_70;
    puStack_40 = &DAT_000187f4;
    pfStack_30 = (function<> *)&puStack_40;
    (**(code **)(*mMapper + 0x40))
              (aiStack_68,mMapper,uVar3,*(code **)(*mMapper + 0x40),0x66,0,&uStack_80,uVar2,
               (function<> *)&puStack_40);
    std::function<>::~function((function<> *)&puStack_40);
    uStack_54 = 1;
    if (aiStack_68[0] != 0) {
      __android_log_print(6,"CacaoImageBuf","lock buffer failed");
      iStack_6c = -0x6f;
    }
    android::hardware::details::return_status::~return_status((return_status *)aiStack_68);
    android::hardware::hidl_handle::~hidl_handle(ahStack_50);
    if (-1 < iStack_6c) {
      this[0x21] = (ImageBuf)0x0;
      *(undefined4 *)(this + 0x10) = uStack_70;
    }
  }
  if (__stack_chk_guard != iStack_24) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void __thiscall cacao::ImageBuf::flushCache(ImageBuf *this)

{
  int iVar1;
  int iStack_50;
  int iStack_4c;
  int aiStack_48 [5];
  undefined1 uStack_34;
  undefined *puStack_30;
  undefined1 *puStack_2c;
  int *piStack_28;
  function<> *pfStack_20;
  int iStack_18;
  
  iStack_18 = __stack_chk_guard;
  iStack_4c = 0;
  iVar1 = isValid(this);
  if ((iVar1 == 0) || (mMapper == (int *)0x0)) {
    __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","flushCache");
    iStack_4c = -0x65;
  }
  else {
    iStack_50 = -1;
    piStack_28 = &iStack_4c;
    puStack_30 = &DAT_00018818;
    puStack_2c = (undefined1 *)&iStack_50;
    pfStack_20 = (function<> *)&puStack_30;
    (**(code **)(*mMapper + 0x48))
              (aiStack_48,mMapper,*(undefined4 *)(this + 0xc),(function<> *)&puStack_30);
    std::function<>::~function((function<> *)&puStack_30);
    uStack_34 = 1;
    if (aiStack_48[0] != 0) {
      __android_log_print(6,"CacaoImageBuf","unlock buffer failed");
      iStack_4c = -0x6f;
    }
    android::hardware::details::return_status::~return_status((return_status *)aiStack_48);
    if (-1 < iStack_4c) {
      this[0x21] = (ImageBuf)0x0;
    }
    close(iStack_50);
  }
  if (__stack_chk_guard != iStack_18) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail(iStack_4c);
  }
  return;
}



void __thiscall cacao::ImageBuf::flushAndClearCache(ImageBuf *this)

{
  int iVar1;
  
  if (((this[0x21] != (ImageBuf)0x0) && (*(int *)(this + 0x10) != 0)) &&
     (iVar1 = (**(code **)(*(int *)this + 0x2c))(this), iVar1 < 0)) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00011544. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(*(int *)this + 0x28))(this);
  return;
}



undefined4 __thiscall cacao::ImageBuf::getDataSize(ImageBuf *this)

{
  return *(undefined4 *)(this + 0x1c);
}



void __thiscall cacao::ImageBuf::setDataSize(ImageBuf *this,undefined4 param_1)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 == 0) {
    __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","setDataSize");
    return;
  }
  *(undefined4 *)(this + 0x1c) = param_1;
  return;
}



undefined4 __thiscall cacao::ImageBuf::getDataSpace(ImageBuf *this)

{
  return *(undefined4 *)(this + 0x18);
}



Cacao * android::Cacao::create(void)

{
  Cacao *pCVar1;
  
  pCVar1 = create();
  return pCVar1;
}



undefined4 __thiscall android::Cacao::getJpegBufferSize(Cacao *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = getJpegBufferSize(this,param_1);
  return uVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

int __cdecl android::Cacao::getCaps(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = getCaps(param_1,param_2);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = fprintf(__stream,__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fflush(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void abort(void)

{
                    // WARNING: Subroutine does not return
  abort();
}



void __aeabi_memclr(void)

{
  __aeabi_memclr();
  return;
}



void dladdr(void)

{
  dladdr();
  return;
}



void dl_iterate_phdr(void)

{
  dl_iterate_phdr();
  return;
}



void __vsnprintf_chk(void)

{
  __vsnprintf_chk();
  return;
}



void _GLOBAL__sub_I_ICacaoService_cpp(void)

{
  android::String16::String16
            ((String16 *)&android::ICacaoService::descriptor,"com.sonymobile.cacao.ICacaoService");
  __cxa_atexit(android::String16::~String16,&android::ICacaoService::descriptor,&DAT_00019000);
  return;
}



void _GLOBAL__sub_I_ICacaoProcessCallback_cpp(void)

{
  android::String16::String16
            ((String16 *)&android::ICacaoProcessCallback::descriptor,
             "com.sonymobile.cacao.ICacaoProcessCallback");
  __cxa_atexit(android::String16::~String16,&android::ICacaoProcessCallback::descriptor,
               &DAT_00019000);
  return;
}



void _GLOBAL__sub_I_ICacaoClient_cpp(void)

{
  android::String16::String16
            ((String16 *)&android::ICacaoClient::descriptor,"com.sonymobile.cacao.ICacaoClient");
  __cxa_atexit(android::String16::~String16,&android::ICacaoClient::descriptor,&DAT_00019000);
  return;
}



void _GLOBAL__sub_I_ICacao_cpp(void)

{
  android::String16::String16
            ((String16 *)&android::ICacao::descriptor,"com.sonymobile.cacao.ICacao");
  __cxa_atexit(android::String16::~String16,&android::ICacao::descriptor,&DAT_00019000);
  return;
}



void _GLOBAL__sub_I_Cacao_cpp(void)

{
  android::Cacao::mService = 0;
  __cxa_atexit(android::sp<>::~sp,&android::Cacao::mService,&DAT_00019000);
  android::Cacao::mDeathNotifier = 0;
  __cxa_atexit(android::sp<>::~sp,&android::Cacao::mDeathNotifier,&DAT_00019000);
  pthread_mutex_init((pthread_mutex_t *)&android::Cacao::mServiceLock,(pthread_mutexattr_t *)0x0);
  __cxa_atexit(0xf225,&android::Cacao::mServiceLock,&DAT_00019000);
  return;
}



void _GLOBAL__sub_I_cacao_imagebuf_cpp(void)

{
  cacao::ImageBuf::mMapper = 0;
  __cxa_atexit(android::sp<>::~sp,&cacao::ImageBuf::mMapper,&DAT_00019000);
  cacao::ImageBuf::mAllocator = 0;
  __cxa_atexit(android::sp<>::~sp,&cacao::ImageBuf::mAllocator,&DAT_00019000);
  return;
}



void __on_dlclose(void)

{
  __cxa_finalize(&DAT_00019000);
  return;
}



void __atexit_handler_wrapper(undefined *UNRECOVERED_JUMPTABLE)

{
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
                    // WARNING: Could not recover jumptable at 0x0000cea6. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}



int atexit(__func *__func)

{
  int iVar1;
  
  iVar1 = __cxa_atexit(0xcea5,__func,&DAT_00019000);
  return iVar1;
}



int pthread_atfork(__prepare *__prepare,__parent *__parent,__child *__child)

{
  int iVar1;
  
  iVar1 = __register_atfork(__prepare,__parent,__child,&DAT_00019000);
  return iVar1;
}



// non-virtual thunk to android::BnInterface<android::ICacaoService>::getInterfaceDescriptor() const

undefined4 * __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  return &ICacaoService::descriptor;
}



// android::ICacaoService::asInterface(android::sp<android::IBinder> const&)

void __thiscall android::ICacaoService::asInterface(ICacaoService *this,undefined4 *param_1)

{
  BpCacaoService *this_00;
  undefined4 *puVar1;
  int *local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  *(undefined4 *)this = 0;
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)((sp<> *)&local_1c,puVar1,&descriptor);
    sp<>::operator=((sp<> *)this,local_1c);
    sp<>::~sp((sp<> *)&local_1c);
    if (*(int *)this == 0) {
      this_00 = operator_new(0x1c);
      BpCacaoService::BpCacaoService(this_00);
      sp<>::operator=((sp<> *)this,(int *)this_00);
    }
  }
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::sp<android::ICacaoProcessCallback>::TEMPNAMEPLACEHOLDERVALUE(android::ICacaoProcessCallback*)

sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)this;
  if (param_1 != (int *)0x0) {
    android::RefBase::incStrong((void *)(*(int *)(*param_1 + -0xc) + (int)param_1));
  }
  if (piVar1 != (int *)0x0) {
    android::RefBase::decStrong((void *)(*(int *)(*piVar1 + -0xc) + (int)piVar1));
  }
  if (piVar1 != *(int **)this) {
    android::sp_report_race();
  }
  *(int **)this = param_1;
  return this;
}



// android::sp<android::Cacao::DeathNotifier>::~sp()

sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  int *piVar1;
  
  piVar1 = *(int **)this;
  if (piVar1 != (int *)0x0) {
    android::RefBase::decStrong((void *)((int)piVar1 + *(int *)(*piVar1 + -0xc)));
  }
  return this;
}



// android::BpCacaoService::BpCacaoService(android::sp<android::IBinder> const&)

BpCacaoService * __thiscall android::BpCacaoService::BpCacaoService(BpCacaoService *this)

{
  undefined4 *puVar1;
  
  android::RefBase::RefBase((RefBase *)(this + 0x14));
  android::IInterface::IInterface((IInterface *)this);
  *(undefined4 *)(this + 0x14) = 0x168c8;
  *(undefined4 *)this = 0x1688c;
  puVar1 = (undefined4 *)
           android::BpRefBase::BpRefBase
                     ((BpRefBase *)(this + 4),(sp *)&PTR_construction_vtable_12__000167e8);
  *(undefined4 *)(this + 0x14) = 0x167b8;
  *(undefined4 *)this = 0x1675c;
  *puVar1 = 0x16788;
  return this;
}



// android::ICacaoClient::ICacaoClient()

void __thiscall android::ICacaoClient::ICacaoClient(ICacaoClient *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)android::IInterface::IInterface((IInterface *)this);
  iVar2 = *param_1;
  *piVar1 = iVar2;
  *(int *)((int)piVar1 + *(int *)(iVar2 + -0xc)) = param_1[3];
  return;
}



// android::ICacaoProcessCallback::~ICacaoProcessCallback()

void __thiscall android::ICacaoProcessCallback::~ICacaoProcessCallback(ICacaoProcessCallback *this)

{
  android::IInterface::~IInterface((IInterface *)this);
  return;
}



// virtual thunk to android::IBinder::DeathRecipient::~DeathRecipient()

void __thiscall android::IBinder::DeathRecipient::~DeathRecipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0xd01e);
  (*pcVar1)();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BnCacaoService::onTransact(unsigned int, android::Parcel const&, android::Parcel*,
// unsigned int)

void __cdecl
android::BnCacaoService::onTransact(int *param_1,Parcel *param_2,IBinder *param_3,sp *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  undefined4 auStack_358 [100];
  sp<> asStack_1c8 [4];
  int local_1c4;
  undefined4 local_1c0;
  int local_1bc;
  undefined4 auStack_1b8 [96];
  undefined4 local_38;
  undefined4 local_34;
  int local_28;
  
  local_28 = __stack_chk_guard;
  switch(param_2) {
  case (Parcel *)0x1:
    iVar1 = android::Parcel::checkInterface(param_3);
    if (iVar1 != 0) {
      android::Parcel::readStrongBinder();
      ICacaoClient::asInterface((ICacaoClient *)&local_1bc,&local_1c0);
      sp<>::~sp((sp<> *)&local_1c0);
      (**(code **)(*param_1 + 0x10))((sp<> *)&local_1c0,param_1,(ICacaoClient *)&local_1bc);
      sp<>::sp<>(asStack_1c8,(int *)&local_1c0);
      android::IInterface::asBinder((sp *)&local_1c4);
      android::Parcel::writeStrongBinder(param_4);
      sp<>::~sp((sp<> *)&local_1c4);
      sp<>::~sp((sp<> *)asStack_1c8);
      sp<>::~sp((sp<> *)&local_1c0);
      sp<>::~sp((sp<> *)&local_1bc);
LAB_0000d1ca:
      uVar2 = 0;
      goto LAB_0000d1d2;
    }
    break;
  case (Parcel *)0x2:
    iVar1 = android::Parcel::checkInterface(param_3);
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0x14))(param_1);
LAB_0000d1c2:
      android::Parcel::writeInt32((int)param_4);
      goto LAB_0000d1ca;
    }
    break;
  case (Parcel *)0x3:
    iVar1 = android::Parcel::checkInterface(param_3);
    if (iVar1 != 0) {
      local_1c0 = android::Parcel::readInt32();
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)&local_1c4);
      sp<>::~sp((sp<> *)&local_1bc);
      __aeabi_memclr4(auStack_1b8,400);
      iVar1 = android::Parcel::readInt32();
      local_1bc = iVar1;
      if (iVar1 != 0) {
        iVar5 = 0;
        puVar4 = auStack_1b8;
        do {
          uVar2 = android::Parcel::readFileDescriptor();
          iVar5 = iVar5 + 1;
          *puVar4 = uVar2;
          puVar4 = puVar4 + 1;
        } while (iVar5 != iVar1);
      }
      if (local_1c4 != 0) {
        local_38 = android::IMemory::size();
        local_34 = android::IMemory::pointer();
      }
      pcVar6 = *(code **)(*param_1 + 0x18);
      iVar1 = 400;
      puVar4 = auStack_358;
      puVar7 = auStack_1b8;
      do {
        iVar1 = iVar1 + -4;
        *puVar4 = *puVar7;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar1 != 0);
      (*pcVar6)(param_1,&local_1c0,(sp<> *)&local_1c4,local_1bc);
      android::Parcel::writeInt32((int)param_4);
      sp<>::~sp((sp<> *)&local_1c4);
      goto LAB_0000d1ca;
    }
    break;
  case (Parcel *)0x4:
    iVar1 = android::Parcel::checkInterface(param_3);
    if (iVar1 != 0) {
      uVar2 = android::Parcel::readInt32();
      uVar3 = android::Parcel::readInt32();
      (**(code **)(*param_1 + 0x1c))(param_1,uVar2,uVar3);
      goto LAB_0000d1c2;
    }
    break;
  default:
    android::BBinder::onTransact((uint)(param_1 + 1),param_2,(Parcel *)param_3,(uint)param_4);
    return;
  }
  uVar2 = 0xffffffff;
LAB_0000d1d2:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar2);
}



// android::sp<android::IInterface>::sp<android::ICacaoService>(android::sp<android::ICacaoService>
// const&)

sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    android::RefBase::incStrong((void *)((int)piVar1 + *(int *)(*piVar1 + -0xc)));
  }
  return this;
}



// non-virtual thunk to android::BnCacaoService::onTransact(unsigned int, android::Parcel const&,
// android::Parcel*, unsigned int)

void __thiscall android::BnCacaoService::onTransact(BnCacaoService *this)

{
  Parcel *in_r1;
  IBinder *in_r2;
  sp *in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



// android::BnInterface<android::ICacaoProcessCallback>::onAsBinder()

BnInterface<> * __thiscall android::BnInterface<>::onAsBinder(BnInterface<> *this)

{
  return this + 4;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BnInterface<android::ICacaoService>::queryLocalInterface(android::String16 const&)

void __cdecl
android::BnInterface<>::queryLocalInterface(sp<> *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *param_3;
  uVar2 = android::String16::size();
  uVar1 = ICacaoService::descriptor;
  uVar3 = android::String16::size();
  iVar4 = strzcmp16(uVar5,uVar2,uVar1,uVar3);
  if (iVar4 != 0) {
    *(undefined4 *)param_1 = 0;
    return;
  }
  sp<>::sp<>(param_1,param_2);
  return;
}



// non-virtual thunk to
// android::BnInterface<android::ICacaoService>::queryLocalInterface(android::String16 const&)

void __thiscall
android::BnInterface<>::queryLocalInterface(BnInterface<> *this,int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *param_2;
  uVar2 = android::String16::size();
  uVar1 = ICacaoService::descriptor;
  uVar3 = android::String16::size();
  iVar4 = strzcmp16(uVar5,uVar2,uVar1,uVar3);
  if (iVar4 != 0) {
    *(undefined4 *)this = 0;
    return;
  }
  sp<>::sp<>((sp<> *)this,(int *)(param_1 + -4));
  return;
}



// android::BpInterface<android::ICacao>::onAsBinder()

undefined4 __thiscall android::BpInterface<>::onAsBinder(BpInterface<> *this)

{
  return *(undefined4 *)(this + 8);
}



// android::BpCacaoService::~BpCacaoService()

BpCacaoService * __thiscall android::BpCacaoService::~BpCacaoService(BpCacaoService *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)(this + 4));
  android::IInterface::~IInterface((IInterface *)this);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  return this;
}



// android::BpCacaoService::~BpCacaoService()

void __thiscall android::BpCacaoService::~BpCacaoService(BpCacaoService *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)(this + 4));
  android::IInterface::~IInterface((IInterface *)this);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  operator_delete(this);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BpCacaoService::connect(android::sp<android::ICacaoClient> const&)

void __cdecl android::BpCacaoService::connect(ICacao *param_1,int param_2,int *param_3)

{
  sp<> asStack_94 [4];
  sp asStack_90 [4];
  Parcel aPStack_8c [52];
  Parcel aPStack_58 [52];
  int local_24;
  
  local_24 = __stack_chk_guard;
  android::Parcel::Parcel(aPStack_58);
  android::Parcel::Parcel(aPStack_8c);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_58);
  sp<>::sp<>(asStack_94,param_3);
  android::IInterface::asBinder(asStack_90);
  android::Parcel::writeStrongBinder((sp *)aPStack_58);
  sp<>::~sp((sp<> *)asStack_90);
  sp<>::~sp((sp<> *)asStack_94);
  (**(code **)(**(int **)(param_2 + 8) + 0x14))(*(int **)(param_2 + 8),1,aPStack_58,aPStack_8c,0);
  android::Parcel::readStrongBinder();
  ICacao::asInterface(param_1,(undefined4 *)asStack_90);
  sp<>::~sp((sp<> *)asStack_90);
  android::Parcel::~Parcel(aPStack_8c);
  android::Parcel::~Parcel(aPStack_58);
  if (__stack_chk_guard == local_24) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacaoService::getServicePid()

undefined4 __thiscall android::BpCacaoService::getServicePid(BpCacaoService *this)

{
  undefined4 uVar1;
  Parcel aPStack_80 [52];
  Parcel aPStack_4c [52];
  int local_18;
  
  local_18 = __stack_chk_guard;
  android::Parcel::Parcel(aPStack_4c);
  android::Parcel::Parcel(aPStack_80);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_4c);
  (**(code **)(**(int **)(this + 8) + 0x14))(*(int **)(this + 8),2,aPStack_4c,aPStack_80,0);
  uVar1 = android::Parcel::readInt32();
  android::Parcel::~Parcel(aPStack_80);
  android::Parcel::~Parcel(aPStack_4c);
  if (__stack_chk_guard == local_18) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)

undefined4 __thiscall
android::BpCacaoService::getCaps
          (BpCacaoService *this,undefined4 param_2_00,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  sp<> asStack_bc [4];
  sp asStack_b8 [4];
  int local_b4;
  Parcel aPStack_b0 [72];
  Parcel aPStack_68 [72];
  
  iVar1 = __stack_chk_guard;
  local_b4 = param_3;
  android::Parcel::Parcel(aPStack_b0);
  android::Parcel::Parcel(aPStack_68);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_b0);
  android::Parcel::writeInt32((int)aPStack_b0);
  sp<>::sp<>(asStack_bc,param_2);
  android::IInterface::asBinder(asStack_b8);
  android::Parcel::writeStrongBinder((sp *)aPStack_b0);
  sp<>::~sp((sp<> *)asStack_b8);
  sp<>::~sp((sp<> *)asStack_bc);
  iVar2 = local_b4;
  android::Parcel::writeInt32((int)aPStack_b0);
  if (iVar2 != 0) {
    piVar5 = &local_b4;
    iVar4 = 0;
    do {
      piVar5 = piVar5 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_b0,SUB41(*piVar5,0));
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar2);
  }
  (**(code **)(**(int **)(this + 8) + 0x14))(*(int **)(this + 8),3,aPStack_b0,aPStack_68,0);
  uVar3 = android::Parcel::readInt32();
  android::Parcel::~Parcel(aPStack_68);
  android::Parcel::~Parcel(aPStack_b0);
  if (__stack_chk_guard == iVar1) {
    return uVar3;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BpCacaoService::getJpegBufferSize(cacao::ImageSize)

undefined4 __cdecl android::BpCacaoService::getJpegBufferSize(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  Parcel aPStack_ac [72];
  Parcel aPStack_64 [72];
  
  iVar1 = __stack_chk_guard;
  android::Parcel::Parcel(aPStack_ac);
  android::Parcel::Parcel(aPStack_64);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_ac);
  android::Parcel::writeInt32((int)aPStack_ac);
  android::Parcel::writeInt32((int)aPStack_ac);
  (**(code **)(**(int **)(param_1 + 8) + 0x14))(*(int **)(param_1 + 8),4,aPStack_ac,aPStack_64,0);
  uVar2 = android::Parcel::readInt32();
  android::Parcel::~Parcel(aPStack_64);
  android::Parcel::~Parcel(aPStack_ac);
  if (__stack_chk_guard == iVar1) {
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::BpCacaoService::~BpCacaoService()

void __thiscall android::BpCacaoService::~BpCacaoService(BpCacaoService *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)this);
  android::IInterface::~IInterface((IInterface *)(this + -4));
  android::RefBase::~RefBase((RefBase *)(this + 0x10));
  return;
}



// non-virtual thunk to android::BpCacaoService::~BpCacaoService()

void __thiscall android::BpCacaoService::~BpCacaoService(BpCacaoService *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)this);
  android::IInterface::~IInterface((IInterface *)(this + -4));
  android::RefBase::~RefBase((RefBase *)(this + 0x10));
  operator_delete((IInterface *)(this + -4));
  return;
}



// virtual thunk to android::BpCacaoService::~BpCacaoService()

void __thiscall android::BpCacaoService::~BpCacaoService(BpCacaoService *this)

{
  IInterface *this_00;
  
  this_00 = (IInterface *)(this + *(int *)(*(int *)this + -0xc));
  android::BpRefBase::~BpRefBase((BpRefBase *)(this_00 + 4));
  android::IInterface::~IInterface(this_00);
  android::RefBase::~RefBase((RefBase *)(this_00 + 0x14));
  return;
}



// virtual thunk to android::BpCacaoService::~BpCacaoService()

void __thiscall android::BpCacaoService::~BpCacaoService(BpCacaoService *this)

{
  IInterface *this_00;
  
  this_00 = (IInterface *)(this + *(int *)(*(int *)this + -0xc));
  android::BpRefBase::~BpRefBase((BpRefBase *)(this_00 + 4));
  android::IInterface::~IInterface(this_00);
  android::RefBase::~RefBase((RefBase *)(this_00 + 0x14));
  operator_delete(this_00);
  return;
}



// android::sp<android::IMemory>::sp<android::MemoryBase>(android::MemoryBase*)

sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  *(int **)this = param_1;
  if (param_1 != (int *)0x0) {
    android::RefBase::incStrong((void *)(*(int *)(*param_1 + -0xc) + (int)param_1));
  }
  return this;
}



// non-virtual thunk to
// android::BnInterface<android::ICacaoProcessCallback>::getInterfaceDescriptor() const

undefined4 * __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  return &ICacaoProcessCallback::descriptor;
}



// android::ICacaoProcessCallback::asInterface(android::sp<android::IBinder> const&)

void __thiscall
android::ICacaoProcessCallback::asInterface(ICacaoProcessCallback *this,undefined4 *param_1)

{
  BpCacaoProcessCallback *this_00;
  undefined4 *puVar1;
  int *local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  *(undefined4 *)this = 0;
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)((sp<> *)&local_1c,puVar1,&descriptor);
    sp<>::operator=((sp<> *)this,local_1c);
    sp<>::~sp((sp<> *)&local_1c);
    if (*(int *)this == 0) {
      this_00 = operator_new(0x1c);
      BpCacaoProcessCallback::BpCacaoProcessCallback(this_00);
      sp<>::operator=((sp<> *)this,(int *)this_00);
    }
  }
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacaoProcessCallback::BpCacaoProcessCallback(android::sp<android::IBinder> const&)

BpCacaoProcessCallback * __thiscall
android::BpCacaoProcessCallback::BpCacaoProcessCallback(BpCacaoProcessCallback *this)

{
  undefined4 *puVar1;
  
  android::RefBase::RefBase((RefBase *)(this + 0x14));
  android::IInterface::IInterface((IInterface *)this);
  *(undefined4 *)(this + 0x14) = 0x16f10;
  *(undefined4 *)this = 0x16edc;
  puVar1 = (undefined4 *)
           android::BpRefBase::BpRefBase
                     ((BpRefBase *)(this + 4),(sp *)&PTR_construction_vtable_12__00016e30);
  *(undefined4 *)(this + 0x14) = 0x16e00;
  *(undefined4 *)this = 0x16dac;
  *puVar1 = 0x16dd0;
  return this;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BnCacaoProcessCallback::onTransact(unsigned int, android::Parcel const&,
// android::Parcel*, unsigned int)

undefined4 __cdecl
android::BnCacaoProcessCallback::onTransact
          (int *param_1,Parcel *param_2,IBinder *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  code *pcVar6;
  undefined4 auStack_350 [99];
  undefined4 local_1c4;
  int local_1bc;
  int local_1b8;
  undefined4 auStack_1b4 [96];
  undefined4 local_34;
  undefined4 local_30;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (param_2 == (Parcel *)0x2) {
    iVar1 = android::Parcel::checkInterface(param_3);
    if (iVar1 != 0) {
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)&local_1bc);
      sp<>::~sp((sp<> *)&local_1b8);
      __aeabi_memclr4(auStack_1b4,400);
      iVar1 = android::Parcel::readInt32();
      local_1b8 = iVar1;
      if (iVar1 != 0) {
        iVar4 = 0;
        puVar5 = auStack_1b4;
        do {
          uVar2 = android::Parcel::readFileDescriptor();
          iVar4 = iVar4 + 1;
          *puVar5 = uVar2;
          puVar5 = puVar5 + 1;
        } while (iVar4 != iVar1);
      }
      if (local_1bc != 0) {
        local_34 = android::IMemory::size();
        local_30 = android::IMemory::pointer();
      }
      uVar2 = 0;
      iVar1 = 0x18c;
      pcVar6 = *(code **)(*param_1 + 0x14);
      puVar5 = auStack_1b4;
      local_1c4 = 0;
      puVar3 = auStack_350;
      do {
        puVar5 = puVar5 + 1;
        iVar1 = iVar1 + -4;
        *puVar3 = *puVar5;
        puVar3 = puVar3 + 1;
      } while (iVar1 != 0);
      (*pcVar6)(param_1,(sp<> *)&local_1bc,local_1b8,auStack_1b4[0]);
      sp<>::~sp((sp<> *)&local_1bc);
      goto LAB_0000d8ee;
    }
  }
  else {
    if (param_2 != (Parcel *)0x1) {
      uVar2 = android::BBinder::onTransact((uint)(param_1 + 1),param_2,(Parcel *)param_3,param_4);
      return uVar2;
    }
    iVar1 = android::Parcel::checkInterface(param_3);
    if (iVar1 != 0) {
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)&local_1bc);
      sp<>::~sp((sp<> *)&local_1b8);
      __aeabi_memclr4(auStack_1b4,400);
      iVar1 = android::Parcel::readInt32();
      local_1b8 = iVar1;
      if (iVar1 != 0) {
        iVar4 = 0;
        puVar5 = auStack_1b4;
        do {
          uVar2 = android::Parcel::readFileDescriptor();
          iVar4 = iVar4 + 1;
          *puVar5 = uVar2;
          puVar5 = puVar5 + 1;
        } while (iVar4 != iVar1);
      }
      if (local_1bc != 0) {
        local_34 = android::IMemory::size();
        local_30 = android::IMemory::pointer();
      }
      iVar1 = 0x18c;
      pcVar6 = *(code **)(*param_1 + 0x10);
      puVar5 = auStack_1b4;
      puVar3 = auStack_350;
      do {
        puVar5 = puVar5 + 1;
        iVar1 = iVar1 + -4;
        *puVar3 = *puVar5;
        puVar3 = puVar3 + 1;
      } while (iVar1 != 0);
      (*pcVar6)(param_1,(sp<> *)&local_1bc,local_1b8,auStack_1b4[0]);
      sp<>::~sp((sp<> *)&local_1bc);
      uVar2 = 0;
      goto LAB_0000d8ee;
    }
  }
  uVar2 = 0xffffffff;
LAB_0000d8ee:
  if (__stack_chk_guard == local_24) {
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::BnCacaoProcessCallback::onTransact(unsigned int, android::Parcel
// const&, android::Parcel*, unsigned int)

void __thiscall android::BnCacaoProcessCallback::onTransact(BnCacaoProcessCallback *this)

{
  Parcel *in_r1;
  IBinder *in_r2;
  uint in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BnInterface<android::ICacaoProcessCallback>::queryLocalInterface(android::String16
// const&)

void __cdecl
android::BnInterface<>::queryLocalInterface(sp<> *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *param_3;
  uVar2 = android::String16::size();
  uVar1 = ICacaoProcessCallback::descriptor;
  uVar3 = android::String16::size();
  iVar4 = strzcmp16(uVar5,uVar2,uVar1,uVar3);
  if (iVar4 != 0) {
    *(undefined4 *)param_1 = 0;
    return;
  }
  sp<>::sp<>(param_1,param_2);
  return;
}



// non-virtual thunk to
// android::BnInterface<android::ICacaoProcessCallback>::queryLocalInterface(android::String16
// const&)

void __thiscall
android::BnInterface<>::queryLocalInterface(BnInterface<> *this,int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *param_2;
  uVar2 = android::String16::size();
  uVar1 = ICacaoProcessCallback::descriptor;
  uVar3 = android::String16::size();
  iVar4 = strzcmp16(uVar5,uVar2,uVar1,uVar3);
  if (iVar4 != 0) {
    *(undefined4 *)this = 0;
    return;
  }
  sp<>::sp<>((sp<> *)this,(int *)(param_1 + -4));
  return;
}



// android::BpCacaoProcessCallback::~BpCacaoProcessCallback()

BpCacaoProcessCallback * __thiscall
android::BpCacaoProcessCallback::~BpCacaoProcessCallback(BpCacaoProcessCallback *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)(this + 4));
  android::IInterface::~IInterface((IInterface *)this);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  return this;
}



// android::BpCacaoProcessCallback::~BpCacaoProcessCallback()

void __thiscall
android::BpCacaoProcessCallback::~BpCacaoProcessCallback(BpCacaoProcessCallback *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)(this + 4));
  android::IInterface::~IInterface((IInterface *)this);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  operator_delete(this);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BpCacaoProcessCallback::notifyProgress(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData)

void __cdecl
android::BpCacaoProcessCallback::notifyProgress
          (int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  sp<> asStack_c0 [4];
  sp asStack_bc [4];
  Parcel aPStack_b8 [72];
  Parcel aPStack_70 [72];
  int local_28;
  int local_8;
  int iStack_4;
  
  local_28 = __stack_chk_guard;
  local_8 = param_3;
  iStack_4 = param_4;
  android::Parcel::Parcel(aPStack_70);
  android::Parcel::Parcel(aPStack_b8);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_70);
  sp<>::sp<>(asStack_c0,param_2);
  android::IInterface::asBinder(asStack_bc);
  android::Parcel::writeStrongBinder((sp *)aPStack_70);
  sp<>::~sp((sp<> *)asStack_bc);
  sp<>::~sp((sp<> *)asStack_c0);
  iVar1 = local_8;
  android::Parcel::writeInt32((int)aPStack_70);
  if (iVar1 != 0) {
    piVar3 = &local_8;
    iVar2 = 0;
    do {
      piVar3 = piVar3 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_70,SUB41(*piVar3,0));
      iVar2 = iVar2 + 1;
    } while (iVar2 != iVar1);
  }
  (**(code **)(**(int **)(param_1 + 8) + 0x14))(*(int **)(param_1 + 8),1,aPStack_70,aPStack_b8,0);
  android::Parcel::~Parcel(aPStack_b8);
  android::Parcel::~Parcel(aPStack_70);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacaoProcessCallback::notifyResult(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData, android::Vector<cacao::ImageBuf*>*)

void __thiscall
android::BpCacaoProcessCallback::notifyResult
          (BpCacaoProcessCallback *this,int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int in_stack_0000018c;
  sp<> asStack_c4 [4];
  sp asStack_c0 [4];
  Parcel aPStack_bc [72];
  Parcel aPStack_74 [72];
  int local_2c;
  int local_8;
  int iStack_4;
  
  local_2c = __stack_chk_guard;
  local_8 = param_2;
  iStack_4 = param_3;
  android::Parcel::Parcel(aPStack_74);
  android::Parcel::Parcel(aPStack_bc);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_74);
  sp<>::sp<>(asStack_c4,param_1);
  android::IInterface::asBinder(asStack_c0);
  android::Parcel::writeStrongBinder((sp *)aPStack_74);
  sp<>::~sp((sp<> *)asStack_c0);
  sp<>::~sp((sp<> *)asStack_c4);
  iVar1 = local_8;
  android::Parcel::writeInt32((int)aPStack_74);
  if (iVar1 != 0) {
    piVar3 = &local_8;
    iVar5 = 0;
    do {
      piVar3 = piVar3 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_74,SUB41(*piVar3,0));
      iVar5 = iVar5 + 1;
    } while (iVar5 != iVar1);
  }
  (**(code **)(**(int **)(this + 8) + 0x14))(*(int **)(this + 8),2,aPStack_74,aPStack_bc,0);
  if ((in_stack_0000018c != 0) && (*(int *)(in_stack_0000018c + 8) != 0)) {
    uVar4 = 0;
    do {
      uVar2 = (**(code **)(**(int **)(*(int *)(in_stack_0000018c + 4) + uVar4 * 4) + 0x10))();
      native_handle_close();
      native_handle_delete(uVar2);
      piVar3 = *(int **)(*(int *)(in_stack_0000018c + 4) + uVar4 * 4);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_stack_0000018c + 8));
  }
  android::Parcel::~Parcel(aPStack_bc);
  android::Parcel::~Parcel(aPStack_74);
  if (__stack_chk_guard == local_2c) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::BpCacaoProcessCallback::~BpCacaoProcessCallback()

void __thiscall
android::BpCacaoProcessCallback::~BpCacaoProcessCallback(BpCacaoProcessCallback *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)this);
  android::IInterface::~IInterface((IInterface *)(this + -4));
  android::RefBase::~RefBase((RefBase *)(this + 0x10));
  return;
}



// non-virtual thunk to android::BpCacaoProcessCallback::~BpCacaoProcessCallback()

void __thiscall
android::BpCacaoProcessCallback::~BpCacaoProcessCallback(BpCacaoProcessCallback *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)this);
  android::IInterface::~IInterface((IInterface *)(this + -4));
  android::RefBase::~RefBase((RefBase *)(this + 0x10));
  operator_delete((IInterface *)(this + -4));
  return;
}



// virtual thunk to android::BpCacaoProcessCallback::~BpCacaoProcessCallback()

void __thiscall
android::BpCacaoProcessCallback::~BpCacaoProcessCallback(BpCacaoProcessCallback *this)

{
  IInterface *this_00;
  
  this_00 = (IInterface *)(this + *(int *)(*(int *)this + -0xc));
  android::BpRefBase::~BpRefBase((BpRefBase *)(this_00 + 4));
  android::IInterface::~IInterface(this_00);
  android::RefBase::~RefBase((RefBase *)(this_00 + 0x14));
  return;
}



// virtual thunk to android::BpCacaoProcessCallback::~BpCacaoProcessCallback()

void __thiscall
android::BpCacaoProcessCallback::~BpCacaoProcessCallback(BpCacaoProcessCallback *this)

{
  IInterface *this_00;
  
  this_00 = (IInterface *)(this + *(int *)(*(int *)this + -0xc));
  android::BpRefBase::~BpRefBase((BpRefBase *)(this_00 + 4));
  android::IInterface::~IInterface(this_00);
  android::RefBase::~RefBase((RefBase *)(this_00 + 0x14));
  operator_delete(this_00);
  return;
}



// non-virtual thunk to android::BnInterface<android::ICacaoClient>::getInterfaceDescriptor() const

undefined4 * __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  return &ICacaoClient::descriptor;
}



// android::ICacaoClient::asInterface(android::sp<android::IBinder> const&)

void __thiscall android::ICacaoClient::asInterface(ICacaoClient *this,undefined4 *param_1)

{
  BpCacaoClient *this_00;
  undefined4 *puVar1;
  int *local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  *(undefined4 *)this = 0;
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)((sp<> *)&local_1c,puVar1,&descriptor);
    sp<>::operator=((sp<> *)this,local_1c);
    sp<>::~sp((sp<> *)&local_1c);
    if (*(int *)this == 0) {
      this_00 = operator_new(0x1c);
      BpCacaoClient::BpCacaoClient(this_00);
      sp<>::operator=((sp<> *)this,(int *)this_00);
    }
  }
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacaoClient::BpCacaoClient(android::sp<android::IBinder> const&)

BpCacaoClient * __thiscall android::BpCacaoClient::BpCacaoClient(BpCacaoClient *this)

{
  undefined4 *puVar1;
  
  android::RefBase::RefBase((RefBase *)(this + 0x14));
  android::IInterface::IInterface((IInterface *)this);
  *(undefined4 *)(this + 0x14) = 0x1754c;
  *(undefined4 *)this = 0x1751c;
  puVar1 = (undefined4 *)
           android::BpRefBase::BpRefBase
                     ((BpRefBase *)(this + 4),(sp *)&PTR_construction_vtable_12__0001746c);
  *(undefined4 *)(this + 0x14) = 0x1743c;
  *(undefined4 *)this = 0x173ec;
  *puVar1 = 0x1740c;
  return this;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BnCacaoClient::onTransact(unsigned int, android::Parcel const&, android::Parcel*,
// unsigned int)

void __cdecl
android::BnCacaoClient::onTransact(int *param_1,Parcel *param_2,IBinder *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  undefined4 auStack_350 [100];
  int local_1c0;
  int local_1bc;
  undefined4 auStack_1b8 [96];
  undefined4 local_38;
  undefined4 local_34;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_2 != (Parcel *)0x1) {
    android::BBinder::onTransact((uint)(param_1 + 1),param_2,(Parcel *)param_3,param_4);
    return;
  }
  iVar1 = android::Parcel::checkInterface(param_3);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = android::Parcel::readInt32();
    android::Parcel::readStrongBinder();
    android::IMemory::asInterface((sp *)&local_1c0);
    sp<>::~sp((sp<> *)&local_1bc);
    __aeabi_memclr4(auStack_1b8,400);
    iVar1 = android::Parcel::readInt32();
    local_1bc = iVar1;
    if (iVar1 != 0) {
      iVar5 = 0;
      puVar4 = auStack_1b8;
      do {
        uVar3 = android::Parcel::readFileDescriptor();
        iVar5 = iVar5 + 1;
        *puVar4 = uVar3;
        puVar4 = puVar4 + 1;
      } while (iVar5 != iVar1);
    }
    if (local_1c0 != 0) {
      local_38 = android::IMemory::size();
      local_34 = android::IMemory::pointer();
    }
    pcVar6 = *(code **)(*param_1 + 0x10);
    iVar1 = 400;
    puVar4 = auStack_350;
    puVar7 = auStack_1b8;
    do {
      iVar1 = iVar1 + -4;
      *puVar4 = *puVar7;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar1 != 0);
    (*pcVar6)(param_1,uVar2,(sp<> *)&local_1c0,local_1bc);
    sp<>::~sp((sp<> *)&local_1c0);
    uVar2 = 0;
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar2);
}



// non-virtual thunk to android::BnCacaoClient::onTransact(unsigned int, android::Parcel const&,
// android::Parcel*, unsigned int)

void __thiscall android::BnCacaoClient::onTransact(BnCacaoClient *this)

{
  Parcel *in_r1;
  IBinder *in_r2;
  uint in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BnInterface<android::ICacaoClient>::queryLocalInterface(android::String16 const&)

void __cdecl
android::BnInterface<>::queryLocalInterface(sp<> *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *param_3;
  uVar2 = android::String16::size();
  uVar1 = ICacaoClient::descriptor;
  uVar3 = android::String16::size();
  iVar4 = strzcmp16(uVar5,uVar2,uVar1,uVar3);
  if (iVar4 != 0) {
    *(undefined4 *)param_1 = 0;
    return;
  }
  sp<>::sp<>(param_1,param_2);
  return;
}



// non-virtual thunk to
// android::BnInterface<android::ICacaoClient>::queryLocalInterface(android::String16 const&)

void __thiscall
android::BnInterface<>::queryLocalInterface(BnInterface<> *this,int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *param_2;
  uVar2 = android::String16::size();
  uVar1 = ICacaoClient::descriptor;
  uVar3 = android::String16::size();
  iVar4 = strzcmp16(uVar5,uVar2,uVar1,uVar3);
  if (iVar4 != 0) {
    *(undefined4 *)this = 0;
    return;
  }
  sp<>::sp<>((sp<> *)this,(int *)(param_1 + -4));
  return;
}



// android::BpCacaoClient::~BpCacaoClient()

BpCacaoClient * __thiscall android::BpCacaoClient::~BpCacaoClient(BpCacaoClient *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)(this + 4));
  android::IInterface::~IInterface((IInterface *)this);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  return this;
}



// android::BpCacaoClient::~BpCacaoClient()

void __thiscall android::BpCacaoClient::~BpCacaoClient(BpCacaoClient *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)(this + 4));
  android::IInterface::~IInterface((IInterface *)this);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  operator_delete(this);
  return;
}



// android::BpCacaoClient::notifyEvent(int, android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData)

void __thiscall
android::BpCacaoClient::notifyEvent
          (BpCacaoClient *this,undefined4 param_2_00,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  sp<> asStack_bc [4];
  sp asStack_b8 [4];
  Parcel aPStack_b4 [72];
  Parcel aPStack_6c [72];
  int local_24;
  int local_4;
  
  local_24 = __stack_chk_guard;
  local_4 = param_3;
  android::Parcel::Parcel(aPStack_6c);
  android::Parcel::Parcel(aPStack_b4);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_6c);
  android::Parcel::writeInt32((int)aPStack_6c);
  sp<>::sp<>(asStack_bc,param_2);
  android::IInterface::asBinder(asStack_b8);
  android::Parcel::writeStrongBinder((sp *)aPStack_6c);
  sp<>::~sp((sp<> *)asStack_b8);
  sp<>::~sp((sp<> *)asStack_bc);
  iVar1 = local_4;
  android::Parcel::writeInt32((int)aPStack_6c);
  if (iVar1 != 0) {
    piVar3 = &local_4;
    iVar2 = 0;
    do {
      piVar3 = piVar3 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_6c,SUB41(*piVar3,0));
      iVar2 = iVar2 + 1;
    } while (iVar2 != iVar1);
  }
  (**(code **)(**(int **)(this + 8) + 0x14))(*(int **)(this + 8),1,aPStack_6c,aPStack_b4,1);
  android::Parcel::~Parcel(aPStack_b4);
  android::Parcel::~Parcel(aPStack_6c);
  if (__stack_chk_guard == local_24) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::BpCacaoClient::~BpCacaoClient()

void __thiscall android::BpCacaoClient::~BpCacaoClient(BpCacaoClient *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)this);
  android::IInterface::~IInterface((IInterface *)(this + -4));
  android::RefBase::~RefBase((RefBase *)(this + 0x10));
  return;
}



// non-virtual thunk to android::BpCacaoClient::~BpCacaoClient()

void __thiscall android::BpCacaoClient::~BpCacaoClient(BpCacaoClient *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)this);
  android::IInterface::~IInterface((IInterface *)(this + -4));
  android::RefBase::~RefBase((RefBase *)(this + 0x10));
  operator_delete((IInterface *)(this + -4));
  return;
}



// virtual thunk to android::BpCacaoClient::~BpCacaoClient()

void __thiscall android::BpCacaoClient::~BpCacaoClient(BpCacaoClient *this)

{
  IInterface *this_00;
  
  this_00 = (IInterface *)(this + *(int *)(*(int *)this + -0xc));
  android::BpRefBase::~BpRefBase((BpRefBase *)(this_00 + 4));
  android::IInterface::~IInterface(this_00);
  android::RefBase::~RefBase((RefBase *)(this_00 + 0x14));
  return;
}



// virtual thunk to android::BpCacaoClient::~BpCacaoClient()

void __thiscall android::BpCacaoClient::~BpCacaoClient(BpCacaoClient *this)

{
  IInterface *this_00;
  
  this_00 = (IInterface *)(this + *(int *)(*(int *)this + -0xc));
  android::BpRefBase::~BpRefBase((BpRefBase *)(this_00 + 4));
  android::IInterface::~IInterface(this_00);
  android::RefBase::~RefBase((RefBase *)(this_00 + 0x14));
  operator_delete(this_00);
  return;
}



// non-virtual thunk to android::BnInterface<android::ICacao>::getInterfaceDescriptor() const

undefined4 * __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  return &ICacao::descriptor;
}



// android::ICacao::asInterface(android::sp<android::IBinder> const&)

void __thiscall android::ICacao::asInterface(ICacao *this,undefined4 *param_1)

{
  BpCacao *this_00;
  undefined4 *puVar1;
  int *local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  *(undefined4 *)this = 0;
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)((sp<> *)&local_1c,puVar1,&descriptor);
    sp<>::operator=((sp<> *)this,local_1c);
    sp<>::~sp((sp<> *)&local_1c);
    if (*(int *)this == 0) {
      this_00 = operator_new(0x1c);
      BpCacao::BpCacao(this_00);
      sp<>::operator=((sp<> *)this,(int *)this_00);
    }
  }
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacao::BpCacao(android::sp<android::IBinder> const&)

BpCacao * __thiscall android::BpCacao::BpCacao(BpCacao *this)

{
  undefined4 *puVar1;
  
  android::RefBase::RefBase((RefBase *)(this + 0x14));
  android::IInterface::IInterface((IInterface *)this);
  *(undefined4 *)(this + 0x14) = 0x17c38;
  *(undefined4 *)this = 0x17bec;
  puVar1 = (undefined4 *)
           android::BpRefBase::BpRefBase
                     ((BpRefBase *)(this + 4),(sp *)&PTR_construction_vtable_12__00017b38);
  *(undefined4 *)(this + 0x14) = 0x17b08;
  *(undefined4 *)this = 0x17a9c;
  *puVar1 = 0x17ad8;
  return this;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BnCacao::onTransact(unsigned int, android::Parcel const&, android::Parcel*, unsigned
// int)

undefined4 __cdecl
android::BnCacao::onTransact(int *param_1,Parcel *param_2,IBinder *param_3,ImageBuf **param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  ImageBuf **ppIVar5;
  ImageBuf **ppIVar6;
  ImageBuf *pIVar7;
  ImageBuf *pIVar8;
  int iVar9;
  undefined4 uVar10;
  int *piVar11;
  ImageBuf ***pppIVar12;
  ImageBuf *pIVar13;
  sp<> *psVar14;
  code *pcVar15;
  ImageBuf **ppIVar16;
  uint uVar17;
  undefined4 auStack_52c [101];
  undefined4 local_398;
  ICacaoProcessCallback *pIStack_394;
  int *local_390;
  ImageBuf **local_38c;
  undefined **local_388 [5];
  undefined4 local_374;
  ICacaoProcessCallback aIStack_370 [4];
  int local_36c;
  undefined **local_368;
  int local_364;
  uint local_360;
  int local_354;
  ImageBuf *local_350 [97];
  undefined4 local_1cc;
  undefined4 local_1c8;
  ImageBuf **local_1bc;
  ImageBuf **local_1b8 [96];
  undefined4 local_38;
  undefined4 local_34;
  int local_28;
  
  local_28 = __stack_chk_guard;
  switch(param_2) {
  case (Parcel *)0x1:
    iVar9 = android::Parcel::checkInterface(param_3);
    if (iVar9 != 0) {
      (**(code **)(*param_1 + 0x10))(param_1);
LAB_0000e822:
      uVar10 = 0;
      goto LAB_0000e82a;
    }
    break;
  case (Parcel *)0x2:
    iVar9 = android::Parcel::checkInterface(param_3);
    if (iVar9 != 0) {
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)local_350);
      sp<>::~sp((sp<> *)&local_1bc);
      __aeabi_memclr4(local_1b8,400);
      ppIVar5 = (ImageBuf **)android::Parcel::readInt32();
      local_1bc = ppIVar5;
      if (ppIVar5 != (ImageBuf **)0x0) {
        ppIVar16 = (ImageBuf **)0x0;
        pppIVar12 = local_1b8;
        do {
          ppIVar6 = (ImageBuf **)android::Parcel::readFileDescriptor();
          ppIVar16 = (ImageBuf **)((int)ppIVar16 + 1);
          *pppIVar12 = ppIVar6;
          pppIVar12 = pppIVar12 + 1;
        } while (ppIVar16 != ppIVar5);
      }
      if (local_350[0] != (ImageBuf *)0x0) {
        local_38 = android::IMemory::size();
        local_34 = android::IMemory::pointer();
      }
      pppIVar12 = local_1b8;
      pcVar15 = *(code **)(*param_1 + 0x14);
      iVar9 = 0x18c;
      puVar4 = (undefined4 *)&stack0xfffff940;
      do {
        pppIVar12 = pppIVar12 + 1;
        iVar9 = iVar9 + -4;
        *puVar4 = *pppIVar12;
        puVar4 = puVar4 + 1;
      } while (iVar9 != 0);
      ppIVar5 = local_350;
      ppIVar16 = local_1bc;
LAB_0000e478:
      psVar14 = (sp<> *)local_350;
      (*pcVar15)(param_1,ppIVar5,ppIVar16,local_1b8[0]);
      android::Parcel::writeInt32((int)param_4);
LAB_0000e7f4:
      sp<>::~sp(psVar14);
      goto LAB_0000e822;
    }
    break;
  case (Parcel *)0x3:
    iVar9 = android::Parcel::checkInterface(param_3);
    if (iVar9 != 0) {
      (**(code **)(*param_1 + 0x18))(param_1);
LAB_0000e81a:
      android::Parcel::writeInt32((int)param_4);
      goto LAB_0000e822;
    }
    break;
  case (Parcel *)0x4:
    iVar9 = android::Parcel::checkInterface(param_3);
    if (iVar9 != 0) {
      local_38c = (ImageBuf **)android::Parcel::readInt32();
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)local_350);
      sp<>::~sp((sp<> *)&local_1bc);
      __aeabi_memclr4(local_1b8,400);
      ppIVar5 = (ImageBuf **)android::Parcel::readInt32();
      local_1bc = ppIVar5;
      if (ppIVar5 != (ImageBuf **)0x0) {
        ppIVar16 = (ImageBuf **)0x0;
        pppIVar12 = local_1b8;
        do {
          ppIVar6 = (ImageBuf **)android::Parcel::readFileDescriptor();
          ppIVar16 = (ImageBuf **)((int)ppIVar16 + 1);
          *pppIVar12 = ppIVar6;
          pppIVar12 = pppIVar12 + 1;
        } while (ppIVar16 != ppIVar5);
      }
      if (local_350[0] != (ImageBuf *)0x0) {
        local_38 = android::IMemory::size();
        local_34 = android::IMemory::pointer();
      }
      iVar9 = 400;
      pcVar15 = *(code **)(*param_1 + 0x1c);
      puVar4 = (undefined4 *)&stack0xfffff940;
      pppIVar12 = local_1b8;
      do {
        iVar9 = iVar9 + -4;
        *puVar4 = *pppIVar12;
        puVar4 = puVar4 + 1;
        pppIVar12 = pppIVar12 + 1;
      } while (iVar9 != 0);
LAB_0000e46c:
      ppIVar5 = local_38c;
      ppIVar16 = local_350;
      local_1b8[0] = local_1bc;
      goto LAB_0000e478;
    }
    break;
  case (Parcel *)0x5:
    iVar9 = android::Parcel::checkInterface(param_3);
    if (iVar9 != 0) {
      local_38c = (ImageBuf **)android::Parcel::readInt32();
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)local_350);
      sp<>::~sp((sp<> *)&local_1bc);
      __aeabi_memclr4(local_1b8,400);
      ppIVar5 = (ImageBuf **)android::Parcel::readInt32();
      local_1bc = ppIVar5;
      if (ppIVar5 != (ImageBuf **)0x0) {
        ppIVar16 = (ImageBuf **)0x0;
        pppIVar12 = local_1b8;
        do {
          ppIVar6 = (ImageBuf **)android::Parcel::readFileDescriptor();
          ppIVar16 = (ImageBuf **)((int)ppIVar16 + 1);
          *pppIVar12 = ppIVar6;
          pppIVar12 = pppIVar12 + 1;
        } while (ppIVar16 != ppIVar5);
      }
      if (local_350[0] != (ImageBuf *)0x0) {
        local_38 = android::IMemory::size();
        local_34 = android::IMemory::pointer();
      }
      iVar9 = 400;
      pcVar15 = *(code **)(*param_1 + 0x20);
      puVar4 = (undefined4 *)&stack0xfffff940;
      pppIVar12 = local_1b8;
      do {
        iVar9 = iVar9 + -4;
        *puVar4 = *pppIVar12;
        puVar4 = puVar4 + 1;
        pppIVar12 = pppIVar12 + 1;
      } while (iVar9 != 0);
      goto LAB_0000e46c;
    }
    break;
  case (Parcel *)0x6:
    iVar9 = android::Parcel::checkInterface(param_3);
    if (iVar9 != 0) {
      local_390 = param_1;
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)&local_354);
      sp<>::~sp((sp<> *)&local_1bc);
      __aeabi_memclr4(local_1b8,400);
      ppIVar5 = (ImageBuf **)android::Parcel::readInt32();
      local_1bc = ppIVar5;
      if (ppIVar5 != (ImageBuf **)0x0) {
        ppIVar16 = (ImageBuf **)0x0;
        pppIVar12 = local_1b8;
        do {
          ppIVar6 = (ImageBuf **)android::Parcel::readFileDescriptor();
          ppIVar16 = (ImageBuf **)((int)ppIVar16 + 1);
          *pppIVar12 = ppIVar6;
          pppIVar12 = pppIVar12 + 1;
        } while (ppIVar16 != ppIVar5);
      }
      local_38c = param_4;
      if (local_354 != 0) {
        local_38 = android::IMemory::size();
        local_34 = android::IMemory::pointer();
      }
      uVar1 = android::Parcel::readInt32();
      android::VectorImpl::VectorImpl((VectorImpl *)&local_368,4,7);
      local_368 = &PTR__Vector_1_00017cfc;
      if (uVar1 != 0) {
        uVar17 = 0;
LAB_0000e520:
        iVar9 = android::Parcel::readUint32();
        uVar2 = android::Parcel::readUint32();
        uVar10 = android::Parcel::readInt32();
        uVar3 = android::Parcel::readNativeHandle();
        pIVar7 = cacao::ObjectBase::operator_new((ObjectBase *)0x28);
        local_350[0] = cacao::ImageBuf::ImageBuf(pIVar7,uVar3,iVar9,uVar2,uVar10,0);
        if (local_350[0] != (ImageBuf *)0x0) goto code_r0x0000e562;
        local_350[0] = (ImageBuf *)0x0;
        if (local_360 != 0) {
          uVar17 = 0;
          uVar1 = local_360;
          do {
            piVar11 = *(int **)(local_364 + uVar17 * 4);
            if (piVar11 != (int *)0x0) {
              (**(code **)(*piVar11 + 4))();
              uVar1 = local_360;
            }
            uVar17 = uVar17 + 1;
          } while (uVar17 < uVar1);
        }
        uVar10 = 0xfffffff4;
        goto LAB_0000e86a;
      }
LAB_0000e574:
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)&local_36c);
      sp<>::~sp((sp<> *)local_350);
      __aeabi_memclr4(local_350 + 1,400);
      pIVar7 = (ImageBuf *)android::Parcel::readInt32();
      local_350[0] = pIVar7;
      if (pIVar7 != (ImageBuf *)0x0) {
        pIVar13 = (ImageBuf *)0x0;
        ppIVar5 = local_350 + 1;
        do {
          pIVar8 = (ImageBuf *)android::Parcel::readFileDescriptor();
          pIVar13 = pIVar13 + 1;
          *ppIVar5 = pIVar8;
          ppIVar5 = ppIVar5 + 1;
        } while (pIVar13 != pIVar7);
      }
      if (local_36c != 0) {
        local_1cc = android::IMemory::size();
        local_1c8 = android::IMemory::pointer();
      }
      uVar10 = android::Parcel::readInt32();
      android::Parcel::readStrongBinder();
      ICacaoProcessCallback::asInterface(aIStack_370,&local_374);
      sp<>::~sp((sp<> *)&local_374);
      piVar11 = local_390;
      pcVar15 = *(code **)(*local_390 + 0x24);
      android::VectorImpl::VectorImpl((VectorImpl *)local_388,(VectorImpl *)&local_368);
      iVar9 = 0x18c;
      pppIVar12 = local_1b8;
      puVar4 = (undefined4 *)&stack0xfffff940;
      local_398 = uVar10;
      pIStack_394 = aIStack_370;
      local_388[0] = &PTR__Vector_1_00017cfc;
      do {
        pppIVar12 = pppIVar12 + 1;
        iVar9 = iVar9 + -4;
        *puVar4 = *pppIVar12;
        puVar4 = puVar4 + 1;
      } while (iVar9 != 0);
      iVar9 = 0x194;
      puVar4 = auStack_52c;
      psVar14 = (sp<> *)local_350;
      do {
        iVar9 = iVar9 + -4;
        *puVar4 = *(undefined4 *)psVar14;
        puVar4 = puVar4 + 1;
        psVar14 = psVar14 + 4;
      } while (iVar9 != 0);
      uVar10 = (*pcVar15)(piVar11,&local_354,local_1bc,local_1b8[0]);
      local_388[0] = &PTR__Vector_1_00017cfc;
      android::VectorImpl::finish_vector();
      android::VectorImpl::~VectorImpl((VectorImpl *)local_388);
      local_374 = uVar10;
      android::Parcel::write(local_38c,(uint)&local_374);
      sp<>::~sp((sp<> *)aIStack_370);
      sp<>::~sp((sp<> *)&local_36c);
      uVar10 = 0;
LAB_0000e86a:
      local_368 = &PTR__Vector_1_00017cfc;
      android::VectorImpl::finish_vector();
      android::VectorImpl::~VectorImpl((VectorImpl *)&local_368);
      sp<>::~sp((sp<> *)&local_354);
      goto LAB_0000e82a;
    }
    break;
  case (Parcel *)0x7:
    iVar9 = android::Parcel::checkInterface(param_3);
    if (iVar9 != 0) {
      local_38c = param_4;
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)&local_368);
      sp<>::~sp((sp<> *)&local_1bc);
      __aeabi_memclr4(local_1b8,400);
      ppIVar5 = (ImageBuf **)android::Parcel::readInt32();
      local_1bc = ppIVar5;
      if (ppIVar5 != (ImageBuf **)0x0) {
        ppIVar16 = (ImageBuf **)0x0;
        pppIVar12 = local_1b8;
        do {
          ppIVar6 = (ImageBuf **)android::Parcel::readFileDescriptor();
          ppIVar16 = (ImageBuf **)((int)ppIVar16 + 1);
          *pppIVar12 = ppIVar6;
          pppIVar12 = pppIVar12 + 1;
        } while (ppIVar16 != ppIVar5);
      }
      if (local_368 != (undefined **)0x0) {
        local_38 = android::IMemory::size();
        local_34 = android::IMemory::pointer();
      }
      android::Parcel::readStrongBinder();
      android::Parcel::readStrongBinder();
      android::IMemory::asInterface((sp *)&local_36c);
      sp<>::~sp((sp<> *)local_350);
      __aeabi_memclr4(local_350 + 1,400);
      pIVar7 = (ImageBuf *)android::Parcel::readInt32();
      local_350[0] = pIVar7;
      if (pIVar7 != (ImageBuf *)0x0) {
        pIVar13 = (ImageBuf *)0x0;
        ppIVar5 = local_350 + 1;
        do {
          pIVar8 = (ImageBuf *)android::Parcel::readFileDescriptor();
          pIVar13 = pIVar13 + 1;
          *ppIVar5 = pIVar8;
          ppIVar5 = ppIVar5 + 1;
        } while (pIVar13 != pIVar7);
      }
      if (local_36c != 0) {
        local_1cc = android::IMemory::size();
        local_1c8 = android::IMemory::pointer();
      }
      uVar10 = android::Parcel::readInt32();
      android::Parcel::readStrongBinder();
      ICacaoProcessCallback::asInterface(aIStack_370,&local_374);
      sp<>::~sp((sp<> *)&local_374);
      iVar9 = 0x18c;
      pcVar15 = *(code **)(*param_1 + 0x28);
      pppIVar12 = local_1b8;
      puVar4 = (undefined4 *)&stack0xfffff940;
      local_398 = uVar10;
      pIStack_394 = aIStack_370;
      do {
        pppIVar12 = pppIVar12 + 1;
        iVar9 = iVar9 + -4;
        *puVar4 = *pppIVar12;
        ppIVar5 = local_38c;
        puVar4 = puVar4 + 1;
      } while (iVar9 != 0);
      iVar9 = 0x194;
      puVar4 = auStack_52c;
      psVar14 = (sp<> *)local_350;
      do {
        iVar9 = iVar9 + -4;
        *puVar4 = *(undefined4 *)psVar14;
        puVar4 = puVar4 + 1;
        psVar14 = psVar14 + 4;
      } while (iVar9 != 0);
      psVar14 = (sp<> *)&local_368;
      local_374 = (*pcVar15)(param_1,psVar14,local_1bc,local_1b8[0]);
      android::Parcel::write(ppIVar5,(uint)&local_374);
      sp<>::~sp((sp<> *)aIStack_370);
      sp<>::~sp((sp<> *)&local_36c);
      sp<>::~sp((sp<> *)&local_354);
      goto LAB_0000e7f4;
    }
    break;
  case (Parcel *)0x8:
    iVar9 = android::Parcel::checkInterface(param_3);
    if (iVar9 != 0) {
      uVar10 = android::Parcel::readIntPtr();
      (**(code **)(*param_1 + 0x2c))(param_1,uVar10);
      goto LAB_0000e81a;
    }
    break;
  default:
    uVar10 = android::BBinder::onTransact
                       ((uint)(param_1 + 1),param_2,(Parcel *)param_3,(uint)param_4);
    return uVar10;
  }
  uVar10 = 0xffffffff;
LAB_0000e82a:
  if (__stack_chk_guard == local_28) {
    return uVar10;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
code_r0x0000e562:
  android::VectorImpl::insertAt(&local_368,(uint)local_350,local_360);
  uVar17 = uVar17 + 1;
  if (uVar1 <= uVar17) goto LAB_0000e574;
  goto LAB_0000e520;
}



// android::Vector<cacao::ImageBuf*>::~Vector()

void __thiscall android::Vector<>::~Vector(Vector<> *this)

{
  *(undefined ***)this = &PTR__Vector_1_00017cfc;
  android::VectorImpl::finish_vector();
  android::VectorImpl::~VectorImpl((VectorImpl *)this);
  return;
}



// non-virtual thunk to android::BnCacao::onTransact(unsigned int, android::Parcel const&,
// android::Parcel*, unsigned int)

void __thiscall android::BnCacao::onTransact(BnCacao *this)

{
  Parcel *in_r1;
  IBinder *in_r2;
  ImageBuf **in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BnInterface<android::ICacao>::queryLocalInterface(android::String16 const&)

void __cdecl
android::BnInterface<>::queryLocalInterface(sp<> *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *param_3;
  uVar2 = android::String16::size();
  uVar1 = ICacao::descriptor;
  uVar3 = android::String16::size();
  iVar4 = strzcmp16(uVar5,uVar2,uVar1,uVar3);
  if (iVar4 != 0) {
    *(undefined4 *)param_1 = 0;
    return;
  }
  sp<>::sp<>(param_1,param_2);
  return;
}



// non-virtual thunk to android::BnInterface<android::ICacao>::queryLocalInterface(android::String16
// const&)

void __thiscall
android::BnInterface<>::queryLocalInterface(BnInterface<> *this,int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *param_2;
  uVar2 = android::String16::size();
  uVar1 = ICacao::descriptor;
  uVar3 = android::String16::size();
  iVar4 = strzcmp16(uVar5,uVar2,uVar1,uVar3);
  if (iVar4 != 0) {
    *(undefined4 *)this = 0;
    return;
  }
  sp<>::sp<>((sp<> *)this,(int *)(param_1 + -4));
  return;
}



// android::BpCacao::~BpCacao()

BpCacao * __thiscall android::BpCacao::~BpCacao(BpCacao *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)(this + 4));
  android::IInterface::~IInterface((IInterface *)this);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  return this;
}



// android::BpCacao::~BpCacao()

void __thiscall android::BpCacao::~BpCacao(BpCacao *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)(this + 4));
  android::IInterface::~IInterface((IInterface *)this);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  operator_delete(this);
  return;
}



// android::BpCacao::disconnect()

void __thiscall android::BpCacao::disconnect(BpCacao *this)

{
  Parcel aPStack_a8 [72];
  Parcel aPStack_60 [72];
  int local_18;
  
  local_18 = __stack_chk_guard;
  android::Parcel::Parcel(aPStack_60);
  android::Parcel::Parcel(aPStack_a8);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_60);
  (**(code **)(**(int **)(this + 8) + 0x14))(*(int **)(this + 8),1,aPStack_60,aPStack_a8,0);
  android::Parcel::~Parcel(aPStack_a8);
  android::Parcel::~Parcel(aPStack_60);
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BpCacao::start(android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)

undefined4 __cdecl android::BpCacao::start(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  sp<> asStack_c0 [4];
  sp asStack_bc [4];
  Parcel aPStack_b8 [72];
  Parcel aPStack_70 [72];
  int local_28;
  int local_8;
  int iStack_4;
  
  local_28 = __stack_chk_guard;
  local_8 = param_3;
  iStack_4 = param_4;
  android::Parcel::Parcel(aPStack_70);
  android::Parcel::Parcel(aPStack_b8);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_70);
  sp<>::sp<>(asStack_c0,param_2);
  android::IInterface::asBinder(asStack_bc);
  android::Parcel::writeStrongBinder((sp *)aPStack_70);
  sp<>::~sp((sp<> *)asStack_bc);
  sp<>::~sp((sp<> *)asStack_c0);
  iVar1 = local_8;
  android::Parcel::writeInt32((int)aPStack_70);
  if (iVar1 != 0) {
    piVar4 = &local_8;
    iVar3 = 0;
    do {
      piVar4 = piVar4 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_70,SUB41(*piVar4,0));
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar1);
  }
  (**(code **)(**(int **)(param_1 + 8) + 0x14))(*(int **)(param_1 + 8),2,aPStack_70,aPStack_b8,0);
  uVar2 = android::Parcel::readInt32();
  android::Parcel::~Parcel(aPStack_b8);
  android::Parcel::~Parcel(aPStack_70);
  if (__stack_chk_guard == local_28) {
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacao::stop()

undefined4 __thiscall android::BpCacao::stop(BpCacao *this)

{
  undefined4 uVar1;
  Parcel aPStack_a8 [72];
  Parcel aPStack_60 [72];
  int local_18;
  
  local_18 = __stack_chk_guard;
  android::Parcel::Parcel(aPStack_60);
  android::Parcel::Parcel(aPStack_a8);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_60);
  (**(code **)(**(int **)(this + 8) + 0x14))(*(int **)(this + 8),3,aPStack_60,aPStack_a8,0);
  uVar1 = android::Parcel::readInt32();
  android::Parcel::~Parcel(aPStack_a8);
  android::Parcel::~Parcel(aPStack_60);
  if (__stack_chk_guard == local_18) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacao::setConfig(int, android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData)

undefined4 __thiscall
android::BpCacao::setConfig(BpCacao *this,undefined4 param_2_00,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  sp<> asStack_bc [4];
  sp asStack_b8 [4];
  Parcel aPStack_b4 [72];
  Parcel aPStack_6c [72];
  int local_24;
  int local_4;
  
  local_24 = __stack_chk_guard;
  local_4 = param_3;
  android::Parcel::Parcel(aPStack_6c);
  android::Parcel::Parcel(aPStack_b4);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_6c);
  android::Parcel::writeInt32((int)aPStack_6c);
  sp<>::sp<>(asStack_bc,param_2);
  android::IInterface::asBinder(asStack_b8);
  android::Parcel::writeStrongBinder((sp *)aPStack_6c);
  sp<>::~sp((sp<> *)asStack_b8);
  sp<>::~sp((sp<> *)asStack_bc);
  iVar1 = local_4;
  android::Parcel::writeInt32((int)aPStack_6c);
  if (iVar1 != 0) {
    piVar4 = &local_4;
    iVar3 = 0;
    do {
      piVar4 = piVar4 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_6c,SUB41(*piVar4,0));
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar1);
  }
  (**(code **)(**(int **)(this + 8) + 0x14))(*(int **)(this + 8),4,aPStack_6c,aPStack_b4,0);
  uVar2 = android::Parcel::readInt32();
  android::Parcel::~Parcel(aPStack_b4);
  android::Parcel::~Parcel(aPStack_6c);
  if (__stack_chk_guard == local_24) {
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacao::getConfig(int, android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData)

undefined4 __thiscall
android::BpCacao::getConfig(BpCacao *this,undefined4 param_2_00,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  sp<> asStack_bc [4];
  sp asStack_b8 [4];
  Parcel aPStack_b4 [72];
  Parcel aPStack_6c [72];
  int local_24;
  int local_4;
  
  local_24 = __stack_chk_guard;
  local_4 = param_3;
  android::Parcel::Parcel(aPStack_6c);
  android::Parcel::Parcel(aPStack_b4);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_6c);
  android::Parcel::writeInt32((int)aPStack_6c);
  sp<>::sp<>(asStack_bc,param_2);
  android::IInterface::asBinder(asStack_b8);
  android::Parcel::writeStrongBinder((sp *)aPStack_6c);
  sp<>::~sp((sp<> *)asStack_b8);
  sp<>::~sp((sp<> *)asStack_bc);
  iVar1 = local_4;
  android::Parcel::writeInt32((int)aPStack_6c);
  if (iVar1 != 0) {
    piVar4 = &local_4;
    iVar3 = 0;
    do {
      piVar4 = piVar4 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_6c,SUB41(*piVar4,0));
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar1);
  }
  (**(code **)(**(int **)(this + 8) + 0x14))(*(int **)(this + 8),5,aPStack_6c,aPStack_b4,0);
  uVar2 = android::Parcel::readInt32();
  android::Parcel::~Parcel(aPStack_b4);
  android::Parcel::~Parcel(aPStack_6c);
  if (__stack_chk_guard == local_24) {
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BpCacao::process(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData, android::Vector<cacao::ImageBuf*>,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData, int,
// android::sp<android::ICacaoProcessCallback> const&)

undefined4 __cdecl
android::BpCacao::process(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_stack_0000018c;
  int *in_stack_00000190;
  int in_stack_00000194;
  int *in_stack_0000032c;
  sp local_c8 [8];
  sp<> asStack_c0 [4];
  Parcel aPStack_bc [72];
  Parcel aPStack_74 [72];
  int local_8;
  int iStack_4;
  
  iVar1 = __stack_chk_guard;
  local_8 = param_3;
  iStack_4 = param_4;
  android::Parcel::Parcel(aPStack_74);
  android::Parcel::Parcel(aPStack_bc);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_74);
  sp<>::sp<>(asStack_c0,param_2);
  android::IInterface::asBinder(local_c8);
  android::Parcel::writeStrongBinder((sp *)aPStack_74);
  sp<>::~sp((sp<> *)local_c8);
  sp<>::~sp((sp<> *)asStack_c0);
  iVar6 = local_8;
  android::Parcel::writeInt32((int)aPStack_74);
  puVar7 = &stack0x00000194;
  if (iVar6 != 0) {
    piVar5 = &local_8;
    iVar3 = 0;
    do {
      piVar5 = piVar5 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_74,SUB41(*piVar5,0));
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar6);
  }
  android::Parcel::writeInt32((int)aPStack_74);
  if (*(int *)(in_stack_0000018c + 8) != 0) {
    uVar4 = 0;
    do {
      (**(code **)(**(int **)(*(int *)(in_stack_0000018c + 4) + uVar4 * 4) + 0x1c))(local_c8);
      android::Parcel::writeUint32((uint)aPStack_74);
      (**(code **)(**(int **)(*(int *)(in_stack_0000018c + 4) + uVar4 * 4) + 0x1c))(local_c8);
      android::Parcel::writeUint32((uint)aPStack_74);
      (**(code **)(**(int **)(*(int *)(in_stack_0000018c + 4) + uVar4 * 4) + 0x3c))();
      android::Parcel::writeInt32((int)aPStack_74);
      (**(code **)(**(int **)(*(int *)(in_stack_0000018c + 4) + uVar4 * 4) + 0x10))();
      android::Parcel::writeNativeHandle((native_handle *)aPStack_74);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_stack_0000018c + 8));
  }
  sp<>::sp<>(asStack_c0,in_stack_00000190);
  android::IInterface::asBinder(local_c8);
  android::Parcel::writeStrongBinder((sp *)aPStack_74);
  sp<>::~sp((sp<> *)local_c8);
  sp<>::~sp((sp<> *)asStack_c0);
  android::Parcel::writeInt32((int)aPStack_74);
  if (in_stack_00000194 != 0) {
    iVar6 = 0;
    do {
      puVar7 = puVar7 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_74,SUB41(*puVar7,0));
      iVar6 = iVar6 + 1;
    } while (iVar6 != in_stack_00000194);
  }
  android::Parcel::writeInt32((int)aPStack_74);
  sp<>::sp<>(asStack_c0,in_stack_0000032c);
  android::IInterface::asBinder(local_c8);
  android::Parcel::writeStrongBinder((sp *)aPStack_74);
  sp<>::~sp((sp<> *)local_c8);
  sp<>::~sp((sp<> *)asStack_c0);
  (**(code **)(**(int **)(param_1 + 8) + 0x14))
            (*(int **)(param_1 + 8),6,(sp *)aPStack_74,aPStack_bc,0);
  uVar2 = android::Parcel::readIntPtr();
  android::Parcel::~Parcel(aPStack_bc);
  android::Parcel::~Parcel(aPStack_74);
  if (__stack_chk_guard == iVar1) {
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BpCacao::process(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData, android::sp<android::IBinder> const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData, int,
// android::sp<android::ICacaoProcessCallback> const&)

undefined4 __cdecl
android::BpCacao::process(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *in_stack_00000190;
  int in_stack_00000194;
  int *in_stack_0000032c;
  sp<> asStack_c8 [4];
  sp asStack_c4 [4];
  Parcel aPStack_c0 [72];
  Parcel aPStack_78 [72];
  int local_30;
  int local_8;
  int iStack_4;
  
  local_30 = __stack_chk_guard;
  local_8 = param_3;
  iStack_4 = param_4;
  android::Parcel::Parcel(aPStack_78);
  android::Parcel::Parcel(aPStack_c0);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_78);
  sp<>::sp<>(asStack_c8,param_2);
  android::IInterface::asBinder(asStack_c4);
  android::Parcel::writeStrongBinder((sp *)aPStack_78);
  sp<>::~sp((sp<> *)asStack_c4);
  sp<>::~sp((sp<> *)asStack_c8);
  iVar3 = local_8;
  android::Parcel::writeInt32((int)aPStack_78);
  puVar5 = &stack0x00000194;
  if (iVar3 != 0) {
    piVar4 = &local_8;
    iVar2 = 0;
    do {
      piVar4 = piVar4 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_78,SUB41(*piVar4,0));
      iVar2 = iVar2 + 1;
    } while (iVar2 != iVar3);
  }
  android::Parcel::writeStrongBinder((sp *)aPStack_78);
  sp<>::sp<>(asStack_c8,in_stack_00000190);
  android::IInterface::asBinder(asStack_c4);
  android::Parcel::writeStrongBinder((sp *)aPStack_78);
  sp<>::~sp((sp<> *)asStack_c4);
  sp<>::~sp((sp<> *)asStack_c8);
  android::Parcel::writeInt32((int)aPStack_78);
  if (in_stack_00000194 != 0) {
    iVar3 = 0;
    do {
      puVar5 = puVar5 + 1;
      android::Parcel::writeFileDescriptor((int)aPStack_78,SUB41(*puVar5,0));
      iVar3 = iVar3 + 1;
    } while (iVar3 != in_stack_00000194);
  }
  android::Parcel::writeInt32((int)aPStack_78);
  sp<>::sp<>(asStack_c8,in_stack_0000032c);
  android::IInterface::asBinder(asStack_c4);
  android::Parcel::writeStrongBinder((sp *)aPStack_78);
  sp<>::~sp((sp<> *)asStack_c4);
  sp<>::~sp((sp<> *)asStack_c8);
  (**(code **)(**(int **)(param_1 + 8) + 0x14))
            (*(int **)(param_1 + 8),7,(sp *)aPStack_78,aPStack_c0,0);
  uVar1 = android::Parcel::readIntPtr();
  android::Parcel::~Parcel(aPStack_c0);
  android::Parcel::~Parcel(aPStack_78);
  if (__stack_chk_guard == local_30) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::BpCacao::cancel(int)

undefined4 __thiscall android::BpCacao::cancel(BpCacao *this,undefined4 param_1)

{
  undefined4 uVar1;
  Parcel aPStack_b0 [72];
  undefined4 local_68;
  int local_64;
  Parcel aPStack_5c [72];
  
  local_64 = __stack_chk_guard;
  local_68 = param_1;
  android::Parcel::Parcel(aPStack_5c);
  android::Parcel::Parcel(aPStack_b0);
  android::Parcel::writeInterfaceToken((String16 *)aPStack_5c);
  android::Parcel::write(aPStack_5c,(uint)&local_68);
  (**(code **)(**(int **)(this + 8) + 0x14))(*(int **)(this + 8),8,aPStack_5c,aPStack_b0,0);
  uVar1 = android::Parcel::readInt32();
  android::Parcel::~Parcel(aPStack_b0);
  android::Parcel::~Parcel(aPStack_5c);
  if (__stack_chk_guard == local_64) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::BpCacao::~BpCacao()

void __thiscall android::BpCacao::~BpCacao(BpCacao *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)this);
  android::IInterface::~IInterface((IInterface *)(this + -4));
  android::RefBase::~RefBase((RefBase *)(this + 0x10));
  return;
}



// non-virtual thunk to android::BpCacao::~BpCacao()

void __thiscall android::BpCacao::~BpCacao(BpCacao *this)

{
  android::BpRefBase::~BpRefBase((BpRefBase *)this);
  android::IInterface::~IInterface((IInterface *)(this + -4));
  android::RefBase::~RefBase((RefBase *)(this + 0x10));
  operator_delete((IInterface *)(this + -4));
  return;
}



// virtual thunk to android::BpCacao::~BpCacao()

void __thiscall android::BpCacao::~BpCacao(BpCacao *this)

{
  IInterface *this_00;
  
  this_00 = (IInterface *)(this + *(int *)(*(int *)this + -0xc));
  android::BpRefBase::~BpRefBase((BpRefBase *)(this_00 + 4));
  android::IInterface::~IInterface(this_00);
  android::RefBase::~RefBase((RefBase *)(this_00 + 0x14));
  return;
}



// virtual thunk to android::BpCacao::~BpCacao()

void __thiscall android::BpCacao::~BpCacao(BpCacao *this)

{
  IInterface *this_00;
  
  this_00 = (IInterface *)(this + *(int *)(*(int *)this + -0xc));
  android::BpRefBase::~BpRefBase((BpRefBase *)(this_00 + 4));
  android::IInterface::~IInterface(this_00);
  android::RefBase::~RefBase((RefBase *)(this_00 + 0x14));
  operator_delete(this_00);
  return;
}



// android::Vector<cacao::ImageBuf*>::~Vector()

void __thiscall android::Vector<>::~Vector(Vector<> *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__Vector_1_00017cfc;
  android::VectorImpl::finish_vector();
  pvVar1 = (void *)android::VectorImpl::~VectorImpl((VectorImpl *)this);
  operator_delete(pvVar1);
  return;
}



// libunwind::AbstractUnwindCursor::~AbstractUnwindCursor()

void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  return;
}



// android::Vector<cacao::ImageBuf*>::do_copy(void*, void const*, unsigned int) const

void __thiscall
android::Vector<>::do_copy(undefined4 param_1_00,undefined4 param_2,undefined4 param_3,int param_4)

{
  __aeabi_memcpy(param_2,param_3,param_4 << 2);
  return;
}



// android::Vector<cacao::ImageBuf*>::do_splat(void*, void const*, unsigned int) const

void __thiscall
android::Vector<>::do_splat
          (undefined4 param_1_00,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  for (; param_4 != 0; param_4 = param_4 + -1) {
    *param_2 = *param_3;
    param_2 = param_2 + 1;
  }
  return;
}



// android::Vector<cacao::ImageBuf*>::do_move_backward(void*, void const*, unsigned int) const

void __thiscall
android::Vector<>::do_move_backward
          (undefined4 param_1_00,undefined4 param_2,undefined4 param_3,int param_4)

{
  __aeabi_memmove(param_2,param_3,param_4 << 2);
  return;
}



// android::Mutex::~Mutex()

Mutex * __thiscall android::Mutex::~Mutex(Mutex *this)

{
  pthread_mutex_destroy((pthread_mutex_t *)this);
  return this;
}



// android::Cacao::CacaoProcessCallback::CacaoProcessCallback(cacao::ICBProcessResultListener*,
// cacao::ProcessResultBase*)

CacaoProcessCallback * __thiscall
android::Cacao::CacaoProcessCallback::CacaoProcessCallback
          (CacaoProcessCallback *this,int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  ICacaoClient::ICacaoClient((ICacaoClient *)this,param_1 + 3);
  android::BBinder::BBinder((BBinder *)(this + 4));
  iVar1 = param_1[2];
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0xb];
  *(int *)(this + 4) = param_1[0xc];
  iVar1 = param_1[1];
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0xd];
  *(int *)(this + 4) = param_1[0xe];
  iVar1 = *param_1;
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0xf];
  iVar1 = param_1[0x10];
  *(undefined4 *)(this + 0x10) = param_2;
  *(undefined4 *)(this + 0x14) = param_3;
  *(int *)(this + 4) = iVar1;
  return this;
}



// android::Cacao::CacaoProcessCallback::CacaoProcessCallback(cacao::ICBProcessResultListener*,
// cacao::ProcessResultBase*)

CacaoProcessCallback * __thiscall
android::Cacao::CacaoProcessCallback::CacaoProcessCallback
          (CacaoProcessCallback *this,undefined4 param_1,undefined4 param_2)

{
  android::RefBase::RefBase((RefBase *)(this + 0x18));
  ICacaoClient::ICacaoClient((ICacaoClient *)this,(int *)&PTR_construction_vtable_12__00017dd8);
  android::BBinder::BBinder((BBinder *)(this + 4));
  *(undefined4 *)this = 0x17d28;
  *(undefined4 *)(this + 4) = 0x17d54;
  *(undefined4 *)(this + 0x10) = param_1;
  *(undefined4 *)(this + 0x14) = param_2;
  *(undefined4 *)(this + 0x18) = 0x17db4;
  return this;
}



// android::Cacao::CacaoProcessCallback::~CacaoProcessCallback()

void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0xf];
  *(int *)(this + 4) = param_1[0x10];
  android::BBinder::~BBinder((BBinder *)(this + 4));
  ICacaoProcessCallback::~ICacaoProcessCallback((ICacaoProcessCallback *)this);
  return;
}



// android::Cacao::CacaoProcessCallback::~CacaoProcessCallback()

CacaoProcessCallback * __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x18));
  return this;
}



// non-virtual thunk to android::Cacao::CacaoProcessCallback::~CacaoProcessCallback()

void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this + -4,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  return;
}



// virtual thunk to android::Cacao::CacaoProcessCallback::~CacaoProcessCallback()

void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  int iVar1;
  
  iVar1 = ~CacaoProcessCallback(this + *(int *)(*(int *)this + -0xc),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x18));
  return;
}



// android::Cacao::CacaoProcessCallback::~CacaoProcessCallback()

void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x18));
  operator_delete(this);
  return;
}



// non-virtual thunk to android::Cacao::CacaoProcessCallback::~CacaoProcessCallback()

void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this + -4);
  return;
}



// virtual thunk to android::Cacao::CacaoProcessCallback::~CacaoProcessCallback()

void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this)

{
  ~CacaoProcessCallback(this + *(int *)(*(int *)this + -0xc));
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::CacaoProcessCallback::notifyProgress(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData)

void __cdecl
android::Cacao::CacaoProcessCallback::notifyProgress
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = *(int **)(param_1 + 0x10);
  piVar1 = *(int **)(param_1 + 0x14);
  local_8 = param_3;
  uStack_4 = param_4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x2c))(piVar1,&local_8);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,*(undefined4 *)(param_1 + 0x14));
  }
  return;
}



// android::Cacao::CacaoProcessCallback::notifyResult(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData, android::Vector<cacao::ImageBuf*>*)

void __thiscall
android::Cacao::CacaoProcessCallback::notifyResult
          (CacaoProcessCallback *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = *(int **)(this + 0x10);
  piVar1 = *(int **)(this + 0x14);
  local_8 = param_2;
  uStack_4 = param_3;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x2c))(piVar1,&local_8);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,*(undefined4 *)(this + 0x14));
  }
  return;
}



// android::Cacao::CacaoClient::CacaoClient()

CacaoClient * __thiscall android::Cacao::CacaoClient::CacaoClient(CacaoClient *this,int *param_1)

{
  int iVar1;
  
  ICacaoClient::ICacaoClient((ICacaoClient *)this,param_1 + 3);
  android::BBinder::BBinder((BBinder *)(this + 4));
  iVar1 = param_1[2];
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0xb];
  *(int *)(this + 4) = param_1[0xc];
  iVar1 = param_1[1];
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0xd];
  *(int *)(this + 4) = param_1[0xe];
  iVar1 = param_1[0xf];
  *(int *)(this + 0x10) = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc) + 0x10) = param_1[0x10];
  *(undefined ***)(this + 0x14) = &PTR__AbstractUnwindCursor_1_000186f4;
  iVar1 = *param_1;
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0x11];
  *(int *)(this + 4) = param_1[0x12];
  *(int *)(this + 0x10) = param_1[0x13];
  *(undefined4 *)(this + 0x14) = 98000;
  *(undefined4 *)(this + 0x18) = 0;
  pthread_mutex_init((pthread_mutex_t *)(this + 0x1c),(pthread_mutexattr_t *)0x0);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  return this;
}



// android::Cacao::CacaoClient::CacaoClient()

CacaoClient * __thiscall android::Cacao::CacaoClient::CacaoClient(CacaoClient *this)

{
  android::RefBase::RefBase((RefBase *)(this + 0x28));
  ICacaoClient::ICacaoClient((ICacaoClient *)this,(int *)&PTR_construction_vtable_12__00017f3c);
  android::BBinder::BBinder((BBinder *)(this + 4));
  *(undefined4 *)(this + 0x28) = 0x17f18;
  *(undefined4 *)this = 0x17e1c;
  *(undefined4 *)(this + 4) = 0x17e6c;
  *(undefined4 *)(this + 0x10) = 0x17ebc;
  *(undefined4 *)(this + 0x14) = 98000;
  *(undefined4 *)(this + 0x18) = 0;
  pthread_mutex_init((pthread_mutex_t *)(this + 0x1c),(pthread_mutexattr_t *)0x0);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  return this;
}



// android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0x11];
  *(int *)(this + 4) = param_1[0x12];
  *(int *)(this + 0x10) = param_1[0x13];
  *(undefined4 *)(this + 0x14) = 98000;
  pthread_mutex_destroy((pthread_mutex_t *)(this + 0x1c));
  sp<>::~sp((sp<> *)(this + 0x18));
  android::BBinder::~BBinder((BBinder *)(this + 4));
  ICacaoProcessCallback::~ICacaoProcessCallback((ICacaoProcessCallback *)this);
  return;
}



// android::Cacao::CacaoClient::~CacaoClient()

CacaoClient * __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x28));
  return this;
}



// non-virtual thunk to android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -4,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x24));
  return;
}



// non-virtual thunk to android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -0x10,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x18));
  return;
}



// non-virtual thunk to android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -0x14,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x14));
  return;
}



// virtual thunk to android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  int iVar1;
  
  iVar1 = ~CacaoClient(this + *(int *)(*(int *)this + -0xc),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x28));
  return;
}



// android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x28));
  operator_delete(this);
  return;
}



// non-virtual thunk to android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -4);
  return;
}



// non-virtual thunk to android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -0x10);
  return;
}



// non-virtual thunk to android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + -0x14);
  return;
}



// virtual thunk to android::Cacao::CacaoClient::~CacaoClient()

void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this)

{
  ~CacaoClient(this + *(int *)(*(int *)this + -0xc));
  return;
}



// android::Cacao::CacaoClient::connect(android::sp<android::ICacaoService> const&)

undefined4 __thiscall android::Cacao::CacaoClient::connect(CacaoClient *this,undefined4 *param_1)

{
  sp<> *this_00;
  int *piVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  int *local_34;
  sp<> asStack_30 [4];
  sp<> asStack_2c [4];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  piVar1 = (int *)*param_1;
  uVar4 = 0;
  if (piVar1 == (int *)0x0) {
    uVar4 = 0xffffff99;
  }
  this_00 = (sp<> *)(this + 0x18);
  uVar2 = uVar4;
  if (*(int *)this_00 != 0) {
    uVar2 = 0xffffff95;
  }
  if ((piVar1 != (int *)0x0) && (*(int *)this_00 == 0)) {
    pcVar3 = *(code **)(*piVar1 + 0x10);
    sp<>::sp<>(asStack_30,(int *)this);
    (*pcVar3)(asStack_2c,piVar1,asStack_30);
    sp<>::operator=(this_00,(undefined4 *)asStack_2c);
    sp<>::~sp(asStack_2c);
    sp<>::~sp((sp<> *)asStack_30);
    if (*(int *)(this + 0x18) == 0) {
      uVar2 = 0xffffff91;
    }
    else {
      sp<>::sp<>((sp<> *)asStack_2c,(int *)this_00);
      android::IInterface::asBinder((sp *)&local_34);
      pcVar3 = *(code **)(*local_34 + 0x18);
      sp<>::sp<>((sp<> *)asStack_30,(int *)this);
      (*pcVar3)(local_34,(sp<> *)asStack_30,0,0);
      sp<>::~sp((sp<> *)asStack_30);
      sp<>::~sp((sp<> *)&local_34);
      sp<>::~sp(asStack_2c);
      uVar2 = uVar4;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  if (__stack_chk_guard == local_28) {
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::sp<android::IMemory>::TEMPNAMEPLACEHOLDERVALUE(android::sp<android::IMemory>&&)

sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)this;
  if (piVar1 != (int *)0x0) {
    android::RefBase::decStrong((void *)(*(int *)(*piVar1 + -0xc) + (int)piVar1));
  }
  if (piVar1 != *(int **)this) {
    android::sp_report_race();
  }
  *(undefined4 *)this = *param_1;
  *param_1 = 0;
  return this;
}



// android::sp<android::IBinder::DeathRecipient>::sp<android::Cacao::CacaoClient>(android::Cacao::CacaoClient*)

sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1 + 4;
  piVar2 = param_1;
  if (param_1 != (int *)0x0) {
    piVar2 = piVar1;
  }
  *(int **)this = piVar2;
  if (param_1 != (int *)0x0) {
    android::RefBase::incStrong((void *)((int)piVar1 + *(int *)(*piVar1 + -0xc)));
  }
  return this;
}



// android::Cacao::CacaoClient::disconnect()

void __thiscall android::Cacao::CacaoClient::disconnect(CacaoClient *this)

{
  sp<> *this_00;
  code *pcVar1;
  wp<> awStack_38 [8];
  sp<> asStack_30 [4];
  int *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  this_00 = (sp<> *)(this + 0x18);
  if (*(int *)this_00 != 0) {
    sp<>::sp<>(asStack_30,(int *)this_00);
    android::IInterface::asBinder((sp *)&local_2c);
    pcVar1 = *(code **)(*local_2c + 0x1c);
    wp<>::wp<>(awStack_38,(int *)this);
    (*pcVar1)(local_2c,awStack_38,0,0,0);
    wp<>::~wp(awStack_38);
    sp<>::~sp((sp<> *)&local_2c);
    sp<>::~sp((sp<> *)asStack_30);
    (**(code **)(**(int **)(this + 0x18) + 0x10))();
    sp<>::clear(this_00);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::wp<android::IBinder::DeathRecipient>::wp<android::Cacao::CacaoClient>(android::Cacao::CacaoClient*)

wp<> * __thiscall android::wp<>::wp<>(wp<> *this,int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = param_1 + 4;
  if (param_1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  *(int **)this = piVar1;
  if (param_1 != (int *)0x0) {
    uVar2 = android::RefBase::createWeak((void *)(*(int *)(*param_1 + -0xc) + (int)param_1));
    *(undefined4 *)(this + 4) = uVar2;
  }
  return this;
}



// android::wp<android::IBinder::DeathRecipient>::~wp()

wp<> * __thiscall android::wp<>::~wp(wp<> *this)

{
  if (*(int *)this != 0) {
    android::RefBase::weakref_type::decWeak(*(void **)(this + 4));
  }
  return this;
}



// android::sp<android::ICacaoService>::clear()

void __thiscall android::sp<>::clear(sp<> *this)

{
  int *piVar1;
  
  piVar1 = *(int **)this;
  if (piVar1 != (int *)0x0) {
    android::RefBase::decStrong((void *)((int)piVar1 + *(int *)(*piVar1 + -0xc)));
    *(undefined4 *)this = 0;
  }
  return;
}



// android::Cacao::CacaoClient::notifyEvent(int, android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData)

void __thiscall android::Cacao::CacaoClient::notifyEvent(CacaoClient *this)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(this + 0x20);
  if (piVar2 != (int *)0x0) {
    piVar1 = (int *)cacao::ProcessFactory::createEvent();
    if (piVar1 == (int *)0x0) {
      __android_log_print(6,"CacaoClient","could not call the callback");
    }
    else {
      (**(code **)(*piVar1 + 0x18))(piVar1,*(undefined4 *)(this + 0x24));
      (**(code **)(*piVar2 + 8))(piVar2,piVar1);
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return;
}



// non-virtual thunk to android::Cacao::CacaoClient::binderDied(android::wp<android::IBinder>
// const&)

void __thiscall android::Cacao::CacaoClient::binderDied(void)

{
  __android_log_print(5,"CacaoClient","client binder died");
  return;
}



// android::Cacao::CacaoClient::subscribeEvents(cacao::ICBProcessEventListener*, void*)

undefined4 __thiscall
android::Cacao::CacaoClient::subscribeEvents
          (CacaoClient *this,undefined4 param_1,undefined4 param_2)

{
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  *(undefined4 *)(this + 0x20) = param_1;
  *(undefined4 *)(this + 0x24) = param_2;
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  return 0;
}



// non-virtual thunk to
// android::Cacao::CacaoClient::subscribeEvents(cacao::ICBProcessEventListener*, void*)

undefined4 __thiscall
android::Cacao::CacaoClient::subscribeEvents
          (CacaoClient *this,undefined4 param_1,undefined4 param_2)

{
  pthread_mutex_lock((pthread_mutex_t *)(this + 8));
  *(undefined4 *)(this + 0xc) = param_1;
  *(undefined4 *)(this + 0x10) = param_2;
  pthread_mutex_unlock((pthread_mutex_t *)(this + 8));
  return 0;
}



// android::Cacao::CacaoClient::start(cacao::ProcessModeBase const*)

int __thiscall android::Cacao::CacaoClient::start(CacaoClient *this,int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined4 auStack_348 [100];
  CacaoClient aCStack_1b8 [4];
  int local_1b4;
  undefined4 local_1b0;
  undefined4 uStack_1ac;
  undefined4 auStack_1a8 [99];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  local_1b4 = 0;
  __aeabi_memclr8(&local_1b0,0x194);
  if (*(int *)(this + 0x18) == 0) {
    iVar2 = -0x65;
  }
  else if (param_1 == (int *)0x0) {
    iVar2 = -0x67;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    allocMemory(aCStack_1b8,uVar1);
    sp<>::operator=((sp<> *)&local_1b4,(undefined4 *)aCStack_1b8);
    sp<>::~sp((sp<> *)aCStack_1b8);
    if (local_1b4 == 0) {
      iVar2 = -0x66;
      goto LAB_0000fa08;
    }
    makeSerializedData(&local_1b4,(int)&local_1b0);
    iVar2 = (**(code **)(*param_1 + 0x18))(param_1,&local_1b0);
    if (-1 < iVar2) {
      piVar3 = *(int **)(this + 0x18);
      iVar2 = 0x18c;
      pcVar7 = *(code **)(*piVar3 + 0x14);
      puVar5 = auStack_1a8;
      puVar6 = auStack_348;
      do {
        iVar2 = iVar2 + -4;
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar2 != 0);
      iVar4 = (*pcVar7)(piVar3,&local_1b4,local_1b0,uStack_1ac);
      iVar2 = iVar4;
      if (iVar4 != -0x6e) {
        iVar2 = -0x6f;
      }
      if (iVar4 == 0) {
        iVar2 = iVar4;
      }
    }
  }
  if (local_1b4 != 0) {
    sp<>::clear((sp<> *)&local_1b4);
  }
LAB_0000fa08:
  sp<>::~sp((sp<> *)&local_1b4);
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  if (__stack_chk_guard != local_1c) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return iVar2;
}



// android::Cacao::CacaoClient::allocMemory(unsigned int)

void __thiscall android::Cacao::CacaoClient::allocMemory(CacaoClient *this,uint param_1)

{
  MemoryHeapBase *this_00;
  MemoryBase *this_01;
  sp<> asStack_20 [4];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  this_00 = operator_new(0x38);
  android::MemoryHeapBase::MemoryHeapBase(this_00,param_1,0,(char *)0x0);
  sp<>::sp<>(asStack_20,(int *)this_00);
  this_01 = operator_new(0x24);
  android::MemoryBase::MemoryBase(this_01,(sp *)asStack_20,0,param_1);
  sp<>::sp<>((sp<> *)this,(int *)this_01);
  sp<>::~sp((sp<> *)asStack_20);
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::CacaoClient::makeSerializedData(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData*)

void __cdecl android::Cacao::CacaoClient::makeSerializedData(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (*param_1 != 0)) {
    uVar1 = android::IMemory::size();
    *(undefined4 *)(param_2 + 0x184) = uVar1;
    uVar1 = android::IMemory::pointer();
    *(undefined4 *)(param_2 + 0x188) = uVar1;
  }
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::CacaoClient::freeMemory(android::sp<android::IMemory>&)

void __cdecl android::Cacao::CacaoClient::freeMemory(sp<> *param_1)

{
  if (*(int *)param_1 != 0) {
    sp<>::clear(param_1);
    return;
  }
  return;
}



// non-virtual thunk to android::Cacao::CacaoClient::start(cacao::ProcessModeBase const*)

void __thiscall android::Cacao::CacaoClient::start(CacaoClient *this)

{
  int *in_r1;
  
  start(this + -0x14,in_r1);
  return;
}



// android::Cacao::CacaoClient::stop()

int __thiscall android::Cacao::CacaoClient::stop(CacaoClient *this)

{
  int iVar1;
  int iVar2;
  
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  if (*(int **)(this + 0x18) == (int *)0x0) {
    iVar2 = -0x65;
  }
  else {
    iVar1 = (**(code **)(**(int **)(this + 0x18) + 0x18))();
    iVar2 = iVar1;
    if (iVar1 != -0x6e) {
      iVar2 = -0x6f;
    }
    if (iVar1 == 0) {
      iVar2 = iVar1;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  return iVar2;
}



// non-virtual thunk to android::Cacao::CacaoClient::stop()

void __thiscall android::Cacao::CacaoClient::stop(CacaoClient *this)

{
  stop(this + -0x14);
  return;
}



// android::Cacao::CacaoClient::setConfig(cacao::ProcessConfigBase const*)

int __thiscall android::Cacao::CacaoClient::setConfig(CacaoClient *this,int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  code *pcVar8;
  undefined4 auStack_350 [100];
  CacaoClient aCStack_1c0 [4];
  int local_1bc;
  undefined4 local_1b8 [102];
  int local_20;
  
  local_20 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  local_1bc = 0;
  __aeabi_memclr8(local_1b8,0x194);
  if (*(int *)(this + 0x18) == 0) {
    iVar2 = -0x65;
  }
  else if (param_1 == (int *)0x0) {
    iVar2 = -0x67;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
    allocMemory(aCStack_1c0,uVar1);
    sp<>::operator=((sp<> *)&local_1bc,(undefined4 *)aCStack_1c0);
    sp<>::~sp((sp<> *)aCStack_1c0);
    if (local_1bc == 0) {
      iVar2 = -0x66;
      goto LAB_0000fbec;
    }
    makeSerializedData(&local_1bc,(int)local_1b8);
    iVar2 = (**(code **)(*param_1 + 0x20))(param_1,local_1b8);
    if (-1 < iVar2) {
      piVar7 = *(int **)(this + 0x18);
      pcVar8 = *(code **)(*piVar7 + 0x1c);
      uVar3 = (**(code **)(*param_1 + 0x10))(param_1);
      iVar2 = 400;
      puVar4 = (undefined4 *)((uint)local_1b8 | 4);
      puVar6 = auStack_350;
      do {
        iVar2 = iVar2 + -4;
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar2 != 0);
      iVar5 = (*pcVar8)(piVar7,uVar3,&local_1bc,local_1b8[0]);
      iVar2 = iVar5;
      if (iVar5 != -0x6e) {
        iVar2 = -0x6f;
      }
      if (iVar5 == 0) {
        iVar2 = iVar5;
      }
    }
  }
  if (local_1bc != 0) {
    sp<>::clear((sp<> *)&local_1bc);
  }
LAB_0000fbec:
  sp<>::~sp((sp<> *)&local_1bc);
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  if (__stack_chk_guard != local_20) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return iVar2;
}



// non-virtual thunk to android::Cacao::CacaoClient::setConfig(cacao::ProcessConfigBase const*)

void __thiscall android::Cacao::CacaoClient::setConfig(CacaoClient *this)

{
  int *in_r1;
  
  setConfig(this + -0x14,in_r1);
  return;
}



// android::Cacao::CacaoClient::getConfig(cacao::ProcessConfigBase*)

int __thiscall android::Cacao::CacaoClient::getConfig(CacaoClient *this,int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  code *pcVar8;
  undefined4 auStack_350 [100];
  CacaoClient aCStack_1c0 [4];
  int local_1bc;
  undefined4 local_1b8 [99];
  undefined4 local_2c;
  undefined4 uStack_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  local_1bc = 0;
  __aeabi_memclr8(local_1b8,0x194);
  if (*(int *)(this + 0x18) == 0) {
    iVar2 = -0x65;
  }
  else if (param_1 == (int *)0x0) {
    iVar2 = -0x67;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
    allocMemory(aCStack_1c0,uVar1);
    sp<>::operator=((sp<> *)&local_1bc,(undefined4 *)aCStack_1c0);
    sp<>::~sp((sp<> *)aCStack_1c0);
    if (local_1bc == 0) {
      iVar2 = -0x66;
      goto LAB_0000fd0a;
    }
    makeSerializedData(&local_1bc,(int)local_1b8);
    iVar2 = (**(code **)(*param_1 + 0x20))(param_1,local_1b8);
    if (-1 < iVar2) {
      piVar7 = *(int **)(this + 0x18);
      pcVar8 = *(code **)(*piVar7 + 0x20);
      uVar3 = (**(code **)(*param_1 + 0x10))(param_1);
      iVar2 = 400;
      puVar4 = (undefined4 *)((uint)local_1b8 | 4);
      puVar6 = auStack_350;
      do {
        iVar2 = iVar2 + -4;
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar2 != 0);
      iVar5 = (*pcVar8)(piVar7,uVar3,&local_1bc,local_1b8[0]);
      iVar2 = iVar5;
      if (iVar5 != -0x6e) {
        iVar2 = -0x6f;
      }
      if (iVar5 == 0) {
        local_2c = 0;
        uStack_28 = 0;
        iVar2 = (**(code **)(*param_1 + 0x24))(param_1,local_1b8);
      }
    }
  }
  if (local_1bc != 0) {
    sp<>::clear((sp<> *)&local_1bc);
  }
LAB_0000fd0a:
  sp<>::~sp((sp<> *)&local_1bc);
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  if (__stack_chk_guard == local_24) {
    return iVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::Cacao::CacaoClient::getConfig(cacao::ProcessConfigBase*)

void __thiscall android::Cacao::CacaoClient::getConfig(CacaoClient *this)

{
  int *in_r1;
  
  getConfig(this + -0x14,in_r1);
  return;
}



// android::Cacao::CacaoClient::process(cacao::ProcessParamBase const*,
// cacao::ICBProcessResultListener*, cacao::ProcessResultBase*)

int __thiscall
android::Cacao::CacaoClient::process(CacaoClient *this,int *param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  CacaoProcessCallback *this_00;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 auStack_860 [99];
  VectorImpl *local_6d4;
  int *local_6d0;
  undefined4 auStack_6cc [101];
  undefined4 local_538;
  sp<> *psStack_534;
  code *local_52c;
  undefined **local_528 [5];
  CacaoClient aCStack_514 [4];
  int local_510;
  int local_50c;
  undefined **local_508 [5];
  int local_4f4;
  undefined4 local_4f0;
  undefined4 uStack_4ec;
  undefined4 auStack_4e8 [100];
  undefined4 auStack_358 [102];
  undefined1 auStack_1c0 [408];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  iVar6 = 0;
  local_4f4 = 0;
  android::VectorImpl::VectorImpl((VectorImpl *)local_508,4,7);
  local_508[0] = &PTR__Vector_1_00017cfc;
  local_510 = 0;
  local_50c = 0;
  __aeabi_memclr8(auStack_1c0,0x194);
  __aeabi_memclr8(auStack_358,0x194);
  if (*(int *)(this + 0x18) == 0) {
    iVar6 = -0x65;
  }
  else {
    if (param_3 == (int *)0x0) {
      iVar6 = -0x67;
    }
    if ((param_1 != (int *)0x0) && (param_3 != (int *)0x0)) {
      uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
      allocMemory(aCStack_514,uVar1);
      sp<>::operator=((sp<> *)&local_4f4,(undefined4 *)aCStack_514);
      sp<>::~sp((sp<> *)aCStack_514);
      if (local_4f4 == 0) {
        iVar6 = -0x66;
        goto LAB_0000ff04;
      }
      makeSerializedData(&local_4f4,(int)auStack_1c0);
      iVar6 = (**(code **)(*param_1 + 0x1c))(param_1,auStack_1c0);
    }
    if (-1 < iVar6) {
      uVar1 = (**(code **)(*param_3 + 0x24))(param_3);
      allocMemory(aCStack_514,uVar1);
      sp<>::operator=((sp<> *)&local_50c,(undefined4 *)aCStack_514);
      sp<>::~sp((sp<> *)aCStack_514);
      if (local_50c == 0) {
LAB_0000fef6:
        iVar6 = -0x66;
      }
      else {
        makeSerializedData(&local_50c,(int)auStack_358);
        iVar6 = (**(code **)(*param_3 + 0x28))(param_3,auStack_358);
        if (-1 < iVar6) {
          this_00 = operator_new(0x20);
          CacaoProcessCallback::CacaoProcessCallback(this_00,param_2,param_3);
          sp<>::operator=((sp<> *)&local_510,(int *)this_00);
          if (local_510 == 0) goto LAB_0000fef6;
          piVar5 = *(int **)(this + 0x18);
          local_52c = *(code **)(*piVar5 + 0x24);
          __aeabi_memcpy8(&local_4f0,auStack_1c0,0x194);
          android::VectorImpl::VectorImpl((VectorImpl *)local_528,(VectorImpl *)local_508);
          iVar6 = 0x18c;
          local_538 = 1;
          local_6d0 = &local_50c;
          puVar2 = auStack_4e8;
          puVar4 = auStack_860;
          local_6d4 = (VectorImpl *)local_528;
          psStack_534 = (sp<> *)&local_510;
          local_528[0] = &PTR__Vector_1_00017cfc;
          do {
            iVar6 = iVar6 + -4;
            *puVar4 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar4 = puVar4 + 1;
          } while (iVar6 != 0);
          iVar6 = 0x194;
          puVar2 = auStack_6cc;
          puVar4 = auStack_358;
          do {
            iVar6 = iVar6 + -4;
            *puVar2 = *puVar4;
            puVar2 = puVar2 + 1;
            puVar4 = puVar4 + 1;
          } while (iVar6 != 0);
          iVar3 = (*local_52c)(piVar5,&local_4f4,local_4f0,uStack_4ec);
          local_528[0] = &PTR__Vector_1_00017cfc;
          android::VectorImpl::finish_vector();
          android::VectorImpl::~VectorImpl((VectorImpl *)local_528);
          iVar6 = iVar3;
          if (iVar3 != -0x6e) {
            iVar6 = -0x6f;
          }
          if (iVar3 == 0) {
            iVar6 = iVar3;
          }
        }
      }
    }
  }
  if (local_4f4 != 0) {
    sp<>::clear((sp<> *)&local_4f4);
  }
LAB_0000ff04:
  if (local_50c != 0) {
    sp<>::clear((sp<> *)&local_50c);
  }
  sp<>::~sp((sp<> *)&local_510);
  sp<>::~sp((sp<> *)&local_50c);
  local_508[0] = &PTR__Vector_1_00017cfc;
  android::VectorImpl::finish_vector();
  android::VectorImpl::~VectorImpl((VectorImpl *)local_508);
  sp<>::~sp((sp<> *)&local_4f4);
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  if (__stack_chk_guard != local_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return iVar6;
}



// non-virtual thunk to android::Cacao::CacaoClient::process(cacao::ProcessParamBase const*,
// cacao::ICBProcessResultListener*, cacao::ProcessResultBase*)

void __thiscall android::Cacao::CacaoClient::process(CacaoClient *this)

{
  int *in_r1;
  undefined4 in_r2;
  int *in_r3;
  
  process(this + -0x14,in_r1,in_r2,in_r3);
  return;
}



// android::Cacao::CacaoClient::processAsync(cacao::ProcessParamBase const*,
// android::Vector<cacao::ImageBuf*>*, cacao::ICBProcessResultListener*, cacao::ProcessResultBase*)

int __thiscall
android::Cacao::CacaoClient::processAsync
          (CacaoClient *this,int *param_1,int param_2,undefined *param_3,int *param_4)

{
  uint uVar1;
  CacaoProcessCallback *this_00;
  VectorImpl *this_01;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 auStack_860 [99];
  VectorImpl *local_6d4;
  int *piStack_6d0;
  undefined4 auStack_6cc [101];
  undefined4 local_538;
  sp<> *psStack_534;
  code *local_52c;
  undefined **local_528 [5];
  CacaoClient aCStack_514 [4];
  int local_510;
  int local_50c;
  undefined **local_508 [2];
  uint local_500;
  int local_4f4;
  undefined4 local_4f0;
  undefined4 uStack_4ec;
  undefined4 auStack_4e8 [100];
  undefined4 auStack_358 [102];
  undefined1 auStack_1c0 [408];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  iVar4 = 0;
  local_4f4 = 0;
  android::VectorImpl::VectorImpl((VectorImpl *)local_508,4,7);
  local_508[0] = &PTR__Vector_1_00017cfc;
  local_50c = 0;
  __aeabi_memclr8(auStack_1c0,0x194);
  __aeabi_memclr8(auStack_358,0x194);
  local_510 = 0;
  if (*(int *)(this + 0x18) != 0) {
    if (param_4 == (int *)0x0) {
      iVar4 = -0x67;
    }
    if (param_3 == (undefined *)0x0) {
      iVar4 = -0x67;
    }
    if (((param_1 != (int *)0x0) && (param_3 != (undefined *)0x0)) && (param_4 != (int *)0x0)) {
      uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
      allocMemory(aCStack_514,uVar1);
      sp<>::operator=((sp<> *)&local_4f4,(undefined4 *)aCStack_514);
      sp<>::~sp((sp<> *)aCStack_514);
      if (local_4f4 == 0) {
        iVar4 = 0;
        goto LAB_0001019c;
      }
      makeSerializedData(&local_4f4,(int)auStack_1c0);
      iVar4 = (**(code **)(*param_1 + 0x1c))(param_1,auStack_1c0);
    }
    local_52c = (code *)param_3;
    if (((param_2 != 0) && (-1 < iVar4)) && (*(int *)(param_2 + 8) != 0)) {
      iVar6 = 0;
      uVar1 = 0;
      do {
        android::VectorImpl::insertAt(local_508,*(int *)(param_2 + 4) + iVar6,local_500);
        uVar1 = uVar1 + 1;
        iVar6 = iVar6 + 4;
      } while (uVar1 < *(uint *)(param_2 + 8));
    }
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    else {
      uVar1 = (**(code **)(*param_4 + 0x24))(param_4);
      allocMemory(aCStack_514,uVar1);
      sp<>::operator=((sp<> *)&local_50c,(undefined4 *)aCStack_514);
      sp<>::~sp((sp<> *)aCStack_514);
      if (local_50c == 0) {
        iVar4 = 0;
      }
      else {
        makeSerializedData(&local_50c,(int)auStack_358);
        iVar4 = (**(code **)(*param_4 + 0x28))(param_4,auStack_358);
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        else {
          this_00 = operator_new(0x20);
          CacaoProcessCallback::CacaoProcessCallback(this_00,local_52c,param_4);
          sp<>::operator=((sp<> *)&local_510,(int *)this_00);
          iVar4 = 0;
          if (local_510 != 0) {
            piVar5 = *(int **)(this + 0x18);
            local_52c = *(code **)(*piVar5 + 0x24);
            __aeabi_memcpy8(&local_4f0,auStack_1c0,0x194);
            this_01 = (VectorImpl *)
                      android::VectorImpl::VectorImpl
                                ((VectorImpl *)local_528,(VectorImpl *)local_508);
            iVar4 = 0x18c;
            local_538 = 0;
            puVar2 = auStack_4e8;
            puVar3 = auStack_860;
            local_6d4 = this_01;
            piStack_6d0 = &local_50c;
            psStack_534 = (sp<> *)&local_510;
            local_528[0] = &PTR__Vector_1_00017cfc;
            do {
              iVar4 = iVar4 + -4;
              *puVar3 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar3 = puVar3 + 1;
            } while (iVar4 != 0);
            iVar4 = 0x194;
            puVar2 = auStack_6cc;
            puVar3 = auStack_358;
            do {
              iVar4 = iVar4 + -4;
              *puVar2 = *puVar3;
              puVar2 = puVar2 + 1;
              puVar3 = puVar3 + 1;
            } while (iVar4 != 0);
            iVar4 = (*local_52c)(piVar5,&local_4f4,local_4f0,uStack_4ec);
            local_528[0] = &PTR__Vector_1_00017cfc;
            android::VectorImpl::finish_vector();
            android::VectorImpl::~VectorImpl(this_01);
          }
        }
      }
    }
  }
  if (local_4f4 != 0) {
    sp<>::clear((sp<> *)&local_4f4);
  }
LAB_0001019c:
  if (local_50c != 0) {
    sp<>::clear((sp<> *)&local_50c);
  }
  sp<>::~sp((sp<> *)&local_510);
  sp<>::~sp((sp<> *)&local_50c);
  local_508[0] = &PTR__Vector_1_00017cfc;
  android::VectorImpl::finish_vector();
  android::VectorImpl::~VectorImpl((VectorImpl *)local_508);
  sp<>::~sp((sp<> *)&local_4f4);
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  if (__stack_chk_guard == local_28) {
    return iVar4;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::Cacao::CacaoClient::processAsync(cacao::ProcessParamBase const*,
// android::Vector<cacao::ImageBuf*>*, cacao::ICBProcessResultListener*, cacao::ProcessResultBase*)

void __thiscall android::Cacao::CacaoClient::processAsync(CacaoClient *this)

{
  int *in_r1;
  int in_r2;
  undefined *in_r3;
  int *in_stack_00000000;
  
  processAsync(this + -0x14,in_r1,in_r2,in_r3,in_stack_00000000);
  return;
}



// android::Cacao::CacaoClient::processAsyncWithBinder(cacao::ProcessParamBase const*,
// android::sp<android::IBinder> const&, cacao::ICBProcessResultListener*,
// cacao::ProcessResultBase*)

int __thiscall
android::Cacao::CacaoClient::processAsyncWithBinder
          (CacaoClient *this,int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  uint uVar1;
  CacaoProcessCallback *this_00;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  code *pcVar6;
  undefined4 auStack_698 [99];
  undefined4 local_50c;
  int *piStack_508;
  undefined4 auStack_504 [101];
  undefined4 local_370;
  sp<> *psStack_36c;
  CacaoClient aCStack_368 [4];
  int local_364;
  int local_360;
  int local_35c;
  undefined4 auStack_358 [102];
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 auStack_1b8 [100];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  iVar5 = 0;
  local_360 = 0;
  local_35c = 0;
  __aeabi_memclr8(&local_1c0,0x194);
  __aeabi_memclr8(auStack_358,0x194);
  local_364 = 0;
  if (*(int *)(this + 0x18) != 0) {
    if (param_4 == (int *)0x0) {
      iVar5 = -0x67;
    }
    if (param_3 == 0) {
      iVar5 = -0x67;
    }
    if ((param_1 != (int *)0x0) && (param_3 != 0 && param_4 != (int *)0x0)) {
      uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
      allocMemory(aCStack_368,uVar1);
      sp<>::operator=((sp<> *)&local_35c,(undefined4 *)aCStack_368);
      sp<>::~sp((sp<> *)aCStack_368);
      if (local_35c == 0) {
        iVar5 = 0;
        goto LAB_000103b8;
      }
      makeSerializedData(&local_35c,(int)&local_1c0);
      iVar5 = (**(code **)(*param_1 + 0x1c))(param_1,&local_1c0);
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else {
      uVar1 = (**(code **)(*param_4 + 0x24))(param_4);
      allocMemory(aCStack_368,uVar1);
      sp<>::operator=((sp<> *)&local_360,(undefined4 *)aCStack_368);
      sp<>::~sp((sp<> *)aCStack_368);
      if (local_360 == 0) {
        iVar5 = 0;
      }
      else {
        makeSerializedData(&local_360,(int)auStack_358);
        iVar5 = (**(code **)(*param_4 + 0x28))(param_4,auStack_358);
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        else {
          this_00 = operator_new(0x20);
          CacaoProcessCallback::CacaoProcessCallback(this_00,param_3,param_4);
          sp<>::operator=((sp<> *)&local_364,(int *)this_00);
          iVar5 = 0;
          if (local_364 != 0) {
            piVar2 = *(int **)(this + 0x18);
            iVar5 = 0x18c;
            pcVar6 = *(code **)(*piVar2 + 0x28);
            local_370 = 0;
            puVar3 = auStack_1b8;
            puVar4 = auStack_698;
            local_50c = param_2;
            piStack_508 = &local_360;
            psStack_36c = (sp<> *)&local_364;
            do {
              iVar5 = iVar5 + -4;
              *puVar4 = *puVar3;
              puVar3 = puVar3 + 1;
              puVar4 = puVar4 + 1;
            } while (iVar5 != 0);
            iVar5 = 0x194;
            puVar3 = auStack_504;
            puVar4 = auStack_358;
            do {
              iVar5 = iVar5 + -4;
              *puVar3 = *puVar4;
              puVar3 = puVar3 + 1;
              puVar4 = puVar4 + 1;
            } while (iVar5 != 0);
            iVar5 = (*pcVar6)(piVar2,&local_35c,local_1c0,local_1bc);
          }
        }
      }
    }
  }
  if (local_35c != 0) {
    sp<>::clear((sp<> *)&local_35c);
  }
LAB_000103b8:
  if (local_360 != 0) {
    sp<>::clear((sp<> *)&local_360);
  }
  sp<>::~sp((sp<> *)&local_364);
  sp<>::~sp((sp<> *)&local_360);
  sp<>::~sp((sp<> *)&local_35c);
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  if (__stack_chk_guard == local_28) {
    return iVar5;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::Cacao::CacaoClient::processAsyncWithBinder(cacao::ProcessParamBase
// const*, android::sp<android::IBinder> const&, cacao::ICBProcessResultListener*,
// cacao::ProcessResultBase*)

void __thiscall android::Cacao::CacaoClient::processAsyncWithBinder(CacaoClient *this)

{
  int *in_r1;
  undefined4 in_r2;
  int in_r3;
  int *in_stack_00000000;
  
  processAsyncWithBinder(this + -0x14,in_r1,in_r2,in_r3,in_stack_00000000);
  return;
}



// android::Cacao::CacaoClient::cancel(void*)

int __thiscall android::Cacao::CacaoClient::cancel(CacaoClient *this,undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  piVar1 = *(int **)(this + 0x18);
  if (piVar1 == (int *)0x0) {
    iVar3 = -0x65;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,param_1);
    iVar3 = iVar2;
    if (iVar2 != -0x6e) {
      iVar3 = -0x6f;
    }
    if (iVar2 == 0) {
      iVar3 = iVar2;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  return iVar3;
}



// non-virtual thunk to android::Cacao::CacaoClient::cancel(void*)

void __thiscall android::Cacao::CacaoClient::cancel(CacaoClient *this)

{
  undefined4 in_r1;
  
  cancel(this + -0x14,in_r1);
  return;
}



// android::sp<android::IMemoryHeap>::sp<android::MemoryHeapBase>(android::MemoryHeapBase*)

sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  if (param_1 == (int *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    *(int *)this = *(int *)(*param_1 + -0xc) + (int)param_1;
    android::RefBase::incStrong
              ((void *)((int)param_1 +
                       *(int *)(*(int *)((int)param_1 + *(int *)(*param_1 + -0xc)) + -0xc) +
                       *(int *)(*param_1 + -0xc)));
  }
  return this;
}



// android::Cacao::DeathNotifier::DeathNotifier()

void __thiscall android::Cacao::DeathNotifier::DeathNotifier(DeathNotifier *this,int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[2];
  iVar1 = *param_1;
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[3];
  return;
}



// android::Cacao::DeathNotifier::DeathNotifier()

DeathNotifier * __thiscall android::Cacao::DeathNotifier::DeathNotifier(DeathNotifier *this)

{
  android::RefBase::RefBase((RefBase *)(this + 4));
  *(undefined4 *)this = 0x17f8c;
  *(undefined4 *)(this + 4) = 0x17fb4;
  return this;
}



// android::Cacao::DeathNotifier::~DeathNotifier()

void __thiscall android::Cacao::DeathNotifier::~DeathNotifier(DeathNotifier *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[3];
  return;
}



// android::Cacao::DeathNotifier::~DeathNotifier()

DeathNotifier * __thiscall android::Cacao::DeathNotifier::~DeathNotifier(DeathNotifier *this)

{
  *(undefined4 *)this = 0x17f8c;
  *(undefined4 *)(this + 4) = 0x17fb4;
  android::RefBase::~RefBase((RefBase *)(this + 4));
  return this;
}



// virtual thunk to android::Cacao::DeathNotifier::~DeathNotifier()

void __thiscall android::Cacao::DeathNotifier::~DeathNotifier(DeathNotifier *this)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)this + -0xc);
  *(undefined4 *)(this + iVar1) = 0x17f8c;
  *(undefined4 *)(this + iVar1 + 4) = 0x17fb4;
  android::RefBase::~RefBase((RefBase *)(this + iVar1 + 4));
  return;
}



// android::Cacao::DeathNotifier::~DeathNotifier()

void __thiscall android::Cacao::DeathNotifier::~DeathNotifier(DeathNotifier *this)

{
  *(undefined4 *)this = 0x17f8c;
  *(undefined4 *)(this + 4) = 0x17fb4;
  android::RefBase::~RefBase((RefBase *)(this + 4));
  operator_delete(this);
  return;
}



// virtual thunk to android::Cacao::DeathNotifier::~DeathNotifier()

void __thiscall android::Cacao::DeathNotifier::~DeathNotifier(DeathNotifier *this)

{
  DeathNotifier *pDVar1;
  
  pDVar1 = this + *(int *)(*(int *)this + -0xc);
  *(undefined4 *)(this + *(int *)(*(int *)this + -0xc)) = 0x17f8c;
  *(undefined4 *)(pDVar1 + 4) = 0x17fb4;
  android::RefBase::~RefBase((RefBase *)(pDVar1 + 4));
  operator_delete(pDVar1);
  return;
}



// android::Cacao::DeathNotifier::binderDied(android::wp<android::IBinder> const&)

void android::Cacao::DeathNotifier::binderDied(void)

{
  code *pcVar1;
  wp<> awStack_38 [8];
  sp<> asStack_30 [4];
  int *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)&mServiceLock);
  if (mService != 0) {
    sp<>::sp<>(asStack_30,&mService);
    android::IInterface::asBinder((sp *)&local_2c);
    pcVar1 = *(code **)(*local_2c + 0x1c);
    wp<>::wp<>(awStack_38,&mDeathNotifier);
    (*pcVar1)(local_2c,awStack_38,0,0,0);
    wp<>::~wp(awStack_38);
    sp<>::~sp((sp<> *)&local_2c);
    sp<>::~sp((sp<> *)asStack_30);
    sp<>::clear((sp<> *)&mDeathNotifier);
  }
  sp<>::clear((sp<> *)&mService);
  mServicePid = 0;
  __android_log_print(5,"CacaoClient","service died");
  pthread_mutex_unlock((pthread_mutex_t *)&mServiceLock);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::wp<android::IBinder::DeathRecipient>::wp<android::Cacao::DeathNotifier>(android::sp<android::Cacao::DeathNotifier>
// const&)

wp<> * __thiscall android::wp<>::wp<>(wp<> *this,int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    uVar2 = android::RefBase::createWeak((void *)((int)piVar1 + *(int *)(*piVar1 + -0xc)));
    *(undefined4 *)(this + 4) = uVar2;
  }
  return this;
}



// android::Cacao::create()

Cacao * android::Cacao::create(void)

{
  int iVar1;
  __pid_t _Var2;
  uint uVar3;
  Cacao *this;
  sp<> local_18 [4];
  int local_14;
  
  local_14 = __stack_chk_guard;
  getService();
  android::ProcessState::self();
  android::ProcessState::startThreadPool();
  sp<>::~sp(local_18);
  iVar1 = mServicePid;
  if (mService != 0) {
    _Var2 = getpid();
    this = (Cacao *)0x0;
    if (iVar1 == _Var2) goto LAB_000106f2;
    this = operator_new(8);
    *(undefined4 *)(this + 4) = 0;
    *(undefined ***)this = &PTR__Cacao_00017fe4;
    uVar3 = connect(this);
    if (uVar3 < 0x80000000) goto LAB_000106f2;
    (**(code **)(*(int *)this + 4))(this);
  }
  this = (Cacao *)0x0;
LAB_000106f2:
  if (__stack_chk_guard == local_14) {
    return this;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::Cacao::getService()

void android::Cacao::getService(void)

{
  int *piVar1;
  uint uVar2;
  code *pcVar3;
  int *local_3c;
  String16 aSStack_38 [4];
  sp<> asStack_34 [4];
  int local_30;
  int *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)&mServiceLock);
  if (mService == (int *)0x0) {
    android::defaultServiceManager();
    if (local_2c == (int *)0x0) {
      __android_log_print(6,"CacaoClient","service manager is not available");
    }
    else {
      uVar2 = 1;
      local_30 = 0;
      while( true ) {
        piVar1 = local_2c;
        pcVar3 = *(code **)(*local_2c + 0x10);
        android::String16::String16(aSStack_38,"cacao");
        (*pcVar3)(asStack_34,piVar1,aSStack_38);
        sp<>::operator=((sp<> *)&local_30,(undefined4 *)asStack_34);
        sp<>::~sp(asStack_34);
        android::String16::~String16(aSStack_38);
        if (local_30 != 0) break;
        usleep(500000);
        __android_log_print(5,"CacaoClient","trying to get cacao service <retry:%d>",uVar2);
        if (9 < uVar2) {
          if (local_30 == 0) {
            __android_log_print(6,"CacaoClient","failed to get cacao service");
            goto LAB_00010892;
          }
          break;
        }
        uVar2 = uVar2 + 1;
      }
      ICacaoService::asInterface((ICacaoService *)asStack_34,&local_30);
      sp<>::operator=((sp<> *)&mService,(undefined4 *)asStack_34);
      sp<>::~sp(asStack_34);
      mServicePid = (**(code **)(*mService + 0x14))();
      if (mDeathNotifier == 0) {
        piVar1 = operator_new(0xc);
        android::RefBase::RefBase((RefBase *)(piVar1 + 1));
        *piVar1 = 0x17f8c;
        piVar1[1] = 0x17fb4;
        sp<>::operator=((sp<> *)&mDeathNotifier,piVar1);
        sp<>::sp<>((sp<> *)asStack_34,(int *)&mService);
        android::IInterface::asBinder((sp *)&local_3c);
        pcVar3 = *(code **)(*local_3c + 0x18);
        sp<>::sp<>((sp<> *)aSStack_38,&mDeathNotifier);
        (*pcVar3)(local_3c,(sp<> *)aSStack_38,0,0);
        sp<>::~sp((sp<> *)aSStack_38);
        sp<>::~sp((sp<> *)&local_3c);
        sp<>::~sp(asStack_34);
      }
LAB_00010892:
      sp<>::~sp((sp<> *)&local_30);
    }
    sp<>::~sp((sp<> *)&local_2c);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&mServiceLock);
  if (__stack_chk_guard != local_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail(&mService);
  }
  return;
}



// android::Cacao::connect()

uint __thiscall android::Cacao::connect(Cacao *this)

{
  CacaoClient *this_00;
  uint uVar1;
  
  getService();
  if (mService == 0) {
    uVar1 = 0;
  }
  else {
    this_00 = operator_new(0x30);
    CacaoClient::CacaoClient(this_00);
    sp<>::operator=((sp<> *)(this + 4),(int *)this_00);
    if (*(CacaoClient **)(this + 4) == (CacaoClient *)0x0) {
      uVar1 = 0xffffff9a;
    }
    else {
      uVar1 = CacaoClient::connect(*(CacaoClient **)(this + 4),&mService);
      if (uVar1 < 0x80000000) {
        return uVar1;
      }
    }
    disconnect(this);
  }
  return uVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&, cacao::Caps*)

int __cdecl android::Cacao::getCaps(undefined4 param_1,int *param_2)

{
  __pid_t _Var1;
  uint uVar2;
  MemoryHeapBase *this;
  MemoryBase *this_00;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  code *pcVar7;
  undefined4 auStack_350 [100];
  sp<> asStack_1c0 [4];
  int local_1bc;
  undefined4 local_1b8 [97];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  getService();
  iVar4 = mServicePid;
  if (mService == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    _Var1 = getpid();
    iVar6 = 0;
    if (iVar4 != _Var1) {
      local_1bc = 0;
      __aeabi_memclr8(local_1b8,0x194);
      if (param_2 == (int *)0x0) {
        iVar6 = -0x67;
      }
      else {
        uVar2 = (**(code **)(*param_2 + 0x10))(param_2);
        this = operator_new(0x38);
        android::MemoryHeapBase::MemoryHeapBase(this,uVar2,0,(char *)0x0);
        sp<>::sp<>(asStack_1c0,(int *)this);
        this_00 = operator_new(0x24);
        android::MemoryBase::MemoryBase(this_00,(sp *)asStack_1c0,0,uVar2);
        sp<>::operator=((sp<> *)&local_1bc,(int *)this_00);
        iVar4 = local_1bc;
        sp<>::~sp((sp<> *)asStack_1c0);
        if (iVar4 == 0) {
          iVar6 = -0x66;
        }
        else {
          local_34 = android::IMemory::size();
          local_30 = android::IMemory::pointer();
          iVar6 = (**(code **)(*param_2 + 0x14))(param_2,local_1b8);
          if (-1 < iVar6) {
            iVar4 = 400;
            pcVar7 = *(code **)(*mService + 0x18);
            puVar3 = (undefined4 *)((uint)local_1b8 | 4);
            puVar5 = auStack_350;
            do {
              iVar4 = iVar4 + -4;
              *puVar5 = *puVar3;
              puVar3 = puVar3 + 1;
              puVar5 = puVar5 + 1;
            } while (iVar4 != 0);
            iVar4 = (*pcVar7)(mService,param_1,&local_1bc,local_1b8[0]);
            iVar6 = iVar4;
            if (iVar4 != -0x6e) {
              iVar6 = -0x6f;
            }
            if (iVar4 == 0) {
              local_2c = 0;
              uStack_28 = 0;
              iVar6 = (**(code **)(*param_2 + 0x18))(param_2,local_1b8);
            }
          }
        }
        if (local_1bc != 0) {
          sp<>::clear((sp<> *)&local_1bc);
        }
      }
      sp<>::~sp((sp<> *)&local_1bc);
    }
  }
  if (__stack_chk_guard == local_24) {
    return iVar6;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::Cacao::getJpegBufferSize(cacao::ImageSize)

undefined4 __thiscall android::Cacao::getJpegBufferSize(Cacao *this,undefined4 param_1)

{
  int iVar1;
  __pid_t _Var2;
  undefined4 uVar3;
  
  getService();
  iVar1 = mServicePid;
  if ((mService != (int *)0x0) && (_Var2 = getpid(), iVar1 != _Var2)) {
                    // WARNING: Could not recover jumptable at 0x00010ae2. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar3 = (**(code **)(*mService + 0x1c))(mService,this,param_1);
    return uVar3;
  }
  return 0;
}



// android::Cacao::isSameProcess()

undefined4 android::Cacao::isSameProcess(void)

{
  int iVar1;
  __pid_t _Var2;
  undefined4 uVar3;
  
  getService();
  iVar1 = mServicePid;
  uVar3 = 0;
  if ((mService != 0) && (_Var2 = getpid(), iVar1 == _Var2)) {
    uVar3 = 1;
  }
  return uVar3;
}



// android::Cacao::~Cacao()

Cacao * __thiscall android::Cacao::~Cacao(Cacao *this)

{
  *(undefined ***)this = &PTR__Cacao_00017fe4;
  disconnect(this);
  sp<>::~sp((sp<> *)(this + 4));
  return this;
}



// android::Cacao::disconnect()

void __thiscall android::Cacao::disconnect(Cacao *this)

{
  CacaoClient *this_00;
  
  getService();
  if (mService != 0) {
    this_00 = *(CacaoClient **)(this + 4);
    if (this_00 != (CacaoClient *)0x0) {
      CacaoClient::disconnect(this_00);
      sp<>::clear((sp<> *)(this + 4));
      return;
    }
  }
  return;
}



// android::Cacao::~Cacao()

void __thiscall android::Cacao::~Cacao(Cacao *this)

{
  *(undefined ***)this = &PTR__Cacao_00017fe4;
  disconnect(this);
  sp<>::~sp((sp<> *)(this + 4));
  operator_delete(this);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::subscribeEvents(cacao::ICBProcessEventListener*, void*)

void __cdecl android::Cacao::subscribeEvents(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010ba2. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x20))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::start(cacao::ProcessModeBase const*)

void __cdecl android::Cacao::start(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010baa. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x24))();
  return;
}



// android::Cacao::stop()

void __thiscall android::Cacao::stop(Cacao *this)

{
                    // WARNING: Could not recover jumptable at 0x00010bb2. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(this + 4) + 0x28))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::setConfig(cacao::ProcessConfigBase const*)

void __cdecl android::Cacao::setConfig(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bba. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x2c))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::getConfig(cacao::ProcessConfigBase*)

void __cdecl android::Cacao::getConfig(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bc2. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x30))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::process(cacao::ProcessParamBase const*, cacao::ICBProcessResultListener*,
// cacao::ProcessResultBase*)

void __cdecl android::Cacao::process(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bce. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x34))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::processAsync(cacao::ProcessParamBase const*, android::Vector<cacao::ImageBuf*>*,
// cacao::ICBProcessResultListener*, cacao::ProcessResultBase*)

void __cdecl android::Cacao::processAsync(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bda. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x38))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::processAsyncWithBinder(cacao::ProcessParamBase const*,
// android::sp<android::IBinder> const&, cacao::ICBProcessResultListener*,
// cacao::ProcessResultBase*)

void __cdecl android::Cacao::processAsyncWithBinder(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010be6. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x3c))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::Cacao::cancel(void*)

void __cdecl android::Cacao::cancel(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010bee. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 4) + 0x40))();
  return;
}



// android::Cacao::Cacao()

void __thiscall android::Cacao::Cacao(Cacao *this)

{
  *(undefined4 *)(this + 4) = 0;
  *(undefined ***)this = &PTR__Cacao_00017fe4;
  return;
}



// cacao::ObjectBase::ObjectBase()

void __thiscall cacao::ObjectBase::ObjectBase(ObjectBase *this)

{
  *(undefined ***)this = &PTR__AbstractUnwindCursor_00018728;
  return;
}



// cacao::ObjectBase::operator new(unsigned int)

void * __thiscall cacao::ObjectBase::operator_new(ObjectBase *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)PAL_MemAllocEx(0,this,"vendor/semc/system/cacao/client/cacao_objectbase.cpp",0x39
                                  ,0);
  return pvVar1;
}



// cacao::ObjectBase::operator delete(void*)

void __thiscall cacao::ObjectBase::operator_delete(ObjectBase *this)

{
  PAL_MemFreeEx(this,0);
  return;
}



// cacao::SharedBuffer::create()

SharedBuffer * cacao::SharedBuffer::create(void)

{
  SharedBuffer *this;
  
  this = operator_new(8);
  *(undefined4 *)this = 0;
  pthread_mutex_init((pthread_mutex_t *)(this + 4),(pthread_mutexattr_t *)0x0);
  incRefCnt(this);
  return this;
}



// cacao::SharedBuffer::incRefCnt()

void __thiscall cacao::SharedBuffer::incRefCnt(SharedBuffer *this)

{
  pthread_mutex_lock((pthread_mutex_t *)(this + 4));
  *(int *)this = *(int *)this + 1;
  pthread_mutex_unlock((pthread_mutex_t *)(this + 4));
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// cacao::SharedBuffer::share(cacao::SharedBuffer*)

SharedBuffer * __cdecl cacao::SharedBuffer::share(SharedBuffer *param_1)

{
  if (param_1 != (SharedBuffer *)0x0) {
    incRefCnt(param_1);
  }
  return param_1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// cacao::SharedBuffer::release(cacao::SharedBuffer*)

undefined4 __cdecl cacao::SharedBuffer::release(SharedBuffer *param_1)

{
  int iVar1;
  
  if ((param_1 != (SharedBuffer *)0x0) && (iVar1 = decRefCnt(param_1), iVar1 == 0)) {
    pthread_mutex_destroy((pthread_mutex_t *)(param_1 + 4));
    operator_delete(param_1);
    return 1;
  }
  return 0;
}



// cacao::SharedBuffer::decRefCnt()

int __thiscall cacao::SharedBuffer::decRefCnt(SharedBuffer *this)

{
  int iVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)(this + 4));
  iVar1 = *(int *)this;
  if (0 < iVar1) {
    iVar1 = iVar1 + -1;
    *(int *)this = iVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 4));
  return iVar1;
}



// cacao::SharedBuffer::SharedBuffer()

SharedBuffer * __thiscall cacao::SharedBuffer::SharedBuffer(SharedBuffer *this)

{
  *(undefined4 *)this = 0;
  pthread_mutex_init((pthread_mutex_t *)(this + 4),(pthread_mutexattr_t *)0x0);
  return this;
}



// cacao::SharedBuffer::~SharedBuffer()

SharedBuffer * __thiscall cacao::SharedBuffer::~SharedBuffer(SharedBuffer *this)

{
  pthread_mutex_destroy((pthread_mutex_t *)(this + 4));
  return this;
}



// cacao::ImageBuf::ImageBuf()

ImageBuf * __thiscall cacao::ImageBuf::ImageBuf(ImageBuf *this)

{
  SharedBuffer *pSVar1;
  int iVar2;
  
  ObjectBase::ObjectBase((ObjectBase *)this);
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined ***)this = &PTR__ImageBuf_00018740;
  *(undefined8 *)(this + 0x14) = 0;
  *(undefined8 *)(this + 4) = 0;
  *(undefined8 *)(this + 0xc) = 0;
  *(undefined8 *)(this + 4) = 0;
  *(undefined8 *)(this + 0x1a) = 0;
  pSVar1 = SharedBuffer::create();
  *(SharedBuffer **)(this + 0x24) = pSVar1;
  iVar2 = getMapper();
  if (-1 < iVar2) {
    getAllocator();
  }
  return this;
}



// cacao::ImageBuf::getMapper()

undefined4 cacao::ImageBuf::getMapper(void)

{
  int iVar1;
  undefined4 uVar2;
  ulonglong local_30;
  void *local_28;
  string asStack_20 [4];
  int local_1c;
  
  uVar2 = 0;
  local_1c = __stack_chk_guard;
  if (mMapper == (undefined4 *)0x0) {
    local_30 = 0xe;
    local_28 = (void *)0x0;
    __aeabi_memcpy((uint)&local_30 | 1,"default",7);
    local_28 = (void *)((uint)local_28 & 0xffffff00);
    android::hardware::graphics::mapper::V2_0::IMapper::getService(asStack_20,SUB41(&local_30,0));
    android::sp<>::operator=((sp<> *)&mMapper,(undefined4 *)asStack_20);
    android::sp<>::~sp((sp<> *)asStack_20);
    if ((local_30 & 1) != 0) {
      operator_delete(local_28);
    }
    if ((mMapper == (undefined4 *)0x0) || (iVar1 = (**(code **)*mMapper)(), iVar1 != 0)) {
      __android_log_print(6,"CacaoImageBuf","gralloc-mapper must be in passthrough mode");
      android::sp<>::operator=((sp<> *)&mMapper,(int *)0x0);
      uVar2 = 0xffffff91;
    }
    else {
      uVar2 = 0;
    }
  }
  if (__stack_chk_guard == local_1c) {
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// cacao::ImageBuf::getAllocator()

undefined4 cacao::ImageBuf::getAllocator(void)

{
  undefined4 uVar1;
  ulonglong local_30;
  void *local_28;
  string asStack_20 [4];
  int local_1c;
  
  uVar1 = 0;
  local_1c = __stack_chk_guard;
  if (mAllocator == 0) {
    local_30 = 0xe;
    local_28 = (void *)0x0;
    __aeabi_memcpy((uint)&local_30 | 1,"default",7);
    local_28 = (void *)((uint)local_28 & 0xffffff00);
    android::hardware::graphics::allocator::V2_0::IAllocator::getService
              (asStack_20,SUB41(&local_30,0));
    android::sp<>::operator=((sp<> *)&mAllocator,(undefined4 *)asStack_20);
    android::sp<>::~sp((sp<> *)asStack_20);
    if ((local_30 & 1) != 0) {
      operator_delete(local_28);
    }
    if (mAllocator == 0) {
      __android_log_print(6,"CacaoImageBuf","gralloc-alloc is missing");
      uVar1 = 0xffffff91;
    }
    else {
      uVar1 = 0;
    }
  }
  if (__stack_chk_guard == local_1c) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int, cacao::ImageFormat, cacao::DataSpace)

ImageBuf * __thiscall
cacao::ImageBuf::ImageBuf
          (ImageBuf *this,int param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  SharedBuffer *pSVar1;
  undefined1 auStack_a0 [4];
  int local_9c;
  int local_98 [5];
  undefined1 local_84;
  uint local_80;
  uint uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined *local_58;
  ImageBuf *local_54;
  int *piStack_50;
  function<> *local_48;
  undefined *local_40;
  undefined1 *local_3c;
  undefined8 *puStack_38;
  int *local_34;
  function<> *local_30;
  int local_24;
  
  local_24 = __stack_chk_guard;
  ObjectBase::ObjectBase((ObjectBase *)this);
  *(int *)(this + 4) = param_1;
  *(undefined ***)this = &PTR__ImageBuf_00018740;
  *(int *)(this + 8) = param_2;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(uint *)(this + 0x14) = param_3;
  *(undefined4 *)(this + 0x18) = param_5;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined2 *)(this + 0x20) = 0x101;
  *(undefined4 *)(this + 0x24) = 0;
  local_68 = 0;
  local_60 = 0;
  local_9c = getMapper();
  if (local_9c < 0) goto LAB_0001104c;
  local_9c = getAllocator();
  if (local_9c < 0) goto LAB_0001104c;
  if (param_3 == 0) {
    if (param_4 == 0x1000001) {
      param_3 = param_2 * param_1 * 2 + 0x10000;
      goto LAB_00010f28;
    }
    if (param_4 == 0x20001) {
      uStack_7c = param_2 + 1U & 0xfffffffe;
      param_3 = param_1 + 1U & 0xfffffffe;
      uStack_74 = 0x11;
    }
    else {
      if (param_4 != 0) {
        __android_log_print(6,"CacaoImageBuf","format is invalid");
        local_9c = -0x67;
        goto LAB_0001104c;
      }
      uStack_7c = param_2 + 1U & 0xfffffffe;
      param_3 = param_1 + 1U & 0xfffffffe;
      uStack_74 = 0x22;
    }
  }
  else {
LAB_00010f28:
    uStack_74 = 0x21;
    uStack_7c = 1;
  }
  local_6c = 0;
  local_70 = 0x33;
  local_78 = 1;
  local_40 = &DAT_00018788;
  local_3c = auStack_a0;
  local_80 = param_3;
  puStack_38 = &local_68;
  local_34 = &local_9c;
  local_30 = (function<> *)&local_40;
  (**(code **)(*mMapper + 0x34))(local_98,mMapper,&local_80,(function<> *)&local_40);
  std::function<>::~function((function<> *)&local_40);
  local_84 = 1;
  if (local_98[0] != 0) {
    __android_log_print(6,"CacaoImageBuf","create descriptor failed");
    local_9c = -0x6f;
  }
  android::hardware::details::return_status::~return_status((return_status *)local_98);
  if (-1 < local_9c) {
    local_58 = &DAT_000187ac;
    local_54 = this;
    piStack_50 = &local_9c;
    local_48 = (function<> *)&local_58;
    (**(code **)(*mAllocator + 0x38))(&local_80,mAllocator,&local_68,1,(function<> *)&local_58);
    std::function<>::~function((function<> *)&local_58);
    local_6c = CONCAT31(local_6c._1_3_,1);
    if (local_80 != 0) {
      __android_log_print(6,"CacaoImageBuf","allocate buffer failed");
      local_9c = -0x6f;
    }
    android::hardware::details::return_status::~return_status((return_status *)&local_80);
    if (-1 < local_9c) {
      pSVar1 = SharedBuffer::create();
      *(SharedBuffer **)(this + 0x24) = pSVar1;
    }
  }
LAB_0001104c:
  if ((local_60._4_1_ != '\0') && ((void *)local_68 != (void *)0x0)) {
    operator_delete__((void *)local_68);
  }
  if (__stack_chk_guard == local_24) {
    return this;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// std::function<void (android::hardware::graphics::mapper::V2_0::Error, void*)>::~function()

function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  code *pcVar2;
  
  pfVar1 = *(function<> **)(this + 0x10);
  if (this == pfVar1) {
    pcVar2 = *(code **)(*(int *)pfVar1 + 0x10);
  }
  else {
    if (pfVar1 == (function<> *)0x0) {
      return this;
    }
    pcVar2 = *(code **)(*(int *)pfVar1 + 0x14);
  }
  (*pcVar2)();
  return this;
}



// cacao::ImageBuf::ImageBuf(void*, cacao::ImageSize, cacao::DataSpace, cacao::ImageFormat)

ImageBuf * __thiscall
cacao::ImageBuf::ImageBuf
          (ImageBuf *this,undefined4 param_1,int param_2,uint param_3,undefined4 param_4,int param_5
          )

{
  int iVar1;
  SharedBuffer *pSVar2;
  
  ObjectBase::ObjectBase((ObjectBase *)this);
  *(int *)(this + 4) = param_2;
  *(uint *)(this + 8) = param_3;
  *(undefined4 *)(this + 0xc) = param_1;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined2 *)(this + 0x20) = 0x100;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x18) = param_4;
  *(undefined ***)this = &PTR__ImageBuf_00018740;
  iVar1 = getMapper();
  if (iVar1 < 0) {
    return this;
  }
  if (param_5 == 0) {
LAB_00011112:
    iVar1 = (param_2 + 0x7fU & 0xffffff80) *
            (((param_3 >> 1) + 0x1f & 0xffffffe0) + (param_3 + 0x1f & 0xffffffe0));
  }
  else {
    if (param_5 != 0x1000001) {
      if (param_5 != 0x20001) goto LAB_00011140;
      goto LAB_00011112;
    }
    iVar1 = param_3 * param_2 * 2 + 0x10000;
  }
  *(int *)(this + 0x14) = iVar1;
LAB_00011140:
  pSVar2 = SharedBuffer::create();
  *(SharedBuffer **)(this + 0x24) = pSVar2;
  return this;
}



// cacao::ImageBuf::ImageBuf(cacao::ImageBuf const&)

ImageBuf * __thiscall cacao::ImageBuf::ImageBuf(ImageBuf *this,int param_1)

{
  undefined4 uVar1;
  SharedBuffer *this_00;
  
  ObjectBase::ObjectBase((ObjectBase *)this);
  *(undefined8 *)(this + 0x1a) = 0;
  *(undefined8 *)(this + 0x14) = 0;
  *(undefined8 *)(this + 4) = 0;
  *(undefined8 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined ***)this = &PTR__ImageBuf_00018740;
  uVar1 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = uVar1;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  this[0x21] = *(ImageBuf *)(param_1 + 0x21);
  this_00 = *(SharedBuffer **)(param_1 + 0x24);
  if (this_00 != (SharedBuffer *)0x0) {
    SharedBuffer::incRefCnt(this_00);
  }
  *(SharedBuffer **)(this + 0x24) = this_00;
  return this;
}



// cacao::ImageBuf::~ImageBuf()

ImageBuf * __thiscall cacao::ImageBuf::~ImageBuf(ImageBuf *this)

{
  int iVar1;
  return_status arStack_30 [28];
  int local_14;
  
  local_14 = __stack_chk_guard;
  *(undefined ***)this = &PTR__ImageBuf_00018740;
  iVar1 = SharedBuffer::release(*(SharedBuffer **)(this + 0x24));
  if ((iVar1 != 0) && (mMapper != (int *)0x0)) {
    if (*(int *)(this + 0x10) != 0) {
      (**(code **)(*(int *)this + 0x2c))(this);
    }
    if (this[0x20] != (ImageBuf)0x0) {
      (**(code **)(*mMapper + 0x3c))(arStack_30,mMapper,*(undefined4 *)(this + 0xc));
      *(undefined4 *)(this + 0xc) = 0;
      *(undefined4 *)(this + 0x10) = 0;
      android::hardware::details::return_status::~return_status(arStack_30);
    }
  }
  libunwind::AbstractUnwindCursor::~AbstractUnwindCursor();
  if (__stack_chk_guard == local_14) {
    return this;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// cacao::ImageBuf::~ImageBuf()

void __thiscall cacao::ImageBuf::~ImageBuf(ImageBuf *this)

{
  ImageBuf *this_00;
  
  this_00 = ~ImageBuf(this);
  ObjectBase::operator_delete((ObjectBase *)this_00);
  return;
}



// cacao::ImageBuf::getBufSize() const

undefined4 __thiscall cacao::ImageBuf::getBufSize(ImageBuf *this)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 != 0) {
    return *(undefined4 *)(this + 0x14);
  }
  __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","getBufSize");
  return 0;
}



// cacao::ImageBuf::isValid() const

undefined4 __thiscall cacao::ImageBuf::isValid(ImageBuf *this)

{
  if (*(int *)(this + 0xc) != 0) {
    return 1;
  }
  __android_log_print(6,"CacaoImageBuf","Failed to validate");
  return 0;
}



// cacao::ImageBuf::getBufAddress()

int __thiscall cacao::ImageBuf::getBufAddress(ImageBuf *this)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 == 0) {
    __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","getBufAddress");
    return 0;
  }
  if (*(int *)(this + 0x10) != 0) {
    return *(int *)(this + 0x10);
  }
  (**(code **)(*(int *)this + 0x28))(this);
  return *(int *)(this + 0x10);
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// cacao::ImageBuf::getImageSize() const

void __cdecl cacao::ImageBuf::getImageSize(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + 8);
  *param_1 = *(undefined4 *)(param_2 + 4);
  param_1[1] = uVar1;
  return;
}



// cacao::ImageBuf::getDirtyFlag() const

bool __thiscall cacao::ImageBuf::getDirtyFlag(ImageBuf *this)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 != 0) {
    return this[0x21] != (ImageBuf)0x0;
  }
  return false;
}



// cacao::ImageBuf::setDirtyFlag(bool)

void __thiscall cacao::ImageBuf::setDirtyFlag(ImageBuf *this,ImageBuf param_2)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 != 0) {
    this[0x21] = param_2;
    return;
  }
  __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","setDirtyFlag");
  return;
}



// cacao::ImageBuf::clearCache()

void __thiscall cacao::ImageBuf::clearCache(ImageBuf *this)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  int local_6c;
  int local_68 [5];
  undefined1 local_54;
  hidl_handle ahStack_50 [16];
  undefined *local_40;
  undefined4 *local_3c;
  int *local_38;
  function<> *local_30;
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_6c = 0;
  iVar1 = isValid(this);
  if ((iVar1 == 0) || (mMapper == (int *)0x0)) {
    __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","clearCache");
    local_6c = -0x65;
  }
  else {
    local_70 = 0;
    local_78 = *(undefined4 *)(this + 4);
    uStack_74 = *(undefined4 *)(this + 8);
    uVar3 = *(undefined4 *)(this + 0xc);
    local_80 = 0;
    uStack_7c = 0;
    uVar2 = android::hardware::hidl_handle::hidl_handle(ahStack_50);
    local_38 = &local_6c;
    local_3c = &local_70;
    local_40 = &DAT_000187f4;
    local_30 = (function<> *)&local_40;
    (**(code **)(*mMapper + 0x40))
              (local_68,mMapper,uVar3,*(code **)(*mMapper + 0x40),0x66,0,&local_80,uVar2,
               (function<> *)&local_40);
    std::function<>::~function((function<> *)&local_40);
    local_54 = 1;
    if (local_68[0] != 0) {
      __android_log_print(6,"CacaoImageBuf","lock buffer failed");
      local_6c = -0x6f;
    }
    android::hardware::details::return_status::~return_status((return_status *)local_68);
    android::hardware::hidl_handle::~hidl_handle(ahStack_50);
    if (-1 < local_6c) {
      this[0x21] = (ImageBuf)0x0;
      *(undefined4 *)(this + 0x10) = local_70;
    }
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// cacao::ImageBuf::flushCache()

void __thiscall cacao::ImageBuf::flushCache(ImageBuf *this)

{
  int iVar1;
  int local_50;
  int local_4c;
  int local_48 [5];
  undefined1 local_34;
  undefined *local_30;
  undefined1 *local_2c;
  int *local_28;
  function<> *local_20;
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_4c = 0;
  iVar1 = isValid(this);
  if ((iVar1 == 0) || (mMapper == (int *)0x0)) {
    __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","flushCache");
    local_4c = -0x65;
  }
  else {
    local_50 = -1;
    local_28 = &local_4c;
    local_30 = &DAT_00018818;
    local_2c = (undefined1 *)&local_50;
    local_20 = (function<> *)&local_30;
    (**(code **)(*mMapper + 0x48))
              (local_48,mMapper,*(undefined4 *)(this + 0xc),(function<> *)&local_30);
    std::function<>::~function((function<> *)&local_30);
    local_34 = 1;
    if (local_48[0] != 0) {
      __android_log_print(6,"CacaoImageBuf","unlock buffer failed");
      local_4c = -0x6f;
    }
    android::hardware::details::return_status::~return_status((return_status *)local_48);
    if (-1 < local_4c) {
      this[0x21] = (ImageBuf)0x0;
    }
    close(local_50);
  }
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(local_4c);
}



// cacao::ImageBuf::flushAndClearCache()

void __thiscall cacao::ImageBuf::flushAndClearCache(ImageBuf *this)

{
  int iVar1;
  
  if (((this[0x21] != (ImageBuf)0x0) && (*(int *)(this + 0x10) != 0)) &&
     (iVar1 = (**(code **)(*(int *)this + 0x2c))(this), iVar1 < 0)) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00011544. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(*(int *)this + 0x28))(this);
  return;
}



// cacao::ImageBuf::getDataSize() const

undefined4 __thiscall cacao::ImageBuf::getDataSize(ImageBuf *this)

{
  return *(undefined4 *)(this + 0x1c);
}



// cacao::ImageBuf::setDataSize(unsigned int)

void __thiscall cacao::ImageBuf::setDataSize(ImageBuf *this,undefined4 param_1)

{
  int iVar1;
  
  iVar1 = isValid(this);
  if (iVar1 != 0) {
    *(undefined4 *)(this + 0x1c) = param_1;
    return;
  }
  __android_log_print(6,"CacaoImageBuf","%s: buffer is not ready","setDataSize");
  return;
}



// cacao::ImageBuf::getDataSpace() const

undefined4 __thiscall cacao::ImageBuf::getDataSpace(ImageBuf *this)

{
  return *(undefined4 *)(this + 0x18);
}



// cacao::ImageBuf::getClassName() const

char * cacao::ImageBuf::getClassName(void)

{
  return "ImageBuf";
}



// cacao::ImageBuf::getNative() const

undefined4 __thiscall cacao::ImageBuf::getNative(ImageBuf *this)

{
  return *(undefined4 *)(this + 0xc);
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat, cacao::DataSpace)::$_0,
// std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int, cacao::ImageFormat,
// cacao::DataSpace)::$_0>, void (android::hardware::graphics::mapper::V2_0::Error,
// android::hardware::hidl_vec<unsigned int> const&)>::~__func()

void __thiscall std::__function::__func<>::~__func(__func<> *this)

{
  operator_delete(this);
  return;
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat, cacao::DataSpace)::$_0,
// std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int, cacao::ImageFormat,
// cacao::DataSpace)::$_0>, void (android::hardware::graphics::mapper::V2_0::Error,
// android::hardware::hidl_vec<unsigned int> const&)>::__clone() const

void __thiscall std::__function::__func<>::__clone(__func<> *this)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x10);
  *puVar1 = &DAT_00018788;
  *(undefined8 *)(puVar1 + 1) = *(undefined8 *)(this + 4);
  puVar1[3] = *(undefined4 *)(this + 0xc);
  return;
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat, cacao::DataSpace)::$_0,
// std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int, cacao::ImageFormat,
// cacao::DataSpace)::$_0>, void (android::hardware::graphics::mapper::V2_0::Error,
// android::hardware::hidl_vec<unsigned int> const&)>::__clone(std::__function::__base<void
// (android::hardware::graphics::mapper::V2_0::Error, android::hardware::hidl_vec<unsigned int>
// const&)>*) const

void __thiscall std::__function::__func<>::__clone(__func<> *this,undefined4 *param_1)

{
  undefined8 uVar1;
  
  *param_1 = &DAT_00018788;
  uVar1 = *(undefined8 *)(this + 4);
  param_1[3] = *(undefined4 *)(this + 0xc);
  *(undefined8 *)(param_1 + 1) = uVar1;
  return;
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat, cacao::DataSpace)::$_0,
// std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int, cacao::ImageFormat,
// cacao::DataSpace)::$_0>, void (android::hardware::graphics::mapper::V2_0::Error,
// android::hardware::hidl_vec<unsigned int>
// const&)>::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error&&,
// android::hardware::hidl_vec<unsigned int> const&)

void __thiscall
std::__function::__func<>::operator()(__func<> *this,undefined4 *param_1,hidl_vec<> *param_2)

{
  **(undefined4 **)(this + 4) = *param_1;
  if (**(int **)(this + 4) != 0) {
    __android_log_print(6,"CacaoImageBuf","create descriptor failed %d");
    **(undefined4 **)(this + 0xc) = 0xffffff91;
    return;
  }
  android::hardware::hidl_vec<>::operator=(*(hidl_vec<> **)(this + 8),param_2);
  return;
}



// android::hardware::hidl_vec<unsigned
// int>::TEMPNAMEPLACEHOLDERVALUE(android::hardware::hidl_vec<unsigned int> const&)

hidl_vec<> * __thiscall
android::hardware::hidl_vec<>::operator=(hidl_vec<> *this,hidl_vec<> *param_1)

{
  if (this != param_1) {
    if ((this[0xc] != (hidl_vec<>)0x0) && (*(void **)this != (void *)0x0)) {
      operator_delete__(*(void **)this);
    }
    copyFrom<>(this,(int *)param_1,*(uint *)(param_1 + 8));
  }
  return this;
}



// void android::hardware::hidl_vec<unsigned int>::copyFrom<android::hardware::hidl_vec<unsigned
// int> >(android::hardware::hidl_vec<unsigned int> const&, unsigned int)

void __thiscall
android::hardware::hidl_vec<>::copyFrom<>(hidl_vec<> *this,int *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  this[0xc] = (hidl_vec<>)0x1;
  *(uint *)(this + 8) = param_2;
  if (param_2 == 0) {
    *(undefined4 *)this = 0;
    return;
  }
  uVar3 = (uint)((ulonglong)param_2 * 4);
  if ((int)((ulonglong)param_2 * 4 >> 0x20) != 0) {
    uVar3 = 0xffffffff;
  }
  puVar1 = operator_new__(uVar3);
  __aeabi_memclr4(puVar1,uVar3);
  *(undefined4 **)this = puVar1;
  *puVar1 = *(undefined4 *)*param_1;
  if (param_2 != 1) {
    uVar3 = 1;
    iVar2 = 4;
    do {
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*(int *)this + iVar2) = *(undefined4 *)(*param_1 + iVar2);
      iVar2 = iVar2 + 4;
    } while (uVar3 != param_2);
  }
  return;
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat, cacao::DataSpace)::$_1,
// std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int, cacao::ImageFormat,
// cacao::DataSpace)::$_1>, void (android::hardware::graphics::mapper::V2_0::Error, unsigned int,
// android::hardware::hidl_vec<android::hardware::hidl_handle> const&)>::__clone() const

void __thiscall std::__function::__func<>::__clone(__func<> *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = operator_new(0xc);
  uVar2 = *(undefined4 *)(this + 4);
  uVar3 = *(undefined4 *)(this + 8);
  *puVar1 = &DAT_000187ac;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  return;
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat, cacao::DataSpace)::$_1,
// std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int, cacao::ImageFormat,
// cacao::DataSpace)::$_1>, void (android::hardware::graphics::mapper::V2_0::Error, unsigned int,
// android::hardware::hidl_vec<android::hardware::hidl_handle>
// const&)>::__clone(std::__function::__base<void (android::hardware::graphics::mapper::V2_0::Error,
// unsigned int, android::hardware::hidl_vec<android::hardware::hidl_handle> const&)>*) const

void __thiscall std::__function::__func<>::__clone(__func<> *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &DAT_000187ac;
  uVar1 = *(undefined4 *)(this + 8);
  param_1[1] = *(undefined4 *)(this + 4);
  param_1[2] = uVar1;
  return;
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat, cacao::DataSpace)::$_1,
// std::allocator<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int, cacao::ImageFormat,
// cacao::DataSpace)::$_1>, void (android::hardware::graphics::mapper::V2_0::Error, unsigned int,
// android::hardware::hidl_vec<android::hardware::hidl_handle>
// const&)>::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error&&, unsigned
// int&&, android::hardware::hidl_vec<android::hardware::hidl_handle> const&)

void __thiscall
std::__function::__func<>::operator()
          (__func<> *this,int *param_1,undefined4 param_3_00,undefined4 *param_3)

{
  int local_48 [5];
  undefined1 local_34;
  undefined *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  function<> *local_20;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (*param_1 == 0) {
    local_2c = *(undefined4 *)(this + 4);
    local_28 = *(undefined4 *)(this + 8);
    local_30 = &DAT_000187d0;
    local_20 = (function<> *)&local_30;
    (**(code **)(*cacao::ImageBuf::mMapper + 0x38))
              (local_48,cacao::ImageBuf::mMapper,*param_3,(function<> *)&local_30);
    function<>::~function((function<> *)&local_30);
    local_34 = 1;
    if (local_48[0] != 0) {
      __android_log_print(6,"CacaoImageBuf","import buffer failed");
      **(undefined4 **)(this + 8) = 0xffffff91;
    }
    android::hardware::details::return_status::~return_status((return_status *)local_48);
  }
  else {
    __android_log_print(6,"CacaoImageBuf","allocate buffer failed %d",*param_1);
    **(undefined4 **)(this + 8) = 0xffffff91;
  }
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat,
// cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error
// const&, unsigned int const&, android::hardware::hidl_vec<android::hardware::hidl_handle> const&)
// const::{lambda(auto:2, auto:3)#1}, std::allocator<std::allocator>, void
// (android::hardware::graphics::mapper::V2_0::Error, void*)>::__clone() const

void __thiscall std::__function::__func<>::operator()(__func<> *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = operator_new(0xc);
  uVar2 = *(undefined4 *)(this + 4);
  uVar3 = *(undefined4 *)(this + 8);
  *puVar1 = &DAT_000187d0;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  return;
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat,
// cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error
// const&, unsigned int const&, android::hardware::hidl_vec<android::hardware::hidl_handle> const&)
// const::{lambda(auto:2, auto:3)#1}, std::allocator<std::allocator>, void
// (android::hardware::graphics::mapper::V2_0::Error,
// void*)>::__clone(std::__function::__base<std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize,
// unsigned int, cacao::ImageFormat,
// cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error
// const&, unsigned int const&, android::hardware::hidl_vec<android::hardware::hidl_handle> const&)
// const::{lambda(auto:2, auto:3)#1}, std::allocator<std::allocator>, void
// (android::hardware::graphics::mapper::V2_0::Error, void*)> >*) const

void __thiscall std::__function::__func<>::operator()(__func<> *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &DAT_000187d0;
  uVar1 = *(undefined4 *)(this + 8);
  param_1[1] = *(undefined4 *)(this + 4);
  param_1[2] = uVar1;
  return;
}



// std::__function::__func<cacao::ImageBuf::ImageBuf(cacao::ImageSize, unsigned int,
// cacao::ImageFormat,
// cacao::DataSpace)::$_1::TEMPNAMEPLACEHOLDERVALUE<android::hardware::graphics::mapper::V2_0::Error,
// unsigned int, android::hardware::hidl_vec<android::hardware::hidl_handle>
// >(android::hardware::graphics::mapper::V2_0::Error const&, unsigned int const&,
// android::hardware::hidl_vec<android::hardware::hidl_handle> const&) const::{lambda(auto:2,
// auto:3)#1}, std::allocator<std::allocator>, void
// (android::hardware::graphics::mapper::V2_0::Error,
// void*)>::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error&&, void
// (&&)(android::hardware::graphics::mapper::V2_0::Error, void*))

void __thiscall
std::__function::__func<>::operator()(__func<> *this,int *param_1,undefined4 *param_2)

{
  int local_30 [5];
  undefined1 local_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  if (*param_1 == 0) {
    *(undefined4 *)(*(int *)(this + 4) + 0xc) = *param_2;
  }
  else {
    __android_log_print(6,"CacaoImageBuf","import buffer failed %d");
    (**(code **)(*cacao::ImageBuf::mMapper + 0x3c))(local_30,cacao::ImageBuf::mMapper,*param_2);
    local_1c = 1;
    if (local_30[0] != 0) {
      **(undefined4 **)(this + 8) = 0xffffff91;
    }
    android::hardware::details::return_status::~return_status((return_status *)local_30);
  }
  if (__stack_chk_guard == local_14) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// std::__function::__func<cacao::ImageBuf::clearCache()::$_2,
// std::allocator<cacao::ImageBuf::clearCache()::$_2>, void
// (android::hardware::graphics::mapper::V2_0::Error, void*)>::__clone() const

void __thiscall std::__function::__func<>::__clone(__func<> *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = operator_new(0xc);
  uVar2 = *(undefined4 *)(this + 4);
  uVar3 = *(undefined4 *)(this + 8);
  *puVar1 = &DAT_000187f4;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  return;
}



// std::__function::__func<cacao::ImageBuf::clearCache()::$_2,
// std::allocator<cacao::ImageBuf::clearCache()::$_2>, void
// (android::hardware::graphics::mapper::V2_0::Error, void*)>::__clone(std::__function::__base<void
// (android::hardware::graphics::mapper::V2_0::Error, void*)>*) const

void __thiscall std::__function::__func<>::__clone(__func<> *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &DAT_000187f4;
  uVar1 = *(undefined4 *)(this + 8);
  param_1[1] = *(undefined4 *)(this + 4);
  param_1[2] = uVar1;
  return;
}



// std::__function::__func<cacao::ImageBuf::clearCache()::$_2,
// std::allocator<cacao::ImageBuf::clearCache()::$_2>, void
// (android::hardware::graphics::mapper::V2_0::Error,
// void*)>::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error&&, void*&&)

void __thiscall
std::__function::__func<>::operator()(__func<> *this,int *param_1,undefined4 *param_2)

{
  __func<> *p_Var1;
  undefined4 uVar2;
  
  if (*param_1 == 0) {
    uVar2 = *param_2;
    p_Var1 = this + 4;
  }
  else {
    __android_log_print(6,"CacaoImageBuf","lock buffer failed %d");
    p_Var1 = this + 8;
    uVar2 = 0xffffff91;
  }
  **(undefined4 **)p_Var1 = uVar2;
  return;
}



// std::__function::__func<cacao::ImageBuf::flushCache()::$_3,
// std::allocator<cacao::ImageBuf::flushCache()::$_3>, void
// (android::hardware::graphics::mapper::V2_0::Error, android::hardware::hidl_handle
// const&)>::__clone() const

void __thiscall std::__function::__func<>::__clone(__func<> *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = operator_new(0xc);
  uVar2 = *(undefined4 *)(this + 4);
  uVar3 = *(undefined4 *)(this + 8);
  *puVar1 = &DAT_00018818;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  return;
}



// std::__function::__func<cacao::ImageBuf::flushCache()::$_3,
// std::allocator<cacao::ImageBuf::flushCache()::$_3>, void
// (android::hardware::graphics::mapper::V2_0::Error, android::hardware::hidl_handle
// const&)>::__clone(std::__function::__base<void (android::hardware::graphics::mapper::V2_0::Error,
// android::hardware::hidl_handle const&)>*) const

void __thiscall std::__function::__func<>::__clone(__func<> *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &DAT_00018818;
  uVar1 = *(undefined4 *)(this + 8);
  param_1[1] = *(undefined4 *)(this + 4);
  param_1[2] = uVar1;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// std::__function::__func<cacao::ImageBuf::flushCache()::$_3,
// std::allocator<cacao::ImageBuf::flushCache()::$_3>, void
// (android::hardware::graphics::mapper::V2_0::Error, android::hardware::hidl_handle
// const&)>::TEMPNAMEPLACEHOLDERVALUE(android::hardware::graphics::mapper::V2_0::Error&&,
// android::hardware::hidl_handle const&)

void __cdecl std::__function::__func<>::operator()(int param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 == 0) {
    iVar1 = android::hardware::hidl_handle::getNativeHandle();
    if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 1)) &&
       (iVar1 = dup(*(int *)(iVar1 + 0xc)), -1 < iVar1)) {
      **(int **)(param_1 + 4) = iVar1;
      return;
    }
  }
  else {
    __android_log_print(6,"CacaoImageBuf","unlock buffer failed %d");
    **(undefined4 **)(param_1 + 8) = 0xffffff91;
  }
  return;
}



// cacao::ProcessFactory::createProcess()

void cacao::ProcessFactory::createProcess(void)

{
  android::Cacao::create();
  return;
}



// cacao::ProcessFactory::createEvent(unsigned int, cacao::ISerialize::SerializedData*)

undefined4 cacao::ProcessFactory::createEvent(void)

{
  return 0;
}



// cacao::ProcessFactory::getJpegBufferSize(cacao::ImageSize)

void cacao::ProcessFactory::getJpegBufferSize(void)

{
  Cacao *in_r0;
  undefined4 in_r1;
  
  android::Cacao::getJpegBufferSize(in_r0,in_r1);
  return;
}



// cacao::ProcessCtrlCapsFactory::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&, cacao::Caps*)

void cacao::ProcessCtrlCapsFactory::getCaps(void)

{
  undefined4 in_r0;
  int *in_r1;
  
  android::Cacao::getCaps(in_r0,in_r1);
  return;
}



uint * decode_eht_entry(uint *param_1,undefined4 *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  if (-1 < (int)uVar1) {
    *param_2 = 1;
    *param_3 = (param_1[1] >> 0x18) * 4 + 4;
    return param_1 + 1;
  }
  uVar2 = (uVar1 << 4) >> 0x1c;
  if ((uVar2 != 3) && (uVar2 != 1)) {
    if (uVar2 == 0) {
      *param_3 = 4;
      *param_2 = 1;
      return param_1;
    }
    return (uint *)0x0;
  }
  *param_3 = ((uVar1 << 8) >> 0x18) * 4 + 4;
  *param_2 = 2;
  return param_1;
}



void _Unwind_VRS_Interpret(int *param_1,int param_2,uint param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined4 *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_3 < param_4) {
    bVar4 = false;
LAB_00011f34:
    uVar8 = param_3 + 1;
    bVar2 = *(byte *)(param_2 + (param_3 ^ 3));
    uVar9 = (uint)bVar2;
    uVar7 = (uint)(char)bVar2;
    if (-1 < (int)uVar7) {
      unw_get_reg(param_1,0xd,&local_2c);
      iVar5 = (uVar9 & 0x3f) * -4 + -4;
      if ((bVar2 & 0x40) == 0) {
        iVar5 = uVar9 * 4 + 4;
      }
      local_2c = (undefined4 *)((int)local_2c + iVar5);
LAB_00011f76:
      unw_set_reg(param_1,0xd,local_2c);
      param_3 = uVar8;
      goto joined_r0x00011e38;
    }
    switch((uVar9 & 0xf0) - 0x80 >> 4) {
    case 0:
      if (param_4 <= uVar8) break;
      bVar1 = *(byte *)(param_2 + (uVar8 ^ 3));
      uVar8 = (uint)bVar1;
      if ((bVar2 & 0xf) != 0 || uVar8 != 0) {
        if ((int)(uVar9 << 0x1c) < 0) {
          bVar4 = true;
        }
        iVar5 = unw_get_reg(param_1,0xd,&local_2c);
        if (iVar5 == 0) {
          if ((bVar1 & 1) != 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,4,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar8 << 0x1e) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,5,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar8 << 0x1d) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,6,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar8 << 0x1c) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,7,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar8 << 0x1b) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,8,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar8 << 0x1a) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,9,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar8 << 0x19) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,10,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((char)bVar1 < '\0') {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xb,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((bVar2 & 1) != 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xc,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar9 << 0x1e) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xd,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
            bVar10 = true;
            puVar3 = local_2c;
          }
          else {
            bVar10 = false;
            puVar3 = local_2c;
          }
          local_2c = puVar3;
          if ((int)(uVar9 << 0x1d) < 0) {
            local_2c = puVar3 + 1;
            iVar5 = unw_set_reg(param_1,0xe,*puVar3);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar9 << 0x1c) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xf,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if (!bVar10) {
            unw_set_reg(param_1,0xd,local_2c);
          }
        }
joined_r0x00011e38:
        param_3 = param_3 + 2;
        goto joined_r0x00011e38;
      }
      uVar6 = 9;
      goto switchD_00011b40_caseD_b4;
    case 1:
      if ((uVar7 & 0xf | 2) != 0xf) {
        unw_get_reg(param_1,uVar7 & 0xf,&local_2c);
        goto LAB_00011f76;
      }
      break;
    case 2:
      iVar5 = unw_get_reg(param_1,0xd,&local_2c);
      param_3 = uVar8;
      if (iVar5 == 0) {
        uVar6 = *local_2c;
        local_2c = local_2c + 1;
        iVar5 = unw_set_reg(param_1,4,uVar6);
        if (iVar5 == 0) {
          uVar7 = (0x20 << (uVar7 & 7)) - 0x10;
          if ((int)(uVar7 * 0x4000000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,5,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar7 * 0x2000000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,6,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((char)uVar7 < '\0') {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,7,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar7 * 0x800000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,8,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar7 * 0x400000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,9,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar7 * 0x200000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,10,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar7 * 0x100000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xb,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar7 * 0x80000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xc,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if ((int)(uVar7 * 0x40000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xd,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
            bVar10 = true;
          }
          else {
            bVar10 = false;
          }
          if ((int)((uVar7 | uVar9 << 0xb) << 0x11) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xe,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if (0x7fffffff < (uint)(int)(short)uVar7) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xf,uVar6);
            if (iVar5 != 0) goto joined_r0x00011e38;
          }
          if (!bVar10) goto LAB_00011f76;
        }
      }
joined_r0x00011e38:
      if (param_4 <= param_3) goto switchD_00011b40_caseD_b0;
      goto LAB_00011f34;
    case 3:
      uVar6 = 9;
      switch(uVar9) {
      case 0xb0:
        goto switchD_00011b40_caseD_b0;
      case 0xb1:
        if (uVar8 < param_4) {
          bVar2 = *(byte *)(param_2 + (uVar8 ^ 3));
          uVar7 = (uint)bVar2;
          uVar6 = 9;
          if ((uVar7 != 0) && ((bVar2 & 0xf0) == 0)) {
            iVar5 = unw_get_reg(param_1,0xd,&local_2c);
            uVar8 = param_3 + 2;
            param_3 = uVar8;
            if (iVar5 == 0) {
              if ((bVar2 & 1) != 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,0,uVar6);
                if (iVar5 != 0) goto joined_r0x00011e38;
              }
              if ((int)(uVar7 << 0x1e) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,1,uVar6);
                if (iVar5 != 0) goto joined_r0x00011e38;
              }
              if ((int)(uVar7 << 0x1d) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,2,uVar6);
                if (iVar5 != 0) goto joined_r0x00011e38;
              }
              if ((int)(uVar7 << 0x1c) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,3,uVar6);
                if (iVar5 != 0) goto joined_r0x00011e38;
              }
              if ((int)(uVar7 << 0x1b) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,4,uVar6);
                if (iVar5 != 0) goto joined_r0x00011e38;
              }
              if ((int)(uVar7 << 0x1a) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,5,uVar6);
                if (iVar5 != 0) goto joined_r0x00011e38;
              }
              if ((int)(uVar7 << 0x19) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,6,uVar6);
                if (iVar5 != 0) goto joined_r0x00011e38;
              }
              if (0x7fffffff < (uint)(int)(char)bVar2) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,7,uVar6);
                if (iVar5 != 0) goto joined_r0x00011e38;
              }
              goto LAB_00011f76;
            }
            goto joined_r0x00011e38;
          }
          goto switchD_00011b40_caseD_b4;
        }
        break;
      case 0xb2:
        if (uVar8 < param_4) {
          uVar9 = 0;
          uVar7 = 0;
          uVar8 = param_3 + 2;
          while (bVar2 = *(byte *)(param_2 + (uVar8 - 1 ^ 3)),
                uVar9 = uVar9 | (bVar2 & 0x7f) << (uVar7 & 0xff), (char)bVar2 < '\0') {
            uVar7 = uVar7 + 7;
            bVar10 = param_4 <= uVar8;
            uVar8 = uVar8 + 1;
            if (bVar10) goto switchD_000119ba_default;
          }
          unw_get_reg(param_1,0xd,&local_2c);
          local_2c = local_2c + uVar9 + 0x81;
          goto LAB_00011f76;
        }
        break;
      case 0xb3:
        uVar7 = 1;
        uVar8 = (uint)*(byte *)(param_2 + (uVar8 ^ 3));
        uVar8 = (uVar8 & 0xf) + 1 | (uVar8 & 0xf0) << 0xc;
LAB_00011e2a:
        _Unwind_VRS_Pop(param_1,1,uVar8,uVar7);
        goto joined_r0x00011e38;
      case 0xb4:
      case 0xb5:
      case 0xb6:
      case 0xb7:
        goto switchD_00011b40_caseD_b4;
      default:
        uVar9 = 1;
LAB_00011dc8:
        _Unwind_VRS_Pop(param_1,1,(uVar7 & 7) + 1 | 0x80000,uVar9);
        param_3 = uVar8;
        goto joined_r0x00011e38;
      }
      break;
    case 4:
      if ((uVar9 & 0xfe) == 200) {
        bVar2 = *(byte *)(param_2 + (uVar8 ^ 3));
        uVar9 = bVar2 & 0xf;
        uVar8 = (uint)(bVar2 >> 4) | (uint)(uVar7 == 0xffffffc8) << 4;
        if (uVar8 + uVar9 < 0x20) {
          uVar7 = 5;
          uVar8 = uVar9 + 1 | uVar8 << 0x10;
          goto LAB_00011e2a;
        }
      }
      break;
    case 5:
      if (-1 < (int)(uVar9 << 0x1c)) {
        uVar9 = 5;
        goto LAB_00011dc8;
      }
    }
switchD_000119ba_default:
    uVar6 = 9;
    goto switchD_00011b40_caseD_b4;
  }
LAB_00011f88:
  unw_get_reg(param_1,0xe,&local_2c);
  unw_set_reg(param_1,0xf,local_2c);
LAB_00011f9c:
  uVar6 = 8;
switchD_00011b40_caseD_b4:
  if (__stack_chk_guard != local_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail(uVar6);
  }
  return;
switchD_00011b40_caseD_b0:
  if (bVar4) goto LAB_00011f9c;
  goto LAB_00011f88;
}



undefined4 _Unwind_VRS_Get(int *param_1,int param_2,uint param_3,int param_4,undefined8 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    if (param_4 == 5) {
      if (0x1f < param_3) {
        return 2;
      }
    }
    else {
      if ((param_4 != 1) || (0xf < param_3)) {
        return 2;
      }
      unw_save_vfp_as_X(param_1);
    }
    iVar1 = unw_get_fpreg(param_1,param_3 + 0x100,param_5);
  }
  else {
    if (param_2 != 0) {
      fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","_Unwind_VRS_Get_Internal",
              "external/libunwind_llvm/src/Unwind-EHABI.cpp",0x35f,"unsupported register class");
      fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
      abort();
    }
    if (0xf < param_3) {
      return 2;
    }
    if (param_4 != 0) {
      return 2;
    }
    iVar1 = unw_get_reg(param_1,param_3,(undefined4 *)param_5);
  }
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 2;
  }
  return uVar2;
}



undefined4 _Unwind_VRS_Set(int *param_1,int param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    if (param_4 == 5) {
      if (0x1f < param_3) {
        return 2;
      }
    }
    else {
      if ((param_4 != 1) || (0xf < param_3)) {
        return 2;
      }
      unw_save_vfp_as_X(param_1);
    }
    iVar1 = unw_set_fpreg(param_1,param_3 + 0x100,*param_5,param_5[1]);
  }
  else {
    if (param_2 != 0) {
      fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","_Unwind_VRS_Set",
              "external/libunwind_llvm/src/Unwind-EHABI.cpp",0x329,"unsupported register class");
      fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
      abort();
    }
    if (0xf < param_3) {
      return 2;
    }
    if (param_4 != 0) {
      return 2;
    }
    iVar1 = unw_set_reg(param_1,param_3,*param_5);
  }
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 2;
  }
  return uVar2;
}



undefined4 _Unwind_VRS_Pop(int *param_1,int param_2,uint param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int *local_30;
  int iStack_2c;
  int *local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (param_2 == 1) {
    if (((param_4 | 4) != 5) || (iVar2 = unw_get_reg(param_1,0xd,&local_24), iVar2 != 0))
    goto LAB_00012284;
    if ((param_3 & 0xffff) != 0) {
      uVar6 = param_3 >> 0x10;
      uVar4 = uVar6 + (param_3 & 0xffff);
      do {
        local_30 = (int *)*local_24;
        iStack_2c = local_24[1];
        local_24 = local_24 + 2;
        iVar2 = _Unwind_VRS_Set(param_1,1,uVar6,param_4,&local_30);
        if (iVar2 != 0) goto LAB_00012284;
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
    }
    piVar3 = local_24;
    if (param_4 == 1) {
      local_24 = local_24 + 1;
      piVar3 = local_24;
    }
  }
  else {
    if (param_2 != 0) {
      fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","_Unwind_VRS_Pop",
              "external/libunwind_llvm/src/Unwind-EHABI.cpp",0x3b9,"unsupported register class");
      fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
      abort();
    }
    if ((param_4 != 0) || (iVar2 = unw_get_reg(param_1,0xd,&local_30), iVar2 != 0)) {
LAB_00012284:
      uVar5 = 2;
      goto LAB_00012286;
    }
    if ((param_3 & 1) != 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x1e) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,1,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x1d) < 0) {
      uVar5 = 2;
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,2,iVar2);
      if (iVar2 != 0) goto LAB_00012286;
    }
    if ((int)(param_3 << 0x1c) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,3,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x1b) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,4,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x1a) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,5,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x19) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,6,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((char)param_3 < '\0') {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,7,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x17) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,8,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x16) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,9,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x15) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,10,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x14) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0xb,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x13) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0xc,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((int)(param_3 << 0x12) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0xd,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
      bVar1 = true;
      piVar3 = local_30;
    }
    else {
      bVar1 = false;
      piVar3 = local_30;
    }
    local_30 = piVar3;
    if ((int)(param_3 << 0x11) < 0) {
      local_30 = piVar3 + 1;
      iVar2 = unw_set_reg(param_1,0xe,*piVar3);
      if (iVar2 != 0) goto LAB_00012284;
    }
    if ((short)param_3 < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0xf,iVar2);
      if (iVar2 != 0) goto LAB_00012284;
    }
    piVar3 = local_30;
    if (bVar1) {
      uVar5 = 0;
      goto LAB_00012286;
    }
  }
  iVar2 = unw_set_reg(param_1,0xd,piVar3);
  uVar5 = 0;
  if (iVar2 != 0) {
    uVar5 = 2;
  }
LAB_00012286:
  if (__stack_chk_guard == local_20) {
    return uVar5;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void __aeabi_unwind_cpp_pr0(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_3c [8];
  int *local_34;
  int local_14;
  
  local_14 = __stack_chk_guard;
  unw_get_proc_info(param_3,(int)auStack_3c);
  if (((*(byte *)(param_2 + 0x50) & 1) == 0) && (*local_34 != 0)) {
    uVar1 = 9;
  }
  else {
    iVar2 = unw_step(param_3);
    uVar1 = 9;
    if (iVar2 == 1) {
      uVar1 = 8;
    }
  }
  if (__stack_chk_guard == local_14) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar1);
}



void __aeabi_unwind_cpp_pr1(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_3c [8];
  int *local_34;
  int local_14;
  
  local_14 = __stack_chk_guard;
  unw_get_proc_info(param_3,(int)auStack_3c);
  if (((*(byte *)(param_2 + 0x50) & 1) == 0) && (*local_34 != 0)) {
    uVar1 = 9;
  }
  else {
    iVar2 = unw_step(param_3);
    uVar1 = 9;
    if (iVar2 == 1) {
      uVar1 = 8;
    }
  }
  if (__stack_chk_guard == local_14) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar1);
}



void __aeabi_unwind_cpp_pr2(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_3c [8];
  int *local_34;
  int local_14;
  
  local_14 = __stack_chk_guard;
  unw_get_proc_info(param_3,(int)auStack_3c);
  if (((*(byte *)(param_2 + 0x50) & 1) == 0) && (*local_34 != 0)) {
    uVar1 = 9;
  }
  else {
    iVar2 = unw_step(param_3);
    uVar1 = 9;
    if (iVar2 == 1) {
      uVar1 = 8;
    }
  }
  if (__stack_chk_guard == local_14) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar1);
}



void _Unwind_RaiseException(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8a0 [3];
  code *local_894;
  undefined4 local_88c;
  undefined4 local_880;
  int aiStack_878 [280];
  int aiStack_418 [256];
  int local_18;
  
  local_18 = __stack_chk_guard;
  unw_getcontext((int)aiStack_418,param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 0xc) = 0;
  unw_init_local(aiStack_878,aiStack_418);
  iVar1 = unw_get_proc_info(aiStack_878,(int)local_8a0);
  if (iVar1 == 0) {
    do {
      if (local_894 != (code *)0x0) {
        *(undefined4 *)(param_1 + 0x48) = local_8a0[0];
        *(undefined4 *)(param_1 + 0x4c) = local_880;
        *(undefined4 *)(param_1 + 0x50) = local_88c;
        iVar1 = (*local_894)(0,param_1,aiStack_878);
        if (iVar1 != 8) {
          if (iVar1 == 6) {
            unwind_phase2(aiStack_418,aiStack_878,param_1,0);
            uVar2 = 2;
            goto LAB_00012510;
          }
          if (iVar1 == 9) {
            uVar2 = 9;
            goto LAB_00012510;
          }
          break;
        }
      }
      iVar1 = unw_get_proc_info(aiStack_878,(int)local_8a0);
    } while (iVar1 == 0);
  }
  uVar2 = 3;
LAB_00012510:
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar2);
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// unwind_phase2(unw_context_t*, unw_cursor_t*, _Unwind_Control_Block*, bool)

void __cdecl unwind_phase2(int *param_1,int *param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_58;
  undefined4 local_54 [3];
  code *local_48;
  undefined4 local_40;
  undefined4 local_34;
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  unw_init_local(param_2,param_1);
  iVar3 = 0;
  do {
    uVar2 = param_4 & 1;
    if ((iVar3 == 1) && (uVar2 != 0)) {
      unw_set_reg(param_2,-1,*(undefined4 *)(param_3 + 0x10));
      param_4 = 0;
    }
    unw_get_reg(param_2,0xfffffffe,&local_2c);
    iVar1 = unw_get_proc_info(param_2,(int)local_54);
    if (iVar1 != 0) goto LAB_00012624;
    if (local_48 != (code *)0x0) {
      *(undefined4 *)(param_3 + 0x48) = local_54[0];
      *(undefined4 *)(param_3 + 0x4c) = local_34;
      *(undefined4 *)(param_3 + 0x50) = local_40;
      iVar1 = (*local_48)(uVar2 + 1,param_3,param_2);
      if (iVar1 == 7) {
        unw_get_reg(param_2,0xffffffff,&local_58);
        *(undefined4 *)(param_3 + 0x10) = local_58;
        unw_resume(param_2);
LAB_00012624:
        if (__stack_chk_guard == local_28) {
          return;
        }
                    // WARNING: Subroutine does not return
        __stack_chk_fail();
      }
      if (iVar1 != 8) {
        if (iVar1 == 9) {
                    // WARNING: Subroutine does not return
          abort();
        }
        goto LAB_00012624;
      }
      if (local_2c == *(int *)(param_3 + 0x20)) {
        fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","unwind_phase2",
                "external/libunwind_llvm/src/Unwind-EHABI.cpp",0x269,
                "during phase1 personality function said it would stop here, but now in phase2 it did not stop here"
               );
        fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
        abort();
      }
    }
    iVar3 = iVar3 + 1;
  } while( true );
}



void _Unwind_Resume(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int aiStack_870 [280];
  int aiStack_410 [256];
  
  unw_getcontext((int)aiStack_410,param_2,param_3,param_4);
  unwind_phase2(aiStack_410,aiStack_870,param_1,1);
  fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","_Unwind_Resume",
          "external/libunwind_llvm/src/Unwind-EHABI.cpp",0x2cf,"_Unwind_Resume() can\'t return");
  fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
  abort();
}



void _Unwind_GetLanguageSpecificData(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_34 [8];
  undefined4 local_2c;
  int local_c;
  
  local_c = __stack_chk_guard;
  iVar1 = unw_get_proc_info(param_1,(int)auStack_34);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = local_2c;
  }
  if (__stack_chk_guard == local_c) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar2);
}



void _Unwind_GetRegionStart(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_34 [10];
  int local_c;
  
  local_c = __stack_chk_guard;
  iVar1 = unw_get_proc_info(param_1,(int)local_34);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = local_34[0];
  }
  if (__stack_chk_guard == local_c) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar2);
}



void _Unwind_DeleteException(int param_1)

{
  if (*(code **)(param_1 + 8) != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00012734. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(param_1 + 8))(1);
    return;
  }
  return;
}



undefined4 __gnu_unwind_frame(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = unw_step(param_2);
  uVar2 = 9;
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 unw_getcontext(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 unaff_lr;
  
  *(int *)param_1 = param_1;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x10) = unaff_r4;
  *(undefined4 *)(param_1 + 0x14) = unaff_r5;
  *(undefined4 *)(param_1 + 0x18) = unaff_r6;
  *(undefined4 *)(param_1 + 0x1c) = unaff_r7;
  *(undefined4 *)(param_1 + 0x20) = unaff_r8;
  *(undefined4 *)(param_1 + 0x24) = unaff_r9;
  *(undefined4 *)(param_1 + 0x28) = unaff_r10;
  *(undefined4 *)(param_1 + 0x2c) = unaff_r11;
  *(undefined4 *)(param_1 + 0x30) = in_r12;
  *(BADSPACEBASE **)(param_1 + 0x34) = register0x00000054;
  *(undefined4 *)(param_1 + 0x38) = unaff_lr;
  *(undefined4 *)(param_1 + 0x3c) = unaff_lr;
  return 0;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// libunwind::Registers_arm::saveVFPWithFSTMD(unsigned long long*)

void __cdecl libunwind::Registers_arm::saveVFPWithFSTMD(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// libunwind::Registers_arm::saveVFPWithFSTMX(unsigned long long*)

void __cdecl libunwind::Registers_arm::saveVFPWithFSTMX(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// libunwind::Registers_arm::saveVFPv3(unsigned long long*)

void __cdecl libunwind::Registers_arm::saveVFPv3(undefined8 *param_1)

{
  undefined8 in_d16;
  undefined8 in_d17;
  undefined8 in_d18;
  undefined8 in_d19;
  undefined8 in_d20;
  undefined8 in_d21;
  undefined8 in_d22;
  undefined8 in_d23;
  undefined8 in_d24;
  undefined8 in_d25;
  undefined8 in_d26;
  undefined8 in_d27;
  undefined8 in_d28;
  undefined8 in_d29;
  undefined8 in_d30;
  undefined8 in_d31;
  
  *param_1 = in_d16;
  param_1[1] = in_d17;
  param_1[2] = in_d18;
  param_1[3] = in_d19;
  param_1[4] = in_d20;
  param_1[5] = in_d21;
  param_1[6] = in_d22;
  param_1[7] = in_d23;
  param_1[8] = in_d24;
  param_1[9] = in_d25;
  param_1[10] = in_d26;
  param_1[0xb] = in_d27;
  param_1[0xc] = in_d28;
  param_1[0xd] = in_d29;
  param_1[0xe] = in_d30;
  param_1[0xf] = in_d31;
  return;
}



undefined4 unw_init_local(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined1 *)((int)param_1 + 0x4a) = 0;
  *param_1 = (int)&DAT_0001883c;
  param_1[1] = (int)&DAT_0001902c;
  iVar1 = *param_2;
  iVar2 = param_2[1];
  iVar3 = param_2[2];
  iVar4 = param_2[3];
  uVar5 = *(undefined8 *)(param_2 + 10);
  uVar6 = *(undefined8 *)(param_2 + 4);
  uVar7 = *(undefined8 *)(param_2 + 6);
  uVar8 = *(undefined8 *)(param_2 + 0xc);
  uVar9 = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_1 + 10) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_1 + 0xc) = uVar5;
  *(undefined8 *)(param_1 + 6) = uVar6;
  *(undefined8 *)(param_1 + 8) = uVar7;
  param_1[2] = iVar1;
  param_1[3] = iVar2;
  param_1[6] = iVar3;
  param_1[7] = iVar4;
  *(undefined8 *)(param_1 + 0xe) = uVar8;
  *(undefined8 *)(param_1 + 0x10) = uVar9;
  __aeabi_memclr(param_1 + 0x14,0x88);
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  *(undefined2 *)(param_1 + 0x60) = 0;
  param_1[0x5f] = 0;
  param_1[0x5e] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  (**(code **)(*param_1 + 0x34))(param_1,0);
  return 0;
}



undefined4 unw_get_reg(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 8))(param_1);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*param_1 + 0xc))(param_1,param_2);
    *param_3 = uVar2;
    return 0;
  }
  return 0xffffe672;
}



undefined4 unw_set_reg(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 8))(param_1);
  if (iVar1 == 0) {
    return 0xffffe672;
  }
  (**(code **)(*param_1 + 0x10))(param_1,param_2,param_3);
  if (param_2 != -1) {
    return 0;
  }
  (**(code **)(*param_1 + 0x34))(param_1,0);
  return 0;
}



undefined4 unw_get_fpreg(int *param_1,undefined4 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,param_2);
    *param_3 = uVar2;
    return 0;
  }
  return 0xffffe672;
}



undefined4 unw_set_fpreg(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x1c))(param_1,param_2,param_3,param_4);
    return 0;
  }
  return 0xffffe672;
}



void unw_step(int *param_1)

{
                    // WARNING: Could not recover jumptable at 0x0001292c. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(*param_1 + 0x20))();
  return;
}



undefined4 unw_get_proc_info(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  (**(code **)(*param_1 + 0x24))(param_1,param_2);
  uVar1 = 0;
  if (*(int *)(param_2 + 4) == 0) {
    uVar1 = 0xffffe66b;
  }
  return uVar1;
}



undefined4 unw_resume(int *param_1)

{
  (**(code **)(*param_1 + 0x28))();
  return 0xffffe674;
}



void unw_save_vfp_as_X(int *param_1)

{
                    // WARNING: Could not recover jumptable at 0x00012964. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(*param_1 + 0x3c))();
  return;
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace, libunwind::Registers_arm>::validReg(int)

bool __thiscall libunwind::UnwindCursor<>::validReg(undefined4 param_1_00,int param_2)

{
  return 0xffffffed < param_2 - 0x10U;
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace, libunwind::Registers_arm>::getReg(int)

undefined4 __thiscall libunwind::UnwindCursor<>::getReg(UnwindCursor<> *this,uint param_1)

{
  switch(param_1) {
  case 0xe:
    return *(undefined4 *)(this + 0x40);
  case 0xfffffffe:
  case 0xd:
    return *(undefined4 *)(this + 0x3c);
  case 0xffffffff:
  case 0xf:
    return *(undefined4 *)(this + 0x44);
  }
  if (param_1 < 0xd) {
    return *(undefined4 *)(this + param_1 * 4 + 8);
  }
  fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","getRegister",
          "external/libunwind_llvm/src/Registers.hpp",0x618,"unsupported arm register");
  fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
  abort();
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace, libunwind::Registers_arm>::setReg(int,
// unsigned int)

void __thiscall
libunwind::UnwindCursor<>::setReg(UnwindCursor<> *this,uint param_1,undefined4 param_2)

{
  switch(param_1) {
  case 0xe:
    *(undefined4 *)(this + 0x40) = param_2;
    return;
  case 0xfffffffe:
  case 0xd:
    *(undefined4 *)(this + 0x3c) = param_2;
    return;
  case 0xffffffff:
  case 0xf:
    *(undefined4 *)(this + 0x44) = param_2;
    return;
  }
  if (param_1 < 0xd) {
    *(undefined4 *)(this + param_1 * 4 + 8) = param_2;
    return;
  }
  fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","setRegister",
          "external/libunwind_llvm/src/Registers.hpp",0x63b,"unsupported arm register");
  fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
  abort();
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace,
// libunwind::Registers_arm>::validFloatReg(int)

bool __thiscall libunwind::UnwindCursor<>::validFloatReg(undefined4 param_1_00,uint param_2)

{
  return (param_2 & 0xffffffe0) == 0x100;
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace, libunwind::Registers_arm>::getFloatReg(int)

undefined8 __thiscall libunwind::UnwindCursor<>::getFloatReg(UnwindCursor<> *this,uint param_1)

{
  int iVar1;
  
  if ((param_1 & 0xfffffff0) == 0x110) {
    if (this[0x4a] == (UnwindCursor<>)0x0) {
      this[0x4a] = (UnwindCursor<>)0x1;
      Registers_arm::saveVFPv3((undefined8 *)(this + 0xd8));
    }
    iVar1 = param_1 * 8 + -0x7a8;
  }
  else {
    if ((param_1 & 0xfffffff0) != 0x100) {
      fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","getFloatRegister",
              "external/libunwind_llvm/src/Registers.hpp",0x70f,"Unknown ARM float register");
      fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
      abort();
    }
    if (this[0x49] == (UnwindCursor<>)0x0) {
      this[0x49] = (UnwindCursor<>)0x1;
      if (this[0x48] == (UnwindCursor<>)0x0) {
        Registers_arm::saveVFPWithFSTMD((undefined8 *)(this + 0x50));
      }
      else {
        Registers_arm::saveVFPWithFSTMX((undefined8 *)(this + 0x50));
      }
    }
    iVar1 = param_1 * 8 + -0x7b0;
  }
  return *(undefined8 *)(this + iVar1);
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// libunwind::UnwindCursor<libunwind::LocalAddressSpace, libunwind::Registers_arm>::setFloatReg(int,
// unsigned long long)

void __cdecl
libunwind::UnwindCursor<>::setFloatReg
          (int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((param_2 & 0xfffffff0) == 0x110) {
    if (*(char *)(param_1 + 0x4a) == '\0') {
      *(undefined1 *)(param_1 + 0x4a) = 1;
      Registers_arm::saveVFPv3((undefined8 *)(param_1 + 0xd8));
    }
    iVar1 = param_1 + param_2 * 8;
    *(undefined4 *)(iVar1 + -0x7a4) = param_4;
    uVar2 = 0xf858;
  }
  else {
    if ((param_2 & 0xfffffff0) != 0x100) {
      fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","setFloatRegister",
              "external/libunwind_llvm/src/Registers.hpp",0x733,"Unknown ARM float register");
      fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
      abort();
    }
    if (*(char *)(param_1 + 0x49) == '\0') {
      *(undefined1 *)(param_1 + 0x49) = 1;
      if (*(char *)(param_1 + 0x48) == '\0') {
        Registers_arm::saveVFPWithFSTMD((undefined8 *)(param_1 + 0x50));
      }
      else {
        Registers_arm::saveVFPWithFSTMX((undefined8 *)(param_1 + 0x50));
      }
    }
    iVar1 = param_1 + param_2 * 8;
    *(undefined4 *)(iVar1 + -0x7ac) = param_4;
    uVar2 = 0xf850;
  }
  *(undefined4 *)(iVar1 + (uVar2 | 0xffff0000)) = param_3;
  return;
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace, libunwind::Registers_arm>::step()

undefined4 __thiscall libunwind::UnwindCursor<>::step(UnwindCursor<> *this)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  uint local_1c;
  uint uStack_18;
  int local_14;
  
  uVar3 = 0;
  local_14 = __stack_chk_guard;
  if (this[0x180] == (UnwindCursor<>)0x0) {
    local_1c = 0;
    uStack_18 = 0;
    puVar1 = decode_eht_entry(*(uint **)(this + 0x178),&local_1c,(int *)&uStack_18);
    iVar2 = _Unwind_VRS_Interpret((int *)this,(int)puVar1,local_1c,uStack_18);
    if (iVar2 == 8) {
      (**(code **)(*(int *)this + 0x34))(this,1);
      if (this[0x180] == (UnwindCursor<>)0x0) {
        if (*(int *)(this + 0x168) != 0) {
          pcVar4 = *(code **)(*(int *)this + 0x10);
          iVar2 = (**(code **)(*(int *)this + 0xc))(this,0xfffffffe);
          (*pcVar4)(this,0xfffffffe,*(int *)(this + 0x168) + iVar2);
        }
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
  }
  if (__stack_chk_guard == local_14) {
    return uVar3;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace,
// libunwind::Registers_arm>::getInfo(unw_proc_info_t*)

void __thiscall libunwind::UnwindCursor<>::getInfo(UnwindCursor<> *this,undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar4 = *(undefined8 *)(this + 0x178);
  uVar3 = *(undefined8 *)(this + 0x160);
  uVar1 = *(undefined8 *)(this + 0x168);
  uVar2 = *(undefined8 *)(this + 0x170);
  *param_1 = *(undefined8 *)(this + 0x158);
  param_1[1] = uVar3;
  param_1[2] = uVar1;
  param_1[3] = uVar2;
  param_1[4] = uVar4;
  return;
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace, libunwind::Registers_arm>::jumpto()

undefined8 __thiscall libunwind::UnwindCursor<>::jumpto(UnwindCursor<> *this)

{
  if (this[0x49] != (UnwindCursor<>)0x0) {
    if (this[0x48] == (UnwindCursor<>)0x0) {
      Registers_arm::restoreVFPWithFLDMD((undefined8 *)(this + 0x50));
    }
    else {
      Registers_arm::restoreVFPWithFLDMX((undefined8 *)(this + 0x50));
    }
  }
  if (this[0x4a] != (UnwindCursor<>)0x0) {
    Registers_arm::restoreVFPv3();
  }
  return *(undefined8 *)(this + 8);
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace, libunwind::Registers_arm>::isSignalFrame()

UnwindCursor<> __thiscall libunwind::UnwindCursor<>::isSignalFrame(UnwindCursor<> *this)

{
  return this[0x181];
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace,
// libunwind::Registers_arm>::getFunctionName(char*, unsigned int, unsigned int*)

void __thiscall
libunwind::UnwindCursor<>::getFunctionName
          (UnwindCursor<> *this,undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_2c [8];
  int local_24;
  int local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = (**(code **)(*(int *)this + 0xc))(this,0xffffffff);
  iVar2 = dladdr(iVar1,auStack_2c);
  if ((iVar2 == 0) || (local_24 == 0)) {
    uVar3 = 0;
  }
  else {
    snprintf(param_1,0xffffffff,param_2);
    *param_3 = iVar1 - local_20;
    uVar3 = 1;
  }
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar3);
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace,
// libunwind::Registers_arm>::setInfoBasedOnIPRegister(bool)

void __thiscall
libunwind::UnwindCursor<>::setInfoBasedOnIPRegister(UnwindCursor<> *this,int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_28 [2];
  undefined4 local_20;
  undefined1 *local_1c;
  uint local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  uVar1 = (**(code **)(*(int *)this + 0xc))(this,0xffffffff);
  local_20 = *(undefined4 *)(this + 4);
  uVar1 = (uVar1 & 0xfffffffe) - param_1;
  local_1c = (undefined1 *)local_28;
  local_18 = uVar1;
  iVar2 = dl_iterate_phdr(0x12ffd,&local_20);
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = local_28[0];
  }
  if ((iVar2 == 0 || iVar3 == 0) ||
     (iVar3 = getInfoFromEHABISection(this,uVar1,local_28), iVar3 == 0)) {
    this[0x180] = (UnwindCursor<>)0x1;
  }
  if (__stack_chk_guard == local_14) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace,
// libunwind::Registers_arm>::getRegisterName(int)

void __thiscall libunwind::UnwindCursor<>::getRegisterName(UnwindCursor<> *this,undefined4 param_1)

{
  Registers_arm::getRegisterName(this + 8,param_1);
  return;
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace, libunwind::Registers_arm>::saveVFPAsX()

void __thiscall libunwind::UnwindCursor<>::saveVFPAsX(UnwindCursor<> *this)

{
  this[0x48] = (UnwindCursor<>)0x1;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// snprintf(char*, unsigned int pass_object_size1, char const*, ...)

void __cdecl snprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,...)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  __vsnprintf_chk(param_1,param_3,0,param_2,&DAT_00014ec2,&stack0x00000000,&stack0x00000000);
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// libunwind::UnwindCursor<libunwind::LocalAddressSpace,
// libunwind::Registers_arm>::getInfoFromEHABISection(unsigned int, libunwind::UnwindInfoSections
// const&)

undefined4 __thiscall
libunwind::UnwindCursor<>::getInfoFromEHABISection(UnwindCursor<> *this,uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  bool bVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  int iVar13;
  code *pcVar14;
  char *pcVar15;
  
  if ((uint)param_2[1] >> 3 == 0) {
    return 0;
  }
  iVar13 = *param_2;
  uVar12 = (uint)param_2[1] >> 3;
  uVar10 = 0;
  uVar3 = uVar12;
  do {
    iVar5 = uVar10 + (uVar3 >> 1);
    uVar8 = *(uint *)(iVar13 + iVar5 * 8);
    uVar1 = (uVar3 - 1) - (uVar3 >> 1);
    uVar2 = iVar5 + 1;
    if (param_1 < (uVar8 | (uVar8 & 0x40000000) << 1) + iVar13 + iVar5 * 8) {
      uVar1 = uVar3 >> 1;
      uVar2 = uVar10;
    }
    uVar10 = uVar2;
    uVar3 = uVar1;
  } while (uVar3 != 0);
  if (uVar10 == 0) {
    return 0;
  }
  uVar3 = *(uint *)(iVar13 + (uVar10 - 1) * 8);
  iVar5 = iVar13 + (uVar10 - 1) * 8;
  if (uVar10 == uVar12) {
    iVar13 = -1;
  }
  else {
    uVar12 = *(uint *)(iVar13 + uVar10 * 8);
    iVar13 = (uVar12 | (uVar12 & 0x40000000) << 1) + iVar13 + uVar10 * 8;
  }
  if (iVar5 == -4) {
    return 0;
  }
  puVar6 = (uint *)(iVar5 + 4);
  uVar10 = *puVar6;
  if (uVar10 == 1) {
    return 0;
  }
  if ((int)uVar10 < 0) {
    bVar11 = true;
LAB_00012ef6:
    uVar12 = (uVar10 << 4) >> 0x1c;
    if (uVar12 == 2) {
      pcVar14 = (code *)0x12455;
      bVar7 = true;
    }
    else {
      if (uVar12 != 1) {
        if (uVar12 != 0) {
          uVar9 = 0x35a;
          pcVar15 = "unknown personality routine";
          goto LAB_00012fb0;
        }
        puVar4 = puVar6 + 1;
        if (bVar11) {
          puVar4 = (uint *)0x0;
        }
        pcVar14 = (code *)0x123ad;
        goto LAB_00012f16;
      }
      pcVar14 = (code *)0x12401;
      bVar7 = false;
    }
    uVar10 = (uVar10 << 8) >> 0x18;
    if ((bool)(uVar10 != 0 & bVar11)) {
      uVar9 = 0x361;
      pcVar15 = "index inlined table detected but pr function requires extra words";
LAB_00012fb0:
      fprintf((FILE *)0x1a21c,"libunwind: %s %s:%d - %s\n","getInfoFromEHABISection",
              "external/libunwind_llvm/src/UnwindCursor.hpp",uVar9,pcVar15);
      fflush((FILE *)0x1a21c);
                    // WARNING: Subroutine does not return
      abort();
    }
    puVar4 = puVar6 + uVar10 + 1;
  }
  else {
    uVar10 = uVar10 | (uVar10 & 0x40000000) << 1;
    puVar4 = (uint *)(uVar10 + (int)puVar6);
    uVar10 = *(uint *)(uVar10 + (int)puVar6);
    puVar6 = puVar4;
    if ((int)uVar10 < 0) {
      bVar11 = false;
      goto LAB_00012ef6;
    }
    bVar11 = false;
    pcVar14 = (code *)((uVar10 | (uVar10 & 0x40000000) << 1) + (int)puVar4);
    puVar4 = puVar4 + 1 + (puVar4[1] >> 0x18) + 1;
LAB_00012f16:
    bVar7 = false;
  }
  *(uint **)(this + 0x178) = puVar6;
  *(uint *)(this + 0x158) = (uVar3 | (uVar3 & 0x40000000) << 1) + iVar5;
  *(int *)(this + 0x15c) = iVar13;
  *(uint **)(this + 0x160) = puVar4;
  *(code **)(this + 0x164) = pcVar14;
  uVar9 = 0;
  if (bVar7) {
    uVar9 = 2;
  }
  if (bVar11) {
    uVar9 = 1;
  }
  *(undefined4 *)(this + 0x16c) = uVar9;
  return 1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// __invoke(dl_phdr_info*, unsigned int, void*)

uint __cdecl
libunwind::LocalAddressSpace::findUnwindSections(unsigned_int,libunwind::UnwindInfoSections&)::
{lambda(dl_phdr_info*,unsigned_int,void*)#1}::__invoke(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (*param_1 <= *(uint *)(param_3 + 8)) {
    uVar2 = (uint)(ushort)param_1[3];
    if (uVar2 == 0) {
      uVar6 = 0;
      uVar7 = 0;
    }
    else {
      iVar1 = 0;
      uVar7 = 0;
      uVar6 = 0;
      uVar3 = 0;
      do {
        uVar5 = param_1[2];
        if (*(int *)(uVar5 + iVar1) == 0x70000001) {
          uVar6 = 1;
          **(int **)(param_3 + 4) = *(int *)(uVar5 + iVar1 + 8) + *param_1;
          *(undefined4 *)(*(int *)(param_3 + 4) + 4) = *(undefined4 *)(uVar5 + iVar1 + 0x14);
          uVar2 = (uint)(ushort)param_1[3];
        }
        else if (*(int *)(uVar5 + iVar1) == 1) {
          uVar4 = *(int *)(uVar5 + iVar1 + 8) + *param_1;
          if ((uVar4 <= *(uint *)(param_3 + 8)) &&
             (*(uint *)(param_3 + 8) < uVar4 + *(int *)(uVar5 + iVar1 + 0x14))) {
            uVar7 = 1;
          }
        }
        iVar1 = iVar1 + 0x20;
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
    return uVar6 & uVar7;
  }
  return 0;
}



// libunwind::Registers_arm::getRegisterName(int)

char * __thiscall
libunwind::Registers_arm::getRegisterName(undefined4 param_1_00,undefined4 param_2)

{
  char *pcVar1;
  
  pcVar1 = "pc";
  switch(param_2) {
  case 0:
    return "r0";
  case 1:
    return "r1";
  case 2:
    return "r2";
  case 3:
    return "r3";
  case 4:
    return "r4";
  case 5:
    return "r5";
  case 6:
    return "r6";
  case 7:
    return "r7";
  case 8:
    return "r8";
  case 9:
    return "r9";
  case 10:
    return "r10";
  case 0xb:
    return "r11";
  case 0xc:
    return "r12";
  case 0xe:
    return "lr";
  default:
    pcVar1 = "unknown register";
switchD_00013094_caseD_ffffffff:
    return pcVar1;
  case 0x40:
    return "s0";
  case 0x41:
    return "s1";
  case 0x42:
    return "s2";
  case 0x43:
    return "s3";
  case 0x44:
    return "s4";
  case 0x45:
    return "s5";
  case 0x46:
    return "s6";
  case 0x47:
    return "s7";
  case 0x48:
    return "s8";
  case 0x49:
    return "s9";
  case 0x4a:
    return "s10";
  case 0x4b:
    return "s11";
  case 0x4c:
    return "s12";
  case 0x4d:
    return "s13";
  case 0x4e:
    return "s14";
  case 0x4f:
    return "s15";
  case 0x50:
    return "s16";
  case 0x51:
    return "s17";
  case 0x52:
    return "s18";
  case 0x53:
    return "s19";
  case 0x54:
    return "s20";
  case 0x55:
    return "s21";
  case 0x56:
    return "s22";
  case 0x57:
    return "s23";
  case 0x58:
    return "s24";
  case 0x59:
    return "s25";
  case 0x5a:
    return "s26";
  case 0x5b:
    return "s27";
  case 0x5c:
    return "s28";
  case 0x5d:
    return "s29";
  case 0x5e:
    return "s30";
  case 0x5f:
    return "s31";
  case 0x100:
    return "d0";
  case 0x101:
    return "d1";
  case 0x102:
    return "d2";
  case 0x103:
    return "d3";
  case 0x104:
    return "d4";
  case 0x105:
    return "d5";
  case 0x106:
    return "d6";
  case 0x107:
    return "d7";
  case 0x108:
    return "d8";
  case 0x109:
    return "d9";
  case 0x10a:
    return "d10";
  case 0x10b:
    return "d11";
  case 0x10c:
    return "d12";
  case 0x10d:
    return "d13";
  case 0x10e:
    return "d14";
  case 0x10f:
    return "d15";
  case 0x110:
    return "d16";
  case 0x111:
    return "d17";
  case 0x112:
    return "d18";
  case 0x113:
    return "d19";
  case 0x114:
    return "d20";
  case 0x115:
    return "d21";
  case 0x116:
    return "d22";
  case 0x117:
    return "d23";
  case 0x118:
    return "d24";
  case 0x119:
    return "d25";
  case 0x11a:
    return "d26";
  case 0x11b:
    return "d27";
  case 0x11c:
    return "d28";
  case 0x11d:
    return "d29";
  case 0x11e:
    return "d30";
  case 0x11f:
    return "d31";
  case 0xfffffffe:
  case 0xd:
    return "sp";
  case 0xffffffff:
  case 0xf:
    goto switchD_00013094_caseD_ffffffff;
  }
}



// libunwind::Registers_arm::restoreCoreAndJumpTo()

undefined8 __thiscall libunwind::Registers_arm::restoreCoreAndJumpTo(Registers_arm *this)

{
  return *(undefined8 *)this;
}



// WARNING: Unknown calling convention: __cdecl
// libunwind::Registers_arm::restoreVFPWithFLDMD(unsigned long long*)

undefined4 __cdecl libunwind::Registers_arm::restoreVFPWithFLDMD(undefined8 *param_1)

{
  return (int)*param_1;
}



// WARNING: Unknown calling convention: __cdecl
// libunwind::Registers_arm::restoreVFPWithFLDMX(unsigned long long*)

undefined4 __cdecl libunwind::Registers_arm::restoreVFPWithFLDMX(undefined8 *param_1)

{
  return (int)*param_1;
}



// libunwind::Registers_arm::restoreVFPv3(unsigned long long*)

void libunwind::Registers_arm::restoreVFPv3(void)

{
  return;
}



void __cxa_atexit(void)

{
  __cxa_atexit();
  return;
}



void __cxa_atexit(void)

{
  __cxa_atexit();
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::incStrong(void *param_1)

{
  incStrong(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::incStrong(void *param_1)

{
  incStrong(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::decStrong(void *param_1)

{
  decStrong(param_1);
  return;
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

void android::sp_report_race(void)

{
  sp_report_race();
  return;
}



void __thiscall android::RefBase::RefBase(RefBase *this)

{
  RefBase(this);
  return;
}



void __thiscall android::RefBase::RefBase(RefBase *this)

{
  RefBase(this);
  return;
}



void __thiscall android::IInterface::IInterface(IInterface *this)

{
  IInterface(this);
  return;
}



void __thiscall android::IInterface::IInterface(IInterface *this)

{
  IInterface(this);
  return;
}



void __thiscall android::BpRefBase::BpRefBase(BpRefBase *this,sp *param_1)

{
  BpRefBase(this,param_1);
  return;
}



void __thiscall android::BpRefBase::BpRefBase(BpRefBase *this,sp *param_1)

{
  BpRefBase(this,param_1);
  return;
}



void __thiscall android::IInterface::~IInterface(IInterface *this)

{
  ~IInterface(this);
  return;
}



void __thiscall android::IInterface::~IInterface(IInterface *this)

{
  ~IInterface(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::checkInterface(IBinder *param_1)

{
  checkInterface(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::checkInterface(IBinder *param_1)

{
  checkInterface(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readStrongBinder(void)

{
  readStrongBinder();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readStrongBinder(void)

{
  readStrongBinder();
  return;
}



void __thiscall android::ICacaoClient::asInterface(ICacaoClient *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



void __thiscall android::ICacaoClient::asInterface(ICacaoClient *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IInterface::asBinder(sp *param_1)

{
  asBinder(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IInterface::asBinder(sp *param_1)

{
  asBinder(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeStrongBinder(sp *param_1)

{
  writeStrongBinder(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeStrongBinder(sp *param_1)

{
  writeStrongBinder(param_1);
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readInt32(void)

{
  readInt32();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readInt32(void)

{
  readInt32();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IMemory::asInterface(sp *param_1)

{
  asInterface(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IMemory::asInterface(sp *param_1)

{
  asInterface(param_1);
  return;
}



void __aeabi_memclr4(void)

{
  __aeabi_memclr4();
  return;
}



void __aeabi_memclr4(void)

{
  __aeabi_memclr4();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readFileDescriptor(void)

{
  readFileDescriptor();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readFileDescriptor(void)

{
  readFileDescriptor();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IMemory::size(void)

{
  size();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IMemory::size(void)

{
  size();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IMemory::pointer(void)

{
  pointer();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IMemory::pointer(void)

{
  pointer();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeInt32(int param_1)

{
  writeInt32(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeInt32(int param_1)

{
  writeInt32(param_1);
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::String16::size(void)

{
  size();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::String16::size(void)

{
  size();
  return;
}



void strzcmp16(void)

{
  strzcmp16();
  return;
}



void strzcmp16(void)

{
  strzcmp16();
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __thiscall android::BpRefBase::~BpRefBase(BpRefBase *this)

{
  ~BpRefBase(this);
  return;
}



void __thiscall android::BpRefBase::~BpRefBase(BpRefBase *this)

{
  ~BpRefBase(this);
  return;
}



void __thiscall android::RefBase::~RefBase(RefBase *this)

{
  ~RefBase(this);
  return;
}



void __thiscall android::RefBase::~RefBase(RefBase *this)

{
  ~RefBase(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void operator_delete(void *param_1)

{
  operator_delete(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void operator_delete(void *param_1)

{
  operator_delete(param_1);
  return;
}



void __thiscall android::Parcel::Parcel(Parcel *this)

{
  Parcel(this);
  return;
}



void __thiscall android::Parcel::Parcel(Parcel *this)

{
  Parcel(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeInterfaceToken(String16 *param_1)

{
  writeInterfaceToken(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeInterfaceToken(String16 *param_1)

{
  writeInterfaceToken(param_1);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __thiscall android::ICacao::asInterface(ICacao *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



void __thiscall android::ICacao::asInterface(ICacao *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



void __thiscall android::Parcel::~Parcel(Parcel *this)

{
  ~Parcel(this);
  return;
}



void __thiscall android::Parcel::~Parcel(Parcel *this)

{
  ~Parcel(this);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeFileDescriptor(int param_1,bool param_2)

{
  writeFileDescriptor(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeFileDescriptor(int param_1,bool param_2)

{
  writeFileDescriptor(param_1,param_2);
  return;
}



void __thiscall android::String16::String16(String16 *this,char *param_1)

{
  String16(this,param_1);
  return;
}



void __thiscall android::String16::String16(String16 *this,char *param_1)

{
  String16(this,param_1);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void native_handle_close(void)

{
  native_handle_close();
  return;
}



void native_handle_close(void)

{
  native_handle_close();
  return;
}



void native_handle_delete(void)

{
  native_handle_delete();
  return;
}



void native_handle_delete(void)

{
  native_handle_delete();
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __thiscall android::VectorImpl::VectorImpl(VectorImpl *this,uint param_1,uint param_2)

{
  VectorImpl(this,param_1,param_2);
  return;
}



void __thiscall android::VectorImpl::VectorImpl(VectorImpl *this,uint param_1,uint param_2)

{
  VectorImpl(this,param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readUint32(void)

{
  readUint32();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readUint32(void)

{
  readUint32();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readNativeHandle(void)

{
  readNativeHandle();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readNativeHandle(void)

{
  readNativeHandle();
  return;
}



void * __thiscall cacao::ObjectBase::operator_new(ObjectBase *this)

{
  void *pvVar1;
  
  pvVar1 = operator_new(this);
  return pvVar1;
}



void * __thiscall cacao::ObjectBase::operator_new(ObjectBase *this)

{
  void *pvVar1;
  
  pvVar1 = operator_new(this);
  return pvVar1;
}



ImageBuf * __thiscall
cacao::ImageBuf::ImageBuf
          (ImageBuf *this,undefined4 param_1,int param_2,uint param_3,undefined4 param_4,int param_5
          )

{
  ImageBuf *pIVar1;
  
  pIVar1 = ImageBuf(this,param_1,param_2,param_3,param_4,param_5);
  return pIVar1;
}



ImageBuf * __thiscall
cacao::ImageBuf::ImageBuf
          (ImageBuf *this,undefined4 param_1,int param_2,uint param_3,undefined4 param_4,int param_5
          )

{
  ImageBuf *pIVar1;
  
  pIVar1 = ImageBuf(this,param_1,param_2,param_3,param_4,param_5);
  return pIVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::insertAt(void *param_1,uint param_2,uint param_3)

{
  insertAt(param_1,param_2,param_3);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::insertAt(void *param_1,uint param_2,uint param_3)

{
  insertAt(param_1,param_2,param_3);
  return;
}



void __thiscall
android::ICacaoProcessCallback::asInterface(ICacaoProcessCallback *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



void __thiscall
android::ICacaoProcessCallback::asInterface(ICacaoProcessCallback *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



void __thiscall android::VectorImpl::VectorImpl(VectorImpl *this,VectorImpl *param_1)

{
  VectorImpl(this,param_1);
  return;
}



void __thiscall android::VectorImpl::VectorImpl(VectorImpl *this,VectorImpl *param_1)

{
  VectorImpl(this,param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::finish_vector(void)

{
  finish_vector();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::finish_vector(void)

{
  finish_vector();
  return;
}



void __thiscall android::VectorImpl::~VectorImpl(VectorImpl *this)

{
  ~VectorImpl(this);
  return;
}



void __thiscall android::VectorImpl::~VectorImpl(VectorImpl *this)

{
  ~VectorImpl(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::write(void *param_1,uint param_2)

{
  write(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::write(void *param_1,uint param_2)

{
  write(param_1,param_2);
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readIntPtr(void)

{
  readIntPtr();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::readIntPtr(void)

{
  readIntPtr();
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeUint32(uint param_1)

{
  writeUint32(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeUint32(uint param_1)

{
  writeUint32(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeNativeHandle(native_handle *param_1)

{
  writeNativeHandle(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::Parcel::writeNativeHandle(native_handle *param_1)

{
  writeNativeHandle(param_1);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __aeabi_memcpy(void)

{
  __aeabi_memcpy();
  return;
}



void __aeabi_memcpy(void)

{
  __aeabi_memcpy();
  return;
}



void __aeabi_memmove(void)

{
  __aeabi_memmove();
  return;
}



void __aeabi_memmove(void)

{
  __aeabi_memmove();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_destroy(__mutex);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_destroy(__mutex);
  return iVar1;
}



void __thiscall android::ICacaoClient::ICacaoClient(ICacaoClient *this,int *param_1)

{
  ICacaoClient(this,param_1);
  return;
}



void __thiscall android::ICacaoClient::ICacaoClient(ICacaoClient *this,int *param_1)

{
  ICacaoClient(this,param_1);
  return;
}



void __thiscall android::BBinder::BBinder(BBinder *this)

{
  BBinder(this);
  return;
}



void __thiscall android::BBinder::BBinder(BBinder *this)

{
  BBinder(this);
  return;
}



void __thiscall android::BBinder::~BBinder(BBinder *this)

{
  ~BBinder(this);
  return;
}



void __thiscall android::BBinder::~BBinder(BBinder *this)

{
  ~BBinder(this);
  return;
}



void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this,int *param_1)

{
  ~CacaoProcessCallback(this,param_1);
  return;
}



void __thiscall
android::Cacao::CacaoProcessCallback::~CacaoProcessCallback(CacaoProcessCallback *this,int *param_1)

{
  ~CacaoProcessCallback(this,param_1);
  return;
}



void __thiscall android::ICacaoClient::ICacaoClient(ICacaoClient *this,int *param_1)

{
  ICacaoClient(this,param_1);
  return;
}



void __thiscall android::ICacaoClient::ICacaoClient(ICacaoClient *this,int *param_1)

{
  ICacaoClient(this,param_1);
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

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
  int iVar1;
  
  iVar1 = pthread_mutex_init(__mutex,__mutexattr);
  return iVar1;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this,int *param_1)

{
  ~CacaoClient(this,param_1);
  return;
}



void __thiscall android::Cacao::CacaoClient::~CacaoClient(CacaoClient *this,int *param_1)

{
  ~CacaoClient(this,param_1);
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

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock(__mutex);
  return iVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_unlock(__mutex);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_unlock(__mutex);
  return iVar1;
}



wp<> * __thiscall android::wp<>::wp<>(wp<> *this,int *param_1)

{
  wp<> *pwVar1;
  
  pwVar1 = wp<>(this,param_1);
  return pwVar1;
}



wp<> * __thiscall android::wp<>::wp<>(wp<> *this,int *param_1)

{
  wp<> *pwVar1;
  
  pwVar1 = wp<>(this,param_1);
  return pwVar1;
}



wp<> * __thiscall android::wp<>::~wp(wp<> *this)

{
  wp<> *pwVar1;
  
  pwVar1 = ~wp(this);
  return pwVar1;
}



wp<> * __thiscall android::wp<>::~wp(wp<> *this)

{
  wp<> *pwVar1;
  
  pwVar1 = ~wp(this);
  return pwVar1;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::createWeak(void *param_1)

{
  createWeak(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::createWeak(void *param_1)

{
  createWeak(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::weakref_type::decWeak(void *param_1)

{
  decWeak(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::weakref_type::decWeak(void *param_1)

{
  decWeak(param_1);
  return;
}



undefined4 cacao::ProcessFactory::createEvent(void)

{
  undefined4 uVar1;
  
  uVar1 = createEvent();
  return uVar1;
}



undefined4 cacao::ProcessFactory::createEvent(void)

{
  undefined4 uVar1;
  
  uVar1 = createEvent();
  return uVar1;
}



void __android_log_print(void)

{
  __android_log_print();
  return;
}



void __android_log_print(void)

{
  __android_log_print();
  return;
}



void __aeabi_memclr8(void)

{
  __aeabi_memclr8();
  return;
}



void __aeabi_memclr8(void)

{
  __aeabi_memclr8();
  return;
}



void __thiscall android::Cacao::CacaoClient::allocMemory(CacaoClient *this,uint param_1)

{
  allocMemory(this,param_1);
  return;
}



void __thiscall android::Cacao::CacaoClient::allocMemory(CacaoClient *this,uint param_1)

{
  allocMemory(this,param_1);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::CacaoClient::makeSerializedData(int *param_1,int param_2)

{
  makeSerializedData(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::Cacao::CacaoClient::makeSerializedData(int *param_1,int param_2)

{
  makeSerializedData(param_1,param_2);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void __thiscall
android::MemoryHeapBase::MemoryHeapBase
          (MemoryHeapBase *this,uint param_1,uint param_2,char *param_3)

{
  MemoryHeapBase(this,param_1,param_2,param_3);
  return;
}



void __thiscall
android::MemoryHeapBase::MemoryHeapBase
          (MemoryHeapBase *this,uint param_1,uint param_2,char *param_3)

{
  MemoryHeapBase(this,param_1,param_2,param_3);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __thiscall
android::MemoryBase::MemoryBase(MemoryBase *this,sp *param_1,int param_2,uint param_3)

{
  MemoryBase(this,param_1,param_2,param_3);
  return;
}



void __thiscall
android::MemoryBase::MemoryBase(MemoryBase *this,sp *param_1,int param_2,uint param_3)

{
  MemoryBase(this,param_1,param_2,param_3);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



CacaoProcessCallback * __thiscall
android::Cacao::CacaoProcessCallback::CacaoProcessCallback
          (CacaoProcessCallback *this,undefined4 param_1,undefined4 param_2)

{
  CacaoProcessCallback *pCVar1;
  
  pCVar1 = CacaoProcessCallback(this,param_1,param_2);
  return pCVar1;
}



CacaoProcessCallback * __thiscall
android::Cacao::CacaoProcessCallback::CacaoProcessCallback
          (CacaoProcessCallback *this,undefined4 param_1,undefined4 param_2)

{
  CacaoProcessCallback *pCVar1;
  
  pCVar1 = CacaoProcessCallback(this,param_1,param_2);
  return pCVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __aeabi_memcpy8(void)

{
  __aeabi_memcpy8();
  return;
}



void __aeabi_memcpy8(void)

{
  __aeabi_memcpy8();
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



wp<> * __thiscall android::wp<>::wp<>(wp<> *this,int *param_1)

{
  wp<> *pwVar1;
  
  pwVar1 = wp<>(this,param_1);
  return pwVar1;
}



wp<> * __thiscall android::wp<>::wp<>(wp<> *this,int *param_1)

{
  wp<> *pwVar1;
  
  pwVar1 = wp<>(this,param_1);
  return pwVar1;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void android::Cacao::getService(void)

{
  getService();
  return;
}



void android::Cacao::getService(void)

{
  getService();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ProcessState::self(void)

{
  self();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ProcessState::self(void)

{
  self();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ProcessState::startThreadPool(void)

{
  startThreadPool();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ProcessState::startThreadPool(void)

{
  startThreadPool();
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = getpid();
  return _Var1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = getpid();
  return _Var1;
}



uint __thiscall android::Cacao::connect(Cacao *this)

{
  uint uVar1;
  
  uVar1 = connect(this);
  return uVar1;
}



uint __thiscall android::Cacao::connect(Cacao *this)

{
  uint uVar1;
  
  uVar1 = connect(this);
  return uVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::defaultServiceManager(void)

{
  defaultServiceManager();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::defaultServiceManager(void)

{
  defaultServiceManager();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int usleep(__useconds_t __useconds)

{
  int iVar1;
  
  iVar1 = usleep(__useconds);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int usleep(__useconds_t __useconds)

{
  int iVar1;
  
  iVar1 = usleep(__useconds);
  return iVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __thiscall android::String16::~String16(String16 *this)

{
  ~String16(this);
  return;
}



void __thiscall android::String16::~String16(String16 *this)

{
  ~String16(this);
  return;
}



void __thiscall android::ICacaoService::asInterface(ICacaoService *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



void __thiscall android::ICacaoService::asInterface(ICacaoService *this,undefined4 *param_1)

{
  asInterface(this,param_1);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



CacaoClient * __thiscall android::Cacao::CacaoClient::CacaoClient(CacaoClient *this)

{
  CacaoClient *pCVar1;
  
  pCVar1 = CacaoClient(this);
  return pCVar1;
}



CacaoClient * __thiscall android::Cacao::CacaoClient::CacaoClient(CacaoClient *this)

{
  CacaoClient *pCVar1;
  
  pCVar1 = CacaoClient(this);
  return pCVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



undefined4 __thiscall android::Cacao::CacaoClient::connect(CacaoClient *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = connect(this,param_1);
  return uVar1;
}



undefined4 __thiscall android::Cacao::CacaoClient::connect(CacaoClient *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = connect(this,param_1);
  return uVar1;
}



void __thiscall android::Cacao::disconnect(Cacao *this)

{
  disconnect(this);
  return;
}



void __thiscall android::Cacao::disconnect(Cacao *this)

{
  disconnect(this);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



void __thiscall android::Cacao::CacaoClient::disconnect(CacaoClient *this)

{
  disconnect(this);
  return;
}



void __thiscall android::Cacao::CacaoClient::disconnect(CacaoClient *this)

{
  disconnect(this);
  return;
}



void PAL_MemAllocEx(void)

{
  PAL_MemAllocEx();
  return;
}



void PAL_MemAllocEx(void)

{
  PAL_MemAllocEx();
  return;
}



void __thiscall cacao::SharedBuffer::incRefCnt(SharedBuffer *this)

{
  incRefCnt(this);
  return;
}



void __thiscall cacao::SharedBuffer::incRefCnt(SharedBuffer *this)

{
  incRefCnt(this);
  return;
}



int __thiscall cacao::SharedBuffer::decRefCnt(SharedBuffer *this)

{
  int iVar1;
  
  iVar1 = decRefCnt(this);
  return iVar1;
}



int __thiscall cacao::SharedBuffer::decRefCnt(SharedBuffer *this)

{
  int iVar1;
  
  iVar1 = decRefCnt(this);
  return iVar1;
}



void __thiscall cacao::ObjectBase::ObjectBase(ObjectBase *this)

{
  ObjectBase(this);
  return;
}



void __thiscall cacao::ObjectBase::ObjectBase(ObjectBase *this)

{
  ObjectBase(this);
  return;
}



SharedBuffer * cacao::SharedBuffer::create(void)

{
  SharedBuffer *pSVar1;
  
  pSVar1 = create();
  return pSVar1;
}



SharedBuffer * cacao::SharedBuffer::create(void)

{
  SharedBuffer *pSVar1;
  
  pSVar1 = create();
  return pSVar1;
}



undefined4 cacao::ImageBuf::getMapper(void)

{
  undefined4 uVar1;
  
  uVar1 = getMapper();
  return uVar1;
}



undefined4 cacao::ImageBuf::getMapper(void)

{
  undefined4 uVar1;
  
  uVar1 = getMapper();
  return uVar1;
}



undefined4 cacao::ImageBuf::getAllocator(void)

{
  undefined4 uVar1;
  
  uVar1 = getAllocator();
  return uVar1;
}



undefined4 cacao::ImageBuf::getAllocator(void)

{
  undefined4 uVar1;
  
  uVar1 = getAllocator();
  return uVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::graphics::mapper::V2_0::IMapper::getService(string *param_1,bool param_2)

{
  getService(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::graphics::mapper::V2_0::IMapper::getService(string *param_1,bool param_2)

{
  getService(param_1,param_2);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::graphics::allocator::V2_0::IAllocator::getService
               (string *param_1,bool param_2)

{
  getService(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::graphics::allocator::V2_0::IAllocator::getService
               (string *param_1,bool param_2)

{
  getService(param_1,param_2);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



void __thiscall android::hardware::details::return_status::~return_status(return_status *this)

{
  ~return_status(this);
  return;
}



void __thiscall android::hardware::details::return_status::~return_status(return_status *this)

{
  ~return_status(this);
  return;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void operator_delete__(void *param_1)

{
  operator_delete__(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void operator_delete__(void *param_1)

{
  operator_delete__(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

undefined4 __cdecl cacao::SharedBuffer::release(SharedBuffer *param_1)

{
  undefined4 uVar1;
  
  uVar1 = release(param_1);
  return uVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

undefined4 __cdecl cacao::SharedBuffer::release(SharedBuffer *param_1)

{
  undefined4 uVar1;
  
  uVar1 = release(param_1);
  return uVar1;
}



void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  ~AbstractUnwindCursor();
  return;
}



void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  ~AbstractUnwindCursor();
  return;
}



ImageBuf * __thiscall cacao::ImageBuf::~ImageBuf(ImageBuf *this)

{
  ImageBuf *pIVar1;
  
  pIVar1 = ~ImageBuf(this);
  return pIVar1;
}



ImageBuf * __thiscall cacao::ImageBuf::~ImageBuf(ImageBuf *this)

{
  ImageBuf *pIVar1;
  
  pIVar1 = ~ImageBuf(this);
  return pIVar1;
}



undefined4 __thiscall cacao::ImageBuf::isValid(ImageBuf *this)

{
  undefined4 uVar1;
  
  uVar1 = isValid(this);
  return uVar1;
}



undefined4 __thiscall cacao::ImageBuf::isValid(ImageBuf *this)

{
  undefined4 uVar1;
  
  uVar1 = isValid(this);
  return uVar1;
}



void __thiscall android::hardware::hidl_handle::hidl_handle(hidl_handle *this)

{
  hidl_handle(this);
  return;
}



void __thiscall android::hardware::hidl_handle::hidl_handle(hidl_handle *this)

{
  hidl_handle(this);
  return;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



void __thiscall android::hardware::hidl_handle::~hidl_handle(hidl_handle *this)

{
  ~hidl_handle(this);
  return;
}



void __thiscall android::hardware::hidl_handle::~hidl_handle(hidl_handle *this)

{
  ~hidl_handle(this);
  return;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * operator_new__(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new__(param_1);
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * operator_new__(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new__(param_1);
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::hidl_handle::getNativeHandle(void)

{
  getNativeHandle();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::hidl_handle::getNativeHandle(void)

{
  getNativeHandle();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int dup(int __fd)

{
  int iVar1;
  
  iVar1 = dup(__fd);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int dup(int __fd)

{
  int iVar1;
  
  iVar1 = dup(__fd);
  return iVar1;
}



Cacao * android::Cacao::create(void)

{
  Cacao *pCVar1;
  
  pCVar1 = create();
  return pCVar1;
}



Cacao * android::Cacao::create(void)

{
  Cacao *pCVar1;
  
  pCVar1 = create();
  return pCVar1;
}



undefined4 __thiscall android::Cacao::getJpegBufferSize(Cacao *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = getJpegBufferSize(this,param_1);
  return uVar1;
}



undefined4 __thiscall android::Cacao::getJpegBufferSize(Cacao *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = getJpegBufferSize(this,param_1);
  return uVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

int __cdecl android::Cacao::getCaps(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = getCaps(param_1,param_2);
  return iVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

int __cdecl android::Cacao::getCaps(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = getCaps(param_1,param_2);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = fprintf(__stream,__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = fprintf(__stream,__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fflush(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fflush(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void abort(void)

{
                    // WARNING: Subroutine does not return
  abort();
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void abort(void)

{
                    // WARNING: Subroutine does not return
  abort();
}



undefined4 unw_getcontext(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 unaff_lr;
  
  *(int *)param_1 = param_1;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x10) = unaff_r4;
  *(undefined4 *)(param_1 + 0x14) = unaff_r5;
  *(undefined4 *)(param_1 + 0x18) = unaff_r6;
  *(undefined4 *)(param_1 + 0x1c) = unaff_r7;
  *(undefined4 *)(param_1 + 0x20) = unaff_r8;
  *(undefined4 *)(param_1 + 0x24) = unaff_r9;
  *(undefined4 *)(param_1 + 0x28) = unaff_r10;
  *(undefined4 *)(param_1 + 0x2c) = unaff_r11;
  *(undefined4 *)(param_1 + 0x30) = 0xffffe510;
  *(BADSPACEBASE **)(param_1 + 0x34) = register0x00000054;
  *(undefined4 *)(param_1 + 0x38) = unaff_lr;
  *(undefined4 *)(param_1 + 0x3c) = unaff_lr;
  return 0;
}



undefined4 unw_getcontext(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 unaff_lr;
  
  *(int *)param_1 = param_1;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x10) = unaff_r4;
  *(undefined4 *)(param_1 + 0x14) = unaff_r5;
  *(undefined4 *)(param_1 + 0x18) = unaff_r6;
  *(undefined4 *)(param_1 + 0x1c) = unaff_r7;
  *(undefined4 *)(param_1 + 0x20) = unaff_r8;
  *(undefined4 *)(param_1 + 0x24) = unaff_r9;
  *(undefined4 *)(param_1 + 0x28) = unaff_r10;
  *(undefined4 *)(param_1 + 0x2c) = unaff_r11;
  *(undefined4 *)(param_1 + 0x30) = 0xffffe510;
  *(BADSPACEBASE **)(param_1 + 0x34) = register0x00000054;
  *(undefined4 *)(param_1 + 0x38) = unaff_lr;
  *(undefined4 *)(param_1 + 0x3c) = unaff_lr;
  return 0;
}



void __aeabi_memclr(void)

{
  __aeabi_memclr();
  return;
}



void __aeabi_memclr(void)

{
  __aeabi_memclr();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl libunwind::Registers_arm::saveVFPWithFSTMX(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl libunwind::Registers_arm::saveVFPWithFSTMX(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl libunwind::Registers_arm::saveVFPv3(undefined8 *param_1)

{
  undefined8 in_d16;
  undefined8 in_d17;
  undefined8 in_d18;
  undefined8 in_d19;
  undefined8 in_d20;
  undefined8 in_d21;
  undefined8 in_d22;
  undefined8 in_d23;
  undefined8 in_d24;
  undefined8 in_d25;
  undefined8 in_d26;
  undefined8 in_d27;
  undefined8 in_d28;
  undefined8 in_d29;
  undefined8 in_d30;
  undefined8 in_d31;
  
  *param_1 = in_d16;
  param_1[1] = in_d17;
  param_1[2] = in_d18;
  param_1[3] = in_d19;
  param_1[4] = in_d20;
  param_1[5] = in_d21;
  param_1[6] = in_d22;
  param_1[7] = in_d23;
  param_1[8] = in_d24;
  param_1[9] = in_d25;
  param_1[10] = in_d26;
  param_1[0xb] = in_d27;
  param_1[0xc] = in_d28;
  param_1[0xd] = in_d29;
  param_1[0xe] = in_d30;
  param_1[0xf] = in_d31;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl libunwind::Registers_arm::saveVFPv3(undefined8 *param_1)

{
  undefined8 in_d16;
  undefined8 in_d17;
  undefined8 in_d18;
  undefined8 in_d19;
  undefined8 in_d20;
  undefined8 in_d21;
  undefined8 in_d22;
  undefined8 in_d23;
  undefined8 in_d24;
  undefined8 in_d25;
  undefined8 in_d26;
  undefined8 in_d27;
  undefined8 in_d28;
  undefined8 in_d29;
  undefined8 in_d30;
  undefined8 in_d31;
  
  *param_1 = in_d16;
  param_1[1] = in_d17;
  param_1[2] = in_d18;
  param_1[3] = in_d19;
  param_1[4] = in_d20;
  param_1[5] = in_d21;
  param_1[6] = in_d22;
  param_1[7] = in_d23;
  param_1[8] = in_d24;
  param_1[9] = in_d25;
  param_1[10] = in_d26;
  param_1[0xb] = in_d27;
  param_1[0xc] = in_d28;
  param_1[0xd] = in_d29;
  param_1[0xe] = in_d30;
  param_1[0xf] = in_d31;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl libunwind::Registers_arm::saveVFPWithFSTMD(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl libunwind::Registers_arm::saveVFPWithFSTMD(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



// WARNING: Unknown calling convention: __cdecl

undefined4 __cdecl libunwind::Registers_arm::restoreVFPWithFLDMX(undefined8 *param_1)

{
  return (int)*param_1;
}



// WARNING: Unknown calling convention: __cdecl

undefined4 __cdecl libunwind::Registers_arm::restoreVFPWithFLDMX(undefined8 *param_1)

{
  return (int)*param_1;
}



// WARNING: Unknown calling convention: __cdecl

undefined4 __cdecl libunwind::Registers_arm::restoreVFPWithFLDMD(undefined8 *param_1)

{
  return (int)*param_1;
}



// WARNING: Unknown calling convention: __cdecl

undefined4 __cdecl libunwind::Registers_arm::restoreVFPWithFLDMD(undefined8 *param_1)

{
  return (int)*param_1;
}



void libunwind::Registers_arm::restoreVFPv3(void)

{
  return;
}



void libunwind::Registers_arm::restoreVFPv3(void)

{
  return;
}



void dladdr(void)

{
  dladdr();
  return;
}



void dladdr(void)

{
  dladdr();
  return;
}



void dl_iterate_phdr(void)

{
  dl_iterate_phdr();
  return;
}



void dl_iterate_phdr(void)

{
  dl_iterate_phdr();
  return;
}



void __vsnprintf_chk(void)

{
  __vsnprintf_chk();
  return;
}



void __vsnprintf_chk(void)

{
  __vsnprintf_chk();
  return;
}


