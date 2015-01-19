
#include "Function.h"
#include "Constant.h"
#include "Value.h"

using namespace System;

void LLVM::Function::Initialise(Module^ module, String^ name, FunctionType^ type, LinkageType linkage)
{
	this->function = llvm::Function::Create(
		type->GetNativeType(), 
		(llvm::GlobalValue::LinkageTypes)linkage, 
		ToUnmanagedString(name), 
		module);
}

LLVM::Function::Function(Module^ module, String^ name, FunctionType^ type)
{
	this->Initialise(module, name, type, LinkageType::ExternalLinkage);
}

LLVM::Function::Function(Module^ module, String^ name, FunctionType^ type, LinkageType linkage)
{
	this->Initialise(module, name, type, linkage);
}

void LLVM::Function::SetArgumentName(unsigned index, String^ name)
{
	llvm::Function::arg_iterator args = this->function->arg_begin();
	
	for(unsigned i = 0; i < index; i++)
		args++;

	llvm::Value* arg = args;
	arg->setName(ToUnmanagedString(name));
}

bool LLVM::Function::Empty::get()
{
	return this->function->empty();
}

LLVM::Function::operator LLVM::Function^(LLVM::Constant^ constant)
{
	return gcnew LLVM::Function(llvm::cast<llvm::Function>(constant->GetNativeConstant()));
}

LLVM::Function::operator LLVM::Constant^(LLVM::Function^ function)
{
	return gcnew LLVM::Constant(function->GetNativeFunction());
}

LLVM::Function::operator LLVM::Value^(LLVM::Function^ function)
{
	return gcnew LLVM::Value(function->GetNativeFunction());
}

LLVM::Function::Function(llvm::Function* function)
{
	this->function = function;
}

llvm::Function* LLVM::Function::GetNativeFunction()
{
	return this->function;
}