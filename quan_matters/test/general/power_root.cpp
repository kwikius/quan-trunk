

#include <quan/math/root.hpp>

#include <iostream>
#include <iomanip>

template <int N, typename Float>
void show_root(Float const & v)
{
  Float  result = quan::root<N>(v);
  std::cout << v << "^1/" << N << " = " << std::setprecision(20) << result << '\n';
  std::cout << "check " << v << " == " << quan::to_power<N>(result)  <<'\n';
}

int main()
{

   show_root<2>(2.f);
   show_root<2>(2.0);

   show_root<4>(7.f);
   show_root<4>(7.0);
   show_root<3>(1000.0);
   show_root<3>(1000.f);

}
