#ifndef QUAN_SEQ_CONS_CONS_DEF_HPP_INCLUDED
#define QUAN_SEQ_CONS_CONS_DEF_HPP_INCLUDED
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

#include <quan/is_model_of.hpp>
#include <quan/tuple/at.hpp>
#include <quan/tuple/num_elements.hpp>
#include <quan/concepts/meta/type_sequence.hpp>
#include <quan/meta/detail/type_sequence_at.hpp>
#include <quan/concepts/meta/type_sequence.hpp>

namespace quan{namespace cons{

   struct nil{
      typedef nil type;
   };

   template <typename T, typename Front = nil>
   struct list;
}}

namespace quan{ namespace tuple{ namespace impl{

    template <int N,typename T, typename Front,typename Access>
    struct at_impl<N,quan::cons::list<T,Front>,Access> 
      : quan::meta::detail::type_sequence_at<N,quan::cons::list<T,Front>,Access>{};

   template <typename T, typename Front>
   struct num_elements_impl<quan::cons::list<T,Front> > : quan::cons::list<T,Front>::length{};

}}}//quan::tuple::impl

namespace quan{ namespace impl{

   template <typename T, typename Front>
   struct is_model_of_impl<
      quan::meta::TypeSequence_,
      quan::cons::list<T,Front>
   > : quan::meta::true_{};
}}


#endif
