#include "Triple.h"

using namespace LLVM;

String^ Triple::Normalize(String^ str)
{
    return gcnew String(
        llvm::Triple::normalize(ToUnmanagedString(str)).c_str());
}

String^ Triple::HostTriple::get()
{
    return gcnew String(llvm::sys::getDefaultTargetTriple().c_str());
}

ArchType Triple::Architecture::get()
{
    return (ArchType)this->Native->getArch();
}

VendorType Triple::Vendor::get()
{
    return (VendorType)this->Native->getVendor();
}

OSType Triple::OS::get()
{
    return (OSType)this->Native->getOS();
}

EnvironmentType Triple::Environment::get()
{
    return (EnvironmentType)this->Native->getEnvironment();
}