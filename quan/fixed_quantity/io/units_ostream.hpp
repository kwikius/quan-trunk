#ifndef QUAN_T1_QUANTITY_UNITS_OSTREAM_HPP_INCLUDED
#define QUAN_T1_QUANTITY_UNITS_OSTREAM_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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

/*
    default stream output of fixed_quantity.
    defines std::ostream& operator << (std::ostream& ,
         physical_quantity_basic_units_out<...> );
    where physical_quantity_basic_units_out<...>
    is the dummy object returned by invoking pq.units()

   TODO add wide stream functionality
*/
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <locale>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#else
#include <quan/avr/iostream_dummy.hpp>
#include <quan/avr/locale_dummy.hpp>
#include <quan/avr/string_dummy.hpp>
extern "C"{
   #include <string.h>
}

#endif

#include <quan/quantity_traits.hpp>
#include <quan/meta/rational.hpp>
#include <quan/fixed_quantity/io/detail/put_rational.hpp>
#include <quan/fixed_quantity/io/units_out.hpp>
#include <quan/fixed_quantity/operations/power_root.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/neq.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/bool.hpp>

namespace quan{

// This ostream operator << picks up the default_fixed_quantity_units_out class
// returned by pq.units(). The general idea is to use the p.units() form for
// output of the basic units (and any scaling). The units(pq) form is meant
// for overloading on  eg for a quan::force::kgf pq;
// pq.units() gives  "[kg.m.s-2 * 9.8XX]"
// units(pq) gives   "kgf"
// this is the pq.units() format definition

    namespace detail{
       /* template <typename Rat>
        struct rational_not_zero : quan::meta::bool_<
            (Rat::numerator!=0)
        >{};*/

        template <bool C>
        struct output_if_c;

        template<> struct output_if_c<true>{

            template <typename Char>
            bool operator() ( std::basic_ostream<Char> & os, std::string const & str)const
            {
               typedef std::ctype<Char> ct;
#ifndef QUAN_AVR_NO_CPP_STDLIB
               auto & facet = std::use_facet<ct>(std::locale());
#else
               ct& facet = std::use_facet<ct>(std::locale());
#endif
               std::basic_string<Char> str1;
               for ( std::size_t i = 0; i < str.length();++i){
                str1 += facet.widen(str[i]);
               }
               os << str1;
               return true;
            }

            template <typename Char>
            bool operator() ( std::basic_ostream<Char> & os, char ch)const
            {
               typedef std::ctype<Char> ct;
#ifndef QUAN_AVR_NO_CPP_STDLIB
               auto & facet = std::use_facet<ct>(std::locale());
#else
               ct& facet = std::use_facet<ct>(std::locale());
#endif
               os << facet.widen(ch);
               return true;
            }
         };

         template<>struct output_if_c<false>{
            
            template <typename CharType>
            bool operator() ( std::basic_ostream<CharType> & , std::string const & )const
            {
               return false;
            }
            template <typename CharType>
            bool operator() ( std::basic_ostream<CharType> & , CharType)const
            {return false;}
            
         };  

        template <typename Cond>
        struct output_if :output_if_c<(Cond::value)>{};      
    }

    template<
        typename CharType,
        typename StaticUnit
    >
    inline std::basic_ostream<CharType>& 
    operator << 
        (std::basic_ostream<CharType>& os,
            default_fixed_quantity_unit< 
                StaticUnit
            >   )
    {
        typedef typename quan::meta::get_length_dimension<StaticUnit>::type p_length;
        typedef typename quan::meta::get_time_dimension<StaticUnit>::type  p_time;
        typedef typename quan::meta::get_mass_dimension<StaticUnit>::type p_mass;
        typedef typename quan::meta::get_temperature_dimension<StaticUnit>::type p_temperature;
        typedef typename quan::meta::get_current_dimension<StaticUnit>::type p_current;
        typedef typename quan::meta::get_substance_dimension<StaticUnit>::type p_substance;
        typedef typename quan::meta::get_intensity_dimension<StaticUnit>::type p_intensity;

        typedef quan::meta::neq_zero<p_length> has_length;
        typedef quan::meta::neq_zero<p_time> has_time;
        typedef quan::meta::neq_zero<p_mass> has_mass;
        typedef quan::meta::neq_zero<p_temperature> has_temperature;
        typedef quan::meta::neq_zero<p_current> has_current;
        typedef quan::meta::neq_zero<p_substance> has_substance;
        typedef quan::meta::neq_zero<p_intensity> has_intensity;
      
        typedef typename quan::meta::get_conversion_factor<StaticUnit>::type conv_factor;
        typedef typename quan::meta::get_exponent<conv_factor>::type exponent;
        typedef typename quan::meta::get_multiplier<conv_factor>::type multiplier;

        // fractional exponent or non 1 incoherent multiplier 
        typedef typename quan::meta::or_<
            quan::meta::neq_one< multiplier>,
            quan::meta::not_<
                quan::meta::is_integer<exponent>
            >
        >::type has_brackets;


        std::basic_ostringstream<CharType> ost;
        detail::output_if<has_brackets>()( os,'[');

        if(detail::output_if<has_mass>()(ost,"kg")){
            detail::put_rational<p_mass>(ost);
            detail::output_if<
               quan::meta::or_<
                  quan::meta::or_<has_length,quan::meta::or_<has_time,has_temperature> >,
                  quan::meta::or_<has_current,quan::meta::or_<has_substance,has_intensity> >
               >
            >()(ost,'.');
        }
        if(detail::output_if<has_length>()(ost,'m')){
            detail::put_rational<p_length>(ost);
            detail::output_if<
               quan::meta::or_<
                  quan::meta::or_<has_time,has_temperature>,
                  quan::meta::or_<has_current,quan::meta::or_<has_substance,has_intensity> >
               >
            >()(ost,'.');
        }
        if(detail::output_if<has_time>()(ost,'s')){
            detail::put_rational<p_time>(ost);
            detail::output_if<
               quan::meta::or_<
                  quan::meta::or_<has_temperature,has_current>,
                  quan::meta::or_<has_substance,has_intensity>
               >
            >()(ost,'.');
        }
        if(detail::output_if<has_temperature>()(ost,'K')){
            detail::put_rational<p_temperature>(ost);
            detail::output_if<
               quan::meta::or_<has_current,quan::meta::or_<has_substance,has_intensity> >
            >()(ost,'.');
        }
        if(detail::output_if<has_current>()(ost,'A')){
            detail::put_rational<p_current>(ost);
            detail::output_if<
               quan::meta::or_<has_substance,has_intensity>
            >()(ost,'.');
        }
        if(detail::output_if<has_substance>()(ost,"mol")){
            detail::put_rational<p_substance>(ost);
            detail::output_if<has_intensity>()(ost,'.');
        }
        if(detail::output_if<has_intensity>()(ost,"cd")){
            detail::put_rational<p_intensity>(ost);
        }
        if (detail::output_if<
               quan::meta::neq_one<multiplier>
            > () (ost," * ")){

            ost << '(' << quan::meta::numerator<exponent>::value
               << '/' << quan::meta::denominator<exponent>::value << ')';
           /* double mux =
                (static_cast<double>(quan::meta::numerator<multiplier>::value) 
                / (quan::meta::denominator<multiplier>::value))
            *
               quan::pow<
                     quan::meta::numerator<exponent>::value,
                     quan::meta::denominator<exponent>::value
                >(10.);*/
// use format spec here
           // ost << mux;
      } else {
         // if it isnt 0
         if( int64_t rt_exponent = quan::meta::numerator<exponent>::value){
            if( detail::output_if<
            // neat exponent
               quan::meta::is_integer<exponent> >() (ost, " * 1e")){
               ost << rt_exponent; 
            } else {
               // messy exponent
               ost << " * 1e" << '(' << rt_exponent << '/' << quan::meta::denominator<exponent>::value << ')';
               // use format spec here ?

               /*<<   quan::pow<
               quan::meta::numerator<exponent>::value,
               quan::meta::denominator<exponent>::value
               >(10.) ;*/
            } 
          }
      }
       detail::output_if<has_brackets>()(ost , ']');
       os << ost.str(); 
       return os;
   }
    
}//quan

#endif

