// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Core/Object.h"

namespace Dviglo
{

/// Emitting ParticleEmitter2D particles stopped.
URHO3D_EVENT(E_PARTICLESEND, ParticlesEnd)
{
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
    URHO3D_PARAM(P_EFFECT, Effect);                // ParticleEffect2D pointer
}

/// All ParticleEmitter2D particles have been removed.
URHO3D_EVENT(E_PARTICLESDURATION, ParticlesDuration)
{
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
    URHO3D_PARAM(P_EFFECT, Effect);                // ParticleEffect2D pointer
}

}
