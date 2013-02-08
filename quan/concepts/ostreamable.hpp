#ifndef QUAN_CONCEPTS_OSTREAMABLE_HPP_INCLUDED
#define QUAN_CONCEPTS_OSTREAMABLE_HPP_INCLUDED

 /// Copyright Andrew Little 2007. All rights reserved

#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <type_traits>
#include <quan/meta/bool.hpp>
#include <string>

namespace quan{

   struct Ostreamable_;

   namespace impl{

      template <typename T>
      struct is_model_of_impl<
         quan::Ostreamable_, T,
         typename quan::where_<
            std::is_arithmetic<T> 
         >::type
      > : quan::meta::true_{};

   } 

   template<>
   struct is_model_of<quan::Ostreamable_,const char*> : quan::meta::true_{};

   template<int N>
   struct is_model_of<quan::Ostreamable_,char const[N]> : quan::meta::true_{};

   template<>
   struct is_model_of<quan::Ostreamable_,const wchar_t*> : quan::meta::true_{};

   template<int N>
   struct is_model_of<quan::Ostreamable_,wchar_t const[N]> : quan::meta::true_{};

   namespace impl{
      template <typename CharType>
      struct is_model_of_impl<quan::Ostreamable_, std::basic_string<CharType> > : quan::meta::true_{};
   }
   
//pointer

}//quan

#endif

