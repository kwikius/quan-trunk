// Copyright Andrew Little 2006

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/mass.hpp>

void default_assignment_test()
{
   quan::mass::lb mass1;
   quan::mass::lb mass2(100.5);
   mass1 = mass2;

   QUAN_CHECK(mass1.numeric_value() == mass2.numeric_value());

}