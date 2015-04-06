#pragma once
#include "LLVM.h"
#include "Constant.h"

namespace LLVM
{
    public ref class BlockAddress : public Constant
    {
    public:
        static BlockAddress^ Get(Function^ f, BasicBlock^ bb);
        static BlockAddress^ Get(BasicBlock^ bb);

        property Function^ Function 
        {
            LLVM::Function^ get();
        };

        property BasicBlock^ BasicBlock
        {
            LLVM::BasicBlock^ get();
        };
    internal:
        BlockAddress(llvm::BlockAddress* address) : Constant(address) {};
    };
}
