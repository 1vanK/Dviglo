// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../../Container/RefCounted.h"
#include "../../Container/Vector.h"
#include "../../Graphics/GraphicsDefs.h"

namespace Dviglo
{

class Graphics;
class ShaderVariation;
class VertexBuffer;

/// Vertex declaration.
class URHO3D_API VertexDeclaration : public RefCounted
{
public:
    /// Construct with vertex buffers and element masks to base declaration on.
    VertexDeclaration(Graphics* graphics, ShaderVariation* vertexShader, VertexBuffer** buffers);
    /// Destruct.
    virtual ~VertexDeclaration() override;

    /// Return input layout object corresponding to the declaration.
    void* GetInputLayout() const { return inputLayout_; }

private:
    /// Input layout object.
    void* inputLayout_;
};

}
