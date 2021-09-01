

/*
http://home.wlu.edu/~levys/kalman_tutorial/
http://www.bzarg.com/p/how-a-kalman-filter-works-in-pictures
http://bilgin.esme.org/BitsBytes/KalmanFilterforDummies.aspx
http://en.wikipedia.org/wiki/Kalman_filter
http://www.cl.cam.ac.uk/~rmf25/papers/Understanding%20the%20Basis%20of%20the%20Kalman%20Filter.pdf

*/

#if __cplusplus < 200000L
#error requires C++20
#endif
#if ! defined __MBED__

#include <quan/fusion/make_matrix.hpp>
#include <quan/fusion/static_value/out/static_value.hpp>

#include <quan/fun/display_matrix.hpp>
#include <quan/fusion/matrix.hpp>
#include <quan/out/time.hpp>
#include <quan/out/length.hpp>
#include <quan/out/reciprocal_length.hpp>
#include <quan/out/reciprocal_time.hpp>
#include <quan/out/acceleration.hpp>
#include <quan/out/velocity.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/three_d/out/vect.hpp>

#include <quan/fixed_quantity/io/input.hpp>
#include <fstream>

namespace {

  QUAN_QUANTITY_LITERAL(time,s)
  QUAN_QUANTITY_LITERAL(length,m)
  QUAN_QUANTITY_LITERAL(velocity,m_per_s)
  QUAN_QUANTITY_LITERAL(reciprocal_length,per_m)
  QUAN_QUANTITY_LITERAL(reciprocal_time,per_ms)
  QUAN_QUANTITY_LITERAL(acceleration,m_per_s2)


  template <typename T,int V>
  constexpr auto static_ = quan::fusion::static_value<T,quan::meta::rational<V> >{};
}

int static_value_test(quan::length::m const & s) 
{

    auto constexpr dt = static_<quan::time::s,1>;
    auto constexpr _0 = static_<int,0>;
    auto constexpr _1 = static_<int,1>;
    auto constexpr _2 = static_<int,2>;

    auto constexpr m1 = quan::fusion::make_matrix<3>
    (
       // s <-         s * 1 +  u * dt  + a *dt^2/2
                          _1 ,      dt  , (dt*dt)/_2,

       // u <- s *      0/dt +  u * 1   +  a * dt
                       _0/dt ,     _1   ,      dt,

       // a <-    s * 0/dt^2 + u * 0/dt +   a * 1
                  _0/(dt*dt) ,    _0/dt ,      _1
    );

    auto constexpr s0 = (_0/dt) * s;
std::cout << "s0 = " << s0 <<'\n';
    auto constexpr s1 = _1 *  static_<quan::velocity::m_per_s,0>;
std::cout << "s1 = " << s1 <<'\n';
    auto constexpr s2 =  dt * static_<quan::acceleration::m_per_s2,0>;
std::cout << "s2 = " << s2 <<'\n';
    auto constexpr sr = s0 + s1 + s2;
std::cout << "sr = " << sr <<'\n';

   // int zz = v0;

    std::cout << "sizeof m1 = " << sizeof(m1) << '\n';

    display(m1, "m1 = ");

    auto const v1 = quan::fusion::make_matrix<3>(
       s,
       static_<quan::velocity::m_per_s,0>,
       static_<quan::acceleration::m_per_s2,0>
    );

    auto const  vr = m1 * v1;


    std::cout << "sizeof vr = " << sizeof(vr) << '\n';
    display(vr, "v2 = ");

   // int dummy = v2;

    return 0;
}

#if defined QUAN_STANDALONE
int main()
{

   quan::length::m x;

   std::ifstream in("input.txt");

   in >> x;

   std::cout << "x = " << x << '\n';
   static_value_test(x);
}
int errors = 0;
#endif

#endif


