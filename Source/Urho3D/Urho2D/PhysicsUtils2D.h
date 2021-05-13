// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

/// \file
/// @nobindfile

#pragma once

#include "../Math/Color.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"

#include <Box2D/Box2D.h>

namespace Dviglo
{

inline Color ToColor(const b2Color& color)
{
    return Color(color.r, color.g, color.b);
}

inline b2Vec2 ToB2Vec2(const Vector2& vector)
{
    return {vector.x_, vector.y_};
}

inline Vector2 ToVector2(const b2Vec2& vec2)
{
    return Vector2(vec2.x, vec2.y);
}

inline b2Vec2 ToB2Vec2(const Vector3& vector)
{
    return {vector.x_, vector.y_};
}

inline Vector3 ToVector3(const b2Vec2& vec2)
{
    return Vector3(vec2.x, vec2.y, 0.0f);
}

}
