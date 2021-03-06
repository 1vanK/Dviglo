// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#ifdef URHO3D_IS_BUILDING
#include "Urho3D.h"
#else
#include <Urho3D/Urho3D.h>
#endif

namespace Dviglo
{

/// %Condition on which a thread can wait.
class URHO3D_API Condition
{
public:
    /// Construct.
    Condition();

    /// Destruct.
    ~Condition();

    /// Set the condition. Will be automatically reset once a waiting thread wakes up.
    void Set();

    /// Wait on the condition.
    void Wait();

private:
#ifndef _WIN32
    /// Mutex for the event, necessary for pthreads-based implementation.
    void* mutex_;
#endif
    /// Operating system specific event.
    void* event_;
};

}
