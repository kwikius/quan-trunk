#ifndef QUAN_FUSION_AS_SEQUENCE_HPP_INCLUDED
#define QUAN_FUSION_AS_SEQUENCE_HPP_INCLUDED

#include <quan/fun/matrix_as_vector.hpp>
#include <quan/concepts/fusion/matrix.hpp>
#include <quan/concepts/fusion/sequence.hpp>

namespace quan{ namespace fusion{

   template <typename M>
   inline constexpr
   typename quan::where_<
      quan::is_model_of<quan::fusion::Matrix_,M>
      ,quan::fun::matrix_as_sequence<M>
   >::type
   as_sequence( M const & m)
   {
      return quan::fun::matrix_as_sequence<M>{m};
   }
   

}}  // quan::fusion

#endif // QUAN_FUSION_AS_SEQUENCE_HPP_INCLUDED