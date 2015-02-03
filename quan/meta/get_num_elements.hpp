#ifndef QUAN_META_GET_NUM_ELEMENTS_HPP_INCLUDED
#define QUAN_META_GET_NUM_ELEMENTS_HPP_INCLUDED
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

#include <quan/meta/strip_cr.hpp>
#include <quan/archetypes/scalar.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/int32.hpp>

namespace quan{ namespace meta{

    namespace impl{

       template <typename T, typename Where = void>
       struct get_num_elements_impl {};
        
       template <
         typename T
       >
       struct get_num_elements_impl<T, 
         typename quan::where_<
            quan::is_model_of<quan::Scalar,T>
         >::type
       > : quan::meta::int32<1>{};
       
    }

    template <typename T> struct get_num_elements : 
    quan::meta::impl::get_num_elements_impl<typename strip_cr<T>::type>{};

}}


#endif // QUAN_META_GET_NUM_ELEMENTS_HPP_INCLUDED
