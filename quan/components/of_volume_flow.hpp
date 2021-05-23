#ifndef QUAN_OF_VOLUME_FLOW_HPP_INCLUDED
#define QUAN_OF_VOLUME_FLOW_HPP_INCLUDED
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

    struct of_volume_flow{

        static const char* abstract_quantity_name()
        {
            return "volume flow";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

         typedef meta::dimension<
            quan::meta::dim_length<3> 
            ,quan::meta::dim_time<-1> 
         > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_volume_flow
        > abstract_quantity;

       struct non_si_unit{

          typedef meta::unit<
             abstract_quantity,
             meta::conversion_factor<
                 meta::rational<-7>,
                 meta::rational<454609,36000>::type,
                 quan::meta::int32<0>
             >
          > gal_per_hr;
       };

       typedef  of_volume_flow type;

    };

    template<>
    inline
    const char*
    of_volume_flow::unprefixed_symbol<char>()
    {
        return "m3.s-1";
    }



}}}//quan::meta::components

#endif
