#pragma once

#include "instruction.h"

namespace LLVM
{
    ref class AllocaInstruction : Instruction
    {
    public:
    internal:
        AllocaInstruction(llvm::AllocaInst* inst) : Instruction(inst) {};
    };
}
