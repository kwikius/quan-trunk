

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