// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"

#include "../Core/Context.h"
#include "../IO/MemoryBuffer.h"
#include "../IO/VectorBuffer.h"
#include "../Physics2D/CollisionChain2D.h"
#include "../Physics2D/PhysicsUtils2D.h"

#include "../DebugNew.h"

namespace Dviglo
{

extern const char* URHO2D_CATEGORY;

CollisionChain2D::CollisionChain2D(Context* context) :
    CollisionShape2D(context),
    loop_(false)
{
    fixtureDef_.shape = &chainShape_;
}

CollisionChain2D::~CollisionChain2D() = default;

void CollisionChain2D::RegisterObject(Context* context)
{
    context->RegisterFactory<CollisionChain2D>(URHO2D_CATEGORY);

    URHO3D_ACCESSOR_ATTRIBUTE("Is Enabled", IsEnabled, SetEnabled, bool, true, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("Loop", GetLoop, SetLoop, bool, false, AM_DEFAULT);
    URHO3D_COPY_BASE_ATTRIBUTES(CollisionShape2D);
    URHO3D_MIXED_ACCESSOR_ATTRIBUTE("Vertices", GetVerticesAttr, SetVerticesAttr, PODVector<unsigned char>, Variant::emptyBuffer, AM_FILE);
}

void CollisionChain2D::SetLoop(bool loop)
{
    if (loop == loop_)
        return;

    loop_ = loop;

    MarkNetworkUpdate();
    RecreateFixture();
}

void CollisionChain2D::SetVertexCount(unsigned count)
{
    vertices_.Resize(count);
}

void CollisionChain2D::SetVertex(unsigned index, const Vector2& vertex)
{
    if (index >= vertices_.Size())
        return;

    vertices_[index] = vertex;

    if (index == vertices_.Size() - 1)
    {
        MarkNetworkUpdate();
        RecreateFixture();
    }
}

void CollisionChain2D::SetVertices(const PODVector<Vector2>& vertices)
{
    vertices_ = vertices;

    MarkNetworkUpdate();
    RecreateFixture();
}

void CollisionChain2D::SetVerticesAttr(const PODVector<unsigned char>& value)
{
    if (value.Empty())
        return;

    PODVector<Vector2> vertices;

    MemoryBuffer buffer(value);
    while (!buffer.IsEof())
        vertices.Push(buffer.ReadVector2());

    SetVertices(vertices);
}

PODVector<unsigned char> CollisionChain2D::GetVerticesAttr() const
{
    VectorBuffer ret;

    for (unsigned i = 0; i < vertices_.Size(); ++i)
        ret.WriteVector2(vertices_[i]);

    return ret.GetBuffer();
}

void CollisionChain2D::ApplyNodeWorldScale()
{
    RecreateFixture();
}

void CollisionChain2D::RecreateFixture()
{
    ReleaseFixture();

    PODVector<b2Vec2> b2Vertices;
    unsigned count = vertices_.Size();
    b2Vertices.Resize(count);

    Vector2 worldScale(cachedWorldScale_.x_, cachedWorldScale_.y_);
    for (unsigned i = 0; i < count; ++i)
        b2Vertices[i] = ToB2Vec2(vertices_[i] * worldScale);

    chainShape_.Clear();
    if (loop_)
        chainShape_.CreateLoop(&b2Vertices[0], count);
    else
        chainShape_.CreateChain(&b2Vertices[0], count);

    CreateFixture();
}

}
