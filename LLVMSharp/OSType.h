#pragma once

namespace LLVM
{
    public enum class OSType
    {
        UnknownOS,

        AuroraUX,
        Cygwin,
        Darwin,
        DragonFly,
        FreeBSD,
        IOS,
        KFreeBSD,
        Linux,
        Lv2,        // PS3
        MacOSX,
        MinGW32,    // i*86-pc-mingw32, *-w64-mingw32
        NetBSD,
        OpenBSD,
        Solaris,
        Win32,
        Haiku,
        Minix,
        RTEMS,
        NativeClient,
        CNK         // BG/P Compute-Node Kernel
    };
}