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
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_compare()
  {
    ll_bigint v1 = 1;
    ll_bigint v2 = 2;

    QUAN_CHECK( v1.compare(v2) == -1 );
    QUAN_CHECK( v2.compare(v1) == 1  );
    QUAN_CHECK( v1.compare(v1) == 0  );
    v1 = -100 ;
    QUAN_CHECK( v1.compare(v2) == -1 );
    QUAN_CHECK( v2.compare(v1) == 1  );
    QUAN_CHECK( v1.compare(v1) == 0  );
  }

}}

