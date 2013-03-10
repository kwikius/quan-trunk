// Copyright Andrew Little 2005
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    tests of quan::meta::rational_c
*/

#include <quan_matters/test/test.hpp>
#include <quan/meta/rational.hpp>
#include <type_traits>

#if 1
void rational_test();
int errors =0;
int main()
{
   rational_test();
   EPILOGUE
}
#endif

void rational_test()
{
    QUAN_CHECK(((std::numeric_limits<int64_t>::max)() >= 0x7FFFFFFF) );
    typedef quan::meta::rational<2,4> smaller;
    const static bool equal1 = std::is_same<
        smaller::type,quan::meta::rational<1,2> 
    >::value;
    QUAN_CHECK(equal1);
    const static bool equal1a = std::is_same<
        smaller::type,quan::meta::rational<1,2> 
    >::value;
    QUAN_CHECK(equal1a);
    const static bool equal2 = std::is_same<
        smaller::type, quan::meta::rational<-10000,-20000>::type
    >::value;
    QUAN_CHECK(equal2);
    const static bool equal2a = std::is_same<
        smaller::type, quan::meta::rational<1,2> 
    >::value;
    QUAN_CHECK(equal2a);
    
    QUAN_CHECK(smaller::numerator == 1); 
    QUAN_CHECK(quan::meta::numerator<smaller>::value ==1); 
    QUAN_CHECK(smaller::denominator == 2);
    QUAN_CHECK(quan::meta::denominator<smaller>::value == 2);
    typedef quan::meta::rational<3,4> bigger;

    const static bool less = quan::meta::lt_<
        smaller, bigger>::value;
    QUAN_CHECK(less);
    const static bool less_equal = quan::meta::lte_<
        smaller,  bigger>::value;
    QUAN_CHECK(less_equal);
    const static bool equal3 = std::is_same<
        smaller::type, bigger::type>::value;
    QUAN_CHECK(!equal3);
    const static bool not_equal_to = quan::meta::neq_<
        smaller,  bigger>::value;
    QUAN_CHECK(not_equal_to);
    const static bool greater_equal = quan::meta::gte_<
        smaller, bigger>::value;
    QUAN_CHECK(!greater_equal);
    const static bool greater = quan::meta::gt_<
        smaller, bigger>::value;
    QUAN_CHECK(!greater);
    
    typedef quan::meta::rational<14,-16> negative;
    
    QUAN_CHECK(negative::numerator == -7);
    QUAN_CHECK(negative::denominator == 8); 
    typedef quan::meta::binary_op<
        smaller,quan::meta::plus,bigger
    >::type sum;
    QUAN_CHECK(sum::numerator == 5);
    QUAN_CHECK(sum::denominator == 4);
    typedef quan::meta::binary_op<
        smaller,quan::meta::minus,bigger
    >::type difference;
    QUAN_CHECK(difference::numerator == -1);
    QUAN_CHECK(difference::denominator == 4);
    typedef quan::meta::binary_op<
        smaller,quan::meta::times,bigger
    >::type prod;
    QUAN_CHECK(prod::numerator == 3);
    QUAN_CHECK(prod::denominator == 8);
    typedef quan::meta::binary_op<
        smaller,quan::meta::divides,bigger
    >::type div;
    QUAN_CHECK(div::numerator == 2);
    QUAN_CHECK(div::denominator== 3);
    // check reduction
    typedef quan::meta::binary_op<
        quan::meta::rational<1,2>,quan::meta::plus,quan::meta::rational<1,2>
    >::type  reduced_result;
    QUAN_CHECK(reduced_result::numerator == 1);
    QUAN_CHECK(reduced_result::denominator == 1);

    typedef quan::meta::unary_operation<
        quan::meta::negate,
        prod
    >::type negated_prod;
    QUAN_CHECK(negated_prod::numerator == -3);
    QUAN_CHECK(negated_prod::denominator == 8);
    typedef quan::meta::unary_operation<
        quan::meta::reciprocal,
        negated_prod
    >::type reciprocal_n_prod;
    QUAN_CHECK(reciprocal_n_prod::numerator == -8);
    QUAN_CHECK(reciprocal_n_prod::denominator == 3);
}

