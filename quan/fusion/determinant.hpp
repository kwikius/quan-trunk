#ifndef QUAN_FUSION_DETERMINANT_HPP_INCLUDED
#define QUAN_FUSION_DETERMINANT_HPP_INCLUDED

#include <quan/concepts/fusion/matrix.hpp>
#include <quan/fun/matrix_determinant.hpp>

namespace quan{ namespace fusion{

#if defined __cpp_concepts

   template <Matrix M>
      requires is_square_matrix<M>
   inline constexpr
   auto determinant ( M const & m)
   {
      return quan::fun::make_determinant<M>{}(m);
   }

#else

   template <typename M>
   inline constexpr 
   typename quan::where_<
      quan::meta::and_<
         quan::is_model_of<quan::fusion::Matrix_,M>
         ,quan::meta::bool_<(is_square_matrix<M>)>
      >
      ,typename quan::fun::make_determinant<M>::type
   >::type
   determinant ( M const & m)
   {
      return quan::fun::make_determinant<M>{}(m);
   }

#endif
 
}} // quan::fusion

#endif // QUAN_FUDION_MATRIX_DETERMINANT_HPP_INCLUDED
