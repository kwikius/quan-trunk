
#include <quan_matters/test/test.hpp>
#include <quan/fun/fold_seq.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <tuple>

int errors = 0;

namespace fusion {
   
   template <typename Seq, typename T , typename F>
   typename quan::fun::fold_seq::result<Seq,T,F>::type
   fold(Seq const & seq, T const & init, F const & f)
   {
       return quan::fun::fold_seq{}(seq,init,f);
   }
}

int main()
{
   auto seq = std::make_tuple(1,2,3,-3,-2,-1,27);

   QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

   auto r = fusion::fold(seq,0,quan::operator_plus{});

   QUAN_CHECK(r == 27);

   std::cout << " r = " << r <<'\n';

   EPILOGUE
}
