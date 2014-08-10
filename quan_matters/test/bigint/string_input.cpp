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
#include "ll_bigint_test.hpp"

#if (0)
void quan::test::ll_bigint_string_input_test1()
{
   using quan::detail::ll_bigint;
   typedef ll_bigint::uint32 uint32;

   std::string str = "123456789123456789123456789";
   ll_bigint num = str;
   num.assign_from_string(str);
   QUAN_CHECK(( num.to_string() == str))
}
#endif
