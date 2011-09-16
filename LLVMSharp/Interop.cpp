
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