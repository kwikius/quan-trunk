
#include <quan/meta/rational.hpp>
#include <quan/meta/type_sequence.hpp>
#include <quan/meta/count_if.hpp>
#include <quan/meta/find_if.hpp>
#include <quan/meta/transform.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <type_traits>

#include <quan_matters/test/simple_test.hpp>
#include <quan/meta/is_same.hpp>

#include <iostream>

// Only useful with concepts
#if defined __cpp_concepts
namespace {

   template <typename T> struct is_dimension : std::false_type{};

   template <quan::meta::Rational ... R> 
   struct is_dimension<quan::meta::type_sequence<R...> > : std::true_type{};

   template <typename T>
   concept bool Dimension = is_dimension<T>::value;


   template <Dimension D> struct is_dimensionless 
   :quan::meta::not_<
      quan::meta::find_if<
         D,quan::meta::neq_zero<quan::meta::fun> 
      > 
   >{};

}
#endif

int errors = 0;

struct my_type;

int main(){

   using quan::meta::rational;

   typedef rational<1> length;
   typedef rational<-1> time;
   typedef rational<0> mass;

   typedef quan::meta::type_sequence<length,time,mass> velocity;

   typedef quan::meta::type_sequence<int,float,double,long,my_type> other;

   static_assert(quan::meta::find_if<other,quan::meta::is_same<int> >::value == true,"error");
   static_assert(quan::meta::find_if<other,quan::meta::is_same<float> >::value == true,"error");
   static_assert(quan::meta::find_if<other,quan::meta::is_same<double> >::value == true,"error");
   static_assert(quan::meta::find_if<other,quan::meta::is_same<long> >::value == true,"error");
   static_assert(quan::meta::find_if<other,quan::meta::is_same<my_type> >::value == true,"error");
   static_assert(quan::meta::find_if<other,quan::meta::is_same<my_type*> >::value == false,"error");
   static_assert(quan::meta::find_if<other,quan::meta::is_same<bool> >::value == false,"error");
   static_assert(quan::meta::find_if<other,quan::meta::is_same<char> >::value == false,"error");

#if defined __cpp_concepts
   static_assert(is_dimension<velocity>::value ==true,"error");

   static_assert( is_dimension<other>::value == false,"error");

   typedef quan::meta::type_sequence<rational<0>,rational<0>,rational<0> > dimless;

   static_assert(is_dimensionless<dimless>::value == true,"error");

   static_assert(is_dimensionless<velocity>::value == false,"error");
#endif
   QUAN_EPILOGUE
     
}







