#include <quan/detail/ll_bigint.hpp>

#include <quan/meta/digit_to_char.hpp>

using quan::detail::ll_bigint;

template <int N>
std::string ll_bigint::to_string_base()const
{
   if ( this->eq_zero()){
     return "0";
   }

   if ( this->eq_one()){
     return "1";
   }

   ll_bigint const divis = N ;
   ll_bigint copy = *this;

   bool negative_sign = ( copy.is_negative())
    ?( copy.negate(), true )
    :false;
   std::string res;
   while(! copy.eq_zero()){
      ll_bigint divres;
      ll_bigint modres;
      ll_bigint::div_mod(copy,divis,divres,modres);
      copy = divres; 
      std::string t;
      // could assert that modres.m_rep.at(0) < N
      t = quan::meta::digit_to_char<N>{}(modres.m_rep.at(0));
      res = t + res;
   }
   if (negative_sign){
    res = "-" + res;
   }
   return res;

}

template std::string ll_bigint::to_string_base<2>()const;
template std::string ll_bigint::to_string_base<16>()const;
template std::string ll_bigint::to_string_base<10>()const;


