
#ifndef QUAN_BIG_RATIONAL_HPP_INCLUDED
#define QUAN_BIG_RATIONAL_HPP_INCLUDED
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
#include <stdexcept>
#include <cassert>
#include <quan/bigint.hpp>
#include <quan/asm/nibble.hpp>

namespace quan{
   struct big_rational;
}

namespace quan{ namespace meta{

   namespace impl{
      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::plus, quan::big_rational
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::plus, quan::bigint
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::plus, quan::big_rational
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::minus, quan::big_rational
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::minus, quan::bigint
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::minus, quan::big_rational
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::times, quan::big_rational
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::times, quan::bigint
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::times, quan::big_rational
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::divides, quan::big_rational
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::divides, quan::bigint
      >{
         typedef quan::big_rational type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::divides, quan::big_rational
      >{
         typedef quan::big_rational type;
      };

   //comp
      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::less, quan::big_rational
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::less, quan::bigint
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::less, quan::big_rational
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::less_equal, quan::big_rational
      >{
         typedef bool type;
      };

       template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::less_equal, quan::bigint
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::less_equal, quan::big_rational
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::equal_to, quan::big_rational
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::equal_to, quan::bigint
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::equal_to, quan::big_rational
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::not_equal_to, quan::big_rational
      >{
         typedef bool type;
      };

       template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::not_equal_to, quan::bigint
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::not_equal_to, quan::big_rational
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::greater_equal, quan::big_rational
      >{
         typedef bool type;
      };

       template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::greater_equal, quan::bigint
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::greater_equal, quan::big_rational
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::greater, quan::big_rational
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::big_rational,quan::meta::greater, quan::bigint
      >{
         typedef bool type;
      };

      template <>
      struct binary_op_impl<
         quan::bigint,quan::meta::greater, quan::big_rational
      >{
         typedef bool type;
      };
   } // impl
}}


namespace quan{

   struct big_rational{
      typedef bigint int_type;
   
   public:

      std::string to_string() const
      {
            if ( this->denom().eq_one()){
               return this->nume().to_string() ;
            }else{
               return this->nume().to_string() + "/" + this->denom().to_string();
            }
      }
      big_rational(): m_nume(0),m_denom(1)
      {
         //m_denom.m_rep.at(0) = 1;
      }
      big_rational(std::string const & nume_in, std::string const & denom_in)
      : m_nume(nume_in),m_denom(denom_in)
      {
         this->normalise();
      }
      template<int L, int R>
      big_rational(char const(& nume_in)[L], char const(& denom_in)[R])
      : m_nume(nume_in),m_denom(denom_in)
      {
         this->normalise();
      }
      template<int L>
      big_rational(char const(& nume_in)[L], std::string const & denom_in)
      : m_nume(nume_in),m_denom(denom_in)
      {
         this->normalise();
      }
       template<int R>
      big_rational(std::string const & nume_in, char const(& denom_in)[R])
      : m_nume(nume_in),m_denom(denom_in)
      {
         this->normalise();
      }
      big_rational(int_type const & n, int_type const & d)
      :m_nume(n),m_denom(d)
      {
          this->normalise();
      }

      big_rational(int_type const & n)
      :m_nume(n),m_denom(1){}

      int_type const & nume() const {return m_nume;}
      int_type const & denom() const {return m_denom;}

      big_rational & operator += (big_rational const & rhs)
      {
         int_type n = this->m_nume * rhs.denom();
         n += rhs.nume() * this->denom();
         this->m_nume.move(n);
         this->m_denom *= rhs.denom();
         this->normalise();
         return *this;
      }

      big_rational & operator -= (big_rational const & rhs)
      {
         int_type n = this->m_nume * rhs.denom();
         n -= rhs.nume() * this->denom();
         this->m_nume.move(n);
         this->m_denom *= rhs.denom();
         this->normalise();
         return *this;
      }

      big_rational & operator *= (big_rational const & rhs)
      {
         this->m_nume *= rhs.nume();
         this->m_denom *=rhs.denom();
         this->normalise();
         return *this;
      }
      
      big_rational & operator /= (big_rational const & rhs)
      {
         int_type n = this->nume() * rhs.denom();
         this->m_denom *= rhs.nume();
         this->m_nume.move(n);
         this->normalise();
         return *this;
      }
      
    /*  bool operator < (big_rational const & rhs)const
      {
         int_type v1 = this->nume() * rhs.denom();
         int_type v2 = rhs.nume() * this->denom();
         return v1 < v2;
      } 

      bool operator <= (big_rational const & rhs)const
      {
         int_type v1 = this->nume() * rhs.denom();
         int_type v2 = rhs.nume() * this->denom();
         return v1 <= v2;
      } 
      
      bool operator == (big_rational const & rhs)const
      {
         return (this->nume() == rhs.nume()) && ( this->denom() == rhs.denom() );
      } 

      bool operator != (big_rational const & rhs)const
      {
         return (this->nume() != rhs.nume()) || ( this->denom() != rhs.denom() );
      } 
      bool operator >= (big_rational const & rhs)const
      {
         int_type v1 = this->nume() * rhs.denom();
         int_type v2 = rhs.nume() * this->denom();
         return v1 >= v2;
      } 
 

      bool operator > (big_rational const & rhs)const
      {
         int_type v1 = this->nume() * rhs.denom();
         int_type v2 = rhs.nume() * this->denom();
         return v1 > v2;
      } 
  */
      bool is_integral() const
      {
         return this->m_denom.eq_one();
      }

      bool eq_one() const
      {
         return (this->m_nume.eq_one()) && (this->m_denom.eq_one());
      }

      bool eq_zero() const
      {
         return this->m_nume.eq_zero();
      }

      double to_double()const
      {
         return this->m_nume.to_double() / this->m_denom.to_double();
      }

   private:
         int_type m_nume;
         int_type m_denom;
         
      void normalise()
      {
#if defined QUAN_NO_EXCEPTIONS
      assert(m_denom.eq_zero() == false);
#else
         if( m_denom.eq_zero()){

            throw std::runtime_error("big_rational 0 denom");
         }
#endif
         if (m_nume.eq_zero()) {
            m_denom = 1;
            return;
         }
         bool sign_change = false;
         if (m_denom.lt_zero()) {
            if(m_nume.lt_zero()){ // neg nume neg denom
               m_nume.negate();
               m_denom.negate();
            }else{              // pos nume neg denom
               m_denom.negate();
               sign_change = true;
            }
         }else{
            if (m_nume.lt_zero()){  // neg nume pos denom
               m_nume.negate();
               sign_change = true;
            } else{
                                    // pos nume pos denom
            }
         }
         int_type g = bigint::gcd(m_nume, m_denom);

         if( ! g.eq_one()){ 
            m_nume.div_eq(g);
            m_denom.div_eq(g);
         }
         if(sign_change){
            m_nume.negate();
         }  
      }
   };

   inline big_rational operator+(big_rational const & lhs, big_rational const & rhs)
   {
      big_rational result = lhs;
      return result += rhs;
   }

  /* inline big_rational operator+(big_rational const & lhs, bigint const & rhs)
   {
      return lhs + big_rational(rhs);
   }

   inline big_rational operator+(bigint const & lhs, big_rational const & rhs)
   {
      return big_rational(lhs) + rhs;
   }*/

  // inline double operator+(big_rational const & lhs, double const & rhs)
   //{
   //   return lhs.to_double() + rhs;
   //}

   //inline double operator+(double const & lhs, big_rational const & rhs)
   //{
   //   return lhs + rhs.to_double();
   //}


   inline big_rational operator-(big_rational const & lhs, big_rational const & rhs)
   {
      big_rational result = lhs;
      return result -= rhs;
   }

   //inline big_rational operator-(big_rational const & lhs, bigint const & rhs)
   //{
   //   return lhs - big_rational(rhs,bigint(1));
   //}

   //inline big_rational operator-(bigint const & lhs, big_rational const & rhs)
   //{
   //   return big_rational(lhs,bigint(1)) - rhs;
   //}

   //inline double operator-(big_rational const & lhs, double const & rhs)
   //{
   //   return lhs.to_double() - rhs;
   //}

   //inline double operator-(double const & lhs, big_rational const & rhs)
   //{
   //   return lhs - rhs.to_double();
   //}

   inline big_rational operator*(big_rational const & lhs, big_rational const & rhs)
   {
      big_rational result = lhs;
      return result *= rhs;
   }

   /*inline big_rational operator*(big_rational const & lhs, bigint const & rhs)
   {
      return lhs * big_rational(rhs,bigint(1));
   }

   inline big_rational operator*(bigint const & lhs, big_rational const & rhs)
   {
      return big_rational(lhs,bigint(1)) * rhs;
   }

   inline double operator*(big_rational const & lhs, double const & rhs)
   {
      return lhs.to_double() * rhs;
   }

   inline double operator*(double const & lhs, big_rational const & rhs)
   {
      return lhs * rhs.to_double();
   }*/


   inline big_rational operator/(big_rational const & lhs, big_rational const & rhs)
   {
      big_rational result = lhs;
      return result /= rhs;
   }

   ////inline big_rational operator/(big_rational const & lhs, bigint const & rhs)
   ////{
   ////   return lhs / big_rational(rhs,bigint(1));
   ////}

   //inline big_rational operator/(bigint const & lhs, big_rational const & rhs)
   //{
   //   return big_rational(lhs,bigint(1)) / rhs;
   //}

   //inline double operator/(big_rational const & lhs, double const & rhs)
   //{
   //   return lhs.to_double() / rhs;
   //}

   //inline double operator/(double const & lhs, big_rational const & rhs)
   //{
   //   return lhs / rhs.to_double();
   //}
  
   inline big_rational 
   operator /(quan::bigint const & lhs,quan::bigint const & rhs)
   {
      return big_rational(lhs,rhs);
   }


     inline bool operator < (big_rational const & lhs, big_rational const & rhs)
      {
         bigint v1 = lhs.nume() * rhs.denom();
         bigint v2 = rhs.nume() * lhs.denom();
         return v1 < v2;
      } 

      inline bool operator <= (big_rational const & lhs, big_rational const & rhs)
      {
         bigint v1 = lhs.nume() * rhs.denom();
         bigint v2 = rhs.nume() * lhs.denom();
         return v1 <= v2;
      } 
      
      inline bool operator == (big_rational const & lhs,big_rational const & rhs)
      {
         return (lhs.nume() == rhs.nume()) && ( lhs.denom() == rhs.denom() );
      } 

      inline bool operator != (big_rational const & lhs,big_rational const & rhs)
      {
         return (lhs.nume() != rhs.nume()) || ( lhs.denom() != rhs.denom() );
      } 

      inline bool operator >= (big_rational const & lhs,big_rational const & rhs)
      {
         bigint v1 = lhs.nume() * rhs.denom();
         bigint v2 = rhs.nume() * lhs.denom();
         return v1 >= v2;
      } 
 
      inline bool operator > (big_rational const & lhs,big_rational const & rhs)
      {
         bigint v1 = lhs.nume() * rhs.denom();
         bigint v2 = rhs.nume() * lhs.denom();
         return v1 > v2;
      } 
  
}

#endif
