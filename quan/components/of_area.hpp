#ifndef QUAN_OF_AREA_HPP_INCLUDED
#define QUAN_OF_AREA_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

/*
 Copyright (c) 2003-2019 Andy Little.

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

#include <quan/components/of_named_quantity.hpp>
#include <quan/meta/name_anonymous_abstract_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_area{

        static const char* abstract_quantity_name()
        {
            return "area";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 2,
            prefix_offset = 0
        };

       typedef meta::dimension<
            quan::meta::dim_length<2> 
       > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_area
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<4046873,1000000>::type,
                    quan::meta::int32<0>
                >
            > acre;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<2>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > a;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-28>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > b;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-10>,
                    meta::rational<202683,40000>::type,
                    quan::meta::int32<0>
                >
            > circular_mil;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > ha;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-2>,
                    meta::rational<145161,15625>::type,
                    quan::meta::int32<0>
                >
            > ft2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-4>,
                    meta::rational<16129,2500>::type,
                    quan::meta::int32<0>
                >
            > in2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<6>,
                    meta::rational<647497,250000>::type,
                    quan::meta::int32<0>
                >
            > mi2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<6>,
                    meta::rational<1294999,500000>::type,
                    quan::meta::int32<0>
                >
            > mi2_us_survey;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<4180637,500000>::type,
                    quan::meta::int32<0>
                >
            > yd2;
        };

        typedef  of_area type;

    };

    template<>
    inline
    const char*
    of_area::unprefixed_symbol<char>()
    {
        return "m2";
    }

}//components

#ifdef QUAN_ENABLE_SELECTED_HOISTED_QUANTITIES

   template<>
   struct name_anonymous_abstract_quantity<
      quan::meta::abstract_quantity<
         quan::meta::components::of_area::dimension,
         quan::meta::anonymous_quantity_traits
      >
   >{
      typedef quan::meta::components::of_area::abstract_quantity type;
   };
#endif

}}//quan::meta::
#endif
