
#pragma once

#include "LLVM.h"

#include "Wrapper.h"

namespace LLVM
{
    public ref class Value : Wrapper<llvm::Value*>
	{
	public:
        property String^ Name
        {
            String^ get();
            void set(String^ name);
        }

        void Dump();
	internal:
		Value(llvm::Value* value) : Wrapper(value) { };
	};
}