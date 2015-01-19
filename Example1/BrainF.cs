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
            this.totalMemory = memory;
            this.reader = new StreamReader(File.Open(filename, FileMode.Open));

            this.GenerateHeader();
            this.ReadLoop(null, null, null);
            this.AddMainFunction();
            this.module.WriteToFile("out.bc");
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

        #region ReadLoop
        private void ReadLoop(PHINode phi, BasicBlock oldBlock, BasicBlock testBlock)
        {
            // parse the input file and generate code for it
            Symbol currentSymbol = Symbol.None;
            Symbol nextSymbol = Symbol.None;
            Int32 currentValue = 0, nextValue = 0;
            Char c;
            Int32 direction;

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
                            Value tape1 = this.builder.CreateTrunc(tape0, Type.GetInteger8Type(this.context), "tape");
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
                            new Constant(this.context, 32, (UInt64)currentValue),
                            "head");
                        break;
                    case Symbol.Change:
                        {
                            LoadInstruction tape0 = this.builder.CreateLoad(this.currentHead, "tape");
                            Value tape1 = this.builder.CreateAdd(tape0, new Constant(this.context, 8, (UInt64)currentValue), "tape");
                            this.builder.CreateStore(tape1, this.currentHead);
                        }
                        break;
                    case Symbol.Loop:
                        BasicBlock testbb = new BasicBlock(this.context, this.brainfFunction, "brainf");
                        this.builder.CreateBranch(testbb);

                        BasicBlock bb0 = this.builder.GetInsertBlock();
                        BasicBlock bb1 = new BasicBlock(this.context, this.brainfFunction, "brainf");
                        this.builder.SetInsertPoint(bb1);

                        PHINode phi0 = new PHINode(PointerType.GetUnqualified(Type.GetInteger8Type(this.context)), 2, "head", testbb);
                        phi0.AddIncomding(this.currentHead, bb0);
                        this.currentHead = phi0;

                        this.ReadLoop(phi0, bb1, testbb);

                        break;
                    default:
                        throw new Exception("Unknown symbol.");
                }

                currentSymbol = nextSymbol;
                currentValue = nextValue;
                nextSymbol = Symbol.None;

                bool loop = currentSymbol == Symbol.None ||
                    currentSymbol == Symbol.Move ||
                    currentSymbol == Symbol.Change;

                while (loop)
                {
                    if (this.reader.EndOfStream)
                    {
                        if (currentSymbol == Symbol.None) currentSymbol = Symbol.EOF;
                        else nextSymbol = Symbol.EOF;

                        loop = false;
                    }
                    else
                    {
                        c = (Char)this.reader.Read();
                        direction = 1;

                        switch (c)
                        {
                            case '-':
                                direction = -1;
                                goto case '+';
                            case '+':
                                if (currentSymbol == Symbol.Change)
                                {
                                    currentValue += direction;
                                }
                                else
                                {
                                    if (currentSymbol == Symbol.None)
                                    {
                                        currentSymbol = Symbol.Change;
                                        currentValue = direction;
                                    }
                                    else
                                    {
                                        nextSymbol = Symbol.Change;
                                        nextValue = direction;
                                        loop = false;
                                    }
                                }
                                break;
                            case '<':
                                direction = -1;
                                goto case '>';
                            case '>':
                                if (currentSymbol == Symbol.Move)
                                {
                                    currentValue += direction;
                                }
                                else
                                {
                                    if (currentSymbol == Symbol.None)
                                    {
                                        currentSymbol = Symbol.Move;
                                        currentValue = direction;
                                    }
                                    else
                                    {
                                        nextSymbol = Symbol.Move;
                                        nextValue = direction;
                                        loop = false;
                                    }
                                }
                                break;
                            case ',':
                                if (currentSymbol == Symbol.None)
                                    currentSymbol = Symbol.Read;
                                else
                                    nextSymbol = Symbol.Read;
                                loop = false;
                                break;
                            case '.':
                                if (currentSymbol == Symbol.None)
                                    currentSymbol = Symbol.Write;
                                else
                                    nextSymbol = Symbol.Write;
                                loop = false;
                                break;
                            case '[':
                                if (currentSymbol == Symbol.None)
                                    currentSymbol = Symbol.Loop;
                                else
                                    nextSymbol = Symbol.Loop;
                                loop = false;
                                break;
                            case ']':
                                if (currentSymbol == Symbol.None)
                                    currentSymbol = Symbol.EndLoop;
                                else
                                    nextSymbol = Symbol.EndLoop;
                                loop = false;
                                break;
                            default:
                                break;
                        }
                    }
                }
            }

            if (currentSymbol == Symbol.EndLoop)
            {
                if(phi == null)
                    throw new Exception("Unexpected ]");

                this.builder.CreateBranch(testBlock);

                phi.AddIncomding(this.currentHead, this.builder.GetInsertBlock());
                Value head0 = phi;

                LoadInstruction tape0 = new LoadInstruction(head0, "tape", testBlock);

                IntegerCompareInstruction test0 = new IntegerCompareInstruction(
                    testBlock, Predicate.Equal, tape0, new Constant(this.context, 8, 0), "test");

                BasicBlock bb0 = new BasicBlock(this.context, this.brainfFunction, "brainf");
                BranchInstruction.Create(bb0, oldBlock, test0, testBlock);

                this.builder.SetInsertPoint(bb0);

                PHINode phi1 = this.builder.CreatePHI(Type.GetInteger8PointerType(this.context), 1, "head");
                phi1.AddIncomding(head0, testBlock);

                this.currentHead = phi1;

                return;
            }

            this.builder.CreateBranch(this.endBlock);

            if (phi != null)
                throw new Exception("Missing ]");
        }
        #endregion

        #region AddMainFunction
        /// <summary>
        /// Adds the main entry point to the BrainF module.
        /// </summary>
        private void AddMainFunction()
        {
            // create the main function
            Function mainFunction = (Function)this.module.GetOrInsertFunction("main", new FunctionType(
                Type.GetInteger32Type(this.context),
                Type.GetInteger32Type(this.context),
                PointerType.GetUnqualified(PointerType.GetUnqualified(Type.GetInteger8Type(this.context)))));

            mainFunction.SetArgumentName(0, "argc");
            mainFunction.SetArgumentName(1, "argv");

            // call the main brainf function
            BasicBlock bb = new BasicBlock(this.context, mainFunction, "main.0");
            CallInstruction brainfCall = CallInstruction.Create(this.brainfFunction, "", bb);
            brainfCall.TailCall = false;

            // return 0
            ReturnInstruction.Create(this.context, new Constant(this.context, 32, 0), bb);
        }
        #endregion
    }
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// :: End of File
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::