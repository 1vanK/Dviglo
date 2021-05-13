// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Core/Object.h"

namespace Dviglo
{

/// Log message event.
URHO3D_EVENT(E_LOGMESSAGE, LogMessage)
{
    URHO3D_PARAM(P_MESSAGE, Message);              // String
    URHO3D_PARAM(P_LEVEL, Level);                  // int
}

/// Async system command execution finished.
URHO3D_EVENT(E_ASYNCEXECFINISHED, AsyncExecFinished)
{
    URHO3D_PARAM(P_REQUESTID, RequestID);          // unsigned
    URHO3D_PARAM(P_EXITCODE, ExitCode);            // int
}

}
