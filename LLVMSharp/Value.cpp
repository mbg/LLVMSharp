
#include "Value.h"
#include "Type.h"

using namespace LLVM;

String^ Value::Name::get()
{
    return ToManagedString(this->Native->getName().data());
}

LLVM::Type^ Value::Type::get()
{
    return gcnew LLVM::Type(this->Native->getType());
}

void Value::Name::set(String^ name)
{
    this->Native->setName(ToUnmanagedString(name));
}

void Value::Dump()
{
    this->Native->dump();
}