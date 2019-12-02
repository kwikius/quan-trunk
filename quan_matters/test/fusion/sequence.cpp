
#include <quan/concepts/fusion/sequence.hpp>
#include <quan/fun/vector.hpp>
#include <quan/fun/at.hpp>
#include <quan/fusion/make_vector.hpp>
#include <quan/are_models_of.hpp>
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

      QUAN_CHECK( (quan::is_model_of<quan::fusion::Sequence_,decltype(seqL)>::value) );
      QUAN_CHECK( (quan::is_model_of<quan::fusion::Sequence_,decltype(seqR)>::value) );
      QUAN_CHECK( (quan::are_models_of<quan::fusion::Sequence_,decltype(seqR),decltype(seqL)>::value) );
   #endif

      QUAN_CHECK(quan::fusion::num_elements<decltype(seqL)> == 16);
      QUAN_CHECK(quan::fusion::num_elements<decltype(seqR)> == 16);

      QUAN_CHECK( ( std::is_same<quan::fusion::sequence_at_t<0,decltype(seqL)>,int>::value ) );
      QUAN_CHECK( ( std::is_same<quan::fusion::sequence_at_t<15,decltype(seqL)>,int>::value ) );

      QUAN_CHECK(quan::fun::at<2>(seqL) == 3);
      quan::fun::at<2>(seqL) = 1;
      QUAN_CHECK(quan::fun::at<2>(seqL) == 1);

      auto new_seq = seqL;

      new_seq = seqL;

      new_seq = quan::fun::vector<
            int,int,int,int,
            int,int,int,int,
            int,int,int,int,
            int,int,int,int >{-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16};
   }

   void sequence_variadic_tpl_vector_test()
   {
     
   }

   void sequence_array_test()
   {
      int ar[] = {1,2,3,4};

      typedef quan::fun::at_seq<0,int(&)[4],quan::fun::as_value> at_seq;
      QUAN_CHECK( quan::fun::is_fun_sequence<decltype(ar)>::value)
      QUAN_CHECK((at_seq{}(ar) == 1))
      QUAN_CHECK(( quan::fun::size_seq<decltype(ar)>::value == 4))
   }
} //namespace

void sequence_test()
{
   sequence_fun_vector_test();
   sequence_variadic_tpl_vector_test();
   sequence_array_test();
}

