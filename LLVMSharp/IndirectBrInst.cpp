#include "IndirectBrInst.h"
#include "Value.h"
#include "BasicBlock.h"

using namespace LLVM;

Value^ IndirectBrInst::Address::get()
{
    llvm::IndirectBrInst* inst = (llvm::IndirectBrInst*)this->Native;
    return gcnew Value(inst->getAddress());
}

void IndirectBrInst::Address::set(Value^ val)
{
    llvm::IndirectBrInst* inst = (llvm::IndirectBrInst*)this->Native;
    inst->setAddress(val);
}

void IndirectBrInst::addDestination(BasicBlock^ d) {
    llvm::IndirectBrInst* inst = (llvm::IndirectBrInst*)this->Native;
    inst->addDestination(d);
}