#pragma once

namespace LLVM
{
    public enum class EnvironmentType
    {
        UnknownEnvironment,

        GNU,
        GNUEABI,
        GNUEABIHF,
        EABI,
        MachO,
        ANDROIDEABI
    };
}