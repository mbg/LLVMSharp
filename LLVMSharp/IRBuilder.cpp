
#include "IRBuilder.h"
#include "BasicBlock.h"
#include "Value.h"
#include "Type.h"
#include "LoadInstruction.h"
#include "CallInstruction.h"

LLVM::IRBuilder::IRBuilder(LLVM::BasicBlock^ block)
{
	this->builder = new llvm::IRBuilder<>(block->GetNativeBlock());
}

LLVM::BasicBlock^ LLVM::IRBuilder::GetInsertBlock()
{
	return gcnew LLVM::BasicBlock(this->builder->GetInsertBlock());
}

LLVM::LoadInstruction^ LLVM::IRBuilder::CreateLoad(LLVM::Value^ pointer, String^ name)
{
	return gcnew LLVM::LoadInstruction(this->builder->CreateLoad(
		pointer->GetNativeValue(),
		ToUnmanagedString(name)));
}

void LLVM::IRBuilder::CreateStore(LLVM::Value^ value, LLVM::Value^ pointer)
{
	this->builder->CreateStore(
		value->GetNativeValue(),
		pointer->GetNativeValue());
}

LLVM::Value^ LLVM::IRBuilder::CreateAdd(LLVM::Value^ leftValue, LLVM::Value^ rightValue, String^ name)
{
	return gcnew LLVM::Value(this->builder->CreateAdd(
		leftValue->GetNativeValue(),
		rightValue->GetNativeValue(),
		ToUnmanagedString(name)));
}

LLVM::Value^ LLVM::IRBuilder::CreateGEP(LLVM::Value^ pointer, LLVM::Value^ index, String^ name)
{
	return gcnew LLVM::Value(this->builder->CreateGEP(
		pointer->GetNativeValue(),
		index->GetNativeValue(),
		ToUnmanagedString(name)));
}

LLVM::Value^ LLVM::IRBuilder::CreateTrunc(LLVM::Value^ value, LLVM::Type^ type, String^ name)
{
	return gcnew LLVM::Value(this->builder->CreateTrunc(
		value->GetNativeValue(),
		type->GetNativeType(),
		ToUnmanagedString(name)));
}

LLVM::Value^ LLVM::IRBuilder::CreateSignExtend(LLVM::Value^ value, LLVM::Type^ type, String^ name)
{
	return gcnew LLVM::Value(this->builder->CreateSExt(
		value->GetNativeValue(),
		type->GetNativeType(),
		ToUnmanagedString(name)));
}

void LLVM::IRBuilder::CreateBranch(LLVM::BasicBlock^ target)
{
	this->builder->CreateBr(target->GetNativeBlock());
}

void LLVM::IRBuilder::CreateCall(LLVM::Value^ target)
{
	this->builder->CreateCall(
		target->GetNativeValue(),
		"");
}

LLVM::CallInstruction^ LLVM::IRBuilder::CreateCall(LLVM::Value^ target, String^ name)
{
	return gcnew LLVM::CallInstruction(this->builder->CreateCall(
		target->GetNativeValue(),
		ToUnmanagedString(name)));
}

LLVM::CallInstruction^ LLVM::IRBuilder::CreateCall(LLVM::Value^ target, ...array<LLVM::Value^>^ arguments)
{
	llvm::Value** args = new llvm::Value*[arguments->Length];

	for(int i=0; i < arguments->Length; i++)
	{
		args[i] = arguments[i]->GetNativeValue();
	}

	return gcnew LLVM::CallInstruction(this->builder->CreateCall(
		target->GetNativeValue(),
		args,
		args + arguments->Length));
}