#ifndef QUAN_META_IS_ELEMENT_OF_HPP_INCLUDED
#define QUAN_META_IS_ELEMENT_OF_HPP_INCLUDED

#if defined __cpp_lib_variant
#include <variant>
#endif

namespace quan{ namespace meta{

   template <typename ...Args>
   constexpr inline bool is_element_of;

   template <typename V, typename First>
   constexpr inline bool is_element_of<V,First> = std::is_same_v<V,First> ;

   template <typename V, typename First, typename ...Args>
   constexpr inline bool is_element_of<V,First,Args...> = is_element_of<V,First> || is_element_of<V,Args...> ;

   #if defined __cpp_lib_variant
   template <typename V, typename ...Args>
   constexpr bool is_element_of<V,std::variant<Args...> > = is_element_of<V, Args...>;
   #endif

}} //quan::meta

#endif // QUAN_META_IS_ELEMENT_OF_HPP_INCLUDED
