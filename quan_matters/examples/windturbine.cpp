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
 2010

/*
    Example works out chord and angle of a wind turbine rotorblade
    as a function of radius,using input parameters in RotorDialog,
    Shows use of pqs in a larger setting
    note: angle result is different from previous versions
    - angle of incidence subtracted
    New...Improved... now with angles...
*/

// see the header for declarations
// see bottom of this file for definitions
#include "windturbine.hpp"

#include <quan_matters/src/constant.cpp>

int main()
{
   for (int i = 0 ; i <= rotordialog.m_num_sections; ++i)
   {
        auto r = rotordialog.get_section_radius(i);
        std::cout << "section " << i << " radius = " << r << '\n';
        auto sect  = rotordialog.getChordOmega(r);
        std::cout << sect << '\n';
    }

}







