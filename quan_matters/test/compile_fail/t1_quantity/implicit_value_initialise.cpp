// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/time.hpp>

/*
    check implicit init from value_type syntax fails
*/
/*
    Should fail to compile
*/

int main()
{
    quan::time::ms t1 = 1;
}
