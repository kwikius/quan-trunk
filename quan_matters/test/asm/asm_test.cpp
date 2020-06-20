
#include <quan_matters/test/test.hpp>
#include <quan/rational.hpp>
#include <quan/meta/numbits.hpp>
#include <iostream>

template <typename T>
std::ostream & operator << (std::ostream & os, quan::asm_::extended_reg<T> const & v)
{
   return os  << " hi = " << static_cast<int>(v.hi) << ",lo = " << static_cast<int>(v.lo) << " sign = " << v.sign << '\n';
}

template <typename T>
std::ostream & operator << (std::ostream & os, quan::rational<T> const & v)
{
   typedef typename std::common_type<T,int>::type int_type;
   return os << static_cast<int_type>(v.num) << " / " << static_cast<int_type>(v.den) << '\n';
}

/*
  currently failing with 
   ereg x{18,8};
   ereg y{1,16};
*/
namespace {
   typedef uint8_t ruint;
   using ereg = quan::asm_::extended_reg<ruint>;
}
void ereg_test()
{
   
}

uint32_t to_uint32( ereg const & in)
{
   assert(in.sign ==1);
   int constexpr nbits = quan::meta::numbits<ruint>::value;
   return (static_cast<uint32_t>(in.hi) << nbits) + static_cast<uint32_t>(in.lo);
}

ereg to_ereg(uint32_t const & v)
{
   auto const lo = static_cast<ruint>(v & 0xff);
   auto const hi = static_cast<ruint>( (v & 0xff00) >> 8U);
   return {hi,lo,1};
}

void ereg_modulo_test()
{
   ereg x{254,7};
   std::cout << "x = " << x <<'\n';
   uint32_t xv = to_uint32(x);
   
   ereg y{255,7};
   std::cout << "y = " << y <<'\n';
   uint32_t yv = to_uint32(y);

   auto r = extended_modulus_unsigned(x,y);
   uint32_t rc = to_uint32(r);

   uint32_t rv = xv % yv;

   QUAN_CHECK( rv == rc);

   std::cout << "r = " << r <<'\n';
   std::cout << "r calc = " << rc <<'\n';
   std::cout << "r value = " << rv <<'\n';

}

/**
* N.B takes several hours to complete!
*/
void ereg_compare_test()
{
   for ( uint32_t x = 0; x <= (255*255);++x){
      std::cout << "*\n";
      for ( uint32_t y = 0; y <= (255*255);++y){
         
         auto const r1a = to_ereg(x) < to_ereg(y);
         auto const r1b = x < y;
         QUAN_CHECK(r1a == r1b);
         if ( r1a != r1b){
            
            std::cout << "< failed with (" << x << "," << y <<")\n";
            std::cout << "to_ereg(x) = " << to_ereg(x) <<'\n';
            std::cout << "to_ereg(y) = " << to_ereg(y) <<'\n';
            return;
         }
        // QUAN_CHECK(r1a == r1b);

         auto const r2a = to_ereg(x) <= to_ereg(y);
         auto const r2b = x <= y;
         QUAN_CHECK(r2a == r2b);
         if ( r2a != r2b){
            std::cout << "<= failed with (" << x << "," << y << ")\n";
            std::cout << "to_ereg(x) = " << to_ereg(x) <<'\n';
            std::cout << "to_ereg(y) = " << to_ereg(y) <<'\n';
            return;
         }

         auto const r3a = to_ereg(x) == to_ereg(y);
         auto const r3b = x == y;
         QUAN_CHECK(r3a == r3b);
         if ( r3a != r3b){
            std::cout << "== failed with (" << x << "," << y  << ")\n";
            std::cout << "to_ereg(x) = " << to_ereg(x) <<'\n';
            std::cout << "to_ereg(y) = " << to_ereg(y) <<'\n';
            return;
         }

         auto const r4a = to_ereg(x) != to_ereg(y);
         auto const r4b = x != y;
         QUAN_CHECK(r4a == r4b);
         if ( r4a != r4b){
            std::cout << "!= failed with (" << x << "," << y << ")\n";
            std::cout << "to_ereg(x) = " << to_ereg(x) <<'\n';
            std::cout << "to_ereg(y) = " << to_ereg(y) <<'\n';
            return;
         }

         auto const r5a = to_ereg(x) >= to_ereg(y);
         auto const r5b = x >= y;
         QUAN_CHECK(r5a == r5b);
         if ( r5a != r5b){
            std::cout << ">= failed with (" << x << "," << y << ")\n";
            std::cout << "to_ereg(x) = " << to_ereg(x) <<'\n';
            std::cout << "to_ereg(y) = " << to_ereg(y) <<'\n';
            return;
         }

         auto const r6a = to_ereg(x) > to_ereg(y);
         auto const r6b = x > y;
         QUAN_CHECK(r6a == r6b);
         if ( r6a != r6b){
            std::cout << "> failed with (" << x << "," << y << ")\n";
            std::cout << "to_ereg(x) = " << to_ereg(x) <<'\n';
            std::cout << "to_ereg(y) = " << to_ereg(y) <<'\n';
            return;
         }
      }
   }
}

int errors = 0;
int main()
{

  // ereg_compare_test(); !!!takes hours

   ereg_modulo_test();

   QUAN_EPILOGUE

//   quan::rational<ruint> r1{16,6};
//   quan::rational<ruint> r2{13,4};
//   auto res = r1 * r2 ;
//
//   std::cout << "res = " << res << '\n';

}




