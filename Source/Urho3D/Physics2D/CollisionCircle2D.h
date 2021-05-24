// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Physics2D/CollisionShape2D.h"

namespace Dviglo
{

/// 2D circle collision component.
class URHO3D_API CollisionCircle2D : public CollisionShape2D
{
    URHO3D_OBJECT(CollisionCircle2D, CollisionShape2D);

public:
    /// Construct.
    explicit CollisionCircle2D(Context* context);
    /// Destruct.
    ~CollisionCircle2D() override;
    /// Register object factory.
    /// @nobind
    static void RegisterObject(Context* context);

    /// Set radius.
    /// @property
    void SetRadius(float radius);
    /// Set center.
    /// @property
    void SetCenter(const Vector2& center);
    /// Set center.
    void SetCenter(float x, float y);

    /// Return radius.
    /// @property
    float GetRadius() const { return radius_; }

    /// Return center.
    /// @property
    const Vector2& GetCenter() const { return center_; }

private:
    /// Apply node world scale.
    void ApplyNodeWorldScale() override;
    /// Recreate fixture.
    void RecreateFixture();

    /// Circle shape.
    b2CircleShape circleShape_;
    /// Radius.
    float radius_;
    /// Center.
    Vector2 center_;
};

}
