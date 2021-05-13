// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../IO/Serializer.h"
#include "../IO/Deserializer.h"

namespace Dviglo
{

/// A common root class for objects that implement both Serializer and Deserializer.
class URHO3D_API AbstractFile : public Deserializer, public Serializer
{
public:
    /// Construct.
    AbstractFile() : Deserializer() { }
    /// Construct.
    explicit AbstractFile(unsigned int size) : Deserializer(size) { }
    /// Destruct.
    ~AbstractFile() override = default;
    /// Change the file name. Used by the resource system.
    /// @property
    virtual void SetName(const String& name) { name_ = name; }
    /// Return the file name.
    const String& GetName() const override { return name_; }

protected:
    /// File name.
    String name_;
};

}
