
#pragma once

#include "LLVM.h"

using namespace System;

namespace LLVM
{
	public ref class BasicBlock
	{
	private:
		llvm::BasicBlock* block;
	public:
		BasicBlock(LLVMContext^ context, Function^ function, String^ name);
		
		void PushBack(Instruction^ instruction);
	internal:
		BasicBlock(llvm::BasicBlock* block);
		llvm::BasicBlock* GetNativeBlock();
	};
}