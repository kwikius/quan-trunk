
#ifndef QUAN_META_ARE_FIXED_QUANTITIES_HPP_INCLUDED
#define QUAN_META_ARE_FIXED_QUANTITIES_HPP_INCLUDED

#include <quan/meta/is_fixed_quantity.hpp>
#include <quan/meta/and.hpp>


namespace quan{ namespace meta{

   template <typename Lhs, typename ...Args>
   struct are_fixed_quantities : quan::meta::and_<  
      is_fixed_quantity<Lhs>, 
      are_fixed_quantities<Args...>
   >{};

   template <typename Lhs, typename Rhs>
   struct are_fixed_quantities<Lhs,Rhs>
   : quan::meta::and_<
       is_fixed_quantity<Lhs>,
       is_fixed_quantity<Rhs> 
   >{};

}} // quan::meta

#endif // QUAN_META_ARE_FIXED_QUANTITIES_HPP_INCLUDED
