// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"

#include "../Graphics/Graphics.h"
#include "../Graphics/Shader.h"
#include "../Graphics/ShaderVariation.h"

#include "../DebugNew.h"

namespace Dviglo
{

ShaderParameter::ShaderParameter(const String& name, unsigned glType, int location) :   // NOLINT(hicpp-member-init)
    name_{name},
    glType_{glType},
    location_{location}
{
}

ShaderParameter::ShaderParameter(ShaderType type, const String& name, unsigned offset, unsigned size, unsigned buffer) :    // NOLINT(hicpp-member-init)
    type_{type},
    name_{name},
    offset_{offset},
    size_{size},
    buffer_{buffer}
{
}

ShaderParameter::ShaderParameter(ShaderType type, const String& name, unsigned reg, unsigned regCount) :    // NOLINT(hicpp-member-init)
    type_{type},
    name_{name},
    register_{reg},
    regCount_{regCount}
{
}

ShaderVariation::ShaderVariation(Shader* owner, ShaderType type) :
    GPUObject(owner->GetSubsystem<Graphics>()),
    owner_(owner),
    type_(type)
{
}

ShaderVariation::~ShaderVariation()
{
    Release();
}

void ShaderVariation::SetName(const String& name)
{
    name_ = name;
}

Shader* ShaderVariation::GetOwner() const
{
    return owner_;
}

}
