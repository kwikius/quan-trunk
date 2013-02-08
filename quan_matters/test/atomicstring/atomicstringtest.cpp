
/*  atomicstring test */

#include <quan/gc.hpp>
#include <quan/atomicstring.hpp>
#include <quan_matters/test/simple_test.hpp>
#include <iostream>
#include <string>

int errors = 0;

int main()
{
   quan::gc_init();
   typedef quan::atomicstring<char> atom_str;
   auto stra = "hello";
// try to avoid string concatting by gcc
   auto strb = "shello";
   ++strb;
   QUAN_CHECK(! (stra == strb))
   auto strc  = "cello";
  
   atom_str a = stra;
   atom_str b = strb;

   std::string stringa = "hello";
   std::string stringb = "xhello";
   
   QUAN_CHECK(a == b)
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
   QUAN_CHECK ( ( a != c) )

   QUAN_EPILOGUE
}