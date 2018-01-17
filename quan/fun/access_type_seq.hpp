#ifndef QUAN_FUN_ACCESS_TYPE_SEQ_HPP_INCLUDED
#define QUAN_FUN_ACCESS_TYPE_SEQ_HPP_INCLUDED
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

namespace quan{ namespace fun{

   template <typename Seq>
   struct access_type_seq_impl {
      typedef typename Seq::access_type type;
   };
   
   template <typename Seq>
   struct access_type_seq : access_type_seq_impl<
        typename quan::meta::strip_cr<Seq>::type::type
   >{};
}}
#endif
