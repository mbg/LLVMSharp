#pragma once

#include "LLVM.h"
#include "TerminatorInst.h"

namespace LLVM
{
    public ref class IndirectBrInst : TerminatorInst
    {
    public:
        property Value^ Address
        {
            Value^ get();
            void set(Value^ val);
        };
    internal:
        IndirectBrInst(llvm::IndirectBrInst* inst) : TerminatorInst(inst) {};
    };
}
