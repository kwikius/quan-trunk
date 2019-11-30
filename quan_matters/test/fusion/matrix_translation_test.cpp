
#include <quan_matters/test/test.hpp>
#include <quan/fusion/make_translation_matrix.hpp>
#include <quan/fusion/make_row_matrix.hpp>
#include <quan/fusion/make_column_matrix.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/fun/display_matrix.hpp>
#include <quan/out/length.hpp>
#include <quan/three_d/out/vect.hpp>
#include <quan/fusion/static_value/out/static_value.hpp>

namespace {

   QUAN_QUANTITY_LITERAL(length,mm)

   typedef quan::length::mm mm;
   typedef quan::three_d::vect<mm> vect;
}

void matrix_translation_test()
{
   auto constexpr v1 = quan::fusion::make_row_matrix(vect{1_mm,2_mm,3_mm});

   display(v1,"v1 = ");

   auto constexpr v2 = quan::fusion::make_translation_matrix(vect{10_mm,20_mm,30_mm});

   display(v2,"v2 = ");

   auto result = v1 * v2 ;

   display(result, "result = ");
   
}

#if 0
int main()
{
   matrix_translation_test();
}
#endif

