

#include <quan_matters/test/test.hpp>

#include <quan/out/length.hpp>
#include <quan/fusion/make_matrix.hpp>
#include <quan/fun/transpose_matrix.hpp>
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

namespace {

   void transpose_matrix_test1()
   {
      
      auto constexpr m = quan::fusion::make_matrix<1>
      (
         1.234, 5.678
      );

      QUAN_CHECK (sizeof (m) == 2 * sizeof(double));
      QUAN_CHECK( (m.at<0,0>() == 1.234))
      QUAN_CHECK( (m.at<0,1>() == 5.678))

      auto constexpr m1 = quan::fun::transpose_matrix<decltype(m)>(m);

      QUAN_CHECK (sizeof (m1) == 2 * sizeof(double));
      QUAN_CHECK( (m1.at<0,0>() == 1.234))
      QUAN_CHECK( (m1.at<1,0>() == 5.678))

   }

}

void transpose_matrix_test()
{
   transpose_matrix_test1();
}