// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"

#include "../Core/EventProfiler.h"

#include "../DebugNew.h"

namespace Dviglo
{

bool EventProfiler::active = false;

EventProfiler::EventProfiler(Context* context) :
    Profiler(context)
{
    // FIXME: Is there a cleaner way?
    delete root_;
    current_ = root_ = new EventProfilerBlock(nullptr, "RunFrame");
    delete [] root_->name_;
    root_->name_ = new char[sizeof("RunFrame")];
    memcpy(root_->name_, "RunFrame", sizeof("RunFrame"));
}

}
