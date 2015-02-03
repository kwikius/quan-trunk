#ifndef QUAN_META_OPERATOR_NAME_HPP_INCLUDED
#define QUAN_META_OPERATOR_NAME_HPP_INCLUDED
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

#include <quan/meta/binary_operator_extra_keys.hpp>

namespace quan{ namespace meta{

   template <typename Op>
   struct binary_operator_name;

   template<>
   struct binary_operator_name<plus>{
      const char* operator()()const{
         return "+";
      }
   };

   template<>
   struct binary_operator_name<minus>{
      const char* operator()()const{
         return "-";
      }
   };

   template<>
   struct binary_operator_name<times>{
      const char* operator()()const{
         return "*";
      }
   };
   
   template<>
   struct binary_operator_name<divides>{
      const char* operator()()const{
         return "/";
      }
   };

   template<>
   struct binary_operator_name<less>{
      const char* operator()()const{
         return "<";
      }
   };

   template<>
   struct binary_operator_name<less_equal>{
      const char* operator()()const{
         return "<=";
      }
   };

   template<>
   struct binary_operator_name<equal_to>{
      const char* operator()()const{
         return "==";
      }
   };

   template<>
   struct binary_operator_name<not_equal_to>{
      const char* operator()()const{
         return "!=";
      }
   };

   template<>
   struct binary_operator_name<greater_equal>{
      const char* operator()()const{
         return ">=";
      }
   };


   template<>
   struct binary_operator_name<greater>{
      const char* operator()()const{
         return ">";
      }
   };
   
}}//quan::meta

#endif
