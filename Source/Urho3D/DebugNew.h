// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

// This file overrides global new to provide file and line information to allocations for easier memory leak detection on MSVC
// compilers. Do not include this file in a compilation unit that uses placement new. Include this file last after other
// includes; e.g. Bullet's include files will cause a compile error if this file is included before them. Also note that
// using DebugNew.h is by no means mandatory, but just a debugging convenience.

// https://docs.microsoft.com/ru-ru/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019

#pragma once

#if defined(_MSC_VER) && defined(_DEBUG)

#define _CRTDBG_MAP_ALLOC

#ifdef _malloca
#undef _malloca
#endif

#include <crtdbg.h>

#define _DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new _DEBUG_NEW

#endif
