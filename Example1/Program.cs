using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using LLVM;
using Type = LLVM.Type;

namespace Example1
{
    class Program
    {
        static void Main(string[] args)
        {
            LLVMContext context = new LLVMContext();
            BrainF compiler = new BrainF(context);

            compiler.Parse("test.bf", 512);
            compiler.GeneratedModule.Dump();

            Console.ReadLine();
        }
    }
}
