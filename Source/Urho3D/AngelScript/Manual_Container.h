// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

namespace Dviglo
{

#define REGISTER_MEMBERS_MANUAL_PART_RefCounted() \
    /* void RefCounted::AddRef() | File: ../Container/RefCounted.h */ \
    engine->RegisterObjectBehaviour(className, asBEHAVE_ADDREF, "void f()", AS_METHODPR(T, AddRef, (), void), AS_CALL_THISCALL); \
    \
    /* void RefCounted::ReleaseRef() | File: ../Container/RefCounted.h */ \
    engine->RegisterObjectBehaviour(className, asBEHAVE_RELEASE, "void f()", AS_METHODPR(T, ReleaseRef, (), void), AS_CALL_THISCALL)

}
