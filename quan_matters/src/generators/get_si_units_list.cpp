


#include <quan/meta/si_units.hpp>
#include <quan/fusion/make_vector.hpp>

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
