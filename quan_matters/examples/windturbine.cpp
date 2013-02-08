// Copyright Andrew Little 1961 2010

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







