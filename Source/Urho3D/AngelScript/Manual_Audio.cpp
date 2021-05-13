// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"
#include "../AngelScript/APITemplates.h"

#include "../Audio/Audio.h"

namespace Dviglo
{

// This function is called before ASRegisterGenerated()
void ASRegisterManualFirst_Audio(asIScriptEngine* engine)
{
}

// ========================================================================================

// template <class T> T* Context::GetSubsystem() const | File: ../Core/Context.h
static Audio* GetAudio()
{
    return GetScriptContext()->GetSubsystem<Audio>();
}

// This function is called after ASRegisterGenerated()
void ASRegisterManualLast_Audio(asIScriptEngine* engine)
{
    // template <class T> T* Context::GetSubsystem() const | File: ../Core/Context.h
    engine->RegisterGlobalFunction("Audio@+ get_audio()", AS_FUNCTION(GetAudio), AS_CALL_CDECL);
}

}
