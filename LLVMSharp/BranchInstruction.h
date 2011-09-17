
#pragma once

#include "LLVM.h"
#include "Instruction.h"

namespace LLVM
{
	public ref class BranchInstruction : Instruction
	{
	public:
		static BranchInstruction^ Create(BasicBlock^ ifTrue, BasicBlock^ ifFalse, Value^ value, BasicBlock^ parent);
	internal:
		BranchInstruction(llvm::BranchInst* instruction) : Instruction(instruction) { };
	};
}