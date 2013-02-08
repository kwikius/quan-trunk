// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    exception on out of range 
*/

#include <quan/out/length.hpp>

int main()
{
 
    try {
        quan::length_<double>::m L1( INT_MAX);
        quan::length_<int>::m L2 = L1;

        std::cout << "conversion 1 succeeded\n";

        quan::length_<double>::m L3( static_cast<double>(INT_MAX)+1 );
        quan::length_<int>::m L4 = L3;

        std::cout << "conversion 2 succeeded\n";
    }
    catch ( std::exception & e){
        std::cout << "conversion failed with " << e.what() <<'\n';
    }

}

