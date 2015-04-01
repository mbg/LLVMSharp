
#include "Interop.h"

using namespace System;
using namespace System::Runtime::InteropServices;

const char* LLVM::ToUnmanagedString(String^ value)
{
	const char* result = (const char*)(Marshal::StringToHGlobalAnsi(value)).ToPointer();
	return result;
}

String^ LLVM::ToManagedString(const char* value)
{
	return gcnew String(value);
}

/*template <class A,class B>
std::vector<B> ToVector(array<A>^ input)
{
    std::vector<B> result;

	for(int i = 0; i < input->Length; i++)
	{
		result.push_back(input[i]->Native);
    }

    return result;
}*/