
#pragma once

#include "LLVM.h"
#include "BranchInstruction.h"
#include "IndirectBrInst.h"

using namespace System;

namespace LLVM
{
	public ref class IRBuilder
	{
	private:
		llvm::IRBuilder<>* builder;
	public:
		IRBuilder(BasicBlock^ block);

		BasicBlock^ GetInsertBlock();
		void SetInsertPoint(BasicBlock^ block);

		LoadInstruction^ CreateLoad(Value^ pointer, String^ name);
		void CreateStore(Value^ value, Value^ pointer);
		Value^ CreateAdd(Value^ leftValue, Value^ rightValue, String^ name);
		Value^ CreateGEP(Value^ pointer, Value^ index, String^ name);
		Value^ CreateTrunc(Value^ value, Type^ type, String^ name);
		Value^ CreateSignExtend(Value^ value, Type^ type, String^ name);
		BranchInstruction^ CreateBranch(BasicBlock^ target);
        BranchInstruction^ CreateCondBranch(Value^ cond, BasicBlock^ trueBranch, BasicBlock^ falseBranch);
        IndirectBrInst^ CreateIndirectBr(Value^ addr);
        IndirectBrInst^ CreateIndirectBr(Value^ addr, unsigned numDests);
		void CreateCall(Value^ target);
		CallInstruction^ CreateCall(Value^ target, String^ name);
		CallInstruction^ CreateCall(Value^ target, ...array<Value^>^ arguments);
		PHINode^ CreatePHI(Type^ type, unsigned int, String^ name);
        ReturnInstruction^ CreateReturn();
        ReturnInstruction^ CreateReturn(Value^ value);
        AllocaInstruction^ CreateAlloca(Type^ type);
        AllocaInstruction^ CreateAlloca(Type^ type, Value^ arraySize);
        AllocaInstruction^ CreateAlloca(Type^ type, String^ name);
        AllocaInstruction^ CreateAlloca(Type^ type, Value^ arraySize, String^ name);

        // floating point instructions
        Value^ CreateFAdd(Value^ lhs, Value^ rhs, String^ name);
        Value^ CreateFSub(Value^ lhs, Value^ rhs, String^ name);
        Value^ CreateFMul(Value^ lhs, Value^ rhs, String^ name);
        Value^ CreateFDiv(Value^ lhs, Value^ rhs, String^ name);
        Value^ CreateFRem(Value^ lhs, Value^ rhs, String^ name);
        Value^ CreateFNeg(Value^ val, String^ name);
        /// <summary>
        /// 
        /// </summary>
        Value^ CreateFPToUI(Value^ val, Type^ destType, String^ name);
        Value^ CreateFPToSI(Value^ val, Type^ destType, String^ name);
        Value^ CreateUIToFP(Value^ val, Type^ destType, String^ name);
        Value^ CreateSIToFP(Value^ val, Type^ destType, String^ name);
        Value^ CreateFPTrunc(Value^ val, Type^ destType, String^ name);
        Value^ CreateFPExt(Value^ val, Type^ destType, String^ name);
        Value^ CreateFCmp(Predicate pred, Value^ lhs, Value^ rhs, String^ name);
	};
}