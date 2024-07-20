#pragma once
#include "CPU/CU.h"


class Instruction
{
public:
	Instruction();
	~Instruction();
	
	struct InstructionOperand {

	};

	enum class OperandType {
		Immediate,
		Register,
		Memory
	};

	void CMC();

private:
	CU controlUnit;
};

