// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"

#include "../Graphics/Graphics.h"
#include "../Graphics/GPUObject.h"

#include "../DebugNew.h"

namespace Dviglo
{

GPUObject::GPUObject(Graphics* graphics) :
    graphics_(graphics)
{
#ifdef URHO3D_OPENGL
    object_.name_ = 0;
#else
    object_.ptr_ = nullptr;
#endif

    if (graphics_)
        graphics->AddGPUObject(this);
}

GPUObject::~GPUObject()
{
    if (graphics_)
        graphics_->RemoveGPUObject(this);
}

void GPUObject::OnDeviceLost()
{
#ifdef URHO3D_OPENGL
    // On OpenGL the object has already been lost at this point; reset object name
    object_.name_ = 0;
#endif
}

void GPUObject::OnDeviceReset()
{
}

void GPUObject::Release()
{
}

void GPUObject::ClearDataLost()
{
    dataLost_ = false;
}

Graphics* GPUObject::GetGraphics() const
{
    return graphics_;
}

}
