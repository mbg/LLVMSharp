
#pragma once

#include <vector>

using namespace System;

namespace LLVM
{
	const char* ToUnmanagedString(String^ value);
	String^ ToManagedString(const char* value);
    //template <class A,class B> std::vector<B> ToVector(array<A>^);
}