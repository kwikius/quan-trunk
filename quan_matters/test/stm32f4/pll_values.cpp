
#include <quan_matters/test/test.hpp>
#include <quan/out/bigint.hpp>
#include <quan/out/big_rational.hpp>

int errors = 0;

/*
  get stm32f4 pll values
inputs ( in Hz)
   clk_in. = HSE or HSI ie xtal
   sys_clk = target sysclk frequency
 , pll_vco_in ?= 2000000 = vco input frequency recommanded 2 MHz but can be between 1 2 MHz

*/
int main()
{
   // pll_vco = (clk_in/ pllm) * pllm 
   // sys_clk = pll_vco / pllp 
   // pll_vco_in = 2MHz  
   // pllm = clk_in / pll_vco_in {Eqn 1 } where 2<= pllm <= 63 
   // pll_vco = sysclk * pllp where pllp = 2 or 4 or 6 or 8, and 64 MHz <= pll_vco <= 432 MHz
   // plln = pll_vco / pll_vco_in; where 64 <= plln <= 432 

   // prog clk_in=XXX sys_clk=YYY [ pll_vco=ZZZ ]
 
   static const quan::bigint clk_in =  8000000;
   static const quan::bigint sys_clk = 168000000;
   // pll_vco_in can be other values between 1 and 2 MHz though 2 MHz is recommended
   // to avoid jitter. ref man 5.3.2
   quan::bigint const pll_vco_in = 2000000;
 
   // from pll_vco_in and clk_in, derive the required value of 
   // pllm, independednt of other values 
   quan::big_rational const pllm{clk_in , pll_vco_in}; // Eqn 1

   // pllm must be between 2 and 63 refman 5.3.2
   QUAN_CHECK(pllm.is_integral())
   QUAN_CHECK ( ( pllm >= quan::big_rational{2} ) && ( pllm <= quan::big_rational{63} ) )

   quan::bigint pllp;
   quan::bigint pll_vco;
   quan::big_rational plln;
  
   // pll_vco must be a multiple of sys_clk of 2,4,6 or 8 (pllp) .refman 5.3.2
   // and pll_vco must be between 64 MHz and 432 MHz. refnman 5.3.2
   // so go through the available PLLP values looking for a match
   int multipliers[]={2,4,6,8};
   for ( int i =0; i < 4;++i){ 
      quan::bigint pllp1 = multipliers[i];
      quan::bigint pll_vco1 = sys_clk * pllp1;
      quan::big_rational plln1 = pll_vco1 / pll_vco_in; 
      if ( ( pll_vco1 >= quan::big_rational{64000000} )
                  && (pll_vco1 <=  quan::big_rational{432000000} ) && plln1.is_integral() )
      {
         pllp = pllp1;
         pll_vco = pll_vco1;
         plln = plln1;
         break;
      }
   }

   QUAN_CHECK(pllp != 0) // if this fails no match found
 
   std::cout << "pllm = " << pllm << '\n';
   std::cout << "plln = " << plln << '\n';
   std::cout << "pllp = " << pllp << '\n';

   std::cout << "pll_vco = " << pll_vco << '\n';

   QUAN_CHECK(sys_clk == ((clk_in / pllm) * plln ) / pllp  );
   QUAN_CHECK(plln.is_integral())
   QUAN_CHECK((plln >= quan::big_rational{64}) &&( plln <= quan::big_rational{432}))

  // QUAN_CHECK((pllp == 2) || (pllp == 4) || (pllp == 6) || (pllp == 8) )
   QUAN_CHECK((pll_vco >= quan::big_rational{64000000} ) && (pll_vco <=  quan::big_rational{432000000} ) )
   QUAN_CHECK(pll_vco_in == 2000000)

   EPILOGUE
}