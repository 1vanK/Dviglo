// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#ifdef URHO3D_IS_BUILDING
#include "Urho3D.h"
#else
#include <Urho3D/Urho3D.h>
#endif

#include "../Base/Iter.h"
#include "../Container/Swap.h"

namespace Dviglo
{

/// %Vector base class.
/** Note that to prevent extra memory use due to vtable pointer, %VectorBase intentionally does not declare a virtual destructor
    and therefore %VectorBase pointers should never be used.
  */
class URHO3D_API VectorBase
{
public:
    /// Construct.
    VectorBase() noexcept :
        size_(0),
        capacity_(0),
        buffer_(nullptr)
    {
    }

    /// Swap with another vector.
    void Swap(VectorBase& rhs)
    {
        Dviglo::Swap(size_, rhs.size_);
        Dviglo::Swap(capacity_, rhs.capacity_);
        Dviglo::Swap(buffer_, rhs.buffer_);
    }

protected:
    static unsigned char* AllocateBuffer(unsigned size);

    /// Size of vector.
    unsigned size_;
    /// Buffer capacity.
    unsigned capacity_;
    /// Buffer.
    unsigned char* buffer_;
};

}
