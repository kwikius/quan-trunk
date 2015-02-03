#ifndef QUAN_AVR_STRING_DUMMY_HPP_INCLUDED
#define QUAN_AVR_STRING_DUMMY_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

#include <quan/avr/cstddef_dummy.hpp>

namespace std{

   template<typename T>
   struct basic_string{

    std::size_t length() const {return 0;}

    T  operator[] (std::size_t i) const { return T();}

     template<typename T1> T1 widen(T1) const { return T1();}

   };

  typedef std::basic_string<char> string;

}

#endif // QUAN_AVR_STRING_DUMMY_HPP_INCLUDED
