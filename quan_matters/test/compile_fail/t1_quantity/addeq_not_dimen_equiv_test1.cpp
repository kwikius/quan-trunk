// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/velocity.hpp>

/*
    should fail to compile
*/

int main()
{
    quan::velocity::m_per_s      v(1);
    v += 20;
}
