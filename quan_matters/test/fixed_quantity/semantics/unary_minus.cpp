// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/resistance.hpp>
#include <quan/magnetic_permeability.hpp>

/*
    test unary_minus for t1_quantity
*/


void unary_minus_test()
{
   quan::resistance::MR R1(4.7);
   quan::resistance::MR R2 = -R1;
   QUAN_CHECK_EQUAL(R1.numeric_value(), -R2.numeric_value());
   quan::magnetic_permeability_<int>::mH_per_m mp1(987.51);
   quan::magnetic_permeability::mH_per_m mp2 = -mp1;
   QUAN_CHECK(mp1.numeric_value() == -mp2.numeric_value());
   QUAN_CHECK(mp2.numeric_value() == -988);
}
