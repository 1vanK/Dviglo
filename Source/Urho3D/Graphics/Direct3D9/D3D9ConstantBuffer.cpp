// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../../Precompiled.h"

#include "../../Graphics/Graphics.h"
#include "../../Graphics/ConstantBuffer.h"
#include "../../IO/Log.h"

#include "../../DebugNew.h"

namespace Dviglo
{

void ConstantBuffer::OnDeviceReset()
{
}

void ConstantBuffer::Release()
{
}

bool ConstantBuffer::SetSize(unsigned size)
{
    URHO3D_LOGERROR("Constant buffers are not supported on Direct3D9");
    return false;
}

void ConstantBuffer::Apply()
{
}

}
