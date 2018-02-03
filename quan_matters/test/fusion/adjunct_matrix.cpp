

#include <quan_matters/test/test.hpp>

#include <quan/out/length.hpp>
#include <quan/fusion/make_matrix.hpp>
#include <quan/fun/adjunct_view.hpp>
#include <quan/fun/matrix_row.hpp>
#include <quan/fun/matrix_col.hpp>
#include <quan/fun/at.hpp>
#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/area.hpp>
#include <quan/velocity.hpp>
#include <quan/reciprocal_length.hpp>
#include <quan/fusion/static_value.hpp>
#include <quan/fixed_quantity/literal.hpp>

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