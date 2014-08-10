#ifndef QUAN_META_UNDEFINED_OPERATION_HPP_INCLUDED
#define QUAN_META_UNDEFINED_OPERATION_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2007. All rights reserved.

#include <quan/meta/bool/false.hpp>

namespace quan{ namespace meta{

   struct quan::undefined{
     
      typedef quan::undefined type;
    //  protected:
        // template<typename T,typename T1> friend class any_type;
         quan::undefined(quan::undefined const &);
         quan::undefined& operator= (quan::undefined const &);
         quan::undefined();
         
   };

   namespace impl{
      template <typename T,typename Where >
      struct is_any_type_impl;

      template <>
      struct is_any_type_impl<quan::undefined,void> 
      : quan::meta::false_{};
   }

}}

#endif

