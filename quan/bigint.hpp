#ifndef QUAN_BIGINT_HPP_INCLUDED
#define QUAN_BIGINT_HPP_INCLUDED
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

#include <quan/config.hpp>

#include <quan/detail/ll_bigint.hpp>

#include <string>
#include <stdexcept>
#include <quan/where.hpp>
// add ops in here...
#include <quan/bigint_binary_operation.hpp>

namespace quan{

   struct bigint{

      bigint();
      bigint( bigint const &);
//#if (QUAN_BIGINT_VERSION == 1)
      bigint(std::string const & str);
      template <int N> bigint(char const(& ar)[N] )
      {
         this->assign_from_string(ar);
      }
      bigint(int n);
      bigint(unsigned int n);
      bigint(long n);
      bigint(unsigned long n);
      bigint(long long n);
      bigint(unsigned long long n);

      bigint & operator = (bigint const & rhs);
      bigint & operator +=( bigint const & rhs);
      bigint & operator -=( bigint const & rhs);     
      bigint & operator *=( bigint const & rhs);
      
      bigint & operator &=( bigint const & rhs);
      bigint & operator |=( bigint const & rhs);     
      bigint & operator ^=( bigint const & rhs);
      bigint & operator <<=( bigint const & rhs);
      bigint & operator >>=( bigint const & rhs);     

      bigint & div_eq( bigint const & rhs);
      bigint & mod_eq( bigint const & rhs);
      
      void negate();

      bool operator <(bigint const &  rhs)const;
      bool operator <=(bigint const &  rhs)const;
      bool operator ==(bigint const &  rhs)const;
      bool operator !=(bigint const &  rhs)const;
      bool operator >=(bigint const &  rhs)const;
      bool operator >(bigint const &  rhs)const;

      bool eq_zero()const;
      bool lt_zero()const;
      bool eq_one()const;
      
      double to_double()const;

      template <int N>
      std::string to_string_base() const;
      std::string to_string() const;
      std::string to_binary_string() const;
      std::string to_hex_string() const;
      void move(bigint & rhs);

      int get_sign() const;
      void set_sign(int in);

      static bigint gcd(bigint const & n, bigint const & d);

    private:
      void assign_from_string(std::string const & str);
//#endif
      detail::ll_bigint m_rep;

#if (QUAN_BIGINT_VERSION == 1 )
      // 1 for plus, -1 for minus
      int m_sign;
#endif
     
      friend struct big_rational;
      typedef detail::ll_bigint::uint32      uint32;
      typedef detail::ll_bigint::uint64      uint64;
      typedef detail::ll_bigint::int32       int32;
      typedef detail::ll_bigint::int64       int64;
      typedef detail::ll_bigint::difference_type difference_type;
      private:
   };
//#if (QUAN_BIGINT_VERSION == 1)
    bigint operator +(bigint const & lhs,bigint const & rhs);
    bigint operator -(bigint const & lhs,bigint const & rhs);
    bigint operator *(bigint const & lhs,bigint const & rhs);
    bigint        div(bigint const & lhs,bigint const & rhs);
    bigint        mod(bigint const & lhs,bigint const & rhs);

    bigint operator &(bigint const & lhs,bigint const & rhs);
    bigint operator |(bigint const & lhs,bigint const & rhs);
    bigint operator ^(bigint const & lhs,bigint const & rhs);
    bigint operator <<(bigint const & lhs,bigint const & rhs);
    bigint operator >>(bigint const & lhs,bigint const & rhs);

    double operator +(bigint const & lhs,double const & rhs);
    double operator +(double const & lhs,bigint const & rhs);
    
    double operator -(bigint const & lhs,double const & rhs);
    double operator -(double const & lhs,bigint const & rhs);
    
    double operator *(bigint const & lhs,double const & rhs);
    double operator *(double const & lhs,bigint const & rhs);

    double operator /(bigint const & lhs,double const & rhs);
    double operator /(double const & lhs,bigint const & rhs);
    // defined in big_rational.hpp
    inline big_rational operator /(bigint const & lhs,bigint const & rhs);
//#endif

}
#endif
