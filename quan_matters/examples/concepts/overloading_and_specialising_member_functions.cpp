
#if defined __cpp_concepts

#include <quan/meta/type_sequence.hpp>
#include <quan/concepts/meta/type_sequence/for_each.hpp>
#include <quan/archetypes/any_type.hpp>

#include <quan/out/length.hpp>

#include <iostream>
#include <typeinfo>

/*
  demo of quan::meta::for_each with the two types of functor it can use
  The first version doesnt need to instantiate the type

  Functor is an object defines operator()  ...
*/

namespace my{

   // .. so this is not a functor
   struct output_apply{

      template <typename T>
      static void apply()
      {
#if ! defined QUAN_NO_RTTI
         std::cout << "apply[" << typeid(T).name() << "] ";
#endif
      }
   };

    struct output_1_rt_arg{

      template <typename T>
      void operator() (T const & t )const
      {
         std::cout << "1 rt arg[" << t << "] ";
      }
   };
   
    struct output_T_no_rt_arg{

      template <typename T>
      void operator() () const
      {
         std::cout << "template no rt arg[" << T{} << "] ";
      }
   };
}

struct test_type {

   template <typename T,typename F>
   requires requires ( void (F::* p)(T const &) const )
   { 
      {p =  &F::operator()};
   } 
   static void fun( F f)
   {
      f(T{});
   }

   template <typename F,typename T >
   requires requires ( void (F::* p)() const)
   { 
      { p = &F:: template operator() <T> };
   }
   static void fun()
   {
      F f;
      f. template operator()<T>();
   }

   template <typename F,typename T >
   requires requires (  void (* p )( ) )
   { 
      p = &F:: template apply<T> ;
   }
   static void fun()
   {
      F:: template apply<T>();
   }
};

template <typename T,typename F> struct test_type1;

template <typename T,typename F>
requires requires ( void (F::* p)(T const &) const )
{ 
   {p = &F::operator()};
} 
struct test_type1<T,F> {

   static void fun()
   {
      F{}(T{});
   }

};


template <typename T,typename F>
requires requires ( void (F::* p)() const)
{ 
   { p = &F:: template operator() <T> };
}
struct test_type1<T,F> {

//  // template <typename F,typename T >
//   requires requires ( void (F::* p)() const)
//   { 
//      { p = &F:: template operator() <T> };
//   }
   static void fun()
   {
      F f;
      f. template operator()<T>();
   }
};

template <typename T,typename F>
// template <typename F,typename T >
requires requires (  void (* p )( ) )
{ 
   p = &F:: template apply<T> ;
}
struct test_type1<T,F> {

   static void fun()
   {
      F:: template apply<T>();
   }
};



int main()
{
   test_type::fun<my::output_apply,int>();

   test_type1<int,my::output_1_rt_arg>::fun();
//
   test_type::fun<int>(my::output_1_rt_arg{});

   test_type1<int,my::output_apply>::fun();
//
   test_type::fun<double>(my::output_1_rt_arg{});

   test_type::fun<my::output_T_no_rt_arg,int>();

   test_type1<int,my::output_T_no_rt_arg>::fun();

   std::cout << "\n--------------\n\n";
 //  typedef quan::meta::type_sequence<int, quan::length::m,bool> types;

   std::cout << "v1 output ...\n";

  // quan::meta::for_each<types,my::output_apply>{}();

   std::cout << "\n\nv2 output ...\n";

  // quan::meta::for_each<types,my::output_v2>{}();

   std::cout << "done\n";

}
#endif
