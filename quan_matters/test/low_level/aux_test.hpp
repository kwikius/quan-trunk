#ifndef QUAN_MATTERS_TEST_LOW_LEVEL_AUX_TEST_HPP_INCLUDED
#define QUAN_MATTERS_TEST_LOW_LEVEL_AUX_TEST_HPP_INCLUDED

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.


#ifndef FP_MAX_DIFFERENCE
#define FP_MAX_DIFFERENCE 1e-12
#endif


#include <quan/meta/conversion_factor.hpp>
#include <quan/meta/si_units.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/eq.hpp>
#include <type_traits>

#define CHECK_RAT(Rational, n, d) \
    QUAN_CHECK( static_cast<int>(Rational ::numerator) == n );\
    QUAN_CHECK( static_cast<int>(Rational ::denominator) == d );

#define CHECK_INT(Integral,T, v)\
    QUAN_CHECK(  (Integral ::type::value) == v);\
    QUAN_CHECK( (std::is_same< Integral  ::value_type, T >::value) );

#define CHECK_QUANTITY_UNIT(Name,E,M,I) \
    QUAN_CHECK( (quan::meta::eq_< \
        Name ::exponent::type ,\
        quan::meta::rational< E > \
    >::value));\
    QUAN_CHECK( (quan::meta::eq_< \
        Name  ::multiplier::type , \
        quan::meta::rational< M > \
    >::type::value));\
    QUAN_CHECK( (quan::meta::eq_<\
        Name  ::id::type , \
       quan::meta::int32< I >\
    >::type::value));

#define CHECK_SI_QUANTITY_UNIT( Prefix , E ) \
 CHECK_QUANTITY_UNIT( Prefix, E , 1, 0)


#endif // QUAN_MATTERS_TEST_LOW_LEVEL_AUX_TEST_HPP_INCLUDED
