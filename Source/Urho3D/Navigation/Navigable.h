// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Scene/Component.h"

namespace Dviglo
{

/// Component which tags geometry for inclusion in the navigation mesh. Optionally auto-includes geometry from child nodes.
class URHO3D_API Navigable : public Component
{
    URHO3D_OBJECT(Navigable, Component);

public:
    /// Construct.
    explicit Navigable(Context* context);
    /// Destruct.
    ~Navigable() override;
    /// Register object factory.
    /// @nobind
    static void RegisterObject(Context* context);

    /// Set whether geometry is automatically collected from child nodes. Default true.
    /// @property
    void SetRecursive(bool enable);

    /// Return whether geometry is automatically collected from child nodes.
    /// @property
    bool IsRecursive() const { return recursive_; }

private:
    /// Recursive flag.
    bool recursive_;
};

}
