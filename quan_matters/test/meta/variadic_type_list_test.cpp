


#include <typeinfo>
#include <type_traits>

#include <quan/meta/type_sequence.hpp>

#include <iostream>
int main()
{
   using quan::meta::type_sequence; 
   using quan::meta::push_back;
   using quan::meta::push_front;
   using quan::meta::pop_front;
   using quan::meta::pop_back;
   using quan::meta::front;
   using quan::meta::back;
   using quan::meta::at;
   using quan::meta::get_num_elements;

   typedef type_sequence<> t1;

    typedef push_back<t1,int>::type t2;
    
    typedef push_back<t2,double>::type t3;

    std::cout << typeid(t3).name() <<'\n';

    std::cout <<  get_num_elements<t3>::value <<'\n';
   
    typedef pop_front<t3>::type t4;

    static_assert (std::is_same<t4,type_sequence<double> >::value, "error 1");

   typedef push_front<t4,int>::type t5;

     static_assert (std::is_same<t5,t3 >::value, "error 2");

    typedef push_front<t1,bool>::type t6;

    static_assert(std::is_same<front<t3>::type,int>::value,"error 3");

    static_assert(std::is_same<back<t3>::type,double>::value,"error 3");

    static_assert(std::is_same<front<t6>::type,bool>::value,"error 4");

     static_assert(std::is_same<back<t6>::type,bool>::value,"error 4");

    static_assert(std::is_same<back<t6>::type,bool>::value,"error 4");

   static_assert(std::is_same<pop_back<t3>::type, t2>::value, "error");

   static_assert(std::is_same<at<0,t2>::type,int>::value, "error");

}