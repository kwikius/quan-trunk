
#include <quan_matters/test/test.hpp>

#include <quan/fusion/matrix.hpp>

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