
#include "IntegerCompareInstruction.h"
#include "BasicBlock.h"
#include "Value.h"

LLVM::IntegerCompareInstruction::IntegerCompareInstruction(
	LLVM::BasicBlock^ parent, LLVM::Predicate predicate, LLVM::Value^ leftHand, LLVM::Value^ rightHand, String^ name)
	: CompareInstruction(new llvm::ICmpInst(
		*(parent->GetNativeBlock()),
		(llvm::CmpInst::Predicate)predicate,
		leftHand->GetNativeValue(),
		rightHand->GetNativeValue(),
		ToUnmanagedString(name)))
{

}