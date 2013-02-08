

// Copyright Andrew Little 2005-2006
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    Check that following define (in <quan/config.hpp>
    prevents cross unit conversions
*/

#define QUAN_DISALLOW_IMPLICIT_UNIT_CONVERSIONS
#include <quan/length.hpp>

int main()
{
    quan::length::m L1(1);
    quan::length::m L2 = L1;
// ###########Should fail here ###########
    quan::length::mm L3 = L2;
// ###########Should fail here ###########

}

