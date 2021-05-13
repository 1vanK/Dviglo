// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"

#include "../Math/MathDefs.h"
#include "../Math/StringHash.h"
#include "../Container/HashMap.h"
#include "../Core/StringHashRegister.h"
#include "../IO/Log.h"

#include <cstdio>

#include "../DebugNew.h"

namespace Dviglo
{

#ifdef URHO3D_HASH_DEBUG

// Expose map to let Visual Studio debugger access it if Urho3D is linked statically.
const StringMap* hashReverseMap = nullptr;

// Hide static global variables in functions to ensure initialization order.
static StringHashRegister& GetGlobalStringHashRegister()
{
    static StringHashRegister stringHashRegister(true /*thread safe*/ );
    hashReverseMap = &stringHashRegister.GetInternalMap();
    return stringHashRegister;
}

#endif

const StringHash StringHash::ZERO;

StringHash::StringHash(const char* str) noexcept :
    value_(Calculate(str))
{
#ifdef URHO3D_HASH_DEBUG
    Dviglo::GetGlobalStringHashRegister().RegisterString(*this, str);
#endif
}

StringHash::StringHash(const String& str) noexcept :
    value_(Calculate(str.CString()))
{
#ifdef URHO3D_HASH_DEBUG
    Dviglo::GetGlobalStringHashRegister().RegisterString(*this, str.CString());
#endif
}

unsigned StringHash::Calculate(const char* str, unsigned hash)
{
    if (!str)
        return hash;

    while (*str)
    {
        hash = SDBMHash(hash, (unsigned char)*str++);
    }

    return hash;
}

StringHashRegister* StringHash::GetGlobalStringHashRegister()
{
#ifdef URHO3D_HASH_DEBUG
    return &Dviglo::GetGlobalStringHashRegister();
#else
    return nullptr;
#endif
}

String StringHash::ToString() const
{
    char tempBuffer[CONVERSION_BUFFER_LENGTH];
    sprintf(tempBuffer, "%08X", value_);
    return String(tempBuffer);
}

String StringHash::Reverse() const
{
#ifdef URHO3D_HASH_DEBUG
    return Dviglo::GetGlobalStringHashRegister().GetStringCopy(*this);
#else
    return String::EMPTY;
#endif
}

}
