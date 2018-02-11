#ifndef QUAN_FIXED_QUANTITY_COMPARE_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_COMPARE_HPP_INCLUDED

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

/*
    compare(pqa,pqb,eps) works like strcmp and string::compare:
    if( a == b ) return 0;
    if( a > b ) return 1;
    if( a < b ) return -1;

    Other comparison operators convert lhs and rhs to one common quantity type
    Then compare numeric values
*/

#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/fixed_quantity/operations/add_subtract.hpp>
#include <quan/archetypes/meta/conversion_factor_concept.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/fixed_quantity/operations/abs.hpp>
#include <quan/meta/and.hpp>
#include <quan/where.hpp>
#if defined QUAN_AVR_NO_CPP_STDLIB
extern "C"{
   #include <math.h>
   #include <stdlib.h>
}
#else
#include <cmath>
#include <cstdlib>
#endif

namespace quan{

    // for compatibility  of built_in types;
    // fails overload resolution?
    template<typename TL, typename TR, typename TE>
    inline QUAN_CONSTEXPR
    typename quan::where_<
        quan ::meta::are_numeric<TL,TR>,
        int 
    >::type
    compare( TL const & a, TR const & b, TE const & eps )
    {
 #ifndef QUAN_AVR_NO_CPP_STDLIB
           using std::abs;
#endif

        return ( abs(a-b) <= abs(eps))
        ? 0 
        :( ((a-b) < 0)? -1: 1 );
    }

    template<typename TL, typename TR>
    inline QUAN_CONSTEXPR
    typename quan::where_<
        quan ::meta::are_numeric<TL,TR>,
        int 
    >::type
    compare( TL const & a, TR const & b )
    {
/*
        typedef typename quan ::meta::binary_op<
            TL,quan ::meta::minus,TR
        >::type eps_type;
*/
        return  (( a - b ) == 0)
        ? 0 
        :( ((a-b) < 0)? -1: 1 );
    }

    template<
        typename StaticUnit_L,typename NumericType_L,
        typename StaticUnit_R,typename NumericType_R,
        typename StaticUnit_E,typename NumericType_E
    >
    inline  QUAN_CONSTEXPR
    typename quan::where_<
        quan::meta::and_<
            quan::meta::dimensionally_equivalent<
                StaticUnit_L,StaticUnit_R
            >,
            quan::meta::dimensionally_equivalent<
                StaticUnit_R, StaticUnit_E
            >
        >,
        int 
    >::type
    compare(
        fixed_quantity< 
            StaticUnit_L,NumericType_L
        >const & lhs,
        fixed_quantity<
            StaticUnit_R,NumericType_R
        >const& rhs,
        fixed_quantity<
            StaticUnit_E,NumericType_E
        >const& ep
    )
    {
        typedef typename quan ::meta::binary_op<
            fixed_quantity< 
                StaticUnit_L,NumericType_L
            >,
            quan ::meta::minus,
            fixed_quantity<
                StaticUnit_R, NumericType_R
            >
        >::type wkg_type;

       #ifndef QUAN_AVR_NO_CPP_STDLIB
           using std::abs;
       #endif
      return ( abs( wkg_type{lhs}.numeric_value() - wkg_type{rhs}.numeric_value() ) <= abs(wkg_type{ep}.numeric_value()) )
      ?  0
      : ( ( wkg_type{lhs}.numeric_value() - wkg_type{rhs}.numeric_value() ) < 0) 
      ? -1
      : 1;

    }

    template<
        typename StaticUnit_L,typename NumericType_L,
        typename StaticUnit_R,typename NumericType_R
    >
    inline QUAN_CONSTEXPR
    typename quan::where_<
        quan ::meta::dimensionally_equivalent<
            StaticUnit_L,
            StaticUnit_R
        >,
        int 
    >::type
    compare(
        fixed_quantity< 
            StaticUnit_L,NumericType_L
        >const & lhs,
        fixed_quantity<
            StaticUnit_R,NumericType_R
        >const& rhs
    )
    {
        typedef typename quan ::meta::binary_op<
            fixed_quantity< 
                StaticUnit_L,NumericType_L
            >,
            quan ::meta::minus,
            fixed_quantity<
                StaticUnit_R, NumericType_R
            >
        >::type wkg_type;

      return ( (wkg_type{lhs} - wkg_type{rhs}).numeric_value() < 0) 
      ? -1 
      : ( (wkg_type{lhs} - wkg_type{rhs}).numeric_value() > 0)
      ? 1
      : 0 ;

    }

    #define QUAN_COMPARISON_OPERATOR(Op) \
    template< \
        typename StaticUnit_L, \
        typename NumericType_L, \
        typename StaticUnit_R, \
        typename NumericType_R \
    > \
    inline QUAN_CONSTEXPR \
    typename quan::where_< \
        quan ::meta::dimensionally_equivalent< \
            StaticUnit_L,StaticUnit_R \
        >, \
        bool \
    >::type \
    operator Op (  \
        fixed_quantity< \
            StaticUnit_L,NumericType_L\
        >const & lhs,\
        fixed_quantity<\
            StaticUnit_R,NumericType_R\
        >const& rhs )\
    {\
        typedef typename quan ::meta::binary_op< \
            fixed_quantity< \
                StaticUnit_L,NumericType_L\
            >,\
            quan ::meta::minus,\
            fixed_quantity<\
                StaticUnit_R,NumericType_R\
            >\
        >::type common_type;\
        return common_type{lhs}.numeric_value() Op common_type{rhs}.numeric_value(); \
    }

    QUAN_COMPARISON_OPERATOR(<)
    QUAN_COMPARISON_OPERATOR(<=)
    QUAN_COMPARISON_OPERATOR(==)
    QUAN_COMPARISON_OPERATOR(!=)
    QUAN_COMPARISON_OPERATOR(>=)
    QUAN_COMPARISON_OPERATOR(>)

    #undef QUAN_COMPARISON_OPERATOR
    
} //quan

#endif
