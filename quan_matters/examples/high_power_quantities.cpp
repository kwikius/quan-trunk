#include <quan/out/length.hpp>
#include <quan/out/area.hpp>
#include <quan/out/volume.hpp>

/*
   high powers
*/

int main()
{
   auto constexpr x = quan::length::ft_us{1};

   std::cout << x << '\n';
   auto v1 = x * x;
   std::cout << v1 << '\n'; // nearest si

   auto v2 = x * x * x;
   std::cout << v2 << '\n';

   auto v3 = x * x * x * x;
   std::cout << v3 << '\n';

   auto v4 = quan::pow<2>(x);
   std::cout << v4 << '\n';

   auto v5 = quan::pow<3>(x);
   std::cout << v5 << '\n';

   auto v6 = quan::pow<4>(x);
   std::cout << v6 << '\n';
   auto v7 = quan::pow<10>(x);
   std::cout << v7 << '\n';

   auto v8  = x * x * x * x * x * x * x * x * x * x * x * x * x;
   std::cout << v8 << '\n';

   auto v9 = quan::pow<201>(x);
   std::cout << v9 << '\n';

   auto v10 = quan::pow<1,5>(v9);
   std::cout << v10 << '\n';

   auto v11 = quan::pow<1,201>(v9);

   std::cout << v11 << '\n';

   quan::length::ft_us x1 = v11;
  
   std::cout << x1 <<'\n';

}