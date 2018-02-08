#ifndef QUAN_FUSION_FOLD_HPP_INCLUDED
#define QUAN_FUSION_FOLD_HPP_INCLUDED

#include <quan/fun/fold_seq.hpp>
#include <utility>

namespace quan{ namespace fusion {

   /*
      Seq is a model of quan::fusion Sequence
      init is the initial value of the fold
      F is a struct with  has a binary operator() which takes 2 arguments by value or const ref
      F has a member struct result with a member type which is the type of the result of F's operator ()
   */
   
   template <typename Seq, typename T , typename F>
   inline constexpr
   typename quan::fun::fold_seq:: template result<Seq,T,F>::type
   fold(Seq && seq, T && init, F&& f)
   {
      // For simplicity fold cannot mutate its sequence or its init
      static_assert( std::is_reference<typename quan::fun::fold_seq::result<Seq,T,F>::type>::value == false,"no ref return");
      return quan::fun::fold_seq{}(std::forward<Seq>(seq),std::forward<T>(init),std::forward<F>(f));
   }

}} // quan::fusion


#endif // QUAN_FUSION_FOLD_HPP_INCLUDED
