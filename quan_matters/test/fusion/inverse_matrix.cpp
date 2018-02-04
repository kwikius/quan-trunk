
#include <quan_matters/test/test.hpp>
#include <quan/fun/binary_matrix_ops.hpp>
#include <quan/out/length.hpp>
#include <quan/fusion/make_matrix.hpp>
#include <quan/fun/adjunct_view.hpp>
#include <quan/fun/inverse_view.hpp>
#include <quan/fun/matrix_row.hpp>
#include <quan/fun/matrix_col.hpp>
#include <quan/fun/display_matrix.hpp>
#include <quan/fun/at.hpp>
#include <quan/fusion/static_value.hpp>

#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/area.hpp>
#include <quan/velocity.hpp>
#include <quan/reciprocal_length.hpp>

#include <quan/fixed_quantity/literal.hpp>

#include <typeinfo>

void fusion_inverse_matrix_test1()
{
   std::cout << "fusion_inverse_matrix_test1()\n";

   auto constexpr m = quan::fusion::make_matrix<4>
   (
       5.0, -2.0, 2.0, 7.0,
       1.0, 0.0, 0.0, 3.0,
       -3.0, 1.0, 5.0, 0.0,
       3.0, -1.0, -9.0, 4.0
   );

   typedef quan::meta::strip_cr<decltype(m)>::type m_type;

   QUAN_CHECK(quan::fun::is_fun_matrix<m_type>::value)

   display(m,"orig matrix m :");

   auto const inv = quan::fun::inverse_view<m_type>{m};

   typedef quan::meta::strip_cr<decltype(inv)>::type inv_type;
   
   QUAN_CHECK(quan::fun::is_fun_matrix<inv_type>::value)

   display(inv,"inverse inv :");

   auto const mux = m * inv;

   display(mux,"m * inv (should be identity) :");

}