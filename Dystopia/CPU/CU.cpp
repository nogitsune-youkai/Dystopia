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

	Instruction inst;
	switch (opcodes) {
	case Opcodes::CMC:
		//std::cout << this->general_purpose_registers.EFLAGS.test(CF);
		inst.CMC();
		//std::cout << this->general_purpose_registers.EFLAGS.test(CF);
	}
}







