#ifndef QUAN_OF_PRESSURE_HPP_INCLUDED
#define QUAN_OF_PRESSURE_HPP_INCLUDED
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

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_pressure{

        static const char* abstract_quantity_name()
        {
            return "pressure";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

         typedef meta::dimension<
            quan::meta::dim_length<-1> 
            ,quan::meta::dim_time<-2> 
            ,quan::meta::dim_mass<1> 
         > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_pressure
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<5>,
                    meta::rational<4053,4000>::type,
                    quan::meta::int32<0>
                >
            > atm;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>,
                    meta::rational<196133,20000>::type,
                    quan::meta::int32<0>
                >
            > at;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<5>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > bar;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<66661,50000>::type,
                    quan::meta::int32<0>
                >
            > cm_mercury0C;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<166653,125000>::type,
                    quan::meta::int32<0>
                >
            > cmHg;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<490319,50000>::type,
                    quan::meta::int32<0>
                >
            > cm_water4C;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<196133,20000>::type,
                    quan::meta::int32<0>
                >
            > cmH20;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > dyn_per_cm2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>,
                    meta::rational<2031833,500000>::type,
                    quan::meta::int32<0>
                >
            > ftHg;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<149449,50000>::type,
                    quan::meta::int32<0>
                >
            > ft_water39_2F;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<2989067,1000000>::type,
                    quan::meta::int32<0>
                >
            > ftH20;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<196133,20000>::type,
                    quan::meta::int32<1>
                >
            > gf_per_cm2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<169319,50000>::type,
                    quan::meta::int32<0>
                >
            > in_mercury32F;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<67537,20000>::type,
                    quan::meta::int32<0>
                >
            > in_mercury60F;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<3386389,1000000>::type,
                    quan::meta::int32<0>
                >
            > inHg;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<2>,
                    meta::rational<124541,50000>::type,
                    quan::meta::int32<0>
                >
            > in_water39_2F;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<2>,
                    meta::rational<2490889,1000000>::type,
                    quan::meta::int32<0>
                >
            > inH20;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>,
                    meta::rational<196133,20000>::type,
                    quan::meta::int32<1>
                >
            > kgf_per_cm2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<196133,20000>::type,
                    quan::meta::int32<0>
                >
            > kgf_per_m2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<6>,
                    meta::rational<196133,20000>::type,
                    quan::meta::int32<0>
                >
            > kgf_per_mm2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<6>,
                    meta::rational<6894757,1000000>::type,
                    quan::meta::int32<0>
                >
            > ksi;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<2>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<2>
                >
            > mbar;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<2>,
                    meta::rational<166653,125000>::type,
                    quan::meta::int32<0>
                >
            > mmHg;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<196133,20000>::type,
                    quan::meta::int32<1>
                >
            > mmH20;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<2394013,500000>::type,
                    quan::meta::int32<0>
                >
            > lbf_per_ft2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<6894757,1000000>::type,
                    quan::meta::int32<0>
                >
            > psi;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<372041,250000>::type,
                    quan::meta::int32<0>
                >
            > poundal_per_ft2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<2>,
                    meta::rational<166653,125000>::type,
                    quan::meta::int32<1>
                >
            > torr;
        };

        typedef  of_pressure type;

    };

    template<>
    inline
    const char*
    of_pressure::unprefixed_symbol<char>()
    {
        return "Pa";
    }

}}}//quan::meta::components
#endif
