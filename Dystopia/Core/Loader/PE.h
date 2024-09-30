#pragma once
#include <bitset>
#include <variant>
#include "Core/Miscellaneous/Types.h"

using PhysicalAddress = ULONG;
using VirtualSize = ULONG;

constexpr UCHAR IMAGE_NUMBEROF_DIRECTORY_ENTRIES = 16;
constexpr USHORT IMAGE_DOS_MAGIC = 0x5A4D;

struct IMAGE_DOS_HEADER {
	USHORT   e_magic;                     // Magic number
	USHORT   e_cblp;                      // bytes on last page of file
	USHORT   e_cp;                        // Pages in file
	USHORT   e_crlc;                      // Relocations
	USHORT   e_cparhdr;                   // Size of header in paragraphs
	USHORT   e_minalloc;                  // Minimum extra paragraphs needed
	USHORT   e_maxalloc;                  // Maximum extra paragraphs needed
	USHORT   e_ss;                        // Initial (relative) SS value
	USHORT   e_sp;                        // Initial SP value
	USHORT   e_csum;                      // Checksum
	USHORT   e_ip;                        // Initial IP value
	USHORT   e_cs;                        // Initial (relative) CS value
	USHORT   e_lfarlc;                    // File address of relocation table
	USHORT   e_ovno;                      // Overlay number
	USHORT   e_res[4];                    // Reserved USHORTs
	USHORT   e_oemid;                     // OEM identifier (for e_oeminfo)
	USHORT   e_oeminfo;                   // OEM information; e_oemid specific
	USHORT   e_res2[10];                  // Reserved USHORTs
	USHORT   e_lfanew;                   // File address of new exe header
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

// Magic number
constexpr UCHAR PEMagic1 = 'P';
constexpr UCHAR PEMagic2 = 'E';
constexpr UCHAR PEMagic3 = '/';
constexpr UCHAR PEMagic4 = '0';
constexpr UCHAR PEMagic5 = '/';
constexpr UCHAR PEMagic6 = '0';

constexpr ULONG IMAGE_NT_SIGNATURE = 0x4550; // Magic USHORT to define file type - 0x00004550

struct IMAGE_FILE_HEADER {
	USHORT Machine; // The number that identifies the type of target machine.
	USHORT NumberOfSections; // The number of sections. This indicates the size of the section table, as of 2024 this number in Windows is limited to 96
	ULONG TimeDateStamp; // indicates when the file was created
	ULONG PointerToSymbolTable; // This value should be zero for an image because COFF debugging information is deprecated. 
	ULONG NumberOfSymbols; // The number of entries in the symbol table. This data can be used to locate the string table, which immediately follows the symbol table. should be 0 as the above field
	USHORT SizeOfOptionalHeader; // The size of the optional header, which is required for executable files but not for object files. This value should be zero for an object file.
	USHORT Characteristics; // The flags that indicate the attributes of the file
} IMAGE_FILE_HEADER, * PIMAGE_FILE_HEADER;

// MachineTypes 
constexpr USHORT IMAGE_FILE_MACHINE_UNKNOWN = 0x0;
constexpr USHORT IMAGE_FILE_MACHINE_ALPHA64 = 0x284;
constexpr USHORT IMAGE_FILE_MACHINE_AM33 = 0x1d3;
constexpr USHORT IMAGE_FILE_MACHINE_AMD64 = 0x8664;
constexpr USHORT IMAGE_FILE_MACHINE_ARM = 0x1c0;
constexpr USHORT IMAGE_FILE_MACHINE_ARM64 = 0xaa64;
constexpr USHORT IMAGE_FILE_MACHINE_ARMNT = 0x1c4;
constexpr USHORT IMAGE_FILE_MACHINE_AXP64 = 0x284;
constexpr USHORT IMAGE_FILE_MACHINE_EBC = 0xebc;
constexpr USHORT IMAGE_FILE_MACHINE_I386 = 0x14c;
constexpr USHORT IMAGE_FILE_MACHINE_IA64 = 0x200;
constexpr USHORT IMAGE_FILE_MACHINE_LOONGARCH32 = 0x6232;
constexpr USHORT IMAGE_FILE_MACHINE_LOONGARCH64 = 0x6264;
constexpr USHORT IMAGE_FILE_MACHINE_M32R = 0x9041;
constexpr USHORT IMAGE_FILE_MACHINE_MIPS16 = 0x266;
constexpr USHORT IMAGE_FILE_MACHINE_MIPSFPU = 0x366;
constexpr USHORT IMAGE_FILE_MACHINE_MIPSFPU16 = 0x466;
constexpr USHORT IMAGE_FILE_MACHINE_POWERPC = 0x1f0;
constexpr USHORT IMAGE_FILE_MACHINE_POWERPCFP = 0x1f1;
constexpr USHORT IMAGE_FILE_MACHINE_R4000 = 0x166;
constexpr USHORT IMAGE_FILE_MACHINE_RISCV32 = 0x5032;
constexpr USHORT IMAGE_FILE_MACHINE_RISCV64 = 0x5064;
constexpr USHORT IMAGE_FILE_MACHINE_RISCV128 = 0x5128;
constexpr USHORT IMAGE_FILE_MACHINE_SH3 = 0x1a2;
constexpr USHORT IMAGE_FILE_MACHINE_SH3DSP = 0x1a3;
constexpr USHORT IMAGE_FILE_MACHINE_SH4 = 0x1a6;
constexpr USHORT IMAGE_FILE_MACHINE_SH5 = 0x1a8;
constexpr USHORT IMAGE_FILE_MACHINE_THUMB = 0x1c2;
constexpr USHORT IMAGE_FILE_MACHINE_WCEMIPSV2 = 0x169;


// Characteristics
constexpr USHORT IMAGE_FILE_RELOCS_STRIPPED = 0x0001;
constexpr USHORT IMAGE_FILE_EXECUTABLE_IMAGE = 0x0002;
constexpr USHORT IMAGE_FILE_LINE_NUMS_STRIPPED = 0x0004; // COFF line numbers have been removed. This flag is deprecated and should be zero. 
constexpr USHORT IMAGE_FILE_LOCAL_SYMS_STRIPPED = 0x0008; // COFF symbol table entries for local symbols have been removed. This flag is deprecated and should be zero. 
constexpr USHORT IMAGE_FILE_AGGRESSIVE_WS_TRIM = 0x0010; // Obsolete. Aggressively trim working set. This flag is deprecated for Windows 2000 and later and must be zero. 
constexpr USHORT IMAGE_FILE_LARGE_ADDRESS_AWARE = 0x0020; // Application can handle > 2-GB addresses. 
constexpr USHORT RESERVED_FLAG = 0x0040; // reserved for future use
constexpr USHORT IMAGE_FILE_UCHARS_REVERSED_LO = 0x0080;
constexpr USHORT IMAGE_FILE_32BIT_MACHINE = 0x0100; // Machine is based on a 32-bit word architecture.
constexpr USHORT IMAGE_FILE_DEBUG_STRIPPED = 0x0200;
constexpr USHORT IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP = 0x0400;
constexpr USHORT IMAGE_FILE_NET_RUN_FROM_SWAP = 0x0800;
constexpr USHORT IMAGE_FILE_SYSTEM = 0x1000;
constexpr USHORT IMAGE_FILE_DLL = 0x2000;
constexpr USHORT IMAGE_FILE_UP_SYSTEM_ONLY = 0x4000;
constexpr USHORT IMAGE_FILE_UCHARS_REVERSED_HI = 0x8000; // Big endian : the MSB precedes the LSB in memory.This flag is deprecated and should be zero.


// ImageFileState 
constexpr USHORT IMAGE_NT_OPTIONAL_HDR32_MAGIC = 0x10B; // normal 32 bit exe
constexpr USHORT IMAGE_NT_OPTIONAL_HDR64_MAGIC = 0x20B; // 64 bit exe
constexpr USHORT IMAGE_ROM_OPTIONAL_HDR_MAGIC = 0x107; // ROM image


typedef struct _IMAGE_DATA_DIRECTORY {
	ULONG VirtualAddress; // RVA of the table
	ULONG Size; // size in UCHARs
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct _IMAGE_OPTIONAL_HEADER64 {
	USHORT Magic; // state of the image file. The most common number is 0x10B, which identifies it as a normal executable file. 0x107 - ROM image, and 0x20B - PE32+ executable. 
	UCHAR MajorLinkerVersion;
	UCHAR MinorLinkerVersion;
	ULONG SizeOfCode; // The size of the code (text) section, or the sum of all code sections if there are multiple sections. 
	ULONG SizeOfInitializedData;
	ULONG SizeOfUninitializedData; // The size of the uninitialized data section(BSS), or the sum of all such sections if there are multiple BSS sections.
	ULONG AddressOfEntryPoint; // The address of the entry point relative to the image base when the executable file is loaded into memory. If no entry point is present, this field must be 0.                         
	ULONG BaseOfCode; // The address that is relative to the image base of the beginning - of - code section when it is loaded into memory.
	ULONG BaseOfData; // The address that is relative to the image base of the beginning-of-data section when it is loaded into memory. This field is absent to PE32+ format
	ULONG ImageBase; // The preferred address of the first byte of image when loaded into memory; must be a multiple of 64 K.The default for Windows NT is 0x00400000. Might be a good idea to define it as bit-field
	ULONG SectionAlignment;
	ULONG FileAlignment;
	USHORT MajorOperatingSystemVersion;
	USHORT MinorOperatingSystemVersion;
	USHORT MajorImageVersion;
	USHORT MinorImageVersion;
	USHORT MajorSubsystemVersion;
	USHORT MinorSubsystemVersion;
	ULONG Win32VersionValue; // Reserved, must be 0 
	ULONG SizeOfImage;
	ULONG SizeOfHeaders;
	ULONG CheckSum;
	USHORT Subsystem;
	USHORT DllCharacteristics;
	ULONG SizeOfStackReserve;
	ULONG SizeOfStackCommit;
	ULONG SizeOfHeapReserve;
	ULONG SizeOfHeapCommit;
	ULONG LoaderFlags; // Reserved
	ULONG NumberOfRvaAndSizes; // The number of data-directory entries in the remainder of the optional header. Each describes a location and size. 
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER, * PIMAGE_OPTIONAL_HEADER;

// Data directories
constexpr UCHAR ExportTable = 0; // The export table address and size. For more information see .edata Section (Image Only). 
constexpr UCHAR ImportTable = 1; // The import table address and size. For more information, see The .idata Section.
constexpr UCHAR ResourceTable = 2; // The resource table address and size. For more information, see The .rsrc Section.
constexpr UCHAR ExceptionTable = 3; // The exception table address and size. For more information, see The .pdata Section. 
constexpr UCHAR CertificateTable = 4; // The attribute certificate table address and size. For more information, see The Attribute Certificate Table (Image Only). 
constexpr UCHAR BaseRelocationTable = 5; // The base relocation table address and size. For more information, see The .reloc Section (Image Only).
constexpr UCHAR Debug = 6; // The debug data starting address and size. For more information, see The .debug Section.
constexpr UCHAR Architecture = 7; // Reserved, must be 0 
constexpr UCHAR GlobalPtr = 8; // The RVA of the value to be stored in the global pointer register. The size member of this structure must be set to zero. 
constexpr UCHAR TLSTable = 9; // The thread local storage (TLS) table address and size. For more information, see The .tls Section.
constexpr UCHAR LoadConfigTable = 10; // The load configuration table address and size. For more information, see The Load Configuration Structure (Image Only).
constexpr UCHAR BoundImport = 11; // The bound import table address and size.
constexpr UCHAR IAT = 12; // The import address table address and size. For more information, see Import Address Table.
constexpr UCHAR DelayImportDescriptor = 13; // The delay import descriptor address and size. For more information, see Delay-Load Import Tables (Image Only).
constexpr UCHAR CLRRuntimeHeader = 14; // The CLR runtime header address and size. For more information, see The .cormeta Section (Object Only).


struct PE32OptionalHeader64 {
	// Standard fields
	USHORT Magic; // state of the image file. The most common number is 0x10B, which identifies it as a normal executable file. 0x107 - ROM image, and 0x20B - PE32+ executable. 
	UCHAR MajorLinkerVersion;
	UCHAR MinorLinkerVersion;
	ULONG SizeOfCode; // The size of the code (text) section, or the sum of all code sections if there are multiple sections. 
	ULONG SizeOfInitializedData;
	ULONG SizeOfUninitializedData; // The size of the uninitialized data section(BSS), or the sum of all such sections if there are multiple BSS sections.
	ULONG AddressOfEntryPoint; // The address of the entry point relative to the image base when the executable file is loaded into memory. If no entry point is present, this field must be 0.                         
	ULONG BaseOfCode; // The address that is relative to the image base of the beginning - of - code section when it is loaded into memory.
	
	// Windows-Specific Fields
	USHORT ImageBase; // The preferred address of the first byte of image when loaded into memory; must be a multiple of 64 K.The default for Windows NT is 0x00400000. Might be a good idea to define it as bit-field
	ULONG SectionAlignment; // The alignment (in bytes) of sections when they are loaded into memory. It must be greater than or equal to FileAlignment. The default is the page size for the architecture. 
	ULONG FileAlignment; // The alignment factor (in bytess) that is used to align the raw data of sections in the image file. The value should be a power of 2 between 512 and 64 K, inclusive. The default is 512. If the SectionAlignment is less than the architecture's page size, then FileAlignment must match SectionAlignment. 
	USHORT MajorOperatingSystemVersion;
	USHORT MinorOperatingSystemVersion;
	USHORT MajorImageVersion;
	USHORT MinorImageVersion;
	USHORT MajorSubsystemVersion;
	USHORT MinorSubsystemVersion;
	ULONG Win32VersionValue; // Reserved, must be 0 
	ULONG SizeOfImage;
	ULONG SizeOfHeaders;
	ULONG CheckSum;
	USHORT Subsystem;
	USHORT DllCharacteristics; 
	USHORT SizeOfStackReserve;
	USHORT SizeOfStackCommit;
	USHORT SizeOfHeapReserve;
	USHORT SizeOfHeapCommit;
	ULONG LoaderFlags; // Reserved
	ULONG NumberOfRvaAndSizes; // The number of data-directory entries in the remainder of the optional header. Each describes a location and size. 
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER_64, * PIMAGE_OPTIONAL_HEADER_64;

constexpr UCHAR IMAGE_SIZEOF_SHORT_NAME = 8;

struct SectionTable {
	UCHAR NAME[IMAGE_SIZEOF_SHORT_NAME]; // An 8 - byte, null - padded UTF - 8 encoded string.If the string is exactly 8 characters long, there is no terminating null.For longer names, this field contains a slash(/ ) that is followed by an ASCII representation of a decimal number that is an offset into the string table.
	std::variant<PhysicalAddress, VirtualSize> Misc; // VirtualSize - The total size of the section when loaded into memory.If this value is greater than SizeOfRawData, the section is zero - padded.This field is valid only for executable images and should be set to zero for object files.
	ULONG VirtualAddress; // For executable images, the address of the first byte of the section relative to the image base when the section is loaded into memory. For object files, this field is the address of the first byte before relocation is applied; for simplicity, compilers should set this to zero. Otherwise, it is an arbitrary value that is subtracted from offsets during relocation. 
	ULONG SizeOfRawData; // The size of the section (for object files) or the size of the initialized data on disk (for image files). For executable images, this must be a multiple of FileAlignment from the optional header. If this is less than VirtualSize, the remainder of the section is zero-filled. Because the SizeOfRawData field is rounded but the VirtualSize field is not, it is possible for SizeOfRawData to be greater than VirtualSize as well. When a section contains only uninitialized data, this field should be zero. 
	ULONG PointerToRawData; // The file pointer to the first page of the section within the COFF file. For executable images, this must be a multiple of FileAlignment from the optional header. For object files, the value should be aligned on a 4-byte boundary for best performance. When a section contains only uninitialized data, this field should be zero. 
	ULONG PointerToRelocations; // The file pointer to the beginning of relocation entries for the section. This is set to zero for executable images or if there are no relocations. 
	ULONG PointerToLineNumbers; // The file pointer to the beginning of line-number entries for the section. This is set to zero if there are no COFF line numbers. This value should be zero for an image because COFF debugging information is deprecated. 
	USHORT NumberOfRelocations; // The number of relocation entries for the section. This is set to zero for executable images. 
	USHORT NumberOfLineNumbers; // The number of line-number entries for the section. This value should be zero for an image because COFF debugging information is deprecated. 
	ULONG Characteristics; // The flags that describe the characteristics of the section. For more information, see Section Flags.
} IMAGE_SECTION_HEADER, * PIMAGE_SECTION_HEADER;

// SectionFlags 
constexpr USHORT ReservedField1 = 0x00000000;
constexpr USHORT ReservedField2 = 0x00000001;
constexpr USHORT ReservedField3 = 0x00000002;
constexpr USHORT ReservedField4 = 0x00000004;
constexpr USHORT IMAGE_SCN_TYPE_NO_PAD = 0x00000008; // The section should not be padded to the next boundary. This flag is obsolete and is replaced by IMAGE_SCN_ALIGN_1UCHARS. This is valid only for object files. 
constexpr USHORT ReservedField5 = 0x00000010;
constexpr USHORT IMAGE_SCN_CNT_CODE = 0x00000020; // The section contains executable code. 
constexpr USHORT IMAGE_SCN_CNT_INITIALIZED_DATA = 0x00000040; // The section contains initialized data. 
constexpr USHORT IMAGE_SCN_CNT_UNINITIALIZED_DATA = 0x00000080; // The section contains uninitialized data. 
constexpr USHORT IMAGE_SCN_LNK_OTHER = 0x00000100; // Reserved for future use. 
constexpr USHORT IMAGE_SCN_LNK_INFO = 0x00000200; // The section contains comments or other information. The .drectve section has this type. This is valid for object files only. 
constexpr USHORT ReservedField6 = 0x00000400;
constexpr USHORT IMAGE_SCN_LNK_REMOVE = 0x00000800; // The section will not become part of the image. This is valid only for object files. 
constexpr USHORT IMAGE_SCN_LNK_COMDAT = 0x00001000; // The section contains COMDAT data. For more information; see COMDAT Sections (Object Only). This is valid only for object files. 
constexpr USHORT IMAGE_SCN_GPREL = 0x00008000; // The section contains data referenced through the global pointer (GP). 
constexpr ULONG IMAGE_SCN_MEM_PURGEABLE = 0x00020000; // Reserved for future use
constexpr ULONG IMAGE_SCN_MEM_16BIT = 0x00020000; // Reserved for future use
constexpr ULONG IMAGE_SCN_MEM_LOCKED = 0x00040000; // Reserved for future use
constexpr ULONG IMAGE_SCN_MEM_PRELOAD = 0x00080000; // Reserved for future use
constexpr ULONG IMAGE_SCN_ALIGN_1UCHARS = 0x00100000; // Align data on a 1-byte boundary. Valid only for object files. 
constexpr ULONG IMAGE_SCN_ALIGN_2UCHARS = 0x00200000; // Align data on a 2-byte boundary. Valid only for object files. 
constexpr ULONG IMAGE_SCN_ALIGN_4UCHARS = 0x00300000;
constexpr ULONG IMAGE_SCN_ALIGN_8UCHARS = 0x00400000;
constexpr ULONG IMAGE_SCN_ALIGN_16UCHARS = 0x00500000;
constexpr ULONG IMAGE_SCN_ALIGN_32UCHARS = 0x00600000;
constexpr ULONG IMAGE_SCN_ALIGN_64UCHARS = 0x00700000;
constexpr ULONG IMAGE_SCN_ALIGN_128UCHARS = 0x00800000;
constexpr ULONG IMAGE_SCN_ALIGN_256UCHARS = 0x00900000;
constexpr ULONG IMAGE_SCN_ALIGN_512UCHARS = 0x00A00000;
constexpr ULONG IMAGE_SCN_ALIGN_1024UCHARS = 0x00B00000;
constexpr ULONG IMAGE_SCN_ALIGN_2048UCHARS = 0x00C00000;
constexpr ULONG IMAGE_SCN_ALIGN_4096UCHARS = 0x00D00000;
constexpr ULONG IMAGE_SCN_LNK_NRELOC_OVFL = 0x01000000; // The section contains extended relocations. 
constexpr ULONG IMAGE_SCN_MEM_DISCARDABLE = 0x02000000; // The section can be discarded as needed. 
constexpr ULONG IMAGE_SCN_MEM_NOT_CACHED = 0x04000000; // The section cannot be cached. 
constexpr ULONG IMAGE_SCN_MEM_NOT_PAGED = 0x08000000; // The section is not pageable. 
constexpr ULONG IMAGE_SCN_MEM_SHARED = 0x10000000; // The section can be shared in memory. 
constexpr ULONG IMAGE_SCN_MEM_EXECUTE = 0x20000000; // The section can be executed as code.
constexpr ULONG IMAGE_SCN_MEM_READ = 0x40000000; // The section can be read. 
constexpr ULONG IMAGE_SCN_MEM_WRITE = 0x80000000; // The section can be written to.


// WindowsSubsystem {
constexpr UCHAR IMAGE_SUBSYSTEM_UNKNOWN = 0; // An unknown subsystem 
constexpr UCHAR IMAGE_SUBSYSTEM_NATIVE = 1; // Device drivers and native Windows processes 
constexpr UCHAR IMAGE_SUBSYSTEM_WINDOWS_GUI = 2; // The Windows graphical user interface (GUI) subsystem 
constexpr UCHAR IMAGE_SUBSYSTEM_WINDOWS_CUI = 3; // The Windows character subsystem 
constexpr UCHAR IMAGE_SUBSYSTEM_OS2_CUI = 5; // The OS / 2 character subsystem
constexpr UCHAR IMAGE_SUBSYSTEM_POSIX_CUI = 7; // The Posix character subsystem 
constexpr UCHAR IMAGE_SUBSYSTEM_NATIVE_WINDOWS = 8; // Native Win9x driver 
constexpr UCHAR IMAGE_SUBSYSTEM_WINDOWS_CE_GUI = 9; // Windows CE 
constexpr UCHAR IMAGE_SUBSYSTEM_EFI_APPLICATION = 10; // An Extensible Firmware Interface (EFI) application 
constexpr UCHAR IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER = 11; // An EFI driver with boot services
constexpr UCHAR IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER = 12; // An EFI driver with run-time services
constexpr UCHAR IMAGE_SUBSYSTEM_EFI_ROM = 13; //constexpr UCHAR An EFI ROM image
constexpr UCHAR IMAGE_SUBSYSTEM_XBOX = 14; // XBOX
constexpr UCHAR IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION = 16; // Windows boot application. 


// DllCharacteristics 
constexpr UCHAR IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA = 0x0020; // Image can handle a high entropy 64-bit virtual address space. 
constexpr UCHAR IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE = 0x0040; // DLL can be relocated at load time. 
constexpr UCHAR IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY = 0x0080; // Code Integrity checks are enforced.
constexpr USHORT IMAGE_DLLCHARACTERISTICS_NX_COMPAT = 0x0100; // Image is NX compatible. 
constexpr USHORT IMAGE_DLLCHARACTERISTICS_NO_ISOLATION = 0x0200; // Isolation aware; but do not isolate the image. 
constexpr USHORT IMAGE_DLLCHARACTERISTICS_NO_SEH = 0x0400; // Does not use structured exception (SE) handling. No SE handler may be called in this image. 
constexpr USHORT IMAGE_DLLCHARACTERISTICS_NO_BIND = 0x0800; // Do not bind the image. 
constexpr USHORT IMAGE_DLLCHARACTERISTICS_APPCONTAINER = 0x1000; // Image must execute in an AppContainer. 
constexpr USHORT IMAGE_DLLCHARACTERISTICS_WDM_DRIVER = 0x2000; // A WDM driver. 
constexpr USHORT IMAGE_DLLCHARACTERISTICS_GUARD_CF = 0x4000; // Image supports Control Flow Guard. 
constexpr USHORT IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE = 0x8000; // Terminal Server aware. 

struct _IMAGE_RELOCATION {
	ULONG VirtualAddress; // The address of the item to which relocation is applied. This is the offset from the beginning of the section, plus the value of the section's RVA/Offset field. See Section Table (Section Headers). For example, if the first byte of the section has an address of 0x10, the third byte has an address of 0x12. 
	ULONG SymbolTableIndex; // A zero-based index into the symbol table. This symbol gives the address that is to be used for the relocation. If the specified symbol has section storage class, then the symbol's address is the address with the first section of the same name. 
	USHORT Type; // A value that indicates the kind of relocation that should be performed. Valid relocation types depend on machine type. See Type Indicators. 
};

// Type indicators

// x64 Processors/. The following relocation type indicators are defined for x64 and compatible processors.

constexpr UCHAR IMAGE_REL_AMD64_ABSOLUTE = 0x0000; // The relocation is ignored. 
constexpr UCHAR IMAGE_REL_AMD64_ADDR64 = 0x0001; // The 64-bit VA of the relocation target. 
constexpr UCHAR IMAGE_REL_AMD64_ADDR32 = 0x0002; // The 32-bit VA of the relocation target. 
constexpr UCHAR IMAGE_REL_AMD64_ADDR32NB = 0x0003; // The 32 - bit address without an image base(RVA).
constexpr UCHAR IMAGE_REL_AMD64_REL32 = 0x0004; // The 32-bit relative address from the byte following the relocation. 
constexpr UCHAR IMAGE_REL_AMD64_REL32_1 = 0x0005; // The 32-bit address relative to byte distance 1 from the relocation. 
constexpr UCHAR IMAGE_REL_AMD64_REL32_2 = 0x0006; // The 32 - bit address relative to byte distance 2 from the relocation.
constexpr UCHAR IMAGE_REL_AMD64_REL32_3 = 0x0007; // The 32 - bit address relative to byte distance 3 from the relocation.
constexpr UCHAR IMAGE_REL_AMD64_REL32_4 = 0x0008; // The 32 - bit address relative to byte distance 4 from the relocation.
constexpr UCHAR IMAGE_REL_AMD64_REL32_5 = 0x0009; // The 32 - bit address relative to byte distance 5 from the relocation.
constexpr UCHAR IMAGE_REL_AMD64_SECTION = 0x000A; // The 16-bit section index of the section that contains the target. This is used to support debugging information. 
constexpr UCHAR IMAGE_REL_AMD64_SECREL = 0x000B; // The 32-bit offset of the target from the beginning of its section. This is used to support debugging information and static thread local storage. 
constexpr UCHAR IMAGE_REL_AMD64_SECREL7 = 0x000C; // A 7-bit unsigned offset from the base of the section that contains the target. 
constexpr UCHAR IMAGE_REL_AMD64_TOKEN = 0x000D; // CLR tokens
constexpr UCHAR IMAGE_REL_AMD64_SREL32 = 0x000E; // A 32-bit signed span-dependent value emitted into the object. 
constexpr UCHAR IMAGE_REL_AMD64_PAIR = 0x000F; // A pair that must immediately follow every span - dependent value.
constexpr UCHAR IMAGE_REL_AMD64_SSPAN32 = 0x0010; // A 32-bit signed span-dependent value that is applied at link time. 


// ARM Processors. The following relocation type indicators are defined for ARM processors.
constexpr UCHAR IMAGE_REL_ARM_ABSOLUTE = 0x0000; 
constexpr UCHAR IMAGE_REL_ARM_ADDR32 = 0x0001;
constexpr UCHAR IMAGE_REL_ARM_ADDR32NB = 0x0002;
constexpr UCHAR IMAGE_REL_ARM_BRANCH24 = 0x0003;
constexpr UCHAR IMAGE_REL_ARM_BRANCH11 = 0x0004;
constexpr UCHAR IMAGE_REL_ARM_REL32 = 0x000A;
constexpr UCHAR IMAGE_REL_ARM_SECTION = 0x000E;
constexpr UCHAR IMAGE_REL_ARM_SECREL = 0x000F;
constexpr UCHAR IMAGE_REL_ARM_MOV32 = 0x0010;
constexpr UCHAR IMAGE_REL_THUMB_MOV32 = 0x0011;
constexpr UCHAR IMAGE_REL_THUMB_BRANCH20 = 0x0012;
constexpr UCHAR Unused = 0x0013;
constexpr UCHAR IMAGE_REL_THUMB_BRANCH24 = 0x0014;
constexpr UCHAR IMAGE_REL_THUMB_BLX23 = 0x0015;
constexpr UCHAR IMAGE_REL_ARM_PAIR = 0x0016;

// ARM64 Processors. The following relocation type indicators are defined for ARM64 processors.
constexpr UCHAR IMAGE_REL_ARM64_ABSOLUTE = 0x0000;
constexpr UCHAR IMAGE_REL_ARM64_ADDR32 = 0x0001;
constexpr UCHAR IMAGE_REL_ARM64_ADDR32NB = 0x0002;
constexpr UCHAR IMAGE_REL_ARM64_BRANCH26 = 0x0003; // The 26 - bit relative displacement to the target, for B and BL instructions.
constexpr UCHAR IMAGE_REL_ARM64_PAGEBASE_REL21 = 0x0004; // The page base of the target, for ADRP instruction. 
constexpr UCHAR IMAGE_REL_ARM64_REL21 = 0x0005; // The 12 - bit relative displacement to the target, for instruction ADR
constexpr UCHAR IMAGE_REL_ARM64_PAGEOFFSET_12A = 0x0006; // The 12 - bit page offset of the target, for instructions ADD / ADDS(immediate) with zero shift.
constexpr UCHAR IMAGE_REL_ARM64_PAGEOFFSET_12L = 0x0007; // The 12-bit page offset of the target, for instruction LDR (indexed, unsigned immediate). 
constexpr UCHAR IMAGE_REL_ARM64_SECREL = 0x0008; // The 32-bit offset of the target from the beginning of its section. This is used to support debugging information and static thread local storage. 
constexpr UCHAR IMAGE_REL_ARM64_SECREL_LOW12A = 0x0009; // Bit 0:11 of section offset of the target, for instructions ADD / ADDS(immediate) with zero shift.
constexpr UCHAR IMAGE_REL_ARM64_SECREL_HIGH12A = 0x000A; // Bit 12:23 of section offset of the target, for instructions ADD/ADDS (immediate) with zero shift. 
constexpr UCHAR IMAGE_REL_ARM64_SECREL_LOW12L = 0x000B; // Bit 0:11 of section offset of the target, for instruction LDR (indexed, unsigned immediate). 
constexpr UCHAR IMAGE_REL_ARM64_TOKEN = 0x000C; // CLR token. 
constexpr UCHAR IMAGE_REL_ARM64_SECTION = 0x000D; // The 16-bit section index of the section that contains the target. This is used to support debugging information. 
constexpr UCHAR IMAGE_REL_ARM64_ADDR64 = 0x000E; // The 64-bit VA of the relocation target. 
constexpr UCHAR IMAGE_REL_ARM64_BRANCH19 = 0x000F; // The 19-bit offset to the relocation target, for conditional B instruction. 
constexpr UCHAR IMAGE_REL_ARM64_BRANCH14 = 0x0010; // The 14-bit offset to the relocation target, for instructions TBZ and TBNZ. 
constexpr UCHAR IMAGE_REL_ARM64_REL32 = 0x0011; // The 32 - bit relative address from the byte following the relocation.


// Hitachi SuperH Processors. The following relocation type indicators are defined for SH3 and SH4 processors. SH5-specific relocations are noted as SHM (SH Media).
constexpr UCHAR IMAGE_REL_SH3_ABSOLUTE = 0x0000; // The relocation is ignored.
constexpr UCHAR IMAGE_REL_SH3_DIRECT16 = 0x0001; // A reference to the 16 - bit location that contains the VA of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_DIRECT32 = 0x0002; // The 32 - bit VA of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_DIRECT8 = 0x0003; // A reference to the 8 - bit location that contains the VA of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_DIRECT8_WORD = 0x0004; // A reference to the 8 - bit instruction that contains the effective 16 - bit VA of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_DIRECT8_LONG = 0x0005; // A reference to the 8 - bit instruction that contains the effective 32 - bit VA of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_DIRECT4 = 0x0006; // A reference to the 8 - bit location whose low 4 bits contain the VA of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_DIRECT4_WORD = 0x0007; // A reference to the 8 - bit instruction whose low 4 bits contain the effective 16 - bit VA of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_DIRECT4_LONG = 0x0008; // A reference to the 8 - bit instruction whose low 4 bits contain the effective 32 - bit VA of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_PCREL8_WORD = 0x0009; // A reference to the 8 - bit instruction that contains the effective 16 - bit relative offset of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_PCREL8_LONG = 0x000A; // A reference to the 8 - bit instruction that contains the effective 32 - bit relative offset of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_PCREL12_WORD = 0x000B; // A reference to the 16 - bit instruction whose low 12 bits contain the effective 16 - bit relative offset of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_STARTOF_SECTION = 0x000C; // A reference to a 32 - bit location that is the VA of the section that contains the target symbol.
constexpr UCHAR IMAGE_REL_SH3_SIZEOF_SECTION = 0x000D; // A reference to the 32 - bit location that is the size of the section that contains the target symbol.
constexpr UCHAR IMAGE_REL_SH3_SECTION = 0x000E; // The 16 - bit section index of the section that contains the target.This is used to support debugging information.
constexpr UCHAR IMAGE_REL_SH3_SECREL = 0x000F; // The 32 - bit offset of the target from the beginning of its section.This is used to support debugging information and static thread local storage.
constexpr UCHAR IMAGE_REL_SH3_DIRECT32_NB = 0x0010; // The 32 - bit RVA of the target symbol.
constexpr UCHAR IMAGE_REL_SH3_GPREL4_LONG = 0x0011; // GP relative.
constexpr UCHAR IMAGE_REL_SH3_TOKEN = 0x0012; // CLR token.
constexpr UCHAR IMAGE_REL_SHM_PCRELPT = 0x0013; // The offset from the current instruction in longwords.If the NOMODE bit is not set, insert the inverse of the low bit at bit 32 to select PTA or PTB.
constexpr UCHAR IMAGE_REL_SHM_REFLO = 0x0014; // The low 16 bits of the 32 - bit address.
constexpr UCHAR IMAGE_REL_SHM_REFHALF = 0x0015; // The high 16 bits of the 32 - bit address.
constexpr UCHAR IMAGE_REL_SHM_RELLO = 0x0016; // The low 16 bits of the relative address.
constexpr UCHAR IMAGE_REL_SHM_RELHALF = 0x0017; // The high 16 bits of the relative address.
constexpr UCHAR IMAGE_REL_SHM_PAIR = 0x0018; // The relocation is valid only when it immediately follows a REFHALF, RELHALF, or RELLO relocation.The SymbolTableIndex field of the relocation contains a displacement and not an index into the symbol table.
constexpr USHORT IMAGE_REL_SHM_NOMODE = 0x8000; // The relocation ignores section mode.


// IBM PowerPC Processors. The following relocation type indicators are defined for PowerPC processors.
constexpr UCHAR IMAGE_REL_PPC_ABSOLUTE = 0x0000; // The relocation is ignored.
constexpr UCHAR IMAGE_REL_PPC_ADDR64 = 0x0001; // The 64-bit VA of the target. 
constexpr UCHAR IMAGE_REL_PPC_ADDR32 = 0x0002; // The 32 - bit VA of the target.
constexpr UCHAR IMAGE_REL_PPC_ADDR24 = 0x0003; // The low 24 bits of the VA of the target.This is valid only when the target symbol is absolute and can be sign - extended to its original value.
constexpr UCHAR IMAGE_REL_PPC_ADDR16 = 0x0004; // The low 16 bits of the target's VA. 
constexpr UCHAR IMAGE_REL_PPC_REL24 = 0x0006; // A 24 - bit PC - relative offset to the symbol's location. 
constexpr UCHAR IMAGE_REL_PPC_REL14 = 0x0007; // A 14 - bit PC - relative offset to the symbol's location. 
constexpr UCHAR IMAGE_REL_PPC_ADDR32NB = 0x000A; // The 32 - bit RVA of the target.
constexpr UCHAR IMAGE_REL_PPC_SECREL = 0x000B; // The 32 - bit offset of the target from the beginning of its section.This is used to support debugging information and static thread local storage.
constexpr UCHAR IMAGE_REL_PPC_SECTION = 0x000C; // The 16 - bit section index of the section that contains the target.This is used to support debugging information.
constexpr UCHAR IMAGE_REL_PPC_SECREL16 = 0x000F; // The 16 - bit offset of the target from the beginning of its section.This is used to support debugging information and static thread local storage.
constexpr UCHAR IMAGE_REL_PPC_REFHI = 0x0010; // The high 16 bits of the target's 32-bit VA.
constexpr UCHAR IMAGE_REL_PPC_REFLO = 0x0011; // The low 16 bits of the target's VA. 
constexpr UCHAR IMAGE_REL_PPC_PAIR = 0x0012; // A relocation that is valid only when it immediately follows a REFHI or SECRELHI relocation.Its SymbolTableIndex contains a displacement and not an index into the symbol table.
constexpr UCHAR IMAGE_REL_PPC_SECRELLO = 0x0013; // The low 16 bits of the 32 - bit offset of the target from the beginning of its section.
constexpr UCHAR IMAGE_REL_PPC_GPREL = 0x0015; // The 16 - bit signed displacement of the target relative to the GP register.
constexpr UCHAR IMAGE_REL_PPC_TOKEN = 0x0016; // The CLR token.


// Intel 386 Processors. The following relocation type indicators are defined for Intel 386 and compatible processors.
constexpr UCHAR IMAGE_REL_I386_ABSOLUTE = 0x0000; // The relocation is ignored.
constexpr UCHAR IMAGE_REL_I386_DIR16 = 0x0001; // Not supported.
constexpr UCHAR IMAGE_REL_I386_REL16 = 0x0002; // Not supported.
constexpr UCHAR IMAGE_REL_I386_DIR32 = 0x0006; // The target's 32-bit VA. 
constexpr UCHAR IMAGE_REL_I386_DIR32NB = 0x0007; // The target's 32-bit RVA. 
constexpr UCHAR IMAGE_REL_I386_SEG12 = 0x0009; // Not supported.
constexpr UCHAR IMAGE_REL_I386_SECTION = 0x000A; // The 16 - bit section index of the section that contains the target.This is used to support debugging information.
constexpr UCHAR IMAGE_REL_I386_SECREL = 0x000B; // The 32 - bit offset of the target from the beginning of its section.This is used to support debugging information and static thread local storage.
constexpr UCHAR IMAGE_REL_I386_TOKEN = 0x000C; // The CLR token.
constexpr UCHAR IMAGE_REL_I386_SECREL7 = 0x000D; // A 7 - bit offset from the base of the section that contains the target.
constexpr UCHAR IMAGE_REL_I386_REL32 = 0x0014; // The 32 - bit relative displacement to the target.This supports the x86 relative branch and call instructions.


// Intel Itanium Processor Family (IPF)
// The following relocation type indicators are defined for the Intel Itanium processor family and compatible processors. 
// Note that relocations on instructions use the bundle's offset and slot number for the relocation offset.
constexpr UCHAR IMAGE_REL_IA64_ABSOLUTE = 0x0000; // The relocation is ignored.
constexpr UCHAR IMAGE_REL_IA64_IMM14 = 0x0001; // The instruction relocation can be followed by an ADDEND relocation whose value is added to the target address before it is inserted into the specified slot in the IMM14 bundle.The relocation target must be absolute or the image must be fixed.
constexpr UCHAR IMAGE_REL_IA64_IMM22 = 0x0002; // The instruction relocation can be followed by an ADDEND relocation whose value is added to the target address before it is inserted into the specified slot in the IMM22 bundle.The relocation target must be absolute or the image must be fixed.
constexpr UCHAR IMAGE_REL_IA64_IMM64 = 0x0003; // The slot number of this relocation must be one(1).The relocation can be followed by an ADDEND relocation whose value is added to the target address before it is stored in all three slots of the IMM64 bundle.
constexpr UCHAR IMAGE_REL_IA64_DIR32 = 0x0004; // The target's 32-bit VA. This is supported only for /LARGEADDRESSAWARE:NO images. 
constexpr UCHAR IMAGE_REL_IA64_DIR64 = 0x0005; // The target's 64-bit VA. 
constexpr UCHAR IMAGE_REL_IA64_PCREL21B = 0x0006; // The instruction is fixed up with the 25 - bit relative displacement to the 16 - bit aligned target.The low 4 bits of the displacement are zero and are not stored.
constexpr UCHAR IMAGE_REL_IA64_PCREL21M = 0x0007; // The instruction is fixed up with the 25 - bit relative displacement to the 16 - bit aligned target.The low 4 bits of the displacement, which are zero, are not stored.
constexpr UCHAR IMAGE_REL_IA64_PCREL21F = 0x0008; // The LSBs of this relocation's offset must contain the slot number whereas the rest is the bundle address. The bundle is fixed up with the 25-bit relative displacement to the 16-bit aligned target. The low 4 bits of the displacement are zero and are not stored. 
constexpr UCHAR IMAGE_REL_IA64_GPREL22 = 0x0009; // The instruction relocation can be followed by an ADDEND relocation whose value is added to the target address and then a 22 - bit GP - relative offset that is calculated and applied to the GPREL22 bundle.
constexpr UCHAR IMAGE_REL_IA64_LTOFF22 = 0x000A; // The instruction is fixed up with the 22 - bit GP - relative offset to the target symbol's literal table entry. The linker creates this literal table entry based on this relocation and the ADDEND relocation that might follow. 
constexpr UCHAR IMAGE_REL_IA64_SECTION = 0x000B; // The 16 - bit section index of the section contains the target.This is used to support debugging information.
constexpr UCHAR IMAGE_REL_IA64_SECREL22 = 0x000C; // The instruction is fixed up with the 22 - bit offset of the target from the beginning of its section.This relocation can be followed immediately by an ADDEND relocation, whose Value field contains the 32 - bit unsigned offset of the target from the beginning of the section.
constexpr UCHAR IMAGE_REL_IA64_SECREL64I = 0x000D; // The slot number for this relocation must be one(1).The instruction is fixed up with the 64 - bit offset of the target from the beginning of its section.
constexpr UCHAR IMAGE_REL_IA64_SECREL32 = 0x000E; // The address of data to be fixed up with the 32 - bit offset of the target from the beginning of its section.
constexpr UCHAR IMAGE_REL_IA64_DIR32NB = 0x0010; // The target's 32-bit RVA. 
constexpr UCHAR IMAGE_REL_IA64_SREL14 = 0x0011; // This is applied to a signed 14 - bit immediate that contains the difference between two relocatable targets.This is a declarative field for the linker that indicates that the compiler has already emitted this value.
constexpr UCHAR IMAGE_REL_IA64_SREL22 = 0x0012; // This is applied to a signed 22 - bit immediate that contains the difference between two relocatable targets.This is a declarative field for the linker that indicates that the compiler has already emitted this value.
constexpr UCHAR IMAGE_REL_IA64_SREL32 = 0x0013; // This is applied to a signed 32 - bit immediate that contains the difference between two relocatable values.This is a declarative field for the linker that indicates that the compiler has already emitted this value.
constexpr UCHAR IMAGE_REL_IA64_UREL32 = 0x0014; // This is applied to an unsigned 32 - bit immediate that contains the difference between two relocatable values.This is a declarative field for the linker that indicates that the compiler has already emitted this value.
constexpr UCHAR IMAGE_REL_IA64_PCREL60X = 0x0015; // A 60 - bit PC - relative fixup that always stays as a BRL instruction of an MLX bundle.
constexpr UCHAR IMAGE_REL_IA64_PCREL60B = 0x0016; // A 60 - bit PC - relative fixup.If the target displacement fits in a signed 25 - bit field, convert the entire bundle to an MBB bundle with NOP.B in slot 1 and a 25 - bit BR instruction(with the 4 lowest bits all zero and dropped) in slot 2.
constexpr UCHAR IMAGE_REL_IA64_PCREL60F = 0x0017; // A 60 - bit PC - relative fixup.If the target displacement fits in a signed 25 - bit field, convert the entire bundle to an MFB bundle with NOP.F in slot 1 and a 25 - bit(4 lowest bits all zero and dropped) BR instruction in slot 2.
constexpr UCHAR IMAGE_REL_IA64_PCREL60I = 0x0018; // A 60 - bit PC - relative fixup.If the target displacement fits in a signed 25 - bit field, convert the entire bundle to an MIB bundle with NOP.I in slot 1 and a 25 - bit(4 lowest bits all zero and dropped) BR instruction in slot 2.
constexpr UCHAR IMAGE_REL_IA64_PCREL60M = 0x0019; // A 60 - bit PC - relative fixup.If the target displacement fits in a signed 25 - bit field, convert the entire bundle to an MMB bundle with NOP.M in slot 1 and a 25 - bit(4 lowest bits all zero and dropped) BR instruction in slot 2.
constexpr UCHAR IMAGE_REL_IA64_IMMGPREL64 = 0x001a; // A 64 - bit GP - relative fixup.
constexpr UCHAR IMAGE_REL_IA64_TOKEN = 0x001b; // A CLR token.
constexpr UCHAR IMAGE_REL_IA64_GPREL32 = 0x001c; // A 32 - bit GP - relative fixup.
constexpr UCHAR IMAGE_REL_IA64_ADDEND = 0x001F; // The relocation is valid only when it immediately follows one of the following relocations : IMM14, IMM22, IMM64, GPREL22, LTOFF22, LTOFF64, SECREL22, SECREL64I, or SECREL32.Its value contains the addend to apply to instructions within a bundle, not for data.


// MIPS Processors. The following relocation type indicators are defined for MIPS processors.
constexpr UCHAR IMAGE_REL_MIPS_ABSOLUTE = 0x0000; // The relocation is ignored.
constexpr UCHAR IMAGE_REL_MIPS_REFHALF = 0x0001; // The high 16 bits of the target's 32-bit VA. 
constexpr UCHAR IMAGE_REL_MIPS_REFWORD = 0x0002; // The target's 32-bit VA. 
constexpr UCHAR IMAGE_REL_MIPS_JMPADDR = 0x0003; // The low 26 bits of the target's VA. This supports the MIPS J and JAL instructions. 
constexpr UCHAR IMAGE_REL_MIPS_REFHI = 0x0004; // The high 16 bits of the target's 32-bit VA. This is used for the first instruction in a two-instruction sequence that loads a full address.
constexpr UCHAR IMAGE_REL_MIPS_REFLO = 0x0005; // The low 16 bits of the target's VA. 
constexpr UCHAR IMAGE_REL_MIPS_GPREL = 0x0006; // A 16 - bit signed displacement of the target relative to the GP register.
constexpr UCHAR IMAGE_REL_MIPS_LITERAL = 0x0007; // The same as IMAGE_REL_MIPS_GPREL.
constexpr UCHAR IMAGE_REL_MIPS_SECTION = 0x000A; // The 16 - bit section index of the section contains the target.This is used to support debugging information.
constexpr UCHAR IMAGE_REL_MIPS_SECREL = 0x000B; // The 32 - bit offset of the target from the beginning of its section.This is used to support debugging information and static thread local storage.
constexpr UCHAR IMAGE_REL_MIPS_SECRELLO = 0x000C; // The low 16 bits of the 32 - bit offset of the target from the beginning of its section.
constexpr UCHAR IMAGE_REL_MIPS_SECRELHI = 0x000D; // The high 16 bits of the 32 - bit offset of the target from the beginning of its section.An IMAGE_REL_MIPS_PAIR relocation must immediately follow this one.
constexpr UCHAR IMAGE_REL_MIPS_JMPADDR16 = 0x0010; // The low 26 bits of the target's VA. This supports the MIPS16 JAL instruction. 
constexpr UCHAR IMAGE_REL_MIPS_REFWORDNB = 0x0022; // The target's 32-bit RVA. 
constexpr UCHAR IMAGE_REL_MIPS_PAIR = 0x0025; // The relocation is valid only when it immediately follows a REFHI or SECRELHI relocation.Its SymbolTableIndex contains a displacement and not an index into the symbol table.


// Mitsubishi M32R. The following relocation type indicators are defined for the Mitsubishi M32R processors.
constexpr UCHAR IMAGE_REL_M32R_ABSOLUTE = 0x0000; // The relocation is ignored.
constexpr UCHAR IMAGE_REL_M32R_ADDR32 = 0x0001; // The target's 32-bit VA. 
constexpr UCHAR IMAGE_REL_M32R_ADDR32NB = 0x0002; // The target's 32-bit RVA. 
constexpr UCHAR IMAGE_REL_M32R_ADDR24 = 0x0003; // The target's 24-bit VA. 
constexpr UCHAR IMAGE_REL_M32R_GPREL16 = 0x0004; // The target's 16-bit offset from the GP register. 
constexpr UCHAR IMAGE_REL_M32R_PCREL24 = 0x0005; // The target's 24-bit offset from the program counter (PC), shifted left by 2 bits and sign-extended 
constexpr UCHAR IMAGE_REL_M32R_PCREL16 = 0x0006; // The target's 16-bit offset from the PC, shifted left by 2 bits and sign-extended 
constexpr UCHAR IMAGE_REL_M32R_PCREL8 = 0x0007; // The target's 8-bit offset from the PC, shifted left by 2 bits and sign-extended 
constexpr UCHAR IMAGE_REL_M32R_REFHALF = 0x0008; // The 16 MSBs of the target VA.
constexpr UCHAR IMAGE_REL_M32R_REFHI = 0x0009; // The 16 MSBs of the target VA, adjusted for LSB sign extension.This is used for the first instruction in a two - instruction sequence that loads a full 32 - bit address.
constexpr UCHAR IMAGE_REL_M32R_REFLO = 0x000A; // The 16 LSBs of the target VA.
constexpr UCHAR IMAGE_REL_M32R_PAIR = 0x000B; // The relocation must follow the REFHI relocation.Its SymbolTableIndex contains a displacement and not an index into the symbol table.
constexpr UCHAR IMAGE_REL_M32R_SECTION = 0x000C; // The 16 - bit section index of the section that contains the target.This is used to support debugging information.
constexpr UCHAR IMAGE_REL_M32R_SECREL = 0x000D; // The 32 - bit offset of the target from the beginning of its section.This is used to support debugging information and static thread local storage.
constexpr UCHAR IMAGE_REL_M32R_TOKEN = 0x000E; // The CLR token.

struct DelayLoadDirectoryTable {
	ULONG Attributes; // Must be zero
	ULONG Name; // The RVA of the name of the DLL to be loaded. The name resides in the read-only data section of the image. It is referenced through the szName field.
	ULONG ModuleHandle; // The RVA of the module handle (in the data section of the image) of the DLL to be delay-loaded. It is used for storage by the routine that is supplied to manage delay-loading. 
	ULONG DelayImportAddressTable; // The RVA of the delay - load import address table.
	ULONG DelayImportNameTable; // The RVA of the delay-load name table, which contains the names of the imports that might need to be loaded. This matches the layout of the import name table.
	ULONG BoundDelayImportTable; // The RVA of the bound delay-load address table, if it exists. 
	ULONG UnloadDelayImportTable; // The RVA of the unload delay-load address table, if it exists. This is an exact copy of the delay import address table. If the caller unloads the DLL, this table should be copied back over the delay import address table so that subsequent calls to the DLL continue to use the thunking mechanism correctly. 
	ULONG TimeStamp; // The timestamp of the DLL to which this image has been bound.
};

//0x1c bytes (sizeof)
struct IMAGE_DEBUG_DIRECTORY
{
	ULONG Characteristics;                                                  
	ULONG TimeDateStamp;  // The time and date that the debug data was created.                                                 
	USHORT MajorVersion;  // The major version number of the debug data format.
	USHORT MinorVersion;  // The minor version number of the debug data format.                                                 
	ULONG Type;           // The format of debugging information.This field enables support of multiple debuggers.For more information, see Debug Type.
	ULONG SizeOfData;     // The size of the debug data (not including the debug directory itself).                                                   
	ULONG AddressOfRawData;  // The address of the debug data when loaded, relative to the image base.                                                
	ULONG PointerToRawData;  // The file pointer to the debug data.                                                
};

// Debug type
constexpr UCHAR IMAGE_DEBUG_TYPE_UNKNOWN = 0x0; // An unknown value that is ignored by all tools.
constexpr UCHAR IMAGE_DEBUG_TYPE_COFF = 0x1; // The COFF debug information(line numbers, symbol table, and string table).This type of debug information is also pointed to by fields in the file headers.
constexpr UCHAR IMAGE_DEBUG_TYPE_CODEVIEW = 0x2; // The Visual C++ debug information.
constexpr UCHAR IMAGE_DEBUG_TYPE_FPO = 0x3; // The frame pointer omission(FPO) information.This information tells the debugger how to interpret nonstandard stack frames, which use the EBP register for a purpose other than as a frame pointer.
constexpr UCHAR IMAGE_DEBUG_TYPE_MISC = 0x4; // The location of DBG file. 
constexpr UCHAR IMAGE_DEBUG_TYPE_EXCEPTION = 0x5; // A copy of.pdata section.
constexpr UCHAR IMAGE_DEBUG_TYPE_FIXUP = 0x6; // Reserved. 
constexpr UCHAR IMAGE_DEBUG_TYPE_OMAP_TO_SRC = 0x7; // The mapping from an RVA in image to an RVA in source image. 
constexpr UCHAR IMAGE_DEBUG_TYPE_OMAP_FROM_SRC = 0x8; // The mapping from an RVA in source image to an RVA in image. 
constexpr UCHAR IMAGE_DEBUG_TYPE_BORLAND = 0x9; 
constexpr UCHAR IMAGE_DEBUG_TYPE_RESERVED10 = 0x10;
constexpr UCHAR IMAGE_DEBUG_TYPE_CLSID = 0x11;
constexpr UCHAR IMAGE_DEBUG_TYPE_REPRO = 0x16; // PE determinism or reproducibility. 
constexpr UCHAR Undefined = 0x17 & 0x19;
constexpr UCHAR IMAGE_DEBUG_TYPE_EX_DLLCHARACTERISTICS = 0x20; // Extended DLL characteristics bits.
// this class describes Portable executable format
class PE
{
};

