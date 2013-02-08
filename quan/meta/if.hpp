#ifndef QUAN_META_IF_HPP_INCLUDED
#define QUAN_META_IF_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006


namespace quan{ namespace meta{
   
   template <bool B, typename T, typename F>
   struct if_c{
      typedef T type;
   };

   template <typename T,typename F>
   struct if_c<false,T,F> {
      typedef F type;
   };

   template<typename C, typename T, typename F>
   struct if_ : if_c<((C::value)!=0),T,F>{};
   
}}//quan::meta

#endif
