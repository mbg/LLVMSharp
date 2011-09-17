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

void LLVM::Module::WriteToFile(String^ filename)
{
	std::string errInfo;
	llvm::raw_ostream* out = new llvm::raw_fd_ostream(
		ToUnmanagedString(filename), errInfo, llvm::raw_fd_ostream::F_Binary);

	llvm::WriteBitcodeToFile(this->module, *out);
	delete out;
}

void LLVM::Module::Dump()
{
	this->module->dump();
}

llvm::Module* LLVM::Module::GetNativeModule()
{
	return this->module;
}