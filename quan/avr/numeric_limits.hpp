#ifndef QUAN_AVR_NUMERIC_LIMITS_HPP_INCLUDED
#define QUAN_AVR_NUMERIC_LIMITS_HPP_INCLUDED

#ifndef QUAN_AVR_NO_CPP_STDLIB
#error only for avr
#endif
#include <quan/where.hpp>

/*
 Copyright (c) 2007 - 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/
/*
 add stuff as needed here 

*/

namespace quan{
  namespace meta{
    namespace detail{
      
       template <typename T, typename Where = void>
       struct numeric_limits;

       template<typename T> 
		 struct numeric_limits<T, typename quan::where_<std::is_integral<T> >::type >{
            static const bool is_signed = std::is_signed<T>::value;
       };
      
    }
}}
  
namespace std{

  template <typename T>
  struct numeric_limits : quan::meta::detail::numeric_limits<T>{};
      
}


#endif // QUAN_AVR_NUMERIC_LIMITS_HPP_INCLUDED
