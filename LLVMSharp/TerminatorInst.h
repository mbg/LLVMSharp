#pragma once

#include "LLVM.h"
#include "Instruction.h"

namespace LLVM
{
    public ref class TerminatorInst : Instruction
    {
    public:
        property unsigned NumSuccessors
        {
            unsigned get();
        };
    internal:
        TerminatorInst(llvm::TerminatorInst* inst) : Instruction(inst) {};
    };
}
