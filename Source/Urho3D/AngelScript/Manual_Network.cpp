// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#ifdef URHO3D_NETWORK

#include "../Precompiled.h"
#include "../AngelScript/APITemplates.h"

#include "../AngelScript/Manual_Network.h"

namespace Dviglo
{

// This function is called before ASRegisterGenerated()
void ASRegisterManualFirst_Network(asIScriptEngine* engine)
{
}

// ========================================================================================

// template <class T> T* Context::GetSubsystem() const | File: ../Core/Context.h
static Network* GetNetwork()
{
    return GetScriptContext()->GetSubsystem<Network>();
}

// This function is called after ASRegisterGenerated()
void ASRegisterManualLast_Network(asIScriptEngine* engine)
{
    // template <class T> T* Context::GetSubsystem() const | File: ../Core/Context.h
    engine->RegisterGlobalFunction("Network@+ get_network()", AS_FUNCTION(GetNetwork), AS_CALL_CDECL);
}

} // namespace Dviglo

#endif // def URHO3D_NETWORK
