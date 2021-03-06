// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Physics2D/CollisionShape2D.h"

namespace Dviglo
{

/// 2D box collision component.
class URHO3D_API CollisionBox2D : public CollisionShape2D
{
    URHO3D_OBJECT(CollisionBox2D, CollisionShape2D);

public:
    /// Construct.
    explicit CollisionBox2D(Context* context);
    /// Destruct.
    ~CollisionBox2D() override;
    /// Register object factory.
    /// @nobind
    static void RegisterObject(Context* context);

    /// Set size.
    /// @property
    void SetSize(const Vector2& size);
    /// Set size.
    void SetSize(float width, float height);
    /// Set center.
    /// @property
    void SetCenter(const Vector2& center);
    /// Set center.
    void SetCenter(float x, float y);
    /// Set angle.
    /// @property
    void SetAngle(float angle);

    /// Return size.
    /// @property
    const Vector2& GetSize() const { return size_; }

    /// Return center.
    /// @property
    const Vector2& GetCenter() const { return center_; }

    /// Return angle.
    /// @property
    float GetAngle() const { return angle_; }

private:
    /// Apply node world scale.
    void ApplyNodeWorldScale() override;
    /// Recreate fixture.
    void RecreateFixture();

    /// Box shape.
    b2PolygonShape boxShape_;
    /// Size.
    Vector2 size_;
    /// Center.
    Vector2 center_;
    /// Angle.
    float angle_;
};

}
