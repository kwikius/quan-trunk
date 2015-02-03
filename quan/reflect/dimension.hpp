#ifndef QUAN_REFLECT_DIMENSION_HPP_INCLUDED
#define QUAN_REFLECT_DIMENSION_HPP_INCLUDED
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

#include <quan/components/of_anonymous_quantity.hpp>
#include <quan/meta/static_unit_concept.hpp>
#include <type_traits>
#include <quan/out/length.hpp>
#include <quan/out/time.hpp>
#include <quan/out/mass.hpp>
#include <quan/out/temperature.hpp>
#include <quan/out/current.hpp>
#include <quan/out/substance.hpp>
#include <quan/out/intensity.hpp>
#include <quan/out/area.hpp>
#include <quan/meta/out/rational.hpp>

namespace quan{namespace reflect{
   namespace detail{
   
      template < typename FixedQuantity, typename Traits>
      struct get_dimension_result_impl;
   
      template <typename FixedQuantity>
      struct get_dimension_result_impl<FixedQuantity,quan::length>{
         typedef typename quan::meta::get_length_dimension<
            typename FixedQuantity::unit
         >::type type;
      };

      template <typename FixedQuantity>
      struct get_dimension_result_impl<FixedQuantity,quan::mass>{
         typedef typename quan::meta::get_mass_dimension<
            typename FixedQuantity::unit
         >::type type;
      };

      template <typename FixedQuantity>
      struct get_dimension_result_impl<FixedQuantity,quan::time>{
         typedef typename quan::meta::get_time_dimension<
            typename FixedQuantity::unit
         >::type type;
      };

      template <typename FixedQuantity>
      struct get_dimension_result_impl<FixedQuantity,quan::current>{
         typedef typename quan::meta::get_current_dimension<
            typename FixedQuantity::unit
         >::type type;
      };

      template <typename FixedQuantity>
      struct get_dimension_result_impl<FixedQuantity,quan::temperature>{
         typedef typename quan::meta::get_temperature_dimension<
            typename FixedQuantity::unit
         >::type type;
      };
   
      template <typename FixedQuantity>
      struct get_dimension_result_impl<FixedQuantity,quan::substance>{
         typedef typename quan::meta::get_substance_dimension<
            typename FixedQuantity::unit
         >::type type;
      };

      template <typename FixedQuantity>
      struct get_dimension_result_impl<FixedQuantity,quan::intensity>{
         typedef typename quan::meta::get_intensity_dimension<
            typename FixedQuantity::unit
         >::type type;
      };

   }//detail
   
   template<typename FixedQuantity>
   struct dimension{
      
      template <typename Traits>
      struct result{
         typedef typename detail::get_dimension_result_impl<FixedQuantity,
            typename std::remove_const<
               typename std::remove_reference<Traits>::type
            >::type
         >::type type;
      };
      template <typename Traits>
      typename result<Traits>::type
      operator()(Traits const & t) const
      {
         typedef typename result<Traits>::type res;
         return res();
      }
   };

}}//quan::reflect

#endif
