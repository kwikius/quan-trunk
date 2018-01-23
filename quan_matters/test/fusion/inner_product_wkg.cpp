
#include <quan_matters/test/test.hpp>
#include <quan/fun/inner_product_seq.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <tuple>
#include <quan/fun/vector3.hpp>
#include <quan/fun/vector9.hpp>
#include <quan/fun/vector16.hpp>
int errors = 0;

namespace fusion {
   
   template <typename SeqL, typename SeqR, typename FF , typename F>
   typename quan::fun::inner_product_seq::result<SeqL,SeqR,FF,F>::type
   inner_product(SeqL & seql, SeqR & seqr, FF const & ff, F const & f)
   {
       return quan::fun::inner_product_seq{}(seql,seqr,ff,f);
   }
}

int main()
{
#if 1
   auto seqL = quan::fun::vector16<
         int,int,int,int,
         int,int,int,int,
         int,int,int,int,
         int,int,int,int >{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
   auto seqR = quan::fun::vector16<
         int,int,int,int,
         int,int,int,int,
         int,int,int,int,
         int,int,int,int >{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
#else
   auto seqL = quan::fun::vector3<int,int,int>{1,2,3};
   auto seqR = quan::fun::vector3<int,int,int>{1,2,3};
#endif
   typedef quan::fun::inner_product_seq::result<
         decltype(seqL),decltype(seqR),quan::operator_plus,quan::operator_times
   >::type
   result_type;

  // QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

   result_type r = fusion::inner_product(seqL,seqR,quan::operator_plus{},quan::operator_times{});

   int sum = 0;
   for ( int i = 1 ; i <= quan::fun::size_seq<decltype(seqL)>::value ;++i){
     sum += i * i;
   }
   std::cout << " r = " << r <<'\n';
   std::cout << " sum = " << sum <<'\n';

   QUAN_CHECK(r == sum);
   EPILOGUE
}
