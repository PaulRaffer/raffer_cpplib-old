
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201103L

#ifndef RAFFER_FINALLY_FINALLY_HPP
#define RAFFER_FINALLY_FINALLY_HPP


#include <functional>


namespace raffer // interface
{

class finally
{
	std::function<void ()> action;

public:
	explicit finally(std::function<void ()> action);
	~finally();
};

} // namespace raffer


#endif // RAFFER_FINALLY_FINALLY_HPP

#endif //  __cplusplus >= 201103L
