// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

/*
 * TODO
 *  - Optimise.
 *  - Profile.
 *  - Documentation.
 *
 * FUTURE
 *  - Support for "stretchiness" with min/max lengths.
 *  - Support for "stiffness" factor, describes how well a bone rotates.
 *  - Implement constraints.
 *  - Skip bones when building the tree.
 *  - Mass/Spring/Damper solver.
 */

namespace Dviglo
{

class Context;

/// Registers all IK systems to the specified context.
/// @nobind
void RegisterIKLibrary(Context* context);

} // namespace Dviglo
