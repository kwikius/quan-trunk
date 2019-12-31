
#ifndef QUAN_SMALL_RATIONAL_HPP_INCLUDED
#define QUAN_SMALL_RATIONAL_HPP_INCLUDED
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
// copyright Andy Little 2008 
#include <quan/config.hpp>
#include <stdexcept>
#include <cassert>
#include <limits>
#include <string>
#include <sstream>

#include <quan/asm/nibble.hpp>
#include <quan/meta/rational.hpp>
#include <cstdint>
namespace quan{

   struct small_rational{
      typedef int16_t   int16;
      typedef int32_t   int32;
 //  private:
      static int32 range_check(int32 v)
      {
         int32 abs_v = v >=0 ? v : -v;
         if( abs_v > std::numeric_limits<int16>::max()){
#ifndef QUAN_NO_EXCEPTIONS
            throw std::logic_error("overflow in small_rational math");
#else
    // flag error somehow..
         return -1;
#endif
         }
         return v;
      }
   
   public:

      small_rational():m_nume(0),m_denom(1){}
      small_rational(int16 nume, int16 denom =1)
       :  m_nume(range_check(nume)),m_denom(range_check(denom))
      {
         this->normalise();
      }
#ifndef QUAN_STM32_CONFIG_HPP
      std::string to_string() const
      {
            std::ostringstream ostr;
            ostr << this->nume();
            int32 d = this->denom();
            if( d != 1){
               ostr << "/" << this->denom();
            }
            return ostr.str();
      }
#endif
      template <int N, int D>
      small_rational(quan::meta::rational<N,D> const & in)
      :m_nume(range_check(N)),m_denom(range_check(D)){this->normalise();}
      int16 nume() const{return m_nume;}
      int16 denom() const {return m_denom;}

      small_rational & operator += (small_rational const & rhs)
      {
         int32 n1 = range_check(static_cast<int32>(this->nume()) * static_cast<int32>(rhs.denom()) );
         int32 n2 = range_check(static_cast<int32>(rhs.nume()) * static_cast<int32>(this->denom()));
         int32 n3 = range_check(n1 + n2);
         int32 d = range_check(static_cast<int32>(this->denom()) * static_cast<int32>(rhs.denom()));
 
         this->m_nume = static_cast<int16>(n3);
         this->m_denom = static_cast<int16>(d);

         this->normalise();
         return *this;
      }

      small_rational operator+(small_rational const & rhs) const
      {
         small_rational result = *this;
         return result += rhs;
      }

      small_rational & operator -= (small_rational const & rhs)
      {
         int32 n1 = range_check(static_cast<int32>(this->nume()) * static_cast<int32>(rhs.denom()) );
         int32 n2 = range_check(static_cast<int32>(rhs.nume()) * static_cast<int32>(this->denom()));
         int32 n3 = range_check(n1 - n2);
         int32 d = range_check(static_cast<int32>(this->denom()) * static_cast<int32>(rhs.denom()));

         this->m_nume = static_cast<int16>(n3);
         this->m_denom = static_cast<int16>(d);

         this->normalise();
         return *this;
      }
      void negate()
      {
         this->m_nume *= -1;
      }
      small_rational operator -() const
      {
         return small_rational( -this->nume(),this->denom() );
      }
      small_rational operator +() const
      {
         return *this;
      }
      small_rational operator-(small_rational const & rhs) const
      {
         small_rational result = *this;
         return result -= rhs;
      }

      small_rational & operator *= (small_rational const & rhs)
      {
         int32 n = range_check( static_cast<int32>(this->nume()) * static_cast<int32>(rhs.nume()) );
         int32 d = range_check( static_cast<int32>(this->denom()) * static_cast<int32>(rhs.denom()) );
   
         this->m_nume = static_cast<int16>(n);
         this->m_denom = static_cast<int16>(d);

         this->normalise();
         return *this;
      }

      small_rational operator*(small_rational const & rhs) const
      {
         small_rational result = *this;
         return result *= rhs;
      }
      small_rational & operator /= (small_rational const & rhs)
      {
         int32 n = range_check( static_cast<int32>(this->nume()) * static_cast<int32>(rhs.denom()) );
         int32 d = range_check( static_cast<int32>(this->denom()) * static_cast<int32>(rhs.nume()) );
         this->m_nume = static_cast<int16>(n);
         this->m_denom = static_cast<int16>(d);

         this->normalise();
         return *this;
      }
      small_rational operator/(small_rational const & rhs)const
      {
         small_rational result = *this;
         return result /= rhs;
      }

      bool operator < (small_rational const & rhs)const
      {
         int32 v1 = static_cast<int32>(this->nume()) * static_cast<int32>(rhs.denom());
         int32 v2 = static_cast<int32>(rhs.nume()) * static_cast<int32>(this->denom());
         return v1 < v2;
      } 

      bool operator <= (small_rational const & rhs)const
      {
         int32 v1 = static_cast<int32>(this->nume()) * static_cast<int32>(rhs.denom());
         int32 v2 = static_cast<int32>(rhs.nume()) * static_cast<int32>(this->denom());
         return v1 <= v2;
      } 
      
      bool operator == (small_rational const & rhs)const
      {
         return (this->nume() == rhs.nume()) && ( this->denom() == rhs.denom() );
      } 

      bool operator != (small_rational const & rhs)const
      {
         return (this->nume() != rhs.nume()) || ( this->denom() != rhs.denom() );
      } 

      bool operator >= (small_rational const & rhs)const
      {
         int32 v1 = static_cast<int32>(this->nume()) * static_cast<int32>(rhs.denom());
         int32 v2 = static_cast<int32>(rhs.nume()) * static_cast<int32>(this->denom());
         return v1 >= v2;
      } 

      bool operator > (small_rational const & rhs)const
      {
         int32 v1 = static_cast<int32>(this->nume()) * static_cast<int32>(rhs.denom());
         int32 v2 = static_cast<int32>(rhs.nume()) * static_cast<int32>(this->denom());
         return v1 > v2;
      } 

      bool is_integral() const
      {
         return this->denom() == 1;
      }

      bool eq_one() const
      {
         return (this->nume() == 1) && (this->denom() == 1);
      }

      bool eq_zero() const
      {
         return this->nume() == 0;
      }

    static  int16 gcd(int16 n, int16 m)
      {
         if (n < 0)n = -n;
         if (m < 0)m = -m;

         for(;;) {
            if(m == 0)return n;
            n %= m;
            if(n == 0 )return m;
            m %= n;
         }
      }
   private:
         int16 m_nume;
         int16 m_denom;
        
      void normalise()
      {

         if( m_denom ==0){
#ifndef QUAN_NO_EXCEPTIONS
            throw std::runtime_error("small_rational 0 denom");
#else
        m_denom = 1;
        m_nume = INT16_MAX;
#endif
         }
         if (m_nume == 0) {
            if ( m_denom != 1) {
               m_denom = static_cast<int16>(1);
               return;
            }
         }else {
            if (m_denom < 0) {
               m_nume = -m_nume;
               m_denom = -m_denom;
            }
         }
         if ( m_denom != 1){
            int16 g = small_rational::gcd(m_nume, m_denom);
            assert(g > 0);
            if( g != 1){ 
               m_nume /= g;
               m_denom /= g;
            }
         }
      }
   };

   inline 
   small_rational 
   abs( small_rational const & in)
   {
      return small_rational{ 
         static_cast<int16_t>(in.nume() >= 0?in.nume():-in.nume()),
         static_cast<int16_t>(in.denom() >= 0?in.denom():-in.denom())
      };
   }
}

#endif
