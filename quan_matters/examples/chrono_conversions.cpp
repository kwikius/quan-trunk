
#include <quan/conversion/chrono.hpp>
#include <quan/out/time.hpp>
#include <iostream>

int main()
{
   std::chrono::duration<double,std::milli> v{20};

   quan::time::ms  ms = quan::from_chrono(v);

   std::cout << ms << '\n';

   v = quan::to_chrono(ms);

   std::cout << v.count() << " ms" <<'\n';
}


