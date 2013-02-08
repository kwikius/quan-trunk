#include <quan/detail/ll_bigint.hpp>
#include <quan/meta/char_to_digit.hpp>
#include <stdexcept>
using quan::detail::ll_bigint;

template <int N>
void ll_bigint::from_string_base(std::string const & str)
{
   *this = 0;

   std::size_t const len = str.length();
   if ( len == 0) {
     return;
   }
   ll_bigint const mult = N;
   bool minus_sign = false;
   std::size_t start = 0;
   if ( str.at(0) == '-'){
     minus_sign = true;
     start = 1;
   }
   for (size_type i = start; i < len; ++i){
      if ( i != start){
        this->mul_eq(mult);
      } 
      int digit = quan::meta::character_to_digit<N>{}(str.at(i));
      if ( digit == -1 ) {
         throw std::runtime_error("invalid integer digit");
      }
      this->plus_eq(digit);
   }
   if ( minus_sign){
     this->negate();
   }

}

template 
void ll_bigint::from_string_base<10>(std::string const & str);

template 
void ll_bigint::from_string_base<16>(std::string const & str);

template 
void ll_bigint::from_string_base<2>(std::string const & str);



