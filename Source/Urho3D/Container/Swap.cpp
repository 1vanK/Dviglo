// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#include "../Precompiled.h"

#include "../Container/ListBase.h"

namespace Dviglo
{

template <> void Swap<String>(String& first, String& second)
{
    first.Swap(second);
}

template <> void Swap<VectorBase>(VectorBase& first, VectorBase& second)
{
    first.Swap(second);
}

template <> void Swap<ListBase>(ListBase& first, ListBase& second)
{
    first.Swap(second);
}

template <> void Swap<HashBase>(HashBase& first, HashBase& second)
{
    first.Swap(second);
}

}
