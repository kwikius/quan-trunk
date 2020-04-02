#ifndef QUAN_ARCHETYPES_SCALAR_HPP_INCLUDED
#define QUAN_ARCHETYPES_SCALAR_HPP_INCLUDED
/*
 Copyright (c) 2003-2013 Andy Little 

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

#include <quan/config.hpp>
#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/is_scalar.hpp>

namespace quan{ 

   struct Scalar;

   namespace impl{

      template <typename T>
      struct is_model_of_impl<quan::Scalar,T> : quan::meta::is_scalar<T> {};

   }

}//quan


#endif // QUAN_CONCEPTS_ANGLE_HPP_INCLUDED
