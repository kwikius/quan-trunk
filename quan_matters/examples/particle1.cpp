
// meant for multiple inclusion

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
 along with this program. If not, see http://www.gnu.org/licenses./
*/

// See <QUAN_ROOT/quan_matters/index.html> for documentation.


#include <ctime>


#include <quan/three_d/out/vect.hpp>
//required for pow<N>( double)
#include <quan/fixed_quantity/operations/power_root.hpp>

#ifdef USE_QUAN
#include <quan/out/length.hpp>
#include <quan/area.hpp>
#include <quan/out/velocity.hpp>
#include <quan/force.hpp>
#include <quan/mass.hpp>
#include <quan/time.hpp>
#include <quan/acceleration.hpp>
//#include <quan/constants/gravitational_constant.hpp>

#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
//#include <quan_matters/src/gravitational_constant.cpp>
//#include <quan_matters/src/acceleration_g.cpp>
#else
#include <quan/constants/gravitational_constant.hpp>
#endif
#endif

//#include <quan_matters/src/acceleration_g.cpp>

#ifdef USE_QUAN
   typedef  quan::fixed_quantity< 
            quan::meta::unit< 
                quan::meta::abstract_quantity<
                    quan::meta::dimension<
#if defined QUAN_META_CUSTOM_DIMENSION
                        quan::meta::dim_length<3> 
                        ,quan::meta::dim_time<-2> 
                        ,quan::meta::dim_mass<-1> 
#else
                        quan::meta::rational<3>,
                        quan::meta::rational<-2>,
                        quan::meta::rational<-1>,
                        quan::meta::rational<0>,
                        quan::meta::rational<0>,
                        quan::meta::rational<0>,
                        quan::meta::rational<0> 
#endif
                    >
                >,
                quan::meta::conversion_factor<
                    quan::meta::rational<0>
                >
            >,
            double
    > G_type;
   
   inline constexpr quan::acceleration::m_per_s2 get_quan_g() { return   quan::acceleration::m_per_s2(9.80665);}
   inline constexpr G_type get_quan_G() { return   G_type{6.6726e-11};}
#else
    inline constexpr double get_g() { return 9.80665;}
    inline constexpr double get_G() { return 6.6726e-11;}
#endif
 
namespace DATA_STRUCT {
#ifdef USE_QUAN
// all units are base units
    typedef quan::length::m length;
    typedef quan::length_<const double>::m length_c;
    typedef quan::velocity::m_per_s velocity;
    typedef quan::time::s time;
    typedef quan::time_<int>::s itime;
    typedef quan::time_<const int>::s itime_c;
    typedef quan::force::N force;
    typedef quan::mass::kg mass;
    typedef quan::acceleration::m_per_s2 acceleration;
  //  static  quan::gravitational_constant::G_type const G;
 #else
    typedef double length;
    typedef double length_c;
    typedef double velocity;
    typedef double time;
    typedef int itime;
    typedef int itime_c;
    typedef double force;
    typedef double mass;
    typedef double acceleration;
    double const G = 6.6726e-11;
    double const g = 9.80665;
#endif
    static constexpr length_c length_epsilon(1.e-6);
    static constexpr int num_particles = 20;
    static constexpr itime_c  max_time(10); 
    static constexpr itime_c timeStep(1);

// add a path class with a trajectory??

class particle{ 
public:
    static bool start;
    DATA_STRUCT::mass mass;
    quan::three_d::vect<DATA_STRUCT::length> pos;
    quan::three_d::vect<DATA_STRUCT::velocity> vel;
   
 
    particle()
     // note pos and vel are default initialised to 0,0,0 in quan
    :mass(1.0), pos(
        DATA_STRUCT::length(rand()%1000/1000.),
        DATA_STRUCT::length(rand()%1000/1000.),
        DATA_STRUCT::length(rand()%1000/1000.)),vel{DATA_STRUCT::velocity{0},DATA_STRUCT::velocity{0},DATA_STRUCT::velocity{0}}
    { 
        if( start){
         //   srand(static_cast<int>(time(0))); 
            start = false;
        }
      /*  pos.x = DATA_STRUCT::length(rand()%1000/1000.);
        pos.y = DATA_STRUCT::length(rand()%1000/1000.);
        pos.z = DATA_STRUCT::length(rand()%1000)/1000.;*/
    } 
    inline void apply_force(quan::three_d::vect<force> const & f);
    inline void update();
     
}; 
   
    inline quan::three_d::vect<force>
    calculate_forces( particle const&, particle const&); 
    inline quan::three_d::vect<force>
    single_particle_forces(particle const&); 

    std::ostream & operator << (std::ostream & os, particle const & p)
    {
        os << p.pos << '\n';
        os << p.vel << '\n';
        return os;
    }
}// namespace DATA_STRUCT
bool DATA_STRUCT ::particle::start = true;

void QUAN_MACRO_CAT(DATA_STRUCT,function)(){ 
    DATA_STRUCT::particle*  myParticles= 0;
    try{
        myParticles = new DATA_STRUCT::particle[DATA_STRUCT::num_particles];
        for( DATA_STRUCT::itime simulation_time
            = DATA_STRUCT::itime(0);
                simulation_time < DATA_STRUCT::max_time; 
                    simulation_time += DATA_STRUCT::timeStep){
            for(int i=0; i < DATA_STRUCT::num_particles; ++i){ 
                for(int j = i+1; j < DATA_STRUCT::num_particles; ++j){ 
                    quan::three_d::vect<DATA_STRUCT::force> f
                        = calculate_forces(myParticles[i], myParticles[j]); 
                    myParticles[i].apply_force(f); 
                    myParticles[j].apply_force(-f); 
                } 
                quan::three_d::vect<DATA_STRUCT::force> f_g
                    = DATA_STRUCT::single_particle_forces(myParticles[i]); 
                myParticles[i].apply_force(f_g); 
            } 
            for (int i = 0; i < DATA_STRUCT::num_particles; ++i){
                myParticles[i].update();
              //  std::cout << i << " " << myParticles[i] << '\n'; 
            }
            
        }
        delete [] myParticles;
   }
    catch (...){
        if (myParticles) delete [] myParticles;
        std::cout << "exception" <<'\n';
    }
} 

void DATA_STRUCT::particle::apply_force(quan::three_d::vect<DATA_STRUCT::force> const & f)
{ 
    this->vel += f / this->mass * DATA_STRUCT::timeStep ; 
} 

void DATA_STRUCT::particle::update()
{
    this->pos += this->vel * DATA_STRUCT::timeStep;
}

quan::three_d::vect<DATA_STRUCT::force>
DATA_STRUCT::calculate_forces(DATA_STRUCT::particle const & x, DATA_STRUCT::particle const & y)
{
    // find absolute distance between particles
    quan::three_d::vect<DATA_STRUCT::length> pos_diff  = y.pos - x.pos;
    quan::meta::binary_op<
       DATA_STRUCT::length,
       quan::meta::times,
       DATA_STRUCT::length
    >::type norm_pos = norm(pos_diff);
 //
    DATA_STRUCT::length abs_distance = magnitude(pos_diff);
    quan::three_d::vect<DATA_STRUCT::force> result;
    if ( abs_distance > DATA_STRUCT::length_epsilon){
#ifdef USE_QUAN
        DATA_STRUCT::force abs_force = get_quan_G() * x.mass * y.mass / norm_pos;
#else
     DATA_STRUCT::force abs_force = get_G() * x.mass * y.mass / norm_pos;
#endif
        result = abs_force * pos_diff / abs_distance;
    }
    else{
        result = quan::three_d::vect<DATA_STRUCT::force>(
            DATA_STRUCT::force(0),
            DATA_STRUCT::force(0),
            DATA_STRUCT::force(0)
        );
    };
    return result;
}
quan::three_d::vect<DATA_STRUCT::force>
DATA_STRUCT::single_particle_forces(DATA_STRUCT::particle const& x){ 
 
    quan::three_d::vect<DATA_STRUCT::force> result(
        DATA_STRUCT::force(0),
#ifdef USE_QUAN
       DATA_STRUCT::force(- x.mass * get_quan_g()),
#else
        DATA_STRUCT::force(- x.mass * get_g()),
#endif
        DATA_STRUCT::force(0)
    );
    return result;
}  
