#pragma once


class ALU
{
private:
	enum class opcodes {

	};

	enum InstructionType {
		// these MIGHT be not a part of ALU, but CU, but for now i have no idea
		DataTransfer = 1,
		BinaryArithmetic = 2,
		DecimalArithmetic = 3,
		Logical = 4,
		ShiftAndRotate = 5,
		BitAndByte = 6,
		ControlTransfer = 7,
		String = 8,
		InputOutput = 9,
		EnterAndLeave = 10,
		FlagControl = 11,
		SegmentRegister = 12,
		Miscellaneous = 13
	};
};

