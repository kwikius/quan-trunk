
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
    test quan cmath overload functionality
*/

#include <quan_matters/test/test.hpp>
#include <quan/cmath.hpp>
#include <quan/mass.hpp>
#include <quan/meta/rational.hpp>


#if 1
void test_cmath();
int errors = 0;
int main()
{
   test_cmath();
   EPILOGUE
}
#endif

template <typename T1, typename T2>
typename quan::where_<
    std::is_same<T1, T2>,
    bool
>::type
check_same_types(T1 a1, T2 a2)
{ return true; }

template <typename T1, typename T2>
typename quan::where_not<
    std::is_same<T1, T2>,
    bool
>::type
check_same_types(T1 a1, T2 a2)
{ return false; }

void test_cmath()
{
    const double PI = 3.14159;

    // mass
    quan::mass_<int>::kg quan_mass_int_kg(10);
    int builtin_mass_int_kg = 10;
    quan::mass_<float>::kg quan_mass_float_kg(10);
    float builtin_mass_float_kg = 10;
    quan::mass_<double>::kg quan_mass_double_kg(10);
    double builtin_mass_double_kg = 10;
    quan::mass_<long double>::kg quan_mass_long_double_kg(10);
    long double builtin_mass_long_double_kg = 10;
    quan::mass_<int>::lb quan_mass_int_lb(10);
    int builtin_mass_int_lb = 10;
    quan::mass_<float>::lb quan_mass_float_lb(10);
    float builtin_mass_float_lb = 10;
    quan::mass_<double>::lb quan_mass_double_lb(10);
    double builtin_mass_double_lb = 10;
    quan::mass_<long double>::lb quan_mass_long_double_lb(10);
    long double builtin_mass_long_double_lb = 10;


    int quan_exp_result = 0;
    int quan_exp = 3;
    int builtin_exp_result = 0;
    int builtin_exp = 3;

    quan::mathematic_angle<quan::meta::rational<1>, int> int_mathematic_angle(static_cast<int>(PI));
    int builtin_int_angle = static_cast<int>(PI);
    int builtin_int = static_cast<int>(0.5);
    quan::mathematic_angle<quan::meta::rational<1>, float> float_mathematic_angle(PI);
    float builtin_float_angle = PI;
    float builtin_float = 0.5;
    quan::mathematic_angle<quan::meta::rational<1>, double> double_mathematic_angle(PI);
    double builtin_double_angle = PI;
    double builtin_double = 0.5;
    quan::mathematic_angle<quan::meta::rational<1>, long double> long_double_mathematic_angle(PI);
    long double builtin_long_double_angle = PI;
    long double builtin_long_double = 0.5;

    QUAN_CHECK_CLOSE( abs(quan_mass_int_kg).numeric_value(),
                       std::abs(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( abs(quan_mass_int_kg).numeric_value(), std::abs(builtin_mass_int_kg) );
    QUAN_CHECK_CLOSE( abs(quan_mass_float_kg).numeric_value(),
                       std::abs(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( abs(quan_mass_float_kg).numeric_value(), std::abs(builtin_mass_float_kg) );
    QUAN_CHECK_CLOSE( abs(quan_mass_double_kg).numeric_value(),
                       std::abs(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( abs(quan_mass_double_kg).numeric_value(), std::abs(builtin_mass_double_kg) );
    QUAN_CHECK_CLOSE( abs(quan_mass_long_double_kg).numeric_value(),
                       std::abs(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( abs(quan_mass_long_double_kg).numeric_value(), std::abs(builtin_mass_long_double_kg) );
    QUAN_CHECK_CLOSE( abs(quan_mass_int_lb).numeric_value(),
                       std::abs(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( abs(quan_mass_int_lb).numeric_value(), std::abs(builtin_mass_int_lb) );
    QUAN_CHECK_CLOSE( abs(quan_mass_float_lb).numeric_value(),
                       std::abs(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( abs(quan_mass_float_lb).numeric_value(), std::abs(builtin_mass_float_lb) );
    QUAN_CHECK_CLOSE( abs(quan_mass_double_lb).numeric_value(),
                       std::abs(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( abs(quan_mass_double_lb).numeric_value(), std::abs(builtin_mass_double_lb) );
    QUAN_CHECK_CLOSE( abs(quan_mass_long_double_lb).numeric_value(),
                       std::abs(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( abs(quan_mass_long_double_lb).numeric_value(), std::abs(builtin_mass_long_double_lb) );
/*
    QUAN_CHECK_CLOSE( quan::acos(builtin_int).numeric_value(),
                       std::acos(builtin_int),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::acos(builtin_int).numeric_value(), std::acos(builtin_int) );
    QUAN_CHECK_CLOSE( quan::acos(builtin_float).numeric_value(),
                       std::acos(builtin_float),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::acos(builtin_float).numeric_value(), std::acos(builtin_float) );
    QUAN_CHECK_CLOSE( quan::acos(builtin_double).numeric_value(),
                       std::acos(builtin_double),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::acos(builtin_double).numeric_value(), std::acos(builtin_double) );
    QUAN_CHECK_CLOSE( quan::acos(builtin_long_double).numeric_value(),
                       std::acos(builtin_long_double),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::acos(builtin_long_double).numeric_value(), std::acos(builtin_long_double) );

    QUAN_CHECK_CLOSE( quan::asin(builtin_int).numeric_value(),
                       std::asin(builtin_int),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::asin(builtin_int).numeric_value(), std::asin(builtin_int) );
    QUAN_CHECK_CLOSE( quan::asin(builtin_float).numeric_value(),
                       std::asin(builtin_float),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::asin(builtin_float).numeric_value(), std::asin(builtin_float) );
    QUAN_CHECK_CLOSE( quan::asin(builtin_double).numeric_value(),
                       std::asin(builtin_double),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::asin(builtin_double).numeric_value(), std::asin(builtin_double) );
    QUAN_CHECK_CLOSE( quan::asin(builtin_long_double).numeric_value(),
                       std::asin(builtin_long_double),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::asin(builtin_long_double).numeric_value(), std::asin(builtin_long_double) );

    QUAN_CHECK_CLOSE( quan::atan(builtin_int).numeric_value(),
                       std::atan(builtin_int),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::atan(builtin_int).numeric_value(), std::atan(builtin_int) );
    QUAN_CHECK_CLOSE( quan::atan(builtin_float).numeric_value(),
                       std::atan(builtin_float),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::atan(builtin_float).numeric_value(), std::atan(builtin_float) );
    QUAN_CHECK_CLOSE( quan::atan(builtin_double).numeric_value(),
                       std::atan(builtin_double),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::atan(builtin_double).numeric_value(), std::atan(builtin_double) );
    QUAN_CHECK_CLOSE( quan::atan(builtin_long_double).numeric_value(),
                       std::atan(builtin_long_double),
                       FP_MAX_DIFFERENCE );
    check_same_types( quan::atan(builtin_long_double).numeric_value(), std::atan(builtin_long_double) );
*/
    QUAN_CHECK_CLOSE( atan2(quan_mass_float_kg, quan_mass_float_kg).numeric_value(),
                       std::atan2(builtin_mass_float_kg, builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( atan2(quan_mass_float_kg, quan_mass_float_kg).numeric_value(), std::atan2(builtin_mass_float_kg, builtin_mass_float_kg) );
    QUAN_CHECK_CLOSE( atan2(quan_mass_double_kg, quan_mass_double_kg).numeric_value(),
                       std::atan2(builtin_mass_double_kg, builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( atan2(quan_mass_double_kg, quan_mass_double_kg).numeric_value(), std::atan2(builtin_mass_double_kg, builtin_mass_double_kg) );
    QUAN_CHECK_CLOSE( atan2(quan_mass_long_double_kg, quan_mass_long_double_kg).numeric_value(),
                       std::atan2(builtin_mass_long_double_kg, builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( atan2(quan_mass_long_double_kg, quan_mass_long_double_kg).numeric_value(), std::atan2(builtin_mass_long_double_kg, builtin_mass_long_double_kg) );
    QUAN_CHECK_CLOSE( atan2(quan_mass_float_lb, quan_mass_float_lb).numeric_value(),
                       std::atan2(builtin_mass_float_lb, builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( atan2(quan_mass_float_lb, quan_mass_float_lb).numeric_value(), std::atan2(builtin_mass_float_lb, builtin_mass_float_lb) );
    QUAN_CHECK_CLOSE( atan2(quan_mass_double_lb, quan_mass_double_lb).numeric_value(),
                       std::atan2(builtin_mass_double_lb, builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( atan2(quan_mass_double_lb, quan_mass_double_lb).numeric_value(), std::atan2(builtin_mass_double_lb, builtin_mass_double_lb) );
    QUAN_CHECK_CLOSE( atan2(quan_mass_long_double_lb, quan_mass_long_double_lb).numeric_value(),
                       std::atan2(builtin_mass_long_double_lb, builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( atan2(quan_mass_long_double_lb, quan_mass_long_double_lb).numeric_value(), std::atan2(builtin_mass_long_double_lb, builtin_mass_long_double_lb) );

    QUAN_CHECK_CLOSE( ceil(quan_mass_int_kg).numeric_value(),
                       std::ceil(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( ceil(quan_mass_int_kg).numeric_value(), std::ceil(builtin_mass_int_kg) );
    QUAN_CHECK_CLOSE( ceil(quan_mass_float_kg).numeric_value(),
                       std::ceil(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( ceil(quan_mass_float_kg).numeric_value(), std::ceil(builtin_mass_float_kg) );
    QUAN_CHECK_CLOSE( ceil(quan_mass_double_kg).numeric_value(),
                       std::ceil(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( ceil(quan_mass_double_kg).numeric_value(), std::ceil(builtin_mass_double_kg) );
    QUAN_CHECK_CLOSE( ceil(quan_mass_long_double_kg).numeric_value(),
                       std::ceil(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( ceil(quan_mass_long_double_kg).numeric_value(), std::ceil(builtin_mass_long_double_kg) );
    QUAN_CHECK_CLOSE( ceil(quan_mass_int_lb).numeric_value(),
                       std::ceil(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( ceil(quan_mass_int_lb).numeric_value(), std::ceil(builtin_mass_int_lb) );
    QUAN_CHECK_CLOSE( ceil(quan_mass_float_lb).numeric_value(),
                       std::ceil(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( ceil(quan_mass_float_lb).numeric_value(), std::ceil(builtin_mass_float_lb) );
    QUAN_CHECK_CLOSE( ceil(quan_mass_double_lb).numeric_value(),
                       std::ceil(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( ceil(quan_mass_double_lb).numeric_value(), std::ceil(builtin_mass_double_lb) );
    QUAN_CHECK_CLOSE( ceil(quan_mass_long_double_lb).numeric_value(),
                       std::ceil(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( ceil(quan_mass_long_double_lb).numeric_value(), std::ceil(builtin_mass_long_double_lb) );

    QUAN_CHECK_CLOSE( cos(int_mathematic_angle),
                       std::cos(builtin_int_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( cos(int_mathematic_angle), std::cos(builtin_int_angle) );
    QUAN_CHECK_CLOSE( cos(float_mathematic_angle),
                       std::cos(builtin_float_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( cos(float_mathematic_angle), std::cos(builtin_float_angle) );
    QUAN_CHECK_CLOSE( cos(double_mathematic_angle),
                       std::cos(builtin_double_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( cos(double_mathematic_angle), std::cos(builtin_double_angle) );
    QUAN_CHECK_CLOSE( cos(long_double_mathematic_angle),
                       std::cos(builtin_long_double_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( cos(long_double_mathematic_angle), std::cos(builtin_long_double_angle) );
/*
    QUAN_CHECK_CLOSE( fabs(quan_mass_int_kg).numeric_value(),
                       std::fabs(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( fabs(quan_mass_int_kg).numeric_value(), std::fabs(builtin_mass_int_kg) );
    QUAN_CHECK_CLOSE( fabs(quan_mass_float_kg).numeric_value(),
                       std::fabs(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( fabs(quan_mass_float_kg).numeric_value(), std::fabs(builtin_mass_float_kg) );
    QUAN_CHECK_CLOSE( fabs(quan_mass_double_kg).numeric_value(),
                       std::fabs(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( fabs(quan_mass_double_kg).numeric_value(), std::fabs(builtin_mass_double_kg) );
    QUAN_CHECK_CLOSE( fabs(quan_mass_long_double_kg).numeric_value(),
                       std::fabs(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( fabs(quan_mass_long_double_kg).numeric_value(), std::fabs(builtin_mass_long_double_kg) );
    QUAN_CHECK_CLOSE( fabs(quan_mass_int_lb).numeric_value(),
                       std::fabs(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( fabs(quan_mass_int_lb).numeric_value(), std::fabs(builtin_mass_int_lb) );
    QUAN_CHECK_CLOSE( fabs(quan_mass_float_lb).numeric_value(),
                       std::fabs(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( fabs(quan_mass_float_lb).numeric_value(), std::fabs(builtin_mass_float_lb) );
    QUAN_CHECK_CLOSE( fabs(quan_mass_double_lb).numeric_value(),
                       std::fabs(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( fabs(quan_mass_double_lb).numeric_value(), std::fabs(builtin_mass_double_lb) );
    QUAN_CHECK_CLOSE( fabs(quan_mass_long_double_lb).numeric_value(),
                       std::fabs(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( fabs(quan_mass_long_double_lb).numeric_value(), std::fabs(builtin_mass_long_double_lb) );
*/
    QUAN_CHECK_CLOSE( floor(quan_mass_int_kg).numeric_value(),
                       std::floor(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( floor(quan_mass_int_kg).numeric_value(), std::floor(builtin_mass_int_kg) );
    QUAN_CHECK_CLOSE( floor(quan_mass_float_kg).numeric_value(),
                       std::floor(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( floor(quan_mass_float_kg).numeric_value(), std::floor(builtin_mass_float_kg) );
    QUAN_CHECK_CLOSE( floor(quan_mass_double_kg).numeric_value(),
                       std::floor(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( floor(quan_mass_double_kg).numeric_value(), std::floor(builtin_mass_double_kg) );
    QUAN_CHECK_CLOSE( floor(quan_mass_long_double_kg).numeric_value(),
                       std::floor(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( floor(quan_mass_long_double_kg).numeric_value(), std::floor(builtin_mass_long_double_kg) );
    QUAN_CHECK_CLOSE( floor(quan_mass_int_lb).numeric_value(),
                       std::floor(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( floor(quan_mass_int_lb).numeric_value(), std::floor(builtin_mass_int_lb) );
    QUAN_CHECK_CLOSE( floor(quan_mass_float_lb).numeric_value(),
                       std::floor(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( floor(quan_mass_float_lb).numeric_value(), std::floor(builtin_mass_float_lb) );
    QUAN_CHECK_CLOSE( floor(quan_mass_double_lb).numeric_value(),
                       std::floor(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( floor(quan_mass_double_lb).numeric_value(), std::floor(builtin_mass_double_lb) );
    QUAN_CHECK_CLOSE( floor(quan_mass_long_double_lb).numeric_value(),
                       std::floor(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( floor(quan_mass_long_double_lb).numeric_value(), std::floor(builtin_mass_long_double_lb) );
/*
    QUAN_CHECK_CLOSE( fmod(quan_mass_float_kg, quan_mass_float_kg).numeric_value(),
                       std::fmod(builtin_mass_float_kg, builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( fmod(quan_mass_float_kg, quan_mass_float_kg).numeric_value(), std::fmod(builtin_mass_float_kg, builtin_mass_float_kg) );
    QUAN_CHECK_CLOSE( fmod(quan_mass_double_kg, quan_mass_double_kg).numeric_value(),
                       std::fmod(builtin_mass_double_kg, builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( fmod(quan_mass_double_kg, quan_mass_double_kg).numeric_value(), std::fmod(builtin_mass_double_kg, builtin_mass_double_kg) );
    QUAN_CHECK_CLOSE( fmod(quan_mass_long_double_kg, quan_mass_long_double_kg).numeric_value(),
                       std::fmod(builtin_mass_long_double_kg, builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    check_same_types( fmod(quan_mass_long_double_kg, quan_mass_long_double_kg).numeric_value(), std::fmod(builtin_mass_long_double_kg, builtin_mass_long_double_kg) );
    QUAN_CHECK_CLOSE( fmod(quan_mass_float_lb, quan_mass_float_lb).numeric_value(),
                       std::fmod(builtin_mass_float_lb, builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( fmod(quan_mass_float_lb, quan_mass_float_lb).numeric_value(), std::fmod(builtin_mass_float_lb, builtin_mass_float_lb) );
    QUAN_CHECK_CLOSE( fmod(quan_mass_double_lb, quan_mass_double_lb).numeric_value(),
                       std::fmod(builtin_mass_double_lb, builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( fmod(quan_mass_double_lb, quan_mass_double_lb).numeric_value(), std::fmod(builtin_mass_double_lb, builtin_mass_double_lb) );
    QUAN_CHECK_CLOSE( fmod(quan_mass_long_double_lb, quan_mass_long_double_lb).numeric_value(),
                       std::fmod(builtin_mass_long_double_lb, builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );
    check_same_types( fmod(quan_mass_long_double_lb, quan_mass_long_double_lb).numeric_value(), std::fmod(builtin_mass_long_double_lb, builtin_mass_long_double_lb) );

    QUAN_CHECK_CLOSE( frexp(quan_mass_int_kg, &quan_exp_result).numeric_value(),
                       std::frexp(builtin_mass_int_kg, &builtin_exp_result),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_exp_result, builtin_exp_result,
                       FP_MAX_DIFFERENCE );
    check_same_types( frexp(quan_mass_int_kg, &quan_exp_result).numeric_value(), std::frexp(builtin_mass_int_kg, &builtin_exp_result) );
    QUAN_CHECK_CLOSE( frexp(quan_mass_float_kg, &quan_exp_result).numeric_value(),
                       std::frexp(builtin_mass_float_kg, &builtin_exp_result),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_exp_result, builtin_exp_result,
                       FP_MAX_DIFFERENCE );
    check_same_types( frexp(quan_mass_float_kg, &quan_exp_result).numeric_value(), std::frexp(builtin_mass_float_kg, &builtin_exp_result) );
    QUAN_CHECK_CLOSE( frexp(quan_mass_double_kg, &quan_exp_result).numeric_value(),
                       std::frexp(builtin_mass_double_kg, &builtin_exp_result),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_exp_result, builtin_exp_result,
                       FP_MAX_DIFFERENCE );
    check_same_types( frexp(quan_mass_double_kg, &quan_exp_result).numeric_value(), std::frexp(builtin_mass_double_kg, &builtin_exp_result) );
    QUAN_CHECK_CLOSE( frexp(quan_mass_long_double_kg, &quan_exp_result).numeric_value(),
                       std::frexp(builtin_mass_long_double_kg, &builtin_exp_result),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_exp_result, builtin_exp_result,
                       FP_MAX_DIFFERENCE );
    check_same_types( frexp(quan_mass_long_double_kg, &quan_exp_result).numeric_value(), std::frexp(builtin_mass_long_double_kg, &builtin_exp_result) );
    QUAN_CHECK_CLOSE( frexp(quan_mass_int_lb, &quan_exp_result).numeric_value(),
                       std::frexp(builtin_mass_int_lb, &builtin_exp_result),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_exp_result, builtin_exp_result,
                       FP_MAX_DIFFERENCE );
    check_same_types( frexp(quan_mass_int_lb, &quan_exp_result).numeric_value(), std::frexp(builtin_mass_int_lb, &builtin_exp_result) );
    QUAN_CHECK_CLOSE( frexp(quan_mass_float_lb, &quan_exp_result).numeric_value(),
                       std::frexp(builtin_mass_float_lb, &builtin_exp_result),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_exp_result, builtin_exp_result,
                       FP_MAX_DIFFERENCE );
    check_same_types( frexp(quan_mass_float_lb, &quan_exp_result).numeric_value(), std::frexp(builtin_mass_float_lb, &builtin_exp_result) );
    QUAN_CHECK_CLOSE( frexp(quan_mass_double_lb, &quan_exp_result).numeric_value(),
                       std::frexp(builtin_mass_double_lb, &builtin_exp_result),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_exp_result, builtin_exp_result,
                       FP_MAX_DIFFERENCE );
    check_same_types( frexp(quan_mass_double_lb, &quan_exp_result).numeric_value(), std::frexp(builtin_mass_double_lb, &builtin_exp_result) );
    QUAN_CHECK_CLOSE( frexp(quan_mass_long_double_lb, &quan_exp_result).numeric_value(),
                       std::frexp(builtin_mass_long_double_lb, &builtin_exp_result),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_exp_result, builtin_exp_result,
                       FP_MAX_DIFFERENCE );
    check_same_types( frexp(quan_mass_long_double_lb, &quan_exp_result).numeric_value(), std::frexp(builtin_mass_long_double_lb, &builtin_exp_result) );

    QUAN_CHECK_CLOSE( ldexp(quan_mass_int_kg, quan_exp).numeric_value(),
                       std::ldexp(builtin_mass_int_kg, builtin_exp),
                       FP_MAX_DIFFERENCE );
    check_same_types( ldexp(quan_mass_int_kg, quan_exp).numeric_value(), std::ldexp(builtin_mass_int_kg, builtin_exp) );
    QUAN_CHECK_CLOSE( ldexp(quan_mass_float_kg, quan_exp).numeric_value(),
                       std::ldexp(builtin_mass_float_kg, builtin_exp),
                       FP_MAX_DIFFERENCE );
    check_same_types( ldexp(quan_mass_float_kg, quan_exp).numeric_value(), std::ldexp(builtin_mass_float_kg, builtin_exp) );
    QUAN_CHECK_CLOSE( ldexp(quan_mass_double_kg, quan_exp).numeric_value(),
                       std::ldexp(builtin_mass_double_kg, builtin_exp),
                       FP_MAX_DIFFERENCE );
    check_same_types( ldexp(quan_mass_double_kg, quan_exp).numeric_value(), std::ldexp(builtin_mass_double_kg, builtin_exp) );
    QUAN_CHECK_CLOSE( ldexp(quan_mass_long_double_kg, quan_exp).numeric_value(),
                       std::ldexp(builtin_mass_long_double_kg, builtin_exp),
                       FP_MAX_DIFFERENCE );
    check_same_types( ldexp(quan_mass_long_double_kg, quan_exp).numeric_value(), std::ldexp(builtin_mass_long_double_kg, builtin_exp) );
    QUAN_CHECK_CLOSE( ldexp(quan_mass_int_lb, quan_exp).numeric_value(),
                       std::ldexp(builtin_mass_int_lb, builtin_exp),
                       FP_MAX_DIFFERENCE );
    check_same_types( ldexp(quan_mass_int_lb, quan_exp).numeric_value(), std::ldexp(builtin_mass_int_lb, builtin_exp) );
    QUAN_CHECK_CLOSE( ldexp(quan_mass_float_lb, quan_exp).numeric_value(),
                       std::ldexp(builtin_mass_float_lb, builtin_exp),
                       FP_MAX_DIFFERENCE );
    check_same_types( ldexp(quan_mass_float_lb, quan_exp).numeric_value(), std::ldexp(builtin_mass_float_lb, builtin_exp) );
    QUAN_CHECK_CLOSE( ldexp(quan_mass_double_lb, quan_exp).numeric_value(),
                       std::ldexp(builtin_mass_double_lb, builtin_exp),
                       FP_MAX_DIFFERENCE );
    check_same_types( ldexp(quan_mass_double_lb, quan_exp).numeric_value(), std::ldexp(builtin_mass_double_lb, builtin_exp) );
    QUAN_CHECK_CLOSE( ldexp(quan_mass_long_double_lb, quan_exp).numeric_value(),
                       std::ldexp(builtin_mass_long_double_lb, builtin_exp),
                       FP_MAX_DIFFERENCE );
    check_same_types( ldexp(quan_mass_long_double_lb, quan_exp).numeric_value(), std::ldexp(builtin_mass_long_double_lb, builtin_exp) );

    QUAN_CHECK_CLOSE( modf(quan_mass_float_kg, &quan_mass_float_kg).numeric_value(),
                       std::modf(builtin_mass_float_kg, &builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_mass_float_kg.numeric_value(), builtin_mass_float_kg,
                       FP_MAX_DIFFERENCE );
    check_same_types( modf(quan_mass_float_kg, &quan_mass_float_kg).numeric_value(), std::modf(builtin_mass_float_kg, &builtin_mass_float_kg) );
    QUAN_CHECK_CLOSE( modf(quan_mass_double_kg, &quan_mass_double_kg).numeric_value(),
                       std::modf(builtin_mass_double_kg, &builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_mass_double_kg.numeric_value(), builtin_mass_double_kg,
                       FP_MAX_DIFFERENCE );
    check_same_types( modf(quan_mass_double_kg, &quan_mass_double_kg).numeric_value(), std::modf(builtin_mass_double_kg, &builtin_mass_double_kg) );
    QUAN_CHECK_CLOSE( modf(quan_mass_long_double_kg, &quan_mass_long_double_kg).numeric_value(),
                       std::modf(builtin_mass_long_double_kg, &builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_mass_long_double_kg.numeric_value(), builtin_mass_long_double_kg,
                       FP_MAX_DIFFERENCE );
    check_same_types( modf(quan_mass_long_double_kg, &quan_mass_long_double_kg).numeric_value(), std::modf(builtin_mass_long_double_kg, &builtin_mass_long_double_kg) );
    QUAN_CHECK_CLOSE( modf(quan_mass_float_lb, &quan_mass_float_lb).numeric_value(),
                       std::modf(builtin_mass_float_lb, &builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_mass_float_lb.numeric_value(), builtin_mass_float_lb,
                       FP_MAX_DIFFERENCE );
    check_same_types( modf(quan_mass_float_lb, &quan_mass_float_lb).numeric_value(), std::modf(builtin_mass_float_lb, &builtin_mass_float_lb) );
    QUAN_CHECK_CLOSE( modf(quan_mass_double_lb, &quan_mass_double_lb).numeric_value(),
                       std::modf(builtin_mass_double_lb, &builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_mass_double_lb.numeric_value(), builtin_mass_double_lb,
                       FP_MAX_DIFFERENCE );
    check_same_types( modf(quan_mass_double_lb, &quan_mass_double_lb).numeric_value(), std::modf(builtin_mass_double_lb, &builtin_mass_double_lb) );
    QUAN_CHECK_CLOSE( modf(quan_mass_long_double_lb, &quan_mass_long_double_lb).numeric_value(),
                       std::modf(builtin_mass_long_double_lb, &builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( quan_mass_long_double_lb.numeric_value(), builtin_mass_long_double_lb,
                       FP_MAX_DIFFERENCE );
    check_same_types( modf(quan_mass_long_double_lb, &quan_mass_long_double_lb).numeric_value(), std::modf(builtin_mass_long_double_lb, &builtin_mass_long_double_lb) );
*/
    QUAN_CHECK_CLOSE( sin(int_mathematic_angle),
                       std::sin(builtin_int_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( sin(int_mathematic_angle), std::sin(builtin_int_angle) );
    QUAN_CHECK_CLOSE( sin(float_mathematic_angle),
                       std::sin(builtin_float_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( sin(float_mathematic_angle), std::sin(builtin_float_angle) );
    QUAN_CHECK_CLOSE( sin(double_mathematic_angle),
                       std::sin(builtin_double_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( sin(double_mathematic_angle), std::sin(builtin_double_angle) );
    QUAN_CHECK_CLOSE( sin(long_double_mathematic_angle),
                       std::sin(builtin_long_double_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( sin(long_double_mathematic_angle), std::sin(builtin_long_double_angle) );

    QUAN_CHECK_CLOSE( tan(int_mathematic_angle),
                       std::tan(builtin_int_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( tan(int_mathematic_angle), std::tan(builtin_int_angle) );
    QUAN_CHECK_CLOSE( tan(float_mathematic_angle),
                       std::tan(builtin_float_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( tan(float_mathematic_angle), std::tan(builtin_float_angle) );
    QUAN_CHECK_CLOSE( tan(double_mathematic_angle),
                       std::tan(builtin_double_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( tan(double_mathematic_angle), std::tan(builtin_double_angle) );
    QUAN_CHECK_CLOSE( tan(long_double_mathematic_angle),
                       std::tan(builtin_long_double_angle),
                       FP_MAX_DIFFERENCE );
    check_same_types( tan(long_double_mathematic_angle), std::tan(builtin_long_double_angle) );

}


