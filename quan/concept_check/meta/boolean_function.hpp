#ifndef QUAN_CONCEPT_CHECK_META_BOOLEAN_FUNCTION_HPP_INCLUDED
#define QUAN_CONCEPT_CHECK_META_BOOLEAN_FUNCTION_HPP_INCLUDED
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


// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <quan/concept_check/meta/boolean_constant.hpp>

namespace quan{ namespace concept_check{namespace meta{

   // assert that T is a metafunction
   template <typename T>
   inline
   void boolean_function()
   {
      quan::concept_check::meta::function<T>();
      quan::concept_check::meta::boolean_constant<typename T::type>();
   }

   template <typename T>
   inline
   void true_function()
   {
      quan::concept_check::meta::boolean_function<T>();
      quan::concept_check::meta::true_constant<typename T::type>();
   }

   template <typename T>
   inline
   void false_function()
   {
      quan::concept_check::meta::boolean_function<T>();
      quan::concept_check::meta::false_constant<typename T::type>();
   }

}}}//quan::concept_check::meta


#endif
 
