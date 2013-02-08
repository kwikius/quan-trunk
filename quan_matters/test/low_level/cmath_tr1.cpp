// Copyright T. Zach Laine 2006

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    test quan cmath overload functionality
    none implemented .. commented out
*/

#define FP_MAX_DIFFERENCE 1e-6

#include <quan_matters/test/test.hpp>
#include <quan/cmath.hpp>
#include <quan/mass.hpp>
#include <quan/meta/rational.hpp>

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

/*
    QUAN_CHECK_CLOSE( fpclassify(quan_mass_int_kg),
                       std::fpclassify(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( fpclassify(quan_mass_float_kg),
                       std::fpclassify(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( fpclassify(quan_mass_double_kg),
                       std::fpclassify(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( fpclassify(quan_mass_long_double_kg),
                       std::fpclassify(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( fpclassify(quan_mass_int_lb),
                       std::fpclassify(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( fpclassify(quan_mass_float_lb),
                       std::fpclassify(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( fpclassify(quan_mass_double_lb),
                       std::fpclassify(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( fpclassify(quan_mass_long_double_lb),
                       std::fpclassify(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );

    QUAN_CHECK_CLOSE( isfinite(quan_mass_int_kg),
                       std::isfinite(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isfinite(quan_mass_float_kg),
                       std::isfinite(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isfinite(quan_mass_double_kg),
                       std::isfinite(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isfinite(quan_mass_long_double_kg),
                       std::isfinite(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isfinite(quan_mass_int_lb),
                       std::isfinite(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isfinite(quan_mass_float_lb),
                       std::isfinite(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isfinite(quan_mass_double_lb),
                       std::isfinite(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isfinite(quan_mass_long_double_lb),
                       std::isfinite(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );

    QUAN_CHECK_CLOSE( isinf(quan_mass_int_kg),
                       std::isinf(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isinf(quan_mass_float_kg),
                       std::isinf(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isinf(quan_mass_double_kg),
                       std::isinf(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isinf(quan_mass_long_double_kg),
                       std::isinf(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isinf(quan_mass_int_lb),
                       std::isinf(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isinf(quan_mass_float_lb),
                       std::isinf(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isinf(quan_mass_double_lb),
                       std::isinf(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isinf(quan_mass_long_double_lb),
                       std::isinf(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );

    QUAN_CHECK_CLOSE( isnan(quan_mass_int_kg),
                       std::isnan(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnan(quan_mass_float_kg),
                       std::isnan(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnan(quan_mass_double_kg),
                       std::isnan(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnan(quan_mass_long_double_kg),
                       std::isnan(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnan(quan_mass_int_lb),
                       std::isnan(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnan(quan_mass_float_lb),
                       std::isnan(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnan(quan_mass_double_lb),
                       std::isnan(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnan(quan_mass_long_double_lb),
                       std::isnan(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );

    QUAN_CHECK_CLOSE( isnormal(quan_mass_int_kg),
                       std::isnormal(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnormal(quan_mass_float_kg),
                       std::isnormal(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnormal(quan_mass_double_kg),
                       std::isnormal(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnormal(quan_mass_long_double_kg),
                       std::isnormal(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnormal(quan_mass_int_lb),
                       std::isnormal(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnormal(quan_mass_float_lb),
                       std::isnormal(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnormal(quan_mass_double_lb),
                       std::isnormal(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( isnormal(quan_mass_long_double_lb),
                       std::isnormal(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );

    QUAN_CHECK_CLOSE( signbit(quan_mass_int_kg),
                       std::signbit(builtin_mass_int_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( signbit(quan_mass_float_kg),
                       std::signbit(builtin_mass_float_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( signbit(quan_mass_double_kg),
                       std::signbit(builtin_mass_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( signbit(quan_mass_long_double_kg),
                       std::signbit(builtin_mass_long_double_kg),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( signbit(quan_mass_int_lb),
                       std::signbit(builtin_mass_int_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( signbit(quan_mass_float_lb),
                       std::signbit(builtin_mass_float_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( signbit(quan_mass_double_lb),
                       std::signbit(builtin_mass_double_lb),
                       FP_MAX_DIFFERENCE );
    QUAN_CHECK_CLOSE( signbit(quan_mass_long_double_lb),
                       std::signbit(builtin_mass_long_double_lb),
                       FP_MAX_DIFFERENCE );
*/
}
