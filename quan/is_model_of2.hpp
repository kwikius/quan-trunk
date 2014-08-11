#ifndef QUAN_IS_MODEL_OF2_HPP_INCLUDED
#define QUAN_IS_MODEL_OF2_HPP_INCLUDED
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

#include <quan/config.hpp>
#include <quan/where_fwd.hpp>
#include <quan/meta/bool/false.hpp>
#include <quan/meta/strip_cr.hpp>

namespace quan{

   namespace impl{

      template < typename Concept,typename T1, typename T2,typename Where>
      struct is_model_of_impl2 : quan::meta::false_{};
   }

   template <typename Concept,typename T1,typename T2>
   struct is_model_of2 : quan::impl::is_model_of_impl2 <
      Concept,
      typename quan::meta::strip_cr<T1>::type,
      typename quan::meta::strip_cr<T2>::type
   >{};

}

#endif

