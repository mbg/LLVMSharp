#pragma once

namespace LLVM
{
    public enum class PassKind
    {
        BasicBlock,
        Region,
        Loop,
        Function,
        CallGraphSCC,
        Module,
        PassManager
    };
}