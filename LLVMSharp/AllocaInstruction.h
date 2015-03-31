#pragma once

#include "instruction.h"

namespace LLVM
{
    public ref class AllocaInstruction : Instruction
    {
    public:
    internal:
        AllocaInstruction(llvm::AllocaInst* inst) : Instruction(inst) {};
    };
}
