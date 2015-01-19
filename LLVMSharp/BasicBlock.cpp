
#include "BasicBlock.h"
#include "LLVMContext.h"
#include "Function.h"
#include "Instruction.h"

LLVM::BasicBlock::BasicBlock(LLVM::LLVMContext^ context, LLVM::Function^ function, String^ name)
    : LLVM::Wrapper<llvm::BasicBlock*>(llvm::BasicBlock::Create(
        context->Native, 
		ToUnmanagedString(name),
		function->GetNativeFunction()))
{
}

LLVM::BasicBlock::BasicBlock(llvm::BasicBlock* block)
    : LLVM::Wrapper<llvm::BasicBlock*>(block)
{
}

void LLVM::BasicBlock::PushBack(LLVM::Instruction^ instruction)
{
    this->Native->getInstList().push_back(instruction);
}