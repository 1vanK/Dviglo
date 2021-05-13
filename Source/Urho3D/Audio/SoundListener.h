// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Scene/Component.h"

namespace Dviglo
{

/// %Sound listener component.
class URHO3D_API SoundListener : public Component
{
    URHO3D_OBJECT(SoundListener, Component);

public:
    /// Construct.
    explicit SoundListener(Context* context);
    /// Destruct.
    ~SoundListener() override;
    /// Register object factory.
    /// @nobind
    static void RegisterObject(Context* context);
};

}
