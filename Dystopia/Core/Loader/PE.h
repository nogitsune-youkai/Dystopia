#pragma once
#include <bitset>
#include <variant>
#include "Core/Miscellaneous/Types.h"

using PhysicalAddress = DWORD;
using VirtualSize = DWORD;

constexpr BYTE IMAGE_NUMBEROF_DIRECTORY_ENTRIES = 16;
constexpr WORD IMAGE_DOS_MAGIC = 0x5A4D;

struct IMAGE_DOS_HEADER {
	WORD   e_magic;                     // Magic number
	WORD   e_cblp;                      // Bytes on last page of file
	WORD   e_cp;                        // Pages in file
	WORD   e_crlc;                      // Relocations
	WORD   e_cparhdr;                   // Size of header in paragraphs
	WORD   e_minalloc;                  // Minimum extra paragraphs needed
	WORD   e_maxalloc;                  // Maximum extra paragraphs needed
	WORD   e_ss;                        // Initial (relative) SS value
	WORD   e_sp;                        // Initial SP value
	WORD   e_csum;                      // Checksum
	WORD   e_ip;                        // Initial IP value
	WORD   e_cs;                        // Initial (relative) CS value
	WORD   e_lfarlc;                    // File address of relocation table
	WORD   e_ovno;                      // Overlay number
	WORD   e_res[4];                    // Reserved words
	WORD   e_oemid;                     // OEM identifier (for e_oeminfo)
	WORD   e_oeminfo;                   // OEM information; e_oemid specific
	WORD   e_res2[10];                  // Reserved words
	QWORD   e_lfanew;                   // File address of new exe header
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

// Magic number
constexpr BYTE PEMagic1 = 'P';
constexpr BYTE PEMagic2 = 'E';
constexpr BYTE PEMagic3 = '/';
constexpr BYTE PEMagic4 = '0';
constexpr BYTE PEMagic5 = '/';
constexpr BYTE PEMagic6 = '0';

constexpr DWORD IMAGE_NT_SIGNATURE = 0x4550; // Magic word to define file type - 0x00004550

struct PEHeader {
	WORD Machine; // The number that identifies the type of target machine.
	WORD NumberOfSections; // The number of sections. This indicates the size of the section table, as of 2024 this number in Windows is limited to 96
	DWORD TimeDateStamp; // indicates when the file was created
	DWORD PointerToSymbolTable; // This value should be zero for an image because COFF debugging information is deprecated. 
	DWORD NumberOfSymbols; // The number of entries in the symbol table. This data can be used to locate the string table, which immediately follows the symbol table. should be 0 as the above field
	WORD SizeOfOptionalHeader; // The size of the optional header, which is required for executable files but not for object files. This value should be zero for an object file.
	WORD Characteristics; // The flags that indicate the attributes of the file
} IMAGE_FILE_HEADER, * PIMAGE_FILE_HEADER;

// MachineTypes 
constexpr WORD IMAGE_FILE_MACHINE_UNKNOWN = 0x0;
constexpr WORD IMAGE_FILE_MACHINE_ALPHA64 = 0x284;
constexpr WORD IMAGE_FILE_MACHINE_AM33 = 0x1d3;
constexpr WORD IMAGE_FILE_MACHINE_AMD64 = 0x8664;
constexpr WORD IMAGE_FILE_MACHINE_ARM = 0x1c0;
constexpr WORD IMAGE_FILE_MACHINE_ARM64 = 0xaa64;
constexpr WORD IMAGE_FILE_MACHINE_ARMNT = 0x1c4;
constexpr WORD IMAGE_FILE_MACHINE_AXP64 = 0x284;
constexpr WORD IMAGE_FILE_MACHINE_EBC = 0xebc;
constexpr WORD IMAGE_FILE_MACHINE_I386 = 0x14c;
constexpr WORD IMAGE_FILE_MACHINE_IA64 = 0x200;
constexpr WORD IMAGE_FILE_MACHINE_LOONGARCH32 = 0x6232;
constexpr WORD IMAGE_FILE_MACHINE_LOONGARCH64 = 0x6264;
constexpr WORD IMAGE_FILE_MACHINE_M32R = 0x9041;
constexpr WORD IMAGE_FILE_MACHINE_MIPS16 = 0x266;
constexpr WORD IMAGE_FILE_MACHINE_MIPSFPU = 0x366;
constexpr WORD IMAGE_FILE_MACHINE_MIPSFPU16 = 0x466;
constexpr WORD IMAGE_FILE_MACHINE_POWERPC = 0x1f0;
constexpr WORD IMAGE_FILE_MACHINE_POWERPCFP = 0x1f1;
constexpr WORD IMAGE_FILE_MACHINE_R4000 = 0x166;
constexpr WORD IMAGE_FILE_MACHINE_RISCV32 = 0x5032;
constexpr WORD IMAGE_FILE_MACHINE_RISCV64 = 0x5064;
constexpr WORD IMAGE_FILE_MACHINE_RISCV128 = 0x5128;
constexpr WORD IMAGE_FILE_MACHINE_SH3 = 0x1a2;
constexpr WORD IMAGE_FILE_MACHINE_SH3DSP = 0x1a3;
constexpr WORD IMAGE_FILE_MACHINE_SH4 = 0x1a6;
constexpr WORD IMAGE_FILE_MACHINE_SH5 = 0x1a8;
constexpr WORD IMAGE_FILE_MACHINE_THUMB = 0x1c2;
constexpr WORD IMAGE_FILE_MACHINE_WCEMIPSV2 = 0x169;


// Characteristics
constexpr WORD IMAGE_FILE_RELOCS_STRIPPED = 0x0001;
constexpr WORD IMAGE_FILE_EXECUTABLE_IMAGE = 0x0002;
constexpr WORD IMAGE_FILE_LINE_NUMS_STRIPPED = 0x0004; // COFF line numbers have been removed. This flag is deprecated and should be zero. 
constexpr WORD IMAGE_FILE_LOCAL_SYMS_STRIPPED = 0x0008; // COFF symbol table entries for local symbols have been removed. This flag is deprecated and should be zero. 
constexpr WORD IMAGE_FILE_AGGRESSIVE_WS_TRIM = 0x0010; // Obsolete. Aggressively trim working set. This flag is deprecated for Windows 2000 and later and must be zero. 
constexpr WORD IMAGE_FILE_LARGE_ADDRESS_AWARE = 0x0020; // Application can handle > 2-GB addresses. 
constexpr WORD RESERVED_FLAG = 0x0040; // reserved for future use
constexpr WORD IMAGE_FILE_BYTES_REVERSED_LO = 0x0080;
constexpr WORD IMAGE_FILE_32BIT_MACHINE = 0x0100; // Machine is based on a 32-bit word architecture.
constexpr WORD IMAGE_FILE_DEBUG_STRIPPED = 0x0200;
constexpr WORD IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP = 0x0400;
constexpr WORD IMAGE_FILE_NET_RUN_FROM_SWAP = 0x0800;
constexpr WORD IMAGE_FILE_SYSTEM = 0x1000;
constexpr WORD IMAGE_FILE_DLL = 0x2000;
constexpr WORD IMAGE_FILE_UP_SYSTEM_ONLY = 0x4000;
constexpr WORD IMAGE_FILE_BYTES_REVERSED_HI = 0x8000; // Big endian : the MSB precedes the LSB in memory.This flag is deprecated and should be zero.


// ImageFileState 
constexpr WORD IMAGE_NT_OPTIONAL_HDR32_MAGIC = 0x10B; // normal 32 bit exe
constexpr WORD IMAGE_NT_OPTIONAL_HDR64_MAGIC = 0x20B; // 64 bit exe
constexpr WORD IMAGE_ROM_OPTIONAL_HDR_MAGIC = 0x107; // ROM image


typedef struct _IMAGE_DATA_DIRECTORY {
	DWORD VirtualAddress; // RVA of the table
	DWORD Size; // size in bytes
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct PE32OptionalHeader {
	WORD Magic; // state of the image file. The most common number is 0x10B, which identifies it as a normal executable file. 0x107 - ROM image, and 0x20B - PE32+ executable. 
	BYTE MajorLinkerVersion;
	BYTE MinorLinkerVersion;
	DWORD SizeOfCode; // The size of the code (text) section, or the sum of all code sections if there are multiple sections. 
	DWORD SizeOfInitializedData;
	DWORD SizeOfUninitializedData; // The size of the uninitialized data section(BSS), or the sum of all such sections if there are multiple BSS sections.
	DWORD AddressOfEntryPoint; // The address of the entry point relative to the image base when the executable file is loaded into memory. If no entry point is present, this field must be 0.                         
	DWORD BaseOfCode; // The address that is relative to the image base of the beginning - of - code section when it is loaded into memory.
	DWORD BaseOfData; // The address that is relative to the image base of the beginning-of-data section when it is loaded into memory. This field is absent to PE32+ format
	DWORD ImageBase; // The preferred address of the first byte of image when loaded into memory; must be a multiple of 64 K.The default for Windows NT is 0x00400000. Might be a good idea to define it as bit-field
	DWORD SectionAlignment;
	DWORD FileAlignment;
	WORD MajorOperatingSystemVersion;
	WORD MinorOperatingSystemVersion;
	WORD MajorImageVersion;
	WORD MinorImageVersion;
	WORD MajorSubsystemVersion;
	WORD MinorSubsystemVersion;
	DWORD Win32VersionValue; // Reserved, must be 0 
	DWORD SizeOfImage;
	DWORD SizeOfHeaders;
	DWORD CheckSum;
	WORD Subsystem;
	WORD DllCharacteristics;
	DWORD SizeOfStackReserve;
	DWORD SizeOfStackCommit;
	DWORD SizeOfHeapReserve;
	DWORD SizeOfHeapCommit;
	DWORD LoaderFlags; // Reserved
	DWORD NumberOfRvaAndSizes; // The number of data-directory entries in the remainder of the optional header. Each describes a location and size. 
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER, * PIMAGE_OPTIONAL_HEADER;


constexpr BYTE ExportTable = 0; // The export table address and size. For more information see .edata Section (Image Only). 
constexpr BYTE ImportTable = 1; // The import table address and size. For more information, see The .idata Section.
constexpr BYTE ResourceTable = 2; // The resource table address and size. For more information, see The .rsrc Section.
constexpr BYTE ExceptionTable = 3; // The exception table address and size. For more information, see The .pdata Section. 
constexpr BYTE CertificateTable = 4; // The attribute certificate table address and size. For more information, see The Attribute Certificate Table (Image Only). 
constexpr BYTE BaseRelocationTable = 5; // The base relocation table address and size. For more information, see The .reloc Section (Image Only).
constexpr BYTE Debug = 6; // The debug data starting address and size. For more information, see The .debug Section.
constexpr BYTE Architecture = 7; // Reserved, must be 0 
constexpr BYTE GlobalPtr = 8; // The RVA of the value to be stored in the global pointer register. The size member of this structure must be set to zero. 
constexpr BYTE TLSTable = 9; // The thread local storage (TLS) table address and size. For more information, see The .tls Section.
constexpr BYTE LoadConfigTable = 10; // The load configuration table address and size. For more information, see The Load Configuration Structure (Image Only).
constexpr BYTE BoundImport = 11; // The bound import table address and size.
constexpr BYTE IAT = 12; // The import address table address and size. For more information, see Import Address Table.
constexpr BYTE DelayImportDescriptor = 13; // The delay import descriptor address and size. For more information, see Delay-Load Import Tables (Image Only).
constexpr BYTE CLRRuntimeHeader = 14; // The CLR runtime header address and size. For more information, see The .cormeta Section (Object Only).


struct PE32OptionalHeader64 {
	// Standard fields
	WORD Magic; // state of the image file. The most common number is 0x10B, which identifies it as a normal executable file. 0x107 - ROM image, and 0x20B - PE32+ executable. 
	BYTE MajorLinkerVersion;
	BYTE MinorLinkerVersion;
	DWORD SizeOfCode; // The size of the code (text) section, or the sum of all code sections if there are multiple sections. 
	DWORD SizeOfInitializedData;
	DWORD SizeOfUninitializedData; // The size of the uninitialized data section(BSS), or the sum of all such sections if there are multiple BSS sections.
	DWORD AddressOfEntryPoint; // The address of the entry point relative to the image base when the executable file is loaded into memory. If no entry point is present, this field must be 0.                         
	DWORD BaseOfCode; // The address that is relative to the image base of the beginning - of - code section when it is loaded into memory.
	
	// Windows-Specific Fields
	QWORD ImageBase; // The preferred address of the first byte of image when loaded into memory; must be a multiple of 64 K.The default for Windows NT is 0x00400000. Might be a good idea to define it as bit-field
	DWORD SectionAlignment; // The alignment (in bytes) of sections when they are loaded into memory. It must be greater than or equal to FileAlignment. The default is the page size for the architecture. 
	DWORD FileAlignment; // The alignment factor (in bytes) that is used to align the raw data of sections in the image file. The value should be a power of 2 between 512 and 64 K, inclusive. The default is 512. If the SectionAlignment is less than the architecture's page size, then FileAlignment must match SectionAlignment. 
	WORD MajorOperatingSystemVersion;
	WORD MinorOperatingSystemVersion;
	WORD MajorImageVersion;
	WORD MinorImageVersion;
	WORD MajorSubsystemVersion;
	WORD MinorSubsystemVersion;
	DWORD Win32VersionValue; // Reserved, must be 0 
	DWORD SizeOfImage;
	DWORD SizeOfHeaders;
	DWORD CheckSum;
	WORD Subsystem;
	WORD DllCharacteristics; 
	QWORD SizeOfStackReserve;
	QWORD SizeOfStackCommit;
	QWORD SizeOfHeapReserve;
	QWORD SizeOfHeapCommit;
	DWORD LoaderFlags; // Reserved
	DWORD NumberOfRvaAndSizes; // The number of data-directory entries in the remainder of the optional header. Each describes a location and size. 
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER_64, * PIMAGE_OPTIONAL_HEADER_64;

constexpr BYTE IMAGE_SIZEOF_SHORT_NAME = 8;

struct SectionTable {
	BYTE NAME[IMAGE_SIZEOF_SHORT_NAME]; // An 8 - byte, null - padded UTF - 8 encoded string.If the string is exactly 8 characters long, there is no terminating null.For longer names, this field contains a slash(/ ) that is followed by an ASCII representation of a decimal number that is an offset into the string table.
	std::variant<PhysicalAddress, VirtualSize> Misc; // VirtualSize - The total size of the section when loaded into memory.If this value is greater than SizeOfRawData, the section is zero - padded.This field is valid only for executable images and should be set to zero for object files.
	DWORD VirtualAddress; // For executable images, the address of the first byte of the section relative to the image base when the section is loaded into memory. For object files, this field is the address of the first byte before relocation is applied; for simplicity, compilers should set this to zero. Otherwise, it is an arbitrary value that is subtracted from offsets during relocation. 
	DWORD SizeOfRawData; // The size of the section (for object files) or the size of the initialized data on disk (for image files). For executable images, this must be a multiple of FileAlignment from the optional header. If this is less than VirtualSize, the remainder of the section is zero-filled. Because the SizeOfRawData field is rounded but the VirtualSize field is not, it is possible for SizeOfRawData to be greater than VirtualSize as well. When a section contains only uninitialized data, this field should be zero. 
	DWORD PointerToRawData; // The file pointer to the first page of the section within the COFF file. For executable images, this must be a multiple of FileAlignment from the optional header. For object files, the value should be aligned on a 4-byte boundary for best performance. When a section contains only uninitialized data, this field should be zero. 
	DWORD PointerToRelocations; // The file pointer to the beginning of relocation entries for the section. This is set to zero for executable images or if there are no relocations. 
	DWORD PointerToLineNumbers; // The file pointer to the beginning of line-number entries for the section. This is set to zero if there are no COFF line numbers. This value should be zero for an image because COFF debugging information is deprecated. 
	WORD NumberOfRelocations; // The number of relocation entries for the section. This is set to zero for executable images. 
	WORD NumberOfLineNumbers; // The number of line-number entries for the section. This value should be zero for an image because COFF debugging information is deprecated. 
	DWORD Characteristics; // The flags that describe the characteristics of the section. For more information, see Section Flags.
} IMAGE_SECTION_HEADER, * PIMAGE_SECTION_HEADER;

// SectionFlags 
constexpr WORD ReservedField1 = 0x00000000;
constexpr WORD ReservedField2 = 0x00000001;
constexpr WORD ReservedField3 = 0x00000002;
constexpr WORD ReservedField4 = 0x00000004;
constexpr WORD IMAGE_SCN_TYPE_NO_PAD = 0x00000008; // The section should not be padded to the next boundary. This flag is obsolete and is replaced by IMAGE_SCN_ALIGN_1BYTES. This is valid only for object files. 
constexpr WORD ReservedField5 = 0x00000010;
constexpr WORD IMAGE_SCN_CNT_CODE = 0x00000020; // The section contains executable code. 
constexpr WORD IMAGE_SCN_CNT_INITIALIZED_DATA = 0x00000040; // The section contains initialized data. 
constexpr WORD IMAGE_SCN_CNT_UNINITIALIZED_DATA = 0x00000080; // The section contains uninitialized data. 
constexpr WORD IMAGE_SCN_LNK_OTHER = 0x00000100; // Reserved for future use. 
constexpr WORD IMAGE_SCN_LNK_INFO = 0x00000200; // The section contains comments or other information. The .drectve section has this type. This is valid for object files only. 
constexpr WORD ReservedField6 = 0x00000400;
constexpr WORD IMAGE_SCN_LNK_REMOVE = 0x00000800; // The section will not become part of the image. This is valid only for object files. 
constexpr WORD IMAGE_SCN_LNK_COMDAT = 0x00001000; // The section contains COMDAT data. For more information; see COMDAT Sections (Object Only). This is valid only for object files. 
constexpr WORD IMAGE_SCN_GPREL = 0x00008000; // The section contains data referenced through the global pointer (GP). 
constexpr DWORD IMAGE_SCN_MEM_PURGEABLE = 0x00020000; // Reserved for future use
constexpr DWORD IMAGE_SCN_MEM_16BIT = 0x00020000; // Reserved for future use
constexpr DWORD IMAGE_SCN_MEM_LOCKED = 0x00040000; // Reserved for future use
constexpr DWORD IMAGE_SCN_MEM_PRELOAD = 0x00080000; // Reserved for future use
constexpr DWORD IMAGE_SCN_ALIGN_1BYTES = 0x00100000; // Align data on a 1-byte boundary. Valid only for object files. 
constexpr DWORD IMAGE_SCN_ALIGN_2BYTES = 0x00200000; // Align data on a 2-byte boundary. Valid only for object files. 
constexpr DWORD IMAGE_SCN_ALIGN_4BYTES = 0x00300000;
constexpr DWORD IMAGE_SCN_ALIGN_8BYTES = 0x00400000;
constexpr DWORD IMAGE_SCN_ALIGN_16BYTES = 0x00500000;
constexpr DWORD IMAGE_SCN_ALIGN_32BYTES = 0x00600000;
constexpr DWORD IMAGE_SCN_ALIGN_64BYTES = 0x00700000;
constexpr DWORD IMAGE_SCN_ALIGN_128BYTES = 0x00800000;
constexpr DWORD IMAGE_SCN_ALIGN_256BYTES = 0x00900000;
constexpr DWORD IMAGE_SCN_ALIGN_512BYTES = 0x00A00000;
constexpr DWORD IMAGE_SCN_ALIGN_1024BYTES = 0x00B00000;
constexpr DWORD IMAGE_SCN_ALIGN_2048BYTES = 0x00C00000;
constexpr DWORD IMAGE_SCN_ALIGN_4096BYTES = 0x00D00000;
constexpr DWORD IMAGE_SCN_LNK_NRELOC_OVFL = 0x01000000; // The section contains extended relocations. 
constexpr DWORD IMAGE_SCN_MEM_DISCARDABLE = 0x02000000; // The section can be discarded as needed. 
constexpr DWORD IMAGE_SCN_MEM_NOT_CACHED = 0x04000000; // The section cannot be cached. 
constexpr DWORD IMAGE_SCN_MEM_NOT_PAGED = 0x08000000; // The section is not pageable. 
constexpr DWORD IMAGE_SCN_MEM_SHARED = 0x10000000; // The section can be shared in memory. 
constexpr DWORD IMAGE_SCN_MEM_EXECUTE = 0x20000000; // The section can be executed as code.
constexpr DWORD IMAGE_SCN_MEM_READ = 0x40000000; // The section can be read. 
constexpr DWORD IMAGE_SCN_MEM_WRITE = 0x80000000; // The section can be written to.


// WindowsSubsystem {
constexpr BYTE IMAGE_SUBSYSTEM_UNKNOWN = 0; // An unknown subsystem 
constexpr BYTE IMAGE_SUBSYSTEM_NATIVE = 1; // Device drivers and native Windows processes 
constexpr BYTE IMAGE_SUBSYSTEM_WINDOWS_GUI = 2; // The Windows graphical user interface (GUI) subsystem 
constexpr BYTE IMAGE_SUBSYSTEM_WINDOWS_CUI = 3; // The Windows character subsystem 
constexpr BYTE IMAGE_SUBSYSTEM_OS2_CUI = 5; // The OS / 2 character subsystem
constexpr BYTE IMAGE_SUBSYSTEM_POSIX_CUI = 7; // The Posix character subsystem 
constexpr BYTE IMAGE_SUBSYSTEM_NATIVE_WINDOWS = 8; // Native Win9x driver 
constexpr BYTE IMAGE_SUBSYSTEM_WINDOWS_CE_GUI = 9; // Windows CE 
constexpr BYTE IMAGE_SUBSYSTEM_EFI_APPLICATION = 10; // An Extensible Firmware Interface (EFI) application 
constexpr BYTE IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER = 11; // An EFI driver with boot services
constexpr BYTE IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER = 12; // An EFI driver with run-time services
constexpr BYTE IMAGE_SUBSYSTEM_EFI_ROM = 13; //constexpr BYTE An EFI ROM image
constexpr BYTE IMAGE_SUBSYSTEM_XBOX = 14; // XBOX
constexpr BYTE IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION = 16; // Windows boot application. 


// DllCharacteristics 
constexpr BYTE IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA = 0x0020; // Image can handle a high entropy 64-bit virtual address space. 
constexpr BYTE IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE = 0x0040; // DLL can be relocated at load time. 
constexpr BYTE IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY = 0x0080; // Code Integrity checks are enforced.
constexpr WORD IMAGE_DLLCHARACTERISTICS_NX_COMPAT = 0x0100; // Image is NX compatible. 
constexpr WORD IMAGE_DLLCHARACTERISTICS_NO_ISOLATION = 0x0200; // Isolation aware; but do not isolate the image. 
constexpr WORD IMAGE_DLLCHARACTERISTICS_NO_SEH = 0x0400; // Does not use structured exception (SE) handling. No SE handler may be called in this image. 
constexpr WORD IMAGE_DLLCHARACTERISTICS_NO_BIND = 0x0800; // Do not bind the image. 
constexpr WORD IMAGE_DLLCHARACTERISTICS_APPCONTAINER = 0x1000; // Image must execute in an AppContainer. 
constexpr WORD IMAGE_DLLCHARACTERISTICS_WDM_DRIVER = 0x2000; // A WDM driver. 
constexpr WORD IMAGE_DLLCHARACTERISTICS_GUARD_CF = 0x4000; // Image supports Control Flow Guard. 
constexpr WORD IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE = 0x8000; // Terminal Server aware. 




// this class describes Portable executable format
class PE
{
};

