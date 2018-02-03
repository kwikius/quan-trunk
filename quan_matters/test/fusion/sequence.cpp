
#include <quan/concepts/fusion/sequence.hpp>
#include <quan/fun/vector.hpp>
#include <quan/fun/at.hpp>
#include <quan/fusion/make_vector.hpp>

#include <quan_matters/test/test.hpp>

#if ( __cplusplus < 201402L )
#error requires C++14 or greater
#endif

namespace {

   void sequence_fun_vector_test()
   {
      auto seqL = quan::fun::vector<
            int,int,int,int,
            int,int,int,int,
            int,int,int,int,
            int,int,int,int >{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

      auto constexpr seqR = quan::fun::vector<
            int,int,int,int,
            int,int,int,int,
            int,int,int,int,
            int,int,int,double >{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

      typedef quan::fun::at_seq<0,decltype(seqR),quan::fun::as_ref>::type ref_type;
      static_assert(std::is_reference<ref_type>::value,"error");
   #if defined __cpp_concepts 
      QUAN_CHECK(quan::fusion::Sequence<decltype(seqL)>);
      QUAN_CHECK(quan::fusion::Sequence<decltype(seqR)>);
    #else
      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seqL)>::value);
      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seqR)>::value);
   #endif

      QUAN_CHECK(quan::fusion::num_elements<decltype(seqL)> == 16);
      QUAN_CHECK(quan::fusion::num_elements<decltype(seqR)> == 16);

      QUAN_CHECK( ( std::is_same<quan::fusion::sequence_at_t<0,decltype(seqL)>,int>::value ) );
      QUAN_CHECK( ( std::is_same<quan::fusion::sequence_at_t<15,decltype(seqL)>,int>::value ) );

      QUAN_CHECK(quan::fun::at<2>(seqL) == 3);
      quan::fun::at<2>(seqL) = 1;
      QUAN_CHECK(quan::fun::at<2>(seqL) == 1);
   }

   void sequence_variadic_tpl_vector_test()
   {
     
   }
}

void sequence_test()
{
   sequence_fun_vector_test();
   sequence_variadic_tpl_vector_test();
}

