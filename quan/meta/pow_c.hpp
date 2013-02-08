#ifndef QUAN_META_POW_C_HPP_INCLUDED
#define QUAN_META_POW_C_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <quan/static_assert.hpp>
#include <quan/meta/digits10.hpp>
/*
    compile time pow function for integers
*/

namespace quan{namespace meta{

    template<
        typename BaseIntegerType,
        BaseIntegerType Base,
      //  unsigned int Exp
        QUAN_INT32 Exp
    >
    struct pow_c;

    template<
        int Base
    >
    struct pow_c<int,Base ,0>{
        enum{ value = 1};
    };

   /* template<
        unsigned int Base
    >
    struct pow_c<unsigned int,Base ,0>{
        enum{ value = 1};
    };*/

    template<
        long Base
    >
    struct pow_c<long,Base ,0>{
        enum{ value = 1};
    };
   /* template<
        unsigned long Base
    >
    struct pow_c<unsigned long,Base ,0U>{
        enum{ value = 1};
    };*/

    template<
        typename IntegerType,
        IntegerType Base, 
        QUAN_INT32 Exp
    >
    struct pow_c {
        /*BOOST_MPL_ASSERT_RELATION(Exp, 
            <=,(quan::meta::max_ice_exponent<IntegerType,Base>::value));*/
        QUAN_STATIC_ASSERT((Exp
            <= quan::meta::digits10<IntegerType>::value));
        QUAN_STATIC_ASSERT( (Exp > 0 ));
        enum{ value = Base * pow_c<IntegerType,Base, Exp - 1 >::value };
    };

   
}}//quan::meta

#endif
