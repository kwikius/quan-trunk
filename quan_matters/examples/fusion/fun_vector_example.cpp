
#include <quan/fun/vector.hpp>

#include <quan/fun/for_each.hpp>
#include <quan/fun/output.hpp>

#include <quan/fusion/make_vector.hpp>

#include <string>
#include <iostream>
#include <typeinfo>

int main()
{

    typedef quan::fun::vector<int,long,double,bool> vtype;
    vtype constexpr v1{100,23L,0.765,true};

    quan::fun::for_each(v1,quan::fun::output(std::cout, " "));

    auto constexpr seqL = quan::fun::vector<
            int,int,int,
            int,int,int,
            int,int,int >{1,2,3,4,5,6,7,8,9};

    typedef quan::fun::vector<int,int,int,int,int,int,int,int,int> vect9;
  
    vect9 constexpr v2 = seqL;

    quan::fun::for_each_and_last(v2,quan::fun::output(std::cout, " "),quan::fun::output(std::cout, "\n"));

    double constexpr test_v = 20.543;
    auto  constexpr v3 = quan::fusion::make_vector(1,std::forward<double const>(test_v),3,4);

   // std::cout << typeid(vvv).name() <<'\n';
    std::cout << "[";
    quan::fun::for_each_and_last(v3,quan::fun::output(std::cout, ", "),quan::fun::output(std::cout,"]\n"));

    auto  v4 = quan::fusion::make_vector(5,6,7,8);

    std::cout << "[";
    quan::fun::for_each_and_last(v4,quan::fun::output(std::cout, ", "),quan::fun::output(std::cout,"]\n"));

}

