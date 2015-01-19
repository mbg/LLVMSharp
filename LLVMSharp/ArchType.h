#pragma once

namespace LLVM
{
    public enum class ArchType
    {
        UnknownArch,

        ARM,     // ARM; arm, armv.*, xscale
        CellSPU, // CellSPU: spu, cellspu
        Hexagon, // Hexagon: hexagon
        MIPS,    // MIPS: mips, mipsallegrex
        MIPSEL,  // MIPSEL: mipsel, mipsallegrexel
        MIPS64,  // MIPS64: mips64
        MIPS64EL,// MIPS64EL: mips64el
        MSP430,  // MSP430: msp430
        PPC,     // PPC: powerpc
        PPC64,   // PPC64: powerpc64, ppu
        R600,    // R600: AMD GPUs HD2XXX - HD6XXX
        Sparc,   // Sparc: sparc
        Sparcv9, // Sparcv9: Sparcv9
        TCE,     // TCE (http://tce.cs.tut.fi/): tce
        Thumb,   // Thumb: thumb, thumbv.*
        X86,     // X86: i[3-9]86
        X86_64,  // X86-64: amd64, x86_64
        XCore,   // XCore: xcore
        MBlaze,  // MBlaze: mblaze
        PTX32,   // PTX: ptx (32-bit)
        PTX64,   // PTX: ptx (64-bit)
        le32,    // le32: generic little-endian 32-bit CPU (PNaCl / Emscripten)
        amdil   // amdil: amd IL
    };
}