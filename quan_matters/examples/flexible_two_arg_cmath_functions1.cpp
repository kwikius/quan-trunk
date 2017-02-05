
/*
 Copyright (c) 2003-2014 Andy Little.
 Copyright T. Zach Laine 2006

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
    Enhanced implementation of atan2 will work with
    any two fixed_quantities of the same dimension, instead of being restricted to the same unit,
    but only if the static units allow conversions
*/

//###########################################
// uncomment to show disallow unit conversions in action
//#define QUAN_DISALLOW_IMPLICIT_UNIT_CONVERSIONS
//##########################################

#include <quan/out/angle.hpp>
#include <quan/out/length.hpp>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/or.hpp>

namespace quan{

    template <
        typename StaticUnit1,
        typename ValueType1,
        typename StaticUnit2,
        typename ValueType2
    >
    inline 
    typename quan::where_<
        quan::meta::and_<
            quan::meta::dimensionally_equivalent<StaticUnit1, StaticUnit2>,
            quan::meta::or_<
                quan::meta::and_<
                    quan::meta::allow_implicit_unit_conversions<StaticUnit1>,
                    quan::meta::allow_implicit_unit_conversions<StaticUnit2>
                >,
                quan::meta::is_math_same_conversion_factor<
                    typename quan::meta::get_conversion_factor<StaticUnit1>::type,
                    typename quan::meta::get_conversion_factor<StaticUnit2>::type
                >
            >            
        >,
        typename quan::angle_<
            typename quan::meta::binary_op<
                fixed_quantity<StaticUnit1, ValueType1>,
                quan::meta::divides,
                fixed_quantity<StaticUnit2, ValueType2>
            >::type
        >::rad
    >::type
    atan2(fixed_quantity<StaticUnit1, ValueType1> const & y,
        fixed_quantity<StaticUnit2, ValueType2> const & x)
    {
        typedef fixed_quantity<StaticUnit1, ValueType1> arg_type1;
        typedef fixed_quantity<StaticUnit2, ValueType2> arg_type2;

        // need to convert both quantities to a common unit
        // which this does, and if necessary promotes value_type
        typedef typename quan::meta::binary_op<
            arg_type1, quan::meta::minus, arg_type2
        >::type finest_grained_type;

        finest_grained_type ty = y;
        finest_grained_type tx = x;

         // 'type' of result of division must be a numeric
        typedef typename quan::meta::binary_op<
            finest_grained_type,
            quan::meta::divides,
            finest_grained_type
        >::type result_value_type;

        // To show this ... check it is a numeric
        static_assert(quan::meta::is_numeric<result_value_type>::value, "assertion failed");

        typedef typename quan::angle_<result_value_type>::rad result_type;
        
        using std::atan2;
        result_type result(
            atan2(ty.numeric_value(), tx.numeric_value())
        );
        return result;
    }

}//quan

using namespace quan;
int main()
{
    length::m  length1(10.0);
    length::yd length2 = length::yd(length1);

    std::cout << "length1 = " << length1 << "\n";
    std::cout << "length2 = " << length2 << "\n";

    std::cout << "atan2(length1, length2) = " << atan2(length1, length2) << "\n";
    std::cout << "std::atan2(1.,1.) = " << std::atan2(1.,1.) <<'\n';

    if( quan::compare(atan2(length1, length2),atan2(1.,1.),1e-12) ==0){
        std::cout << "match\n";
    }
    else {
        std::cout << "no match \n";
    }
    
    return 0;
}
