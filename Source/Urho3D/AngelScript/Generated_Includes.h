// DO NOT EDIT. This file is generated

#pragma once

#include "../Audio/Audio.h"
#include "../Audio/AudioDefs.h"
#include "../Audio/BufferedSoundStream.h"
#include "../Audio/OggVorbisSoundStream.h"
#include "../Audio/Sound.h"
#include "../Audio/SoundListener.h"
#include "../Audio/SoundSource.h"
#include "../Audio/SoundSource3D.h"
#include "../Audio/SoundStream.h"
#include "../Container/Allocator.h"
#include "../Container/Hash.h"
#include "../Container/HashBase.h"
#include "../Container/LinkedList.h"
#include "../Container/ListBase.h"
#include "../Container/RefCounted.h"
#include "../Container/Sort.h"
#include "../Container/Str.h"
#include "../Container/VectorBase.h"
#include "../Core/Attribute.h"
#include "../Core/Condition.h"
#include "../Core/Context.h"
#include "../Core/EventProfiler.h"
#include "../Core/Mutex.h"
#include "../Core/Object.h"
#include "../Core/ProcessUtils.h"
#include "../Core/Profiler.h"
#include "../Core/Spline.h"
#include "../Core/StringHashRegister.h"
#include "../Core/StringUtils.h"
#include "../Core/Thread.h"
#include "../Core/Timer.h"
#include "../Core/Variant.h"
#include "../Core/WorkQueue.h"

#ifdef URHO3D_DATABASE
#include "../Database/Database.h"
#endif

#include "../Engine/Console.h"
#include "../Engine/DebugHud.h"
#include "../Engine/Engine.h"
#include "../Engine/EngineDefs.h"
#include "../Graphics/AnimatedModel.h"
#include "../Graphics/Animation.h"
#include "../Graphics/AnimationController.h"
#include "../Graphics/AnimationState.h"
#include "../Graphics/Batch.h"
#include "../Graphics/BillboardSet.h"
#include "../Graphics/Camera.h"
#include "../Graphics/ConstantBuffer.h"
#include "../Graphics/CustomGeometry.h"
#include "../Graphics/DebugRenderer.h"
#include "../Graphics/DecalSet.h"
#include "../Graphics/Drawable.h"
#include "../Graphics/GPUObject.h"
#include "../Graphics/Geometry.h"
#include "../Graphics/Graphics.h"
#include "../Graphics/GraphicsDefs.h"
#include "../Graphics/IndexBuffer.h"
#include "../Graphics/Light.h"
#include "../Graphics/Material.h"
#include "../Graphics/Model.h"
#include "../Graphics/OcclusionBuffer.h"
#include "../Graphics/Octree.h"
#include "../Graphics/OctreeQuery.h"
#include "../Graphics/ParticleEffect.h"
#include "../Graphics/ParticleEmitter.h"
#include "../Graphics/RenderPath.h"
#include "../Graphics/RenderSurface.h"
#include "../Graphics/Renderer.h"
#include "../Graphics/RibbonTrail.h"
#include "../Graphics/Shader.h"
#include "../Graphics/ShaderPrecache.h"
#include "../Graphics/ShaderVariation.h"
#include "../Graphics/Skeleton.h"
#include "../Graphics/Skybox.h"
#include "../Graphics/StaticModel.h"
#include "../Graphics/StaticModelGroup.h"
#include "../Graphics/Tangent.h"
#include "../Graphics/Technique.h"
#include "../Graphics/Terrain.h"
#include "../Graphics/TerrainPatch.h"
#include "../Graphics/Texture.h"
#include "../Graphics/Texture2D.h"
#include "../Graphics/Texture2DArray.h"
#include "../Graphics/Texture3D.h"
#include "../Graphics/TextureCube.h"
#include "../Graphics/VertexBuffer.h"
#include "../Graphics/View.h"
#include "../Graphics/Viewport.h"
#include "../Graphics/Zone.h"

#ifdef URHO3D_IK
#include "../IK/IK.h"
#include "../IK/IKConstraint.h"
#include "../IK/IKEffector.h"
#include "../IK/IKSolver.h"
#endif

#include "../IO/AbstractFile.h"
#include "../IO/Compression.h"
#include "../IO/Deserializer.h"
#include "../IO/File.h"
#include "../IO/FileSystem.h"
#include "../IO/FileWatcher.h"
#include "../IO/Log.h"
#include "../IO/MemoryBuffer.h"
#include "../IO/NamedPipe.h"
#include "../IO/PackageFile.h"
#include "../IO/Serializer.h"
#include "../IO/VectorBuffer.h"
#include "../Input/Controls.h"
#include "../Input/Input.h"
#include "../Input/InputConstants.h"
#include "../LibraryInfo.h"
#include "../Math/AreaAllocator.h"
#include "../Math/BoundingBox.h"
#include "../Math/Color.h"
#include "../Math/Frustum.h"
#include "../Math/MathDefs.h"
#include "../Math/Matrix2.h"
#include "../Math/Matrix3.h"
#include "../Math/Matrix3x4.h"
#include "../Math/Matrix4.h"
#include "../Math/Plane.h"
#include "../Math/Polyhedron.h"
#include "../Math/Quaternion.h"
#include "../Math/Random.h"
#include "../Math/Ray.h"
#include "../Math/Rect.h"
#include "../Math/Sphere.h"
#include "../Math/StringHash.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Math/Vector4.h"

#ifdef URHO3D_NAVIGATION
#include "../Navigation/CrowdAgent.h"
#include "../Navigation/CrowdManager.h"
#include "../Navigation/DynamicNavigationMesh.h"
#include "../Navigation/NavArea.h"
#include "../Navigation/NavBuildData.h"
#include "../Navigation/Navigable.h"
#include "../Navigation/NavigationMesh.h"
#include "../Navigation/Obstacle.h"
#include "../Navigation/OffMeshConnection.h"
#endif

#ifdef URHO3D_NETWORK
#include "../Network/Connection.h"
#include "../Network/HttpRequest.h"
#include "../Network/Network.h"
#include "../Network/NetworkPriority.h"
#include "../Network/Protocol.h"
#endif

#ifdef URHO3D_PHYSICS
#include "../Physics/CollisionShape.h"
#include "../Physics/Constraint.h"
#include "../Physics/PhysicsWorld.h"
#include "../Physics/RaycastVehicle.h"
#include "../Physics/RigidBody.h"
#endif

#ifdef URHO3D_URHO2D
#include "../Physics2D/CollisionBox2D.h"
#include "../Physics2D/CollisionChain2D.h"
#include "../Physics2D/CollisionCircle2D.h"
#include "../Physics2D/CollisionEdge2D.h"
#include "../Physics2D/CollisionPolygon2D.h"
#include "../Physics2D/CollisionShape2D.h"
#include "../Physics2D/Constraint2D.h"
#include "../Physics2D/ConstraintDistance2D.h"
#include "../Physics2D/ConstraintFriction2D.h"
#include "../Physics2D/ConstraintGear2D.h"
#include "../Physics2D/ConstraintMotor2D.h"
#include "../Physics2D/ConstraintMouse2D.h"
#include "../Physics2D/ConstraintPrismatic2D.h"
#include "../Physics2D/ConstraintPulley2D.h"
#include "../Physics2D/ConstraintRevolute2D.h"
#include "../Physics2D/ConstraintRope2D.h"
#include "../Physics2D/ConstraintWeld2D.h"
#include "../Physics2D/ConstraintWheel2D.h"
#include "../Physics2D/Physics2D.h"
#include "../Physics2D/PhysicsWorld2D.h"
#include "../Physics2D/RigidBody2D.h"
#endif

#include "../Resource/BackgroundLoader.h"
#include "../Resource/Decompress.h"
#include "../Resource/Image.h"
#include "../Resource/JSONFile.h"
#include "../Resource/JSONValue.h"
#include "../Resource/Localization.h"
#include "../Resource/Resource.h"
#include "../Resource/ResourceCache.h"
#include "../Resource/XMLElement.h"
#include "../Resource/XMLFile.h"
#include "../Scene/Animatable.h"
#include "../Scene/AnimationDefs.h"
#include "../Scene/Component.h"
#include "../Scene/LogicComponent.h"
#include "../Scene/Node.h"
#include "../Scene/ObjectAnimation.h"
#include "../Scene/ReplicationState.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResolver.h"
#include "../Scene/Serializable.h"
#include "../Scene/SmoothedTransform.h"
#include "../Scene/SplinePath.h"
#include "../Scene/UnknownComponent.h"
#include "../Scene/ValueAnimation.h"
#include "../Scene/ValueAnimationInfo.h"
#include "../UI/BorderImage.h"
#include "../UI/Button.h"
#include "../UI/CheckBox.h"
#include "../UI/Cursor.h"
#include "../UI/DropDownList.h"
#include "../UI/FileSelector.h"
#include "../UI/Font.h"
#include "../UI/FontFace.h"
#include "../UI/FontFaceBitmap.h"
#include "../UI/FontFaceFreeType.h"
#include "../UI/LineEdit.h"
#include "../UI/ListView.h"
#include "../UI/Menu.h"
#include "../UI/MessageBox.h"
#include "../UI/ProgressBar.h"
#include "../UI/ScrollBar.h"
#include "../UI/ScrollView.h"
#include "../UI/Slider.h"
#include "../UI/Sprite.h"
#include "../UI/Text.h"
#include "../UI/Text3D.h"
#include "../UI/ToolTip.h"
#include "../UI/UI.h"
#include "../UI/UIBatch.h"
#include "../UI/UIComponent.h"
#include "../UI/UIElement.h"
#include "../UI/UISelectable.h"
#include "../UI/View3D.h"
#include "../UI/Window.h"

#ifdef URHO3D_URHO2D
#include "../Urho2D/AnimatedSprite2D.h"
#include "../Urho2D/AnimationSet2D.h"
#include "../Urho2D/Drawable2D.h"
#include "../Urho2D/ParticleEffect2D.h"
#include "../Urho2D/ParticleEmitter2D.h"
#include "../Urho2D/Renderer2D.h"
#include "../Urho2D/Sprite2D.h"
#include "../Urho2D/SpriteSheet2D.h"
#include "../Urho2D/StaticSprite2D.h"
#include "../Urho2D/StretchableSprite2D.h"
#include "../Urho2D/TileMap2D.h"
#include "../Urho2D/TileMapDefs2D.h"
#include "../Urho2D/TileMapLayer2D.h"
#include "../Urho2D/TmxFile2D.h"
#include "../Urho2D/Urho2D.h"
#endif

// Ignored headers

//#include "../Database/ODBC/ODBCConnection.h"
//#include "../Database/ODBC/ODBCResult.h"
//#include "../Engine/Application.h"
//#include "../Graphics/Direct3D11/D3D11GraphicsImpl.h"
//#include "../Graphics/Direct3D11/D3D11ShaderProgram.h"
//#include "../Graphics/Direct3D11/D3D11VertexDeclaration.h"
//#include "../Graphics/Direct3D9/D3D9VertexDeclaration.h"
//#include "../Graphics/OpenGL/OGLGraphicsImpl.h"

//#ifdef URHO3D_IK
//#include "../IK/IKConverters.h"
//#endif

//#ifdef URHO3D_PHYSICS
//#include "../Physics/PhysicsUtils.h"
//#endif

//#ifdef URHO3D_URHO2D
//#include "../Physics2D/PhysicsUtils2D.h"
//#endif

//#include "../Resource/PListFile.h"
