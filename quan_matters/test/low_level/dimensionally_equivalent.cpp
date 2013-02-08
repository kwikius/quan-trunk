
// Copyright Andrew Little 2006

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/velocity.hpp>

#if 1

void dimensionally_equivalent_test();
int errors =0;
int main()
{
   dimensionally_equivalent_test();
   EPILOGUE
}
#endif

void dimensionally_equivalent_test()
{
    typedef quan::meta::binary_op<
        quan::length::m,
        quan::meta::divides,
        quan::time::s
    >::type vely1;
    bool val1 = quan::meta::dimensionally_equivalent<
        vely1,
        quan::velocity::m_per_s
    >::value;
    QUAN_CHECK(val1);

    bool val2 = quan::meta::dimensionally_equivalent<
        vely1::unit,
        quan::velocity::m_per_s::unit
    >::value;
    QUAN_CHECK(val2);

   
  
    bool val4 = quan::meta::dimensionally_equivalent<
        quan::length::m,
        quan::velocity::m_per_s
    >::value;
    QUAN_CHECK(val4 == false);

    bool val5 = quan::meta::dimensionally_equivalent<
        quan::length::m::unit,
        quan::velocity::m_per_s::unit
    >::value;
    QUAN_CHECK(val5 ==false);
}

