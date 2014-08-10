#ifndef QUAN_META_OPERATOR_NAME_HPP_INCLUDED
#define QUAN_META_OPERATOR_NAME_HPP_INCLUDED

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
