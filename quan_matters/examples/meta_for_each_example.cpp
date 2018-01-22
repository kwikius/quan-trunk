

#include <quan/meta/type_sequence.hpp>
#include <quan/concepts/meta/type_sequence/for_each.hpp>

#include <quan/out/length.hpp>

#include <iostream>
#include <typeinfo>

/*
  demo of quan::meta::for_each with the two types of functor it can use
  The first version doesnt need to instantiate the type
*/

namespace my{

   struct output_v1{

      template <typename T>
      void operator()() const
      {
         std::cout << "v1[" << typeid(T).name() << "] ";
      }
   };

}
// foreach requires to be a model of 
namespace quan{ namespace impl{
   

  template<>  struct is_model_of_impl<
      quan::meta::PolymorphicFunctor<1,0>,
      my::output_v1
   > : quan::meta::true_{};

}}

namespace my{

    struct output_v2{

      template <typename T>
      void operator()(T const & t ) const
      {
         std::cout << "v2[" << t << "] ";
      }
   };
}
// foreach requires a model of ..
namespace quan{ namespace impl{

  template<>  struct is_model_of_impl<
      quan::meta::PolymorphicFunctor<1,1>,
      my::output_v2
   > : quan::meta::true_{};

}} // quan::impl


int main()
{
   typedef quan::meta::type_sequence<int, quan::length::m,bool> types;

   std::cout << "v1 output ...\n";

   quan::meta::for_each<types,my::output_v1>{}();

   std::cout << "\n\nv2 output ...\n";

   quan::meta::for_each<types,my::output_v2>{}();

   std::cout << "done\n";

}
