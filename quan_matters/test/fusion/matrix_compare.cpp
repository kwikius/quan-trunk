
#include <quan_matters/test/test.hpp>
#include <quan/fusion/matrix.hpp>

namespace {

   void fusion_compare_equal_seq()
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

      auto constexpr m3 = quan::fusion::make_matrix<4>
      (
         1,2,3,4,
         1,2,3,4,
         1,2,3,4,
         1,2,3,4
      );

      QUAN_CHECK(m1 == m1)
      QUAN_CHECK(!(m1 == m2))
      QUAN_CHECK(m1 == m3)
      QUAN_CHECK(!(m2 == m3))
   }

   void fusion_compare_not_equal_seq()
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

      auto constexpr m3 = quan::fusion::make_matrix<4>
      (
         1,2,3,4,
         1,2,3,4,
         1,2,3,4,
         1,2,3,4
      );

      QUAN_CHECK( (m1 != m1) == false)
      QUAN_CHECK(m1 != m2)
      QUAN_CHECK(m2 != m3)
      QUAN_CHECK((m1 != m3) == false)
   }

   void binary_op_test()
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
      typedef decltype(m1) m1_type;
      typedef decltype(m2) m2_type;
      typedef  quan::meta::binary_op<m1_type, quan::meta::equal_to,m2_type>::type result_type1;

      //TODO n.b not always TODO static value case
    //  QUAN_CHECK( (std::is_same<result_type1,bool>::value) )

       QUAN_CHECK( !(std::is_same<result_type1,quan::undefined>::value) )

      typedef  quan::meta::binary_op<m1_type, quan::meta::not_equal_to,m2_type>::type result_type2;

      QUAN_CHECK( !(std::is_same<result_type2,quan::undefined>::value) )

      //TODO n.b not always TODO static value case
     // QUAN_CHECK( (std::is_same<result_type2,bool>::value) )
   }

}

void fusion_compare_seq()
{
   std::cout << "fusion compare matrix test\n";
#if defined __cpp_concepts
   std::cout << "using c++ concepts\n";
#endif
  fusion_compare_equal_seq();
  fusion_compare_not_equal_seq();
  binary_op_test();
}

#if defined CODEBLOCKS_STANDALONE
int errors = 0;
int main()
{

   fusion_compare_seq();
   QUAN_EPILOGUE
}
#endif

