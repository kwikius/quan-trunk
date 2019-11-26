
#include <quan_matters/test/test.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fusion/matrix.hpp>
#include <quan/fun/inner_product_seq.hpp>

#include <quan/fusion/inner_product.hpp>

namespace  {
   
   // used for compare
   struct ll_compare{

      ll_compare(double eps = 1.e-6):m_eps{eps}{}

      template< typename L, typename R>
      struct result
      { 
         typedef bool type;
      };

      template< typename L, typename R>
      struct  apply {
         typedef bool type;
      };

      template< typename L, typename R>
      bool operator()(L const &  lhs, R const & rhs) const
      {
         typedef decltype(lhs - rhs) eps_type;
         eps_type const eps{m_eps};

         bool res = abs(lhs-rhs) <= abs(eps);
        // std::cout << " lhs = " << lhs << " , rhs = " << rhs << ", eps = " << eps << ", res = " << res <<'\n';
         return res;
      }

      double const m_eps;
   };

}

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

   auto const m_inverse = quan::fun::inverse_view<m_type>{m};

   typedef quan::meta::strip_cr<decltype(m_inverse)>::type inv_type;
   
   QUAN_CHECK(quan::fun::is_fun_matrix<inv_type>::value)

   display(m_inverse,"inverse m_inverse :");

   auto const identity_synth = m * m_inverse;

   display(identity_synth,"m * m_inverse (should be identity) :");

   auto constexpr identity = quan::fusion::make_matrix<4>
   (
       1, 0, 0, 0,
       0, 1, 0, 0,
       0, 0, 1, 0,
       0, 0, 0, 1
   );

   auto seq1 = quan::fusion::as_sequence(identity_synth);
   auto seq2 = quan::fusion::as_sequence(identity);

   bool res = quan::fusion::inner_product(
      seq1,seq2,quan::operator_logical_and(), ll_compare{}
   );
   QUAN_CHECK(res )

   auto mm = m* identity_synth;

   auto seq3 = quan::fusion::as_sequence(m);
   auto seq4 = quan::fusion::as_sequence(mm);

   bool res1 = quan::fusion::inner_product(
      seq3,seq4,quan::operator_logical_and(), ll_compare{}
   );
   QUAN_CHECK(res1 )

   display (mm, "m * synthetic identity (should be same as m)");
   
}