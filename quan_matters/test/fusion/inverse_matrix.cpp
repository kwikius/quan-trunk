
#include <quan_matters/test/test.hpp>
#include <quan/fun/binary_matrix_ops.hpp>
#include <quan/out/length.hpp>
#include <quan/fusion/make_matrix.hpp>
#include <quan/fun/adjunct_view.hpp>
#include <quan/fun/inverse_view.hpp>
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
#include <typeinfo>

void fusion_inverse_matrix_test1()
{

   auto constexpr m = quan::fusion::make_matrix<4>
   (
       5.f, -2.f, 2.f, 7.f,
       1.f, 0.f, 0.f, 3.f,
       -3.f, 1.f, 5.f, 0.f,
       3.f, -1.f, -9.f, 4.f
   );

   typedef quan::meta::strip_cr<decltype(m)>::type m_type;

   QUAN_CHECK(quan::fun::is_fun_matrix<m_type>::value)
   auto const inv = quan::fun::inverse_view<m_type>{m};

  // std::cout << typeid(inv).name() <<'\n';
//
   typedef quan::meta::strip_cr<decltype(inv)>::type inv_type;
   
   QUAN_CHECK(quan::fun::is_fun_matrix<inv_type>::value)

   std::cout << inv.at<0,0>() << ", " << inv.at<0,1>() << ", " << inv.at<0,2>() << ", " << inv.at<0,3>() << '\n';
   std::cout << inv.at<1,0>() << ", " << inv.at<1,1>() << ", " << inv.at<1,2>() << ", " << inv.at<1,3>() << '\n';
   std::cout << inv.at<2,0>() << ", " << inv.at<2,1>() << ", " << inv.at<2,2>() << ", " << inv.at<2,3>() << '\n';
   std::cout << inv.at<3,0>() << ", " << inv.at<3,1>() << ", " << inv.at<3,2>() << ", " << inv.at<3,3>() << '\n';

}