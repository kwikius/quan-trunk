#ifndef QUAN_CONCEPTS_OSTREAMABLE_HPP_INCLUDED
#define QUAN_CONCEPTS_OSTREAMABLE_HPP_INCLUDED

/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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

