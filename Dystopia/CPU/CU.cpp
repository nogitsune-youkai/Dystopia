#include "CU.h"
#include "Instruction.h"
#include "Opcodes.h"


CU::CU()
{
	
}

CU::~CU()
{
	delete controlUnit;
}

void CU::Decode()
{
}

void CU::Fetch()
{
}

void CU::Execute()
{
	// the code in this function is only for test purposes for now and will be rewritten
	Instruction inst;
	switch (opcodes) {
	case Opcodes::CMC:
		//std::cout << this->general_purpose_registers.EFLAGS.test(CF);
		inst.CMC();
		break;
		//std::cout << this->general_purpose_registers.EFLAGS.test(CF);
	default:
		std::cout << "Unknown opcode";
	}
}







