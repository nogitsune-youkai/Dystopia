#pragma once
#include <stdint.h>
#include <iostream>
#include <bitset>

using BYTE = uint8_t; // 8 bit value
using WORD = uint16_t; // 16 bit value
using DWORD = uint32_t; // 32 bit value
using QWORD = uint64_t; // 64 bit value



/*THIS CLASS DESCRIBES AN ABSTRACT X86_64 CPU*/
class CPU
{
public:
	CPU();
private:

	struct x86_general_purpose_registers {
		DWORD EAX;
		DWORD EBX;
		DWORD ECX;
		DWORD EDX;
		DWORD ESI;
		DWORD EDI;
		DWORD EBP;
		DWORD ESP;
		std::bitset<31> EFLAGS;
	};

	struct segment_registers {
		WORD CS;
		WORD DS;
		WORD SS;
		WORD ES;
		WORD FS;
		WORD GS;
	};

	enum modes_of_operation {PROTECTED, REAL_ADDRESS, 
		                     SYSTEM_MANAGEMENT, COMPATIBILITY, 
		                     X64_MODE}; // modes of CPU operation
	
	DWORD EIP; // instruction pointer

	/*
	EFLAGS
	S - Status Flag
	C - Control Flag
	X - System Flag
	*/
	enum flags {								
		CF = 0,	// S: Carry Flag
		PF = 2,	// S: Parity Flag
		AF = 4,	// S: Auxiliary Carry Flag
		ZF = 6,	// S: Zero Flag
		SF = 7,	// S: Sign Flag
		TF = 8,	// X: Trap Flag
		IF = 9,	// X: Interrupt Enable Flag
		DF = 10, // C: Direction Flag
		OF = 11, // S: Overflow Flag
		IOPL = 12 | 13, // X: I/O Privilege Level
		NT = 14, // X: Nested Task
		RF = 16, // X: Resume Flag
		VM = 17, // X: Virtual-8086 Mode
		AC = 18, // X: Alignment Check / Access Control
		VIF = 19, // X: Virtual Interrupt Flag
		VIP = 20, // X: Virtual Interrupt Pending
		ID = 21 // X: ID Flag
	};
};

