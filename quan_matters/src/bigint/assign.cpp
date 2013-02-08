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

