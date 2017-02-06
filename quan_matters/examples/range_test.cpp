/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
*/

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

        std::cout << "Expect to throw an exception here...\n";
        quan::length_<int>::m L4 = L3;

        std::cout << "(!!!Unexpected!!!) conversion 2 succeeded \n";
    }
    catch ( std::exception & e){
        std::cout << "OK (expected) out of range conversion failed with \"" << e.what() << "\"\n";
    }

}

