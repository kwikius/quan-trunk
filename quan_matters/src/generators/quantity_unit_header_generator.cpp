
/*
  TODO apply each unit conv_factor<1> conv_factor<2> etc , not si_units
*/

#include <quan/meta/find_if.hpp>
#include <quan/meta/si_units.hpp>
#include <quan/all_types.hpp>
#include <quan/fixed_quantity/io/detail/units_out_impl.hpp>
#include <iostream>
#include <quan/fusion/make_vector.hpp>
#include <quan/fun/for_each.hpp>
#include <quan/fun/integer_range.hpp>
#include <string>
#include <fstream>

auto get_quantities_list()
{
   return quan::fusion::make_vector(
      quan::meta::components::of_acceleration{},
      quan::meta::components::of_area{},
      quan::meta::components::of_area_moment_of_inertia{},
      quan::meta::components::of_capacitance{},
      quan::meta::components::of_charge{},
      quan::meta::components::of_circulation{},
      quan::meta::components::of_conductance{},
      quan::meta::components::of_current{},
      quan::meta::components::of_density{},
      quan::meta::components::of_energy{},
      quan::meta::components::of_energy_per_area_time{},
      quan::meta::components::of_energy_per_area_time_length{},
      quan::meta::components::of_energy_per_mass{},
      quan::meta::components::of_energy_per_volume{},
      quan::meta::components::of_entropy{},
      quan::meta::components::of_force{},
      quan::meta::components::of_force_per_area{},
      quan::meta::components::of_force_per_length{},
      quan::meta::components::of_force_per_mass{},
      quan::meta::components::of_force_per_volume{},
      quan::meta::components::of_frequency{},
      quan::meta::components::of_fuel_consumption{},
      quan::meta::components::of_heat_density{},
      quan::meta::components::of_heat_flow_density{},
      quan::meta::components::of_heat_flow{},
      quan::meta::components::of_heat_transfer_coefficient{},
      quan::meta::components::of_inductance{},
      quan::meta::components::of_intensity{},
      quan::meta::components::of_length{},
      quan::meta::components::of_magnetic_field_strength{},
      quan::meta::components::of_magnetic_flux_density{},
      quan::meta::components::of_magnetic_flux{},
      quan::meta::components::of_magnetic_permeability{},
      quan::meta::components::of_magnetomotive_force{},
      quan::meta::components::of_mass_flow{},
      quan::meta::components::of_mass{},
      quan::meta::components::of_mass_per_area{},
      quan::meta::components::of_permeability{},
      quan::meta::components::of_potential_difference{},
      quan::meta::components::of_power{},
      quan::meta::components::of_pressure{},
      quan::meta::components::of_reciprocal_length{},
      quan::meta::components::of_reciprocal_mass{},
      quan::meta::components::of_reciprocal_time{},
      quan::meta::components::of_resistance{},
      quan::meta::components::of_resistivity{},
      quan::meta::components::of_specific_entropy{},
      quan::meta::components::of_substance{},
      quan::meta::components::of_temperature{},
      quan::meta::components::of_thermal_conductivity{},
      quan::meta::components::of_thermal_diffusivity{},
      quan::meta::components::of_thermal_insulance{},
      quan::meta::components::of_thermal_resistance{},
      quan::meta::components::of_thermal_resistivity{},
      quan::meta::components::of_time{},
      quan::meta::components::of_torque{},
      quan::meta::components::of_velocity{},
      quan::meta::components::of_voltage{},
      quan::meta::components::of_volume_flow{},
      quan::meta::components::of_volume{},
      quan::meta::components::of_volume_per_energy{}
   );
}

#if 0
auto get_si_units_list()
{
  using quan::meta::si_unit;
  return quan::fusion::make_vector(
         si_unit::yotta{},
         si_unit::zetta{},
         si_unit::exa{},
         si_unit::peta{},
         si_unit::tera{},
         si_unit::giga{},
         si_unit::mega{},
         si_unit::kilo{},
         si_unit::hecto{},
         si_unit::deka{},
         si_unit::none{},
         si_unit::deci{},
         si_unit::centi{},
         si_unit::milli{},
         si_unit::micro{},
         si_unit::nano{},
         si_unit::pico{},
         si_unit::femto{},
         si_unit::atto{},
         si_unit::zepto{},
         si_unit::yocto{}
      ); 
}
#endif

/*
   we input an SiUnit and a quantity traits
   the si_unit is adjusted
   The resulting type may be undefined
   or an si conversion_factor
*/
  struct get_adjusted_si_unit{
    template <typename SiUnit, typename OfQ>
     struct apply{
         typedef typename quan::meta::get_multiplier<SiUnit>::type multiplier;
         static_assert(quan::meta::eq_one<multiplier>::value,"invalid multiplier - not si unit");
         typedef typename quan::meta::get_exponent<SiUnit>::type exponent;
         static_assert(quan::meta::denominator<exponent>::value == 1,"invalid exponent - not integer");

         static constexpr int64_t extent = OfQ::extent;
         static constexpr int64_t prefix_offset = OfQ::prefix_offset;

         typedef quan::detail::get_adjusted_prefix<extent, prefix_offset> adjust_fun;
         // the si_unit exponent
         static constexpr int64_t si_exponent_value = quan::meta::numerator<exponent>::value;
         // check for clean divison
         static constexpr bool divison_clean = si_exponent_value % extent == 0;

         // if clean divison then evaluate the adjusted prefix
         typedef typename quan::meta::eval_if_c<
            divison_clean,
            typename adjust_fun:: template apply<si_exponent_value>,
            quan::undefined
         >::type adjusted_exponent;
         // finlly if its valid create a conversion factor
         typedef typename quan::meta::if_<
            std::is_same<quan::undefined,adjusted_exponent>,
            quan::undefined,
            quan::meta::conversion_factor<
               adjusted_exponent
            >
         >::type type;
     };
  };

// we have pretested the SiUnit so it is good
//template <typename SiUnit, typename OfQ>
//void output_unit(std::ostream & out)
//{
//     std::string const quantity_name = OfQ::abstract_quantity_name();
//     std::string const quantity_symbol = OfQ:: template unprefixed_symbol<char>();
//     
//      typedef typename get_adjusted_si_unit::apply<
//         SiUnit,OfQ
//      >::type adjusted_si_unit;
//     std::string const si_unit_name = quan::meta::si_unit::template prefix<SiUnit>::name();
//     
//     std::string const si_unit_prefix = quan::meta::si_unit::template prefix<adjusted_si_unit>:: template symbol<char>();
//     out << "   struct " << si_unit_prefix << quantity_symbol << " :  quan::meta::unit<\n";
//     out << "      quan::meta::components::of_" << quantity_name << "::abstract_quantity,\n";
//     out << "      typename quan::meta::si_unit::" << ((si_unit_name!="")?si_unit_name:"none") << " // coherent_exponent " << SiUnit::exponent::numerator << '\n';
//     out << "   >{};\n";
//
//}

// we have pretested the SiUnit so it is good
template <typename SiUnit, typename OfQ>
void output_typedef(std::ostream & out)
{
   typedef typename get_adjusted_si_unit::apply<
      SiUnit,OfQ
   >::type adjusted_si_unit;
   static_assert(! std::is_same<adjusted_si_unit, quan::undefined>::value,"wtf");
   std::string const quantity_name = OfQ::abstract_quantity_name();
   std::string const quantity_symbol = OfQ:: template unprefixed_symbol<char>();
   std::string const si_unit_name = quan::meta::si_unit:: template prefix<SiUnit>::name();
   std::string const si_unit_prefix = quan::meta::si_unit:: template prefix<adjusted_si_unit>:: template symbol<char>();

   out << "      typedef quan::fixed_quantity<\n";
   out << "         quan::of_" << quantity_name << "::" <<  si_unit_prefix << quantity_symbol << ",\n";
   out << "         Value_type\n";
   out << "      > " <<  si_unit_prefix << quantity_symbol << ";\n";
}

template <typename OfQ>
struct output_typedef_t{

   typedef output_typedef_t type;
   output_typedef_t(std::ostream & out):m_out{out}{}

   std::ostream & m_out;
   template <typename SiUnit>
   void operator() (SiUnit const &) const
   {
      output_typedef<SiUnit,OfQ>(m_out);
   }
  
};

struct null_fun{
   typedef null_fun type;
  
   null_fun(std::ostream & out):m_out{out}{}
    std::ostream & m_out;
   template <typename SiUnit>
   void operator()(SiUnit const & )const 
   {
      typedef typename quan::meta::get_exponent<SiUnit>::type exponent;
      static constexpr int64_t value = quan::meta::numerator<exponent>::value;
      static_assert( quan::meta::denominator<exponent>::value == 1,"exponent is not integer");
      m_out << "      // coherent_exponent :" << static_cast<int>( value) << " -> N/A\n";
   }
};

template <typename OfQ>
struct output_unit_t{
   typedef output_unit_t type;
   output_unit_t(std::ostream & out):m_out{out}{}

   std::ostream & m_out;
   template <typename SiUnit>
   void operator() (SiUnit const &) const
   {
      //output_unit<SiUnit,OfQ>(m_out);
      std::string const quantity_name = OfQ::abstract_quantity_name();
     std::string const quantity_symbol = OfQ:: template unprefixed_symbol<char>();
     
      typedef typename get_adjusted_si_unit::apply<
         SiUnit,OfQ
      >::type adjusted_si_unit;
     static_assert(! std::is_same<adjusted_si_unit, quan::undefined>::value,"wtf");
     std::string const si_unit_name = quan::meta::si_unit::template prefix<SiUnit>::name();
     
     std::string const si_unit_prefix = quan::meta::si_unit::template prefix<adjusted_si_unit>:: template symbol<char>();
     m_out << "   struct " << si_unit_prefix << quantity_symbol << " :  quan::meta::unit<\n";
     m_out << "      quan::meta::components::of_" << quantity_name << "::abstract_quantity,\n";
     m_out << "      typename quan::meta::si_unit::" << ((si_unit_name!="")?si_unit_name:"none") << " // coherent_exponent " << SiUnit::exponent::numerator << '\n';
     m_out << "   >{};\n";

   }
  
};

/*
 proceed if the unit is good and call F on u
  else do nothing with u
*/
template <typename OfQ, template <typename> class F >
struct output_unit_if_t{
   output_unit_if_t(std::ostream & out):m_out{out}{}

   std::ostream & m_out;
   // pass in an integral_constant
   template <typename IntegralConstant>
   void operator()(IntegralConstant const & I)const
   {
      typedef quan::meta::conversion_factor<
         quan::meta::rational<IntegralConstant::value>
      > si_unit;

      typedef typename get_adjusted_si_unit::apply<
        si_unit,OfQ
      >::type adjusted_si_unit;

      typedef typename quan::meta::eval_if<
         quan::meta::or_<
            std::is_same<adjusted_si_unit, quan::undefined>,
            quan::meta::bool_<quan::meta::si_unit::template prefix<adjusted_si_unit>::value == false>,
            quan::meta::bool_<quan::meta::si_unit::template prefix<si_unit>::value == false>
         >,
         null_fun,
         F<OfQ>
      >::type fun;
      fun{m_out}(si_unit{});
   }

};

struct output_quantity{
   output_quantity(std::ostream & out) : m_out{out}{}
   std::ostream & m_out;
   template <typename Q>
   void operator()(Q const &)const
   {
   
      quan::fun::integer_range<-27,27> si_exp_range;
      std::string const quantity_name = Q::abstract_quantity_name();
      m_out << "struct of_" << quantity_name <<"{\n";
      quan::fun::for_each(si_exp_range,output_unit_if_t<Q, output_unit_t >{m_out});
      m_out << "};\n";
      m_out << "----------------------------------------\n\n";
      quan::fun::for_each(si_exp_range,output_unit_if_t<Q,output_typedef_t >{m_out});
      m_out << "------------###############-------------\n\n";
   }
};


#if 0
struct si_fun{
   template <typename T>
   void operator()(T t)const
   { 
    std::cout << quan::meta::si_unit::prefix<T>:: name() <<'\n';
    std::cout << quan::meta::si_unit::prefix<T>:: template symbol<char>() <<'\n';
   }
};
#endif
#if 1
int main()
{
  // output_unit_if_t<quan::meta::components::of_area,output_unit_t>{std::cout}(quan::meta::si_unit::micro{});
   std::ofstream out("output.txt");
   output_quantity{out}(quan::meta::components::of_mass{});

/*
   typedef quan::meta::if_<
      quan::meta::si_unit::prefix<si_unit>,
      si_fun,
      null_fun
   >::type fun;

   fun{}(si_unit{});
 */ 
  
}

#else
int main()
{
   std::ofstream out("output.txt");

   quan::fun::for_each(get_quantities_list(),output_quantity<output_unit_t,output_typedef_t>{out});
}
#endif
