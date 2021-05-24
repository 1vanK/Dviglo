// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Physics2D/Constraint2D.h"

namespace Dviglo
{

/// 2D wheel constraint component.
class URHO3D_API ConstraintWheel2D : public Constraint2D
{
    URHO3D_OBJECT(ConstraintWheel2D, Constraint2D);

public:
    /// Construct.
    explicit ConstraintWheel2D(Context* context);
    /// Destruct.
    ~ConstraintWheel2D() override;
    /// Register object factory.
    /// @nobind
    static void RegisterObject(Context* context);

    /// Set anchor.
    /// @property
    void SetAnchor(const Vector2& anchor);
    /// Set axis.
    /// @property
    void SetAxis(const Vector2& axis);
    /// Set enable motor.
    /// @property
    void SetEnableMotor(bool enableMotor);
    /// Set max motor torque.
    /// @property
    void SetMaxMotorTorque(float maxMotorTorque);
    /// Set motor speed.
    /// @property
    void SetMotorSpeed(float motorSpeed);
    /// Set frequency Hz.
    /// @property
    void SetFrequencyHz(float frequencyHz);
    /// Set damping ratio.
    /// @property
    void SetDampingRatio(float dampingRatio);

    /// Return anchor.
    /// @property
    const Vector2& GetAnchor() const { return anchor_; }

    /// Return axis.
    /// @property
    const Vector2& GetAxis() const { return axis_; }

    /// Return enable motor.
    /// @property
    bool GetEnableMotor() const { return jointDef_.enableMotor; }

    /// Return maxMotor torque.
    /// @property
    float GetMaxMotorTorque() const { return jointDef_.maxMotorTorque; }

    /// Return motor speed.
    /// @property
    float GetMotorSpeed() const { return jointDef_.motorSpeed; }

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
    b2WheelJointDef jointDef_;
    /// Anchor.
    Vector2 anchor_;
    /// Axis.
    Vector2 axis_;
};

}
