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
 along with this program. If not, see http://www.gnu.org/licenses.
*/

#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>


using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_from_string_base10()
  {
    ll_bigint v;
    v.from_string_base<10>              ("655341234567893635426");
    QUAN_CHECK(v.to_string_base<10>() == "655341234567893635426")

    v.from_string_base<16>              ("FF0F7654321FFFFFFFFFFFFFFFFFFFFF");
    QUAN_CHECK(v.to_string_base<16>() == "FF0F7654321FFFFFFFFFFFFFFFFFFFFF");

    v.from_string_base<2>("11110001");
    QUAN_CHECK(v.to_string_base<16>() == "F1")
    
    v.from_string_base<16>("FFABCDEF1234567897FCAFCA");
    QUAN_CHECK(v.to_string_base<10>() == "79126376314809684474963210186")
  }

}}

