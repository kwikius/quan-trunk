#include <quan/meta/fold.hpp>
#include <quan_matters/test/test.hpp>

#include <quan/meta/rational.hpp>
#include <quan/meta/type_sequence.hpp>
#include <quan/operators/binary_operator_functors.hpp>

#include <quan/fusion/meta_rational_to_runtime.hpp>

#include <quan/fusion/static_value/static_value.hpp>

#include <quan/fusion/static_value/static_bool.hpp>
#include <quan/fusion/static_monoid.hpp>
#include <quan/length.hpp>

namespace {
   using quan::meta::rational;

   template <int N, int D = 1>
   using static_mm = quan::fusion::static_value<quan::length::mm, quan::meta::rational<N,D> >;

   template <int N, int D = 1>
   using static_double = quan::fusion::static_value<double, quan::meta::rational<N,D> >;
}

int errors = 0;
int main()
{
   typedef rational<0> zero;
   typedef rational<1,2> half;
   typedef rational<1> one;
   typedef rational<2> two;
   typedef quan::fusion::static_bool<true> true_;
   typedef quan::fusion::static_bool<false> false_;

   typedef quan::meta::type_sequence<zero,one,two,one,two,half> seq;

   typedef quan::meta::fold<seq,zero,quan::operator_plus>::type result_type;

   QUAN_CHECK (quan::meta::is_rational<result_type>::value)

   QUAN_CHECK( quan::fusion::to_runtime{}(result_type{}) == 6.5)

// test runtime types also
   typedef quan::meta::type_sequence<int,float,long,double> seq1;

   typedef quan::meta::fold<seq1,int,quan::operator_plus>::type result_type1;

   QUAN_CHECK( (std::is_same<result_type1,double>::value) );

   typedef quan::meta::type_sequence<true_,false_,false_>  seq2;


   typedef quan::meta::fold<
       seq2,
       quan::fusion::static_monoid<quan::operator_logical_or,false_>::type,
       quan::operator_logical_or
   >::type result_type2;

   QUAN_CHECK( (std::is_same<result_type2,true_>::value))
   QUAN_CHECK( quan::fusion::to_runtime{}(result_type2{}) == true)

      typedef quan::meta::fold<
       seq2,
       quan::fusion::static_monoid<quan::operator_logical_and,true_>::type,
       quan::operator_logical_and
   >::type result_type3;

   QUAN_CHECK( (std::is_same<result_type3,false_>::value))
   QUAN_CHECK( quan::fusion::to_runtime{}(result_type3{}) == false)

   typedef quan::meta::type_sequence<
         static_double<1>
         ,static_double<2>
         ,static_double<3> 
         ,static_double<1,5>
   > seq4;
      
   typedef quan::meta::fold<
      seq4,
      static_mm<1>,
      quan::operator_times
   >::type result_type4;

   QUAN_CHECK( (std::is_same<result_type4,static_mm<6,5> >::value))
   QUAN_CHECK( quan::fusion::to_runtime{}(result_type4{}) == quan::length::mm{6.0/5})

   QUAN_EPILOGUE
   
}