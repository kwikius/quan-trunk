

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
#include <quan/fusion/static_value.hpp>

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

int kalman1() 
{
    quan::three_d::vect<quan::length::m>  constexpr             s{1.0_m,1.0_m,1.0_m};
    quan::three_d::vect<quan::velocity::m_per_s> constexpr      u{0.0_m_per_s,0_m_per_s,0_m_per_s};
    quan::three_d::vect<quan::acceleration::m_per_s2> constexpr a{0.0_m_per_s2,0.0_m_per_s2,-0.0_m_per_s2};

    auto constexpr dt = static_<quan::time::s,1>;
    auto constexpr _0 = static_<int,0>;
    auto constexpr _1 = static_<int,1>;
    auto constexpr _2 = static_<int,2>;

    /*
      matrix is upper_triangular
     if (r > c) then type = reciprocal type at c,r
     and numeric_value is 0
    (0,0),(0,1),(0,2)
          (1,1),(1,2)
                 (2,2)
     (1,0)
     (2,0) (2,1)
    */
    auto constexpr m1 = quan::fusion::make_matrix<3>
    (
       // s <-         s * 1 +  u * dt  + a *dt^2/2
                          _1 ,      dt  , (dt*dt)/_2,

       // u <- s *      0/dt +  u * 1   +  a * dt
                       _0/dt ,     _1   ,      dt,

       // a <-    s * 0/dt^2 + u * 0/dt +   a * 1
                  _0/(dt*dt) ,    _0/dt ,      _1
    );

    // can use a matrix of vectors if each vector represents a different dimension
    auto x = quan::fusion::make_matrix<3>(
       s,  // distance
       u,  // velocity
       a   // accleration
    );

    display(x, "x = ");

    auto x1 = m1 * x;

    display(x1,"x1 = ");

    // or put values in direct
    auto alt_x = quan::fusion::make_matrix<3>(
      s.x,s.y,s.z,
      u.x,u.y,u.z,
      a.x,a.y,a.z
    );

    auto x2 = m1 * alt_x;

    display(x2, "res1 = ");

    return 0;
}

#if defined QUAN_STANDALONE
int main()
{
   kalman1();
}
int errors = 0;
#endif

#endif


