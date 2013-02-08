
#include "bigint_test.hpp"

void quan::test::bigint_compare_test()
{
  std::cout << "bigint compare test\n";
  quan::bigint v1 = 1;
  quan::bigint v2 = 2;

  QUAN_CHECK (v1 < v2)
  QUAN_CHECK (!(v1 < v1))
  QUAN_CHECK (v1 <= v2)
  QUAN_CHECK (v2 <= v2)
  QUAN_CHECK (! (v2 <= v1))
  QUAN_CHECK (v2 > v1)
  QUAN_CHECK (! (v1 > v2))
  QUAN_CHECK (v2 >= v1)
  QUAN_CHECK (v1 >= v1)
  QUAN_CHECK ( v1 != v2);
  QUAN_CHECK( v2 != v1);
  QUAN_CHECK ( (v1 == v1))
  QUAN_CHECK (! (v1 == v2))
  QUAN_CHECK (! (v2 == v1))
}
