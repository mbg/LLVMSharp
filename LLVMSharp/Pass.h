#pragma once

#include <vcclr.h>

#include "LLVM.h"

#include "llvm/Pass.h"
#include "llvm/Assembly/PrintModulePass.h"

#include "Wrapper.h"


namespace LLVM
{
    ref class Pass;

    class PassDispatcher : public llvm::Pass
    {
    private:
        gcroot<LLVM::Pass^> parent;
    public:
        PassDispatcher(LLVM::Pass^ parent, llvm::PassKind kind, char pid) : llvm::Pass(kind, pid), parent(parent) {};
    protected:
        virtual const char* getPassName();
        virtual llvm::Pass* createPrinterPass(llvm::raw_ostream &O, const std::string &Banner) const;
    };

    public ref class Pass abstract : Wrapper<llvm::Pass*>
    {
    internal:
        Pass(llvm::Pass* pass) : Wrapper(pass) {};
    public:
        Pass(PassKind kind, char pid) : Wrapper(new PassDispatcher(this, (llvm::PassKind)kind, pid)) {};

        virtual property String^ PassName
        {
            String^ get() = 0;
        }

        virtual Pass^ CreatePrinterPass(String^ banner) = 0;
    };

    public ref class ModulePass : Pass
    {
    internal:
        ModulePass(llvm::ModulePass* pass) : Pass(pass) {};
    public:
        ModulePass(char pid) : Pass(PassKind::Module, pid) {};

        virtual property String^ PassName
        {
            String^ get() override;
        }

        virtual Pass^ CreatePrinterPass(String^ banner) override;
    };

    public ref class ImmutablePass : ModulePass
    {
    internal:
        ImmutablePass(llvm::ImmutablePass* pass) : ModulePass(pass) {};
    public:
        ImmutablePass(char pid) : ModulePass(pid) {};

        virtual void InitializePass();
        bool RunOnModule(Module^) { return false; }
    };
}
