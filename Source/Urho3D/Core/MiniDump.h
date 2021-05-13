// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

namespace Dviglo
{

#if defined(_MSC_VER) && defined(URHO3D_MINIDUMPS)
/// Write a minidump. Needs to be called from within a structured exception handler.
URHO3D_API int WriteMiniDump(const char* applicationName, void* exceptionPointers);
#endif

}

