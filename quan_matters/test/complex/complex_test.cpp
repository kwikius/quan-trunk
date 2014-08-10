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

//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <quan_matters/test/simple_test.hpp>
#include <quan/out/length.hpp>
#include <quan/complex/complex.hpp>
#include <complex>
/*
    tests on quan complex
*/

int main()
{
  
    quan::complex<double> q_cpl(2, 7);
    std::complex<double> s_cpl(2,7);
    q_cpl *= q_cpl;
    s_cpl *= s_cpl;

    QUAN_CHECK_EQUAL(q_cpl.real(),s_cpl.real());
    QUAN_CHECK_EQUAL(q_cpl.imag(),s_cpl.imag());

    quan::complex<double> q_cpl1(.5, -90);
    std::complex<double> s_cpl1(.5,-90);
    q_cpl1 *= q_cpl1;
    s_cpl1 *= s_cpl1;

    QUAN_CHECK_EQUAL(q_cpl1.real(),s_cpl1.real());
    QUAN_CHECK_EQUAL(q_cpl1.imag(),s_cpl1.imag());


    EPILOGUE
}

