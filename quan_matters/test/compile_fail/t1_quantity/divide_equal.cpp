// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/area.hpp>

/*
    Should fail to compile
*/
int main()
{
    quan::area::ft2 A(1);
    A /= quan::area::ft2(1); 
}
