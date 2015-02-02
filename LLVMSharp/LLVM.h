
#pragma once

#include "llvm/DerivedTypes.h"
#include "llvm/Constants.h"
#include "llvm/Instructions.h"
#include "llvm/Intrinsics.h"
#include "llvm/Module.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/IRBuilder.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/Triple.h"
#include "llvm/ADT/STLExtras.h"

#include "Interop.h"
#include "LinkageType.h"
#include "IntrinsicType.h"
#include "Predicate.h"
#include "ArchType.h"
#include "VendorType.h"
#include "OSType.h"
#include "EnvironmentType.h"
#include "PassKind.h"

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
    ref class AllocaInstruction;
	ref class PHINode;
}