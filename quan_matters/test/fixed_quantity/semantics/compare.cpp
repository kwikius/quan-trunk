// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/pressure.hpp>
#include <quan/torque.hpp>
#include <quan/resistance.hpp>
#include <quan/length.hpp>

namespace {
void inbuilt_compare_test();
void compare_test1();
}

void compare_test()
{
   inbuilt_compare_test();
   compare_test1();

}

namespace {
void compare_test1()
{
    quan::pressure::Pa a,b(1.9999999);
    a = b;
    quan::pressure::Pa c = a;
    QUAN_CHECK( a == b && b == c);

    QUAN_CHECK(compare( a, b, quan::pressure::Pa(1e-6) ) == 0);
    QUAN_CHECK(compare(-a, -b, -quan::pressure::Pa(1e-6) ) == 0);
    QUAN_CHECK(compare( a, b, -quan::pressure::Pa(1e-6) ) == 0);

    QUAN_CHECK(compare(-a, -b, quan::pressure::Pa(1e-6) ) == 0);
    QUAN_CHECK(compare(a, a  ) == 0);

    QUAN_CHECK( a.numeric_value() == b.numeric_value()  
    &&  b.numeric_value() == c.numeric_value() );
    quan::pressure::mbar d(1000);
    quan::pressure::bar e(1);
    QUAN_CHECK(d == e);
    double ratio = d / e;
    QUAN_CHECK(ratio == 1.);
    QUAN_CHECK(d - e == quan::pressure::bar() );
    QUAN_CHECK(e - d == quan::pressure::mbar() );
    QUAN_CHECK( ( compare( d, e, quan::pressure::mbar(1e-6) ) == 0 ) );
    QUAN_CHECK( ( compare(-d, -e, -quan::pressure::mbar(1e-6) ) == 0 ) );
    QUAN_CHECK( ( compare( d, e, -quan::pressure::mbar(1e-6) ) == 0 ) );
    QUAN_CHECK( ( compare(-d, -e, quan::pressure::mbar(1e-6) ) == 0 ) );

    quan::pressure::bar neg_e = -e;
    QUAN_CHECK( neg_e == +neg_e);
    QUAN_CHECK( neg_e == -e);
    QUAN_CHECK( e + neg_e == quan::pressure::bar() );
    QUAN_CHECK( neg_e + e == quan::pressure::mbar() );
    QUAN_CHECK( d + neg_e == quan::pressure::mbar() );
    QUAN_CHECK( neg_e + d == quan::pressure::bar() );
    d *= 2;
    ratio = e/d;
    QUAN_CHECK(ratio == 0.5);
    e/=2.;
    ratio = d/e;
    QUAN_CHECK(ratio == 4.);

    quan::torque::mN_m torque(1);
    QUAN_CHECK(torque++ == quan::torque::mN_m(1.) );
    QUAN_CHECK(torque == quan::torque::mN_m(2.) );
    QUAN_CHECK(++torque == quan::torque::mN_m(3.) );
    QUAN_CHECK(torque-- == quan::torque::mN_m(3.));
    QUAN_CHECK(torque == quan::torque::mN_m(2.));
    QUAN_CHECK(--torque == quan::torque::mN_m(1.));

    quan::resistance::kR  same(2.5);
    quan::resistance::kR  same1 = same;
    quan::resistance::kR  same2 = same;
    QUAN_CHECK( same == same);
    QUAN_CHECK( same1 == same);
    QUAN_CHECK( same == same1);
    QUAN_CHECK( same2 == same);
    QUAN_CHECK( same == same2);
    quan::resistance::kR smaller(2.4);
    QUAN_CHECK(smaller < same);

    // check sign of epsilon doesnt matter
    QUAN_CHECK(  compare(smaller,same,quan::resistance::kR(.01) ) < 0 );  
    QUAN_CHECK(  compare(-smaller,-same,quan::resistance::kR(.01) )  > 0 );
    QUAN_CHECK(  compare(smaller,same,-quan::resistance::kR(.01)) < 0 ); 
    QUAN_CHECK(  compare(-smaller,-same,-quan::resistance::kR(.01)) > 0 );
    QUAN_CHECK(  compare(same,smaller,quan::resistance::kR(.01)) > 0 );
    QUAN_CHECK(  compare(same,smaller,-quan::resistance::kR(.01)) > 0  ); 
    QUAN_CHECK(  compare(-same,-smaller,quan::resistance::kR(.01)) < 0 );
    QUAN_CHECK(  compare(-same,-smaller,-quan::resistance::kR(.01)) < 0 );

    QUAN_CHECK(smaller <= same);
    QUAN_CHECK(smaller != same);
    QUAN_CHECK(same != smaller);
    QUAN_CHECK(same > smaller);
    QUAN_CHECK(same >= smaller);

    quan::resistance::R  samex(2500);
    QUAN_CHECK( samex == same);
    QUAN_CHECK( same == samex);

    quan::resistance::R smallerx(2400);

    QUAN_CHECK(smallerx < same);
    QUAN_CHECK(smallerx <= same);
    QUAN_CHECK(smallerx != same);
    QUAN_CHECK(same != smallerx);
    QUAN_CHECK(same > smallerx);
    QUAN_CHECK(same >= smallerx);

    quan::length::in L1(36);
    quan::length::ft L2(3);
    QUAN_CHECK(compare(L1,L2,quan::length::in(1e-9)) == 0);
        
    quan::length::yd L3 = L2;
    QUAN_CHECK(compare(L3,L2, quan::length::ft(1e-6)) == 0);

    quan::length::mi L4(1);
    QUAN_CHECK(compare(L4,L2 * 1760, quan::length::yd(1e-6)) == 0);
}

void inbuilt_compare_test()
{
    int a1 = 1;
    double b1 = 1.00001;
    float c1 = 0.001F;
    QUAN_CHECK((quan::compare(a1,b1,c1)==0));
    QUAN_CHECK((quan::compare(a1,b1) < 0));
    QUAN_CHECK((quan::compare(b1,a1) > 0));
    QUAN_CHECK((quan::compare(a1,a1)== 0));
    QUAN_CHECK((quan::compare(a1,b1,-c1)== 0));
    QUAN_CHECK((quan::compare(c1,b1,a1) == 0));
    QUAN_CHECK((quan::compare(b1,c1,a1)==0));

    QUAN_CHECK((quan::compare(1.,1.3,.2) < 0));
    QUAN_CHECK((quan::compare(1.3,1.,.2) > 0));
    QUAN_CHECK((quan::compare(1.,1.3,.4) == 0));
    QUAN_CHECK((quan::compare(1,1.) == 0));
}

}//namespace


