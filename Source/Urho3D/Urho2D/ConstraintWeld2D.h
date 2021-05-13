// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Urho2D/Constraint2D.h"

namespace Dviglo
{

/// 2D weld constraint component.
class URHO3D_API ConstraintWeld2D : public Constraint2D
{
    URHO3D_OBJECT(ConstraintWeld2D, Constraint2D);

public:
    /// Construct.
    explicit ConstraintWeld2D(Context* context);
    /// Destruct.
    ~ConstraintWeld2D() override;
    /// Register object factory.
    /// @nobind
    static void RegisterObject(Context* context);

    /// Set anchor.
    /// @property
    void SetAnchor(const Vector2& anchor);
    /// Set frequency Hz.
    /// @property
    void SetFrequencyHz(float frequencyHz);
    /// Set damping ratio.
    /// @property
    void SetDampingRatio(float dampingRatio);

    /// Return anchor.
    /// @property
    const Vector2& GetAnchor() const { return anchor_; }

    /// Return frequency Hz.
    /// @property
    float GetFrequencyHz() const { return jointDef_.frequencyHz; }

    /// Return damping ratio.
    /// @property
    float GetDampingRatio() const { return jointDef_.dampingRatio; }

private:
    /// Return joint def.
    b2JointDef* GetJointDef() override;

    /// Box2D joint def.
    b2WeldJointDef jointDef_;
    /// Anchor.
    Vector2 anchor_;
};

}
