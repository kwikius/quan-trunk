#ifndef QUAN_AVR_NUMERIC_LIMITS_HPP_INCLUDED
#define QUAN_AVR_NUMERIC_LIMITS_HPP_INCLUDED

#include <type_traits>
#include <quan/where.hpp>
#include <type_traits>

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
