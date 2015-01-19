#pragma once

#include "LLVM.h"

#include "Wrapper.h"

namespace LLVM
{
    public ref class Triple : Wrapper<llvm::Triple*>
    {
    public:
        Triple() : Wrapper(new llvm::Triple()) {};
        Triple(llvm::Triple* triple) : Wrapper(triple) {};

        static property String^ HostTriple
        {
            static String^ get();
        }

        property ArchType Architecture
        {
            ArchType get();
        }

        property VendorType Vendor
        {
            VendorType get();
        }

        property OSType OS
        {
            OSType get();
        }

        property EnvironmentType Environment
        {
            EnvironmentType get();
        }

        static String^ Normalize(String^ triple);
    };
}
