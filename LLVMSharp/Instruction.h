
#pragma once

#include "LLVM.h"

#include "Wrapper.h"

namespace LLVM
{
    public ref class Instruction : Wrapper<llvm::Instruction*>
	{
	private:
	public:
		static explicit operator Instruction^ (Value^ constant);
		static operator Value^ (Instruction^ function);
	internal:
		Instruction(llvm::Instruction* instruction) : Wrapper(instruction) { };
	};
}