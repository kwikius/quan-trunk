#ifndef QUAN_FUSION_INNER_PRODUCT_HPP_INCLUDED
#define QUAN_FUSION_INNER_PRODUCT_HPP_INCLUDED

#include <quan/fun/inner_product_seq.hpp>
#include <quan/concepts/fusion/sequence.hpp>

namespace quan{ namespace fusion {
   
 #if defined ( __cpp_concepts )
   template <quan::fusion::Sequence SeqL, quan::fusion::Sequence SeqR, typename FF , typename F>
#else
   template <typename SeqL, typename SeqR, typename FF , typename F>
#endif
   inline constexpr
   typename quan::fun::inner_product_seq::result<SeqL,SeqR,FF,F>::type
   inner_product(SeqL && seql, SeqR && seqr, FF && ff, F && f)
   {
       static_assert( std::is_reference<
         typename quan::fun::inner_product_seq::result<SeqL,SeqR,FF,F>::type
       >::value == false,
       "no ref return");

       return quan::fun::inner_product_seq{}(
         std::forward<SeqL>(seql),
            std::forward<SeqR>(seqr),
               std::forward<FF>(ff),
                  std::forward<F>(f)
       );
   }

} } // quan::fusion

#endif // QUAN_FUSION_INNER_PRODUCT_HPP_INCLUDED
