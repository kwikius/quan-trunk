/*
Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses.
*/

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
