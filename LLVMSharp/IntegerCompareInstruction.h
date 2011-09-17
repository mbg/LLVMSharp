
#pragma once

#include "LLVM.h"
#include "CompareInstruction.h"

namespace LLVM
{
	public ref class IntegerCompareInstruction : CompareInstruction
	{
	public:
		IntegerCompareInstruction(BasicBlock^ parent, Predicate predicate, Value^ leftHand, Value^ rightHand, String^ name);
	};
}