#include "Pass.h"

using namespace LLVM;

const char* PassDispatcher::getPassName()
{
    return ToUnmanagedString(this->parent->PassName);
}

llvm::Pass* PassDispatcher::createPrinterPass(llvm::raw_ostream &O, const std::string &Banner) const
{
    return this->parent->CreatePrinterPass(gcnew String(Banner.c_str()))->Native;
}

String^ ModulePass::PassName::get()
{
    return gcnew String(this->Native->getPassName());
}

Pass^ ModulePass::CreatePrinterPass(String^ banner)
{
    return gcnew ModulePass(llvm::createPrintModulePass(NULL, false, ToUnmanagedString(banner)));
}

void ImmutablePass::InitializePass()
{
    llvm::ImmutablePass* ip = (llvm::ImmutablePass*)this->Native;
    ip->initializePass();
}