#ifndef QUAN_FUN_IS_FUN_SEQUENCE_HPP_INCLUDED
#define QUAN_FUN_IS_FUN_SEQUENCE_HPP_INCLUDED

#include <type_traits>
 #include <tuple>
/*
 to make a model of fun::Sequence

 // sequence requirements are
   num_elements and at?
 
*/
namespace quan{ namespace fun{

   template <typename T>
   struct is_fun_sequence_impl : std::false_type{};

   template <typename T>
   struct is_fun_sequence : is_fun_sequence_impl<
      typename std::remove_const<
         typename std::remove_reference<T>::type
      >::type
   >{};

   
   template<typename... Elements> 
   struct is_fun_sequence_impl<std::tuple<Elements...> > : std::true_type{};
}}//quan::fun

#endif
