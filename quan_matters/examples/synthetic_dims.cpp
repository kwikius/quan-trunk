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
    Get dimension of a synthessied quantity
*/

#include <quan/out/all_types.hpp>
#include <string>

std::string ar[]={
"length","time","mass","temperature","current","substance","intensity"
};

template <typename Q>
void show (
    std::ostream& os, 
    std::string const & name, 
    std::string const & non_prog_name,
    Q q, 
    std::string const & upf_sym,
    std::string const & upf_out_sym,
    std::string const & upf_pre_sym = "null",
    int offset = 0, 
    int extent = 1
) 
{
    typedef typename Q::unit static_unit;

    
    os << name << ',' ;
    os 
    #define GET_STATIC_UNIT(D) << \
    quan::meta::numerator< \
      typename quan::meta:: get_ ## D ## _dimension<static_unit>::type \
    >::value
    GET_STATIC_UNIT(length) << ','
    GET_STATIC_UNIT(time) << ','
    GET_STATIC_UNIT(mass) << ','
    GET_STATIC_UNIT(temperature) << ','
    GET_STATIC_UNIT(current) << ','
    GET_STATIC_UNIT(substance) << ','
    GET_STATIC_UNIT(intensity) << ','
    #undef GET_STATIC_UNIT
    << upf_pre_sym << ',' << upf_sym <<','
    << offset << ',' << extent <<','
    << non_prog_name  << ','  << upf_out_sym
    << '\n';
    
}

#include <fstream>
int main()
{
    quan::length::m length(1);
    quan::time::s time(1);
    quan::mass::kg mass(1);
    quan::temperature::K temperature(1);
    quan::current::A current(1);
    quan::substance::mol subst(1);
    quan::intensity::cd intensity(1);
    quan::energy::J energy(1); 
    quan::area::m2 area(1);
    quan::force::N force(1);
    quan::volume::m3 volume(1);
    quan::power::W power(1);
    quan::pressure::Pa pressure(1);
#if (1)
    std::ostream & os = std::cout;
#else
    std::ofstream os("db_dims.csv");
#endif
    os << "abstract quantity name ,";
    for (int i = 0 ; i < 7 ; ++i){
        os << ar[i] << ',';
    }
    os << "upf_pre_sym,upf_sym,offset,extent,non-prog name,upf_out_sym" << '\n';

    show(os, "volume_flow" , // name
         "volume flow" , //out name
        volume/time, //dim
        "m3_per_s", // prog sym
        "m3.s-1" //upf_out_sym
    );

    show(os, "force_per_mass" , // name
         "force divided by mass" , //out name
        force/mass, //dim
        "N_per_kg", // prog sym
        "N.kg-1" //upf_out_sym
    );

      show(os, "energy_per_area_time" , // name
         "energy divided by area time" , //out name
        energy / (area * time), //dim
        "W_per_m2", // prog sym
        "W.m-2" //upf_out_sym
    );

    show(os, "force_per_length" , // name
         "force divided by length" , //out name
        force / length, //dim
        "N_per_m", // prog sym
        "N.m-1" //upf_out_sym
    );
    
    show(os, "energy_per_volume" , // name
         "energy divided by volume" , //out name
         energy / volume, //dim
        "J_per_m3", // prog sym
        "J.m-3" //upf_out_sym
    );
    
    show(os, "energy_per_mass" , // name
         "energy divided by mass" , //out name
         energy / mass, //dim
        "J_per_kg", // prog sym
        "J.kg-1" //upf_out_sym
    );
    
    show(os, "heat_transfer_coefficient" , // name
         "heat transfer coefficient" , //out name
         power / (area * temperature), //dim
        "W_per_m2_K", // prog sym
        "W.m-2.K-1" //upf_out_sym
    );

    show(os, "heat_density" , // name
         "heat density" , //out name
         energy / area, //dim
        "J_per_m2", // prog sym
        "J.m-2" //upf_out_sym
    );
 
    show(os, "heat_flow_density" , // name
         "heat flow density" , //out name
         power / area, //dim
        "W_per_m2", // prog sym
        "W.m-2" //upf_out_sym
    );

    show(os, "volume_per_energy" , // name
         "volume divided by energy" , //out name
         volume / energy, //dim
        "m3_per_J", // prog sym
        "m3.J-1" //upf_out_sym
    );

    show(os, "fuel_consumption" , // name
         "fuel consumption" , //out name
        length / volume, //dim
        "m_per_m3", // prog sym
        "m.m-3" //upf_out_sym
    );

    show(os, "entropy" , // name
         "entropy" , //out name
        energy / temperature, //dim
        "J_per_K", // prog sym
        "J.K-1" //upf_out_sym
    );

    show(os, "heat_flow" , // name
         "heat flow" , //out name
        power, //dim
        "W", // prog sym
        "W" //upf_out_sym
    );

    show(os, "specific_entropy" , // name
         "specific entropy" , //out name
        energy / ( mass * temperature), //dim
        "J_per_kg_K", // prog sym
        "J.kg-1.K-1" //upf_out_sym
    );
///////////WRONG//////////////////
    show(os, "thermal_conductivity" , // name
         "thermal conductivity" , //out name
////////////////
        power / ( length * temperature), //dim
        "W_per_m_K", // prog sym
        "W.m-1.K-1" //upf_out_sym
    );
////////////////////
    show(os, "thermal_diffusivity" , // name
         "thermal diffusivity" , //out name
        area / time, //dim
        "m2_per_s", // prog sym
        "m2.s-1" //upf_out_sym
    );

    show(os, "thermal_insulance" , // name
         "thermal insulance" , //out name
        area * temperature / power, //dim
        "m2_K_per_W", // prog sym
        "m2.K.W-1" //upf_out_sym
    );

    show(os, "thermal_resistance" , // name
         "thermal resistance" , //out name
        temperature / power, //dim
        "K_per_W", // prog sym
        "K.W-1" //upf_out_sym
    );

    show(os, "thermal_resistivity" , // name
         "thermal resistivity" , //out name
        (length * temperature) / power, //dim
        "m_K_per_W", // prog sym
        "m.K.W-1" //upf_out_sym
    );
  // in fact are 3 types of permeability  
    show(os, "permeability" , // name
        "permeability" , //out name
        mass /( pressure * time * area), //dim
        "g_per_Pa_s_m2", // prog sym
        "g.Pa-1.s-1.m-2", //upf_out_sym,
        "null",3
    );
}
