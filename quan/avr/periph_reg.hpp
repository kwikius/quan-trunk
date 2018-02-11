#ifndef QUAN_AVR_PERIPH_REG_HPP_INCLUDED
#define QUAN_AVR_PERIPH_REG_HPP_INCLUDED

/*
 Copyright (c) 2013 Andy Little

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

#include <quan/where.hpp>
#include <quan/meta/is_single_bit.hpp>
#include <quan/meta/bitpos.hpp>
#include <quan/is_model_of.hpp>
#include <quan/bit.hpp>

#include <quan/meta/bool/true.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/bool.hpp>
#ifdef QUAN_AVR_NO_CPP_STDLIB
#include <quan/std/tr1/is_base_of.hpp>
#else
#include <type_traits>
#endif



namespace quan{ namespace avr{

   struct PeriphReg; // Archetype

   // base class for periph reg<address>, used as default method to see if T is a PeriphReg
   template <typename T, typename Where = void>
   struct periph_reg_base;

   template <typename T> struct periph_reg_base<T, typename quan::where_c<(sizeof( T ) == 1)>::type>{
      
   protected :
      volatile T m_value;
   };

}}

namespace quan { namespace impl{

   // Any class derived from periph_reg_base is a model of PeripReg Archetype

   template< typename T>
   struct is_model_of_impl<
        quan::avr::PeriphReg,T,
        typename quan::where_<
            std::is_base_of<quan::avr::periph_reg_base<typename T::value_type>,T >
        >::type
   >
   : quan::meta::true_{};

}}

namespace quan{ namespace avr{

   template<typename Module, uint8_t Offset, typename T = typename Module::value_type>
   struct periph_reg : periph_reg_base<T>{
      static_assert(sizeof(periph_reg_base<T>) == 1,"invalid periph reg");
      typedef Module module_type;
      typedef T value_type;
      static constexpr T address_offset = Offset;
      static constexpr T address =  module_type::address + address_offset;

      typedef periph_reg type;
  
      using periph_reg_base<T>::m_value;

      value_type get()const
      {
         return m_value;
      }

      void set(value_type v)
      {
            m_value = v;
      }

      template <uint8_t Bit> void setbit()
      {
          m_value |= quan::bit<value_type>(Bit);
      }

     
      template <uint8_t Bit> void clearbit()
      {
          m_value &= ~quan::bit<value_type>(Bit);
      }

      template <uint8_t Bit> bool getbit() const
      {
          return ( m_value & quan::bit<value_type>(Bit) ) != 0;
      }

      template <value_type Value> typename quan::where_<
				quan::meta::bool_<Value!=0> 
	   >::type or_equals()
      {
        m_value |= Value;
      }

      template <value_type Value> typename quan::where_<
				quan::meta::bool_<Value==0> 
	   >::type or_equals()
      {
        // nothing to do
      }

      template <value_type Value> 
      typename quan::where_<
				quan::meta::bool_<(~Value)!=0> 
      >::type and_equals()
      {
           m_value &= Value;
      }

      template <value_type Value> typename quan::where_<
			quan::meta::bool_<(~Value)==0> 
		>::type and_equals()
      {
        //nothing to do  
      }

// where there is a read and write even of one bit, there is no advantage to bitbanding
    template <value_type V> typename quan::where_<
      quan::meta::bool_<V!=0> 
     >::type xor_equals() 
     {
         m_value ^= V;
     }

      template <value_type V> typename quan::where_<
			quan::meta::bool_<V==0> 
		>::type xor_equals()
      {
       // static_assert (false, "false");
      }

     periph_reg& operator =(value_type v)
     {  
         m_value = v;
         return  *this;
     }

     periph_reg& operator |=(value_type v)
     {  
         m_value |= v;
         return  *this;
     }

     periph_reg& operator &=(value_type v)
     {  
         m_value &= v;
         return  *this;
     }
  
     private:

       periph_reg() = delete;
       periph_reg(periph_reg const &) = delete;
       periph_reg & operator = (periph_reg const &) = delete;

   };

   template<typename Module, uint32_t Offset, typename T = typename Module::value_type>
   inline typename Module::value_type operator &( periph_reg<Module,Offset,T> const & reg, typename Module::value_type val)
   {
         return reg.get() & val;
   }

   template<typename Module, uint32_t Offset, typename T = typename Module::value_type>
   inline typename Module::value_type operator |( periph_reg<Module,Offset,T> const & reg, typename Module::value_type val)
   {
         return reg.get() | val;
   }

}}

#endif // QUAN_PERIPH_REG_HPP_INCLUDED

