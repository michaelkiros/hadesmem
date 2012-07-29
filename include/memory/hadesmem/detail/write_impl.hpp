// Copyright Joshua Boyce 2010-2012.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// This file is part of HadesMem.
// <http://www.raptorfactor.com/> <raptorfactor@raptorfactor.com>

#pragma once

#include <cstddef>

#include <windows.h>

namespace hadesmem
{

class Process;

namespace detail
{

void Write(Process const& process, PVOID address, LPCVOID in, std::size_t in_size);

}

}