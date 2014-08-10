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

#if(QUAN_BIGINT_VERSION == 1)
quan::bigint & quan::bigint::div_eq( quan::bigint const & rhs)
{
   this->m_rep.div_eq(rhs.m_rep);
   this->set_sign(this->get_sign() * rhs.get_sign());
   return *this;
}

quan::bigint & quan::bigint::mod_eq( quan::bigint const & rhs)
{
   this->m_rep.mod_eq(rhs.m_rep);
   this->set_sign(this->get_sign() * rhs.get_sign());
   return *this;
}

quan::bigint& 
quan::bigint::operator = (quan::bigint const & rhs)
{
   if( this != &rhs){
      this->m_rep = rhs.m_rep;
      this->m_sign = rhs.m_sign;
      this->m_rep.compact();
   }
   return *this;
}

quan::bigint& 
quan::bigint::operator += (quan::bigint const & rhs)
{
   if(this->m_rep.is_equal_to_zero()){
      *this = rhs;
      return * this;
   }
   if ( this->m_sign == rhs.m_sign){
      this->m_rep.plus_eq(rhs.m_rep);
   }
   else{
      int cmp = this->m_rep.compare(rhs.m_rep);
      if (cmp == 0 ){
         this->m_rep.clear_to_zero();
         this->m_sign = 1;
      }else {
         if(cmp > 0){
            this->m_rep.minus_eq(rhs.m_rep);
            //no change in sign
         }else{
            rhs.m_rep.minus(this->m_rep,this->m_rep);
           // this->set_sign(this->get_sign() * -1);
           // ok isnt zero
            this->m_sign *=-1;
         }
         this->m_rep.compact();
      }
   }
   return *this;
}

quan::bigint& 
quan::bigint::operator -= (quan::bigint const & rhs)
 {
   if ( this->m_sign == rhs.m_sign){
   // its a sub
      int cmp = this->m_rep.compare(rhs.m_rep);
      if (cmp == 0 ){
         this->m_rep.clear_to_zero();
         this->m_sign = 1;
         this->m_rep.compact();
      }else {
         if(cmp > 0){
            this->m_rep.minus_eq(rhs.m_rep);
            //no change in sign
         }else{
            rhs.m_rep.minus(this->m_rep,this->m_rep);
            //this->set_sign(this->get_sign() * -1);
            // ok isnt zero
            this->m_sign *=-1;
         }
         this->m_rep.compact();
      }
   }else{
      //its an add
      this->m_rep.plus_eq(rhs.m_rep);
      //no change in sign
   }
   return * this;
}

quan::bigint& 
quan::bigint::operator *= (quan::bigint const & rhs)
{
   this->m_rep.mul_eq(rhs.m_rep);
   this->set_sign(this->get_sign() * rhs.get_sign());
   return *this;
}

#endif

