#ifndef QUAN_FUSION_MAKE_MATRIX_HPP_INCLUDED
#define QUAN_FUSION_MAKE_MATRIX_HPP_INCLUDED

#include <quan/fun/matrix.hpp>
#include <quan/concepts/fusion/sequence.hpp>
#include <tuple>

namespace quan{ namespace fusion{

#if defined __cpp_concepts
   template <int R, int C, quan::fusion::Sequence Seq>
     requires quan::fusion::num_elements<Seq> == R * C
   inline constexpr 
   quan::fun::matrix<R,C,Seq>
   make_matrix( Seq && seq)
   {
      return quan::fun::matrix<R,C,Seq>(seq);
   }

   template<int R, int C, typename... Elements>
     requires sizeof ...(Elements) == R * C
   inline constexpr quan::fun::matrix<R,C,std::tuple<Elements...> >
   make_matrix(Elements&&... args)
   {
      return make_matrix<R,C>(std::forward_as_tuple(args...));
   }

#else
   template <int R, int C, typename Seq>
   inline constexpr 
   typename quan::where_<
      quan::meta::and_<
         quan::is_model_of<quan::fusion::Sequence_,Seq>
         ,quan::meta::bool_< ( quan::fusion::num_elements<Seq> == R * C ) >
      >,
      quan::fun::matrix<R,C,Seq>
   >::type
   make_matrix( Seq && seq)
   {
      return quan::fun::matrix<R,C,Seq>(seq);
   }

   template<int R, int C, typename... Elements>
   inline constexpr 
   typename quan::where_c<
      ( sizeof ...(Elements) == R * C)
     ,quan::fun::matrix<R,C,std::tuple<Elements...> >
   >::type
   make_matrix(Elements&&... args)
   {
      return make_matrix<R,C>(std::forward_as_tuple(args...));
   }

#endif

}} // quan::fusion


#endif // QUAN_FUSION_MAKE_MATRIX_HPP_INCLUDED
