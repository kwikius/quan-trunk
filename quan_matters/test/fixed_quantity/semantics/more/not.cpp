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


#include <quan_matters/test/test.hpp>
#include <quan/length.hpp>

void not_test()
{
   quan::length::mm var1;

   QUAN_CHECK( !var1 );

   quan::length::ft var2(0);
   QUAN_CHECK( !var2 );

   QUAN_CHECK( !!var2 ==false );

   quan::length::mi var3(1.5);

   QUAN_CHECK( !var3 ==false );
   QUAN_CHECK( !!var3 );
   
}
