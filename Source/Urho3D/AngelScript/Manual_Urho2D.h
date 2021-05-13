// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#ifdef URHO3D_URHO2D

#include "../Urho2D/ParticleEffect2D.h"
#include "../Urho2D/TileMap2D.h"
#include "../Urho2D/PhysicsWorld2D.h"
#include "../Urho2D/CollisionPolygon2D.h"
#include "../Urho2D/CollisionChain2D.h"
#include "../Urho2D/RigidBody2D.h"

namespace Dviglo
{

// RigidBody2D* PhysicsRaycastResult2D::body_ | File: ../Urho2D/PhysicsWorld2D.h
template <class T> RigidBody2D* PhysicsRaycastResult2D_GetBody(T* ptr)
{
    return ptr->body_;
}

#define REGISTER_MEMBERS_MANUAL_PART_PhysicsRaycastResult2D() \
    /* RigidBody2D* PhysicsRaycastResult2D::body_ | File: ../Urho2D/PhysicsWorld2D.h */ \
    engine->RegisterObjectMethod(className, "RigidBody2D@+ get_body() const", AS_FUNCTION_OBJLAST(PhysicsRaycastResult2D_GetBody<T>), AS_CALL_CDECL_OBJLAST);

// ========================================================================================

// void PhysicsWorld2D::Raycast(PODVector<PhysicsRaycastResult2D>& results, const Vector2& startPoint, const Vector2& endPoint, unsigned collisionMask = M_MAX_UNSIGNED) | File: ../Urho2D/PhysicsWorld2D.h
template <class T> CScriptArray* PhysicsWorld2D_Raycast(const Vector2& startPoint, const Vector2& endPoint, unsigned collisionMask, T* ptr)
{
    PODVector<PhysicsRaycastResult2D> result;
    ptr->Raycast(result, startPoint, endPoint, collisionMask);
    return VectorToArray<PhysicsRaycastResult2D>(result, "Array<PhysicsRaycastResult2D>");
}

// void PhysicsWorld2D::RaycastSingle(PhysicsRaycastResult2D& result, const Vector2& startPoint, const Vector2& endPoint, unsigned collisionMask = M_MAX_UNSIGNED) | File: ../Urho2D/PhysicsWorld2D.h
template <class T> PhysicsRaycastResult2D PhysicsWorld2D_RaycastSingle(const Vector2& startPoint, const Vector2& endPoint, unsigned collisionMask, T* ptr)
{
    PhysicsRaycastResult2D result;
    ptr->RaycastSingle(result, startPoint, endPoint, collisionMask);
    return result;
}

// void PhysicsWorld2D::GetRigidBodies(PODVector<RigidBody2D*>& results, const Rect& aabb, unsigned collisionMask = M_MAX_UNSIGNED) | File: ../Urho2D/PhysicsWorld2D.h
template <class T> CScriptArray* PhysicsWorld2D_GetRigidBodies(const Rect& aabb, unsigned collisionMask, T* ptr)
{
    PODVector<RigidBody2D*> results;
    ptr->GetRigidBodies(results, aabb, collisionMask);
    return VectorToHandleArray<RigidBody2D>(results, "Array<RigidBody2D@>");
}

#define REGISTER_MEMBERS_MANUAL_PART_PhysicsWorld2D() \
    /* void PhysicsWorld2D::Raycast(PODVector<PhysicsRaycastResult2D>& results, const Vector2& startPoint, const Vector2& endPoint, unsigned collisionMask = M_MAX_UNSIGNED) */ \
    engine->RegisterObjectMethod(className, "Array<PhysicsRaycastResult2D>@ Raycast(const Vector2&, const Vector2&, uint = 0xffff)", AS_FUNCTION_OBJLAST(PhysicsWorld2D_Raycast<T>), AS_CALL_CDECL_OBJLAST); \
    \
    /* void PhysicsWorld2D::RaycastSingle(PhysicsRaycastResult2D& result, const Vector2& startPoint, const Vector2& endPoint, unsigned collisionMask = M_MAX_UNSIGNED) | File: ../Urho2D/PhysicsWorld2D.h */ \
    engine->RegisterObjectMethod(className, "PhysicsRaycastResult2D RaycastSingle(const Vector2&, const Vector2&, uint = 0xffff)", AS_FUNCTION_OBJLAST(PhysicsWorld2D_RaycastSingle<T>), AS_CALL_CDECL_OBJLAST); \
    \
    /* void PhysicsWorld2D::GetRigidBodies(PODVector<RigidBody2D*>& results, const Rect& aabb, unsigned collisionMask = M_MAX_UNSIGNED) | File: ../Urho2D/PhysicsWorld2D.h */ \
    engine->RegisterObjectMethod(className, "Array<RigidBody2D@>@ GetRigidBodies(const Rect&in, uint = 0xffff)", AS_FUNCTION_OBJLAST(PhysicsWorld2D_GetRigidBodies<T>), AS_CALL_CDECL_OBJLAST);

}

#endif // def URHO3D_URHO2D
