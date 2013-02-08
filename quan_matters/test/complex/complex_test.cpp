// Copyright Andrew Little 2006
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

    BOOST_CHECK_EQUAL(q_cpl.real(),s_cpl.real());
    BOOST_CHECK_EQUAL(q_cpl.imag(),s_cpl.imag());

    quan::complex<double> q_cpl1(.5, -90);
    std::complex<double> s_cpl1(.5,-90);
    q_cpl1 *= q_cpl1;
    s_cpl1 *= s_cpl1;

    BOOST_CHECK_EQUAL(q_cpl1.real(),s_cpl1.real());
    BOOST_CHECK_EQUAL(q_cpl1.imag(),s_cpl1.imag());


    EPILOGUE
}

