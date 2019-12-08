#ifndef QUAN_OF_LENGTH_HPP_INCLUDED
#define QUAN_OF_LENGTH_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
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

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>
#include <quan/meta/name_anonymous_abstract_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_length{

        static const char* abstract_quantity_name()
        {
            return "length";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };


       typedef meta::dimension<
            quan::meta::dim_length<1> 
       > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_length
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<457201,250000>::type,
                    quan::meta::int32<0>
                >
            > fathom_us;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<11>,
                    meta::rational<1495979,1000000>::type,
                    quan::meta::int32<0>
                >
            > AU;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<502921,250000>::type,
                    quan::meta::int32<0>
                >
            > ch;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<1143,625>::type,
                    quan::meta::int32<0>
                >
            > fathom;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<381,125>::type,
                    quan::meta::int32<0>
                >
            > ft;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<1524003,500000>::type,
                    quan::meta::int32<0>
                >
            > ft_us;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-2>,
                    meta::rational<127,50>::type,
                    quan::meta::int32<0>
                >
            > in;

            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-5>,
                    meta::rational<127,50>::type,
                    quan::meta::int32<0>
                >
            > thou;

            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-5>,
                    meta::rational<127,50>::type,
                    quan::meta::int32<1>
                >
            > mil;

            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<15>,
                    meta::rational<946073,100000>::type,
                    quan::meta::int32<0>
                >
            > l_y_;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<25146,15625>::type,
                    quan::meta::int32<0>
                >
            > mi;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<463,250>::type,
                    quan::meta::int32<0>
                >
            > naut_mile;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<16>,
                    meta::rational<1542839,500000>::type,
                    quan::meta::int32<0>
                >
            > pc;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-3>,
                    meta::rational<4233333,1000000>::type,
                    quan::meta::int32<0>
                >
            > pica_comp;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-3>,
                    meta::rational<2108759,500000>::type,
                    quan::meta::int32<0>
                >
            > pica_prn;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-4>,
                    meta::rational<1763889,500000>::type,
                    quan::meta::int32<0>
                >
            > point_comp;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-4>,
                    meta::rational<1757299,500000>::type,
                    quan::meta::int32<0>
                >
            > point_prn;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<502921,100000>::type,
                    quan::meta::int32<0>
                >
            > rd;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<1143,125>::type,
                    quan::meta::int32<0>
                >
            > yd;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-10>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > angstrom;
        };

        typedef  of_length type;
    };
 
    template<>
    inline
    const char*
    of_length::unprefixed_symbol<char>()
    {
        return "m";
    }

    template<>
    inline
    const wchar_t*
    of_length::unprefixed_symbol<wchar_t>()
    {
        return L"m";
    }

}//components

#ifdef QUAN_ENABLE_SELECTED_HOISTED_QUANTITIES
// enable hoisting of anonymous length
   template<>
   struct name_anonymous_abstract_quantity<
      abstract_quantity<
         quan::meta::components::of_length::dimension,
         quan::meta::anonymous_quantity_traits
      >
   >{
      typedef components::of_length::abstract_quantity type;
   };
#endif

}}//quan::meta

#endif
