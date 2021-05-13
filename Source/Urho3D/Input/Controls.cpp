// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"

#include "../Input/Controls.h"

namespace Dviglo
{

Controls::Controls() :
    buttons_(0),
    yaw_(0.f),
    pitch_(0.f)
{
}

Controls::~Controls() = default;

void Controls::Reset()
{
    buttons_ = 0;
    yaw_ = 0.0f;
    pitch_ = 0.0f;
    extraData_.Clear();
}

}
