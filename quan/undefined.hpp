#ifndef QUAN_UNDEFINED_HPP_INCLUDED
#define QUAN_UNDEFINED_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2007. All rights reserved.

#include <quan/meta/bool/false.hpp>
#include <quan/meta/bool/true.hpp>

namespace quan{ 

   struct undefined{
     
      typedef undefined type;
      private:
         undefined(undefined const &) = delete;
         undefined& operator= (undefined const &) = delete;
         undefined() = delete;
         
   };
 
   namespace impl{
      template <typename T,typename Where = void >
      struct is_any_type_impl : quan::meta::true_{};

      template <>
      struct is_any_type_impl<quan::undefined> 
      : quan::meta::false_{};
   }

}

#endif

