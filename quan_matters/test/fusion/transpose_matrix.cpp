

#include <quan_matters/test/test.hpp>


#include <quan/fusion/matrix.hpp>


namespace {

   void transpose_matrix_test1()
   {
      
#if defined __MBED__
      auto const m = quan::fusion::make_matrix<1>
#else
      auto constexpr m = quan::fusion::make_matrix<1>
#endif
      (
         1.234, 5.678
      );

      QUAN_CHECK (sizeof (m) == 2 * sizeof(double));
      QUAN_CHECK( (m.at<0,0>() == 1.234))
      QUAN_CHECK( (m.at<0,1>() == 5.678))

#if defined __MBED__
      auto const m1 = quan::fun::transpose_matrix<decltype(m)>(m);
#else
      auto constexpr m1 = quan::fun::transpose_matrix<decltype(m)>(m);
#endif

      QUAN_CHECK (sizeof (m1) == 2 * sizeof(double));
      QUAN_CHECK( (m1.at<0,0>() == 1.234))
      QUAN_CHECK( (m1.at<1,0>() == 5.678))

   }

}

void transpose_matrix_test()
{
   transpose_matrix_test1();
}