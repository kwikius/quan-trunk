#ifndef QUAN_OF_RECIPROCAL_LENGTH_HPP_INCLUDED
#define QUAN_OF_RECIPROCAL_LENGTH_HPP_INCLUDED
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

    struct of_reciprocal_length{

        static const char* abstract_quantity_name()
        {
            return "reciprocal length";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = -1,
            prefix_offset = 0
        };

        typedef meta::dimension<
            meta::rational<-1>, // length
            meta::rational<0>, // time
            meta::rational<0>, // mass
            meta::rational<0>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_reciprocal_length
        > abstract_quantity;

        typedef  of_reciprocal_length type;

    };

    template<>
    inline
    const char*
    of_reciprocal_length::unprefixed_symbol<char>()
    {
        return "m-1";
    }

    struct non_si_unit_of_reciprocal_length{
    };

}//components

#ifdef QUAN_ENABLE_SELECTED_HOISTED_QUANTITIES

   template<>
   struct name_anonymous_abstract_quantity<
      quan::meta::abstract_quantity<
         quan::meta::components::of_reciprocal_length::dimension,
         quan::meta::anonymous_quantity_traits
      >
   >{
      typedef quan::meta::components::of_reciprocal_length::abstract_quantity type;
   };

#endif

}}//quan::meta

#endif
