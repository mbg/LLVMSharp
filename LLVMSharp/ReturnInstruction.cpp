
#include "ReturnInstruction.h"
#include "LLVMContext.h"
#include "Value.h"
#include "BasicBlock.h"

LLVM::ReturnInstruction^ LLVM::ReturnInstruction::Create(LLVM::LLVMContext^ context, LLVM::BasicBlock^ block)
{
	return gcnew LLVM::ReturnInstruction(llvm::ReturnInst::Create(
		context->GetNativeContext(),
		block->GetNativeBlock()));
}

LLVM::ReturnInstruction^ LLVM::ReturnInstruction::Create(LLVM::LLVMContext^ context, LLVM::Value^ value, LLVM::BasicBlock^ parent)
{
	return gcnew LLVM::ReturnInstruction(llvm::ReturnInst::Create(
		context->GetNativeContext(),
		value->GetNativeValue(),
		parent->GetNativeBlock()));
}