// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../../Precompiled.h"

#include "../../Graphics/Graphics.h"
#include "../../Graphics/GraphicsImpl.h"

#include "../../DebugNew.h"

namespace Dviglo
{

GraphicsImpl::GraphicsImpl() :
    interface_(nullptr),
    device_(nullptr),
    defaultColorSurface_(nullptr),
    defaultDepthStencilSurface_(nullptr),
    frameQuery_(nullptr),
    adapter_(D3DADAPTER_DEFAULT),
    deviceType_(D3DDEVTYPE_HAL),
    shaderProgram_(nullptr),
    deviceLost_(false),
    queryIssued_(false)
{
    memset(&presentParams_, 0, sizeof presentParams_);
}

bool GraphicsImpl::CheckFormatSupport(D3DFORMAT format, DWORD usage, D3DRESOURCETYPE type)
{
    return interface_ ? SUCCEEDED(interface_->CheckDeviceFormat(adapter_, deviceType_, D3DFMT_X8R8G8B8, usage, type, format)) :
        false;
}

bool GraphicsImpl::CheckMultiSampleSupport(D3DFORMAT format, int level)
{
    return interface_ ? SUCCEEDED(interface_->CheckDeviceMultiSampleType(adapter_, deviceType_, format, FALSE,
        (D3DMULTISAMPLE_TYPE)level, nullptr)) : false;
}

}
