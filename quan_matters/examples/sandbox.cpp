
#include <type_traits>
#include <quan/rational.hpp>

#include <iostream>

int main()
{

  std::cout << std::numeric_limits<intmax_t>::digits10 <<'\n';
  static_assert( std::is_same<long int, intmax_t>::value );
  quan::rational<intmax_t> constexpr lhs{   1414213562,1000000000};
 // quan::rational<intmax_t> constexpr lhs{ 17677669500,1250000000};

  auto constexpr r = lhs * lhs;

  auto constexpr n = r.nume();
  auto constexpr d = r.denom();

  std::cout <<  n << '/' << d << '\n';
}