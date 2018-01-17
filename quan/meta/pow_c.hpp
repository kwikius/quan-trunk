#ifndef QUAN_META_POW_C_HPP_INCLUDED
#define QUAN_META_POW_C_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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
        int64_t Exp
    >
    struct pow_c;

    template<
        int Base
    >
    struct pow_c<int,Base ,0>{
        enum{ value = 1};
    };

    template<
        unsigned int Base
    >
    struct pow_c<unsigned int,Base ,0>{
        enum{ value = 1};
    };

    template<
        long Base
    >
    struct pow_c<long,Base ,0>{
        enum{ value = 1};
    };

    
    template<
        unsigned long Base
    >
    struct pow_c<unsigned long,Base ,0U>{
        enum{ value = 1};
    };

    template<
        long long Base
    >
    struct pow_c<long long,Base ,0>{
        enum{ value = 1};
    };

    template<
       unsigned long long Base
    >
    struct pow_c<unsigned long long,Base ,0>{
        enum{ value = 1};
    };

    template<
        typename IntegerType,
        IntegerType Base, 
        int64_t Exp
    >
    struct pow_c {

        QUAN_STATIC_ASSERT((Exp
            <= quan::meta::digits10<IntegerType>::value));
        QUAN_STATIC_ASSERT( (Exp > 0 ));
        enum{ value = Base * pow_c<IntegerType,Base, Exp - 1 >::value };
    };

   
}}//quan::meta

#endif
