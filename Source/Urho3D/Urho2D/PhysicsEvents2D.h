// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Core/Object.h"

// For prestep / poststep events, which are the same for 2D and 3D physics. The events themselves don't depend
// on whether 3D physics support or Bullet has been compiled in.
#include "../Physics/PhysicsEvents.h"

namespace Dviglo
{

/// Physics update contact. Global event sent by PhysicsWorld2D.
URHO3D_EVENT(E_PHYSICSUPDATECONTACT2D, PhysicsUpdateContact2D)
{
    URHO3D_PARAM(P_WORLD, World);                  // PhysicsWorld2D pointer
    URHO3D_PARAM(P_BODYA, BodyA);                  // RigidBody2D pointer
    URHO3D_PARAM(P_BODYB, BodyB);                  // RigidBody2D pointer
    URHO3D_PARAM(P_NODEA, NodeA);                  // Node pointer
    URHO3D_PARAM(P_NODEB, NodeB);                  // Node pointer
    URHO3D_PARAM(P_CONTACTS, Contacts);            // Buffer containing position (Vector2), normal (Vector2), negative overlap distance (float). Normal is the same for all points.
    URHO3D_PARAM(P_SHAPEA, ShapeA);                // CollisionShape2D pointer
    URHO3D_PARAM(P_SHAPEB, ShapeB);                // CollisionShape2D pointer
    URHO3D_PARAM(P_ENABLED, Enabled);              // bool [in/out]
}

/// Physics begin contact. Global event sent by PhysicsWorld2D.
URHO3D_EVENT(E_PHYSICSBEGINCONTACT2D, PhysicsBeginContact2D)
{
    URHO3D_PARAM(P_WORLD, World);                  // PhysicsWorld2D pointer
    URHO3D_PARAM(P_BODYA, BodyA);                  // RigidBody2D pointer
    URHO3D_PARAM(P_BODYB, BodyB);                  // RigidBody2D pointer
    URHO3D_PARAM(P_NODEA, NodeA);                  // Node pointer
    URHO3D_PARAM(P_NODEB, NodeB);                  // Node pointer
    URHO3D_PARAM(P_CONTACTS, Contacts);            // Buffer containing position (Vector2), normal (Vector2), negative overlap distance (float). Normal is the same for all points.
    URHO3D_PARAM(P_SHAPEA, ShapeA);                // CollisionShape2D pointer
    URHO3D_PARAM(P_SHAPEB, ShapeB);                // CollisionShape2D pointer
}

/// Physics end contact. Global event sent by PhysicsWorld2D.
URHO3D_EVENT(E_PHYSICSENDCONTACT2D, PhysicsEndContact2D)
{
    URHO3D_PARAM(P_WORLD, World);                  // PhysicsWorld2D pointer
    URHO3D_PARAM(P_BODYA, BodyA);                  // RigidBody2D pointer
    URHO3D_PARAM(P_BODYB, BodyB);                  // RigidBody2D pointer
    URHO3D_PARAM(P_NODEA, NodeA);                  // Node pointer
    URHO3D_PARAM(P_NODEB, NodeB);                  // Node pointer
    URHO3D_PARAM(P_CONTACTS, Contacts);            // Buffer containing position (Vector2), normal (Vector2), negative overlap distance (float). Normal is the same for all points.
    URHO3D_PARAM(P_SHAPEA, ShapeA);                // CollisionShape2D pointer
    URHO3D_PARAM(P_SHAPEB, ShapeB);                // CollisionShape2D pointer
}

/// Node update contact. Sent by scene nodes participating in a collision.
URHO3D_EVENT(E_NODEUPDATECONTACT2D, NodeUpdateContact2D)
{
    URHO3D_PARAM(P_BODY, Body);                    // RigidBody2D pointer
    URHO3D_PARAM(P_OTHERNODE, OtherNode);          // Node pointer
    URHO3D_PARAM(P_OTHERBODY, OtherBody);          // RigidBody2D pointer
    URHO3D_PARAM(P_CONTACTS, Contacts);            // Buffer containing position (Vector2), normal (Vector2), negative overlap distance (float). Normal is the same for all points.
    URHO3D_PARAM(P_SHAPE, Shape);                  // CollisionShape2D pointer
    URHO3D_PARAM(P_OTHERSHAPE, OtherShape);        // CollisionShape2D pointer
    URHO3D_PARAM(P_ENABLED, Enabled);              // bool [in/out]
}

/// Node begin contact. Sent by scene nodes participating in a collision.
URHO3D_EVENT(E_NODEBEGINCONTACT2D, NodeBeginContact2D)
{
    URHO3D_PARAM(P_BODY, Body);                    // RigidBody2D pointer
    URHO3D_PARAM(P_OTHERNODE, OtherNode);          // Node pointer
    URHO3D_PARAM(P_OTHERBODY, OtherBody);          // RigidBody2D pointer
    URHO3D_PARAM(P_CONTACTS, Contacts);            // Buffer containing position (Vector2), normal (Vector2), negative overlap distance (float). Normal is the same for all points.
    URHO3D_PARAM(P_SHAPE, Shape);                  // CollisionShape2D pointer
    URHO3D_PARAM(P_OTHERSHAPE, OtherShape);        // CollisionShape2D pointer
}

/// Node end contact. Sent by scene nodes participating in a collision.
URHO3D_EVENT(E_NODEENDCONTACT2D, NodeEndContact2D)
{
    URHO3D_PARAM(P_BODY, Body);                    // RigidBody2D pointer
    URHO3D_PARAM(P_OTHERNODE, OtherNode);          // Node pointer
    URHO3D_PARAM(P_OTHERBODY, OtherBody);          // RigidBody2D pointer
    URHO3D_PARAM(P_CONTACTS, Contacts);            // Buffer containing position (Vector2), normal (Vector2), negative overlap distance (float). Normal is the same for all points.
    URHO3D_PARAM(P_SHAPE, Shape);                  // CollisionShape2D pointer
    URHO3D_PARAM(P_OTHERSHAPE, OtherShape);        // CollisionShape2D pointer
}

}
