#ifndef QUAN_OF_AREA_HPP_INCLUDED
#define QUAN_OF_AREA_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

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
            meta::rational<2>, // length
            meta::rational<0>, // time
            meta::rational<0>, // mass
            meta::rational<0>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
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
