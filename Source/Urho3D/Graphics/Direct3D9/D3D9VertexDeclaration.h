// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../../Container/RefCounted.h"
#include "../../Container/Vector.h"
#include "../../Graphics/GraphicsDefs.h"

#include <d3d9.h>

namespace Dviglo
{

class Graphics;
class VertexBuffer;

/// One element in a vertex declaration. In contrast to the VertexElement structure, takes into account the stream source index.
struct VertexDeclarationElement
{
    /// Element type.
    VertexElementType type_;
    /// Element semantic.
    VertexElementSemantic semantic_;
    /// Semantic index.
    unsigned char index_;
    /// Stream index.
    unsigned char streamIndex_;
    /// Byte offset.
    unsigned offset_;
};

/// Vertex declaration.
class URHO3D_API VertexDeclaration : public RefCounted
{
public:
    /// Construct with a single buffer's vertex element list.
    VertexDeclaration(Graphics* graphics, const PODVector<VertexElement>& srcElements);
    /// Construct with vertex buffers to base declaration on. Higher index buffers will override semantics on lower indices.
    VertexDeclaration(Graphics* graphics, const PODVector<VertexBuffer*>& buffers);
    /// Construct with vertex buffers (shared pointer vector) to base declaration on. Higher index buffers will override semantics on lower indices.
    VertexDeclaration(Graphics* graphics, const Vector<SharedPtr<VertexBuffer> >& buffers);
    /// Destruct.
    ~VertexDeclaration();

    /// Return Direct3D vertex declaration.
    IDirect3DVertexDeclaration9* GetDeclaration() const { return declaration_; }

private:
    /// Create declaration.
    void Create(Graphics* graphics, const PODVector<VertexDeclarationElement>& elements);
    /// Release declaration.
    void Release();

    /// Direct3D vertex declaration.
    IDirect3DVertexDeclaration9* declaration_;
};

}
