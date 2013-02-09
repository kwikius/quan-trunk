// Copyright Andrew Little 2006
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
     emulate SIunits syntax in Quan
*/

#include <quan/out/length.hpp>
#include <quan/out/time.hpp>
#include <quan/out/velocity.hpp>

namespace SIunits{

    quan::length::m meter()
    {
        return quan::length::m(1);
    }
    quan::length::m millimeter()
    {
        return quan::length::mm(1);
    }
    quan::time::s second()
    {
        return quan::time::s(1);
    }

    quan::time::s minute()
    {
        return quan::time::min(1);
    }

    typedef quan::length::m length;
    typedef quan::time::s time;
    typedef quan::velocity::m_per_s velocity;
}

int main()
{
    SIunits::velocity x1 = 10 * SIunits::millimeter() / SIunits::second();

    SIunits::velocity x2 = SIunits::length(10) / SIunits::time(1);

    SIunits::time t = SIunits::minute();

    std::cout << x1 <<'\n';
    std::cout << x2 <<'\n';
    std::cout << t <<'\n';
    
}



