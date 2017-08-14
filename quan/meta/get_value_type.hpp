#ifndef QUAN_META_GET_VALUETYPE_HPP_INCLUDED
#define QUAN_META_GET_VALUETYPE_HPP_INCLUDED

namespace quan{ namespace meta{

   template <typename T>
   struct get_value_type{
      typedef typename T::value_type type;
   };

   template <typename T,unsigned int N>
   struct get_value_type<T[N]>{
      typedef T type;
   };
}}

#endif //QUAN_META_GET_VALUETYPE_HPP_INCLUDED