//
// libsemigroups - C++ library for semigroups and monoids
// Copyright (C) 2018 James D. Mitchell
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef LIBSEMIGROUPS_INCLUDE_INTERNAL_LIBSEMIGROUPS_EXCEPTION_H_
#define LIBSEMIGROUPS_INCLUDE_INTERNAL_LIBSEMIGROUPS_EXCEPTION_H_

#include <exception>
#include <string>

#include "internal/stl.h"

namespace libsemigroups {
  struct LibsemigroupsException : public std::runtime_error {
    LibsemigroupsException(std::string const& fname,
                           int                linenum,
                           std::string const& msg)
        : std::runtime_error(fname + ":" + to_string(linenum) + ":" + msg) {}
  };

}  // namespace libsemigroups

#define LIBSEMIGROUPS_EXCEPTION(msg) \
  LibsemigroupsException(__FILE__, __LINE__, msg)
#define INTERNAL_EXCEPTION \
  LIBSEMIGROUPS_EXCEPTION("internal error, something went wrong")

#endif  // LIBSEMIGROUPS_INCLUDE_INTERNAL_LIBSEMIGROUPS_EXCEPTION_H_
