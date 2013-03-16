#ifndef QUAN_META_COUNT_IF_HPP_INCLUDED
#define QUAN_META_COUNT_IF_HPP_INCLUDED
/*
 Copyright (c) 2012-2013 Andy Little 

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

       template <typename SrcList, typename Count, typename Pred> struct count_if_i {
        
          typedef typename quan::meta::front<SrcList>::type src_element;

          typedef typename quan::meta::eval_if<
               typename Pred::template apply<src_element>,
               std::integral_constant<uint32_t, (Count::value + 1)>,
               Count
           >::type new_count;

          typedef typename quan::meta::pop_front<SrcList>::type list_in_next;

          typedef typename quan::meta::eval_if_c<
            (quan::meta::get_num_elements<list_in_next>::value > 0),
            quan::meta::detail::count_if_i<list_in_next,new_count,Pred>,
            new_count
          >::type type; 
       };
    }

    template <typename SrcList, typename F> 
    struct count_if{
        typedef typename quan::meta::eval_if_c<
            (quan::meta::get_num_elements<SrcList>::value  == 0),
            std::integral_constant<uint32_t, 0>,
            quan::meta::detail::count_if_i<SrcList,std::integral_constant<uint32_t,0>,F>
         >::type type;

         static const uint32_t value = type::value;
    };

}}// quan::meta

#endif // QUAN_META_COUNT_IF_HPP_INCLUDED
