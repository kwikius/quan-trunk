#ifndef QUAN_FUN_DETAIL_ARGTYPE_HPP_INCLUDED
#define QUAN_FUN_DETAIL_ARGTYPE_HPP_INCLUDED

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
            typename std::add_reference<
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
