// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Container/Vector.h"
#include "../Container/List.h"
#include "../Container/HashSet.h"
#include "../Container/HashMap.h"

#include <algorithm>

// VS2010+ and other compilers: use std::begin(), std::end() & range based for
// C++11 features need to be enabled
#if !defined(_MSC_VER) || _MSC_VER > 1600
#define foreach(VAL, VALS) for (VAL : VALS)
// Fallback solution for VS2010. Will have problem with break statement.
// See https://github.com/urho3d/Urho3D/issues/561
#else

namespace Dviglo
{

template<typename T>
struct false_wrapper {
    false_wrapper(const T& value) : value(value) { }
    operator bool() const { return false; }
    T value;
};

template<typename T>
false_wrapper<T> make_false_wrapper(const T& value) {
    return false_wrapper<T>(value);
}

// vector support functions

template <class T>
Dviglo::RandomAccessIterator<T> Begin(Dviglo::Vector<T> &v) {
    return v.Begin();
}
template <class T>
Dviglo::RandomAccessIterator<T> Begin(Dviglo::Vector<T> *v) {
    return v->Begin();
}

template <class T>
Dviglo::RandomAccessConstIterator<T> Begin(const Dviglo::Vector<T> &v) {
    return v.Begin();
}
template <class T>
Dviglo::RandomAccessConstIterator<T> Begin(const Dviglo::Vector<T> *v) {
    return v->Begin();
}

template <class T>
Dviglo::RandomAccessIterator<T> End(Dviglo::Vector<T> &v) {
    return v.End();
}
template <class T>
Dviglo::RandomAccessIterator<T> End(Dviglo::Vector<T> *v) {
    return v->End();
}

template <class T>
Dviglo::RandomAccessConstIterator<T> End(const Dviglo::Vector<T> &v) {
    return v.End();
}
template <class T>
Dviglo::RandomAccessConstIterator<T> End(const Dviglo::Vector<T> *v) {
    return v->End();
}

// podvector support functions

template <class T>
Dviglo::RandomAccessIterator<T> Begin(Dviglo::PODVector<T> &v) {
    return v.Begin();
}
template <class T>
Dviglo::RandomAccessIterator<T> Begin(Dviglo::PODVector<T> *v) {
    return v->Begin();
}

template <class T>
Dviglo::RandomAccessConstIterator<T> Begin(const Dviglo::PODVector<T> &v) {
    return v.Begin();
}
template <class T>
Dviglo::RandomAccessConstIterator<T> Begin(const Dviglo::PODVector<T> *v) {
    return v->Begin();
}

template <class T>
Dviglo::RandomAccessIterator<T> End(Dviglo::PODVector<T> &v) {
    return v.End();
}
template <class T>
Dviglo::RandomAccessIterator<T> End(Dviglo::PODVector<T> *v) {
    return v->End();
}

template <class T>
Dviglo::RandomAccessConstIterator<T> End(const Dviglo::PODVector<T> &v) {
    return v.End();
}
template <class T>
Dviglo::RandomAccessConstIterator<T> End(const Dviglo::PODVector<T> *v) {
    return v->End();
}

}

#define foreach(VAL, VALS) \
    if (const auto& _foreach_begin = Dviglo::make_false_wrapper(Dviglo::Begin(VALS))) { } else \
    if (const auto& _foreach_end = Dviglo::make_false_wrapper(Dviglo::End(VALS))) { } else \
    for (auto it = _foreach_begin.value; it != _foreach_end.value; ++it) \
    if (bool _foreach_flag = false) { } else \
    for (VAL = *it; !_foreach_flag; _foreach_flag = true)

#endif
