#ifndef QUAN_META_FOLD_HPP_INCLUDED
#define QUAN_META_FOLD_HPP_INCLUDED
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

#include <quan/meta/detail/fold_i.hpp>

namespace quan{ namespace meta{

#if defined __cpp_concepts 
  template <quan::meta::TypeSequence Seq, typename Init, typename F>
#else
   template < typename Seq, typename Init, typename F>
#endif
   struct fold{
      typedef typename quan::meta::eval_if_c<
         (quan::meta::get_num_elements<Seq>::value > 0),
         quan::meta::detail::fold_i<Seq,Init,F>,
         identity<Init>
      > ::type type;
   };


}}// quan::meta

#endif // QUAN_META_FOLD_HPP_INCLUDED
