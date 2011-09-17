
#pragma once

#include "LLVM.h"
#include "Instruction.h"

namespace LLVM
{
	public ref class CompareInstruction : Instruction
	{
	internal:
		CompareInstruction(llvm::CmpInst* instruction) : Instruction(instruction) { };
	};
}