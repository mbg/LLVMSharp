
#include "Function.h"
#include "Constant.h"
#include "Value.h"

using namespace System;
using namespace LLVM;

LLVM::Function::Function(Module^ module, String^ name, FunctionType^ type, LinkageType linkage)
    : LLVM::Wrapper<llvm::Function*>(llvm::Function::Create(
        (llvm::FunctionType*)type->Native, 
		(llvm::GlobalValue::LinkageTypes)linkage, 
		ToUnmanagedString(name), 
		module))
{
}

Function::Function(Module^ module, String^ name, FunctionType^ type)
    : LLVM::Wrapper<llvm::Function*>(llvm::Function::Create(
		(llvm::FunctionType*)type->Native, 
        (llvm::GlobalValue::LinkageTypes)LinkageType::ExternalLinkage, 
		ToUnmanagedString(name), 
		module))
{
}

void LLVM::Function::SetArgumentName(unsigned index, String^ name)
{
	llvm::Function::arg_iterator args = this->Native->arg_begin();
	
	for(unsigned i = 0; i < index; i++)
		args++;

	llvm::Value* arg = args;
	arg->setName(ToUnmanagedString(name));
}

bool LLVM::Function::Empty::get()
{
	return this->Native->empty();
}

LLVM::Function::operator LLVM::Function^(LLVM::Constant^ constant)
{
	return gcnew LLVM::Function(llvm::cast<llvm::Function>(constant->Native));
}

LLVM::Function::operator LLVM::Constant^(LLVM::Function^ function)
{
	return gcnew LLVM::Constant(function);
}

LLVM::Function::operator LLVM::Value^(LLVM::Function^ function)
{
	return gcnew LLVM::Value(function);
}