
#ifndef QUAN_FUN_STD_FOR_EACH_HPP_INCLUDED
#define QUAN_FUN_STD_FOR_EACH_HPP_INCLUDED

#include <quan/fun/is_fun_sequence.hpp>

namespace quan{namespace fun{

   template <typename C, typename F>
   inline
   typename quan::where_not
      is_fun_sequence<C>,
      void
   >::type
   for_each(C & c, F const & f)
   {
      for(auto elem : c,[]() {f(elem);} );
   }
   
  
}}//quan::fun

#endif
