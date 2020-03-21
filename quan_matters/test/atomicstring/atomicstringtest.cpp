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

/*  atomicstring test */

//#include <quan/gc.hpp>
#include <quan/atomicstring.hpp>
#include <quan_matters/test/simple_test.hpp>
#include <iostream>
#include <string>

int errors = 0;

int main()
{
   //quan::gc_init();
   typedef quan::atomicstring<char> atom_str;

   // try to avoid string concatting by gcc
   // trying to get 2 c strings with same string but different pointers
   char stra [] = "hello";
   char strb [] = "hello";
   // if this fails it is due to optimisation by the compiler
   QUAN_CHECK((stra != strb))
   auto strc  = "cello";
  
   atom_str a = stra;
   atom_str b = strb;

   QUAN_CHECK(a == b)

   std::string stringa = "hello";
   std::string stringb = "xhello";
   
   // check copy ctor
   auto copied = a;
   QUAN_CHECK(copied == a)

   QUAN_CHECK( a == stra)
   QUAN_CHECK(a == strb)
   QUAN_CHECK(a == stringa)
   QUAN_CHECK( stra == a)
   QUAN_CHECK(strb == a)
   QUAN_CHECK( stringa == a)
   QUAN_CHECK(  ! ( strc == a ) )
   QUAN_CHECK( ! ( a == strc) )
   QUAN_CHECK( ! ( a == stringb) )

   atom_str c  = "cello";
   QUAN_CHECK ( ( a != c) )
   QUAN_CHECK ( ! ( a == c) )

   QUAN_CHECK( !(a != stra))
   QUAN_CHECK( ! ( a != strb))
   QUAN_CHECK(a  != stringb)
   QUAN_CHECK( !  ( a != stringa))
   QUAN_CHECK( ! (stra != a))
   QUAN_CHECK( ! ( strb != a))
   QUAN_CHECK(  ( strc != a ) )
   QUAN_CHECK( ( a != strc) )
   QUAN_CHECK( ! (stringa  != a))
   QUAN_CHECK(  (stringb  != a))
   
   QUAN_CHECK ( ( a != c) )

   // check assign
   c = a;
   QUAN_CHECK ( ( a == c) )
   QUAN_CHECK ( !( a != c) )

   char nil1 [] = "";
   char nil2 [] = "";
   
   QUAN_CHECK((nil1 != nil2))

   atom_str atom_nil1 = nil1;
   atom_str atom_nil2 = nil2;

   QUAN_CHECK(atom_nil1 == atom_nil2)

   a = atom_nil1;

   QUAN_CHECK(a != b);
   QUAN_CHECK(b != a);
   QUAN_CHECK(a == atom_nil1)
   QUAN_CHECK(atom_nil1 == a)
   

   QUAN_EPILOGUE
}
