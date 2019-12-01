
#include <quan_matters/test/test.hpp>

#include <quan/fusion/matrix.hpp>

#include <quan/fun/compare_seq_ops.hpp>


void fusion_compare_seq()
{
    auto constexpr m1 = quan::fusion::make_matrix<4>
      (
         1.0 ,2.0 ,3.0 ,4.0 ,
         1.0 ,2.0 ,3.0 ,4.0 ,
         1.0 ,2.0 ,3.0 ,4.0 ,
         1.0 ,2.0 ,3.0 ,4.0
      );

      auto constexpr m2 = quan::fusion::make_matrix<4>
      (
         1,0,0,0,
         0,1,0,0,
         0,0,1,0,
         0,0,0,2
      );

      auto constexpr result = m1 * m2;
      typedef quan::meta::strip_cr<decltype(result)>::type result_type;

      auto const res_view = quan::fusion::make_multiplies_view(m1,m2);

      typedef quan::meta::strip_cr<decltype(res_view)>::type res_view_type;

      typedef quan::fun::as_value_matrix<res_view_type>::type alt_result_type;

      QUAN_CHECK( (std::is_same<result_type,alt_result_type>::value) );

      typedef quan::fun::matrix_as_sequence<res_view_type> mat_as_seq1;

      mat_as_seq1 s1{res_view};

      typedef quan::fun::matrix_as_sequence<result_type> mat_as_seq2;
      mat_as_seq2 s2{result};

   
      QUAN_CHECK(s1 == s2);
      QUAN_CHECK(s2 == s1);
      QUAN_CHECK(s1 == s1);

      QUAN_CHECK( (s1 == quan::fusion::as_sequence(result)) )
      QUAN_CHECK( ( quan::fusion::as_sequence(result) != quan::fusion::as_sequence(m1) ) )


}