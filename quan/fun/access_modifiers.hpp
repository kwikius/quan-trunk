#ifndef QUAN_FUN_ACCESS_MODIFIERS_HPP_INCLUDED
#define QUAN_FUN_ACCESS_MODIFIERS_HPP_INCLUDED

 // Copyright (c) 2005-2006 Andrew Little.  ALL RIGHTS RESERVED.
 // No part of this document may be reproduced or transmitted 
 // in any form or by any means without the written permission 
 // of the author.

#include <type_traits>

namespace quan{namespace fun{

    struct as_value{

        template <typename T>
        struct result{
            typedef typename std::remove_const< 
                typename std::remove_reference<T>::type
            >::type type;
        };

        template <typename T>
        typename result<T>::type
        operator()(T in)const
        {
            return in;
        }
        typedef as_value type;
    };

     struct as_const_value{
        template <typename T>
        struct result{
            typedef typename std::add_const<T>::type type;
        };

        template <typename T>
        typename result<T>::type
        operator()(T const in)const
        {
            return in;
        }
        typedef as_const_value type;
    };

    struct as_const_ref{
        template <typename T>
        struct result{
            typedef typename std::add_lvalue_reference<
               typename std::add_const<T>::type
            >::type type;
        };

        template <typename T>
        typename result<T>::type
        operator()(T const & in)const
        {
            return in;
        }
        typedef as_const_ref type;
    };

     struct as_ref{
        template <typename T>
        struct result{
            typedef typename std::add_lvalue_reference<
              typename std::remove_const<T>::type
            >::type type;
        };

        template <typename T>
        typename result<T>::type
        operator()(T & in)const
        {
            return in;
        }
        typedef as_ref type;
    };
    
    template <typename AcessF>
    struct add_const_to_ref;

    template<>
    struct add_const_to_ref<as_ref> : as_const_ref {};
    template<>
    struct add_const_to_ref<as_const_ref> : as_const_ref{};
    template<>
    struct add_const_to_ref<as_value> : as_value{};

   struct as_pointer{
        template <typename T>
        struct result{
              typedef typename std::remove_const<T>::type * type;
        };

        template <typename T>
        typename result<T>::type
        operator()(T & in)const
        {
            return &in;
        }
         typedef as_pointer type;
    };

}}//quan::fun

#endif
