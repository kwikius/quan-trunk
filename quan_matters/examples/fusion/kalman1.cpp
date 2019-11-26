

/*
http://home.wlu.edu/~levys/kalman_tutorial/
http://www.bzarg.com/p/how-a-kalman-filter-works-in-pictures
http://bilgin.esme.org/BitsBytes/KalmanFilterforDummies.aspx
http://en.wikipedia.org/wiki/Kalman_filter
http://www.cl.cam.ac.uk/~rmf25/papers/Understanding%20the%20Basis%20of%20the%20Kalman%20Filter.pdf

*/

#include <quan/fusion/make_matrix.hpp>

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
}

int kalman1() 
{
    quan::three_d::vect<quan::length::m>              p{0.0_m,0.0_m,0.0_m};
    quan::three_d::vect<quan::velocity::m_per_s>      v{1.0_m_per_s,0_m_per_s,1_m_per_s};
    quan::three_d::vect<quan::acceleration::m_per_s2> a{0.0_m_per_s2,0.1_m_per_s2,0_m_per_s2};

    auto constexpr dt = 1.0_s;
    auto constexpr m1 = quan::fusion::make_matrix<3>
    (
       1.0                  ,      dt  ,  quan::pow<2>(dt)/2.0,
       0.0/dt               ,     1.0  ,                dt  ,
       0.0/quan::pow<2>(dt) ,     0.0/dt ,               1.0
    );

    // ds = u * dt + 1/2 a*dt^2 :  s <- old_s + u * dt + 1/2 a*dt^2  // p * 1    + v * dt +  a * dt^2 / 2
    // v = u + a * dt           :  v <- v + a * dt                   // p * 0/dt + v * 1  +  a * dt
    // a = v/dt  - u/dt         :  a <- v / dt - a                   // p * 0/dt^2 + v * dt - a * 1

    auto x = quan::fusion::make_matrix<3>
    (
       p,
       v,
       a
    );
    display(x, "x = ");

    for (int32_t i = 0; i < 3; ++i){
       x = m1 * x;
       display(x,"x = ");
    }

    return 0;
}


