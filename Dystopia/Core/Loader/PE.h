#pragma once
#include <bitset>
#include "Core/Miscellaneous/Types.h"

struct PEHeader {
	DWORD Magic; // Magic word to define file type - 0x00004550
	WORD Machine; // The number that identifies the type of target machine.
	WORD NumberOfSections; // The number of sections. This indicates the size of the section table, as of 2024 this number in Windows is limited to 96
	DWORD TimeDateStamp; // indicates when the file was created
	DWORD PointerToSymbolTable; // This value should be zero for an image because COFF debugging information is deprecated. 
	DWORD NumberOfSymbols; // The number of entries in the symbol table. This data can be used to locate the string table, which immediately follows the symbol table. should be 0 as the above field
	WORD SizeOfOptionalHeader; // The size of the optional header, which is required for executable files but not for object files. This value should be zero for an object file.
	std::bitset<16> Characteristics; // The flags that indicate the attributes of the file
};

enum MachineTypes {
	IMAGE_FILE_MACHINE_UNKNOWN = 0x0,
	IMAGE_FILE_MACHINE_ALPHA = 0x184,
	IMAGE_FILE_MACHINE_ALPHA64 = 0x284,
	IMAGE_FILE_MACHINE_AM33 = 0x1d3,
	IMAGE_FILE_MACHINE_AMD64 = 0x8664,
	IMAGE_FILE_MACHINE_ARM = 0x1c0,
	IMAGE_FILE_MACHINE_ARM64 = 0xaa64,
	IMAGE_FILE_MACHINE_ARMNT = 0x1c4,
	IMAGE_FILE_MACHINE_AXP64 = 0x284,
	IMAGE_FILE_MACHINE_EBC = 0xebc,
	IMAGE_FILE_MACHINE_I386 = 0x14c,
	IMAGE_FILE_MACHINE_IA64 = 0x200,
	IMAGE_FILE_MACHINE_LOONGARCH32 = 0x6232,
	IMAGE_FILE_MACHINE_LOONGARCH64 = 0x6264,
	IMAGE_FILE_MACHINE_M32R = 0x9041,
	IMAGE_FILE_MACHINE_MIPS16 = 0x266,
	IMAGE_FILE_MACHINE_MIPSFPU = 0x366,
	IMAGE_FILE_MACHINE_MIPSFPU16 = 0x466,
	IMAGE_FILE_MACHINE_POWERPC = 0x1f0,
	IMAGE_FILE_MACHINE_POWERPCFP = 0x1f1,
	IMAGE_FILE_MACHINE_R4000 = 0x166,
	IMAGE_FILE_MACHINE_RISCV32 = 0x5032,
	IMAGE_FILE_MACHINE_RISCV64 = 0x5064,
	IMAGE_FILE_MACHINE_RISCV128 = 0x5128,
	IMAGE_FILE_MACHINE_SH3 = 0x1a2,
	IMAGE_FILE_MACHINE_SH3DSP = 0x1a3,
	IMAGE_FILE_MACHINE_SH4 = 0x1a6,
	IMAGE_FILE_MACHINE_SH5 = 0x1a8,
	IMAGE_FILE_MACHINE_THUMB = 0x1c2,
	IMAGE_FILE_MACHINE_WCEMIPSV2 = 0x169
};

enum Characteristics {
	IMAGE_FILE_RELOCS_STRIPPED = 0x0001,
	IMAGE_FILE_EXECUTABLE_IMAGE = 0x0002,
	IMAGE_FILE_LINE_NUMS_STRIPPED = 0x0004, // COFF line numbers have been removed. This flag is deprecated and should be zero. 
	IMAGE_FILE_LOCAL_SYMS_STRIPPED = 0x0008, // COFF symbol table entries for local symbols have been removed. This flag is deprecated and should be zero. 
	IMAGE_FILE_AGGRESSIVE_WS_TRIM = 0x0010, // Obsolete. Aggressively trim working set. This flag is deprecated for Windows 2000 and later and must be zero. 
	IMAGE_FILE_LARGE_ADDRESS_AWARE = 0x0020, // Application can handle > 2-GB addresses. 
	RESERVED_FLAG = 0x0040, // reserved for future use
	IMAGE_FILE_BYTES_REVERSED_LO = 0x0080,
	IMAGE_FILE_32BIT_MACHINE = 0x0100, // Machine is based on a 32-bit word architecture.
	IMAGE_FILE_DEBUG_STRIPPED = 0x0200,
	IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP = 0x0400,
	IMAGE_FILE_NET_RUN_FROM_SWAP = 0x0800,
	IMAGE_FILE_SYSTEM = 0x1000,
	IMAGE_FILE_DLL = 0x2000,
	IMAGE_FILE_UP_SYSTEM_ONLY = 0x4000,
	IMAGE_FILE_BYTES_REVERSED_HI = 0x8000 // Big endian : the MSB precedes the LSB in memory.This flag is deprecated and should be zero.
};

struct PE32OptionalHeader {
	// Standard fields
	WORD Magic; // state of the image file. The most common number is 0x10B, which identifies it as a normal executable file. 0x107 - ROM image, and 0x20B - PE32+ executable. 
	BYTE MajorLinkerVersion;
	BYTE MinorLinkerVersion;
	DWORD SizeOfCode; // The size of the code (text) section, or the sum of all code sections if there are multiple sections. 
	DWORD SizeOfInitializedData;
	DWORD SizeOfUninitializedData; // The size of the uninitialized data section(BSS), or the sum of all such sections if there are multiple BSS sections.
	DWORD AddressOfEntryPoint; // The address of the entry point relative to the image base when the executable file is loaded into memory. If no entry point is present, this field must be 0.                         
	DWORD BaseOfCode; // The address that is relative to the image base of the beginning - of - code section when it is loaded into memory.
	//DWORD BaseOfData; // The address that is relative to the image base of the beginning-of-data section when it is loaded into memory. This field is absent to PE32+ format
	
	// Windows-Specific Fields
	QWORD ImageBase; // The preferred address of the first byte of image when loaded into memory; must be a multiple of 64 K.The default for Windows NT is 0x00400000. Might be a good idea to define it as bit-field
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
	QWORD SizeOfStackReserve;
	QWORD SizeOfStackCommit;
	QWORD SizeOfHeapReserve;
	QWORD SizeOfHeapCommit;
	DWORD LoaderFlags; // Reserved
	DWORD NumberOfRvaAndSizes; // The number of data-directory entries in the remainder of the optional header. Each describes a location and size. 
	QWORD ExportTable; // The export table address and size. For more information see .edata Section (Image Only). 
	QWORD ImportTable; // The import table address and size. For more information, see The .idata Section.
	QWORD ResourceTable; // The resource table address and size. For more information, see The .rsrc Section.
	QWORD ExceptionTable; // The exception table address and size. For more information, see The .pdata Section. 
	QWORD CertificateTable; // The attribute certificate table address and size. For more information, see The Attribute Certificate Table (Image Only). 
	QWORD BaseRelocationTable; // The base relocation table address and size. For more information, see The .reloc Section (Image Only).
	QWORD Debug; // The debug data starting address and size. For more information, see The .debug Section.
	QWORD Architecture; // Reserved, must be 0 
	QWORD GlobalPtr; // The RVA of the value to be stored in the global pointer register. The size member of this structure must be set to zero. 
	QWORD TLSTable; // The thread local storage (TLS) table address and size. For more information, see The .tls Section.
	QWORD LoadConfigTable; // The load configuration table address and size. For more information, see The Load Configuration Structure (Image Only).
	QWORD BoundImport; // The bound import table address and size.
	QWORD IAT; // The import address table address and size. For more information, see Import Address Table.
	QWORD DelayImportDescriptor; // The delay import descriptor address and size. For more information, see Delay-Load Import Tables (Image Only).
	QWORD CLRRuntimeHeader; // The CLR runtime header address and size. For more information, see The .cormeta Section (Object Only).
	QWORD ReservedField;
};

enum WindowsSubsystem {
	IMAGE_SUBSYSTEM_UNKNOWN, // An unknown subsystem 
	IMAGE_SUBSYSTEM_NATIVE, // Device drivers and native Windows processes 
	IMAGE_SUBSYSTEM_WINDOWS_GUI, // The Windows graphical user interface (GUI) subsystem 
	IMAGE_SUBSYSTEM_WINDOWS_CUI, // The Windows character subsystem 
	IMAGE_SUBSYSTEM_OS2_CUI = 5, // The OS / 2 character subsystem
	IMAGE_SUBSYSTEM_POSIX_CUI = 7, // The Posix character subsystem 
	IMAGE_SUBSYSTEM_NATIVE_WINDOWS, // Native Win9x driver 
	IMAGE_SUBSYSTEM_WINDOWS_CE_GUI, // Windows CE 
	IMAGE_SUBSYSTEM_EFI_APPLICATION, // An Extensible Firmware Interface (EFI) application 
	IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER, // An EFI driver with boot services
	IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER, // An EFI driver with run-time services
	IMAGE_SUBSYSTEM_EFI_ROM, //	An EFI ROM image
	IMAGE_SUBSYSTEM_XBOX, // XBOX
	IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION = 16 // Windows boot application. 
};

enum DllCharacteristics {
	IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA = 0x0020, // Image can handle a high entropy 64-bit virtual address space. 
	IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE = 0x0040, // DLL can be relocated at load time. 
	IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY = 0x0080, // Code Integrity checks are enforced.
	IMAGE_DLLCHARACTERISTICS_NX_COMPAT = 0x0100, // Image is NX compatible. 
	IMAGE_DLLCHARACTERISTICS_NO_ISOLATION = 0x0200, // Isolation aware, but do not isolate the image. 
	IMAGE_DLLCHARACTERISTICS_NO_SEH = 0x0400, // Does not use structured exception (SE) handling. No SE handler may be called in this image. 
	IMAGE_DLLCHARACTERISTICS_NO_BIND = 0x0800, // Do not bind the image. 
	IMAGE_DLLCHARACTERISTICS_APPCONTAINER = 0x1000, // Image must execute in an AppContainer. 
	IMAGE_DLLCHARACTERISTICS_WDM_DRIVER = 0x2000, // A WDM driver. 
	IMAGE_DLLCHARACTERISTICS_GUARD_CF = 0x4000, // Image supports Control Flow Guard. 
	IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE = 0x8000, // Terminal Server aware. 
};

struct _IMAGE_DATA_DIRECTORY {
	DWORD VirtualAddress; // RVA of the table
	DWORD Size; // size in bytes
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

// this class describes Portable executable format
class PE
{
};

