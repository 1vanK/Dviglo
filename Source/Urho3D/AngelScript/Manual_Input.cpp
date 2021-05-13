// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"
#include "../AngelScript/APITemplates.h"

#include "../AngelScript/Manual_Input.h"

namespace Dviglo
{

// This function is called before ASRegisterGenerated()
void ASRegisterManualFirst_Input(asIScriptEngine* engine)
{
}

// ========================================================================================

// template <class T> T* Context::GetSubsystem() const | File: ../Core/Context.h
static Input* GetInput()
{
    return GetScriptContext()->GetSubsystem<Input>();
}

// This function is called after ASRegisterGenerated()
void ASRegisterManualLast_Input(asIScriptEngine* engine)
{
    // template <class T> T* Context::GetSubsystem() const | File: ../Core/Context.h
    engine->RegisterGlobalFunction("Input@+ get_input()", AS_FUNCTION(GetInput), AS_CALL_CDECL);
}

}