#include "Module.h"
#include "LLVMContext.h"
#include "Constant.h"
#include "FunctionType.h"

using namespace System;

LLVM::Module::Module(LLVMContext^ context, String^ name)
{
	this->module = new llvm::Module(ToUnmanagedString(name), context->GetNativeContext());
}

LLVM::Constant^ LLVM::Module::GetOrInsertFunction(String^ name, FunctionType^ signature)
{
	return gcnew LLVM::Constant(this->module->getOrInsertFunction(
		ToUnmanagedString(name),
		signature->GetNativeType()));
	return nullptr;
}

void LLVM::Module::Dump()
{
	this->module->dump();
}

llvm::Module* LLVM::Module::GetNativeModule()
{
	return this->module;
}