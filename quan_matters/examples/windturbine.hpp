#ifndef BLADECALC_EXAMPLE_HPP_INCLUDED
#define BLADECALC_EXAMPLE_HPP_INCLUDED


// note could include all types... #include <quan/all_types.hpp>
// but compile-time is reduced if only the required types
// are included.
#include <quan/two_d/vect.hpp>
#include <quan/time.hpp>
#include <quan/velocity.hpp>
#include <quan/density.hpp>
#include <quan/force.hpp>
#include <quan/mass.hpp>
#include <quan/mass_flow.hpp>
#include <quan/out/angle.hpp>
#include <quan/out/length.hpp>
#include <quan/constants/constant.hpp>
#include <quan/fixed_quantity/operations/atan2.hpp>
#include <iostream>

// angle and chord of a rotor blade
struct chord_omega{

    chord_omega(quan::length::m const & chord,
                quan::angle::rad const& omega)
    : m_chord(chord), m_omega(omega)
    {}
    quan::length::m const   m_chord;
    quan::angle::deg  const   m_omega;
   private :
      chord_omega & operator =( chord_omega const &);
};

std::ostream& operator << (std::ostream& os,chord_omega const & in)
{
    os << "chord = " << in.m_chord << ", angle = " << in.m_omega;
    return os;
}


/*
Example
works out chord and angle of a wind turbine rotorblade
as a function of radius,
using input parameters in RotorDialog
*/

inline
chord_omega
getChordOmega(quan::length::m const & r);

// class for info about rotor
struct RotorDialog{

    RotorDialog():
        m_outer_dia{2300},
        m_inner_dia{300},
        m_vw{quan::velocity::mi_per_h{12.0}},
        m_tsr{6.5},
        m_ellipticality{0},
        m_rho_air{1.225},
        m_cd{.01},
        m_cl{0.7},
        m_numblades{3},
        m_alpha{4},
        m_num_sections{10}
    {}

    // outer diameter of turbine rotor
    quan::length_<int>::mm  const   m_outer_dia;
    quan::length_<int>::mm  const   m_inner_dia;
    // free wind velocity
    quan::velocity::m_per_s const   m_vw;
    // tip speed ratio rel free wind
    double              const       m_tsr;
    // blade shape param  (between 0 and 1)
    // nearer 1 gives'elliptical lift gradient
    // for reduced tip vortex
    double              const       m_ellipticality;
    // air density
    quan::density::kg_per_m3 const  m_rho_air;
    // drag coefficient
    double              const       m_cd;
    // lift coefficient
    double              const       m_cl;
    // number of blades on rotor
    int                 const       m_numblades;
    //angle of incidence
    quan::angle::deg    const       m_alpha;
    int                 const       m_num_sections ;

    quan::length::m get_section_spacing()const
    {
        return (m_outer_dia - m_inner_dia) / 2. * (m_num_sections -1);
    }
    chord_omega getChordOmega(quan::length::m const& r) const;
    quan::length::m get_section_radius(int section)const
    {
        /*quan::length::m dif = (m_outer_dia - m_inner_dia)/ 2.;*/
        return (( (m_outer_dia - m_inner_dia)/ 2.) * section)/ (m_num_sections) + (m_inner_dia /2);
    }
   private:
      RotorDialog & operator = ( RotorDialog const &);
}rotordialog;

chord_omega RotorDialog::getChordOmega(quan::length::m const& r)const
{
    using quan::length;
    using quan::velocity;
    using quan::mass_flow;
    using quan::force;
    using quan::pow;
    using quan::constant;
    using quan::angle;
    using quan::two_d::vect;

    auto const tip_r = this->m_outer_dia / 2.0;
    if (r > tip_r){
        throw std::out_of_range{"getChordOmega Input radius is out of range"};
    }

// input air flow velocity vector
    auto Vin = vect<double>{this->m_tsr * (r / tip_r),1}* this->m_vw;

// exhaust air flow velocity vector
    auto Vout = vect<velocity::m_per_s> {
      velocity::m_per_s(0),
      Vin.y
    * ( (r < tip_r)
        ? 1.0
          -  ((2.0 / 3.0) * (1.0 - this->m_ellipticality)
            + (this->m_ellipticality * sqrt(1.0 - pow<2>(r / tip_r) )))
        : 1.0 - (2.0/3.0)*(1.0 - this->m_ellipticality) )
    };

    auto Vb = ( Vin + Vout )/ 2.;

    auto const  dr = get_section_spacing();
    auto const  air_mass_flow
      = Vb.y * 2 * constant::pi * r * this->m_rho_air * dr;

    auto const Fb_y = air_mass_flow * (Vin.y - Vout.y) ;
    double const  cl = this->m_cl;
    double const  drag_coeff  = this->m_cd / cl;

    auto const epsilon = 0.0001 * abs(Vin.y);

    velocity::m_per_s oldVout_x(0);
    for (int i = 0 ;i < 1000 ; ++i){
        Vb.x = Vout.x / 2.0 + Vin.x;
        auto const beta = atan2(Vb.y,Vb.x);
        auto const cos_beta = cos(beta);
        auto const sin_beta = sin(beta);
        auto const Lift
        = Fb_y /(cos_beta + drag_coeff * sin_beta);
        auto const Fb_x
        = Lift * (sin_beta - drag_coeff * cos_beta);
        oldVout_x = Vout.x;
        Vout.x = Fb_x / air_mass_flow;
        if (compare(Vout.x,oldVout_x,epsilon) == 0 ){
            auto const chord
            = Lift
            / ( norm(Vb) * 0.5 * this->m_rho_air
                * cl * dr * this->m_numblades );
            return chord_omega{chord,beta};
        }
    }//fail
    return chord_omega{length::mm{0.0},angle::rad{0.0}};
}

#endif
