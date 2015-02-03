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
 along with this program. If not, see http://www.gnu.org/licenses.
*/

#include <quan/bigint.hpp>
#include <cassert>

using quan::bigint;

namespace {

 template <int N>
 struct string_prefix;

 template <> struct string_prefix<10>{
    const char * operator()() const
    {
       return "";
    }
 };

 template <> struct string_prefix<16>{
    const char * operator()() const
    {
       return "0x";
    }
 };

 template <> struct string_prefix<2>{
    const char * operator()() const
    {
       return "0b";
    }
 };

}

bigint::bigint(){}

bigint::bigint(std::string const & str)
{
   this->assign_from_string(str);
}

bigint::bigint(bigint const & in): m_rep(in.m_rep){}

bigint & bigint::operator = (bigint const & in)
{
 m_rep = in.m_rep;
 return *this;
}

void bigint::assign_from_string(std::string const & str)
{
   bool is_neg= false;
   std::string str1;
   if ( (str.length() > 1) && ( str.at(0) == '-')){
       is_neg = true;
       str1 = str.substr(1,str.npos);
   }else{
     str1 = str;
   }
   std::string prefix;
   if ( str1.length() > 2){
     prefix = str1.substr(0,2);
   }
   if ((prefix == "0x") || (prefix == "0X")) {
      str1 = str1.substr(2,str1.npos);
      this->m_rep.from_string_base<16>(str1);
   }else {
      if ((prefix == "0b") || (prefix == "0B")){
         str1 = str1.substr(2,str1.npos);
         this->m_rep.from_string_base<2>(str1);
      }
      else{
         this->m_rep.from_string_base<10>(str1);
      }
   }
   if (is_neg){
     m_rep.negate();
   }
}

bigint::bigint(int n) : m_rep(n){}
bigint::bigint(long n) : m_rep(n){}
bigint::bigint(long long n) : m_rep(n){}
bigint::bigint(unsigned long n): m_rep(static_cast<long long>(n)){};
bigint::bigint(unsigned int n) : m_rep(static_cast<long long>(n)){};
//  bigint(unsigned long long n);

 template <int N>
std::string  bigint::to_string_base() const
{  
  if ( m_rep.is_negative()){
    quan::detail::ll_bigint t = m_rep;
    t.negate();
    return std::string{"-"} + string_prefix<N>{}() + t.to_string_base<N>();
  }
  else{
   return string_prefix<N>{}() + m_rep.to_string_base<N>();
  }
}

std::string bigint::to_string() const
{
  return to_string_base<10>();
}

std::string bigint::to_binary_string() const
{
  return to_string_base<2>();
}

std::string bigint::to_hex_string() const
{
  return to_string_base<16>();
}

bigint & bigint::operator +=( bigint const & rhs)
{
  m_rep.plus_eq(rhs.m_rep);
  return *this;
}

bigint & bigint::operator -=( bigint const & rhs)
{
  m_rep.minus_eq(rhs.m_rep);
  return *this;
}

bigint & bigint::operator *=( bigint const & rhs)
{
  m_rep.mul_eq(rhs.m_rep);
  return *this;
}

bigint & bigint::div_eq( bigint const & rhs)
{
  m_rep.div_eq(rhs.m_rep);
  return *this;
}

bigint & bigint::mod_eq( bigint const & rhs)
{
  m_rep.mod_eq(rhs.m_rep);
  return *this;
}

bigint & bigint::operator &=( bigint const & rhs)
{
  m_rep.bitand_eq(rhs.m_rep);
  return *this;
}
bigint & bigint::operator |=( bigint const & rhs)
{
  m_rep.bitor_eq(rhs.m_rep);
  return *this;
}     
bigint & bigint::operator ^=( bigint const & rhs)
{
  m_rep.bitxor_eq(rhs.m_rep);
  return *this;
}

bigint & bigint::operator <<=( bigint const & rhs)
{
  assert(rhs.m_rep.m_rep.size() == 1);
  std::size_t shift = rhs.m_rep.m_rep[0];
  m_rep.arith_shl_eq(shift);
  return *this;
}
bigint & bigint::operator >>=( bigint const & rhs)
{
  assert(rhs.m_rep.m_rep.size() == 1);
  std::size_t shift = rhs.m_rep.m_rep[0];
  m_rep.arith_shr_eq(shift);
  return *this;
}  

double bigint::to_double()const
{
   return this->m_rep.to_double();
}

void bigint::move(bigint & rhs)
{
   this->m_rep.move(rhs.m_rep);
}

bool bigint::operator <(bigint const &  rhs)const
{
   return this->m_rep.less_than(rhs.m_rep);
}

bool bigint::operator <=(bigint const &  rhs)const
{
   return this->m_rep.less_equal(rhs.m_rep);
}

bool bigint::operator ==(bigint const &  rhs)const
{
  return this->m_rep.equal_to(rhs.m_rep);
}


 bool bigint::operator !=(bigint const &  rhs)const
{
   return this->m_rep.not_equal(rhs.m_rep);
}


bool bigint::operator >=(bigint const &  rhs)const
{
   return this->m_rep.greater_equal(rhs.m_rep);
}

bool bigint::operator >(bigint const &  rhs)const
{
 return this->m_rep.greater(rhs.m_rep);
}

#if(QUAN_BIGINT_VERSION == 1)

int bigint::get_sign() const
{
   // what sign means here is now unclear!
   assert(false);
   return m_rep_get_sign_bit();
}

void bigint::set_sign(int in)
{
   assert(false);
   assert((in == 1) || (in ==-1));
   if( this->m_rep.is_equal_to_zero()){
      m_sign = 1;
   }
   else{
      m_sign = in;
   }
}
#endif

bool bigint::eq_zero()const
{
   return this->m_rep.eq_zero();
}

bool bigint::lt_zero()const
{
   return this->m_rep.is_negative();
}

bool bigint::eq_one()const
{
   return this->m_rep.eq_one();
}

void bigint::negate()
{
   this->m_rep.negate();
}

bigint bigint::gcd(bigint const & n, bigint const & d)
{
   detail::ll_bigint ll_result = detail::ll_bigint::gcd(n.m_rep,d.m_rep);
   bigint result;
   result.m_rep.move(ll_result);
   return result;
}

namespace quan{

   bigint operator +(bigint const & lhs,bigint const & rhs)
   {
      bigint res = lhs;
      return res += rhs;
   }

   double operator +(bigint const & lhs,double const & rhs)
   {
      return lhs.to_double() + rhs;
   }

   double operator +(double const & lhs,bigint const & rhs)
   {
      return lhs + rhs.to_double();
   }

   bigint operator -(bigint const & lhs,bigint const & rhs)
   {
      bigint res = lhs;
      return res -= rhs;
   }

   double operator -(bigint const & lhs,double const & rhs)
   {
      return lhs.to_double() - rhs;
   }

   double operator -(double const & lhs,bigint const & rhs)
   {
      return lhs - rhs.to_double();
   }

   bigint operator *(bigint const & lhs,bigint const & rhs)
   {
      bigint res = lhs;
      return res *= rhs;
   }

   double operator *(bigint const & lhs,double const & rhs)
   {
      return lhs.to_double() * rhs;
   }

   double operator *(double const & lhs,bigint const & rhs)
   {
      return lhs * rhs.to_double();
   }

   double operator /(bigint const & lhs,double const & rhs)
   {
      return lhs.to_double() / rhs;
   }

   double operator /(double const & lhs,bigint const & rhs)
   {
      return lhs / rhs.to_double();
   }

   bigint        div(bigint const & lhs,bigint const & rhs)
   {
      bigint t = lhs;
      return t.div_eq(rhs);
   }
   bigint        mod(bigint const & lhs,bigint const & rhs)
   {
      bigint t = lhs;
      return t.mod_eq(rhs);
   }

    bigint operator &(bigint const & lhs,bigint const & rhs)
    {
         bigint t = lhs;
         return t &= rhs;
    }
    bigint operator |(bigint const & lhs,bigint const & rhs)
    {
         bigint t = lhs;
         return t |= rhs;
    }
    bigint operator ^(bigint const & lhs,bigint const & rhs)
    {
         bigint t = lhs;
         return t ^= rhs;
    }
    bigint operator <<(bigint const & lhs,bigint const & rhs)
    {
         bigint t = lhs;
         return t <<= rhs;
    }
    bigint operator >>(bigint const & lhs,bigint const & rhs)
    {
         bigint t = lhs;
         return t >>= rhs;
    }

//currently in big_rational.hpp
   //big_rational operator /(bigint const & lhs,bigint const & rhs);

}//quan


   
