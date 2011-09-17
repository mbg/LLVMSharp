
#pragma once

#include "LLVM.h"
#include "Instruction.h"

namespace LLVM
{
	public ref class ReturnInstruction : Instruction
	{
	private:
	public:
		static ReturnInstruction^ Create(LLVMContext^ context, BasicBlock^ block);
		static ReturnInstruction^ Create(LLVMContext^ context, Value^ value, BasicBlock^ parent);
	internal:
		ReturnInstruction(llvm::ReturnInst* instruction) : Instruction(instruction) { };
	};
}