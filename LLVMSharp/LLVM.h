
#pragma once

#include "llvm/DerivedTypes.h"
#include "llvm/Constants.h"
#include "llvm/Instructions.h"
#include "llvm/Intrinsics.h"
#include "llvm/Module.h"
#include "llvm/Support/IRBuilder.h"
#include "llvm/ADT/STLExtras.h"

#include "Interop.h"
#include "LinkageType.h"
#include "IntrinsicType.h"

// pre-define classes
namespace LLVM
{
	ref class LLVMContext;
	ref class Module;
	ref class Function;
	ref class Type;
	ref class IntegerType;
	ref class PointerType;
	ref class FunctionType;
	ref class Value;
	ref class Constant;
	ref class BasicBlock;
	ref class Instruction;
	ref class LoadInstruction;
	ref class CallInstruction;
	ref class ReturnInstruction;
}