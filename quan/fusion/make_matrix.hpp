#ifndef QUAN_FUSION_MAKE_MATRIX_HPP_INCLUDED
#define QUAN_FUSION_MAKE_MATRIX_HPP_INCLUDED

#include <quan/fun/matrix.hpp>
#include <quan/fusion/make_vector.hpp>
#include <quan/concepts/fusion/sequence.hpp>
#include <quan/fun/vector.hpp>

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
   inline constexpr quan::fun::matrix<R,C,quan::fun::vector<typename quan::meta::strip_cr<Elements>::type...> >
   make_matrix(Elements&&... args)
   {
      return make_matrix<R,C>(quan::fusion::make_vector(args...));
   }

   template<int R, typename... Elements>
      requires sizeof...(Elements) % R  == 0
   inline constexpr 
   quan::fun::matrix<R,sizeof...(Elements) / R,quan::fun::vector<typename quan::meta::strip_cr<Elements>::type...> >
   make_matrix(Elements&&... args)
   {
      return make_matrix<R,sizeof...(Elements) / R>(quan::fusion::make_vector(args...));
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
     ,quan::fun::matrix<R,C,quan::fun::vector<typename quan::meta::strip_cr<Elements>::type...> >
   >::type
   make_matrix(Elements&&... args)
   {
      return make_matrix<R,C>(quan::fusion::make_vector(args...));
   }

   template<int R, typename... Elements>
   inline constexpr 
     typename quan::where_c<
         (((sizeof...(Elements)) % R ) == 0)
         ,quan::fun::matrix<R,sizeof...(Elements) / R,quan::fun::vector<typename quan::meta::strip_cr<Elements>::type...> >
     >::type
   make_matrix(Elements&&... args)
   {
      return make_matrix<R,sizeof...(Elements) / R>(quan::fusion::make_vector(args...));
   }

#endif

}} // quan::fusion


#endif // QUAN_FUSION_MAKE_MATRIX_HPP_INCLUDED
