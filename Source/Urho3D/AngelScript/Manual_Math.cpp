// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"
#include "../AngelScript/APITemplates.h"

#include "../AngelScript/Manual_Math.h"

namespace Dviglo
{

// This function is called before ASRegisterGenerated()
void ASRegisterManualFirst_Math(asIScriptEngine* engine)
{
}

// ========================================================================================

// This function is called after ASRegisterGenerated()
void ASRegisterManualLast_Math(asIScriptEngine* engine)
{
    // template <class T, typename std::enable_if...> inline T Mod(T x, T y) | File: ../Math/MathDefs.h
    engine->RegisterGlobalFunction("float Mod(float, float)", AS_FUNCTION(Mod<float>), AS_CALL_CDECL);
}

}
