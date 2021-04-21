
/*
requires C++20
*/

struct my_rat{
  constexpr my_rat( int n , int d) : num{n},den{d} {}
  int num;
  int den;
};

struct my_exp10{
  constexpr my_exp10( int n , int d) : num{n},den{d} {}
  int num;
  int den;
};

struct my_cf{
   constexpr my_cf( my_rat m, my_exp10 e) : mux{m},exp(e){}
   my_rat mux;
   my_exp10 exp;
};

constexpr my_cf operator*( my_rat m, my_exp10 e)
{
   return my_cf(m,e);
}

#include <iostream>

template<my_cf cf>
void print()
{
   std::cout << "[" << cf.mux.num << "/" << cf.mux.den << "] * 10^(" << cf.exp.num << "/" << cf.exp.den << ")";
}

int main()
{
   print<my_cf(my_rat(1,2),my_exp10(2,3))>();
   print<my_rat(1,3) * my_exp10(3,4)>();
}

