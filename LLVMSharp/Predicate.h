
#pragma once

namespace LLVM
{
	public enum class Predicate
	{
		AlwaysFalse = 0,
		OrderedEqual = 1,
		OrderedGreaterThan = 2,
		OrderedGreaterOrEqual = 3,
		OrderedLessThan = 4,
		OrderedLessOrEqual = 5,
		OrderedNotEqual = 6,
		Ordered = 7,
		Unordered = 8,
		UnorderedOrEqual = 9,
		UnorderedOrGreaterThan = 10,
		UnorderedOrGreaterOrEqal = 11,
		UnorderedOrLessThan = 12,
		UnorderedOrLessOrEqual = 13,
		UnorderedOrNotEqual = 14,
		AlwaysTrue = 15,
		Equal = 32,
		NotEqual = 33,
		UnsignedGreaterThan = 34,
		UnsignedGreaterOrEqual = 35,
		UnsignedLessThan = 36,
		UnsignedLessOrEqual = 37,
		SignedGreaterThan = 38,
		SignedGreaterOrEqual = 39,
		SignedLessThan = 40,
		SignedLessOrEqual = 41
	};
}