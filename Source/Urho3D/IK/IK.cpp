// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../IK/IK.h"
#include "../IK/IKConstraint.h"
#include "../IK/IKEffector.h"
#include "../IK/IKSolver.h"

namespace Dviglo
{

const char* IK_CATEGORY = "Inverse Kinematics";

// ----------------------------------------------------------------------------
void RegisterIKLibrary(Context* context)
{
    //IKConstraint::RegisterObject(context);
    IKEffector::RegisterObject(context);
    IKSolver::RegisterObject(context);
}

} // namespace Dviglo
