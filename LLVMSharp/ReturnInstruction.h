
#pragma once

#include "LLVM.h"

namespace LLVM
{
	public ref class ReturnInstruction
	{
	private:
		llvm::ReturnInst* instruction;
	public:
		static ReturnInstruction^ Create(LLVMContext^ context, BasicBlock^ block);
	internal:
		ReturnInstruction(llvm::ReturnInst* instruction) : instruction(instruction) { };
		llvm::ReturnInst* GetNativeInstruction();
	};
}