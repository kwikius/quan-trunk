
// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <quan_matters/test/test.hpp>

#include <quan/out/length.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/complex/complex.hpp>
#include <complex>
/*
    tests on quan complex
*/

namespace {
   QUAN_QUANTITY_LITERAL(length,mm);
}

void complex_test1()
{
    quan::complex<double> q_cpl(2, 7);
    std::complex<double> s_cpl(2,7);
    q_cpl *= q_cpl;
    s_cpl *= s_cpl;

    QUAN_CHECK(q_cpl.real() == s_cpl.real());
    QUAN_CHECK(q_cpl.imag() == s_cpl.imag());

    quan::complex<double> q_cpl1(.5, -90);
    std::complex<double> s_cpl1(.5,-90);
    q_cpl1 *= q_cpl1;
    s_cpl1 *= s_cpl1;

    QUAN_CHECK(q_cpl1.real() == s_cpl1.real());
    QUAN_CHECK(q_cpl1.imag() == s_cpl1.imag());
}


void complex_test2()
{
    typedef quan::length::mm mm;
    quan::complex<mm> q_cpl{2_mm, 7_mm};
    quan::complex<double> s_cpl(2,7);
    q_cpl *= s_cpl;
    s_cpl *= s_cpl;

    QUAN_CHECK(q_cpl.real().numeric_value() == s_cpl.real());
    QUAN_CHECK(q_cpl.imag().numeric_value() == s_cpl.imag());

    quan::complex<double> q_cpl1(.5, -90);
    quan::complex<double> s_cpl1(.5,-90);
    q_cpl1 *= s_cpl1;
    s_cpl1 *= s_cpl1;

    QUAN_CHECK(q_cpl1.real() == s_cpl1.real());
    QUAN_CHECK(q_cpl1.imag() == s_cpl1.imag());
}
#if 0
int errors = 0;

int main()
{
   complex_test1();
   complex_test2();

    EPILOGUE
}
#endif
