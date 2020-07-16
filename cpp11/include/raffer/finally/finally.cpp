
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201103L

#include "finally.hpp"


namespace raffer // implementation
{

finally::finally(std::function<void ()> action)
: action{std::move(action)} {}

finally::~finally() { action(); }

} // namespace raffer


#endif // __cplusplus >= 201103L
