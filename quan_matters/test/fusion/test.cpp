
#include <quan_matters/test/test.hpp>

void static_value_test();
void static_monoid_test();
void inner_product_test();
void fold_test();
void matrix_test();
void sequence_test();

void adjunct_matrix_test1();
void fusion_inverse_matrix_test1();

int errors = 0;

int main()
{
  std::cout << "fusion test\n";

  static_value_test();
  sequence_test();
  static_monoid_test();
  fold_test();
  inner_product_test();
  matrix_test();
  adjunct_matrix_test1();
  fusion_inverse_matrix_test1();

  QUAN_EPILOGUE
}