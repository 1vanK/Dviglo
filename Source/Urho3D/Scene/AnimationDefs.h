// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

/// \file

#pragma once

namespace Dviglo
{

/// Animation wrap mode.
enum WrapMode
{
    /// Loop mode.
    WM_LOOP = 0,
    /// Play once, when animation finished it will be removed.
    WM_ONCE,
    /// Clamp mode.
    WM_CLAMP,
};

}

