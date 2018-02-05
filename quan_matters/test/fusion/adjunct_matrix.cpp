
#include <quan_matters/test/test.hpp>

#include <quan/fusion/matrix.hpp>

void adjunct_matrix_test1()
{
   auto constexpr m = quan::fusion::make_matrix<2>
   (
      1.0,2.0,
      3.0, 4.0
   );

   auto const view = quan::fun::adjunct_view<quan::meta::strip_cr<decltype(m)>::type>{m};

   QUAN_CHECK( (view.at<0,0>() == 4.f) )
   QUAN_CHECK( (view.at<0,1>() == -2.f) )

   QUAN_CHECK( (view.at<1,0>() == -3.f) )
   QUAN_CHECK( (view.at<1,1>() == 1.f) )

}
