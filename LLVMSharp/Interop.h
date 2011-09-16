
#pragma once

using namespace System;

namespace LLVM
{
	const char* ToUnmanagedString(String^ value);
	String^ ToManagedString(const char* value);
}