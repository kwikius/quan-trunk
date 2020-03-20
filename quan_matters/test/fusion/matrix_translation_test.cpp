
#include <quan_matters/test/test.hpp>
#include <quan/fusion/make_translation_matrix.hpp>
#include <quan/fusion/make_row_matrix.hpp>
#include <quan/fusion/make_column_matrix.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/fun/display_matrix.hpp>
#include <quan/out/length.hpp>
#include <quan/three_d/out/vect.hpp>
#include <quan/fusion/static_value/out/static_value.hpp>

#include <quan/fusion/compare_matrix.hpp>

namespace {

   QUAN_QUANTITY_LITERAL(length,mm)

   typedef quan::length::mm mm;
   typedef quan::three_d::vect<mm> vect;
}

void matrix_translation_test()
{
   auto constexpr v1 = quan::fusion::make_row_matrix(vect{mm{1},mm{2},mm{3}});
   QUAN_CHECK(quan::fusion::num_rows<decltype(v1)> == 1);
   QUAN_CHECK(quan::fusion::num_columns<decltype(v1)> == 4);

   display(v1,"v1 = ");

   auto constexpr v2 = quan::fusion::make_translation_matrix(vect{mm{10},mm{20},mm{30}});
   QUAN_CHECK(quan::fusion::num_rows<decltype(v2)> == 4);
   QUAN_CHECK(quan::fusion::num_columns<decltype(v2)> == 4);

   display(v2,"v2 = ");

   auto result = v1 * v2 ;

   display(result, "result = ");

   auto result_comp = quan::fusion::make_row_matrix(
      vect{mm{11},mm{22},mm{33}}
   );

   display(result_comp, "result_comp = ");
   
   QUAN_CHECK( (quan::are_models_of<quan::fusion::Matrix_,decltype(result),decltype(result_comp)>::value) )
   QUAN_CHECK( (quan::fusion::num_rows<decltype(result)>  == quan::fusion::num_rows<decltype(result_comp)>) )
   QUAN_CHECK( (quan::fusion::num_columns<decltype(result)>  == quan::fusion::num_columns<decltype(result_comp)>) )

   QUAN_CHECK( result == result_comp )

   QUAN_CHECK( !(quan::fun::are_fun_sequences<decltype(result),decltype(result_comp)>::value))
   auto lseq = quan::fusion::as_sequence(result);
   auto rseq = quan::fusion::as_sequence(result_comp);

   QUAN_CHECK( (quan::fun::are_fun_sequences<decltype(lseq),decltype(rseq)>::value))

   typedef quan::fun::inner_product_seq::result<
         decltype(lseq),
         decltype(rseq),
         quan::operator_logical_and, quan::operator_equal_to
      >::type result_type;

  // std::cout << typeid(result_type).name() <<'\n';
   
   auto res = lseq == rseq;
   QUAN_CHECK(res);
}

#if defined CODEBLOCKS_STANDALONE
int errors = 0;
int main()
{
   matrix_translation_test();
   QUAN_EPILOGUE
}
#endif

