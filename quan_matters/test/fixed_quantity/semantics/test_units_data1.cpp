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


// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    compare all known units with expected
*/

#include <quan_matters/test/simple_test.hpp>
#include <quan/out/all_types.hpp>
#include <iostream>

void test_units_data1()
{
     QUAN_CHECK(units_str(quan::length::ym()) == "ym");
    QUAN_CHECK(units_str(quan::length::zm()) == "zm");
    QUAN_CHECK(units_str(quan::length::am()) == "am");
    QUAN_CHECK(units_str(quan::length::fm()) == "fm");
    QUAN_CHECK(units_str(quan::length::pm()) == "pm");
    QUAN_CHECK(units_str(quan::length::nm()) == "nm");
    QUAN_CHECK(units_str(quan::length::um()) == "um");
    QUAN_CHECK(units_str(quan::length::mm()) == "mm");
    QUAN_CHECK(units_str(quan::length::cm()) == "cm");
    QUAN_CHECK(units_str(quan::length::dm()) == "dm");
    QUAN_CHECK(units_str(quan::length::m()) == "m");
    QUAN_CHECK(units_str(quan::length::dam()) == "dam");
    QUAN_CHECK(units_str(quan::length::hm()) == "hm");
    QUAN_CHECK(units_str(quan::length::km()) == "km");
    QUAN_CHECK(units_str(quan::length::Mm()) == "Mm");
    QUAN_CHECK(units_str(quan::length::Gm()) == "Gm");
    QUAN_CHECK(units_str(quan::length::Tm()) == "Tm");
    QUAN_CHECK(units_str(quan::length::Pm()) == "Pm");
    QUAN_CHECK(units_str(quan::length::Em()) == "Em");
    QUAN_CHECK(units_str(quan::length::Zm()) == "Zm");
    QUAN_CHECK(units_str(quan::length::fathom_us()) == "fathom (U.S.)");
    QUAN_CHECK(units_str(quan::length::AU()) == "AU");
    QUAN_CHECK(units_str(quan::length::ch()) == "ch");
    QUAN_CHECK(units_str(quan::length::fathom()) == "fathom");
    QUAN_CHECK(units_str(quan::length::ft()) == "ft");
    QUAN_CHECK(units_str(quan::length::ft_us()) == "ft (U.S.)");
    QUAN_CHECK(units_str(quan::length::in()) == "in");
    QUAN_CHECK(units_str(quan::length::l_y_()) == "l.y.");
    QUAN_CHECK(units_str(quan::length::mi()) == "mi");
    QUAN_CHECK(units_str(quan::length::naut_mile()) == "nautical mile");
    QUAN_CHECK(units_str(quan::length::pc()) == "pc");
    QUAN_CHECK(units_str(quan::length::pica_comp()) == "pica (comp)");
    QUAN_CHECK(units_str(quan::length::pica_prn()) == "pica (prn)");
    QUAN_CHECK(units_str(quan::length::point_comp()) == "point (comp)");
    QUAN_CHECK(units_str(quan::length::point_prn()) == "point (prn)");
    QUAN_CHECK(units_str(quan::length::rd()) == "rd");
    QUAN_CHECK(units_str(quan::length::yd()) == "yd");
    QUAN_CHECK(units_str(quan::length::angstrom()) == "angstrom");
    QUAN_CHECK(units_str(quan::time::ys()) == "ys");
    QUAN_CHECK(units_str(quan::time::zs()) == "zs");
    QUAN_CHECK(units_str(quan::time::as()) == "as");
    QUAN_CHECK(units_str(quan::time::fs()) == "fs");
    QUAN_CHECK(units_str(quan::time::ps()) == "ps");
    QUAN_CHECK(units_str(quan::time::ns()) == "ns");
    QUAN_CHECK(units_str(quan::time::us()) == "us");
    QUAN_CHECK(units_str(quan::time::ms()) == "ms");
    QUAN_CHECK(units_str(quan::time::cs()) == "cs");
    QUAN_CHECK(units_str(quan::time::ds()) == "ds");
    QUAN_CHECK(units_str(quan::time::s()) == "s");
    QUAN_CHECK(units_str(quan::time::das()) == "das");
    QUAN_CHECK(units_str(quan::time::hs()) == "hs");
    QUAN_CHECK(units_str(quan::time::ks()) == "ks");
    QUAN_CHECK(units_str(quan::time::Ms()) == "Ms");
    QUAN_CHECK(units_str(quan::time::Gs()) == "Gs");
    QUAN_CHECK(units_str(quan::time::Ts()) == "Ts");
    QUAN_CHECK(units_str(quan::time::Ps()) == "Ps");
    QUAN_CHECK(units_str(quan::time::Es()) == "Es");
    QUAN_CHECK(units_str(quan::time::Zs()) == "Zs");
    QUAN_CHECK(units_str(quan::time::d()) == "d");
    QUAN_CHECK(units_str(quan::time::d_sid()) == "d (sid)");
    QUAN_CHECK(units_str(quan::time::h()) == "h");
    QUAN_CHECK(units_str(quan::time::h_sid()) == "h (sid)");
#if ! defined (min)
     QUAN_CHECK(units_str( quan::time::min()) == "min");
#else
 
    //use of min() looks like the macro so just create a variable
    quan::time::min min;   
    QUAN_CHECK(units_str(min) == "min");
#endif
    QUAN_CHECK(units_str(quan::time::min_sid()) == "min (sid)");
    QUAN_CHECK(units_str(quan::time::s_sid()) == "s (sid)");
    QUAN_CHECK(units_str(quan::time::wk()) == "wk");
    QUAN_CHECK(units_str(quan::time::yr()) == "yr");
    QUAN_CHECK(units_str(quan::time::yr_sid()) == "yr (sid)");
    QUAN_CHECK(units_str(quan::time::yr_trop()) == "yr (trop)");

    QUAN_CHECK(units_str(quan::mass::zg()) == "zg");
    QUAN_CHECK(units_str(quan::mass::ag()) == "ag");
    QUAN_CHECK(units_str(quan::mass::fg()) == "fg");
    QUAN_CHECK(units_str(quan::mass::pg()) == "pg");
    QUAN_CHECK(units_str(quan::mass::ng()) == "ng");
    QUAN_CHECK(units_str(quan::mass::ug()) == "ug");
    QUAN_CHECK(units_str(quan::mass::mg()) == "mg");
    QUAN_CHECK(units_str(quan::mass::g()) == "g");
    QUAN_CHECK(units_str(quan::mass::dag()) == "dag");
    QUAN_CHECK(units_str(quan::mass::hg()) == "hg");
    QUAN_CHECK(units_str(quan::mass::kg()) == "kg");
    QUAN_CHECK(units_str(quan::mass::Mg()) == "Mg");
    QUAN_CHECK(units_str(quan::mass::Gg()) == "Gg");
    QUAN_CHECK(units_str(quan::mass::Tg()) == "Tg");
    QUAN_CHECK(units_str(quan::mass::Pg()) == "Pg");
    QUAN_CHECK(units_str(quan::mass::Eg()) == "Eg");
    QUAN_CHECK(units_str(quan::mass::Zg()) == "Zg");
    QUAN_CHECK(units_str(quan::mass::AT()) == "AT");
    QUAN_CHECK(units_str(quan::mass::ton_long()) == "ton (long)");
    QUAN_CHECK(units_str(quan::mass::t()) == "t");
    QUAN_CHECK(units_str(quan::mass::kg()) == "kg");
    QUAN_CHECK(units_str(quan::mass::carat()) == "carat");
    QUAN_CHECK(units_str(quan::mass::grain()) == "grain");
    QUAN_CHECK(units_str(quan::mass::hundredwgt_short()) == "hundredweight (long)");
    QUAN_CHECK(units_str(quan::mass::hundredwgt_long()) == "hundredweight (short)");
    QUAN_CHECK(units_str(quan::mass::oz()) == "oz");
    QUAN_CHECK(units_str(quan::mass::troy_oz()) == "oz (troy)");
    QUAN_CHECK(units_str(quan::mass::dwt()) == "dwt");
    QUAN_CHECK(units_str(quan::mass::lb()) == "lb");
    QUAN_CHECK(units_str(quan::mass::troy_lb()) == "lb (troy)");
    QUAN_CHECK(units_str(quan::mass::slug()) == "slug");
    QUAN_CHECK(units_str(quan::temperature::yK()) == "yK");
    QUAN_CHECK(units_str(quan::temperature::zK()) == "zK");
    QUAN_CHECK(units_str(quan::temperature::aK()) == "aK");
    QUAN_CHECK(units_str(quan::temperature::fK()) == "fK");
    QUAN_CHECK(units_str(quan::temperature::pK()) == "pK");
    QUAN_CHECK(units_str(quan::temperature::nK()) == "nK");
    QUAN_CHECK(units_str(quan::temperature::uK()) == "uK");
    QUAN_CHECK(units_str(quan::temperature::mK()) == "mK");
    QUAN_CHECK(units_str(quan::temperature::cK()) == "cK");
    QUAN_CHECK(units_str(quan::temperature::dK()) == "dK");
    QUAN_CHECK(units_str(quan::temperature::K()) == "K");
    QUAN_CHECK(units_str(quan::temperature::daK()) == "daK");
    QUAN_CHECK(units_str(quan::temperature::hK()) == "hK");
    QUAN_CHECK(units_str(quan::temperature::kK()) == "kK");
    QUAN_CHECK(units_str(quan::temperature::MK()) == "MK");
    QUAN_CHECK(units_str(quan::temperature::GK()) == "GK");
    QUAN_CHECK(units_str(quan::temperature::TK()) == "TK");
    QUAN_CHECK(units_str(quan::temperature::PK()) == "PK");
    QUAN_CHECK(units_str(quan::temperature::EK()) == "EK");
    QUAN_CHECK(units_str(quan::temperature::ZK()) == "ZK");
    QUAN_CHECK(units_str(quan::current::yA()) == "yA");
    QUAN_CHECK(units_str(quan::current::zA()) == "zA");
    QUAN_CHECK(units_str(quan::current::aA()) == "aA");
    QUAN_CHECK(units_str(quan::current::fA()) == "fA");
    QUAN_CHECK(units_str(quan::current::pA()) == "pA");
    QUAN_CHECK(units_str(quan::current::nA()) == "nA");
    QUAN_CHECK(units_str(quan::current::uA()) == "uA");
    QUAN_CHECK(units_str(quan::current::mA()) == "mA");
    QUAN_CHECK(units_str(quan::current::cA()) == "cA");
    QUAN_CHECK(units_str(quan::current::dA()) == "dA");
    QUAN_CHECK(units_str(quan::current::A()) == "A");
    QUAN_CHECK(units_str(quan::current::daA()) == "daA");
    QUAN_CHECK(units_str(quan::current::hA()) == "hA");
    QUAN_CHECK(units_str(quan::current::kA()) == "kA");
    QUAN_CHECK(units_str(quan::current::MA()) == "MA");
    QUAN_CHECK(units_str(quan::current::GA()) == "GA");
    QUAN_CHECK(units_str(quan::current::TA()) == "TA");
    QUAN_CHECK(units_str(quan::current::PA()) == "PA");
    QUAN_CHECK(units_str(quan::current::EA()) == "EA");
    QUAN_CHECK(units_str(quan::current::ZA()) == "ZA");
    QUAN_CHECK(units_str(quan::current::abampere()) == "abampere");
     QUAN_CHECK(units_str(quan::substance::ymol()) == "ymol");
    QUAN_CHECK(units_str(quan::substance::zmol()) == "zmol");
    QUAN_CHECK(units_str(quan::substance::amol()) == "amol");
    QUAN_CHECK(units_str(quan::substance::fmol()) == "fmol");
    QUAN_CHECK(units_str(quan::substance::pmol()) == "pmol");
    QUAN_CHECK(units_str(quan::substance::nmol()) == "nmol");
    QUAN_CHECK(units_str(quan::substance::umol()) == "umol");
    QUAN_CHECK(units_str(quan::substance::mmol()) == "mmol");
    QUAN_CHECK(units_str(quan::substance::cmol()) == "cmol");
    QUAN_CHECK(units_str(quan::substance::dmol()) == "dmol");
    QUAN_CHECK(units_str(quan::substance::mol()) == "mol");
    QUAN_CHECK(units_str(quan::substance::damol()) == "damol");
    QUAN_CHECK(units_str(quan::substance::hmol()) == "hmol");
    QUAN_CHECK(units_str(quan::substance::kmol()) == "kmol");
    QUAN_CHECK(units_str(quan::substance::Mmol()) == "Mmol");
    QUAN_CHECK(units_str(quan::substance::Gmol()) == "Gmol");
    QUAN_CHECK(units_str(quan::substance::Tmol()) == "Tmol");
    QUAN_CHECK(units_str(quan::substance::Pmol()) == "Pmol");
    QUAN_CHECK(units_str(quan::substance::Emol()) == "Emol");
    QUAN_CHECK(units_str(quan::substance::Zmol()) == "Zmol");
    QUAN_CHECK(units_str(quan::intensity::ycd()) == "ycd");
    QUAN_CHECK(units_str(quan::intensity::zcd()) == "zcd");
    QUAN_CHECK(units_str(quan::intensity::acd()) == "acd");
    QUAN_CHECK(units_str(quan::intensity::fcd()) == "fcd");
    QUAN_CHECK(units_str(quan::intensity::pcd()) == "pcd");
    QUAN_CHECK(units_str(quan::intensity::ncd()) == "ncd");
    QUAN_CHECK(units_str(quan::intensity::ucd()) == "ucd");
    QUAN_CHECK(units_str(quan::intensity::mcd()) == "mcd");
    QUAN_CHECK(units_str(quan::intensity::ccd()) == "ccd");
    QUAN_CHECK(units_str(quan::intensity::dcd()) == "dcd");
    QUAN_CHECK(units_str(quan::intensity::cd()) == "cd");
    QUAN_CHECK(units_str(quan::intensity::dacd()) == "dacd");
    QUAN_CHECK(units_str(quan::intensity::hcd()) == "hcd");
    QUAN_CHECK(units_str(quan::intensity::kcd()) == "kcd");
    QUAN_CHECK(units_str(quan::intensity::Mcd()) == "Mcd");
    QUAN_CHECK(units_str(quan::intensity::Gcd()) == "Gcd");
    QUAN_CHECK(units_str(quan::intensity::Tcd()) == "Tcd");
    QUAN_CHECK(units_str(quan::intensity::Pcd()) == "Pcd");
    QUAN_CHECK(units_str(quan::intensity::Ecd()) == "Ecd");
    QUAN_CHECK(units_str(quan::intensity::Zcd()) == "Zcd");
    QUAN_CHECK(units_str(quan::area::pm2()) == "pm2");
    QUAN_CHECK(units_str(quan::area::nm2()) == "nm2");
    QUAN_CHECK(units_str(quan::area::um2()) == "um2");
    QUAN_CHECK(units_str(quan::area::mm2()) == "mm2");
    QUAN_CHECK(units_str(quan::area::dm2()) == "dm2");
    QUAN_CHECK(units_str(quan::area::m2()) == "m2");

    QUAN_CHECK(units_str(quan::area::dam2()) == "dam2");
    QUAN_CHECK(units_str(quan::area::km2()) == "km2");
    QUAN_CHECK(units_str(quan::area::Mm2()) == "Mm2");
    QUAN_CHECK(units_str(quan::area::Gm2()) == "Gm2");
    QUAN_CHECK(units_str(quan::area::Tm2()) == "Tm2");
    QUAN_CHECK(units_str(quan::area::acre()) == "acre");
    QUAN_CHECK(units_str(quan::area::a()) == "a");
    QUAN_CHECK(units_str(quan::area::b()) == "b");
    QUAN_CHECK(units_str(quan::area::circular_mil()) == "circular mil");
    QUAN_CHECK(units_str(quan::area::ha()) == "ha");
    QUAN_CHECK(units_str(quan::area::ft2()) == "ft2");
    QUAN_CHECK(units_str(quan::area::in2()) == "in2");
    QUAN_CHECK(units_str(quan::area::mi2()) == "mi2");
    QUAN_CHECK(units_str(quan::area::mi2_us_survey()) == "mi2 (U.S.)");
    QUAN_CHECK(units_str(quan::area::yd2()) == "yd2");
//    QUAN_CHECK(units_str(quan::area::are()) == "are");
    QUAN_CHECK(units_str(quan::volume::um3()) == "um3");
    QUAN_CHECK(units_str(quan::volume::mm3()) == "mm3");
    QUAN_CHECK(units_str(quan::volume::cm3()) == "cm3");
    QUAN_CHECK(units_str(quan::volume::dm3()) == "dm3");
    QUAN_CHECK(units_str(quan::volume::m3()) == "m3");
    QUAN_CHECK(units_str(quan::volume::dam3()) == "dam3");
    QUAN_CHECK(units_str(quan::volume::hm3()) == "hm3");
    QUAN_CHECK(units_str(quan::volume::km3()) == "km3");
    QUAN_CHECK(units_str(quan::volume::Mm3()) == "Mm3");
    QUAN_CHECK(units_str(quan::volume::acre_foot()) == "acre-foot");
    QUAN_CHECK(units_str(quan::volume::bbl()) == "bbl");
    QUAN_CHECK(units_str(quan::volume::bu()) == "bu");
    QUAN_CHECK(units_str(quan::volume::cord()) == "cord");
    QUAN_CHECK(units_str(quan::volume::ft3()) == "ft3");
    QUAN_CHECK(units_str(quan::volume::in3()) == "in3");
    QUAN_CHECK(units_str(quan::volume::mi3()) == "mi3");
    QUAN_CHECK(units_str(quan::volume::yd3()) == "yd3");
    QUAN_CHECK(units_str(quan::volume::cup()) == "cup");
    QUAN_CHECK(units_str(quan::volume::fl_oz_US()) == "fl oz (U.S.)");
    QUAN_CHECK(units_str(quan::volume::gal()) == "gal");
//mark

    QUAN_CHECK(units_str(quan::volume::gal_US()) == "gal (U.S.)");
    QUAN_CHECK(units_str(quan::acceleration::ym_per_s2()) == "ym.s-2");
    QUAN_CHECK(units_str(quan::acceleration::zm_per_s2()) == "zm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::am_per_s2()) == "am.s-2");
    QUAN_CHECK(units_str(quan::acceleration::fm_per_s2()) == "fm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::pm_per_s2()) == "pm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::nm_per_s2()) == "nm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::um_per_s2()) == "um.s-2");
    QUAN_CHECK(units_str(quan::acceleration::mm_per_s2()) == "mm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::cm_per_s2()) == "cm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::dm_per_s2()) == "dm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::m_per_s2()) == "m.s-2");
    QUAN_CHECK(units_str(quan::acceleration::dam_per_s2()) == "dam.s-2");
    QUAN_CHECK(units_str(quan::acceleration::hm_per_s2()) == "hm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::km_per_s2()) == "km.s-2");
    QUAN_CHECK(units_str(quan::acceleration::Mm_per_s2()) == "Mm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::Gm_per_s2()) == "Gm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::Tm_per_s2()) == "Tm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::Pm_per_s2()) == "Pm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::Em_per_s2()) == "Em.s-2");
    QUAN_CHECK(units_str(quan::acceleration::Zm_per_s2()) == "Zm.s-2");
    QUAN_CHECK(units_str(quan::acceleration::g_s()) == "g");
    QUAN_CHECK(units_str(quan::acceleration::ft_per_s2()) == "ft.s-2");
    QUAN_CHECK(units_str(quan::acceleration::Gal()) == "Gal");
    QUAN_CHECK(units_str(quan::acceleration::in_per_s2()) == "in.s-2");
    QUAN_CHECK(units_str(quan::force::yN()) == "yN");
    QUAN_CHECK(units_str(quan::force::zN()) == "zN");
    QUAN_CHECK(units_str(quan::force::aN()) == "aN");
    QUAN_CHECK(units_str(quan::force::fN()) == "fN");
    QUAN_CHECK(units_str(quan::force::pN()) == "pN");
    QUAN_CHECK(units_str(quan::force::nN()) == "nN");
    QUAN_CHECK(units_str(quan::force::uN()) == "uN");
    QUAN_CHECK(units_str(quan::force::mN()) == "mN");
    QUAN_CHECK(units_str(quan::force::cN()) == "cN");
    QUAN_CHECK(units_str(quan::force::dN()) == "dN");

    QUAN_CHECK(units_str(quan::force::N()) == "N");
    QUAN_CHECK(units_str(quan::force::daN()) == "daN");
    QUAN_CHECK(units_str(quan::force::hN()) == "hN");
    QUAN_CHECK(units_str(quan::force::kN()) == "kN");

    QUAN_CHECK(units_str(quan::force::MN()) == "MN");
    QUAN_CHECK(units_str(quan::force::GN()) == "GN");
    QUAN_CHECK(units_str(quan::force::TN()) == "TN");
    QUAN_CHECK(units_str(quan::force::PN()) == "PN");
    QUAN_CHECK(units_str(quan::force::EN()) == "EN");
    QUAN_CHECK(units_str(quan::force::ZN()) == "ZN");
    QUAN_CHECK(units_str(quan::force::dyn()) == "dyn");
    QUAN_CHECK(units_str(quan::force::kgf()) == "kgf");
    QUAN_CHECK(units_str(quan::force::kip()) == "kip");
    QUAN_CHECK(units_str(quan::force::ozf()) == "ozf");
    QUAN_CHECK(units_str(quan::force::poundal()) == "poundal");
    QUAN_CHECK(units_str(quan::force::lbf()) == "lbf");
    QUAN_CHECK(units_str(quan::force::ton_force()) == "ton-force");
    QUAN_CHECK(units_str(quan::capacitance::yF()) == "yF");
    QUAN_CHECK(units_str(quan::capacitance::zF()) == "zF");
    QUAN_CHECK(units_str(quan::capacitance::aF()) == "aF");
    QUAN_CHECK(units_str(quan::capacitance::fF()) == "fF");
    QUAN_CHECK(units_str(quan::capacitance::pF()) == "pF");
    QUAN_CHECK(units_str(quan::capacitance::nF()) == "nF");
    QUAN_CHECK(units_str(quan::capacitance::uF()) == "uF");
    QUAN_CHECK(units_str(quan::capacitance::mF()) == "mF");
    QUAN_CHECK(units_str(quan::capacitance::cF()) == "cF");
    QUAN_CHECK(units_str(quan::capacitance::dF()) == "dF");
    QUAN_CHECK(units_str(quan::capacitance::F()) == "F");
    QUAN_CHECK(units_str(quan::capacitance::daF()) == "daF");
    QUAN_CHECK(units_str(quan::capacitance::hF()) == "hF");
    QUAN_CHECK(units_str(quan::capacitance::kF()) == "kF");
    QUAN_CHECK(units_str(quan::capacitance::MF()) == "MF");
    QUAN_CHECK(units_str(quan::capacitance::GF()) == "GF");
    QUAN_CHECK(units_str(quan::capacitance::TF()) == "TF");
    QUAN_CHECK(units_str(quan::capacitance::PF()) == "PF");
    QUAN_CHECK(units_str(quan::capacitance::EF()) == "EF");
    QUAN_CHECK(units_str(quan::capacitance::ZF()) == "ZF");
    QUAN_CHECK(units_str(quan::capacitance::abfarad()) == "abfarad");
    QUAN_CHECK(units_str(quan::charge::yC()) == "yC");
    QUAN_CHECK(units_str(quan::charge::zC()) == "zC");
    QUAN_CHECK(units_str(quan::charge::aC()) == "aC");
    QUAN_CHECK(units_str(quan::charge::fC()) == "fC");
    QUAN_CHECK(units_str(quan::charge::pC()) == "pC");
    QUAN_CHECK(units_str(quan::charge::nC()) == "nC");
    QUAN_CHECK(units_str(quan::charge::uC()) == "uC");
    QUAN_CHECK(units_str(quan::charge::mC()) == "mC");
    QUAN_CHECK(units_str(quan::charge::cC()) == "cC");
    QUAN_CHECK(units_str(quan::charge::dC()) == "dC");
    QUAN_CHECK(units_str(quan::charge::C()) == "C");
    QUAN_CHECK(units_str(quan::charge::daC()) == "daC");
    QUAN_CHECK(units_str(quan::charge::hC()) == "hC");
    QUAN_CHECK(units_str(quan::charge::kC()) == "kC");
    QUAN_CHECK(units_str(quan::charge::MC()) == "MC");
    QUAN_CHECK(units_str(quan::charge::GC()) == "GC");
    QUAN_CHECK(units_str(quan::charge::TC()) == "TC");
    QUAN_CHECK(units_str(quan::charge::PC()) == "PC");
    QUAN_CHECK(units_str(quan::charge::EC()) == "EC");
    QUAN_CHECK(units_str(quan::charge::ZC()) == "ZC");
    QUAN_CHECK(units_str(quan::charge::A_h()) == "A.h");
    QUAN_CHECK(units_str(quan::charge::abcoulomb()) == "abcoulomb");

}
