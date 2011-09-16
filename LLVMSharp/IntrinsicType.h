
#pragma once

namespace LLVM
{
	public enum class IntrinsicType
	{
		not_intrinsic = 0,
#define GET_INTRINSIC_ENUM_VALUES
#include "llvm/Intrinsics.gen"
#undef GET_INTRINSIC_ENUM_VALUES
		, num_intrinsics
	};
}