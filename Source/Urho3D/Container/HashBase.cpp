// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"

#include "../DebugNew.h"

namespace Dviglo
{

void HashBase::AllocateBuckets(unsigned size, unsigned numBuckets)
{
    delete[] ptrs_;

    auto ptrs = new HashNodeBase* [numBuckets + 2];
    auto* data = reinterpret_cast<unsigned*>(ptrs);
    data[0] = size;
    data[1] = numBuckets;
    ptrs_ = ptrs;

    ResetPtrs();
}

void HashBase::ResetPtrs()
{
    // Reset bucket pointers
    if (!ptrs_)
        return;

    unsigned numBuckets = NumBuckets();
    HashNodeBase** ptrs = Ptrs();
    for (unsigned i = 0; i < numBuckets; ++i)
        ptrs[i] = nullptr;
}

}
