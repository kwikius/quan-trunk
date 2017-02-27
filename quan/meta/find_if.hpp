#ifndef QUAN_META_FIND_IF_HPP_INCLUDED
#define QUAN_META_FIND_IF_HPP_INCLUDED
/*
 Copyright (c) 2012-2017 Andy Little 

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

#include <quan/meta/type_sequence.hpp>
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace meta{

    namespace detail{

       template <typename SrcList, typename Pred> struct find_if_i {
          typedef typename quan::meta::front<SrcList>::type src_element;
          typedef typename quan::meta::pop_front<SrcList>::type list_in_next;
          typedef typename quan::meta::eval_if<
               typename Pred::template apply<src_element>,
               std::true_type,
               quan::meta::eval_if_c<
                  (quan::meta::get_num_elements<list_in_next>::value > 0)
                  ,find_if_i<list_in_next,Pred>
                  ,std::false_type
               >
           >::type type;
       };
    }

    template <typename SrcList, typename F> 
    struct find_if{
        typedef typename quan::meta::eval_if_c<
            (quan::meta::get_num_elements<SrcList>::value  == 0),
            std::false_type,
            quan::meta::detail::find_if_i<SrcList,F>
         >::type type;

         static constexpr bool value = type::value;
    };

}}// quan::meta

#endif // QUAN_META_FIND_IF_HPP_INCLUDED
