#ifndef QUAN_CONCEPTS_FUSION_SEQUENCE_HPP_INCLUDED1
#define QUAN_CONCEPTS_FUSION_SEQUENCE_HPP_INCLUDED1

#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/is_model_of.hpp>

namespace quan { namespace fusion{

#if defined __cpp_concepts

   template <typename S>
   concept bool Sequence = quan::fun::is_fun_sequence<S>::value;

#endif

   struct Sequence_;

}} // quan::fusion

// do the old pre concepts version always
namespace quan{ namespace impl{

   template <typename S> 
   struct is_model_of_impl<
      quan::fusion::Sequence_,S, 
      typename quan::where_<quan::fun::is_fun_sequence<S> >::type 
   > : quan::meta::true_{};

}} // quan::impl

namespace quan { namespace fusion{

#if defined __cpp_concepts
   template <int N , Sequence S>
   using sequence_at_t = typename quan::fun::at_seq<N,S,quan::fun::as_value>::type;

   template <Sequence S>
   constexpr std::size_t num_elements = quan::fun::size_seq<S>::value;
#else
   template <int N , typename S>
   using sequence_at_t = typename quan::fun::at_seq<N,S,quan::fun::as_value>::type;

   template <typename S>
   constexpr std::size_t num_elements = quan::fun::size_seq<S>::value;

#endif

}} // quan::fusion

#endif // QUAN_CONCEPTS_FUSION_SEQUENCE_HPP_INCLUDED
