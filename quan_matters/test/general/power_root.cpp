


#include <quan_matters/test/test.hpp>
#include <quan/math/root.hpp>

#include <iostream>
#include <iomanip>

template <int N, typename Float>
void show_root(Float const & v)
{
  std::cout << "value = " << v << '\n';
  Float  result = quan::root<N>(v);

  Float result1 = std::pow(v,static_cast<float>(1)/N);

  QUAN_CHECK( result1 == result1);
  std::cout << "diy     " << v << "^1/" << N << " = " << std::setprecision(20) << result << '\n';
  std::cout << "inbuilt " << v << "^1/" << N << " = " << std::setprecision(20) << result1 << "\n\n";

}

void root_test()
{
   show_root<2>(2.f);
   show_root<2>(2.0);

   show_root<4>(7.f);
   show_root<4>(7.0);
   show_root<3>(1000.0);
   show_root<3>(1000.f);

   show_root<2>(1'000'000.0);

}


