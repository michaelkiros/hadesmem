// Copyright Joshua Boyce 2010-2012.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// This file is part of HadesMem.
// <http://www.raptorfactor.com/> <raptorfactor@raptorfactor.com>

#pragma once

#include <locale>

#include <windows.h>

// Disables the user-mode callback exception filter present in 64-bit versions 
// of Windows. Microsoft Support article KB976038 (http://goo.gl/tlIsu).
void DisableUserModeCallbackExceptionFilter();

// Enables CRT debug flags for memory leak detection in debug builds.
void EnableCrtDebugFlags();

// Forces termination of the application if heap corruption is detected.
// Recommended as per Microsoft article "Windows ISV Software Security 
// Defenses" (http://goo.gl/d7WHe).
void EnableTerminationOnHeapCorruption();

// Custom 'bottom up randomization' implementation similar to that of EMET.
// Modified version of code by Didier Stevens (http://goo.gl/LzOAA).
void EnableBottomUpRand();