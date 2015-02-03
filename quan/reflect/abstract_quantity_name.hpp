#ifndef QUAN_REFLECT_ABSTRACT_QUANTITY_NAME_HPP_INCLUDED
#define QUAN_REFLECT_ABSTRACT_QUANTITY_NAME_HPP_INCLUDED 
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
#include <quan/meta/eval_if.hpp>
#include <string>

namespace quan{namespace reflect{

   template <typename Quantity>
   std::string abstract_quantity_name(Quantity const & )
   {
      typedef typename Quantity::unit unit;

      typedef typename quan::meta::eval_if<
         quan::meta::is_named_quantity<Quantity>,
         quan::meta::get_named_quantity_traits<
            typename Quantity::unit
         >,
         meta::components::of_anonymous_quantity<Quantity>
      >::type result;
      
      return typename result::abstract_quantity_name();
   }
}}
#endif
