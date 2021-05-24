// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

// Functions that users can change to affect the work BindingGenerator

#include "XmlSourceData.h"
#include "Tuning.h"
#include "Utils.h"

// Some parts of the engine are compiled only if there are defines
string InsideDefine(const string& headerFile)
{
    string dir = WithoutFileName(headerFile);

    if (dir == "../Network")
        return "URHO3D_NETWORK";

    if (dir == "../Database")
        return "URHO3D_DATABASE";

    if (dir == "../IK")
        return "URHO3D_IK";

    if (dir == "../Physics")
        return "URHO3D_PHYSICS";

    if (dir == "../Navigation")
        return "URHO3D_NAVIGATION";

    if (dir == "../Urho2D")
        return "URHO3D_URHO2D";

    if (dir == "../Physics2D")
        return "URHO3D_URHO2D";

    return string();
}

// Users can prevent the automatic creation of bindings for certain files and dirs
bool IsIgnoredHeader(const string& headerFile)
{
    static vector<string> ignoredDirs = {
        "../AngelScript",
        //"../Container",
        "../LuaScript",
        "../Graphics/Direct3D11",
        "../Graphics/Direct3D9",
        "../Graphics/OpenGL",
        "../Database/ODBC",
        "../Database/SQLite",
    };

    static vector<string> ignoredHeaders = {
        //"../Graphics/Drawable.h",
    };

    if (CONTAINS(SourceData::ignoredHeaders_, headerFile))
        return true;

    if (CONTAINS(ignoredHeaders, headerFile))
        return true;

    string dir = WithoutFileName(headerFile);
    if (CONTAINS(ignoredDirs, dir))
        return true;

    return false;
}
