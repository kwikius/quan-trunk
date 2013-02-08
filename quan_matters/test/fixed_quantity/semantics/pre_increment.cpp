// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/resistance.hpp>
#include <quan/force.hpp>

/*
    test pre_increment for t1_quantity
*/

void pre_increment_test()
{
   quan::resistance::MR R1(4.7);
   quan::resistance::MR Rold = R1;
   QUAN_CHECK_EQUAL( Rold.numeric_value(),R1.numeric_value());

   quan::resistance::MR R2 = ++R1;
   QUAN_CHECK_EQUAL(R2.numeric_value(), R1.numeric_value() );
   QUAN_CHECK_EQUAL(R1.numeric_value(),Rold.numeric_value() + 1);

   quan::force::kip F1(987.51);
   quan::force::kip Fold = F1;
   quan::force::kip F2 = ++F1;
   QUAN_CHECK(F2.numeric_value() == F1.numeric_value() );
   QUAN_CHECK(F1.numeric_value() == Fold.numeric_value() + 1 );
   QUAN_CHECK(F2.numeric_value() == QUAN_FLOAT_TYPE(988.51));
}

