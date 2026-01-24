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

typedef pointer pointer __((offset(0xec)));

typedef pointer pointer __((offset(0x60)));

typedef pointer pointer __((offset(0x4c)));

typedef pointer pointer __((offset(0x68)));

typedef pointer pointer __((offset(0xac)));

typedef pointer pointer __((offset(0x180)));

typedef pointer pointer __((offset(0x6c)));

typedef pointer pointer __((offset(0xa0)));

typedef pointer pointer __((offset(0xb4)));

typedef pointer pointer __((offset(0x9c)));

typedef pointer pointer __((offset(0x14)));

typedef pointer pointer __((offset(0x134)));

typedef pointer pointer __((offset(0x34)));

typedef pointer pointer __((offset(0x40)));

typedef pointer pointer __((offset(0x48)));

typedef pointer pointer __((offset(0x3c)));

typedef pointer pointer __((offset(0xdc)));

typedef pointer pointer __((offset(0x64)));

typedef pointer pointer __((offset(0x58)));

typedef pointer pointer __((offset(0x50)));

typedef pointer pointer __((offset(0x5c)));

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

typedef struct __func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_1,std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_1>,void(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)> __func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_1,std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_1>,void(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>, *P__func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_1,std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_1>,void(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>;

struct __func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_1,std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_1>,void(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)> { // PlaceHolder Class Structure
};

typedef struct __func<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3,std::allocator<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3>,void(unsigned_int,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)> __func<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3,std::allocator<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3>,void(unsigned_int,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>, *P__func<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3,std::allocator<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3>,void(unsigned_int,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>;

struct __func<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3,std::allocator<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3>,void(unsigned_int,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)> { // PlaceHolder Class Structure
};

typedef struct __func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_2,std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_2>,void(vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)> __func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_2,std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_2>,void(vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>, *P__func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_2,std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_2>,void(vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>;

struct __func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_2,std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex_const&,android::sp<android::IMemory>const&,cacao::ISerialize::SerializedData)::$_2>,void(vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)> { // PlaceHolder Class Structure
};

typedef struct sp<android::hidl::manager::V1_0::IServiceNotification> sp<android::hidl::manager::V1_0::IServiceNotification>, *Psp<android::hidl::manager::V1_0::IServiceNotification>;

struct sp<android::hidl::manager::V1_0::IServiceNotification> { // PlaceHolder Class Structure
};

typedef struct sp<android::hardware::hidl_death_recipient> sp<android::hardware::hidl_death_recipient>, *Psp<android::hardware::hidl_death_recipient>;

struct sp<android::hardware::hidl_death_recipient> { // PlaceHolder Class Structure
};

typedef struct sp<android::CacaoService::Client> sp<android::CacaoService::Client>, *Psp<android::CacaoService::Client>;

struct sp<android::CacaoService::Client> { // PlaceHolder Class Structure
};

typedef struct sp<android::IBinder> sp<android::IBinder>, *Psp<android::IBinder>;

struct sp<android::IBinder> { // PlaceHolder Class Structure
};

typedef struct sp<android::IBinder::DeathRecipient> sp<android::IBinder::DeathRecipient>, *Psp<android::IBinder::DeathRecipient>;

struct sp<android::IBinder::DeathRecipient> { // PlaceHolder Class Structure
};

typedef struct sp<android::ICacaoProcessCallback> sp<android::ICacaoProcessCallback>, *Psp<android::ICacaoProcessCallback>;

struct sp<android::ICacaoProcessCallback> { // PlaceHolder Class Structure
};

typedef struct UnwindCursor<libunwind::LocalAddressSpace,libunwind::Registers_arm> UnwindCursor<libunwind::LocalAddressSpace,libunwind::Registers_arm>, *PUnwindCursor<libunwind::LocalAddressSpace,libunwind::Registers_arm>;

struct UnwindCursor<libunwind::LocalAddressSpace,libunwind::Registers_arm> { // PlaceHolder Class Structure
};

typedef struct Registers_arm Registers_arm, *PRegisters_arm;

struct Registers_arm { // PlaceHolder Class Structure
};

typedef struct _IO_FILE FILE;

typedef int __pid_t;

typedef union pthread_mutex_t pthread_mutex_t, *Ppthread_mutex_t;

typedef struct __pthread_mutex_s __pthread_mutex_s, *P__pthread_mutex_s;

typedef union _union_13 _union_13, *P_union_13;

typedef struct __pthread_internal_slist __pthread_internal_slist, *P__pthread_internal_slist;

typedef struct __pthread_internal_slist __pthread_slist_t;

struct __pthread_internal_slist {
    struct __pthread_internal_slist *__next;
};

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

typedef struct unw_cursor_t unw_cursor_t, *Punw_cursor_t;

struct unw_cursor_t { // PlaceHolder Structure
};

typedef struct unw_context_t unw_context_t, *Punw_context_t;

struct unw_context_t { // PlaceHolder Structure
};

typedef struct _Unwind_Control_Block _Unwind_Control_Block, *P_Unwind_Control_Block;

struct _Unwind_Control_Block { // PlaceHolder Structure
};

typedef struct unw_proc_info_t unw_proc_info_t, *Punw_proc_info_t;

struct unw_proc_info_t { // PlaceHolder Structure
};

typedef struct dl_phdr_info dl_phdr_info, *Pdl_phdr_info;

struct dl_phdr_info { // PlaceHolder Structure
};

typedef struct function<void(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)> function<void(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>, *Pfunction<void(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>;

struct function<void(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps_const&,vendor::somc::hardware::camera::cacao::V3_0::ErrCode)> { // PlaceHolder Structure
};


// WARNING! conflicting data type names: /Demangler/std/string - /string

typedef undefined function;

typedef struct __base __base, *P__base;

struct __base { // PlaceHolder Structure
};

typedef struct __func<android::CacaoService::getInterfaces()::$_0,std::allocator<android::CacaoService::getInterfaces()::$_0>,void(android::hardware::camera::common::V1_0::Status,android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao>const&)> __func<android::CacaoService::getInterfaces()::$_0,std::allocator<android::CacaoService::getInterfaces()::$_0>,void(android::hardware::camera::common::V1_0::Status,android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao>const&)>, *P__func<android::CacaoService::getInterfaces()::$_0,std::allocator<android::CacaoService::getInterfaces()::$_0>,void(android::hardware::camera::common::V1_0::Status,android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao>const&)>;

struct __func<android::CacaoService::getInterfaces()::$_0,std::allocator<android::CacaoService::getInterfaces()::$_0>,void(android::hardware::camera::common::V1_0::Status,android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao>const&)> { // PlaceHolder Structure
};

typedef struct ObjectBase ObjectBase, *PObjectBase;

struct ObjectBase { // PlaceHolder Structure
};

typedef undefined ImageSize;

typedef struct ProcessEventBase ProcessEventBase, *PProcessEventBase;

struct ProcessEventBase { // PlaceHolder Structure
};

typedef struct ICBProcessResultListener ICBProcessResultListener, *PICBProcessResultListener;

struct ICBProcessResultListener { // PlaceHolder Structure
};

typedef struct Caps Caps, *PCaps;

struct Caps { // PlaceHolder Structure
};

typedef struct ProcessResultBase ProcessResultBase, *PProcessResultBase;

struct ProcessResultBase { // PlaceHolder Structure
};

typedef struct CameraIndex CameraIndex, *PCameraIndex;

struct CameraIndex { // PlaceHolder Structure
};

typedef undefined SerializedData;

typedef struct CacaoCaps CacaoCaps, *PCacaoCaps;

struct CacaoCaps { // PlaceHolder Structure
};

typedef struct ErrCode ErrCode, *PErrCode;

struct ErrCode { // PlaceHolder Structure
};

typedef struct ICacao ICacao, *PICacao;

struct ICacao { // PlaceHolder Structure
};

typedef struct List<android::sp<android::CacaoService::Client>> List<android::sp<android::CacaoService::Client>>, *PList<android::sp<android::CacaoService::Client>>;

struct List<android::sp<android::CacaoService::Client>> { // PlaceHolder Structure
};

typedef struct BnInterface<android::ICacao> BnInterface<android::ICacao>, *PBnInterface<android::ICacao>;

struct BnInterface<android::ICacao> { // PlaceHolder Structure
};

typedef struct sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao> sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao>, *Psp<vendor::somc::hardware::camera::cacao::V3_0::ICacao>;

struct sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao> { // PlaceHolder Structure
};

typedef struct MemoryBase MemoryBase, *PMemoryBase;

struct MemoryBase { // PlaceHolder Structure
};

typedef struct List<android::CacaoService::Client::Request*> List<android::CacaoService::Client::Request*>, *PList<android::CacaoService::Client::Request*>;

struct List<android::CacaoService::Client::Request*> { // PlaceHolder Structure
};

typedef struct VectorImpl VectorImpl, *PVectorImpl;

struct VectorImpl { // PlaceHolder Structure
};

typedef struct BnInterface<android::ICacaoService> BnInterface<android::ICacaoService>, *PBnInterface<android::ICacaoService>;

struct BnInterface<android::ICacaoService> { // PlaceHolder Structure
};

typedef struct String16 String16, *PString16;

struct String16 { // PlaceHolder Structure
};

typedef struct sp<android::IMemory> sp<android::IMemory>, *Psp<android::IMemory>;

struct sp<android::IMemory> { // PlaceHolder Structure
};

typedef struct sp<android::ICacaoClient> sp<android::ICacaoClient>, *Psp<android::ICacaoClient>;

struct sp<android::ICacaoClient> { // PlaceHolder Structure
};

typedef struct sp sp, *Psp;

struct sp { // PlaceHolder Structure
};

typedef struct IBinder IBinder, *PIBinder;

struct IBinder { // PlaceHolder Structure
};

typedef struct wp wp, *Pwp;

struct wp { // PlaceHolder Structure
};

typedef struct Vector Vector, *PVector;

struct Vector { // PlaceHolder Structure
};

typedef struct ICacaoService ICacaoService, *PICacaoService;

struct ICacaoService { // PlaceHolder Structure
};

typedef struct sp<android::IMemoryHeap> sp<android::IMemoryHeap>, *Psp<android::IMemoryHeap>;

struct sp<android::IMemoryHeap> { // PlaceHolder Structure
};

typedef struct wp<android::IBinder::DeathRecipient> wp<android::IBinder::DeathRecipient>, *Pwp<android::IBinder::DeathRecipient>;

struct wp<android::IBinder::DeathRecipient> { // PlaceHolder Structure
};

typedef struct MemoryHeapBase MemoryHeapBase, *PMemoryHeapBase;

struct MemoryHeapBase { // PlaceHolder Structure
};

typedef struct Parcel Parcel, *PParcel;

struct Parcel { // PlaceHolder Structure
};

typedef struct Vector<cacao::ImageBuf*> Vector<cacao::ImageBuf*>, *PVector<cacao::ImageBuf*>;

struct Vector<cacao::ImageBuf*> { // PlaceHolder Structure
};

typedef struct IInterface IInterface, *PIInterface;

struct IInterface { // PlaceHolder Structure
};

typedef struct CacaoService CacaoService, *PCacaoService;

struct CacaoService { // PlaceHolder Structure
};

typedef struct RefBase RefBase, *PRefBase;

struct RefBase { // PlaceHolder Structure
};

typedef struct BBinder BBinder, *PBBinder;

struct BBinder { // PlaceHolder Structure
};

typedef undefined _ListIterator;

typedef struct IBase IBase, *PIBase;

struct IBase { // PlaceHolder Structure
};

typedef struct Client Client, *PClient;

struct Client { // PlaceHolder Structure
};

typedef struct Request Request, *PRequest;

struct Request { // PlaceHolder Structure
};

typedef struct hidl_string hidl_string, *Phidl_string;

struct hidl_string { // PlaceHolder Structure
};

typedef struct hidl_vec hidl_vec, *Phidl_vec;

struct hidl_vec { // PlaceHolder Structure
};

typedef struct hidl_handle hidl_handle, *Phidl_handle;

struct hidl_handle { // PlaceHolder Structure
};

typedef struct hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize> hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize>, *Phidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize>;

struct hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize> { // PlaceHolder Structure
};

typedef struct hidl_vec<unsigned_int> hidl_vec<unsigned_int>, *Phidl_vec<unsigned_int>;

struct hidl_vec<unsigned_int> { // PlaceHolder Structure
};

typedef struct hidl_death_recipient hidl_death_recipient, *Phidl_death_recipient;

struct hidl_death_recipient { // PlaceHolder Structure
};

typedef struct Status Status, *PStatus;

struct Status { // PlaceHolder Structure
};

typedef struct return_status return_status, *Preturn_status;

struct return_status { // PlaceHolder Structure
};

typedef struct UnwindInfoSections UnwindInfoSections, *PUnwindInfoSections;

struct UnwindInfoSections { // PlaceHolder Structure
};

typedef struct AbstractUnwindCursor AbstractUnwindCursor, *PAbstractUnwindCursor;

struct AbstractUnwindCursor { // PlaceHolder Structure
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

typedef struct Elf32_Dyn_ARM Elf32_Dyn_ARM, *PElf32_Dyn_ARM;

struct Elf32_Dyn_ARM {
    enum Elf32_DynTag_ARM d_tag;
    dword d_val;
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

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
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



pointer __((offset(0xc))) VTT;
undefined4 __stack_chk_guard;
pointer PTR_~Request_00020c48;
pointer PTR_~Vector+1_000218b8;
pointer __((offset(0x14))) VTT;
pointer PTR_~Caps+1_00021868;
undefined *PTR_~Caps+1_0002188c;
undefined *PTR_~AbstractUnwindCursor+1_00021914;
undefined *PTR_~AbstractUnwindCursor+1_00021938;
undefined *PTR_~AbstractUnwindCursor+1_0002195c;
undefined DAT_00022000;
pointer PTR_~List+1_000218a8;
pointer PTR_~AbstractUnwindCursor+1_0002183c;
pointer PTR_~AbstractUnwindCursor+1_00021854;
pointer PTR_~List+1_000218e0;
undefined *PTR_~AbstractUnwindCursor+1_000218f0;
undefined4 descriptor;
undefined DAT_0001ea01;
undefined remoteBinder;
undefined *PTR_~AbstractUnwindCursor+1_00021980;
undefined DAT_00022004;
undefined DAT_0001ec54;

sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::incStrong(void *param_1)

{
  incStrong(param_1);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::decStrong(void *param_1)

{
  decStrong(param_1);
  return;
}



Request * __thiscall android::CacaoService::Client::Request::~Request(Request *this)

{
  Request *pRVar1;
  
  pRVar1 = ~Request(this);
  return pRVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void operator_delete(void *param_1)

{
  operator_delete(param_1);
  return;
}



void __thiscall android::ICacao::ICacao(ICacao *this)

{
  ICacao(this);
  return;
}



void __thiscall android::BBinder::BBinder(BBinder *this)

{
  BBinder(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
  int iVar1;
  
  iVar1 = pthread_mutex_init(__mutex,__mutexattr);
  return iVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * operator_new__(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new__(param_1);
  return pvVar1;
}



void __android_log_print(void)

{
  __android_log_print();
  return;
}



void cacao::ProcessFactoryInternal::createProcess(void)

{
  createProcess();
  return;
}



void __thiscall android::RefBase::RefBase(RefBase *this)

{
  RefBase(this);
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

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_destroy(__mutex);
  return iVar1;
}



void __thiscall android::BBinder::~BBinder(BBinder *this)

{
  ~BBinder(this);
  return;
}



void __thiscall android::ICacao::~ICacao(ICacao *this)

{
  ~ICacao(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void operator_delete__(void *param_1)

{
  operator_delete__(param_1);
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this,int *param_1)

{
  ~Client(this,param_1);
  return;
}



void __thiscall android::RefBase::~RefBase(RefBase *this)

{
  ~RefBase(this);
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this);
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

void android::IPCThreadState::self(void)

{
  self();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IPCThreadState::getCallingPid(void)

{
  getCallingPid();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = getpid();
  return _Var1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_unlock(__mutex);
  return iVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IInterface::asBinder(sp *param_1)

{
  asBinder(param_1);
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



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createMode(SerializedData *param_1)

{
  createMode(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createConfig(uint param_1,SerializedData *param_2)

{
  createConfig(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createParam(SerializedData *param_1)

{
  createParam(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createResult(SerializedData *param_1)

{
  createResult(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



void __thiscall android::VectorImpl::VectorImpl(VectorImpl *this,uint param_1,uint param_2)

{
  VectorImpl(this,param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::VectorImpl::insertAt(void *param_1,uint param_2,uint param_3)

{
  insertAt(param_1,param_2,param_3);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createParam(sp *param_1,SerializedData *param_2)

{
  createParam(param_1,param_2);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __aeabi_memclr8(void)

{
  __aeabi_memclr8();
  return;
}



void __thiscall android::CacaoService::Client::allocMemory(Client *this,uint param_1)

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



sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  sp<> *psVar1;
  
  psVar1 = ~sp(this);
  return psVar1;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::CacaoService::Client::makeSerializedData(int *param_1,int param_2)

{
  makeSerializedData(param_1,param_2);
  return;
}



void __thiscall android::sp<>::clear(sp<> *this)

{
  clear(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::sp_report_race(void)

{
  sp_report_race();
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



void __thiscall android::CacaoService::Client::onHandleEvent(Client *this,int *param_1)

{
  onHandleEvent(this,param_1);
  return;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



void __thiscall android::CacaoService::Client::onHandleProgress(Client *this,int *param_1)

{
  onHandleProgress(this,param_1);
  return;
}



void __thiscall android::CacaoService::Client::onHandleResult(Client *this,int *param_1)

{
  onHandleResult(this,param_1);
  return;
}



void __thiscall android::ICacaoService::ICacaoService(ICacaoService *this)

{
  ICacaoService(this);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::camera::provider::V2_4::ICameraProvider::registerForNotifications
               (string *param_1,sp *param_2)

{
  registerForNotifications(param_1,param_2);
  return;
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



void __thiscall android::ICacaoService::~ICacaoService(ICacaoService *this)

{
  ~ICacaoService(this);
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this,int *param_1)

{
  ~CacaoService(this,param_1);
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this);
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

void android::hardware::Status::description(void)

{
  description();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::details::return_status::assertOk(void)

{
  assertOk();
  return;
}



void __thiscall
android::hardware::details::return_status::operator=(return_status *this,return_status *param_1)

{
  operator=(this,param_1);
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



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void vendor::somc::hardware::camera::cacao::V3_1::ICacao::castFrom(sp *param_1,bool param_2)

{
  castFrom(param_1,param_2);
  return;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  sp<> *psVar1;
  
  psVar1 = operator=(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



void __aeabi_memcpy(void)

{
  __aeabi_memcpy();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void vendor::somc::hardware::camera::provider::V1_0::IVendorSomcCameraProvider::getService
               (string *param_1,bool param_2)

{
  getService(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void std::__basic_string_common<true>::__throw_length_error(void)

{
  __throw_length_error();
  return;
}



void __thiscall android::CacaoService::getInterfaces(CacaoService *this)

{
  getInterfaces(this);
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



Client * __thiscall
android::CacaoService::Client::Client(Client *this,int *param_1,int *param_2,undefined4 param_3)

{
  Client *pCVar1;
  
  pCVar1 = Client(this,param_1,param_2,param_3);
  return pCVar1;
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



void __thiscall cacao::ObjectBase::ObjectBase(ObjectBase *this)

{
  ObjectBase(this);
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



void __thiscall cacao::ObjectBase::~ObjectBase(ObjectBase *this)

{
  ~ObjectBase(this);
  return;
}



void __aeabi_memcpy4(void)

{
  __aeabi_memcpy4();
  return;
}



function<> * __thiscall std::function<>::~function(function<> *this)

{
  function<> *pfVar1;
  
  pfVar1 = ~function(this);
  return pfVar1;
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



void __thiscall android::String16::String16(String16 *this,char *param_1)

{
  String16(this,param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::checkCallingPermission(String16 *param_1)

{
  checkCallingPermission(param_1);
  return;
}



void __thiscall android::String16::~String16(String16 *this)

{
  ~String16(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BnCacaoService::onTransact(uint param_1,Parcel *param_2,Parcel *param_3,uint param_4)

{
  onTransact(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl
android::CacaoService::onTransact(int *param_1,Parcel *param_2,Parcel *param_3,uint param_4)

{
  onTransact(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::wp<>::promote(int *param_1,int *param_2)

{
  promote(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::weakref_type::attemptIncStrong(void *param_1)

{
  attemptIncStrong(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::CacaoService::binderDied(int *param_1,int *param_2)

{
  binderDied(param_1,param_2);
  return;
}



void __thiscall android::CacaoService::Client::serviceDied(Client *this)

{
  serviceDied(this);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void abort(void)

{
                    // WARNING: Subroutine does not return
  abort();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl
android::CacaoService::serviceDied(int param_1,undefined4 param_2_00,int param_3,int param_4)

{
  serviceDied(param_1,param_2_00,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ICacao::getInterfaceDescriptor(void)

{
  getInterfaceDescriptor();
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



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ICacaoService::getInterfaceDescriptor(void)

{
  getInterfaceDescriptor();
  return;
}



sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp<>(this,param_1);
  return psVar1;
}



void __thiscall cacao::ObjectBase::operator_delete(ObjectBase *this,void *param_1)

{
  operator_delete(this,param_1);
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



void __aeabi_memmove(void)

{
  __aeabi_memmove();
  return;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



void __aeabi_memclr4(void)

{
  __aeabi_memclr4();
  return;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::defaultServiceManager(void)

{
  defaultServiceManager();
  return;
}



CacaoService * __thiscall android::CacaoService::CacaoService(CacaoService *this)

{
  CacaoService *pCVar1;
  
  pCVar1 = CacaoService(this);
  return pCVar1;
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



void __thiscall android::CacaoService::Client::Request::~Request(Request *this)

{
  Request *pRVar1;
  
  pRVar1 = ~Request(this);
  operator_delete(pRVar1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::CacaoService::Client::Request::onHandleProgress(int param_1)

{
  if (*(int **)(param_1 + 8) == (int *)0x0) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00018ad0. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 8) + 8))();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::CacaoService::Client::Request::onHandleResult(int param_1)

{
  if (*(int **)(param_1 + 8) == (int *)0x0) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00018adc. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 8) + 0xc))();
  return;
}



void __thiscall
android::CacaoService::Client::Request::setBufVector(Request *this,undefined4 param_1)

{
  *(undefined4 *)(this + 0xc) = param_1;
  return;
}



void __thiscall android::CacaoService::Client::Request::setResult(Request *this,undefined4 param_1)

{
  *(undefined4 *)(this + 0x10) = param_1;
  return;
}



Client * __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x40));
  return this;
}



BnInterface<> * __thiscall android::BnInterface<>::onAsBinder(BnInterface<> *this)

{
  return this + 4;
}



void __thiscall android::CacaoService::Client::disconnect(Client *this)

{
  int iVar1;
  __pid_t _Var2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  sp<> asStack_30 [4];
  sp asStack_2c [4];
  int iStack_28;
  
  iStack_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  android::IPCThreadState::self();
  iVar1 = android::IPCThreadState::getCallingPid();
  if (iVar1 != *(int *)(this + 0x2c)) {
    android::IPCThreadState::self();
    iVar1 = android::IPCThreadState::getCallingPid();
    _Var2 = getpid();
    if (iVar1 != _Var2) goto LAB_00018f84;
  }
  if (*(int **)(this + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x30) + 4))();
  }
  *(undefined4 *)(this + 0x30) = 0;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x20));
  while (piVar4 = (int *)(*(int **)(this + 0x3c))[2], piVar4 != *(int **)(this + 0x3c)) {
    if ((int *)*piVar4 != (int *)0x0) {
      (**(code **)(*(int *)*piVar4 + 4))();
    }
    iVar1 = piVar4[1];
    iVar3 = piVar4[2];
    *(int *)(iVar1 + 8) = iVar3;
    *(int *)(iVar3 + 4) = iVar1;
    if (piVar4 != (int *)0x0) {
      operator_delete(piVar4);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x20));
  if (this[0x34] == (Client)0x0) {
    pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
    piVar4 = *(int **)(this + 0x24);
    pcVar5 = *(code **)(*piVar4 + 0x2c);
    sp<>::sp(asStack_30,(int *)(this + 0x28));
    android::IInterface::asBinder(asStack_2c);
    (*pcVar5)(piVar4,asStack_2c);
    sp<>::~sp((sp<> *)asStack_2c);
    sp<>::~sp((sp<> *)asStack_30);
    sp<>::clear((sp<> *)(this + 0x28));
    pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  }
LAB_00018f84:
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  if (__stack_chk_guard != iStack_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

int __cdecl
android::CacaoService::Client::start
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x18));
  if ((*(int *)(param_1 + 0x30) == 0) ||
     (piVar1 = (int *)cacao::ProcessFactoryInternal::createMode((SerializedData *)&uStack_8),
     piVar1 == (int *)0x0)) {
    iVar3 = -0x80000000;
  }
  else {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x30) + 0xc))(*(int **)(param_1 + 0x30),piVar1);
    (**(code **)(*piVar1 + 4))(piVar1);
    iVar3 = iVar2;
    if (iVar2 != -0x6e) {
      iVar3 = -0x80000000;
    }
    if (-1 < iVar2) {
      iVar3 = 0;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x18));
  return iVar3;
}



int __thiscall android::CacaoService::Client::stop(Client *this)

{
  int iVar1;
  int iVar2;
  
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  if (*(int **)(this + 0x30) == (int *)0x0) {
    iVar2 = -0x80000000;
  }
  else {
    iVar1 = (**(code **)(**(int **)(this + 0x30) + 0x10))();
    iVar2 = iVar1;
    if (iVar1 != -0x6e) {
      iVar2 = -0x80000000;
    }
    if (-1 < iVar1) {
      iVar2 = 0;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  return iVar2;
}



int __thiscall
android::CacaoService::Client::setConfig
          (Client *this,uint param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_4;
  
  uStack_4 = param_3;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  if ((*(int *)(this + 0x30) == 0) ||
     (piVar1 = (int *)cacao::ProcessFactoryInternal::createConfig
                                (param_1,(SerializedData *)&uStack_4), piVar1 == (int *)0x0)) {
    iVar3 = -0x80000000;
  }
  else {
    iVar2 = (**(code **)(**(int **)(this + 0x30) + 0x14))(*(int **)(this + 0x30),piVar1);
    (**(code **)(*piVar1 + 4))(piVar1);
    iVar3 = iVar2;
    if (iVar2 != -0x6e) {
      iVar3 = -0x80000000;
    }
    if (-1 < iVar2) {
      iVar3 = 0;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  return iVar3;
}



int __thiscall
android::CacaoService::Client::getConfig
          (Client *this,uint param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_4;
  
  uStack_4 = param_3;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  if (*(int *)(this + 0x30) != 0) {
    piVar1 = (int *)cacao::ProcessFactoryInternal::createConfig(param_1,(SerializedData *)&uStack_4)
    ;
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(**(int **)(this + 0x30) + 0x18))(*(int **)(this + 0x30),piVar1);
      if (-1 < iVar2) {
        iVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,&uStack_4);
      }
      (**(code **)(*piVar1 + 4))(piVar1);
      iVar3 = iVar2;
      if (iVar2 != -0x6e) {
        iVar3 = -0x80000000;
      }
      if (-1 < iVar2) {
        iVar3 = 0;
      }
      goto LAB_00019116;
    }
  }
  iVar3 = -0x80000000;
LAB_00019116:
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  return iVar3;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

undefined4 __cdecl
android::CacaoService::Client::process
          (int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  VectorImpl *this;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int in_stack_0000018c;
  int in_stack_00000328;
  int *in_stack_0000032c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x18));
  if (*(int *)(param_1 + 0x30) == 0) {
LAB_00019158:
    uVar7 = 0;
  }
  else {
    if (*param_2 == 0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)cacao::ProcessFactoryInternal::createParam((SerializedData *)&uStack_8);
      if (piVar1 == (int *)0x0) goto LAB_00019158;
    }
    iVar2 = cacao::ProcessFactoryInternal::createResult(&stack0x00000194);
    if (iVar2 == 0) {
      uVar7 = 0;
    }
    else {
      if (*(int *)(in_stack_0000018c + 8) == 0) {
        this = (VectorImpl *)0x0;
      }
      else {
        this = operator_new(0x14);
        android::VectorImpl::VectorImpl(this,4,7);
        *(undefined ***)this = &PTR__Vector_1_000218b8;
        if (*(int *)(in_stack_0000018c + 8) != 0) {
          iVar8 = 0;
          uVar6 = 0;
          do {
            android::VectorImpl::insertAt
                      (this,*(int *)(in_stack_0000018c + 4) + iVar8,*(uint *)(this + 8));
            uVar6 = uVar6 + 1;
            iVar8 = iVar8 + 4;
          } while (uVar6 < *(uint *)(in_stack_0000018c + 8));
        }
      }
      piVar3 = operator_new(0x14);
      *piVar3 = (int)&PTR__Request_00020c48;
      sp<>::sp((sp<> *)(piVar3 + 1),in_stack_0000032c);
      piVar3[2] = param_1 + 0x14;
      piVar3[3] = 0;
      piVar3[4] = 0;
      (**(code **)(*piVar3 + 0x18))(piVar3,iVar2);
      (**(code **)(*piVar3 + 0x10))(piVar3,this);
      pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x20));
      iVar8 = *(int *)(param_1 + 0x3c);
      puVar4 = operator_new(0xc);
      *puVar4 = piVar3;
      puVar4[2] = iVar8;
      puVar4[1] = *(undefined4 *)(iVar8 + 4);
      *(undefined4 **)(*(int *)(iVar8 + 4) + 8) = puVar4;
      *(undefined4 **)(iVar8 + 4) = puVar4;
      pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x20));
      piVar5 = *(int **)(param_1 + 0x30);
      if (in_stack_00000328 == 0) {
        uVar7 = (**(code **)(*piVar5 + 0x20))(piVar5,piVar1,this,piVar3,iVar2);
      }
      else {
        uVar7 = (**(code **)(*piVar5 + 0x1c))(piVar5,piVar1,piVar3,iVar2);
      }
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x18));
  return uVar7;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

undefined4 __cdecl
android::CacaoService::Client::process
          (int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  code *pcVar9;
  sp *in_stack_0000018c;
  int in_stack_00000328;
  int *in_stack_0000032c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x18));
  if (*(int *)(param_1 + 0x30) == 0) {
LAB_000192aa:
    uVar8 = 0;
  }
  else {
    if (*param_2 == 0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)cacao::ProcessFactoryInternal::createParam
                                (in_stack_0000018c,(SerializedData *)&uStack_8);
      if (piVar1 == (int *)0x0) goto LAB_000192aa;
    }
    piVar2 = (int *)cacao::ProcessFactoryInternal::createResult(&stack0x00000194);
    uVar8 = 0;
    if (piVar2 != (int *)0x0) {
      piVar3 = operator_new(0x14);
      *piVar3 = (int)&PTR__Request_00020c48;
      sp<>::sp((sp<> *)(piVar3 + 1),in_stack_0000032c);
      piVar3[2] = param_1 + 0x14;
      piVar3[3] = 0;
      piVar3[4] = 0;
      (**(code **)(*piVar3 + 0x10))(piVar3,0);
      (**(code **)(*piVar3 + 0x18))(piVar3,piVar2);
      pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x20));
      iVar7 = *(int *)(param_1 + 0x3c);
      puVar4 = operator_new(0xc);
      *puVar4 = piVar3;
      puVar4[2] = iVar7;
      puVar4[1] = *(undefined4 *)(iVar7 + 4);
      *(undefined4 **)(*(int *)(iVar7 + 4) + 8) = puVar4;
      *(undefined4 **)(iVar7 + 4) = puVar4;
      pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x20));
      piVar5 = *(int **)(param_1 + 0x30);
      if (in_stack_00000328 == 0) {
        piVar6 = (int *)0x0;
        pcVar9 = *(code **)(*piVar5 + 0x20);
      }
      else {
        pcVar9 = *(code **)(*piVar5 + 0x1c);
        piVar6 = piVar3;
        piVar3 = piVar2;
      }
      uVar8 = (*pcVar9)(piVar5,piVar1,piVar6,piVar3);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x18));
  return uVar8;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

int __cdecl android::CacaoService::Client::cancel(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    return -0x80000000;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0x30) + 0x24))();
  iVar2 = iVar1;
  if (iVar1 != -0x6e) {
    iVar2 = -0x80000000;
  }
  if (-1 < iVar1) {
    iVar2 = 0;
  }
  return iVar2;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BnCacao::onTransact(uint param_1,Parcel *param_2,Parcel *param_3,uint param_4)

{
  onTransact(param_1,param_2,param_3,param_4);
  return;
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



void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -4,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x3c));
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -4);
  return;
}



void android::BnCacao::onTransact(void)

{
  onTransact();
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -0x10,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x30));
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -0x10);
  return;
}



void __thiscall android::CacaoService::Client::onHandleEvent(Client *this)

{
  int *in_r1;
  
  onHandleEvent(this + -0x10,in_r1);
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -0x14,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x2c));
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -0x14);
  return;
}



void __thiscall android::CacaoService::Client::onHandleProgress(Client *this)

{
  int *in_r1;
  
  onHandleProgress(this + -0x14,in_r1);
  return;
}



void __thiscall android::CacaoService::Client::onHandleResult(Client *this)

{
  int *in_r1;
  
  onHandleResult(this + -0x14,in_r1);
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  int iVar1;
  
  iVar1 = ~Client(this + *(int *)(*(int *)this + -0xc),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x40));
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + *(int *)(*(int *)this + -0xc));
  return;
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



CacaoService * __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x38));
  return this;
}



BnInterface<> * __thiscall android::BnInterface<>::onAsBinder(BnInterface<> *this)

{
  return this + 4;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::CacaoService::connect(undefined4 *param_1,int *param_2,int *param_3)

{
  Client *this;
  undefined4 uVar1;
  sp<> asStack_30 [4];
  undefined4 uStack_2c;
  int iStack_28;
  
  iStack_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(param_2 + 5));
  this = operator_new(0x48);
  sp<>::sp<>(asStack_30,param_2);
  android::IPCThreadState::self();
  uVar1 = android::IPCThreadState::getCallingPid();
  Client::Client(this,(int *)asStack_30,param_3,uVar1);
  sp<>::sp<>((sp<> *)&uStack_2c,(int *)this);
  sp<>::~sp((sp<> *)asStack_30);
  (**(code **)(*param_2 + 0x28))(param_2,(sp<> *)&uStack_2c);
  *param_1 = uStack_2c;
  uStack_2c = 0;
  sp<>::~sp((sp<> *)&uStack_2c);
  pthread_mutex_unlock((pthread_mutex_t *)(param_2 + 5));
  if (__stack_chk_guard != iStack_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void android::CacaoService::getServicePid(void)

{
  getpid();
  return;
}



int __thiscall
android::CacaoService::getCaps
          (CacaoService *this,int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  void *pvVar11;
  uint extraout_r3;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int iStack_28ac;
  return_status arStack_28a8 [8];
  void *pvStack_28a0;
  int aiStack_2890 [3];
  undefined3 uStack_2883;
  undefined4 uStack_2880;
  undefined1 uStack_287c;
  CacaoCaps aCStack_2878 [16];
  void *pvStack_2868;
  char cStack_285c;
  void *pvStack_2858;
  char cStack_284c;
  void *pvStack_2840;
  char cStack_2834;
  void *pvStack_2830;
  char cStack_2824;
  void *pvStack_2818;
  char cStack_280c;
  void *pvStack_2808;
  char cStack_27fc;
  void *pvStack_27e8;
  char cStack_27dc;
  void *pvStack_27d8;
  char cStack_27cc;
  void *pvStack_27c8;
  char cStack_27bc;
  undefined4 uStack_27b0;
  uint uStack_27a8;
  void *pvStack_27a0;
  undefined8 uStack_2798;
  undefined4 *puStack_2790;
  undefined8 uStack_2788;
  uint uStack_2780;
  void *pvStack_2778;
  undefined8 uStack_2770;
  undefined4 *puStack_2768;
  undefined8 uStack_2760;
  undefined4 auStack_2758 [2];
  uint uStack_2750;
  void *pvStack_2748;
  char cStack_273c;
  undefined4 *puStack_2738;
  char cStack_272c;
  uint uStack_2728;
  void *pvStack_2720;
  char cStack_2714;
  undefined4 *puStack_2710;
  char cStack_2704;
  uint uStack_2700;
  void *pvStack_26f8;
  char cStack_26ec;
  undefined4 *puStack_26e8;
  char cStack_26dc;
  undefined4 uStack_26d8;
  uint uStack_26d0;
  void *pvStack_26c8;
  char cStack_26bc;
  undefined4 *puStack_26b8;
  char cStack_26ac;
  undefined4 *puStack_26a8;
  char cStack_269c;
  undefined4 uStack_2698;
  undefined4 uStack_2694;
  undefined **ppuStack_2690;
  CacaoCaps *pCStack_268c;
  int *piStack_2688;
  function<> *pfStack_2680;
  undefined **ppuStack_2678;
  int iStack_2674;
  CacaoCaps *pCStack_2670;
  int *piStack_266c;
  function<> *pfStack_2668;
  undefined **ppuStack_2660;
  undefined **ppuStack_265c;
  undefined4 uStack_2658;
  uint uStack_2654;
  undefined4 auStack_2650 [256];
  undefined4 auStack_2250 [129];
  undefined4 auStack_204c [256];
  undefined4 auStack_1c4c [128];
  uint uStack_1a4c;
  undefined4 auStack_1a48 [256];
  undefined4 auStack_1648 [128];
  undefined4 uStack_1448;
  uint uStack_1444;
  undefined4 auStack_1440 [256];
  undefined4 auStack_1040 [128];
  undefined4 auStack_e40 [128];
  undefined4 uStack_c40;
  undefined4 uStack_c3c;
  undefined4 uStack_c38;
  uint uStack_c34;
  undefined4 auStack_c30 [256];
  undefined4 auStack_830 [128];
  uint uStack_630;
  undefined4 auStack_62c [256];
  undefined4 auStack_22c [129];
  undefined4 uStack_4;
  
  iVar4 = __stack_chk_guard;
  uStack_4 = param_3;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x14));
  cacao::ObjectBase::ObjectBase((ObjectBase *)&ppuStack_2660);
  ppuStack_265c = &PTR__Caps_1_0002188c;
  ppuStack_2660 = &PTR__Caps_1_00021868;
  vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps::CacaoCaps((CacaoCaps *)auStack_2758);
  iVar5 = vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps::CacaoCaps(aCStack_2878);
  *(undefined8 *)(iVar5 + 0xd8) = 0;
  uStack_2798 = 0;
  *(undefined1 *)(iVar5 + 0xe4) = 1;
  uStack_2788 = 0;
  *(undefined8 *)(iVar5 + 0xe8) = 0;
  *(undefined1 *)(iVar5 + 0xf4) = 1;
  uStack_2770 = 0;
  *(undefined8 *)(iVar5 + 0x100) = 0;
  *(undefined1 *)(iVar5 + 0x10c) = 1;
  uStack_2760 = 0;
  *(undefined8 *)(iVar5 + 0x110) = 0;
  *(undefined1 *)(iVar5 + 0x11c) = 1;
  iStack_28ac = 0;
  uVar9 = 0;
  if (*param_1 == 0) {
LAB_0001a30a:
    aiStack_2890[0] = 0;
    aiStack_2890[1] = 0;
    stack0xffffd778 = 0;
    uStack_2883 = 0;
    uStack_2880 = 0;
    uStack_287c = 0;
    piVar7 = *(int **)(this + 0x34);
    if (piVar7 == (int *)0x0) {
      piStack_2688 = &iStack_28ac;
      ppuStack_2690 = &PTR__AbstractUnwindCursor_1_00021938;
      pCStack_268c = (CacaoCaps *)auStack_2758;
      pfStack_2680 = (function<> *)&ppuStack_2690;
      (**(code **)(**(int **)(this + 0x30) + 0x54))
                (arStack_28a8,*(int **)(this + 0x30),uVar9,(function<> *)&ppuStack_2690);
      android::hardware::details::return_status::operator=
                ((return_status *)aiStack_2890,arStack_28a8);
      android::hardware::details::return_status::~return_status(arStack_28a8);
      std::function<>::~function((function<> *)&ppuStack_2690);
    }
    else {
      ppuStack_2678 = &PTR__AbstractUnwindCursor_1_00021914;
      piStack_266c = &iStack_28ac;
      iStack_2674 = iVar5;
      pCStack_2670 = (CacaoCaps *)auStack_2758;
      pfStack_2668 = (function<> *)&ppuStack_2678;
      (**(code **)(*piVar7 + 0x5c))(arStack_28a8,piVar7,uVar9,(function<> *)&ppuStack_2678);
      android::hardware::details::return_status::operator=
                ((return_status *)aiStack_2890,arStack_28a8);
      android::hardware::details::return_status::~return_status(arStack_28a8);
      std::function<>::~function((function<> *)&ppuStack_2678);
    }
    uStack_287c = 1;
    if (aiStack_2890[0] != 0) {
      android::hardware::Status::description();
      pvVar11 = pvStack_28a0;
      if (((byte)arStack_28a8[0] & 1) == 0) {
        pvVar11 = (void *)((uint)arStack_28a8 | 1);
      }
      __android_log_print(6,"CacaoService","Transaction error: %s",pvVar11);
      if (((byte)arStack_28a8[0] & 1) != 0) {
        operator_delete(pvStack_28a0);
      }
      iStack_28ac = -0x6f;
    }
    android::hardware::details::return_status::~return_status((return_status *)aiStack_2890);
    if (iStack_28ac < 0) {
LAB_0001a802:
      iVar5 = iStack_28ac;
      if (iStack_28ac != -0x6e) {
        iVar5 = -0x80000000;
      }
      if (-1 < iStack_28ac) {
        iVar5 = 0;
      }
      goto LAB_0001a458;
    }
    iVar5 = *(int *)(this + 0x34);
    if (iVar5 == 0) {
      uVar8 = uStack_2750;
      uVar1 = extraout_r3;
      if (uStack_2750 < 0x81) {
        uVar8 = uStack_2728;
        uVar1 = uStack_2728;
      }
      uVar2 = uStack_26d0;
      uVar3 = uStack_2700;
      if (uVar8 < 0x81) goto joined_r0x0001a626;
    }
    else {
      uVar8 = uStack_2750;
      uVar1 = extraout_r3;
      if (uStack_2750 < 0x81) {
        uVar8 = uStack_2728;
        uVar1 = uStack_2728;
      }
      if ((uVar8 < 0x81) && (uStack_2700 < 0x81)) {
        uVar2 = uStack_2780;
        uVar3 = uStack_26d0;
        if (uStack_26d0 < 0x81) {
          uVar3 = uStack_27a8;
        }
joined_r0x0001a626:
        if ((uVar3 < 0x81) && (uVar2 < 0x81)) {
          uStack_2654 = uStack_2750;
          uStack_2658 = auStack_2758[0];
          if (uStack_2750 != 0) {
            puVar10 = auStack_2650;
            puVar13 = (undefined4 *)((int)pvStack_2748 + 4);
            uVar8 = 0;
            puVar6 = auStack_2250;
            puVar12 = puStack_2738;
            do {
              uVar8 = uVar8 + 1;
              *puVar10 = puVar13[-1];
              uVar9 = *puVar13;
              puVar13 = puVar13 + 2;
              puVar10[1] = uVar9;
              puVar10 = puVar10 + 2;
              *puVar6 = *puVar12;
              puVar6 = puVar6 + 1;
              puVar12 = puVar12 + 1;
            } while (uVar8 != uStack_2750);
          }
          if (uVar1 != 0) {
            puVar10 = auStack_204c + 1;
            puVar13 = (undefined4 *)((int)pvStack_2720 + 4);
            uVar8 = 0;
            puVar6 = auStack_1c4c;
            puVar12 = puStack_2710;
            do {
              uVar8 = uVar8 + 1;
              puVar10[-1] = puVar13[-1];
              uVar9 = *puVar13;
              puVar13 = puVar13 + 2;
              *puVar10 = uVar9;
              puVar10 = puVar10 + 2;
              *puVar6 = *puVar12;
              puVar6 = puVar6 + 1;
              puVar12 = puVar12 + 1;
            } while (uVar8 != uVar1);
          }
          uStack_1a4c = uStack_2700;
          if (uStack_2700 != 0) {
            puVar10 = auStack_1a48 + 1;
            puVar13 = (undefined4 *)((int)pvStack_26f8 + 4);
            uVar8 = 0;
            puVar6 = auStack_1648;
            puVar12 = puStack_26e8;
            do {
              uVar8 = uVar8 + 1;
              *puVar6 = *puVar12;
              puVar10[-1] = puVar13[-1];
              uVar9 = *puVar13;
              puVar13 = puVar13 + 2;
              *puVar10 = uVar9;
              puVar10 = puVar10 + 2;
              puVar6 = puVar6 + 1;
              puVar12 = puVar12 + 1;
            } while (uVar8 != uStack_2700);
          }
          uStack_1444 = uStack_26d0;
          uStack_1448 = uStack_26d8;
          if (uStack_26d0 != 0) {
            puVar13 = auStack_1440;
            puVar14 = auStack_1040;
            puVar10 = (undefined4 *)((int)pvStack_26c8 + 4);
            uVar8 = 0;
            puVar6 = puStack_26a8;
            puVar12 = puStack_26b8;
            do {
              uVar8 = uVar8 + 1;
              *puVar13 = puVar10[-1];
              uVar9 = *puVar10;
              puVar10 = puVar10 + 2;
              puVar13[1] = uVar9;
              puVar13 = puVar13 + 2;
              *puVar14 = *puVar12;
              puVar14[0x80] = *puVar6;
              puVar14 = puVar14 + 1;
              puVar6 = puVar6 + 1;
              puVar12 = puVar12 + 1;
            } while (uVar8 != uStack_26d0);
          }
          uStack_c40 = uStack_2698;
          uStack_c3c = uStack_2694;
          if (iVar5 == 0) {
            uStack_c34 = 0;
            uStack_c38 = 0;
            uStack_630 = 0;
          }
          else {
            uStack_c38 = uStack_27b0;
            uStack_c34 = uStack_27a8;
            if (uStack_27a8 != 0) {
              uVar8 = 0;
              puVar10 = auStack_c30 + 1;
              puVar13 = (undefined4 *)((int)pvStack_27a0 + 4);
              puVar6 = auStack_830;
              puVar12 = puStack_2790;
              do {
                uVar8 = uVar8 + 1;
                puVar10[-1] = puVar13[-1];
                uVar9 = *puVar13;
                puVar13 = puVar13 + 2;
                *puVar10 = uVar9;
                puVar10 = puVar10 + 2;
                *puVar6 = *puVar12;
                puVar6 = puVar6 + 1;
                puVar12 = puVar12 + 1;
              } while (uVar8 != uStack_27a8);
            }
            uStack_630 = uStack_2780;
            if (uStack_2780 != 0) {
              uVar8 = 0;
              puVar10 = auStack_62c + 1;
              puVar13 = (undefined4 *)((int)pvStack_2778 + 4);
              puVar6 = auStack_22c;
              puVar12 = puStack_2768;
              do {
                uVar8 = uVar8 + 1;
                puVar10[-1] = puVar13[-1];
                uVar9 = *puVar13;
                puVar13 = puVar13 + 2;
                *puVar10 = uVar9;
                puVar10 = puVar10 + 2;
                *puVar6 = *puVar12;
                puVar6 = puVar6 + 1;
                puVar12 = puVar12 + 1;
              } while (uVar8 != uStack_2780);
            }
          }
          iStack_28ac = cacao::Caps::serialize((Caps *)&ppuStack_2660,(int)&uStack_4);
          goto LAB_0001a802;
        }
      }
    }
    __android_log_print(6,"CacaoService","Max support item over.");
    iStack_28ac = -0x6f;
  }
  else {
    if (*param_1 == 1) {
      uVar9 = 1;
      goto LAB_0001a30a;
    }
    __android_log_print(6,"CacaoService","Invalid camera index");
    iStack_28ac = -0x67;
  }
  iVar5 = -0x80000000;
LAB_0001a458:
  if ((uStack_2760._4_1_ != '\0') && (puStack_2768 != (undefined4 *)0x0)) {
    operator_delete__(puStack_2768);
  }
  puStack_2768 = (undefined4 *)0x0;
  if ((uStack_2770._4_1_ != '\0') && (pvStack_2778 != (void *)0x0)) {
    operator_delete__(pvStack_2778);
  }
  pvStack_2778 = (void *)0x0;
  if ((uStack_2788._4_1_ != '\0') && (puStack_2790 != (undefined4 *)0x0)) {
    operator_delete__(puStack_2790);
  }
  puStack_2790 = (undefined4 *)0x0;
  if ((uStack_2798._4_1_ != '\0') && (pvStack_27a0 != (void *)0x0)) {
    operator_delete__(pvStack_27a0);
  }
  pvStack_27a0 = (void *)0x0;
  if ((cStack_27bc != '\0') && (pvStack_27c8 != (void *)0x0)) {
    operator_delete__(pvStack_27c8);
  }
  pvStack_27c8 = (void *)0x0;
  if ((cStack_27cc != '\0') && (pvStack_27d8 != (void *)0x0)) {
    operator_delete__(pvStack_27d8);
  }
  pvStack_27d8 = (void *)0x0;
  if ((cStack_27dc != '\0') && (pvStack_27e8 != (void *)0x0)) {
    operator_delete__(pvStack_27e8);
  }
  pvStack_27e8 = (void *)0x0;
  if ((cStack_27fc != '\0') && (pvStack_2808 != (void *)0x0)) {
    operator_delete__(pvStack_2808);
  }
  pvStack_2808 = (void *)0x0;
  if ((cStack_280c != '\0') && (pvStack_2818 != (void *)0x0)) {
    operator_delete__(pvStack_2818);
  }
  pvStack_2818 = (void *)0x0;
  if ((cStack_2824 != '\0') && (pvStack_2830 != (void *)0x0)) {
    operator_delete__(pvStack_2830);
  }
  pvStack_2830 = (void *)0x0;
  if ((cStack_2834 != '\0') && (pvStack_2840 != (void *)0x0)) {
    operator_delete__(pvStack_2840);
  }
  pvStack_2840 = (void *)0x0;
  if ((cStack_284c != '\0') && (pvStack_2858 != (void *)0x0)) {
    operator_delete__(pvStack_2858);
  }
  pvStack_2858 = (void *)0x0;
  if ((cStack_285c != '\0') && (pvStack_2868 != (void *)0x0)) {
    operator_delete__(pvStack_2868);
  }
  if ((cStack_269c != '\0') && (puStack_26a8 != (undefined4 *)0x0)) {
    operator_delete__(puStack_26a8);
  }
  puStack_26a8 = (undefined4 *)0x0;
  if ((cStack_26ac != '\0') && (puStack_26b8 != (undefined4 *)0x0)) {
    operator_delete__(puStack_26b8);
  }
  puStack_26b8 = (undefined4 *)0x0;
  if ((cStack_26bc != '\0') && (pvStack_26c8 != (void *)0x0)) {
    operator_delete__(pvStack_26c8);
  }
  pvStack_26c8 = (void *)0x0;
  if ((cStack_26dc != '\0') && (puStack_26e8 != (undefined4 *)0x0)) {
    operator_delete__(puStack_26e8);
  }
  puStack_26e8 = (undefined4 *)0x0;
  if ((cStack_26ec != '\0') && (pvStack_26f8 != (void *)0x0)) {
    operator_delete__(pvStack_26f8);
  }
  pvStack_26f8 = (void *)0x0;
  if ((cStack_2704 != '\0') && (puStack_2710 != (undefined4 *)0x0)) {
    operator_delete__(puStack_2710);
  }
  puStack_2710 = (undefined4 *)0x0;
  if ((cStack_2714 != '\0') && (pvStack_2720 != (void *)0x0)) {
    operator_delete__(pvStack_2720);
  }
  pvStack_2720 = (void *)0x0;
  if ((cStack_272c != '\0') && (puStack_2738 != (undefined4 *)0x0)) {
    operator_delete__(puStack_2738);
  }
  puStack_2738 = (undefined4 *)0x0;
  if ((cStack_273c != '\0') && (pvStack_2748 != (void *)0x0)) {
    operator_delete__(pvStack_2748);
  }
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&ppuStack_2660);
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x14));
  if (__stack_chk_guard == iVar4) {
    return iVar5;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

undefined4 __cdecl
android::CacaoService::getJpegBufferSize(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  return_status arStack_70 [8];
  void *pvStack_68;
  int aiStack_58 [3];
  undefined3 uStack_4b;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined **ppuStack_40;
  undefined4 *puStack_3c;
  undefined4 *puStack_38;
  function<> *pfStack_30;
  int iStack_24;
  
  iStack_24 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x14));
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  aiStack_58[0] = 0;
  aiStack_58[1] = 0;
  stack0xffffffb0 = 0;
  uStack_4b = 0;
  puStack_38 = &uStack_74;
  puStack_3c = &uStack_78;
  ppuStack_40 = &PTR__AbstractUnwindCursor_1_0002195c;
  uStack_80 = param_2;
  uStack_7c = param_3;
  pfStack_30 = (function<> *)&ppuStack_40;
  (**(code **)(**(int **)(param_1 + 0x30) + 0x58))
            (arStack_70,*(int **)(param_1 + 0x30),&uStack_80,(function<> *)&ppuStack_40);
  android::hardware::details::return_status::operator=((return_status *)aiStack_58,arStack_70);
  android::hardware::details::return_status::~return_status(arStack_70);
  std::function<>::~function((function<> *)&ppuStack_40);
  uStack_44 = 1;
  if (aiStack_58[0] != 0) {
    android::hardware::Status::description();
    pvVar2 = pvStack_68;
    if (((byte)arStack_70[0] & 1) == 0) {
      pvVar2 = (void *)((uint)arStack_70 | 1);
    }
    __android_log_print(6,"CacaoService","Transaction error: %s",pvVar2);
    if (((byte)arStack_70[0] & 1) != 0) {
      operator_delete(pvStack_68);
    }
    uStack_74 = 0xffffff91;
  }
  android::hardware::details::return_status::~return_status((return_status *)aiStack_58);
  uVar1 = uStack_78;
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x14));
  if (__stack_chk_guard != iStack_24) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return uVar1;
}



void __thiscall android::CacaoService::registerClient(CacaoService *this,int *param_1)

{
  code *pcVar1;
  sp<> asStack_38 [4];
  int *piStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  iStack_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  if (*param_1 != 0) {
    iStack_30 = *(int *)(this + 0x20);
    List<>::insert(&iStack_2c,this + 0x1c,&iStack_30,param_1);
    (**(code **)(*(int *)*param_1 + 0x44))(&iStack_30);
    iStack_2c = iStack_30;
    iStack_30 = 0;
    android::IInterface::asBinder((sp *)&piStack_34);
    pcVar1 = *(code **)(*piStack_34 + 0x18);
    sp<>::sp<>(asStack_38,(int *)this);
    (*pcVar1)(piStack_34,asStack_38,0,0);
    sp<>::~sp((sp<> *)asStack_38);
    sp<>::~sp((sp<> *)&piStack_34);
    sp<>::~sp((sp<> *)&iStack_2c);
    sp<>::~sp((sp<> *)&iStack_30);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  if (__stack_chk_guard != iStack_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void __thiscall android::CacaoService::unregisterClient(CacaoService *this,int *param_1)

{
  int iVar1;
  sp<> *psVar2;
  int *piVar3;
  sp<> *this_00;
  code *pcVar4;
  int iVar5;
  sp<> *psStack_40;
  int iStack_3c;
  undefined4 auStack_38 [2];
  undefined4 uStack_30;
  int iStack_2c;
  int iStack_28;
  
  iStack_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  psVar2 = *(sp<> **)(this + 0x20);
  this_00 = *(sp<> **)(psVar2 + 8);
  if (psVar2 != this_00) {
    do {
      if (*(int **)this_00 != (int *)0x0) {
        (**(code **)(**(int **)this_00 + 0x44))((sp<> *)&uStack_30);
        auStack_38[0] = uStack_30;
        uStack_30 = 0;
        android::IInterface::asBinder((sp *)&iStack_2c);
        iVar1 = iStack_2c;
        iVar5 = *param_1;
        sp<>::~sp((sp<> *)&iStack_2c);
        sp<>::~sp((sp<> *)auStack_38);
        sp<>::~sp((sp<> *)&uStack_30);
        if (iVar1 == iVar5) {
          piVar3 = (int *)*param_1;
          pcVar4 = *(code **)(*piVar3 + 0x1c);
          wp<>::wp<>((wp<> *)auStack_38,(int *)this);
          (*pcVar4)(piVar3,(wp<> *)auStack_38,0,0,0);
          wp<>::~wp((wp<> *)auStack_38);
          sp<>::clear(this_00);
          psStack_40 = this_00;
          List<>::erase(&iStack_3c,this + 0x1c,(int *)&psStack_40);
          break;
        }
        psVar2 = *(sp<> **)(this + 0x20);
      }
      this_00 = *(sp<> **)(this_00 + 8);
    } while (psVar2 != this_00);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  if (__stack_chk_guard != iStack_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::CacaoService::onRegistration(undefined8 *param_1,CacaoService *param_2)

{
  getInterfaces(param_2);
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined8 *)((int)param_1 + 0xd) = 0;
  return;
}



void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  return;
}



undefined4 android::hidl::manager::V1_0::IServiceNotification::isRemote(void)

{
  return 0;
}



undefined4 android::hidl::manager::V1_0::IServiceNotification::isRemote(void)

{
  return 0;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + -4,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x34));
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + -4);
  return;
}



void __thiscall android::CacaoService::onTransact(CacaoService *this)

{
  Parcel *in_r1;
  Parcel *in_r2;
  uint in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



void __thiscall android::CacaoService::binderDied(CacaoService *this)

{
  int *in_r1;
  
  binderDied((int *)(this + -0x10),in_r1);
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + -0x10,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x28));
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + -0x10);
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  int iVar1;
  
  iVar1 = ~CacaoService(this + *(int *)(*(int *)this + -0xc),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x38));
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + *(int *)(*(int *)this + -0xc));
  return;
}



void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  return;
}



void android::hidl::manager::V1_0::IServiceNotification::interfaceChain(void)

{
  interfaceChain();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::manager::V1_0::IServiceNotification::debug
               (hidl_handle *param_1,hidl_vec *param_2)

{
  debug(param_1,param_2);
  return;
}



void android::hidl::manager::V1_0::IServiceNotification::interfaceDescriptor(void)

{
  interfaceDescriptor();
  return;
}



void android::hidl::manager::V1_0::IServiceNotification::getHashChain(void)

{
  getHashChain();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::manager::V1_0::IServiceNotification::setHALInstrumentation(void)

{
  setHALInstrumentation();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::manager::V1_0::IServiceNotification::linkToDeath(sp *param_1,ulonglong param_2)

{
  linkToDeath(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::manager::V1_0::IServiceNotification::ping(void)

{
  ping();
  return;
}



void android::hidl::manager::V1_0::IServiceNotification::getDebugInfo(void)

{
  getDebugInfo();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::manager::V1_0::IServiceNotification::notifySyspropsChanged(void)

{
  notifySyspropsChanged();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::manager::V1_0::IServiceNotification::unlinkToDeath(sp *param_1)

{
  unlinkToDeath(param_1);
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  int iVar1;
  
  iVar1 = ~CacaoService(this + *(int *)(*(int *)this + -0x3c),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x38));
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + *(int *)(*(int *)this + -0x3c));
  return;
}



void __thiscall android::CacaoService::onRegistration(CacaoService *this,int *param_1)

{
  getInterfaces((CacaoService *)(*(int *)(*param_1 + -0x40) + (int)param_1));
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0xd) = 0;
  return;
}



void __thiscall
android::CacaoService::serviceDied(CacaoService *this,undefined4 param_1,int param_2,int param_3)

{
  serviceDied((int)(this + *(int *)(*(int *)this + -0x10)),*(int *)(*(int *)this + -0x10),param_2,
              param_3);
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  int iVar1;
  
  iVar1 = ~CacaoService(this + *(int *)(*(int *)this + -0x14),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x38));
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + *(int *)(*(int *)this + -0x14));
  return;
}



void __cxa_pure_virtual(void)

{
  __cxa_pure_virtual();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BBinder::onTransact(uint param_1,Parcel *param_2,Parcel *param_3,uint param_4)

{
  onTransact(param_1,param_2,param_3,param_4);
  return;
}



void __thiscall android::ICacao::~ICacao(ICacao *this)

{
  ~ICacao(this);
  return;
}



void __thiscall android::ICacao::~ICacao(ICacao *this)

{
  ~ICacao(this);
  return;
}



void android::ICacao::~ICacao(void)

{
  ~ICacao();
  return;
}



void android::ICacao::~ICacao(void)

{
  ~ICacao();
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



void android::BnCacaoService::onTransact(void)

{
  onTransact();
  return;
}



void __thiscall android::ICacaoService::~ICacaoService(ICacaoService *this)

{
  ~ICacaoService(this);
  return;
}



void __thiscall android::ICacaoService::~ICacaoService(ICacaoService *this)

{
  ~ICacaoService(this);
  return;
}



void android::ICacaoService::~ICacaoService(void)

{
  ~ICacaoService();
  return;
}



void android::ICacaoService::~ICacaoService(void)

{
  ~ICacaoService();
  return;
}



void android::hidl::base::V1_0::IBase::interfaceChain(void)

{
  interfaceChain();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::base::V1_0::IBase::debug(hidl_handle *param_1,hidl_vec *param_2)

{
  debug(param_1,param_2);
  return;
}



void android::hidl::base::V1_0::IBase::interfaceDescriptor(void)

{
  interfaceDescriptor();
  return;
}



void android::hidl::base::V1_0::IBase::getHashChain(void)

{
  getHashChain();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::base::V1_0::IBase::setHALInstrumentation(void)

{
  setHALInstrumentation();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::base::V1_0::IBase::linkToDeath(sp *param_1,ulonglong param_2)

{
  linkToDeath(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::base::V1_0::IBase::ping(void)

{
  ping();
  return;
}



void android::hidl::base::V1_0::IBase::getDebugInfo(void)

{
  getDebugInfo();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::base::V1_0::IBase::notifySyspropsChanged(void)

{
  notifySyspropsChanged();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hidl::base::V1_0::IBase::unlinkToDeath(sp *param_1)

{
  unlinkToDeath(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ObjectBase::dump(uint param_1)

{
  dump(param_1);
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

void cacao::ProcessCtrlGatewayFactory::create(void)

{
  create();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createMode(SerializedData *param_1)

{
  createMode(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createParam(SerializedData *param_1)

{
  createParam(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createResult(SerializedData *param_1)

{
  createResult(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createConfig(uint param_1,SerializedData *param_2)

{
  createConfig(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createParam(sp *param_1,SerializedData *param_2)

{
  createParam(param_1,param_2);
  return;
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



void __on_dlclose(void)

{
  __cxa_finalize(&DAT_00022000);
  return;
}



void __atexit_handler_wrapper(undefined *UNRECOVERED_JUMPTABLE)

{
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
                    // WARNING: Could not recover jumptable at 0x000189da. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}



int atexit(__func *__func)

{
  int iVar1;
  
  iVar1 = __cxa_atexit(0x189d9,__func,&DAT_00022000);
  return iVar1;
}



int pthread_atfork(__prepare *__prepare,__parent *__parent,__child *__child)

{
  int iVar1;
  
  iVar1 = __register_atfork(__prepare,__parent,__child,&DAT_00022000);
  return iVar1;
}



// android::CacaoService::Client::Request::Request(android::sp<android::ICacaoProcessCallback>
// const&, cacao::ICBProcessResultListener*)

Request * __thiscall
android::CacaoService::Client::Request::Request(Request *this,int *param_1,undefined4 param_2)

{
  *(undefined ***)this = &PTR__Request_00020c48;
  sp<>::sp((sp<> *)(this + 4),param_1);
  *(undefined4 *)(this + 8) = param_2;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return this;
}



// android::sp<android::CacaoService::Client>::sp(android::sp<android::CacaoService::Client> const&)

sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    android::RefBase::incStrong((void *)((int)piVar1 + *(int *)(*piVar1 + -0xc)));
  }
  return this;
}



// android::CacaoService::Client::Request::~Request()

Request * __thiscall android::CacaoService::Client::Request::~Request(Request *this)

{
  *(undefined ***)this = &PTR__Request_00020c48;
  sp<>::clear((sp<> *)(this + 4));
  if (*(int **)(this + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xc) + 4))();
  }
  if (*(int **)(this + 0x10) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x10) + 4))();
  }
  sp<>::~sp((sp<> *)(this + 4));
  return this;
}



// android::sp<android::ICacaoProcessCallback>::clear()

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



// android::sp<android::IMemoryHeap>::~sp()

sp<> * __thiscall android::sp<>::~sp(sp<> *this)

{
  int *piVar1;
  
  piVar1 = *(int **)this;
  if (piVar1 != (int *)0x0) {
    android::RefBase::decStrong((void *)((int)piVar1 + *(int *)(*piVar1 + -0xc)));
  }
  return this;
}



// android::CacaoService::Client::Request::~Request()

void __thiscall android::CacaoService::Client::Request::~Request(Request *this)

{
  Request *pRVar1;
  
  pRVar1 = ~Request(this);
  operator_delete(pRVar1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::Client::Request::onHandleProgress(cacao::ProcessResultBase const*)

void __cdecl android::CacaoService::Client::Request::onHandleProgress(int param_1)

{
  if (*(int **)(param_1 + 8) != (int *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00018ad0. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(**(int **)(param_1 + 8) + 8))();
    return;
  }
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::Client::Request::onHandleResult(cacao::ProcessResultBase const*)

void __cdecl android::CacaoService::Client::Request::onHandleResult(int param_1)

{
  if (*(int **)(param_1 + 8) != (int *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00018adc. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(**(int **)(param_1 + 8) + 0xc))();
    return;
  }
  return;
}



// android::CacaoService::Client::Request::setBufVector(android::Vector<cacao::ImageBuf*>*)

void __thiscall
android::CacaoService::Client::Request::setBufVector(Request *this,undefined4 param_1)

{
  *(undefined4 *)(this + 0xc) = param_1;
  return;
}



// android::CacaoService::Client::Request::setResult(cacao::ProcessResultBase*)

void __thiscall android::CacaoService::Client::Request::setResult(Request *this,undefined4 param_1)

{
  *(undefined4 *)(this + 0x10) = param_1;
  return;
}



// android::CacaoService::Client::Client(android::sp<android::CacaoService> const&,
// android::sp<android::ICacaoClient> const&, int)

Client * __thiscall
android::CacaoService::Client::Client
          (Client *this,int *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  Client *pCVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  
  android::ICacao::ICacao((ICacao *)this);
  android::BBinder::BBinder((BBinder *)(this + 4));
  iVar2 = param_1[2];
  *(int *)this = iVar2;
  *(int *)(this + *(int *)(iVar2 + -0xc)) = param_1[0xb];
  *(int *)(this + 4) = param_1[0xc];
  iVar2 = param_1[1];
  *(int *)this = iVar2;
  *(int *)(this + *(int *)(iVar2 + -0xc)) = param_1[0xd];
  iVar2 = param_1[0xe];
  *(undefined ***)(this + 0x14) = &PTR__AbstractUnwindCursor_1_0002183c;
  *(int *)(this + 4) = iVar2;
  pCVar1 = this + 0x10;
  *(undefined ***)pCVar1 = &PTR__AbstractUnwindCursor_1_00021854;
  iVar2 = *param_1;
  *(int *)this = iVar2;
  *(int *)(this + *(int *)(iVar2 + -0xc)) = param_1[0xf];
  iVar2 = param_1[0x10];
  *(undefined4 *)pCVar1 = 0x20d18;
  *(undefined4 *)(this + 0x14) = 0x20d2c;
  *(int *)(this + 4) = iVar2;
  pthread_mutex_init((pthread_mutex_t *)(this + 0x18),(pthread_mutexattr_t *)0x0);
  pthread_mutex_init((pthread_mutex_t *)(this + 0x1c),(pthread_mutexattr_t *)0x0);
  pthread_mutex_init((pthread_mutex_t *)(this + 0x20),(pthread_mutexattr_t *)0x0);
  sp<>::sp((sp<> *)(this + 0x24),param_2);
  sp<>::sp((sp<> *)(this + 0x28),param_3);
  this[0x34] = (Client)0x0;
  *(undefined4 *)(this + 0x2c) = param_4;
  *(undefined ***)(this + 0x38) = &PTR__List_1_000218a8;
  pvVar3 = operator_new__(0xc);
  *(void **)(this + 0x3c) = pvVar3;
  *(void **)((int)pvVar3 + 4) = pvVar3;
  *(void **)((int)pvVar3 + 8) = pvVar3;
  __android_log_print(3,"CacaoService","client create - pid:%d",param_4);
  piVar4 = (int *)cacao::ProcessFactoryInternal::createProcess();
  *(int **)(this + 0x30) = piVar4;
  if (piVar4 == (int *)0x0) {
    __android_log_print(6,"CacaoService","client create - create process failed");
  }
  else {
    (**(code **)(*piVar4 + 8))(piVar4,pCVar1,0);
  }
  return this;
}



// android::CacaoService::Client::Client(android::sp<android::CacaoService> const&,
// android::sp<android::ICacaoClient> const&, int)

Client * __thiscall
android::CacaoService::Client::Client(Client *this,int *param_1,int *param_2,undefined4 param_3)

{
  void *pvVar1;
  int *piVar2;
  
  android::RefBase::RefBase((RefBase *)(this + 0x40));
  android::ICacao::ICacao((ICacao *)this);
  android::BBinder::BBinder((BBinder *)(this + 4));
  *(undefined4 *)(this + 0x40) = 0x20d58;
  *(undefined4 *)this = 0x20c78;
  *(undefined4 *)(this + 4) = 0x20ccc;
  *(undefined4 *)(this + 0x14) = 0x20d2c;
  *(undefined4 *)(this + 0x10) = 0x20d18;
  pthread_mutex_init((pthread_mutex_t *)(this + 0x18),(pthread_mutexattr_t *)0x0);
  pthread_mutex_init((pthread_mutex_t *)(this + 0x1c),(pthread_mutexattr_t *)0x0);
  pthread_mutex_init((pthread_mutex_t *)(this + 0x20),(pthread_mutexattr_t *)0x0);
  sp<>::sp((sp<> *)(this + 0x24),param_1);
  sp<>::sp((sp<> *)(this + 0x28),param_2);
  this[0x34] = (Client)0x0;
  *(undefined4 *)(this + 0x2c) = param_3;
  *(undefined ***)(this + 0x38) = &PTR__List_1_000218a8;
  pvVar1 = operator_new__(0xc);
  *(void **)(this + 0x3c) = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(void **)((int)pvVar1 + 8) = pvVar1;
  __android_log_print(3,"CacaoService","client create - pid:%d",param_3);
  piVar2 = (int *)cacao::ProcessFactoryInternal::createProcess();
  *(int **)(this + 0x30) = piVar2;
  if (piVar2 == (int *)0x0) {
    __android_log_print(6,"CacaoService","client create - create process failed");
  }
  else {
    (**(code **)(*piVar2 + 8))(piVar2,this + 0x10,0);
  }
  return this;
}



// android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0xf];
  iVar1 = param_1[0x10];
  *(undefined4 *)(this + 0x10) = 0x20d18;
  *(undefined4 *)(this + 0x14) = 0x20d2c;
  *(int *)(this + 4) = iVar1;
  __android_log_print(3,"CacaoService","client delete - pid:%d",*(undefined4 *)(this + 0x2c));
  this[0x34] = (Client)0x1;
  (**(code **)(*(int *)this + 0x10))(this);
  List<>::~List((List<> *)(this + 0x38));
  sp<>::~sp((sp<> *)(this + 0x28));
  sp<>::~sp((sp<> *)(this + 0x24));
  pthread_mutex_destroy((pthread_mutex_t *)(this + 0x20));
  pthread_mutex_destroy((pthread_mutex_t *)(this + 0x1c));
  pthread_mutex_destroy((pthread_mutex_t *)(this + 0x18));
  android::BBinder::~BBinder((BBinder *)(this + 4));
  android::ICacao::~ICacao((ICacao *)this);
  return;
}



// android::List<android::CacaoService::Client::Request*>::~List()

List<> * __thiscall android::List<>::~List(List<> *this)

{
  *(undefined ***)this = &PTR__List_1_000218a8;
  clear(this);
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  return this;
}



// android::CacaoService::Client::~Client()

Client * __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x40));
  return this;
}



// non-virtual thunk to android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -4,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x3c));
  return;
}



// non-virtual thunk to android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -0x10,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x30));
  return;
}



// non-virtual thunk to android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -0x14,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x2c));
  return;
}



// virtual thunk to android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  int iVar1;
  
  iVar1 = ~Client(this + *(int *)(*(int *)this + -0xc),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x40));
  return;
}



// android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x40));
  operator_delete(this);
  return;
}



// non-virtual thunk to android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -4);
  return;
}



// non-virtual thunk to android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -0x10);
  return;
}



// non-virtual thunk to android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + -0x14);
  return;
}



// virtual thunk to android::CacaoService::Client::~Client()

void __thiscall android::CacaoService::Client::~Client(Client *this)

{
  ~Client(this + *(int *)(*(int *)this + -0xc));
  return;
}



// android::CacaoService::Client::disconnect()

void __thiscall android::CacaoService::Client::disconnect(Client *this)

{
  int iVar1;
  __pid_t _Var2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  sp<> asStack_30 [4];
  sp asStack_2c [4];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  android::IPCThreadState::self();
  iVar1 = android::IPCThreadState::getCallingPid();
  if (iVar1 != *(int *)(this + 0x2c)) {
    android::IPCThreadState::self();
    iVar1 = android::IPCThreadState::getCallingPid();
    _Var2 = getpid();
    if (iVar1 != _Var2) goto LAB_00018f84;
  }
  if (*(int **)(this + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x30) + 4))();
  }
  *(undefined4 *)(this + 0x30) = 0;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x20));
  while (piVar4 = (int *)(*(int **)(this + 0x3c))[2], piVar4 != *(int **)(this + 0x3c)) {
    if ((int *)*piVar4 != (int *)0x0) {
      (**(code **)(*(int *)*piVar4 + 4))();
    }
    iVar1 = piVar4[1];
    iVar3 = piVar4[2];
    *(int *)(iVar1 + 8) = iVar3;
    *(int *)(iVar3 + 4) = iVar1;
    if (piVar4 != (int *)0x0) {
      operator_delete(piVar4);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x20));
  if (this[0x34] == (Client)0x0) {
    pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
    piVar4 = *(int **)(this + 0x24);
    pcVar5 = *(code **)(*piVar4 + 0x2c);
    sp<>::sp(asStack_30,(int *)(this + 0x28));
    android::IInterface::asBinder(asStack_2c);
    (*pcVar5)(piVar4,asStack_2c);
    sp<>::~sp((sp<> *)asStack_2c);
    sp<>::~sp((sp<> *)asStack_30);
    sp<>::clear((sp<> *)(this + 0x28));
    pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  }
LAB_00018f84:
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::CacaoService::getClientPid()

void android::CacaoService::getClientPid(void)

{
  android::IPCThreadState::self();
  android::IPCThreadState::getCallingPid();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::Client::start(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData)

int __cdecl
android::CacaoService::Client::start
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_8 = param_3;
  uStack_4 = param_4;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x18));
  if ((*(int *)(param_1 + 0x30) == 0) ||
     (piVar1 = (int *)cacao::ProcessFactoryInternal::createMode((SerializedData *)&local_8),
     piVar1 == (int *)0x0)) {
    iVar3 = -0x80000000;
  }
  else {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x30) + 0xc))(*(int **)(param_1 + 0x30),piVar1);
    (**(code **)(*piVar1 + 4))(piVar1);
    iVar3 = iVar2;
    if (iVar2 != -0x6e) {
      iVar3 = -0x80000000;
    }
    if (-1 < iVar2) {
      iVar3 = 0;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x18));
  return iVar3;
}



// android::CacaoService::Client::stop()

int __thiscall android::CacaoService::Client::stop(Client *this)

{
  int iVar1;
  int iVar2;
  
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  if (*(int **)(this + 0x30) == (int *)0x0) {
    iVar2 = -0x80000000;
  }
  else {
    iVar1 = (**(code **)(**(int **)(this + 0x30) + 0x10))();
    iVar2 = iVar1;
    if (iVar1 != -0x6e) {
      iVar2 = -0x80000000;
    }
    if (-1 < iVar1) {
      iVar2 = 0;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  return iVar2;
}



// android::CacaoService::Client::setConfig(int, android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData)

int __thiscall
android::CacaoService::Client::setConfig
          (Client *this,uint param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_4;
  
  local_4 = param_3;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  if ((*(int *)(this + 0x30) == 0) ||
     (piVar1 = (int *)cacao::ProcessFactoryInternal::createConfig
                                (param_1,(SerializedData *)&local_4), piVar1 == (int *)0x0)) {
    iVar3 = -0x80000000;
  }
  else {
    iVar2 = (**(code **)(**(int **)(this + 0x30) + 0x14))(*(int **)(this + 0x30),piVar1);
    (**(code **)(*piVar1 + 4))(piVar1);
    iVar3 = iVar2;
    if (iVar2 != -0x6e) {
      iVar3 = -0x80000000;
    }
    if (-1 < iVar2) {
      iVar3 = 0;
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  return iVar3;
}



// android::CacaoService::Client::getConfig(int, android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData)

int __thiscall
android::CacaoService::Client::getConfig
          (Client *this,uint param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_4;
  
  local_4 = param_3;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  if (*(int *)(this + 0x30) != 0) {
    piVar1 = (int *)cacao::ProcessFactoryInternal::createConfig(param_1,(SerializedData *)&local_4);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(**(int **)(this + 0x30) + 0x18))(*(int **)(this + 0x30),piVar1);
      if (-1 < iVar2) {
        iVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,&local_4);
      }
      (**(code **)(*piVar1 + 4))(piVar1);
      iVar3 = iVar2;
      if (iVar2 != -0x6e) {
        iVar3 = -0x80000000;
      }
      if (-1 < iVar2) {
        iVar3 = 0;
      }
      goto LAB_00019116;
    }
  }
  iVar3 = -0x80000000;
LAB_00019116:
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  return iVar3;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::Client::process(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData, android::Vector<cacao::ImageBuf*>,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData, int,
// android::sp<android::ICacaoProcessCallback> const&)

undefined4 __cdecl
android::CacaoService::Client::process
          (int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  VectorImpl *this;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int in_stack_0000018c;
  int in_stack_00000328;
  int *in_stack_0000032c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_8 = param_3;
  uStack_4 = param_4;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x18));
  if (*(int *)(param_1 + 0x30) == 0) {
LAB_00019158:
    uVar7 = 0;
  }
  else {
    if (*param_2 == 0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)cacao::ProcessFactoryInternal::createParam((SerializedData *)&local_8);
      if (piVar1 == (int *)0x0) goto LAB_00019158;
    }
    iVar2 = cacao::ProcessFactoryInternal::createResult(&stack0x00000194);
    if (iVar2 == 0) {
      uVar7 = 0;
    }
    else {
      if (*(int *)(in_stack_0000018c + 8) == 0) {
        this = (VectorImpl *)0x0;
      }
      else {
        this = operator_new(0x14);
        android::VectorImpl::VectorImpl(this,4,7);
        *(undefined ***)this = &PTR__Vector_1_000218b8;
        if (*(int *)(in_stack_0000018c + 8) != 0) {
          iVar8 = 0;
          uVar6 = 0;
          do {
            android::VectorImpl::insertAt
                      (this,*(int *)(in_stack_0000018c + 4) + iVar8,*(uint *)(this + 8));
            uVar6 = uVar6 + 1;
            iVar8 = iVar8 + 4;
          } while (uVar6 < *(uint *)(in_stack_0000018c + 8));
        }
      }
      piVar3 = operator_new(0x14);
      *piVar3 = (int)&PTR__Request_00020c48;
      sp<>::sp((sp<> *)(piVar3 + 1),in_stack_0000032c);
      piVar3[2] = param_1 + 0x14;
      piVar3[3] = 0;
      piVar3[4] = 0;
      (**(code **)(*piVar3 + 0x18))(piVar3,iVar2);
      (**(code **)(*piVar3 + 0x10))(piVar3,this);
      pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x20));
      iVar8 = *(int *)(param_1 + 0x3c);
      puVar4 = operator_new(0xc);
      *puVar4 = piVar3;
      puVar4[2] = iVar8;
      puVar4[1] = *(undefined4 *)(iVar8 + 4);
      *(undefined4 **)(*(int *)(iVar8 + 4) + 8) = puVar4;
      *(undefined4 **)(iVar8 + 4) = puVar4;
      pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x20));
      piVar5 = *(int **)(param_1 + 0x30);
      if (in_stack_00000328 == 0) {
        uVar7 = (**(code **)(*piVar5 + 0x20))(piVar5,piVar1,this,piVar3,iVar2);
      }
      else {
        uVar7 = (**(code **)(*piVar5 + 0x1c))(piVar5,piVar1,piVar3,iVar2);
      }
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x18));
  return uVar7;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::Client::process(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData, android::sp<android::IBinder> const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData, int,
// android::sp<android::ICacaoProcessCallback> const&)

undefined4 __cdecl
android::CacaoService::Client::process
          (int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  code *pcVar9;
  sp *in_stack_0000018c;
  int in_stack_00000328;
  int *in_stack_0000032c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_8 = param_3;
  uStack_4 = param_4;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x18));
  if (*(int *)(param_1 + 0x30) == 0) {
LAB_000192aa:
    uVar8 = 0;
  }
  else {
    if (*param_2 == 0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)cacao::ProcessFactoryInternal::createParam
                                (in_stack_0000018c,(SerializedData *)&local_8);
      if (piVar1 == (int *)0x0) goto LAB_000192aa;
    }
    piVar2 = (int *)cacao::ProcessFactoryInternal::createResult(&stack0x00000194);
    uVar8 = 0;
    if (piVar2 != (int *)0x0) {
      piVar3 = operator_new(0x14);
      *piVar3 = (int)&PTR__Request_00020c48;
      sp<>::sp((sp<> *)(piVar3 + 1),in_stack_0000032c);
      piVar3[2] = param_1 + 0x14;
      piVar3[3] = 0;
      piVar3[4] = 0;
      (**(code **)(*piVar3 + 0x10))(piVar3,0);
      (**(code **)(*piVar3 + 0x18))(piVar3,piVar2);
      pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x20));
      iVar7 = *(int *)(param_1 + 0x3c);
      puVar4 = operator_new(0xc);
      *puVar4 = piVar3;
      puVar4[2] = iVar7;
      puVar4[1] = *(undefined4 *)(iVar7 + 4);
      *(undefined4 **)(*(int *)(iVar7 + 4) + 8) = puVar4;
      *(undefined4 **)(iVar7 + 4) = puVar4;
      pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x20));
      piVar5 = *(int **)(param_1 + 0x30);
      if (in_stack_00000328 == 0) {
        piVar6 = (int *)0x0;
        pcVar9 = *(code **)(*piVar5 + 0x20);
      }
      else {
        pcVar9 = *(code **)(*piVar5 + 0x1c);
        piVar6 = piVar3;
        piVar3 = piVar2;
      }
      uVar8 = (*pcVar9)(piVar5,piVar1,piVar6,piVar3);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x18));
  return uVar8;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::Client::cancel(int)

int __cdecl android::CacaoService::Client::cancel(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x30) + 0x24))();
    iVar2 = iVar1;
    if (iVar1 != -0x6e) {
      iVar2 = -0x80000000;
    }
    if (-1 < iVar1) {
      iVar2 = 0;
    }
    return iVar2;
  }
  return -0x80000000;
}



// android::CacaoService::Client::onHandleEvent(cacao::ProcessEventBase const*)

void __thiscall android::CacaoService::Client::onHandleEvent(Client *this,int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined4 auStack_358 [101];
  Client aCStack_1c4 [4];
  int local_1c0;
  int *local_1bc;
  undefined4 local_1b8 [102];
  int local_20;
  
  local_20 = __stack_chk_guard;
  local_1bc = (int *)0x0;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x1c));
  sp<>::operator=((sp<> *)&local_1bc,(undefined4 *)(this + 0x28));
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x1c));
  if (local_1bc != (int *)0x0) {
    local_1c0 = 0;
    __aeabi_memclr8(local_1b8,0x194);
    if (param_1 == (int *)0x0) {
      __android_log_print(6,"CacaoService","event:%p",0);
      if (local_1bc == (int *)0x0) {
        __android_log_print(6,"CacaoService","client:%p",0);
      }
    }
    else {
      uVar2 = (**(code **)(*param_1 + 0x1c))(param_1);
      allocMemory(aCStack_1c4,uVar2);
      sp<>::operator=((sp<> *)&local_1c0,(undefined4 *)aCStack_1c4);
      sp<>::~sp((sp<> *)aCStack_1c4);
      if (local_1c0 == 0) {
        __android_log_print(6,"CacaoService","event allocMemory fail");
      }
      else {
        makeSerializedData(&local_1c0,(int)local_1b8);
        iVar3 = (**(code **)(*param_1 + 0x20))(param_1,local_1b8);
        piVar1 = local_1bc;
        if (-1 < iVar3) {
          pcVar7 = *(code **)(*local_1bc + 0x10);
          uVar4 = (**(code **)(*param_1 + 0x10))(param_1);
          iVar3 = 400;
          puVar5 = (undefined4 *)((uint)local_1b8 | 4);
          puVar6 = auStack_358;
          do {
            iVar3 = iVar3 + -4;
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
          } while (iVar3 != 0);
          (*pcVar7)(piVar1,uVar4,&local_1c0,local_1b8[0]);
        }
      }
    }
    if (local_1c0 != 0) {
      sp<>::clear((sp<> *)&local_1c0);
    }
    sp<>::~sp((sp<> *)&local_1c0);
  }
  sp<>::~sp((sp<> *)&local_1bc);
  if (__stack_chk_guard == local_20) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::sp<android::ICacaoClient>::TEMPNAMEPLACEHOLDERVALUE(android::sp<android::ICacaoClient>
// const&)

sp<> * __thiscall android::sp<>::operator=(sp<> *this,undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)this;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    android::RefBase::incStrong((void *)(*(int *)(*piVar1 + -0xc) + (int)piVar1));
  }
  if (piVar2 != (int *)0x0) {
    android::RefBase::decStrong((void *)(*(int *)(*piVar2 + -0xc) + (int)piVar2));
  }
  if (piVar2 != *(int **)this) {
    android::sp_report_race();
  }
  *(int **)this = piVar1;
  return this;
}



// android::CacaoService::Client::allocMemory(unsigned int)

void __thiscall android::CacaoService::Client::allocMemory(Client *this,uint param_1)

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
  sp<>::~sp(asStack_20);
  if (__stack_chk_guard == local_1c) {
    return;
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



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::Client::makeSerializedData(android::sp<android::IMemory> const&,
// cacao::ISerialize::SerializedData*)

void __cdecl android::CacaoService::Client::makeSerializedData(int *param_1,int param_2)

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
// android::CacaoService::Client::freeMemory(android::sp<android::IMemory>&)

void __cdecl android::CacaoService::Client::freeMemory(sp<> *param_1)

{
  if (*(int *)param_1 != 0) {
    sp<>::clear(param_1);
    return;
  }
  return;
}



// non-virtual thunk to android::CacaoService::Client::onHandleEvent(cacao::ProcessEventBase const*)

void __thiscall android::CacaoService::Client::onHandleEvent(Client *this)

{
  int *in_r1;
  
  onHandleEvent(this + -0x10,in_r1);
  return;
}



// android::CacaoService::Client::onHandleProgress(cacao::ProcessResultBase const*)

void __thiscall android::CacaoService::Client::onHandleProgress(Client *this,int *param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  pthread_mutex_t *__mutex;
  code *pcVar7;
  undefined4 auStack_350 [99];
  sp<> asStack_1c4 [4];
  int local_1c0;
  int *local_1bc;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  undefined4 auStack_1b0 [100];
  int local_20;
  
  local_20 = __stack_chk_guard;
  local_1c0 = 0;
  local_1bc = (int *)0x0;
  __aeabi_memclr8(&local_1b8,0x194);
  if (param_1 == (int *)0x0) {
    __android_log_print(6,"CacaoService","pResult:%p",0);
  }
  else {
    __mutex = (pthread_mutex_t *)(this + 0x20);
    pthread_mutex_lock(__mutex);
    piVar2 = *(int **)(this + 0x3c);
    for (piVar6 = (int *)piVar2[2]; piVar6 != piVar2; piVar6 = (int *)piVar6[2]) {
      if ((int *)*piVar6 != (int *)0x0) {
        piVar2 = (int *)(**(code **)(*(int *)*piVar6 + 0x1c))();
        if (piVar2 == param_1) {
          if ((int *)*piVar6 != (int *)0x0) {
            (**(code **)(*(int *)*piVar6 + 0x20))(asStack_1c4);
            sp<>::operator=((sp<> *)&local_1bc,(undefined4 *)asStack_1c4);
            sp<>::~sp(asStack_1c4);
            pthread_mutex_unlock(__mutex);
            uVar1 = (**(code **)(*param_1 + 0x24))(param_1);
            allocMemory((Client *)asStack_1c4,uVar1);
            sp<>::operator=((sp<> *)&local_1c0,(undefined4 *)asStack_1c4);
            sp<>::~sp(asStack_1c4);
            if (local_1c0 != 0) {
              makeSerializedData(&local_1c0,(int)&local_1b8);
              (**(code **)(*param_1 + 0x28))(param_1,&local_1b8);
            }
            goto LAB_00019656;
          }
          break;
        }
        piVar2 = *(int **)(this + 0x3c);
      }
    }
    __android_log_print(6,"CacaoService","pRequest:%p",0);
    pthread_mutex_unlock(__mutex);
  }
LAB_00019656:
  piVar2 = local_1bc;
  if (local_1bc == (int *)0x0) {
    __android_log_print(6,"CacaoService","could not call the progress callback");
  }
  else {
    iVar4 = 0x18c;
    pcVar7 = *(code **)(*local_1bc + 0x10);
    puVar3 = auStack_1b0;
    puVar5 = auStack_350;
    do {
      iVar4 = iVar4 + -4;
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar4 != 0);
    (*pcVar7)(piVar2,&local_1c0,local_1b8,uStack_1b4);
  }
  if (local_1c0 != 0) {
    sp<>::clear((sp<> *)&local_1c0);
  }
  sp<>::~sp((sp<> *)&local_1c0);
  sp<>::~sp((sp<> *)&local_1bc);
  if (__stack_chk_guard == local_20) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::CacaoService::Client::onHandleProgress(cacao::ProcessResultBase
// const*)

void __thiscall android::CacaoService::Client::onHandleProgress(Client *this)

{
  int *in_r1;
  
  onHandleProgress(this + -0x14,in_r1);
  return;
}



// android::CacaoService::Client::onHandleResult(cacao::ProcessResultBase const*)

void __thiscall android::CacaoService::Client::onHandleResult(Client *this,int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  pthread_mutex_t *__mutex;
  int *piVar8;
  code *pcVar9;
  undefined4 auStack_358 [99];
  undefined4 local_1cc;
  sp<> asStack_1c4 [4];
  int local_1c0;
  int *local_1bc;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  undefined4 auStack_1b0 [99];
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_1c0 = 0;
  local_1bc = (int *)0x0;
  __aeabi_memclr8(&local_1b8,0x194);
  if (param_1 == (int *)0x0) {
    __android_log_print(6,"CacaoService","pResult:%p",0);
  }
  else {
    __mutex = (pthread_mutex_t *)(this + 0x20);
    pthread_mutex_lock(__mutex);
    piVar3 = *(int **)(this + 0x3c);
    for (piVar8 = (int *)piVar3[2]; piVar8 != piVar3; piVar8 = (int *)piVar8[2]) {
      if ((int *)*piVar8 != (int *)0x0) {
        piVar3 = (int *)(**(code **)(*(int *)*piVar8 + 0x1c))();
        if (piVar3 == param_1) {
          piVar3 = (int *)*piVar8;
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 0x20))(asStack_1c4,piVar3);
            sp<>::operator=((sp<> *)&local_1bc,(undefined4 *)asStack_1c4);
            sp<>::~sp(asStack_1c4);
            uVar1 = (**(code **)(*piVar3 + 0x14))(piVar3);
            iVar6 = piVar8[1];
            iVar5 = piVar8[2];
            *(int *)(iVar6 + 8) = iVar5;
            *(int *)(iVar5 + 4) = iVar6;
            operator_delete(piVar8);
            pthread_mutex_unlock(__mutex);
            uVar2 = (**(code **)(*param_1 + 0x24))(param_1);
            allocMemory((Client *)asStack_1c4,uVar2);
            sp<>::operator=((sp<> *)&local_1c0,(undefined4 *)asStack_1c4);
            sp<>::~sp(asStack_1c4);
            if (local_1c0 != 0) {
              makeSerializedData(&local_1c0,(int)&local_1b8);
              (**(code **)(*param_1 + 0x28))(param_1,&local_1b8);
            }
            goto LAB_000197c8;
          }
          break;
        }
        piVar3 = *(int **)(this + 0x3c);
      }
    }
    __android_log_print(6,"CacaoService","pRequest:%p",0);
    pthread_mutex_unlock(__mutex);
  }
  uVar1 = 0;
  piVar3 = (int *)0x0;
LAB_000197c8:
  piVar8 = local_1bc;
  if (local_1bc == (int *)0x0) {
    __android_log_print(6,"CacaoService","could not call the result callback");
  }
  else {
    iVar6 = 0x18c;
    pcVar9 = *(code **)(*local_1bc + 0x14);
    puVar4 = auStack_1b0;
    puVar7 = auStack_358;
    local_1cc = uVar1;
    do {
      iVar6 = iVar6 + -4;
      *puVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar6 != 0);
    (*pcVar9)(piVar8,&local_1c0,local_1b8,uStack_1b4);
  }
  if (local_1c0 != 0) {
    sp<>::clear((sp<> *)&local_1c0);
  }
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(piVar3);
  }
  sp<>::~sp((sp<> *)&local_1c0);
  sp<>::~sp((sp<> *)&local_1bc);
  if (__stack_chk_guard == local_24) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// non-virtual thunk to android::CacaoService::Client::onHandleResult(cacao::ProcessResultBase
// const*)

void __thiscall android::CacaoService::Client::onHandleResult(Client *this)

{
  int *in_r1;
  
  onHandleResult(this + -0x14,in_r1);
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



// android::sp<android::IMemory>::sp<android::MemoryBase>(android::MemoryBase*)

sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  *(int **)this = param_1;
  if (param_1 != (int *)0x0) {
    android::RefBase::incStrong((void *)(*(int *)(*param_1 + -0xc) + (int)param_1));
  }
  return this;
}



// android::CacaoService::Client::serviceDied()

void __thiscall android::CacaoService::Client::serviceDied(Client *this)

{
  __android_log_print(6,"CacaoService","The camera provider is died.");
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  if (*(int **)(this + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x30) + 0x28))();
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  return;
}



// android::CacaoService::getServiceName()

char * android::CacaoService::getServiceName(void)

{
  return "cacao";
}



// android::CacaoService::getClientUid()

void android::CacaoService::getClientUid(void)

{
  android::IPCThreadState::self();
  android::IPCThreadState::getCallingUid();
  return;
}



// android::CacaoService::CacaoService()

CacaoService * __thiscall android::CacaoService::CacaoService(CacaoService *this,int *param_1)

{
  int iVar1;
  void *pvVar2;
  sp<> asStack_2c [4];
  ulonglong local_28;
  void *local_20;
  int local_18;
  
  local_18 = __stack_chk_guard;
  android::ICacaoService::ICacaoService((ICacaoService *)this);
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
  iVar1 = *param_1;
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0x11];
  *(int *)(this + 4) = param_1[0x12];
  *(int *)(this + 0x10) = param_1[0x13];
  *(int *)(this + *(int *)(*(int *)this + -0x10)) = param_1[0x14];
  *(int *)(this + *(int *)(*(int *)this + -0x14)) = param_1[0x15];
  pthread_mutex_init((pthread_mutex_t *)(this + 0x14),(pthread_mutexattr_t *)0x0);
  pthread_mutex_init((pthread_mutex_t *)(this + 0x18),(pthread_mutexattr_t *)0x0);
  *(undefined ***)(this + 0x1c) = &PTR__List_1_000218e0;
  pvVar2 = operator_new__(0xc);
  *(void **)(this + 0x20) = pvVar2;
  *(void **)((int)pvVar2 + 4) = pvVar2;
  *(void **)((int)pvVar2 + 8) = pvVar2;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined8 *)(this + 0x24) = 0;
  *(undefined8 *)(this + 0x2c) = 0;
  local_28 = 0;
  local_20 = (void *)0x0;
  sp<>::sp<>(asStack_2c,(int *)this);
  android::hardware::camera::provider::V2_4::ICameraProvider::registerForNotifications
            ((string *)&local_28,(sp *)asStack_2c);
  sp<>::~sp((sp<> *)asStack_2c);
  if ((local_28 & 1) != 0) {
    operator_delete(local_20);
  }
  if (__stack_chk_guard == local_18) {
    return this;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::sp<android::hidl::manager::V1_0::IServiceNotification>::sp<android::CacaoService>(android::CacaoService*)

sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  if (param_1 == (int *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    *(int *)this = *(int *)(*param_1 + -0x10) + (int)param_1;
    android::RefBase::incStrong
              ((void *)((int)param_1 +
                       *(int *)(*(int *)((int)param_1 + *(int *)(*param_1 + -0x10)) + -0xc) +
                       *(int *)(*param_1 + -0x10)));
  }
  return this;
}



// android::CacaoService::CacaoService()

CacaoService * __thiscall android::CacaoService::CacaoService(CacaoService *this)

{
  void *pvVar1;
  sp<> asStack_2c [4];
  ulonglong local_28;
  void *local_20;
  int local_18;
  
  local_18 = __stack_chk_guard;
  android::RefBase::RefBase((RefBase *)(this + 0x38));
  *(undefined4 *)(this + 0x44) = 0x217f4;
  *(undefined4 *)(this + 0x40) = 0x216f0;
  *(undefined4 *)(this + 0x38) = 0x2181c;
  android::ICacaoService::ICacaoService((ICacaoService *)this);
  android::BBinder::BBinder((BBinder *)(this + 4));
  *(undefined4 *)(this + 0x38) = 0x20e90;
  *(undefined4 *)this = 0x20dc8;
  *(undefined4 *)(this + 4) = 0x20e18;
  *(undefined4 *)(this + 0x10) = 0x20e68;
  *(undefined4 *)(this + 0x40) = 0x20ee8;
  *(undefined4 *)(this + 0x44) = 0x20f34;
  pthread_mutex_init((pthread_mutex_t *)(this + 0x14),(pthread_mutexattr_t *)0x0);
  pthread_mutex_init((pthread_mutex_t *)(this + 0x18),(pthread_mutexattr_t *)0x0);
  *(undefined ***)(this + 0x1c) = &PTR__List_1_000218e0;
  pvVar1 = operator_new__(0xc);
  *(void **)(this + 0x20) = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(void **)((int)pvVar1 + 8) = pvVar1;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined8 *)(this + 0x24) = 0;
  *(undefined8 *)(this + 0x2c) = 0;
  local_28 = 0;
  local_20 = (void *)0x0;
  sp<>::sp<>(asStack_2c,(int *)this);
  android::hardware::camera::provider::V2_4::ICameraProvider::registerForNotifications
            ((string *)&local_28,(sp *)asStack_2c);
  sp<>::~sp((sp<> *)asStack_2c);
  if ((local_28 & 1) != 0) {
    operator_delete(local_20);
  }
  if (__stack_chk_guard == local_18) {
    return this;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  *(int *)(this + *(int *)(iVar1 + -0xc)) = param_1[0x11];
  *(int *)(this + 4) = param_1[0x12];
  *(int *)(this + 0x10) = param_1[0x13];
  *(int *)(this + *(int *)(*(int *)this + -0x10)) = param_1[0x14];
  *(int *)(this + *(int *)(*(int *)this + -0x14)) = param_1[0x15];
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  sp<>::operator=((sp<> *)(this + 0x30),(int *)0x0);
  sp<>::operator=((sp<> *)(this + 0x34),(int *)0x0);
  sp<>::~sp((sp<> *)(this + 0x34));
  sp<>::~sp((sp<> *)(this + 0x30));
  List<>::~List((List<> *)(this + 0x1c));
  pthread_mutex_destroy((pthread_mutex_t *)(this + 0x18));
  pthread_mutex_destroy((pthread_mutex_t *)(this + 0x14));
  android::BBinder::~BBinder((BBinder *)(this + 4));
  android::ICacaoService::~ICacaoService((ICacaoService *)this);
  return;
}



// android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao>::TEMPNAMEPLACEHOLDERVALUE(vendor::somc::hardware::camera::cacao::V3_0::ICacao*)

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



// android::List<android::sp<android::CacaoService::Client> >::~List()

List<> * __thiscall android::List<>::~List(List<> *this)

{
  *(undefined ***)this = &PTR__List_1_000218e0;
  clear(this);
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  return this;
}



// android::CacaoService::~CacaoService()

CacaoService * __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x38));
  return this;
}



// non-virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + -4,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x34));
  return;
}



// non-virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + -0x10,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x28));
  return;
}



// virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  int iVar1;
  
  iVar1 = ~CacaoService(this + *(int *)(*(int *)this + -0xc),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x38));
  return;
}



// virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  int iVar1;
  
  iVar1 = ~CacaoService(this + *(int *)(*(int *)this + -0x3c),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x38));
  return;
}



// virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  int iVar1;
  
  iVar1 = ~CacaoService(this + *(int *)(*(int *)this + -0x14),(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(iVar1 + 0x38));
  return;
}



// android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this,(int *)&VTT);
  android::RefBase::~RefBase((RefBase *)(this + 0x38));
  operator_delete(this);
  return;
}



// non-virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + -4);
  return;
}



// non-virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + -0x10);
  return;
}



// virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + *(int *)(*(int *)this + -0xc));
  return;
}



// virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + *(int *)(*(int *)this + -0x3c));
  return;
}



// virtual thunk to android::CacaoService::~CacaoService()

void __thiscall android::CacaoService::~CacaoService(CacaoService *this)

{
  ~CacaoService(this + *(int *)(*(int *)this + -0x14));
  return;
}



// android::CacaoService::getInterfaces()

void __thiscall android::CacaoService::getInterfaces(CacaoService *this)

{
  CacaoService *pCVar1;
  int *piVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 local_98;
  int local_94;
  int *local_90;
  int local_8c [5];
  undefined1 local_78;
  char local_77;
  sp<> asStack_74 [4];
  sp<> local_70 [8];
  void *local_68;
  int local_58 [3];
  undefined3 local_4b;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined **local_40;
  int *local_3c;
  undefined4 *local_38;
  function<> *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_90 = (int *)0x0;
  local_98 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  stack0xffffffb0 = 0;
  local_4b = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  iVar6 = *(int *)(this + 0x2c);
  pCVar1 = this + 0x28;
  uVar4 = *(uint *)pCVar1;
  vendor::somc::hardware::camera::provider::V1_0::IVendorSomcCameraProvider::getService
            ((string *)local_8c,"internal/0");
  sp<>::operator=((sp<> *)&local_90,(undefined4 *)local_8c);
  sp<>::~sp((sp<> *)local_8c);
  piVar2 = local_90;
  pcVar7 = *(code **)(*local_90 + 0x18);
  sp<>::sp<>(local_70,(int *)this);
  iVar8 = uVar4 + 1;
  iVar6 = iVar6 + (uint)(0xfffffffe < uVar4);
  iVar5 = iVar8;
  iVar9 = iVar6;
  (*pcVar7)(local_8c,piVar2,local_70);
  sp<>::~sp((sp<> *)local_70);
  local_78 = 1;
  if (local_8c[0] == 0) {
    android::hardware::details::return_status::assertOk();
    if (local_77 == '\0') {
      __android_log_print(5,"CacaoService",
                          "%s: Unable to link to provider \'internal/0\' death notifications",
                          "getInterfaces",iVar5,iVar9);
    }
  }
  else {
    android::hardware::Status::description();
    pvVar3 = local_68;
    if (((byte)local_70[0] & 1) == 0) {
      pvVar3 = (void *)((uint)local_70 | 1);
    }
    __android_log_print(6,"CacaoService",
                        "%s: Transaction error in linking to camera provider \'internal/0\' death: %s"
                        ,"getInterfaces",pvVar3,iVar9);
    if (((byte)local_70[0] & 1) != 0) {
      operator_delete(local_68);
    }
  }
  local_38 = &local_98;
  local_3c = &local_94;
  local_40 = &PTR__AbstractUnwindCursor_1_000218f0;
  local_30 = (function<> *)&local_40;
  (**(code **)(*local_90 + 0x58))((return_status *)local_70,local_90,(function<> *)&local_40);
  android::hardware::details::return_status::operator=
            ((return_status *)local_58,(return_status *)local_70);
  android::hardware::details::return_status::~return_status((return_status *)local_70);
  std::function<>::~function((function<> *)&local_40);
  uStack_44 = 1;
  if (local_58[0] == 0) {
    iVar5 = 0;
  }
  else {
    android::hardware::Status::description();
    pvVar3 = local_68;
    if (((byte)local_70[0] & 1) == 0) {
      pvVar3 = (void *)((uint)local_70 | 1);
    }
    __android_log_print(6,"CacaoService","Transaction error trying to cacao interface: %s",pvVar3);
    if (((byte)local_70[0] & 1) != 0) {
      operator_delete(local_68);
    }
    iVar5 = -0x6f;
  }
  if (local_94 != 0) {
    __android_log_print(6,"CacaoService","Unable to cacao interface");
    iVar5 = -0x6f;
  }
  android::hardware::details::return_status::~return_status((return_status *)local_8c);
  if (-1 < iVar5) {
    *(int *)pCVar1 = iVar8;
    *(int *)(this + 0x2c) = iVar6;
    sp<>::operator=((sp<> *)(this + 0x30),&local_98);
    vendor::somc::hardware::camera::cacao::V3_1::ICacao::castFrom((sp *)local_8c,SUB41(&local_98,0))
    ;
    local_78 = 1;
    if (local_8c[0] == 0) {
      android::hardware::details::return_status::assertOk();
      sp<>::sp((sp<> *)local_70,(int *)asStack_74);
      sp<>::operator=((sp<> *)(this + 0x34),(undefined4 *)local_70);
      sp<>::~sp((sp<> *)local_70);
    }
    else {
      android::hardware::Status::description();
      pvVar3 = (void *)((uint)local_70 | 1);
      if (((byte)local_70[0] & 1) != 0) {
        pvVar3 = local_68;
      }
      __android_log_print(6,"CacaoService","Transaction error when casting cacao interface [%s]: %s"
                          ,pvVar3,"getInterfaces");
      if (((byte)local_70[0] & 1) != 0) {
        operator_delete(local_68);
      }
    }
    sp<>::~sp(asStack_74);
    android::hardware::details::return_status::~return_status((return_status *)local_8c);
  }
  __android_log_print(4,"CacaoService","%s: cookie:%llu","getInterfaces",*(undefined4 *)pCVar1,
                      *(undefined4 *)(this + 0x2c));
  android::hardware::details::return_status::~return_status((return_status *)local_58);
  sp<>::~sp((sp<> *)&local_98);
  sp<>::~sp((sp<> *)&local_90);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// vendor::somc::hardware::camera::provider::V1_0::IVendorSomcCameraProvider::getService(char
// const*, bool)

void __cdecl
vendor::somc::hardware::camera::provider::V1_0::IVendorSomcCameraProvider::getService
          (string *param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  void *pvVar3;
  char *__s;
  undefined8 uVar4;
  ulonglong local_30;
  void *local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_30 = 0;
  local_28 = (void *)0x0;
  __s = "";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  sVar1 = strlen(__s);
  if (0xffffffef < sVar1) {
    uVar4 = std::__basic_string_common<true>::__throw_length_error();
    iVar2 = (int)((ulonglong)uVar4 >> 0x20);
                    // WARNING: Could not recover jumptable at 0x0001a134. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)param_1)((int)uVar4,iVar2,*(undefined1 *)(iVar2 + 0xb));
    return;
  }
  if (sVar1 < 0xb) {
    pvVar3 = (void *)((uint)&local_30 | 1);
    local_30 = CONCAT71(local_30._1_7_,(char)(sVar1 << 1));
    if (sVar1 == 0) goto LAB_0001a0f8;
  }
  else {
    pvVar3 = operator_new(sVar1 + 0x10 & 0xfffffff0);
    local_30 = CONCAT44(sVar1,sVar1 + 0x10) & 0xfffffffffffffff0 | 1;
    local_28 = pvVar3;
  }
  __aeabi_memcpy(pvVar3,__s,sVar1);
LAB_0001a0f8:
  *(undefined1 *)((int)pvVar3 + sVar1) = 0;
  vendor::somc::hardware::camera::provider::V1_0::IVendorSomcCameraProvider::getService
            (param_1,SUB41(&local_30,0));
  if ((local_30 & 1) != 0) {
    operator_delete(local_28);
  }
  if (__stack_chk_guard != local_24) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



// android::sp<android::hardware::hidl_death_recipient>::sp<android::CacaoService>(android::CacaoService*)

sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  if (param_1 == (int *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    *(int *)this = *(int *)(*param_1 + -0x14) + (int)param_1;
    android::RefBase::incStrong
              ((void *)((int)param_1 +
                       *(int *)(*(int *)((int)param_1 + *(int *)(*param_1 + -0x14)) + -0xc) +
                       *(int *)(*param_1 + -0x14)));
  }
  return this;
}



// std::function<void (vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps const&,
// vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::~function()

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



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::onRegistration(android::hardware::hidl_string const&,
// android::hardware::hidl_string const&, bool)

void __cdecl android::CacaoService::onRegistration(undefined8 *param_1,CacaoService *param_2)

{
  getInterfaces(param_2);
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined8 *)((int)param_1 + 0xd) = 0;
  return;
}



// virtual thunk to android::CacaoService::onRegistration(android::hardware::hidl_string const&,
// android::hardware::hidl_string const&, bool)

void __thiscall android::CacaoService::onRegistration(CacaoService *this,int *param_1)

{
  getInterfaces((CacaoService *)(*(int *)(*param_1 + -0x40) + (int)param_1));
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0xd) = 0;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::connect(android::sp<android::ICacaoClient> const&)

void __cdecl android::CacaoService::connect(undefined4 *param_1,int *param_2,int *param_3)

{
  Client *this;
  undefined4 uVar1;
  sp<> asStack_30 [4];
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(param_2 + 5));
  this = operator_new(0x48);
  sp<>::sp<>(asStack_30,param_2);
  android::IPCThreadState::self();
  uVar1 = android::IPCThreadState::getCallingPid();
  Client::Client(this,(int *)asStack_30,param_3,uVar1);
  sp<>::sp<>((sp<> *)&local_2c,(int *)this);
  sp<>::~sp((sp<> *)asStack_30);
  (**(code **)(*param_2 + 0x28))(param_2,(sp<> *)&local_2c);
  *param_1 = local_2c;
  local_2c = 0;
  sp<>::~sp((sp<> *)&local_2c);
  pthread_mutex_unlock((pthread_mutex_t *)(param_2 + 5));
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)

int __thiscall
android::CacaoService::getCaps
          (CacaoService *this,int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  void *pvVar11;
  uint extraout_r3;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int local_28ac;
  return_status local_28a8 [8];
  void *local_28a0;
  int local_2890 [3];
  undefined3 local_2883;
  undefined4 uStack_2880;
  undefined1 uStack_287c;
  CacaoCaps aCStack_2878 [16];
  void *local_2868;
  char local_285c;
  void *local_2858;
  char local_284c;
  void *local_2840;
  char local_2834;
  void *local_2830;
  char local_2824;
  void *local_2818;
  char local_280c;
  void *local_2808;
  char local_27fc;
  void *local_27e8;
  char local_27dc;
  void *local_27d8;
  char local_27cc;
  void *local_27c8;
  char local_27bc;
  undefined4 local_27b0;
  uint local_27a8;
  void *local_27a0;
  undefined8 local_2798;
  undefined4 *local_2790;
  undefined8 local_2788;
  uint local_2780;
  void *local_2778;
  undefined8 local_2770;
  undefined4 *local_2768;
  undefined8 local_2760;
  undefined4 local_2758 [2];
  uint local_2750;
  void *local_2748;
  char local_273c;
  undefined4 *local_2738;
  char local_272c;
  uint local_2728;
  void *local_2720;
  char local_2714;
  undefined4 *local_2710;
  char local_2704;
  uint local_2700;
  void *local_26f8;
  char local_26ec;
  undefined4 *local_26e8;
  char local_26dc;
  undefined4 local_26d8;
  uint local_26d0;
  void *local_26c8;
  char local_26bc;
  undefined4 *local_26b8;
  char local_26ac;
  undefined4 *local_26a8;
  char local_269c;
  undefined4 local_2698;
  undefined4 uStack_2694;
  undefined **local_2690;
  CacaoCaps *local_268c;
  int *piStack_2688;
  function<> *local_2680;
  undefined **local_2678;
  int local_2674;
  CacaoCaps *local_2670;
  int *local_266c;
  function<> *local_2668;
  undefined **local_2660;
  undefined **local_265c;
  undefined4 local_2658;
  uint local_2654;
  undefined4 local_2650 [256];
  undefined4 auStack_2250 [129];
  undefined4 auStack_204c [256];
  undefined4 auStack_1c4c [128];
  uint local_1a4c;
  undefined4 auStack_1a48 [256];
  undefined4 auStack_1648 [128];
  undefined4 uStack_1448;
  uint uStack_1444;
  undefined4 local_1440 [256];
  undefined4 local_1040 [128];
  undefined4 local_e40 [128];
  undefined4 uStack_c40;
  undefined4 uStack_c3c;
  undefined4 uStack_c38;
  uint uStack_c34;
  undefined4 auStack_c30 [256];
  undefined4 auStack_830 [128];
  uint uStack_630;
  undefined4 auStack_62c [256];
  undefined4 auStack_22c [129];
  undefined4 local_4;
  
  iVar4 = __stack_chk_guard;
  local_4 = param_3;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x14));
  cacao::ObjectBase::ObjectBase((ObjectBase *)&local_2660);
  local_265c = &PTR__Caps_1_0002188c;
  local_2660 = &PTR__Caps_1_00021868;
  vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps::CacaoCaps((CacaoCaps *)local_2758);
  iVar5 = vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps::CacaoCaps(aCStack_2878);
  *(undefined8 *)(iVar5 + 0xd8) = 0;
  local_2798 = 0;
  *(undefined1 *)(iVar5 + 0xe4) = 1;
  local_2788 = 0;
  *(undefined8 *)(iVar5 + 0xe8) = 0;
  *(undefined1 *)(iVar5 + 0xf4) = 1;
  local_2770 = 0;
  *(undefined8 *)(iVar5 + 0x100) = 0;
  *(undefined1 *)(iVar5 + 0x10c) = 1;
  local_2760 = 0;
  *(undefined8 *)(iVar5 + 0x110) = 0;
  *(undefined1 *)(iVar5 + 0x11c) = 1;
  local_28ac = 0;
  uVar9 = 0;
  if (*param_1 == 0) {
LAB_0001a30a:
    local_2890[0] = 0;
    local_2890[1] = 0;
    stack0xffffd778 = 0;
    local_2883 = 0;
    uStack_2880 = 0;
    uStack_287c = 0;
    piVar7 = *(int **)(this + 0x34);
    if (piVar7 == (int *)0x0) {
      piStack_2688 = &local_28ac;
      local_2690 = &PTR__AbstractUnwindCursor_1_00021938;
      local_268c = (CacaoCaps *)local_2758;
      local_2680 = (function<> *)&local_2690;
      (**(code **)(**(int **)(this + 0x30) + 0x54))
                (local_28a8,*(int **)(this + 0x30),uVar9,(function<> *)&local_2690);
      android::hardware::details::return_status::operator=((return_status *)local_2890,local_28a8);
      android::hardware::details::return_status::~return_status(local_28a8);
      std::function<>::~function((function<> *)&local_2690);
    }
    else {
      local_2678 = &PTR__AbstractUnwindCursor_1_00021914;
      local_266c = &local_28ac;
      local_2674 = iVar5;
      local_2670 = (CacaoCaps *)local_2758;
      local_2668 = (function<> *)&local_2678;
      (**(code **)(*piVar7 + 0x5c))(local_28a8,piVar7,uVar9,(function<> *)&local_2678);
      android::hardware::details::return_status::operator=((return_status *)local_2890,local_28a8);
      android::hardware::details::return_status::~return_status(local_28a8);
      std::function<>::~function((function<> *)&local_2678);
    }
    uStack_287c = 1;
    if (local_2890[0] != 0) {
      android::hardware::Status::description();
      pvVar11 = local_28a0;
      if (((byte)local_28a8[0] & 1) == 0) {
        pvVar11 = (void *)((uint)local_28a8 | 1);
      }
      __android_log_print(6,"CacaoService","Transaction error: %s",pvVar11);
      if (((byte)local_28a8[0] & 1) != 0) {
        operator_delete(local_28a0);
      }
      local_28ac = -0x6f;
    }
    android::hardware::details::return_status::~return_status((return_status *)local_2890);
    if (local_28ac < 0) {
LAB_0001a802:
      iVar5 = local_28ac;
      if (local_28ac != -0x6e) {
        iVar5 = -0x80000000;
      }
      if (-1 < local_28ac) {
        iVar5 = 0;
      }
      goto LAB_0001a458;
    }
    iVar5 = *(int *)(this + 0x34);
    if (iVar5 == 0) {
      uVar8 = local_2750;
      uVar1 = extraout_r3;
      if (local_2750 < 0x81) {
        uVar8 = local_2728;
        uVar1 = local_2728;
      }
      uVar2 = local_26d0;
      uVar3 = local_2700;
      if (uVar8 < 0x81) goto joined_r0x0001a626;
    }
    else {
      uVar8 = local_2750;
      uVar1 = extraout_r3;
      if (local_2750 < 0x81) {
        uVar8 = local_2728;
        uVar1 = local_2728;
      }
      if ((uVar8 < 0x81) && (local_2700 < 0x81)) {
        uVar2 = local_2780;
        uVar3 = local_26d0;
        if (local_26d0 < 0x81) {
          uVar3 = local_27a8;
        }
joined_r0x0001a626:
        if ((uVar3 < 0x81) && (uVar2 < 0x81)) {
          local_2654 = local_2750;
          local_2658 = local_2758[0];
          if (local_2750 != 0) {
            puVar10 = local_2650;
            puVar13 = (undefined4 *)((int)local_2748 + 4);
            uVar8 = 0;
            puVar6 = auStack_2250;
            puVar12 = local_2738;
            do {
              uVar8 = uVar8 + 1;
              *puVar10 = puVar13[-1];
              uVar9 = *puVar13;
              puVar13 = puVar13 + 2;
              puVar10[1] = uVar9;
              puVar10 = puVar10 + 2;
              *puVar6 = *puVar12;
              puVar6 = puVar6 + 1;
              puVar12 = puVar12 + 1;
            } while (uVar8 != local_2750);
          }
          if (uVar1 != 0) {
            puVar10 = auStack_204c + 1;
            puVar13 = (undefined4 *)((int)local_2720 + 4);
            uVar8 = 0;
            puVar6 = auStack_1c4c;
            puVar12 = local_2710;
            do {
              uVar8 = uVar8 + 1;
              puVar10[-1] = puVar13[-1];
              uVar9 = *puVar13;
              puVar13 = puVar13 + 2;
              *puVar10 = uVar9;
              puVar10 = puVar10 + 2;
              *puVar6 = *puVar12;
              puVar6 = puVar6 + 1;
              puVar12 = puVar12 + 1;
            } while (uVar8 != uVar1);
          }
          local_1a4c = local_2700;
          if (local_2700 != 0) {
            puVar10 = auStack_1a48 + 1;
            puVar13 = (undefined4 *)((int)local_26f8 + 4);
            uVar8 = 0;
            puVar6 = auStack_1648;
            puVar12 = local_26e8;
            do {
              uVar8 = uVar8 + 1;
              *puVar6 = *puVar12;
              puVar10[-1] = puVar13[-1];
              uVar9 = *puVar13;
              puVar13 = puVar13 + 2;
              *puVar10 = uVar9;
              puVar10 = puVar10 + 2;
              puVar6 = puVar6 + 1;
              puVar12 = puVar12 + 1;
            } while (uVar8 != local_2700);
          }
          uStack_1444 = local_26d0;
          uStack_1448 = local_26d8;
          if (local_26d0 != 0) {
            puVar13 = local_1440;
            puVar14 = local_1040;
            puVar10 = (undefined4 *)((int)local_26c8 + 4);
            uVar8 = 0;
            puVar6 = local_26a8;
            puVar12 = local_26b8;
            do {
              uVar8 = uVar8 + 1;
              *puVar13 = puVar10[-1];
              uVar9 = *puVar10;
              puVar10 = puVar10 + 2;
              puVar13[1] = uVar9;
              puVar13 = puVar13 + 2;
              *puVar14 = *puVar12;
              puVar14[0x80] = *puVar6;
              puVar14 = puVar14 + 1;
              puVar6 = puVar6 + 1;
              puVar12 = puVar12 + 1;
            } while (uVar8 != local_26d0);
          }
          uStack_c40 = local_2698;
          uStack_c3c = uStack_2694;
          if (iVar5 == 0) {
            uStack_c34 = 0;
            uStack_c38 = 0;
            uStack_630 = 0;
          }
          else {
            uStack_c38 = local_27b0;
            uStack_c34 = local_27a8;
            if (local_27a8 != 0) {
              uVar8 = 0;
              puVar10 = auStack_c30 + 1;
              puVar13 = (undefined4 *)((int)local_27a0 + 4);
              puVar6 = auStack_830;
              puVar12 = local_2790;
              do {
                uVar8 = uVar8 + 1;
                puVar10[-1] = puVar13[-1];
                uVar9 = *puVar13;
                puVar13 = puVar13 + 2;
                *puVar10 = uVar9;
                puVar10 = puVar10 + 2;
                *puVar6 = *puVar12;
                puVar6 = puVar6 + 1;
                puVar12 = puVar12 + 1;
              } while (uVar8 != local_27a8);
            }
            uStack_630 = local_2780;
            if (local_2780 != 0) {
              uVar8 = 0;
              puVar10 = auStack_62c + 1;
              puVar13 = (undefined4 *)((int)local_2778 + 4);
              puVar6 = auStack_22c;
              puVar12 = local_2768;
              do {
                uVar8 = uVar8 + 1;
                puVar10[-1] = puVar13[-1];
                uVar9 = *puVar13;
                puVar13 = puVar13 + 2;
                *puVar10 = uVar9;
                puVar10 = puVar10 + 2;
                *puVar6 = *puVar12;
                puVar6 = puVar6 + 1;
                puVar12 = puVar12 + 1;
              } while (uVar8 != local_2780);
            }
          }
          local_28ac = cacao::Caps::serialize((Caps *)&local_2660,(int)&local_4);
          goto LAB_0001a802;
        }
      }
    }
    __android_log_print(6,"CacaoService","Max support item over.");
    local_28ac = -0x6f;
  }
  else {
    if (*param_1 == 1) {
      uVar9 = 1;
      goto LAB_0001a30a;
    }
    __android_log_print(6,"CacaoService","Invalid camera index");
    local_28ac = -0x67;
  }
  iVar5 = -0x80000000;
LAB_0001a458:
  if ((local_2760._4_1_ != '\0') && (local_2768 != (undefined4 *)0x0)) {
    operator_delete__(local_2768);
  }
  local_2768 = (undefined4 *)0x0;
  if ((local_2770._4_1_ != '\0') && (local_2778 != (void *)0x0)) {
    operator_delete__(local_2778);
  }
  local_2778 = (void *)0x0;
  if ((local_2788._4_1_ != '\0') && (local_2790 != (undefined4 *)0x0)) {
    operator_delete__(local_2790);
  }
  local_2790 = (undefined4 *)0x0;
  if ((local_2798._4_1_ != '\0') && (local_27a0 != (void *)0x0)) {
    operator_delete__(local_27a0);
  }
  local_27a0 = (void *)0x0;
  if ((local_27bc != '\0') && (local_27c8 != (void *)0x0)) {
    operator_delete__(local_27c8);
  }
  local_27c8 = (void *)0x0;
  if ((local_27cc != '\0') && (local_27d8 != (void *)0x0)) {
    operator_delete__(local_27d8);
  }
  local_27d8 = (void *)0x0;
  if ((local_27dc != '\0') && (local_27e8 != (void *)0x0)) {
    operator_delete__(local_27e8);
  }
  local_27e8 = (void *)0x0;
  if ((local_27fc != '\0') && (local_2808 != (void *)0x0)) {
    operator_delete__(local_2808);
  }
  local_2808 = (void *)0x0;
  if ((local_280c != '\0') && (local_2818 != (void *)0x0)) {
    operator_delete__(local_2818);
  }
  local_2818 = (void *)0x0;
  if ((local_2824 != '\0') && (local_2830 != (void *)0x0)) {
    operator_delete__(local_2830);
  }
  local_2830 = (void *)0x0;
  if ((local_2834 != '\0') && (local_2840 != (void *)0x0)) {
    operator_delete__(local_2840);
  }
  local_2840 = (void *)0x0;
  if ((local_284c != '\0') && (local_2858 != (void *)0x0)) {
    operator_delete__(local_2858);
  }
  local_2858 = (void *)0x0;
  if ((local_285c != '\0') && (local_2868 != (void *)0x0)) {
    operator_delete__(local_2868);
  }
  if ((local_269c != '\0') && (local_26a8 != (undefined4 *)0x0)) {
    operator_delete__(local_26a8);
  }
  local_26a8 = (undefined4 *)0x0;
  if ((local_26ac != '\0') && (local_26b8 != (undefined4 *)0x0)) {
    operator_delete__(local_26b8);
  }
  local_26b8 = (undefined4 *)0x0;
  if ((local_26bc != '\0') && (local_26c8 != (void *)0x0)) {
    operator_delete__(local_26c8);
  }
  local_26c8 = (void *)0x0;
  if ((local_26dc != '\0') && (local_26e8 != (undefined4 *)0x0)) {
    operator_delete__(local_26e8);
  }
  local_26e8 = (undefined4 *)0x0;
  if ((local_26ec != '\0') && (local_26f8 != (void *)0x0)) {
    operator_delete__(local_26f8);
  }
  local_26f8 = (void *)0x0;
  if ((local_2704 != '\0') && (local_2710 != (undefined4 *)0x0)) {
    operator_delete__(local_2710);
  }
  local_2710 = (undefined4 *)0x0;
  if ((local_2714 != '\0') && (local_2720 != (void *)0x0)) {
    operator_delete__(local_2720);
  }
  local_2720 = (void *)0x0;
  if ((local_272c != '\0') && (local_2738 != (undefined4 *)0x0)) {
    operator_delete__(local_2738);
  }
  local_2738 = (undefined4 *)0x0;
  if ((local_273c != '\0') && (local_2748 != (void *)0x0)) {
    operator_delete__(local_2748);
  }
  cacao::ObjectBase::~ObjectBase((ObjectBase *)&local_2660);
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x14));
  if (__stack_chk_guard == iVar4) {
    return iVar5;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps::CacaoCaps()

void __thiscall vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps::CacaoCaps(CacaoCaps *this)

{
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  this[0x44] = (CacaoCaps)0x1;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  this[0x54] = (CacaoCaps)0x1;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  this[0x6c] = (CacaoCaps)0x1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  this[0x1c] = (CacaoCaps)0x1;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  this[0x2c] = (CacaoCaps)0x1;
  this[0x7c] = (CacaoCaps)0x1;
  this[0x9c] = (CacaoCaps)0x1;
  this[0xac] = (CacaoCaps)0x1;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  this[0xbc] = (CacaoCaps)0x1;
  return;
}



// cacao::Caps::serialize(cacao::ISerialize::SerializedData*) const

undefined4 __thiscall cacao::Caps::serialize(Caps *this,int param_1)

{
  int iVar1;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x188) != 0)) &&
     (*(int *)(param_1 + 0x18c) + 0x262cU <= *(uint *)(param_1 + 0x184))) {
    iVar1 = *(int *)(param_1 + 0x188) + *(int *)(param_1 + 0x18c);
    __aeabi_memcpy4(iVar1,this + 8,0xc0c);
    __aeabi_memcpy4(iVar1 + 0xc0c,this + 0xc14,0x604);
    __aeabi_memcpy4(iVar1 + 0x1210,this + 0x1218,0x808);
    *(undefined4 *)(iVar1 + 0x1a18) = *(undefined4 *)(this + 0x1a20);
    *(undefined4 *)(iVar1 + 0x1a1c) = *(undefined4 *)(this + 0x1a24);
    __aeabi_memcpy4(iVar1 + 0x1a20,this + 0x1a28,0xc0c);
    *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + 0x262c;
    return 0;
  }
  return 0xffffff99;
}



// cacao::Caps::~Caps()

void __thiscall cacao::Caps::~Caps(Caps *this)

{
  cacao::ObjectBase::~ObjectBase((ObjectBase *)this);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::getJpegBufferSize(cacao::ImageSize)

undefined4 __cdecl
android::CacaoService::getJpegBufferSize(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 local_74;
  return_status local_70 [8];
  void *local_68;
  int local_58 [3];
  undefined3 local_4b;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined **local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  function<> *local_30;
  int local_24;
  
  local_24 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x14));
  local_78 = 0;
  local_74 = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  stack0xffffffb0 = 0;
  local_4b = 0;
  local_38 = &local_74;
  local_3c = &local_78;
  local_40 = &PTR__AbstractUnwindCursor_1_0002195c;
  local_80 = param_2;
  uStack_7c = param_3;
  local_30 = (function<> *)&local_40;
  (**(code **)(**(int **)(param_1 + 0x30) + 0x58))
            (local_70,*(int **)(param_1 + 0x30),&local_80,(function<> *)&local_40);
  android::hardware::details::return_status::operator=((return_status *)local_58,local_70);
  android::hardware::details::return_status::~return_status(local_70);
  std::function<>::~function((function<> *)&local_40);
  uStack_44 = 1;
  if (local_58[0] != 0) {
    android::hardware::Status::description();
    pvVar2 = local_68;
    if (((byte)local_70[0] & 1) == 0) {
      pvVar2 = (void *)((uint)local_70 | 1);
    }
    __android_log_print(6,"CacaoService","Transaction error: %s",pvVar2);
    if (((byte)local_70[0] & 1) != 0) {
      operator_delete(local_68);
    }
    local_74 = 0xffffff91;
  }
  android::hardware::details::return_status::~return_status((return_status *)local_58);
  uVar1 = local_78;
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x14));
  if (__stack_chk_guard == local_24) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::CacaoService::getServicePid()

void android::CacaoService::getServicePid(void)

{
  getpid();
  return;
}



// android::CacaoService::registerClient(android::sp<android::CacaoService::Client> const&)

void __thiscall android::CacaoService::registerClient(CacaoService *this,int *param_1)

{
  code *pcVar1;
  sp<> asStack_38 [4];
  int *local_34;
  int local_30;
  int iStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  if (*param_1 != 0) {
    local_30 = *(int *)(this + 0x20);
    List<>::insert(&iStack_2c,this + 0x1c,&local_30,param_1);
    (**(code **)(*(int *)*param_1 + 0x44))(&local_30);
    iStack_2c = local_30;
    local_30 = 0;
    android::IInterface::asBinder((sp *)&local_34);
    pcVar1 = *(code **)(*local_34 + 0x18);
    sp<>::sp<>(asStack_38,(int *)this);
    (*pcVar1)(local_34,asStack_38,0,0);
    sp<>::~sp((sp<> *)asStack_38);
    sp<>::~sp((sp<> *)&local_34);
    sp<>::~sp((sp<> *)&iStack_2c);
    sp<>::~sp((sp<> *)&local_30);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::sp<android::IBinder::DeathRecipient>::sp<android::CacaoService>(android::CacaoService*)

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



// android::CacaoService::unregisterClient(android::sp<android::IBinder> const&)

void __thiscall android::CacaoService::unregisterClient(CacaoService *this,int *param_1)

{
  int iVar1;
  sp<> *psVar2;
  int *piVar3;
  sp<> *this_00;
  code *pcVar4;
  int iVar5;
  sp<> *local_40;
  int iStack_3c;
  undefined4 local_38 [2];
  undefined4 local_30;
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pthread_mutex_lock((pthread_mutex_t *)(this + 0x18));
  psVar2 = *(sp<> **)(this + 0x20);
  this_00 = *(sp<> **)(psVar2 + 8);
  if (psVar2 != this_00) {
    do {
      if (*(int **)this_00 != (int *)0x0) {
        (**(code **)(**(int **)this_00 + 0x44))((sp<> *)&local_30);
        local_38[0] = local_30;
        local_30 = 0;
        android::IInterface::asBinder((sp *)&local_2c);
        iVar1 = local_2c;
        iVar5 = *param_1;
        sp<>::~sp((sp<> *)&local_2c);
        sp<>::~sp((sp<> *)local_38);
        sp<>::~sp((sp<> *)&local_30);
        if (iVar1 == iVar5) {
          piVar3 = (int *)*param_1;
          pcVar4 = *(code **)(*piVar3 + 0x1c);
          wp<>::wp<>((wp<> *)local_38,(int *)this);
          (*pcVar4)(piVar3,(wp<> *)local_38,0,0,0);
          wp<>::~wp((wp<> *)local_38);
          sp<>::clear(this_00);
          local_40 = this_00;
          List<>::erase(&iStack_3c,this + 0x1c,(int *)&local_40);
          break;
        }
        psVar2 = *(sp<> **)(this + 0x20);
      }
      this_00 = *(sp<> **)(this_00 + 8);
    } while (psVar2 != this_00);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(this + 0x18));
  if (__stack_chk_guard != local_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



// android::wp<android::IBinder::DeathRecipient>::wp<android::CacaoService>(android::CacaoService*)

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



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::List<android::sp<android::CacaoService::Client>
// >::erase(android::List<android::sp<android::CacaoService::Client>
// >::_ListIterator<android::sp<android::CacaoService::Client>,
// android::List<android::sp<android::CacaoService::Client> >::NON_CONST_ITERATOR>)

void __cdecl android::List<>::erase(int *param_1,undefined4 param_2,int *param_3)

{
  sp<> *psVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*param_3 + 4);
  iVar3 = *(int *)(*param_3 + 8);
  *(int *)(iVar2 + 8) = iVar3;
  *(int *)(iVar3 + 4) = iVar2;
  if ((sp<> *)*param_3 != (sp<> *)0x0) {
    psVar1 = sp<>::~sp((sp<> *)*param_3);
    operator_delete(psVar1);
  }
  *param_1 = iVar3;
  return;
}



// libunwind::AbstractUnwindCursor::~AbstractUnwindCursor()

void __thiscall libunwind::AbstractUnwindCursor::~AbstractUnwindCursor(void)

{
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::onTransact(unsigned int, android::Parcel const&, android::Parcel*,
// unsigned int)

void __cdecl
android::CacaoService::onTransact(int *param_1,Parcel *param_2,Parcel *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  String16 *pSVar3;
  undefined4 uVar4;
  String16 aSStack_28 [4];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (param_2 == (Parcel *)0x1) {
    android::IPCThreadState::self();
    iVar1 = android::IPCThreadState::getCallingPid();
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar1 != iVar2) {
      pSVar3 = (String16 *)
               android::String16::String16(aSStack_28,"com.sonymobile.permission.IMAGE_PROCESSOR");
      iVar1 = android::checkCallingPermission(pSVar3);
      android::String16::~String16(aSStack_28);
      if (iVar1 == 0) {
        uVar4 = 0xffffffff;
        goto LAB_0001acea;
      }
    }
  }
  uVar4 = android::BnCacaoService::onTransact((uint)param_1,param_2,param_3,param_4);
LAB_0001acea:
  if (__stack_chk_guard == local_24) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail(uVar4);
}



// non-virtual thunk to android::CacaoService::onTransact(unsigned int, android::Parcel const&,
// android::Parcel*, unsigned int)

void __thiscall android::CacaoService::onTransact(CacaoService *this)

{
  Parcel *in_r1;
  Parcel *in_r2;
  uint in_r3;
  
  onTransact((int *)(this + -4),in_r1,in_r2,in_r3);
  return;
}



// android::hidl::manager::V1_0::IServiceNotification::isRemote() const

undefined4 android::hidl::manager::V1_0::IServiceNotification::isRemote(void)

{
  return 0;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::binderDied(android::wp<android::IBinder> const&)

void __cdecl android::CacaoService::binderDied(int *param_1,int *param_2)

{
  code *pcVar1;
  sp<> asStack_1c [4];
  int local_18;
  
  local_18 = __stack_chk_guard;
  pcVar1 = *(code **)(*param_1 + 0x2c);
  wp<>::promote((int *)asStack_1c,param_2);
  (*pcVar1)(param_1,asStack_1c);
  sp<>::~sp(asStack_1c);
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::wp<android::IBinder>::promote() const

void __cdecl android::wp<>::promote(int *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = 0;
  if ((*param_2 != 0) &&
     (iVar1 = android::RefBase::weakref_type::attemptIncStrong((void *)param_2[1]), iVar1 != 0)) {
    *param_1 = *param_2;
  }
  return;
}



// non-virtual thunk to android::CacaoService::binderDied(android::wp<android::IBinder> const&)

void __thiscall android::CacaoService::binderDied(CacaoService *this)

{
  int *in_r1;
  
  binderDied((int *)(this + -0x10),in_r1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::serviceDied(unsigned long long,
// android::wp<android::hidl::base::V1_0::IBase> const&)

void __cdecl
android::CacaoService::serviceDied(int param_1,undefined4 param_2_00,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  __android_log_print(6,"CacaoService","The camera provider is died. current:%llu, died:%llu",
                      param_4,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
                      param_3,param_4);
  if (*(int *)(param_1 + 0x28) != param_3 || *(int *)(param_1 + 0x2c) != param_4) {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  *(int *)(param_1 + 0x24) = iVar1 + 1;
  if (iVar1 < 0x13) {
    pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x18));
    puVar2 = *(undefined4 **)(param_1 + 0x20);
    for (puVar3 = (undefined4 *)puVar2[2]; puVar3 != puVar2; puVar3 = (undefined4 *)puVar3[2]) {
      if ((Client *)*puVar3 != (Client *)0x0) {
        Client::serviceDied((Client *)*puVar3);
        puVar2 = *(undefined4 **)(param_1 + 0x20);
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x18));
    return;
  }
  __android_log_print(6,"CacaoService",
                      "Abort cacao service because camera provider is died frequently.");
                    // WARNING: Subroutine does not return
  abort();
}



// virtual thunk to android::CacaoService::serviceDied(unsigned long long,
// android::wp<android::hidl::base::V1_0::IBase> const&)

void __thiscall
android::CacaoService::serviceDied(CacaoService *this,undefined4 param_1,int param_2,int param_3)

{
  serviceDied((int)(this + *(int *)(*(int *)this + -0x10)),*(int *)(*(int *)this + -0x10),param_2,
              param_3);
  return;
}



void instantiate(void)

{
  android::BinderService<>::publish(0,8);
  return;
}



// android::CacaoService::Client::Request::getBufVector() const

undefined4 __thiscall android::CacaoService::Client::Request::getBufVector(Request *this)

{
  return *(undefined4 *)(this + 0xc);
}



// android::CacaoService::Client::Request::getResult() const

undefined4 __thiscall android::CacaoService::Client::Request::getResult(Request *this)

{
  return *(undefined4 *)(this + 0x10);
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::Client::Request::getCallback() const

void __cdecl android::CacaoService::Client::Request::getCallback(sp<> *param_1,int param_2)

{
  sp<>::sp(param_1,(int *)(param_2 + 4));
  return;
}



// virtual thunk to android::hardware::hidl_death_recipient::~hidl_death_recipient()

void __thiscall android::hardware::hidl_death_recipient::~hidl_death_recipient(void)

{
  code *pcVar1;
  
                    // WARNING: Does not return
  pcVar1 = (code *)software_udf(0xfe,0x1ae36);
  (*pcVar1)();
}



// android::BnInterface<android::ICacao>::onAsBinder()

BnInterface<> * __thiscall android::BnInterface<>::onAsBinder(BnInterface<> *this)

{
  return this + 4;
}



// android::BnInterface<android::ICacao>::getInterfaceDescriptor() const

void android::BnInterface<>::getInterfaceDescriptor(void)

{
  android::ICacao::getInterfaceDescriptor();
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



// non-virtual thunk to android::BnInterface<android::ICacao>::getInterfaceDescriptor() const

void __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  android::ICacao::getInterfaceDescriptor();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::CacaoService::Client::getClient() const

void __cdecl android::CacaoService::Client::getClient(sp<> *param_1,int param_2)

{
  sp<>::sp(param_1,(int *)(param_2 + 0x28));
  return;
}



// android::BnInterface<android::ICacaoService>::getInterfaceDescriptor() const

void android::BnInterface<>::getInterfaceDescriptor(void)

{
  android::ICacaoService::getInterfaceDescriptor();
  return;
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



// non-virtual thunk to android::BnInterface<android::ICacaoService>::getInterfaceDescriptor() const

void __thiscall android::BnInterface<>::getInterfaceDescriptor(void)

{
  android::ICacaoService::getInterfaceDescriptor();
  return;
}



// android::hidl::base::V1_0::IBase::~IBase()

IBase * __thiscall android::hidl::base::V1_0::IBase::~IBase(IBase *this)

{
  android::RefBase::~RefBase((RefBase *)(this + 4));
  return this;
}



// android::hidl::base::V1_0::IBase::~IBase()

void __thiscall android::hidl::base::V1_0::IBase::~IBase(IBase *this)

{
  android::RefBase::~RefBase((RefBase *)(this + 4));
  operator_delete(this);
  return;
}



// virtual thunk to android::hidl::base::V1_0::IBase::~IBase()

void __thiscall android::hidl::base::V1_0::IBase::~IBase(IBase *this)

{
  android::RefBase::~RefBase((RefBase *)(this + *(int *)(*(int *)this + -0xc) + 4));
  return;
}



// virtual thunk to android::hidl::base::V1_0::IBase::~IBase()

void __thiscall android::hidl::base::V1_0::IBase::~IBase(IBase *this)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)this + -0xc);
  android::RefBase::~RefBase((RefBase *)(this + iVar1 + 4));
  operator_delete(this + iVar1);
  return;
}



// cacao::Caps::~Caps()

void __thiscall cacao::Caps::~Caps(Caps *this)

{
  undefined8 uVar1;
  
  uVar1 = cacao::ObjectBase::~ObjectBase((ObjectBase *)this);
  cacao::ObjectBase::operator_delete((ObjectBase *)uVar1,(void *)((ulonglong)uVar1 >> 0x20));
  return;
}



// cacao::Caps::getClassName() const

undefined * cacao::Caps::getClassName(void)

{
  return &DAT_0001ea01;
}



// non-virtual thunk to cacao::Caps::getSerializedSize() const

undefined4 __thiscall cacao::Caps::getSerializedSize(void)

{
  return 0x262c;
}



// cacao::Caps::deserialize(cacao::ISerialize::SerializedData*)

undefined4 __thiscall cacao::Caps::deserialize(Caps *this,int param_1)

{
  int iVar1;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x188) != 0)) &&
     (*(int *)(param_1 + 0x18c) + 0x262cU <= *(uint *)(param_1 + 0x184))) {
    iVar1 = *(int *)(param_1 + 0x188) + *(int *)(param_1 + 0x18c);
    __aeabi_memcpy4(this + 8,iVar1,0xc0c);
    __aeabi_memcpy4(this + 0xc14,iVar1 + 0xc0c,0x604);
    __aeabi_memcpy4(this + 0x1218,iVar1 + 0x1210,0x808);
    *(undefined4 *)(this + 0x1a20) = *(undefined4 *)(iVar1 + 0x1a18);
    *(undefined4 *)(this + 0x1a24) = *(undefined4 *)(iVar1 + 0x1a1c);
    __aeabi_memcpy4(this + 0x1a28,iVar1 + 0x1a20,0xc0c);
    *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + 0x262c;
    return 0;
  }
  return 0xffffff99;
}



// non-virtual thunk to cacao::Caps::~Caps()

void __thiscall cacao::Caps::~Caps(Caps *this)

{
  cacao::ObjectBase::~ObjectBase((ObjectBase *)(this + -4));
  return;
}



// non-virtual thunk to cacao::Caps::~Caps()

void __thiscall cacao::Caps::~Caps(Caps *this)

{
  undefined8 uVar1;
  
  uVar1 = cacao::ObjectBase::~ObjectBase((ObjectBase *)(this + -4));
  cacao::ObjectBase::operator_delete((ObjectBase *)uVar1,(void *)((ulonglong)uVar1 >> 0x20));
  return;
}



// non-virtual thunk to cacao::Caps::serialize(cacao::ISerialize::SerializedData*) const

void __thiscall cacao::Caps::serialize(Caps *this,int param_1)

{
  serialize(this + -4,param_1);
  return;
}



// non-virtual thunk to cacao::Caps::deserialize(cacao::ISerialize::SerializedData*)

void __thiscall cacao::Caps::deserialize(Caps *this,int param_1)

{
  deserialize(this + -4,param_1);
  return;
}



// android::List<android::CacaoService::Client::Request*>::~List()

void __thiscall android::List<>::~List(List<> *this)

{
  List<> *pLVar1;
  
  pLVar1 = ~List(this);
  operator_delete(pLVar1);
  return;
}



// android::List<android::CacaoService::Client::Request*>::clear()

void __thiscall android::List<>::clear(List<> *this)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  
  pvVar2 = *(void **)(this + 4);
  pvVar1 = *(void **)((int)pvVar2 + 8);
  pvVar3 = pvVar2;
  if (*(void **)((int)pvVar2 + 8) != pvVar2) {
    do {
      pvVar3 = *(void **)((int)pvVar1 + 8);
      if (pvVar1 != (void *)0x0) {
        operator_delete(pvVar1);
        pvVar2 = *(void **)(this + 4);
      }
      pvVar1 = pvVar3;
    } while (pvVar3 != pvVar2);
  }
  *(void **)((int)pvVar3 + 4) = pvVar3;
  *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
  return;
}



// android::Vector<cacao::ImageBuf*>::~Vector()

void __thiscall android::Vector<>::~Vector(Vector<> *this)

{
  *(undefined ***)this = &PTR__Vector_1_000218b8;
  android::VectorImpl::finish_vector();
  android::VectorImpl::~VectorImpl((VectorImpl *)this);
  return;
}



// android::Vector<cacao::ImageBuf*>::~Vector()

void __thiscall android::Vector<>::~Vector(Vector<> *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__Vector_1_000218b8;
  android::VectorImpl::finish_vector();
  pvVar1 = (void *)android::VectorImpl::~VectorImpl((VectorImpl *)this);
  operator_delete(pvVar1);
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



// android::List<android::sp<android::CacaoService::Client> >::~List()

void __thiscall android::List<>::~List(List<> *this)

{
  List<> *pLVar1;
  
  pLVar1 = ~List(this);
  operator_delete(pLVar1);
  return;
}



// android::List<android::sp<android::CacaoService::Client> >::clear()

void __thiscall android::List<>::clear(List<> *this)

{
  sp<> *psVar1;
  sp<> *psVar2;
  sp<> *psVar3;
  
  psVar2 = *(sp<> **)(this + 4);
  psVar1 = *(sp<> **)(psVar2 + 8);
  psVar3 = psVar2;
  if (*(sp<> **)(psVar2 + 8) != psVar2) {
    do {
      psVar3 = *(sp<> **)(psVar1 + 8);
      if (psVar1 != (sp<> *)0x0) {
        psVar1 = sp<>::~sp(psVar1);
        operator_delete(psVar1);
        psVar2 = *(sp<> **)(this + 4);
      }
      psVar1 = psVar3;
    } while (psVar3 != psVar2);
  }
  *(sp<> **)(psVar3 + 4) = psVar3;
  *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
  return;
}



// std::__function::__func<android::CacaoService::getInterfaces()::$_0,
// std::allocator<android::CacaoService::getInterfaces()::$_0>, void
// (android::hardware::camera::common::V1_0::Status,
// android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao> const&)>::~__func()

void __thiscall std::__function::__func<>::~__func(__func<> *this)

{
  operator_delete(this);
  return;
}



// std::__function::__func<android::CacaoService::getInterfaces()::$_0,
// std::allocator<android::CacaoService::getInterfaces()::$_0>, void
// (android::hardware::camera::common::V1_0::Status,
// android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao> const&)>::__clone() const

void __thiscall std::__function::__func<>::__clone(__func<> *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = operator_new(0xc);
  uVar2 = *(undefined4 *)(this + 4);
  uVar3 = *(undefined4 *)(this + 8);
  *puVar1 = &PTR__AbstractUnwindCursor_1_000218f0;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  return;
}



// std::__function::__func<android::CacaoService::getInterfaces()::$_0,
// std::allocator<android::CacaoService::getInterfaces()::$_0>, void
// (android::hardware::camera::common::V1_0::Status,
// android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao>
// const&)>::__clone(std::__function::__base<void (android::hardware::camera::common::V1_0::Status,
// android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao> const&)>*) const

void __thiscall std::__function::__func<>::__clone(__func<> *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &PTR__AbstractUnwindCursor_1_000218f0;
  uVar1 = *(undefined4 *)(this + 8);
  param_1[1] = *(undefined4 *)(this + 4);
  param_1[2] = uVar1;
  return;
}



// std::__function::__func<android::CacaoService::getInterfaces()::$_0,
// std::allocator<android::CacaoService::getInterfaces()::$_0>, void
// (android::hardware::camera::common::V1_0::Status,
// android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao>
// const&)>::TEMPNAMEPLACEHOLDERVALUE(android::hardware::camera::common::V1_0::Status&&,
// android::sp<vendor::somc::hardware::camera::cacao::V3_0::ICacao> const&)

void __thiscall
std::__function::__func<>::operator()(__func<> *this,undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  sp<> asStack_1c [4];
  int local_18;
  
  local_18 = __stack_chk_guard;
  uVar1 = *param_1;
  android::sp<>::sp(asStack_1c,param_2);
  **(undefined4 **)(this + 4) = uVar1;
  android::sp<>::operator=(*(sp<> **)(this + 8),(undefined4 *)asStack_1c);
  android::sp<>::~sp((sp<> *)asStack_1c);
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// std::__function::__func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex
// const&, android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_1,
// std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_1>, void
// (vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps const&,
// vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::__clone() const

void __thiscall std::__function::__func<>::__clone(__func<> *this)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x10);
  *puVar1 = &PTR__AbstractUnwindCursor_1_00021914;
  *(undefined8 *)(puVar1 + 1) = *(undefined8 *)(this + 4);
  puVar1[3] = *(undefined4 *)(this + 0xc);
  return;
}



// std::__function::__func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex
// const&, android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_1,
// std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_1>, void
// (vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps const&,
// vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::__clone(std::__function::__base<void
// (vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps const&,
// vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>*) const

void __thiscall std::__function::__func<>::__clone(__func<> *this,undefined4 *param_1)

{
  undefined8 uVar1;
  
  *param_1 = &PTR__AbstractUnwindCursor_1_00021914;
  uVar1 = *(undefined8 *)(this + 4);
  param_1[3] = *(undefined4 *)(this + 0xc);
  *(undefined8 *)(param_1 + 1) = uVar1;
  return;
}



// std::__function::__func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex
// const&, android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_1,
// std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_1>, void
// (vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps const&,
// vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::TEMPNAMEPLACEHOLDERVALUE(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps
// const&, vendor::somc::hardware::camera::cacao::V3_0::ErrCode&&)

void __thiscall
std::__function::__func<>::operator()(__func<> *this,undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 local_138 [2];
  undefined4 local_130;
  void *local_128 [3];
  char local_11c;
  void *local_118 [3];
  char local_10c;
  undefined4 local_108;
  void *local_100 [3];
  char local_f4;
  void *local_f0 [3];
  char local_e4;
  undefined4 local_e0;
  void *local_d8 [3];
  char local_cc;
  void *local_c8 [3];
  char local_bc;
  undefined4 local_b8;
  undefined4 local_b0;
  void *local_a8 [3];
  char local_9c;
  void *local_98 [3];
  char local_8c;
  void *local_88 [3];
  char local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  void *local_60;
  char local_54;
  void *local_50;
  char local_44;
  void *local_38;
  char local_2c;
  void *local_28;
  char local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps::CacaoCaps((CacaoCaps *)local_138,param_1);
  if (*param_2 == 0) {
    vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps::operator=
              (*(CacaoCaps **)(this + 4),local_138);
    puVar1 = *(undefined4 **)(this + 8);
    *puVar1 = local_138[0];
    puVar1[2] = local_130;
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar1 + 4),(hidl_vec<> *)local_128);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar1 + 8),(hidl_vec<> *)local_118);
    puVar1[0xc] = local_108;
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar1 + 0xe),(hidl_vec<> *)local_100);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar1 + 0x12),(hidl_vec<> *)local_f0);
    puVar1[0x16] = local_e0;
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar1 + 0x18),(hidl_vec<> *)local_d8);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar1 + 0x1c),(hidl_vec<> *)local_c8);
    puVar1[0x20] = local_b8;
    puVar1[0x22] = local_b0;
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar1 + 0x24),(hidl_vec<> *)local_a8);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar1 + 0x28),(hidl_vec<> *)local_98);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar1 + 0x2c),(hidl_vec<> *)local_88);
    puVar1[0x30] = local_78;
    puVar1[0x31] = uStack_74;
  }
  else {
    __android_log_print(6,"CacaoService","hidl cacao interface getCaps error");
    **(undefined4 **)(this + 0xc) = 0xffffff91;
  }
  if ((local_1c != '\0') && (local_28 != (void *)0x0)) {
    operator_delete__(local_28);
  }
  local_28 = (void *)0x0;
  if ((local_2c != '\0') && (local_38 != (void *)0x0)) {
    operator_delete__(local_38);
  }
  local_38 = (void *)0x0;
  if ((local_44 != '\0') && (local_50 != (void *)0x0)) {
    operator_delete__(local_50);
  }
  local_50 = (void *)0x0;
  if ((local_54 != '\0') && (local_60 != (void *)0x0)) {
    operator_delete__(local_60);
  }
  local_60 = (void *)0x0;
  if ((local_7c != '\0') && (local_88[0] != (void *)0x0)) {
    operator_delete__(local_88[0]);
  }
  local_88[0] = (void *)0x0;
  if ((local_8c != '\0') && (local_98[0] != (void *)0x0)) {
    operator_delete__(local_98[0]);
  }
  local_98[0] = (void *)0x0;
  if ((local_9c != '\0') && (local_a8[0] != (void *)0x0)) {
    operator_delete__(local_a8[0]);
  }
  local_a8[0] = (void *)0x0;
  if ((local_bc != '\0') && (local_c8[0] != (void *)0x0)) {
    operator_delete__(local_c8[0]);
  }
  local_c8[0] = (void *)0x0;
  if ((local_cc != '\0') && (local_d8[0] != (void *)0x0)) {
    operator_delete__(local_d8[0]);
  }
  local_d8[0] = (void *)0x0;
  if ((local_e4 != '\0') && (local_f0[0] != (void *)0x0)) {
    operator_delete__(local_f0[0]);
  }
  local_f0[0] = (void *)0x0;
  if ((local_f4 != '\0') && (local_100[0] != (void *)0x0)) {
    operator_delete__(local_100[0]);
  }
  local_100[0] = (void *)0x0;
  if ((local_10c != '\0') && (local_118[0] != (void *)0x0)) {
    operator_delete__(local_118[0]);
  }
  local_118[0] = (void *)0x0;
  if ((local_11c != '\0') && (local_128[0] != (void *)0x0)) {
    operator_delete__(local_128[0]);
  }
  if (__stack_chk_guard == local_18) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps::CacaoCaps(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps
// const&)

CacaoCaps * __thiscall
vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps::CacaoCaps
          (CacaoCaps *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)this = *param_1;
  *(undefined4 *)(this + 8) = param_1[2];
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)(this + 0x10),(hidl_vec<> *)(param_1 + 4));
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)(this + 0x20),(hidl_vec<> *)(param_1 + 8));
  *(undefined4 *)(this + 0x30) = param_1[0xc];
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)(this + 0x38),(hidl_vec<> *)(param_1 + 0xe))
  ;
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0x48),(hidl_vec<> *)(param_1 + 0x12));
  *(undefined4 *)(this + 0x58) = param_1[0x16];
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0x60),(hidl_vec<> *)(param_1 + 0x18));
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0x70),(hidl_vec<> *)(param_1 + 0x1c));
  *(undefined4 *)(this + 0x80) = param_1[0x20];
  *(undefined4 *)(this + 0x88) = param_1[0x22];
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0x90),(hidl_vec<> *)(param_1 + 0x24));
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0xa0),(hidl_vec<> *)(param_1 + 0x28));
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0xb0),(hidl_vec<> *)(param_1 + 0x2c));
  uVar1 = param_1[0x31];
  *(undefined4 *)(this + 0xc0) = param_1[0x30];
  *(undefined4 *)(this + 0xc4) = uVar1;
  *(undefined4 *)(this + 200) = param_1[0x32];
  *(undefined4 *)(this + 0xd0) = param_1[0x34];
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0xd8),(hidl_vec<> *)(param_1 + 0x36));
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0xe8),(hidl_vec<> *)(param_1 + 0x3a));
  *(undefined4 *)(this + 0xf8) = param_1[0x3e];
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0x100),(hidl_vec<> *)(param_1 + 0x40));
  android::hardware::hidl_vec<>::hidl_vec
            ((hidl_vec<> *)(this + 0x110),(hidl_vec<> *)(param_1 + 0x44));
  return this;
}



// vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps::TEMPNAMEPLACEHOLDERVALUE(vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps
// const&)

CacaoCaps * __thiscall
vendor::somc::hardware::camera::cacao::V3_1::CacaoCaps::operator=
          (CacaoCaps *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)this = *param_1;
  *(undefined4 *)(this + 8) = param_1[2];
  android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(this + 0x10),(hidl_vec<> *)(param_1 + 4));
  android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(this + 0x20),(hidl_vec<> *)(param_1 + 8));
  *(undefined4 *)(this + 0x30) = param_1[0xc];
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0x38),(hidl_vec<> *)(param_1 + 0xe));
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0x48),(hidl_vec<> *)(param_1 + 0x12));
  *(undefined4 *)(this + 0x58) = param_1[0x16];
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0x60),(hidl_vec<> *)(param_1 + 0x18));
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0x70),(hidl_vec<> *)(param_1 + 0x1c));
  *(undefined4 *)(this + 0x80) = param_1[0x20];
  *(undefined4 *)(this + 0x88) = param_1[0x22];
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0x90),(hidl_vec<> *)(param_1 + 0x24));
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0xa0),(hidl_vec<> *)(param_1 + 0x28));
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0xb0),(hidl_vec<> *)(param_1 + 0x2c));
  uVar1 = param_1[0x31];
  *(undefined4 *)(this + 0xc0) = param_1[0x30];
  *(undefined4 *)(this + 0xc4) = uVar1;
  *(undefined4 *)(this + 200) = param_1[0x32];
  *(undefined4 *)(this + 0xd0) = param_1[0x34];
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0xd8),(hidl_vec<> *)(param_1 + 0x36));
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0xe8),(hidl_vec<> *)(param_1 + 0x3a));
  *(undefined4 *)(this + 0xf8) = param_1[0x3e];
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0x100),(hidl_vec<> *)(param_1 + 0x40));
  android::hardware::hidl_vec<>::operator=
            ((hidl_vec<> *)(this + 0x110),(hidl_vec<> *)(param_1 + 0x44));
  return this;
}



// android::hardware::hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize>::TEMPNAMEPLACEHOLDERVALUE(android::hardware::hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize>
// const&)

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



// void 
// android::hardware::hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize>::copyFrom<android::hardware::hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize>
// >(android::hardware::hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize> const&,
// unsigned int)

void __thiscall
android::hardware::hidl_vec<>::copyFrom<>(hidl_vec<> *this,int *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  this[0xc] = (hidl_vec<>)0x1;
  *(uint *)(this + 8) = param_2;
  if (param_2 == 0) {
    *(undefined4 *)this = 0;
    return;
  }
  uVar5 = (uint)((ulonglong)param_2 * 8);
  if ((int)((ulonglong)param_2 * 8 >> 0x20) != 0) {
    uVar5 = 0xffffffff;
  }
  puVar1 = operator_new__(uVar5);
  __aeabi_memclr8(puVar1,uVar5);
  *(undefined4 **)this = puVar1;
  uVar2 = ((undefined4 *)*param_1)[1];
  *puVar1 = *(undefined4 *)*param_1;
  puVar1[1] = uVar2;
  if (param_2 != 1) {
    uVar5 = 1;
    iVar3 = 8;
    do {
      iVar4 = *(int *)this;
      uVar5 = uVar5 + 1;
      uVar2 = *(undefined4 *)(*param_1 + iVar3 + 4);
      *(undefined4 *)(iVar4 + iVar3) = *(undefined4 *)(*param_1 + iVar3);
      iVar4 = iVar4 + iVar3;
      iVar3 = iVar3 + 8;
      *(undefined4 *)(iVar4 + 4) = uVar2;
    } while (uVar5 != param_2);
  }
  return;
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



// android::hardware::hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize>::hidl_vec(android::hardware::hidl_vec<vendor::somc::hardware::camera::cacao::V3_0::ImageSize>
// const&)

hidl_vec<> * __thiscall
android::hardware::hidl_vec<>::hidl_vec(hidl_vec<> *this,hidl_vec<> *param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  this[0xc] = (hidl_vec<>)0x1;
  operator=(this,param_1);
  return this;
}



// android::hardware::hidl_vec<unsigned int>::hidl_vec(android::hardware::hidl_vec<unsigned int>
// const&)

hidl_vec<> * __thiscall
android::hardware::hidl_vec<>::hidl_vec(hidl_vec<> *this,hidl_vec<> *param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  this[0xc] = (hidl_vec<>)0x1;
  operator=(this,param_1);
  return this;
}



// std::__function::__func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex
// const&, android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_2,
// std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_2>, void
// (vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps const&,
// vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::__clone() const

void __thiscall std::__function::__func<>::__clone(__func<> *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = operator_new(0xc);
  uVar2 = *(undefined4 *)(this + 4);
  uVar3 = *(undefined4 *)(this + 8);
  *puVar1 = &PTR__AbstractUnwindCursor_1_00021938;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  return;
}



// std::__function::__func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex
// const&, android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_2,
// std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_2>, void
// (vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps const&,
// vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::__clone(std::__function::__base<void
// (vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps const&,
// vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>*) const

void __thiscall std::__function::__func<>::__clone(__func<> *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &PTR__AbstractUnwindCursor_1_00021938;
  uVar1 = *(undefined4 *)(this + 8);
  param_1[1] = *(undefined4 *)(this + 4);
  param_1[2] = uVar1;
  return;
}



// std::__function::__func<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex
// const&, android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_2,
// std::allocator<android::CacaoService::getCaps(cacao::ProcessCtrlCaps::CameraIndex const&,
// android::sp<android::IMemory> const&, cacao::ISerialize::SerializedData)::$_2>, void
// (vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps const&,
// vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::TEMPNAMEPLACEHOLDERVALUE(vendor::somc::hardware::camera::cacao::V3_0::CacaoCaps
// const&, vendor::somc::hardware::camera::cacao::V3_0::ErrCode&&)

void __thiscall
std::__function::__func<>::operator()(__func<> *this,undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  void *local_e0 [3];
  char local_d4;
  void *local_d0 [3];
  char local_c4;
  undefined4 local_c0;
  void *local_b8 [3];
  char local_ac;
  void *local_a8 [3];
  char local_9c;
  undefined4 local_98;
  void *local_90 [3];
  char local_84;
  void *local_80 [3];
  char local_74;
  undefined4 local_70;
  undefined4 local_68;
  void *local_60 [3];
  char local_54;
  void *local_50 [3];
  char local_44;
  void *local_40 [3];
  char local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar1 = *param_1;
  uVar2 = param_1[2];
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)local_e0,(hidl_vec<> *)(param_1 + 4));
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)local_d0,(hidl_vec<> *)(param_1 + 8));
  local_c0 = param_1[0xc];
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)local_b8,(hidl_vec<> *)(param_1 + 0xe));
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)local_a8,(hidl_vec<> *)(param_1 + 0x12));
  local_98 = param_1[0x16];
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)local_90,(hidl_vec<> *)(param_1 + 0x18));
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)local_80,(hidl_vec<> *)(param_1 + 0x1c));
  local_70 = param_1[0x20];
  local_68 = param_1[0x22];
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)local_60,(hidl_vec<> *)(param_1 + 0x24));
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)local_50,(hidl_vec<> *)(param_1 + 0x28));
  android::hardware::hidl_vec<>::hidl_vec((hidl_vec<> *)local_40,(hidl_vec<> *)(param_1 + 0x2c));
  local_30 = param_1[0x30];
  uStack_2c = param_1[0x31];
  if (*param_2 == 0) {
    puVar3 = *(undefined4 **)(this + 4);
    *puVar3 = uVar1;
    puVar3[2] = uVar2;
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar3 + 4),(hidl_vec<> *)local_e0);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar3 + 8),(hidl_vec<> *)local_d0);
    puVar3[0xc] = local_c0;
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar3 + 0xe),(hidl_vec<> *)local_b8);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar3 + 0x12),(hidl_vec<> *)local_a8);
    puVar3[0x16] = local_98;
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar3 + 0x18),(hidl_vec<> *)local_90);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar3 + 0x1c),(hidl_vec<> *)local_80);
    puVar3[0x20] = local_70;
    puVar3[0x22] = local_68;
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar3 + 0x24),(hidl_vec<> *)local_60);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar3 + 0x28),(hidl_vec<> *)local_50);
    android::hardware::hidl_vec<>::operator=((hidl_vec<> *)(puVar3 + 0x2c),(hidl_vec<> *)local_40);
    puVar3[0x30] = local_30;
    puVar3[0x31] = uStack_2c;
  }
  else {
    __android_log_print(6,"CacaoService","hidl cacao interface getCaps error");
    **(undefined4 **)(this + 8) = 0xffffff91;
  }
  if ((local_34 != '\0') && (local_40[0] != (void *)0x0)) {
    operator_delete__(local_40[0]);
  }
  local_40[0] = (void *)0x0;
  if ((local_44 != '\0') && (local_50[0] != (void *)0x0)) {
    operator_delete__(local_50[0]);
  }
  local_50[0] = (void *)0x0;
  if ((local_54 != '\0') && (local_60[0] != (void *)0x0)) {
    operator_delete__(local_60[0]);
  }
  local_60[0] = (void *)0x0;
  if ((local_74 != '\0') && (local_80[0] != (void *)0x0)) {
    operator_delete__(local_80[0]);
  }
  local_80[0] = (void *)0x0;
  if ((local_84 != '\0') && (local_90[0] != (void *)0x0)) {
    operator_delete__(local_90[0]);
  }
  local_90[0] = (void *)0x0;
  if ((local_9c != '\0') && (local_a8[0] != (void *)0x0)) {
    operator_delete__(local_a8[0]);
  }
  local_a8[0] = (void *)0x0;
  if ((local_ac != '\0') && (local_b8[0] != (void *)0x0)) {
    operator_delete__(local_b8[0]);
  }
  local_b8[0] = (void *)0x0;
  if ((local_c4 != '\0') && (local_d0[0] != (void *)0x0)) {
    operator_delete__(local_d0[0]);
  }
  local_d0[0] = (void *)0x0;
  if ((local_d4 != '\0') && (local_e0[0] != (void *)0x0)) {
    operator_delete__(local_e0[0]);
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// std::__function::__func<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3,
// std::allocator<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3>, void (unsigned
// int, vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::__clone() const

void __thiscall std::__function::__func<>::__clone(__func<> *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = operator_new(0xc);
  uVar2 = *(undefined4 *)(this + 4);
  uVar3 = *(undefined4 *)(this + 8);
  *puVar1 = &PTR__AbstractUnwindCursor_1_0002195c;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  return;
}



// std::__function::__func<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3,
// std::allocator<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3>, void (unsigned
// int, vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::__clone(std::__function::__base<void
// (unsigned int, vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>*) const

void __thiscall std::__function::__func<>::__clone(__func<> *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &PTR__AbstractUnwindCursor_1_0002195c;
  uVar1 = *(undefined4 *)(this + 8);
  param_1[1] = *(undefined4 *)(this + 4);
  param_1[2] = uVar1;
  return;
}



// std::__function::__func<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3,
// std::allocator<android::CacaoService::getJpegBufferSize(cacao::ImageSize)::$_3>, void (unsigned
// int, vendor::somc::hardware::camera::cacao::V3_0::ErrCode)>::TEMPNAMEPLACEHOLDERVALUE(unsigned
// int&&, vendor::somc::hardware::camera::cacao::V3_0::ErrCode&&)

void __thiscall
std::__function::__func<>::operator()(__func<> *this,undefined4 *param_1,int *param_2)

{
  __func<> *p_Var1;
  undefined4 uVar2;
  
  if (*param_2 == 0) {
    uVar2 = *param_1;
    p_Var1 = this + 4;
  }
  else {
    __android_log_print(6,"CacaoService","hidl cacao interface getJpegBufferSize error");
    p_Var1 = this + 8;
    uVar2 = 0xffffff91;
  }
  **(undefined4 **)p_Var1 = uVar2;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::List<android::sp<android::CacaoService::Client>
// >::insert(android::List<android::sp<android::CacaoService::Client>
// >::_ListIterator<android::sp<android::CacaoService::Client>,
// android::List<android::sp<android::CacaoService::Client> >::NON_CONST_ITERATOR>,
// android::sp<android::CacaoService::Client> const&)

void __cdecl
android::List<>::insert(undefined4 *param_1,undefined4 param_2,int *param_3,int *param_4)

{
  sp<> *psVar1;
  int iVar2;
  
  psVar1 = operator_new(0xc);
  psVar1 = sp<>::sp(psVar1,param_4);
  iVar2 = *param_3;
  *(int *)(psVar1 + 8) = iVar2;
  *(undefined4 *)(psVar1 + 4) = *(undefined4 *)(iVar2 + 4);
  *(sp<> **)(*(int *)(iVar2 + 4) + 8) = psVar1;
  *(sp<> **)(*param_3 + 4) = psVar1;
  *param_1 = psVar1;
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// android::BinderService<android::CacaoService>::publish(bool, int)

undefined4 __cdecl android::BinderService<>::publish(undefined4 param_1,undefined4 param_2)

{
  CacaoService *this;
  undefined4 uVar1;
  code *pcVar2;
  sp<> asStack_34 [4];
  String16 aSStack_30 [4];
  int *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  android::defaultServiceManager();
  pcVar2 = *(code **)(*local_2c + 0x18);
  android::String16::String16(aSStack_30,"cacao");
  this = operator_new(0x48);
  CacaoService::CacaoService(this);
  sp<>::sp<>(asStack_34,(int *)this);
  uVar1 = (*pcVar2)(local_2c,aSStack_30,asStack_34,param_1,param_2);
  sp<>::~sp((sp<> *)asStack_34);
  android::String16::~String16(aSStack_30);
  sp<>::~sp((sp<> *)&local_2c);
  if (__stack_chk_guard == local_28) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// android::sp<android::IBinder>::sp<android::CacaoService>(android::CacaoService*)

sp<> * __thiscall android::sp<>::sp<>(sp<> *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1 + 1;
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



// cacao::ProcessFactoryInternal::createProcess()

void cacao::ProcessFactoryInternal::createProcess(void)

{
  cacao::ProcessCtrlGatewayFactory::create();
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// cacao::ProcessFactoryInternal::createMode(cacao::ISerialize::SerializedData*)

void __cdecl cacao::ProcessFactoryInternal::createMode(SerializedData *param_1)

{
  cacao::ProcessCtrlGatewayFactory::createMode(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// cacao::ProcessFactoryInternal::createParam(cacao::ISerialize::SerializedData*)

void __cdecl cacao::ProcessFactoryInternal::createParam(SerializedData *param_1)

{
  cacao::ProcessCtrlGatewayFactory::createParam(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// cacao::ProcessFactoryInternal::createResult(cacao::ISerialize::SerializedData*)

void __cdecl cacao::ProcessFactoryInternal::createResult(SerializedData *param_1)

{
  cacao::ProcessCtrlGatewayFactory::createResult(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// cacao::ProcessFactoryInternal::createConfig(unsigned int, cacao::ISerialize::SerializedData*)

void __cdecl cacao::ProcessFactoryInternal::createConfig(uint param_1,SerializedData *param_2)

{
  cacao::ProcessCtrlGatewayFactory::createConfig(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked
// cacao::ProcessFactoryInternal::createParam(android::sp<android::IBinder> const&,
// cacao::ISerialize::SerializedData*)

void __cdecl cacao::ProcessFactoryInternal::createParam(sp *param_1,SerializedData *param_2)

{
  cacao::ProcessCtrlGatewayFactory::createParam(param_1,param_2);
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
LAB_0001c0f4:
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
LAB_0001c136:
      unw_set_reg(param_1,0xd,local_2c);
      param_3 = uVar8;
      goto joined_r0x0001bff8;
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
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar8 << 0x1e) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,5,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar8 << 0x1d) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,6,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar8 << 0x1c) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,7,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar8 << 0x1b) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,8,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar8 << 0x1a) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,9,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar8 << 0x19) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,10,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((char)bVar1 < '\0') {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xb,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((bVar2 & 1) != 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xc,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar9 << 0x1e) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xd,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
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
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar9 << 0x1c) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xf,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if (!bVar10) {
            unw_set_reg(param_1,0xd,local_2c);
          }
        }
joined_r0x0001bff8:
        param_3 = param_3 + 2;
        goto joined_r0x0001bff8;
      }
      uVar6 = 9;
      goto switchD_0001bd00_caseD_b4;
    case 1:
      if ((uVar7 & 0xf | 2) != 0xf) {
        unw_get_reg(param_1,uVar7 & 0xf,&local_2c);
        goto LAB_0001c136;
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
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar7 * 0x2000000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,6,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((char)uVar7 < '\0') {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,7,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar7 * 0x800000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,8,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar7 * 0x400000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,9,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar7 * 0x200000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,10,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar7 * 0x100000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xb,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar7 * 0x80000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xc,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if ((int)(uVar7 * 0x40000) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xd,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
            bVar10 = true;
          }
          else {
            bVar10 = false;
          }
          if ((int)((uVar7 | uVar9 << 0xb) << 0x11) < 0) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xe,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if (0x7fffffff < (uint)(int)(short)uVar7) {
            uVar6 = *local_2c;
            local_2c = local_2c + 1;
            iVar5 = unw_set_reg(param_1,0xf,uVar6);
            if (iVar5 != 0) goto joined_r0x0001bff8;
          }
          if (!bVar10) goto LAB_0001c136;
        }
      }
joined_r0x0001bff8:
      if (param_4 <= param_3) goto switchD_0001bd00_caseD_b0;
      goto LAB_0001c0f4;
    case 3:
      uVar6 = 9;
      switch(uVar9) {
      case 0xb0:
        goto switchD_0001bd00_caseD_b0;
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
                if (iVar5 != 0) goto joined_r0x0001bff8;
              }
              if ((int)(uVar7 << 0x1e) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,1,uVar6);
                if (iVar5 != 0) goto joined_r0x0001bff8;
              }
              if ((int)(uVar7 << 0x1d) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,2,uVar6);
                if (iVar5 != 0) goto joined_r0x0001bff8;
              }
              if ((int)(uVar7 << 0x1c) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,3,uVar6);
                if (iVar5 != 0) goto joined_r0x0001bff8;
              }
              if ((int)(uVar7 << 0x1b) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,4,uVar6);
                if (iVar5 != 0) goto joined_r0x0001bff8;
              }
              if ((int)(uVar7 << 0x1a) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,5,uVar6);
                if (iVar5 != 0) goto joined_r0x0001bff8;
              }
              if ((int)(uVar7 << 0x19) < 0) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,6,uVar6);
                if (iVar5 != 0) goto joined_r0x0001bff8;
              }
              if (0x7fffffff < (uint)(int)(char)bVar2) {
                uVar6 = *local_2c;
                local_2c = local_2c + 1;
                iVar5 = unw_set_reg(param_1,7,uVar6);
                if (iVar5 != 0) goto joined_r0x0001bff8;
              }
              goto LAB_0001c136;
            }
            goto joined_r0x0001bff8;
          }
          goto switchD_0001bd00_caseD_b4;
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
            if (bVar10) goto switchD_0001bb7a_default;
          }
          unw_get_reg(param_1,0xd,&local_2c);
          local_2c = local_2c + uVar9 + 0x81;
          goto LAB_0001c136;
        }
        break;
      case 0xb3:
        uVar7 = 1;
        uVar8 = (uint)*(byte *)(param_2 + (uVar8 ^ 3));
        uVar8 = (uVar8 & 0xf) + 1 | (uVar8 & 0xf0) << 0xc;
LAB_0001bfea:
        _Unwind_VRS_Pop(param_1,1,uVar8,uVar7);
        goto joined_r0x0001bff8;
      case 0xb4:
      case 0xb5:
      case 0xb6:
      case 0xb7:
        goto switchD_0001bd00_caseD_b4;
      default:
        uVar9 = 1;
LAB_0001bf88:
        _Unwind_VRS_Pop(param_1,1,(uVar7 & 7) + 1 | 0x80000,uVar9);
        param_3 = uVar8;
        goto joined_r0x0001bff8;
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
          goto LAB_0001bfea;
        }
      }
      break;
    case 5:
      if (-1 < (int)(uVar9 << 0x1c)) {
        uVar9 = 5;
        goto LAB_0001bf88;
      }
    }
switchD_0001bb7a_default:
    uVar6 = 9;
    goto switchD_0001bd00_caseD_b4;
  }
LAB_0001c148:
  unw_get_reg(param_1,0xe,&local_2c);
  unw_set_reg(param_1,0xf,local_2c);
LAB_0001c15c:
  uVar6 = 8;
switchD_0001bd00_caseD_b4:
  if (__stack_chk_guard != local_28) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail(uVar6);
  }
  return;
switchD_0001bd00_caseD_b0:
  if (bVar4) goto LAB_0001c15c;
  goto LAB_0001c148;
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
      fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n",
              "_Unwind_VRS_Get_Internal","external/libunwind_llvm/src/Unwind-EHABI.cpp",0x35f,
              "unsupported register class");
      fflush((FILE *)android::IBinder::remoteBinder);
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
      fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n","_Unwind_VRS_Set",
              "external/libunwind_llvm/src/Unwind-EHABI.cpp",0x329,"unsupported register class");
      fflush((FILE *)android::IBinder::remoteBinder);
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
    goto LAB_0001c444;
    if ((param_3 & 0xffff) != 0) {
      uVar6 = param_3 >> 0x10;
      uVar4 = uVar6 + (param_3 & 0xffff);
      do {
        local_30 = (int *)*local_24;
        iStack_2c = local_24[1];
        local_24 = local_24 + 2;
        iVar2 = _Unwind_VRS_Set(param_1,1,uVar6,param_4,&local_30);
        if (iVar2 != 0) goto LAB_0001c444;
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
      fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n","_Unwind_VRS_Pop",
              "external/libunwind_llvm/src/Unwind-EHABI.cpp",0x3b9,"unsupported register class");
      fflush((FILE *)android::IBinder::remoteBinder);
                    // WARNING: Subroutine does not return
      abort();
    }
    if ((param_4 != 0) || (iVar2 = unw_get_reg(param_1,0xd,&local_30), iVar2 != 0)) {
LAB_0001c444:
      uVar5 = 2;
      goto LAB_0001c446;
    }
    if ((param_3 & 1) != 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x1e) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,1,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x1d) < 0) {
      uVar5 = 2;
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,2,iVar2);
      if (iVar2 != 0) goto LAB_0001c446;
    }
    if ((int)(param_3 << 0x1c) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,3,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x1b) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,4,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x1a) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,5,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x19) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,6,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((char)param_3 < '\0') {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,7,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x17) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,8,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x16) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,9,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x15) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,10,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x14) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0xb,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x13) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0xc,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((int)(param_3 << 0x12) < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0xd,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
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
      if (iVar2 != 0) goto LAB_0001c444;
    }
    if ((short)param_3 < 0) {
      iVar2 = *local_30;
      local_30 = local_30 + 1;
      iVar2 = unw_set_reg(param_1,0xf,iVar2);
      if (iVar2 != 0) goto LAB_0001c444;
    }
    piVar3 = local_30;
    if (bVar1) {
      uVar5 = 0;
      goto LAB_0001c446;
    }
  }
  iVar2 = unw_set_reg(param_1,0xd,piVar3);
  uVar5 = 0;
  if (iVar2 != 0) {
    uVar5 = 2;
  }
LAB_0001c446:
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
            goto LAB_0001c6d0;
          }
          if (iVar1 == 9) {
            uVar2 = 9;
            goto LAB_0001c6d0;
          }
          break;
        }
      }
      iVar1 = unw_get_proc_info(aiStack_878,(int)local_8a0);
    } while (iVar1 == 0);
  }
  uVar2 = 3;
LAB_0001c6d0:
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
    if (iVar1 != 0) goto LAB_0001c7e4;
    if (local_48 != (code *)0x0) {
      *(undefined4 *)(param_3 + 0x48) = local_54[0];
      *(undefined4 *)(param_3 + 0x4c) = local_34;
      *(undefined4 *)(param_3 + 0x50) = local_40;
      iVar1 = (*local_48)(uVar2 + 1,param_3,param_2);
      if (iVar1 == 7) {
        unw_get_reg(param_2,0xffffffff,&local_58);
        *(undefined4 *)(param_3 + 0x10) = local_58;
        unw_resume(param_2);
LAB_0001c7e4:
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
        goto LAB_0001c7e4;
      }
      if (local_2c == *(int *)(param_3 + 0x20)) {
        fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n","unwind_phase2",
                "external/libunwind_llvm/src/Unwind-EHABI.cpp",0x269,
                "during phase1 personality function said it would stop here, but now in phase2 it did not stop here"
               );
        fflush((FILE *)android::IBinder::remoteBinder);
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
  fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n","_Unwind_Resume",
          "external/libunwind_llvm/src/Unwind-EHABI.cpp",0x2cf,"_Unwind_Resume() can\'t return");
  fflush((FILE *)android::IBinder::remoteBinder);
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
                    // WARNING: Could not recover jumptable at 0x0001c8f4. Too many branches
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
  *param_1 = (int)&PTR__AbstractUnwindCursor_1_00021980;
  param_1[1] = (int)&DAT_00022004;
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
                    // WARNING: Could not recover jumptable at 0x0001caec. Too many branches
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
                    // WARNING: Could not recover jumptable at 0x0001cb24. Too many branches
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
  fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n","getRegister",
          "external/libunwind_llvm/src/Registers.hpp",0x618,"unsupported arm register");
  fflush((FILE *)android::IBinder::remoteBinder);
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
  fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n","setRegister",
          "external/libunwind_llvm/src/Registers.hpp",0x63b,"unsupported arm register");
  fflush((FILE *)android::IBinder::remoteBinder);
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
      fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n","getFloatRegister"
              ,"external/libunwind_llvm/src/Registers.hpp",0x70f,"Unknown ARM float register");
      fflush((FILE *)android::IBinder::remoteBinder);
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
      fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n","setFloatRegister"
              ,"external/libunwind_llvm/src/Registers.hpp",0x733,"Unknown ARM float register");
      fflush((FILE *)android::IBinder::remoteBinder);
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
  iVar2 = dl_iterate_phdr(0x1d1bd,&local_20);
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
  __vsnprintf_chk(param_1,param_3,0,param_2,&DAT_0001ec54,&stack0x00000000,&stack0x00000000);
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
LAB_0001d0b6:
    uVar12 = (uVar10 << 4) >> 0x1c;
    if (uVar12 == 2) {
      pcVar14 = (code *)0x1c615;
      bVar7 = true;
    }
    else {
      if (uVar12 != 1) {
        if (uVar12 != 0) {
          uVar9 = 0x35a;
          pcVar15 = "unknown personality routine";
          goto LAB_0001d170;
        }
        puVar4 = puVar6 + 1;
        if (bVar11) {
          puVar4 = (uint *)0x0;
        }
        pcVar14 = (code *)0x1c56d;
        goto LAB_0001d0d6;
      }
      pcVar14 = (code *)0x1c5c1;
      bVar7 = false;
    }
    uVar10 = (uVar10 << 8) >> 0x18;
    if ((bool)(uVar10 != 0 & bVar11)) {
      uVar9 = 0x361;
      pcVar15 = "index inlined table detected but pr function requires extra words";
LAB_0001d170:
      fprintf((FILE *)android::IBinder::remoteBinder,"libunwind: %s %s:%d - %s\n",
              "getInfoFromEHABISection","external/libunwind_llvm/src/UnwindCursor.hpp",uVar9,pcVar15
             );
      fflush((FILE *)android::IBinder::remoteBinder);
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
      goto LAB_0001d0b6;
    }
    bVar11 = false;
    pcVar14 = (code *)((uVar10 | (uVar10 & 0x40000000) << 1) + (int)puVar4);
    puVar4 = puVar4 + 1 + (puVar4[1] >> 0x18) + 1;
LAB_0001d0d6:
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
switchD_0001d254_caseD_ffffffff:
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
    goto switchD_0001d254_caseD_ffffffff;
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



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
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



Request * __thiscall android::CacaoService::Client::Request::~Request(Request *this)

{
  Request *pRVar1;
  
  pRVar1 = ~Request(this);
  return pRVar1;
}



Request * __thiscall android::CacaoService::Client::Request::~Request(Request *this)

{
  Request *pRVar1;
  
  pRVar1 = ~Request(this);
  return pRVar1;
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



void __thiscall android::ICacao::ICacao(ICacao *this)

{
  ICacao(this);
  return;
}



void __thiscall android::ICacao::ICacao(ICacao *this)

{
  ICacao(this);
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



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
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



void cacao::ProcessFactoryInternal::createProcess(void)

{
  createProcess();
  return;
}



void cacao::ProcessFactoryInternal::createProcess(void)

{
  createProcess();
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



void __thiscall android::CacaoService::Client::~Client(Client *this,int *param_1)

{
  ~Client(this,param_1);
  return;
}



void __thiscall android::CacaoService::Client::~Client(Client *this,int *param_1)

{
  ~Client(this,param_1);
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



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IPCThreadState::self(void)

{
  self();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IPCThreadState::self(void)

{
  self();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IPCThreadState::getCallingPid(void)

{
  getCallingPid();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::IPCThreadState::getCallingPid(void)

{
  getCallingPid();
  return;
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



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
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



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createMode(SerializedData *param_1)

{
  createMode(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createMode(SerializedData *param_1)

{
  createMode(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createConfig(uint param_1,SerializedData *param_2)

{
  createConfig(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createConfig(uint param_1,SerializedData *param_2)

{
  createConfig(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createParam(SerializedData *param_1)

{
  createParam(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createParam(SerializedData *param_1)

{
  createParam(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createResult(SerializedData *param_1)

{
  createResult(param_1);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createResult(SerializedData *param_1)

{
  createResult(param_1);
  return;
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



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createParam(sp *param_1,SerializedData *param_2)

{
  createParam(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl cacao::ProcessFactoryInternal::createParam(sp *param_1,SerializedData *param_2)

{
  createParam(param_1,param_2);
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



void __thiscall android::CacaoService::Client::allocMemory(Client *this,uint param_1)

{
  allocMemory(this,param_1);
  return;
}



void __thiscall android::CacaoService::Client::allocMemory(Client *this,uint param_1)

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



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::CacaoService::Client::makeSerializedData(int *param_1,int param_2)

{
  makeSerializedData(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::CacaoService::Client::makeSerializedData(int *param_1,int param_2)

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



void __thiscall android::ICacaoService::ICacaoService(ICacaoService *this)

{
  ICacaoService(this);
  return;
}



void __thiscall android::ICacaoService::ICacaoService(ICacaoService *this)

{
  ICacaoService(this);
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

void android::hardware::camera::provider::V2_4::ICameraProvider::registerForNotifications
               (string *param_1,sp *param_2)

{
  registerForNotifications(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::camera::provider::V2_4::ICameraProvider::registerForNotifications
               (string *param_1,sp *param_2)

{
  registerForNotifications(param_1,param_2);
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



void __thiscall android::CacaoService::~CacaoService(CacaoService *this,int *param_1)

{
  ~CacaoService(this,param_1);
  return;
}



void __thiscall android::CacaoService::~CacaoService(CacaoService *this,int *param_1)

{
  ~CacaoService(this,param_1);
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

void android::hardware::Status::description(void)

{
  description();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::Status::description(void)

{
  description();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::details::return_status::assertOk(void)

{
  assertOk();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::hardware::details::return_status::assertOk(void)

{
  assertOk();
  return;
}



void __thiscall
android::hardware::details::return_status::operator=(return_status *this,return_status *param_1)

{
  operator=(this,param_1);
  return;
}



void __thiscall
android::hardware::details::return_status::operator=(return_status *this,return_status *param_1)

{
  operator=(this,param_1);
  return;
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



// WARNING: Unknown calling convention -- yet parameter storage is locked

void vendor::somc::hardware::camera::cacao::V3_1::ICacao::castFrom(sp *param_1,bool param_2)

{
  castFrom(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void vendor::somc::hardware::camera::cacao::V3_1::ICacao::castFrom(sp *param_1,bool param_2)

{
  castFrom(param_1,param_2);
  return;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
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



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
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



// WARNING: Unknown calling convention -- yet parameter storage is locked

void vendor::somc::hardware::camera::provider::V1_0::IVendorSomcCameraProvider::getService
               (string *param_1,bool param_2)

{
  getService(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void vendor::somc::hardware::camera::provider::V1_0::IVendorSomcCameraProvider::getService
               (string *param_1,bool param_2)

{
  getService(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void std::__basic_string_common<true>::__throw_length_error(void)

{
  __throw_length_error();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void std::__basic_string_common<true>::__throw_length_error(void)

{
  __throw_length_error();
  return;
}



void __thiscall android::CacaoService::getInterfaces(CacaoService *this)

{
  getInterfaces(this);
  return;
}



void __thiscall android::CacaoService::getInterfaces(CacaoService *this)

{
  getInterfaces(this);
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



Client * __thiscall
android::CacaoService::Client::Client(Client *this,int *param_1,int *param_2,undefined4 param_3)

{
  Client *pCVar1;
  
  pCVar1 = Client(this,param_1,param_2,param_3);
  return pCVar1;
}



Client * __thiscall
android::CacaoService::Client::Client(Client *this,int *param_1,int *param_2,undefined4 param_3)

{
  Client *pCVar1;
  
  pCVar1 = Client(this,param_1,param_2,param_3);
  return pCVar1;
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



void __thiscall cacao::ObjectBase::~ObjectBase(ObjectBase *this)

{
  ~ObjectBase(this);
  return;
}



void __thiscall cacao::ObjectBase::~ObjectBase(ObjectBase *this)

{
  ~ObjectBase(this);
  return;
}



void __aeabi_memcpy4(void)

{
  __aeabi_memcpy4();
  return;
}



void __aeabi_memcpy4(void)

{
  __aeabi_memcpy4();
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



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::checkCallingPermission(String16 *param_1)

{
  checkCallingPermission(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::checkCallingPermission(String16 *param_1)

{
  checkCallingPermission(param_1);
  return;
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



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BnCacaoService::onTransact(uint param_1,Parcel *param_2,Parcel *param_3,uint param_4)

{
  onTransact(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::BnCacaoService::onTransact(uint param_1,Parcel *param_2,Parcel *param_3,uint param_4)

{
  onTransact(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::wp<>::promote(int *param_1,int *param_2)

{
  promote(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl android::wp<>::promote(int *param_1,int *param_2)

{
  promote(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::weakref_type::attemptIncStrong(void *param_1)

{
  attemptIncStrong(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::RefBase::weakref_type::attemptIncStrong(void *param_1)

{
  attemptIncStrong(param_1);
  return;
}



void __thiscall android::CacaoService::Client::serviceDied(Client *this)

{
  serviceDied(this);
  return;
}



void __thiscall android::CacaoService::Client::serviceDied(Client *this)

{
  serviceDied(this);
  return;
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



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl
android::CacaoService::serviceDied(int param_1,undefined4 param_2_00,int param_3,int param_4)

{
  serviceDied(param_1,param_2_00,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention: __cdecl -- yet parameter storage is locked

void __cdecl
android::CacaoService::serviceDied(int param_1,undefined4 param_2_00,int param_3,int param_4)

{
  serviceDied(param_1,param_2_00,param_3,param_4);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ICacao::getInterfaceDescriptor(void)

{
  getInterfaceDescriptor();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ICacao::getInterfaceDescriptor(void)

{
  getInterfaceDescriptor();
  return;
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



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ICacaoService::getInterfaceDescriptor(void)

{
  getInterfaceDescriptor();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void android::ICacaoService::getInterfaceDescriptor(void)

{
  getInterfaceDescriptor();
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



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
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



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
}



sp<> * __thiscall android::sp<>::sp(sp<> *this,int *param_1)

{
  sp<> *psVar1;
  
  psVar1 = sp(this,param_1);
  return psVar1;
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



CacaoService * __thiscall android::CacaoService::CacaoService(CacaoService *this)

{
  CacaoService *pCVar1;
  
  pCVar1 = CacaoService(this);
  return pCVar1;
}



CacaoService * __thiscall android::CacaoService::CacaoService(CacaoService *this)

{
  CacaoService *pCVar1;
  
  pCVar1 = CacaoService(this);
  return pCVar1;
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

void cacao::ProcessCtrlGatewayFactory::create(void)

{
  create();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::create(void)

{
  create();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createMode(SerializedData *param_1)

{
  createMode(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createMode(SerializedData *param_1)

{
  createMode(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createParam(SerializedData *param_1)

{
  createParam(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createParam(SerializedData *param_1)

{
  createParam(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createResult(SerializedData *param_1)

{
  createResult(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createResult(SerializedData *param_1)

{
  createResult(param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createConfig(uint param_1,SerializedData *param_2)

{
  createConfig(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createConfig(uint param_1,SerializedData *param_2)

{
  createConfig(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createParam(sp *param_1,SerializedData *param_2)

{
  createParam(param_1,param_2);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void cacao::ProcessCtrlGatewayFactory::createParam(sp *param_1,SerializedData *param_2)

{
  createParam(param_1,param_2);
  return;
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
  *(undefined4 *)(param_1 + 0x30) = 0xffffe7c0;
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
  *(undefined4 *)(param_1 + 0x30) = 0xffffe7c0;
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


