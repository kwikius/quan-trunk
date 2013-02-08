
#include <quan_matters/test/simple_test.hpp>

#include <quan/integer.hpp>

int errors =0; 
int main()
{
   typedef quan::integer<uint8_t> integer;

  // std::cout << std::hex << integer::bitmask <<'\n';
   integer a = 1;

   QUAN_CHECK( a == 1)
   //std::cout << a <<'\n';

   integer b = 2;
 // std::cout << std::numeric_limits<int8_t>::max() <<'\n';

   b = 127 ;
   bool caught = false;
   integer temp = b;
   try{
   b *= b ;
   }catch (std::exception & e){
      caught = true;
   }
   QUAN_CHECK(caught)
   b = temp ;
/*
   b /= 2;
   QUAN_CHECK( b == 63)
   b += 3;
   QUAN_CHECK( b == 66)
   b -= 4;
   QUAN_CHECK( b == 62)
   b %= 3 ; // sign of orig lhs?
   QUAN_CHECK( b == 2 )

   caught = false;
   try{
     b = -1;
   }catch (std::exception & e){
      caught = true;
   }
   QUAN_CHECK(caught)
*/
/*
// unsigned only
   b &= 1;
   b <<= 3;
   b >>= 3;
   b &= 3;
   b ^= 5;
   b |= 4;
 */  
  QUAN_EPILOGUE
}