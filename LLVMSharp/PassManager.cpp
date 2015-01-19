#include "PassManager.h"

using namespace LLVM;

void PassManagerBase::Add(Pass^ pass)
{
    this->Native->add(pass);
}

bool PassManager::Run(Module^ module)
{
    llvm::PassManager* pm = (llvm::PassManager*)this->Native;
    return pm->run(*module->Native);
}

bool FunctionPassManager::Run(Function^ function)
{
    llvm::FunctionPassManager* fpm = (llvm::FunctionPassManager*)this->Native;
    return fpm->run(*function->Native);
}

bool FunctionPassManager::DoInitialization()
{
    llvm::FunctionPassManager* fpm = (llvm::FunctionPassManager*)this->Native;
    return fpm->doInitialization();
}

bool FunctionPassManager::DoFinalization()
{
    llvm::FunctionPassManager* fpm = (llvm::FunctionPassManager*)this->Native;
    return fpm->doFinalization();
}