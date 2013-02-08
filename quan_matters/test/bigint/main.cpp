#include "ll_bigint_test.hpp"
#include "bigint_test.hpp"
#include <quan_matters/test/big_rational/big_rational_test1.hpp>

#if( QUAN_VERSION == 1)
int errors =0;
#else
int quan::test::errors =0;
#endif

int main()
{
  // quan::test::ll_bigint_test();
   quan::test::test_ctor();
   quan::test::test_assign();
   quan::test::bigint_plus_eq_test();
   quan::test::bigint_plus_test();
   quan::test::bigint_minus_eq_test();
   quan::test::bigint_mul_eq_test();
   quan::test::bigint_div_eq_test();
   quan::test::bigint_shl_test();
   quan::test::bigint_shr_test();
   quan::test::bigint_or_test();
   quan::test::bigint_and_test();
   quan::test::bigint_xor_test();
   quan::test::bigint_compare_test();
   quan::test::bigint_test1();

   QUAN_EPILOGUE
}
