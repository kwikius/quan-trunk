
#ifndef QUAN_FUN_RANGE_HPP_INCLUDED
#define QUAN_FUN_RANGE_HPP_INCLUDED

#include <quan/fun/range_seq.hpp>
namespace quan{ namespace fun{

   template <int First, int Last, typename Seq>
   inline
   range_seq<Seq,First,Last>
   range(Seq & seq)
   {
      return range_seq<Seq,First,Last>(seq);
   }
   
   template <int First, int Last,typename Seq>
   inline
   range_seq<const Seq,First,Last>
   range(Seq const & seq)
   {
      return range_seq<const Seq,First,Last>(seq);
   }
}}
#endif
