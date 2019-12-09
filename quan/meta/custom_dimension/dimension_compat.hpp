#ifndef QUAN_META_CUSTOM_DIMENSION_COMPAT_HPP_INCLUDED
#define QUAN_META_CUSTOM_DIMENSION_COMPAT_HPP_INCLUDED

/*
 Copyright (c) 2003-2019 Andy Little.

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

#include <quan/meta/custom_dimension/dimension.hpp>
#include <quan/meta/rational.hpp>

namespace quan{ namespace  meta{

   template <typename D>
   struct is_dimensionless<
      D, 
      typename quan::where_<quan::meta::is_dimension<D> >::type
   > : std::is_same<D, quan::meta::dimension<> >{};

   template <typename DL, typename DR>
   struct  dimensionally_equivalent<
      DL,DR,
      typename quan::where_<
         quan::meta::and_<
            quan::meta::is_dimension<DL>,
            quan::meta::is_dimension<DR>
         >
      >::type
    > : quan::meta::detail::are_equal_dimensions<DL,DR>{};

   template <typename D, typename Where>
   struct get_quantity_system;

   struct si_unit_system;

   template <typename ...D>
   struct get_quantity_system< dimension<D...>,void >{ typedef si_unit_system type;};

  namespace impl{

      template <typename DL, typename DR>
      struct binary_op_impl<
         DL,quan::meta::plus,DR,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::is_dimension<DL>,
               quan::meta::is_dimension<DR>,
               quan::meta::dimensionally_equivalent<DL,DR>
            >
         >::type
      > {
          typedef DL type;
      };

      template <typename DL, typename DR>
      struct binary_op_impl<
         DL,quan::meta::minus,DR,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::is_dimension<DL>,
               quan::meta::is_dimension<DR>,
               quan::meta::dimensionally_equivalent<DL,DR>
            >
         >::type
      > {
          typedef DL type;
      };

      template <typename DL, typename DR>
      struct binary_op_impl<
         DL,quan::meta::times,DR,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::is_dimension<DL>,
               quan::meta::is_dimension<DR>
            >
         >::type
      > : quan::meta::detail::add_dimensions< DL,DR>{};

      template <typename DL, typename DR>
      struct binary_op_impl<
         DL,quan::meta::divides,DR,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::is_dimension<DL>,
               quan::meta::is_dimension<DR>
            >
         >::type
      > : quan::meta::detail::subtract_dimensions< DL,DR>{};

      template <typename D,typename Exp>
      struct binary_op_impl<
         D,quan::meta::pow,Exp,
         typename quan::where_< quan::meta::is_dimension<D> >::type
      > : quan::meta::detail::multiply_dimension<
            D, std::ratio<Exp::numerator,Exp::denominator> 
      >{};
      
  } // impl

  template <typename D>
  struct unary_operation< 
      reciprocal, D, typename quan::where_< quan::meta::is_dimension<D> >::type
  > : quan::meta::detail::negate_dimension<D>{};

   #define QUAN_META_GET_DIMENSION(base_dim) template <typename D> \
   struct get_ ## base_dim ## _dimension< \
      D,typename quan::where_< quan::meta::is_dimension<D> >::type \
   >{ \
       typedef typename quan::meta::detail::get_base_dimension< \
            D,quan::meta::detail::base_dimension_id_t:: base_dim \
       >::type::ratio ratio_type; \
       typedef quan::meta::rational<ratio_type::num, ratio_type::den> type; \
   };

   QUAN_META_GET_DIMENSION(length)
   QUAN_META_GET_DIMENSION(time)
   QUAN_META_GET_DIMENSION(mass)
   QUAN_META_GET_DIMENSION(temperature)
   QUAN_META_GET_DIMENSION(current)
   QUAN_META_GET_DIMENSION(substance)
   QUAN_META_GET_DIMENSION(intensity)

   #undef QUAN_META_GET_DIMENSION

}} //quan::meta

#endif // QUAN_META_CUSTOM_DIMENSION_COMPAT_HPP_INCLUDED
