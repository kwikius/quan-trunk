

#include <quan/fun/add_subtract_ops.hpp>
#include <quan_matters/test/test.hpp>

#include <quan/fusion/matrix.hpp>

void matrix_add_test1()
{
#if defined __MBED__
   auto const m1 = quan::fusion::make_matrix<4>
#else
    auto constexpr m1 = quan::fusion::make_matrix<4>
#endif
      (
         1.0 ,2.0 ,3.0 ,4.0 ,
         1.0 ,2.0 ,3.0 ,4.0 ,
         1.0 ,2.0 ,3.0 ,4.0 ,
         1.0 ,2.0 ,3.0 ,4.0
      );

}