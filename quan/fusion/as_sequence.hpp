#ifndef QUAN_FUSION_AS_SEQUENCE_HPP_INCLUDED
#define QUAN_FUSION_AS_SEQUENCE_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/is_model_of.hpp>

#include <quan/concepts/fusion/matrix.hpp>
#include <quan/fun/matrix_as_sequence.hpp>
#include <quan/concepts/fusion/sequence.hpp>

namespace quan{ namespace fusion{

#if defined __cpp_concepts

   template <fusion::Matrix M>
   inline constexpr
   auto as_sequence( M const & m)
   {
      return quan::fun::matrix_as_sequence<M>{m};
   }

#else

   template <typename M>
   inline constexpr
   typename quan::where_<
      quan::is_model_of<quan::fusion::Matrix_,M>
      ,quan::fun::matrix_as_sequence<M>
   >::type
   as_sequence( M const & m)
   {
      static_assert(quan::fun::is_fun_matrix<M>::value,"");
      return quan::fun::matrix_as_sequence<M>{m};
   }

#endif  
}}  // quan::fusion

#endif // QUAN_FUSION_AS_SEQUENCE_HPP_INCLUDED
