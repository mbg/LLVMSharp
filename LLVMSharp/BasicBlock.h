
#pragma once

#include "LLVM.h"

#include "Wrapper.h"

using namespace System;

namespace LLVM
{
    public ref class BasicBlock : Wrapper<llvm::BasicBlock*>
	{
	private:
	public:
		BasicBlock(LLVMContext^ context, Function^ function, String^ name);
		
		void PushBack(Instruction^ instruction);
	internal:
		BasicBlock(llvm::BasicBlock* block);
		//llvm::BasicBlock* GetNativeBlock();
	};
}