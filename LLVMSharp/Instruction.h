
#pragma once

#include "LLVM.h"

namespace LLVM
{
	public ref class Instruction
	{
	private:
		llvm::Instruction* instruction;
	public:
		static explicit operator Instruction^ (Value^ constant);
		static operator Value^ (Instruction^ function);
	internal:
		Instruction(llvm::Instruction* instruction) : instruction(instruction) { };
		llvm::Instruction* GetNativeInstruction();
	};
}