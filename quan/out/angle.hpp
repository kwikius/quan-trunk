
#ifndef QUAN_ANGLE_OUT_ANGLE_HPP_INCLUDED
#define QUAN_ANGLE_OUT_ANGLE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
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


#include <quan/angle/out/mathematic_angle.hpp>
#include <quan/angle/out/fraction_of_revolution.hpp>
#include <quan/angle.hpp>

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <quan/is_model_of.hpp>
#include <quan/concepts/ostreamable.hpp>

namespace quan{ namespace impl{

   template < 
      typename T
   >
   struct is_model_of_impl<
      quan::Ostreamable_
      ,T
      ,typename quan::where_<quan::meta::is_angle<T> >::type
   > : quan::meta::true_{};
}} 
#endif

#endif
