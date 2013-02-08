
// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/out/length.hpp>
    
/*
    get conversion factor from one dimensionally-equivalent 
    type to another
*/

namespace quan{

    template <
        typename Target,
        typename Source
    >
    typename quan::meta::arithmetic_promote<
        typename Target::value_type,
        typename Source::value_type
    >::type
    conversion_factor()
    {
        Source s(1);
        Target t = s;
        return t.numeric_value();
    }

    
}//quan

int main()
{
    quan::length::m plankA(2);
    quan::length::mm plankB(1000);
    std::cout << "ratio  plankA / plankB = " << plankA / plankB << '\n'; 

    std::cout << "conversion-factor\n";
    std::cout << quan::conversion_factor<
        quan::length::mm,quan::length::m
    >() << '\n';
}
