// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"

#include "../Audio/SoundListener.h"
#include "../Core/Context.h"

namespace Dviglo
{

extern const char* AUDIO_CATEGORY;

SoundListener::SoundListener(Context* context) :
    Component(context)
{
}

SoundListener::~SoundListener() = default;

void SoundListener::RegisterObject(Context* context)
{
    context->RegisterFactory<SoundListener>(AUDIO_CATEGORY);

    URHO3D_ACCESSOR_ATTRIBUTE("Is Enabled", IsEnabled, SetEnabled, bool, true, AM_DEFAULT);
}

}
