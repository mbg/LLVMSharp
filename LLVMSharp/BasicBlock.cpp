
#include "BasicBlock.h"
#include "LLVMContext.h"
#include "Function.h"
#include "Instruction.h"

LLVM::BasicBlock::BasicBlock(LLVM::LLVMContext^ context, LLVM::Function^ function, String^ name)
{
	this->block = llvm::BasicBlock::Create(
		context->GetNativeContext(), 
		ToUnmanagedString(name),
		function->GetNativeFunction());
}

LLVM::BasicBlock::BasicBlock(llvm::BasicBlock* block)
{
	this->block = block;
}

llvm::BasicBlock* LLVM::BasicBlock::GetNativeBlock()
{
	return this->block;
}

void LLVM::BasicBlock::PushBack(LLVM::Instruction^ instruction)
{
	this->block->getInstList().push_back(instruction->GetNativeInstruction());
}