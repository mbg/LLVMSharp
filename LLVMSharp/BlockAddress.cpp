#include "BlockAddress.h"
#include "Function.h"
#include "BasicBlock.h"

using namespace LLVM;

BlockAddress^ BlockAddress::Get(LLVM::Function^ f, LLVM::BasicBlock^ bb)
{
    return gcnew BlockAddress(llvm::BlockAddress::get(f, bb));
}

BlockAddress^ BlockAddress::Get(LLVM::BasicBlock^ bb)
{
    return gcnew BlockAddress(llvm::BlockAddress::get(bb));
}

LLVM::Function^ BlockAddress::Function::get()
{
    llvm::BlockAddress* address = (llvm::BlockAddress*)this->Native;
    return gcnew LLVM::Function(address->getFunction());
}

LLVM::BasicBlock^ BlockAddress::BasicBlock::get()
{
    llvm::BlockAddress* address = (llvm::BlockAddress*)this->Native;
    return gcnew LLVM::BasicBlock(address->getBasicBlock());
}