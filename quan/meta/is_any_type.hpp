#ifndef QUAN_META_IS_ANY_TYPE_HPP_INCLUDED
#define QUAN_META_IS_ANY_TYPE_HPP_INCLUDED

#include <quan/undefined.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/strip_cr.hpp>
#include <type_traits>

namespace quan{ namespace meta{

   template <typename T> 
   struct is_any_type : quan::meta::not_< 
      std::is_same<typename quan::meta::strip_cr<T>::type, quan::undefined>
   >{};

 }} // quan::meta

#endif // QUAN_META_IS_ANY_TYPE_HPP_INCLUDED
