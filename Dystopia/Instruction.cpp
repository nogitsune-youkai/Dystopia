#include "Instruction.h"


Instruction::Instruction()
{
	 
	 
}

Instruction::~Instruction()
{
	
}

void Instruction::CMC()
{
	std::cout << controlUnit.general_purpose_registers.EFLAGS.test(CU::CF);
	controlUnit.general_purpose_registers.EFLAGS.flip(CU::CF); // presumably this should 
															  // emulate complement carry flag instruction
	std::cout << controlUnit.general_purpose_registers.EFLAGS.test(CU::CF);
}
