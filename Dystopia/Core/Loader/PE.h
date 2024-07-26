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
	WORD Magic; // state of the image file. The most common number is 0x10B, which identifies it as a normal executable file. 0x107 - ROM image, and 0x20B - PE32+ executable. 
	BYTE MajorLinkerVersion;
	BYTE MinorLinkerVersion;
	DWORD SizeOfCode; // The size of the code (text) section, or the sum of all code sections if there are multiple sections. 
	DWORD SizeOfUninitializedData; // The size of the uninitialized data section(BSS), or the sum of all such sections if there are multiple BSS sections.
	DWORD AddressOfEntryPoint; // The address of the entry point relative to the image base when the executable file is loaded into memory. If no entry point is present, this field must be 0.                         
	DWORD BaseOfCode; // The address that is relative to the image base of the beginning - of - code section when it is loaded into memory.
	DWORD BaseOfData; // The address that is relative to the image base of the beginning-of-data section when it is loaded into memory. This field is absent to PE32+ format
	QWORD ImageBase; // The preferred address of the first byte of image when loaded into memory; must be a multiple of 64 K.The default for Windows NT is 0x00400000. 
};

// this class describes Portable executable format
class PE
{
};

