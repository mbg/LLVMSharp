// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// :: $projectname$
// :: Copyright 2011 mbg
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// :: Created: 9/15/2011 4:32:37 PM
// ::      by: AD\mbg
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#region References
using System;
using LLVM;
using System.IO;

using Type = LLVM.Type;
#endregion

namespace Example1
{
    /// <summary>
    /// 
    /// </summary>
    class BrainF
    {
        #region Instance Members
        private UInt64 totalMemory;
        private StreamReader reader;
        private LLVMContext context;
        private Module module;
        private Function getcharFunction;
        private Function putcharFunction;
        private Function brainfFunction;
        private IRBuilder builder;
        private Value currentHead;
        private BasicBlock endBlock;
        #endregion

        #region Properties
        public Module GeneratedModule
        {
            get
            {
                return this.module;
            }
        }
        #endregion

        #region Constructor
        /// <summary>
        /// Initialises a new instance of this class.
        /// </summary>
        public BrainF(LLVMContext context)
        {
            this.context = context;
        }
        #endregion

        #region Parse
        public void Parse(String filename, UInt64 memory)
        {
            this.Parse(File.Open(filename, FileMode.Open, FileAccess.Read), memory);
        }
        public void Parse(Stream stream, UInt64 memory)
        {
            this.totalMemory = memory;
            this.reader = new StreamReader(stream);

            this.GenerateHeader();

            // parse the input file and generate code for it
            Symbol currentSymbol = Symbol.None;
            Symbol nextSymbol = Symbol.None;
            UInt64 currentValue = 0, nextValue = 0;
            Char c;

            while (currentSymbol != Symbol.EOF && currentSymbol != Symbol.EndLoop)
            {
                switch (currentSymbol)
                {
                    case Symbol.None:
                        break;
                    case Symbol.Read:
                        {
                            CallInstruction getCharCall = this.builder.CreateCall(this.getcharFunction, "tape");
                            getCharCall.TailCall = false;

                            Value tape0 = (Value)getCharCall;
                            Value tape1 = this.builder.CreateTrunc(null, Type.GetInteger8Type(this.context), "tape");
                            builder.CreateStore(tape1, this.currentHead);
                        }
                        break;
                    case Symbol.Write:
                        {
                            LoadInstruction tape0 = this.builder.CreateLoad(this.currentHead, "tape");
                            Value tape1 = this.builder.CreateSignExtend(tape0, Type.GetInteger32Type(this.context), "tape");
                            CallInstruction putcharCall = this.builder.CreateCall(this.putcharFunction, tape1);
                            putcharCall.TailCall = false;
                        }
                        break;
                    case Symbol.Move:
                        this.currentHead = this.builder.CreateGEP(
                            this.currentHead,
                            new Constant(this.context, 32, currentValue),
                            "head");
                        break;
                    case Symbol.Change:
                        {
                            LoadInstruction tape0 = this.builder.CreateLoad(this.currentHead, "tape");
                            Value tape1 = this.builder.CreateAdd(tape0, new Constant(this.context, 8, currentValue), "tape");
                            this.builder.CreateStore(tape1, this.currentHead);
                        }
                        break;
                    case Symbol.Loop:
                        BasicBlock testbb = new BasicBlock(this.context, this.brainfFunction, "brainf");
                        this.builder.CreateBranch(testbb);

                        BasicBlock bb0 = this.builder.GetInsertBlock();
                        BasicBlock bb1 = new BasicBlock(this.context, this.brainfFunction, "brainf");
                        //this.builder.SetInsertPoint(bb1);

                        //PHINode phi0 ...
                        break;
                    default:
                        throw new Exception("Unknown symbol.");
                }

                currentSymbol = nextSymbol;
                currentValue = nextValue;
                nextSymbol = Symbol.None;

                while (currentSymbol == Symbol.None || 
                    currentSymbol == Symbol.Move || 
                    currentSymbol == Symbol.Change)
                {
                    c = (Char)this.reader.Read();
                }
            }
        }
        #endregion

        #region GenerateHeader
        /// <summary>
        /// Generates the BrainF runtime environment.
        /// </summary>
        private void GenerateHeader()
        {
            this.module = new Module(this.context, "BrainF");

            // === Function prototypes =========================================
            Function memsetFunction = Intrinsic.GetDecleration(this.module, IntrinsicType.memset, 
                Type.GetInteger8PointerType(this.context), Type.GetInteger32Type(this.context));

            // declare i32 @getchar()
            this.getcharFunction = (Function)this.module.GetOrInsertFunction("getchar",
                new FunctionType(Type.GetInteger32Type(this.context)));

            // declare i32 @putchar(i32)
            this.putcharFunction = (Function)this.module.GetOrInsertFunction("putchar",
                new FunctionType(Type.GetInteger32Type(this.context), Type.GetInteger32Type(this.context)));

            // === Function header =============================================

            // define void @brainf()
            this.brainfFunction = (Function)this.module.GetOrInsertFunction("brainf",
                new FunctionType(Type.GetVoidType(this.context)));

            this.builder = new IRBuilder(new BasicBlock(
                this.context, this.brainfFunction, "brainf"));

            // %arr = malloc i8, i32 %d
            Constant valMemory = new Constant(this.context, 32, this.totalMemory);
            BasicBlock bb = this.builder.GetInsertBlock();
            Type intType = Type.GetInteger32Type(this.context);
            Type byteType = Type.GetInteger8Type(this.context);
            Constant allocsize = new Constant(byteType);
            allocsize.TruncOrBitCast(intType);
            Instruction pointerArray = CallInstruction.CreateMalloc(bb, intType, byteType, allocsize, valMemory, null, "arr");
            bb.PushBack(pointerArray);

            // call void @llvm.memset.
            CallInstruction memsetCall = this.builder.CreateCall(
                memsetFunction,
                pointerArray,
                new Constant(this.context, 8, 0),
                valMemory,
                new Constant(this.context, 32, 1),
                new Constant(this.context, 1, 0));
            memsetCall.TailCall = false;

            // 
            this.currentHead = this.builder.CreateGEP(
                pointerArray, new Constant(this.context, 32, this.totalMemory / 2), "head");

            // Footer
            this.endBlock = new BasicBlock(this.context, this.brainfFunction, "brainf");
            this.endBlock.PushBack(CallInstruction.CreateFree(pointerArray, this.endBlock));

            ReturnInstruction.Create(this.context, this.endBlock);
        }
        #endregion
    }
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// :: End of File
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::