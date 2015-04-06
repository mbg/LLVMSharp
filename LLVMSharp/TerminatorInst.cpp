#include "TerminatorInst.h"
#include "BasicBlock.h"

using namespace LLVM;

unsigned TerminatorInst::NumSuccessors::get()
{
    llvm::TerminatorInst* inst = (llvm::TerminatorInst*)this->Native;
    return inst->getNumSuccessors();
}