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
		BYTE AL;
		BYTE BL;
		BYTE CL;
		BYTE DL;
		BYTE AH;
		BYTE BH;
		BYTE CH;
		BYTE DH;
		// 16 bit registers
		WORD AX;
		WORD BX;
		WORD CX;
		WORD DX;
		WORD SI;
		WORD DI;
		WORD BP;
		WORD SP;
		// 32 bit registers
		DWORD EAX;
		DWORD EBX;
		DWORD ECX;
		DWORD EDX;
		DWORD ESI;
		DWORD EDI;
		DWORD EBP;
		DWORD ESP;
		DWORD R8D;
		DWORD R9D;
		DWORD R10D;
		DWORD R11D;
		DWORD R12D;
		DWORD R13D;
		DWORD R14D;
		DWORD R15D;

		//64 bit registers
		QWORD RAX;
		QWORD RBX;
		QWORD RCX;
		QWORD RDX;
		QWORD RSI;
		QWORD RDI;
		QWORD RBP;
		QWORD RSP;
		QWORD R8;
		QWORD R9;
		QWORD R10;
		QWORD R11;
		QWORD R12;
		QWORD R13;
		QWORD R14;
		QWORD R15;
		std::bitset<31> EFLAGS;
	} general_purpose_registers;

	struct segment_registers {
		WORD CS;
		WORD DS;
		WORD SS;
		WORD ES;
		WORD FS;
		WORD GS;
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
	DWORD EIP; // instruction pointer
	CU* controlUnit;
	
	
	
};

