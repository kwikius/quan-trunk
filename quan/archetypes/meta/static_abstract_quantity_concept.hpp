#ifndef QUAN_META_STATIC_ABSTRACT_QUANTITY_CONCEPT_HPP_INCLUDED
#define QUAN_META_STATIC_ABSTRACT_QUANTITY_CONCEPT_HPP_INCLUDED

/*
 Copyright (c) 2005-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/
/*
    associated metafunctions for the StaticAbstractQuantity Concept.
    These are required to be specialised per model.
*/

#include <quan/config.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_arithmetic.hpp>
#endif
#include <quan/meta/anonymous_quantity_traits.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/bool/false.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/where.hpp>
#include <quan/undefined.hpp>

namespace quan { namespace meta{

    template <
       typename Lhs,
       typename Rhs,
       typename Enable = void
    > struct dimensionally_equivalent : quan::meta::false_{};


    template <
      typename Q, 
      typename Where = void
    >
    struct is_dimensionless : quan::meta::false_{};

    template <typename Q>
    struct is_dimensionless<
      Q,
      typename quan::where_<std::is_arithmetic<Q> >::type
    > : quan::meta::true_{};

    template <
        typename Quantity_L,
        typename Quantity_R,
        typename Where = void
    > 
    struct is_same_quantity : quan::meta::false_{};

    template <typename Quantity, typename Where = void>
    struct is_named_quantity : quan::meta::false_{};

    template <typename Quantity, typename Where = void>
    struct make_anonymous : quan::undefined{};

    template <typename Quantity, typename Where = void>
    struct get_named_quantity_traits : quan::undefined{};

    template <typename Quantity, typename Where = void>
    struct get_length_dimension  : quan::undefined{};;
    
    template <typename Quantity, typename Where = void>
    struct get_time_dimension  : quan::undefined{};;
    
    template <typename Quantity, typename Where = void>
    struct get_mass_dimension  : quan::undefined{};;

    template <typename Quantity, typename Where = void>
    struct get_temperature_dimension  : quan::undefined{};;

    template <typename Quantity, typename Where = void>
    struct get_current_dimension  : quan::undefined{};;

    template <typename Quantity, typename Where = void>
    struct get_substance_dimension  : quan::undefined{};;

    template <typename Quantity, typename Where = void>
    struct get_intensity_dimension  : quan::undefined{};;

    template <typename Quantity, typename Where = void>
    struct name_anonymous_abstract_quantity ;
    

} }//quan::meta

#endif

