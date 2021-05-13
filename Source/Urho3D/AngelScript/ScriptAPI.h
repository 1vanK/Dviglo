// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

class asIScriptEngine;

namespace Dviglo
{

class Context;

/// Register the Core library to script.
void RegisterCoreAPI(asIScriptEngine* engine);
/// Register the Scene library to script.
void RegisterSceneAPI(asIScriptEngine* engine);
/// Register the Script interfaces to script.
void RegisterScriptInterfaceAPI(asIScriptEngine* engine);
/// Register the Script library to script.
void RegisterScriptAPI(asIScriptEngine* engine);

}
