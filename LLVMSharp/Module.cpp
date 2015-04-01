#include "Module.h"
#include "LLVMContext.h"
#include "Constant.h"
#include "FunctionType.h"

using namespace System;

LLVM::Module::Module(LLVMContext^ context, String^ name)
    : Wrapper<llvm::Module*>(new llvm::Module(ToUnmanagedString(name), context))
{
}

LLVM::Constant^ LLVM::Module::GetOrInsertFunction(String^ name, FunctionType^ signature)
{
    llvm::Constant* fn = this->Native->getOrInsertFunction(
		ToUnmanagedString(name),
        (llvm::FunctionType*)signature->Native);

    return gcnew LLVM::Constant(fn);
}

LLVM::Constant^ LLVM::Module::GetFunction(String^ name)
{
    llvm::Constant* fn = this->Native->getFunction(
		ToUnmanagedString(name));

    if(fn == NULL)
        return nullptr;

    return gcnew LLVM::Constant(fn);
}

void LLVM::Module::WriteToFile(String^ filename)
{
	std::string errInfo;
	llvm::raw_ostream* out = new llvm::raw_fd_ostream(
		ToUnmanagedString(filename), errInfo, llvm::raw_fd_ostream::F_Binary);

	llvm::WriteBitcodeToFile(this->Native, *out);
	delete out;
}

void LLVM::Module::Dump()
{
	this->Native->dump();
}