#pragma once
#include <iostream>
#include <bitset>


/*THIS CLASS DESCRIBES AN ABSTRACT X86_64 CPU*/
class CPU
{
public:
	CPU();
	~CPU();
private:

	enum modes_of_operation {PROTECTED, REAL_ADDRESS, 
		                     SYSTEM_MANAGEMENT, COMPATIBILITY, 
		                     X64_MODE}; // modes of CPU operation
	
};

