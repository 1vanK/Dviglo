// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include <Urho3D/LibraryInfo.h>
#include <iostream>

using namespace Dviglo;

int main(int argc, char* argv[])
{
    std::cout << GetRevision() << "\n" << GetCompilerDefines();
}
