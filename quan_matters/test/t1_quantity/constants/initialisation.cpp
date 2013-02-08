// Copyright Andrew Little 2006

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    Check constants initialisation.
    The standard allows dedefinition of templated static members in headers
    but this doesnt work for all compilers.
    Check on problems with defining the constant in Headers.
    Whether constants are defined in headers or not
    is controlled by  <quan/config.hpp> macro
    QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
*/

#include <quan_matters/test/test.hpp>
#include <quan/constants/gravitational_constant.hpp>
#include <quan/out/length.hpp>
#include <quan/out/force.hpp>
#include <quan/out/mass.hpp>

#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
#include <quan_matters/src/gravitational_constant.cpp>
#endif


#if 1
void constant_init_test();
int main()
{
 constant_init_test();
 EPILOGUE
}

struct config{
    static  quan::gravitational_constant::G_type const G;
};
    const  quan::gravitational_constant::G_type
    config::G = quan::gravitational_constant::G ;

void constant_init_test()
{
       // find absolute distance between particles
    quan::length::m length(2);
    quan::mass::kg m1(100);
    quan::mass::kg m2(120);
    quan::force::N f =config::G * m1 * m2/(length * length);

    QUAN_FLOAT_TYPE val1 = f.numeric_value();
    QUAN_FLOAT_TYPE val2 = 6.6726e-11 * 100. * 120. / (2. * 2.);
    QUAN_CHECK_CLOSE(val1,val2, 1e-12);
}


