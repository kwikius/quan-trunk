
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_compare()
  {
    ll_bigint v1 = 1;
    ll_bigint v2 = 2;

    QUAN_CHECK( v1.compare(v2) == -1 );
    QUAN_CHECK( v2.compare(v1) == 1  );
    QUAN_CHECK( v1.compare(v1) == 0  );
    v1 = -100 ;
    QUAN_CHECK( v1.compare(v2) == -1 );
    QUAN_CHECK( v2.compare(v1) == 1  );
    QUAN_CHECK( v1.compare(v1) == 0  );
  }

}}

