

#include <quan/fusion/fold.hpp>

#include <quan_matters/test/test.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <tuple>

void fold_test()
{
   auto const seq = std::make_tuple(1,2,3,27.5,-3,-2,-1);

   QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

   auto r = quan::fusion::fold(seq,0,quan::operator_plus{});

   QUAN_CHECK( (std::is_same<decltype(r),double>::value))

   QUAN_CHECK(r == 27.5);

}
