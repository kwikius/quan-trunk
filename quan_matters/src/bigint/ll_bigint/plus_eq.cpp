#include <quan/detail/ll_bigint.hpp>
#include <quan/asm/nibble.hpp>
#include <algorithm>

using quan::detail::ll_bigint;

void ll_bigint::plus_eq (ll_bigint const & rhs_in)
{
  //make copy of rhs as want to resize and ok if rhs == *this
  this->request_compact(0);
  ll_bigint rhs = rhs_in;
  rhs.request_compact(0);
  size_type size = std::max(this->get_num_elements(),rhs.get_num_elements()) +1;
  this->extend(size);
  rhs.extend(size);
  for ( size_type i = 0; i != size; ++i){
      uint64 res 
         = static_cast<uint64>(this->m_rep.at(i))
         + static_cast<uint64>(rhs.m_rep.at(i));
      this->m_rep.at(i) = static_cast<uint32>(quan::asm_::lo_nibble(res));
      bool carry = quan::asm_::hi_nibble(res)  != 0 ;
      for ( size_type carry_pos = i + 1; carry && ( carry_pos < size ) ; ++carry_pos){
         res = static_cast<uint64>( this->m_rep.at(carry_pos)) + 1;
         this->m_rep.at(carry_pos) = static_cast<uint32>(quan::asm_::lo_nibble(res));
         carry = quan::asm_::hi_nibble(res)  !=0 ;
      }
   }
   this->request_compact(0);
   return;
}

//only for use with negate. doesnt check for overflow or do any resizing
void 
ll_bigint::plus_eq1()
{
   size_type const size = this->get_num_elements();
   uint64 res = static_cast<uint64>(this->m_rep.at(0)) + 1 ;
   this->m_rep.at(0) = static_cast<uint32>(quan::asm_::lo_nibble(res));
   bool carry = quan::asm_::hi_nibble(res)  != 0 ;
   for ( size_type carry_pos = 1; carry && ( carry_pos < size ) ; ++carry_pos){
      res = static_cast<uint64>( this->m_rep.at(carry_pos)) + 1;
      this->m_rep.at(carry_pos) = static_cast<uint32>(quan::asm_::lo_nibble(res));
      carry = quan::asm_::hi_nibble(res)  !=0 ;
   }
   return;
}

