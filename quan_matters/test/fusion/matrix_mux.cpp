

#include <quan_matters/test/test.hpp>

#include <quan/fun/vector3.hpp>
#include <quan/fun/vector9.hpp>
#include <quan/fun/binary_matrix_ops.hpp>
#include <quan/fusion/make_matrix.hpp>


void matrix_mux_result_test()
{
    auto m1 = quan::fusion::make_matrix<3,3>(
        1.0, 0.0 , 0.0
       ,0.0, 1.0 , 0.0
       ,0.0, 0.0 , 1.0
    );

    auto m2 = quan::fusion::make_matrix<3,3>(
        2.0, 0.0 , 0.0
       ,0.0, 2.0 , 0.0
       ,0.0, 0.0 , 2.0
    );

   // typedef quan::fun::make_matrix_mux_result<decltype(m1),decltype(m2)>::type result_type;

    auto result = m1 * m2;

    QUAN_CHECK( (result.at<0,0>() == 2.0))
    QUAN_CHECK( (result.at<0,1>() == 0.0))
    QUAN_CHECK( (result.at<0,2>() == 0.0))

    QUAN_CHECK( (result.at<1,0>() == 0.0))
    QUAN_CHECK( (result.at<1,1>() == 2.0))
    QUAN_CHECK( (result.at<1,2>() == 0.0))

    QUAN_CHECK( (result.at<2,0>() == 0.0))
    QUAN_CHECK( (result.at<2,1>() == 0.0))
    QUAN_CHECK( (result.at<2,2>() == 2.0))
}