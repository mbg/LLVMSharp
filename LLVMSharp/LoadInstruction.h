
#pragma once

#include "LLVM.h"

namespace LLVM
{
	public ref class LoadInstruction
	{
	private:
		llvm::LoadInst* instruction;
	public:
		LoadInstruction(Value^ value, String^ name, BasicBlock^ parent);

		static explicit operator LoadInstruction^ (Value^ constant);
		static operator Value^ (LoadInstruction^ function);
	internal:
		LoadInstruction(llvm::LoadInst* instruction) : instruction(instruction) { };
		llvm::LoadInst* GetNativeInstruction();
	};
}