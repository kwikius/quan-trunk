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


// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/time.hpp>
#include <quan/velocity.hpp>
#include <quan/length.hpp>
#include <typeinfo>

/*
    check anonymous_cast function
    semantics of output changed
*/

void anonymous_cast_test()
{
    quan::length::m length(1);

    quan::meta::binary_op<
        quan::velocity::m_per_s,
        quan::meta::times,
        quan::time::s
    >::type auto_length;

#ifdef QUAN_ENABLE_SELECTED_HOISTED_QUANTITIES
// length is hoisted
    QUAN_CHECK( ( typeid(auto_length) == typeid(length)));
    QUAN_CHECK( ( typeid(auto_length) != typeid(anonymous_cast(length) )));
#else
   QUAN_CHECK( ( typeid(auto_length) != typeid(length)));
   QUAN_CHECK( ( typeid(auto_length) == typeid(anonymous_cast(length) )));
#endif
}


