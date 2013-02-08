// Copyright Andrew Little 2005
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    Preliminary tests on three_d vects
*/

#include <quan_matters/test/test.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/length.hpp>

void vect_test1()
{
    typedef quan::three_d::vect<double> vect;
    vect v1(1.,2.,3.);
    QUAN_CHECK(v1.x == 1.);
    QUAN_CHECK(v1.y == 2.);
    QUAN_CHECK(v1.z == 3.);
    vect v2 = v1 * 2;
    QUAN_CHECK(v2.x == 2.);
    QUAN_CHECK(v2.y == 4.);
    QUAN_CHECK(v2.z == 6.);
    vect v3 = v1 + v2;
    QUAN_CHECK(v3.x == 3.);
    QUAN_CHECK(v3.y == 6.);
    QUAN_CHECK(v3.z == 9.);
    vect v4 = v1 - v2;
    QUAN_CHECK(v4.x == -1.);
    QUAN_CHECK(v4.y == -2.);
    QUAN_CHECK(v4.z == -3.);
    
    typedef quan::three_d::vect<int> vect1;

    vect1 v5(1,2,3);
    vect  v6 = v5 + v1;
    QUAN_CHECK(v6.x == 2.);
    QUAN_CHECK(v6.y == 4.);
    QUAN_CHECK(v6.z == 6.); 
}

void vect_t1_quantity_test1()
{
    typedef quan::length::mm len;
    typedef quan::three_d::vect<len> vect;
    vect v1(len(1.),len(2.),len(3.));
    QUAN_CHECK(v1.x.numeric_value() == 1.);
    QUAN_CHECK(v1.y.numeric_value() == 2.);
    QUAN_CHECK(v1.z.numeric_value() == 3.);
    vect v2 =v1 * 2.;
    QUAN_CHECK(v2.x.numeric_value() == 2.);
    QUAN_CHECK(v2.y.numeric_value() == 4.);
    QUAN_CHECK(v2.z.numeric_value() == 6.);
    vect v3 = v1 + v2;
    QUAN_CHECK(v3.x.numeric_value() == 3.);
    QUAN_CHECK(v3.y.numeric_value() == 6.);
    QUAN_CHECK(v3.z.numeric_value() == 9.);
    vect v4 = v1 - v2;
    QUAN_CHECK(v4.x.numeric_value() == -1.);
    QUAN_CHECK(v4.y.numeric_value() == -2.);
    QUAN_CHECK(v4.z.numeric_value() == -3.);
    
    typedef quan::length_<int>::mm len1;
    typedef quan::three_d::vect<
        len1
    > vect1;

    vect1 v5(len1(1),len1(2),len1(3));
    vect  v6 = v5 + v1;
    QUAN_CHECK(v6.x.numeric_value() == 2.);
    QUAN_CHECK(v6.y.numeric_value() == 4.);
    QUAN_CHECK(v6.z.numeric_value() == 6.); 
}

#if 0
int errors = 0;
int main()
{
   vect_test1();
   vect_t1_quantity_test1();
   EPILOGUE
}
#endif