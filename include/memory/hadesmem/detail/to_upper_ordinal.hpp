// Copyright (C) 2010-2013 Joshua Boyce.
// See the file COPYING for copying permission.

#pragma once

#include <cassert>
#include <limits>
#include <string>
#include <vector>

#include <windows.h>

#include <hadesmem/error.hpp>

namespace hadesmem
{

namespace detail
{

inline std::wstring ToUpperOrdinal(std::wstring const& str)
{
  std::vector<wchar_t> str_buf(std::begin(str), std::end(str));
  str_buf.push_back(0);
  
  assert(str_buf.size() < (std::numeric_limits<DWORD>::max)());
  DWORD const num_converted = ::CharUpperBuff(str_buf.data(), 
    static_cast<DWORD>(str_buf.size()));
  if (num_converted != str_buf.size())
  {
    DWORD const last_error = ::GetLastError();
    HADESMEM_DETAIL_THROW_EXCEPTION(Error() << 
      ErrorString("CharUpperBuff failed.") << 
      ErrorCodeWinRet(num_converted) << 
      ErrorCodeWinLast(last_error));
  }
  
  return str_buf.data();
}

}

}
