#ifndef QUAN_FUSION_FOLD_HPP_INCLUDED
#define QUAN_FUSION_FOLD_HPP_INCLUDED

#include <quan/fun/fold_seq.hpp>
#include <utility>

namespace quan{ namespace fusion {
   
   template <typename Seq, typename T , typename F>
   inline constexpr
   typename quan::fun::fold_seq::result<Seq,T,F>::type
   fold(Seq && seq, T && init, F&& f)
   {
      return quan::fun::fold_seq{}(std::forward<Seq>(seq),std::forward<T>(init),std::forward<F>(f));
   }

}} // quan::fusion


#endif // QUAN_FUSION_FOLD_HPP_INCLUDED
