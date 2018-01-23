
#include <quan_matters/test/test.hpp>

#if defined __cpp_concepts

#include <quan/meta/type_sequence.hpp>
#include <quan/concepts/meta/type_sequence/for_each.hpp>
//#include <quan/archetypes/any_type.hpp>
//#include <quan/undefined.hpp>
//#include <quan/concepts/any_type.hpp>

#include <quan/out/length.hpp>

#include <iostream>
#include <typeinfo>
#include <string>

/*
    for some types check that the correct function is called with correct type
    quan::meta::for_each works on types
    quan::meta::for_each does a runtime call but returns void
    
*/

namespace my{

   template <typename T>
   std::string name();

   template<> std::string name<int>() { return "int";}
   template<> std::string name<bool>() { return "bool";}
   template<> std::string name<double>() { return "double";}

   template<> std::string name<quan::length::mm>()  { return "quan::length::mm";}

   std::string type_name;
   std::string call_name;

   //not a functor
   struct output_apply{

      template <typename T>
      static void apply()
      {
         type_name += name<T>() + " ";
         call_name += "apply<T>() ";
      }
   };

   // functor with 1 runtime arg
    struct output_1_rt_arg{

      template <typename T>
      void operator() (T const & t )const
      {
         type_name += name<T>() + " ";
         call_name += "operator()(T t) ";
      }
   };
   
    // functor with type but no rt arg
    struct output_T_no_rt_arg{

      template <typename T>
      void operator() () const
      {
         type_name += name<T>() + " ";
         call_name += "operator()<T>() ";
      }
   };
}

// in this class overload the static member functions
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

// in this class specialise the class for each type of function
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

template <typename F> struct test_type2;

template <typename F>
requires requires ( void (F::* p)() const)
{ 
   { p = &F:: template operator() <quan::AnyType_> };
}
struct test_type2<F> {

   static void fun()
   {

      F{}. template operator()<quan::length::mm>();
   }
};

template <typename F>
requires requires ( void (F::* p)(quan::AnyType_ const &) const )
{ 
   {p = &F::operator()};
} 
struct test_type2<F> {

   static void fun()
   {
      F{}(quan::length::mm{});
   }

};

template <typename T,typename F>
requires requires ( void (F::* p)() const)
{ 
   { p = &F:: template operator() <T> };
}
struct test_type1<T,F> {

   static void fun()
   {
      F f;
      f. template operator()<T>();
   }
};

template <typename T,typename F>
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

template <typename F>
requires requires (  void (* p )( ) )
{ 
   p = &F:: template apply<auto> ;
}
struct test_type2<F> {

   static void fun()
   {
      F:: template apply<int>();
   }
};

namespace {

   void clear_names()
   {
      my::call_name = "";
      my::type_name = "";
   }
}
int errors = 0;
int main()
{
   test_type::fun<my::output_apply,int>();
   QUAN_CHECK( (my::call_name == "apply<T>() ") && ( my::type_name == "int "))
   clear_names();

   test_type1<quan::length::mm,my::output_1_rt_arg>::fun();
   QUAN_CHECK( (my::call_name == "operator()(T t) ") && ( my::type_name == "quan::length::mm " ))
   clear_names();
//
   test_type::fun<int>(my::output_1_rt_arg{});
   QUAN_CHECK( (my::call_name == "operator()(T t) ") && ( my::type_name == "int "))
   clear_names();

   test_type1<int,my::output_apply>::fun();
   QUAN_CHECK( (my::call_name == "apply<T>() ") && ( my::type_name == "int "))
   clear_names();
//
   test_type::fun<quan::length::mm >(my::output_1_rt_arg{});
   QUAN_CHECK( (my::call_name == "operator()(T t) ") && ( my::type_name == "quan::length::mm " ))
   clear_names();

   test_type::fun<my::output_T_no_rt_arg,int>();
   QUAN_CHECK( (my::call_name == "operator()<T>() ") && ( my::type_name == "int " ))
   clear_names();

   test_type1<int,my::output_T_no_rt_arg>::fun();
   QUAN_CHECK( (my::call_name == "operator()<T>() ") && ( my::type_name == "int " ))
   clear_names();

   test_type2<my::output_T_no_rt_arg>::fun();
   QUAN_CHECK( (my::call_name == "operator()<T>() ") && ( my::type_name == "quan::length::mm " ))
   clear_names();
  // std::cout << "|" << my::call_name << "| \n";

   test_type2<my::output_1_rt_arg>::fun();
   QUAN_CHECK( (my::call_name == "operator()(T t) ") && ( my::type_name == "quan::length::mm " ))
   clear_names();

   test_type2<my::output_apply>::fun();
   QUAN_CHECK( (my::call_name == "apply<T>() ") && ( my::type_name == "int " ))
   clear_names();

   typedef quan::meta::type_sequence<int, quan::length::mm,bool> types;

   // these dont change
   std::string const result_type_names = "int quan::length::mm bool ";

   std::string result_call_names = "operator()<T>() operator()<T>() operator()<T>() ";
   quan::meta::for_each<types,my::output_T_no_rt_arg>{}();
   QUAN_CHECK( (my::call_name == result_call_names ) && ( my::type_name == result_type_names))
   clear_names();

   result_call_names = "operator()(T t) operator()(T t) operator()(T t) ";
   quan::meta::for_each<types,my::output_1_rt_arg>{}();
   QUAN_CHECK( (my::call_name == result_call_names ) && ( my::type_name == result_type_names))
   clear_names();

   result_call_names = "apply<T>() apply<T>() apply<T>() ";
   quan::meta::for_each<types,my::output_apply>{}();
   QUAN_CHECK( (my::call_name == result_call_names ) && ( my::type_name == result_type_names))
   clear_names();


   QUAN_EPILOGUE

}
#else // __cpp_concepts

int errors = 0;
int main()
{
   std::cout << "concepts for_each not tested without concepts support\n";
  
}

#endif
