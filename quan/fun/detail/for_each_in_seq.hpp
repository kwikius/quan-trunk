#ifndef QUANTA_DETAIL_FOR_EACH_IN_WRAPPER_N_HPP_INCLUDED
#define QUANTA_DETAIL_FOR_EACH_IN_WRAPPER_N_HPP_INCLUDED

#include <quan/fun/at_seq.hpp>
#include <quan/fun/at.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/access_modifiers.hpp>


namespace quan{ namespace fun {namespace detail{
   
// compile time loop unrolling impl
   template <int N>
   struct for_each_in_seq_n;

   template <>
   struct for_each_in_seq_n<0>{
      template <typename Sequence, typename F>
      void
      operator()(Sequence& a, F const & f)const
      {
         at_seq<0,Sequence,as_ref> at;
         f(at(a));
      }
      template <typename Sequence, typename F>
      void
      operator()(Sequence const& a, F const & f)const
      {
         at_seq<0,Sequence,as_const_ref> at;
         f(at(a));
      }
      typedef for_each_in_seq_n type;
   };

   template <int N>
   struct for_each_in_seq_n{
      template<typename Sequence, typename F>
      void
      operator()(Sequence& a, F const & f)const
      {
         static_assert( quan::fun::size_seq<Sequence>::value >= N ,"error" );
         for_each_in_seq_n<N-1> prev;
         prev(a,f);
         at_seq<N,Sequence,as_ref> at;
         f(at(a));
      }
      template <typename Sequence, typename F>
      void
      operator()(Sequence const & a, F const & f)const
      {
         static_assert( quan::fun::size_seq<Sequence>::value >= N ,"error" );
         for_each_in_seq_n<N-1> prev;
         prev(a,f);
         at_seq<N,Sequence,as_const_ref> at;
         f(at(a));
      }
      typedef for_each_in_seq_n type;
   };

}}}//quan::fun::detail


#endif
