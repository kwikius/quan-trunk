
#ifndef QUAN_META_ASM_ABS_HPP_INCLUDED
#define QUAN_META_ASM_ABS_HPP_INCLUDED

// Copyright Andrew Little 2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <type_traits>
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace meta{namespace asm_{

   namespace impl{

      template <typename T, T v>
      struct signed_abs_impl{
         static const T value = (v >=0) ? v : -v;
         typedef signed_abs_impl type;
      };
      template <typename T, T v>
      struct unsigned_abs_impl{
         static const T value = v;
         typedef unsigned_abs_impl type;
      };
      
   }

   template <typename T, T v>
   struct abs{
      typedef typename quan::meta::eval_if<
         std::is_signed<T>,
         impl::signed_abs_impl<T,v>,
         impl::unsigned_abs_impl<T,v>
      >::type type;
      static const T value = type::value;
   };

}}}//quan::meta::asm_

#endif

