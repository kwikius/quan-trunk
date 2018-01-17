#ifndef QUAN_FUN_DETAIL_ARGTYPE_HPP_INCLUDED
#define QUAN_FUN_DETAIL_ARGTYPE_HPP_INCLUDED
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

#include <quan/meta/not.hpp>
#include <quan/meta/if.hpp>
#include <type_traits>

#include <quan/fun/access_modifiers.hpp>

namespace quan{namespace fun{namespace detail{

    template <typename T>
    struct arg_type{
        typedef typename quan::meta::if_<
            quan::meta::and_<
                std::is_reference<T>,
                quan::meta::not_<
                    std::is_const<T>
                >
            >,
            T,
            typename std::add_lvalue_reference<
                typename std::add_const<
                    T
                >::type
            >::type
        >::type type;
    };

    template <typename Seq>
    struct seq_compatible_ref{
        typedef typename quan::meta::if_<
            std::is_const<Seq>,
            quan::fun::as_const_ref,
            quan::fun::as_ref
        >::type type;
    };

}}}//quan::fun::detail

#endif
