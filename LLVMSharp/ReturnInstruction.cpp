
#include "ReturnInstruction.h"
#include "LLVMContext.h"
#include "BasicBlock.h"

LLVM::ReturnInstruction^ LLVM::ReturnInstruction::Create(LLVM::LLVMContext^ context, LLVM::BasicBlock^ block)
{
	return gcnew LLVM::ReturnInstruction(llvm::ReturnInst::Create(
		context->GetNativeContext(),
		block->GetNativeBlock()));
}

llvm::ReturnInst* LLVM::ReturnInstruction::GetNativeInstruction()
{
	return this->instruction;
}