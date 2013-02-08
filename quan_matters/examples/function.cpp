
/*
 quan::function demo
 common interface to  object with members or free function
 differs from std::function as std::function takes the object in its arg
 whereas quan version is constructed with a ref
 however refs can be dangerous if objectgoes out of scope
 but means that function call sig is consistent
*/


#include <quan/function.hpp>
#include <iostream>

void freefun()
{
  std::cout << "freefun()\n";
}

struct my{
  my(std::string const & str): m_str(str){}
  void operator()(){ std::cout << m_str << ".operator()\n"; }
  void fun1(){ std::cout << m_str <<  ".fun1()\n"; }
  std::string m_str;
};

int main()
{

  auto pm = new my{"my fun"};

  quan::function<void(void)> f1(pm,&my::operator());
  quan::function<void(void)> f2(pm,&my::fun1);
  quan::function<void(void)> f3(fun1);

  f1();
  f2();
  f3();

}
