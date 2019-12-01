
#include <quan_matters/test/test.hpp>
#include <quan/fusion/make_translation_matrix.hpp>
#include <quan/fusion/make_row_matrix.hpp>
#include <quan/fusion/make_column_matrix.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/fun/display_matrix.hpp>
#include <quan/out/length.hpp>
#include <quan/three_d/out/vect.hpp>
#include <quan/fusion/static_value/out/static_value.hpp>

void matrix_as_sequence_test()
{
   auto constexpr m2 = quan::fusion::make_matrix<4>
   (
      1,0,0,0,
      0,1,0,0,
      0,0,1,0,
      0,0,0,2
   );

   typedef quan::fun::matrix_as_sequence<decltype(m2)> mat_as_seq1;

   QUAN_CHECK(quan::fun::is_fun_sequence<mat_as_seq1>::value )
   QUAN_CHECK(quan::fun::is_fun_matrix<mat_as_seq1>::value == false)

   auto res = m2 == m2;
   QUAN_CHECK(res)

}

#if defined CODEBLOCKS_STANDALONE
int errors = 0;
int main()
{
   matrix_as_sequence_test();
   QUAN_EPILOGUE
}
#endif