

#include <quan_matters/test/simple_test.hpp>
#include <quan/conversion/itoa.hpp>
#include <quan/meta/integer_max.hpp>

#include <quan/conversion/float_to_ascii.hpp>

int main()
{
    // max length of buffer?
    char buf [100] ;
    memset(buf,0,100);

    QUAN_CHECK(quan::float_to_ascii<1>(0.1,buf) == 3);
    QUAN_CHECK(strcmp(buf,"0.1") == 0); 

    QUAN_CHECK(quan::float_to_ascii<2>(0.01,buf) == 4);
    QUAN_CHECK(strcmp(buf,"0.01") == 0);
    QUAN_CHECK(quan::float_to_ascii<1>(1.0,buf) == 3);
    QUAN_CHECK(strcmp(buf,"1.0") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(0.9,buf) == 3);
    QUAN_CHECK(strcmp(buf,"0.9") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(0.05,buf) == 3);
    QUAN_CHECK(strcmp(buf,"0.1") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(0.04,buf) == 3);
    QUAN_CHECK(strcmp(buf,"0.0") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(0.8,buf) == 3);
    QUAN_CHECK(strcmp(buf,"0.8") == 0);

    QUAN_CHECK(quan::float_to_ascii<2>(0.8,buf) == 4);
    QUAN_CHECK(strcmp(buf,"0.80") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(0.99,buf) == 3);
    QUAN_CHECK(strcmp(buf,"1.0") == 0);

    QUAN_CHECK(quan::float_to_ascii<2>(1.0,buf) == 4);
    QUAN_CHECK(strcmp(buf,"1.00") == 0);

    QUAN_CHECK(quan::float_to_ascii<6>(1.0,buf) == 8);
    QUAN_CHECK(strcmp(buf,"1.000000") == 0);

    QUAN_CHECK(quan::float_to_ascii<6>(66.000005,buf) == 9);
    QUAN_CHECK(strcmp(buf,"66.000005") == 0);

    QUAN_CHECK(quan::float_to_ascii<2>(12345.67,buf) == 8);
    QUAN_CHECK(strcmp(buf,"12345.67") == 0);

    QUAN_CHECK(quan::float_to_ascii<2>(0.0001,buf) == 4);
    QUAN_CHECK(strcmp(buf,"0.00") == 0);

    QUAN_CHECK(quan::float_to_ascii<6>(0.0001,buf) == 8);
    QUAN_CHECK(strcmp(buf,"0.000100") == 0);

    QUAN_CHECK(quan::float_to_ascii<6>(189765432.543215,buf) == 16);
    QUAN_CHECK(strcmp(buf,"189765432.543215") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(5.09,buf) == 3);
    QUAN_CHECK(strcmp(buf,"5.1") == 0);

    QUAN_CHECK(quan::float_to_ascii<2>(5.009,buf) == 4);
    QUAN_CHECK(strcmp(buf,"5.01") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(5.01,buf) == 3);
    QUAN_CHECK(strcmp(buf,"5.0") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(5.11,buf) == 3);
    QUAN_CHECK(strcmp(buf,"5.1") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(5.0,buf) == 3);
    QUAN_CHECK(strcmp(buf,"5.0") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(4.99,buf) == 3);
    QUAN_CHECK(strcmp(buf,"5.0") == 0);

    QUAN_CHECK(quan::float_to_ascii<1>(5.01,buf) == 3);
    QUAN_CHECK(strcmp(buf,"5.0") == 0);

    QUAN_CHECK(quan::float_to_ascii<2>(5.5,buf) == 4);
    QUAN_CHECK(strcmp(buf,"5.50") == 0);

    QUAN_CHECK(quan::float_to_ascii<3>(5.5555,buf) == 5);
    QUAN_CHECK(strcmp(buf,"5.556") == 0);

    QUAN_CHECK(quan::float_to_ascii<2>(5.55,buf) == 4);
    QUAN_CHECK(strcmp(buf,"5.55") == 0);

    QUAN_CHECK(quan::float_to_ascii<4>(1.00014,buf) == 6);
    QUAN_CHECK(strcmp(buf,"1.0001") == 0);

    QUAN_CHECK(quan::float_to_ascii<4>(1.00015,buf) == 6);
    QUAN_CHECK(strcmp(buf,"1.0002") == 0);

    EPILOGUE;
}

int errors = 0;
