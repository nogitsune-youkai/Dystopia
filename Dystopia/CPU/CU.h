#pragma once


#include <bitset>
#include <iostream>
#include "Core/Miscellaneous/Types.h"





// THIS CLASS DESCRIBES CONTROL UNIT OF CPU
class CU
{
public:
	CU();
	~CU();
	void Decode();
	void Fetch();
	void Execute();
	struct general_purpose_registers {
		// 8 bit registers
		UCHAR AL;
		UCHAR BL;
		UCHAR CL;
		UCHAR DL;
		UCHAR AH;
		UCHAR BH;
		UCHAR CH;
		UCHAR DH;
		// 16 bit registers
		USHORT AX;
		USHORT BX;
		USHORT CX;
		USHORT DX;
		USHORT SI;
		USHORT DI;
		USHORT BP;
		USHORT SP;
		// 32 bit registers
		ULONG EAX;
		ULONG EBX;
		ULONG ECX;
		ULONG EDX;
		ULONG ESI;
		ULONG EDI;
		ULONG EBP;
		ULONG ESP;
		ULONG R8D;
		ULONG R9D;
		ULONG R10D;
		ULONG R11D;
		ULONG R12D;
		ULONG R13D;
		ULONG R14D;
		ULONG R15D;

		//64 bit registers
		ULONGLONG RAX;
		ULONGLONG RBX;
		ULONGLONG RCX;
		ULONGLONG RDX;
		ULONGLONG RSI;
		ULONGLONG RDI;
		ULONGLONG RBP;
		ULONGLONG RSP;
		ULONGLONG R8;
		ULONGLONG R9;
		ULONGLONG R10;
		ULONGLONG R11;
		ULONGLONG R12;
		ULONGLONG R13;
		ULONGLONG R14;
		ULONGLONG R15;
		std::bitset<31> EFLAGS;
	} general_purpose_registers;

	struct segment_registers {
		USHORT CS;
		USHORT DS;
		USHORT SS;
		USHORT ES;
		USHORT FS;
		USHORT GS;
	};

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
private:
	ULONG EIP; // instruction pointer
	CU* controlUnit;
	
	
	
};

