// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Core/Object.h"
#include "../Database/DbConnection.h"

namespace Dviglo
{

/// %Database cursor. Event handler could set P_FILTER to true to filter out a row from resultset and P_ABORT to true to stop further cursor events.
URHO3D_EVENT(E_DBCURSOR, DbCursor)
{
    URHO3D_PARAM(P_DBCONNECTION, DbConnection);    // DbConnection pointer
    URHO3D_PARAM(P_RESULTIMPL, ResultImpl);        // Underlying result object pointer (cannot be used in scripting)
    URHO3D_PARAM(P_SQL, SQL);                      // String
    URHO3D_PARAM(P_NUMCOLS, NumCols);              // unsigned
    URHO3D_PARAM(P_COLVALUES, ColValues);          // VariantVector
    URHO3D_PARAM(P_COLHEADERS, ColHeaders);        // StringVector
    URHO3D_PARAM(P_FILTER, Filter);                // bool [in]
    URHO3D_PARAM(P_ABORT, Abort);                  // bool [in]
}

}
