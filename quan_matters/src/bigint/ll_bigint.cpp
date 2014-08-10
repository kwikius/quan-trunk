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

//check to_double with single size
#include <quan/config.hpp>
#if(QUAN_BIGINT_VERSION == 1)

#include <quan/detail/ll_bigint.hpp>

#include <iostream>

// affects bitsize
void quan::detail::ll_bigint::shl_eq( quan::detail::ll_bigint::ll_bigint const & rhs)
{
      // could be improved!
    ll_bigint shl = rhs;
    while ( ! shl.is_equal_to_zero()){
      this->mul_eq(ll_bigint(static_cast<uint32>(2)));
      shl.minus_eq(ll_bigint(static_cast<uint32>(1)));
    }
}
//affects bitsize
void quan::detail::ll_bigint::shr_eq(quan::detail::ll_bigint::ll_bigint const & rhs)
{
       // could be improved!
    ll_bigint shr = rhs;
    while ( ! shr.is_equal_to_zero()){
     // this->div_eq(ll_bigint(static_cast<uint32>(2)));
      this->integer_shift_right_by_1();
      shr.minus_eq(ll_bigint(static_cast<uint32>(1)));
    }
}
// need to be both positive?
quan::detail::ll_bigint 
quan::detail::ll_bigint::gcd(quan::detail::ll_bigint const & n,quan::detail::ll_bigint const & d)
{
   ll_bigint nume = n;
   ll_bigint denom = d;
   for(;;){
      if ( denom.is_equal_to_zero()){
         return nume;
      }
      nume.mod_eq(denom);
      if ( nume.is_equal_to_zero()){
         return denom;
      }
      denom.mod_eq(nume);
   }
}

void quan::detail::ll_bigint::assign_from_stringbase2(std::string const & str)
{
   assert (str != "");
   ll_bigint const two  = static_cast<uint32>(2);
   std::size_t const len = str.length();
   this->clear_to_zero();
   for (std::size_t i = 0; i < len; ++i){
      if( i !=0){
         this->mul_eq(two);
      }
      uint32 const cur = static_cast<uint32>( str.at(i) - '0');
      assert( ( cur == 0 ) || (cur ==1));
      this->plus_eq(cur);
   }
}

void quan::detail::ll_bigint::assign_from_hex_string(std::string const & str)
{
   assert (str != "");
   ll_bigint const ten (static_cast<uint32>(0x10));
   std::size_t const len = str.length();
   this->clear_to_zero();
   for (std::size_t i = 0; i < len; ++i){
      if( i !=0){
         this->mul_eq(ten);
      }
      if ( ( str[i] >= '0' )  && (str[i] <= '9')){
         uint32 const cur = static_cast<uint32>( str.at(i) - '0');
         assert( ( cur >= 0U ) && (cur < 10U));
         this->plus_eq(cur);
         continue;
      }
      else {
         if (( str[i] >= 'A' ) && (str[i] <= 'F')){
       
          uint32 const cur = static_cast<uint32>( (str.at(i) - 'A') +10);
            assert( ( cur >= 10U ) && (cur < 16U));
            this->plus_eq(cur);
            continue;
         }else{
            assert (( str[i] >= 'a' ) && (str[i] <= 'f'));
            uint32 const cur = static_cast<uint32>( (str.at(i) - 'a') +10);
            assert( ( cur >= 10U ) && (cur < 16U));
            this->plus_eq(cur);
            continue;
         }
      }               
   }
}

void quan::detail::ll_bigint::assign_from_string(std::string const & str)
{
   assert (str != "");
   ll_bigint const ten (static_cast<uint32>(10));
   std::size_t const len = str.length();
   this->clear_to_zero();
   for (std::size_t i = 0; i < len; ++i){
      if( i !=0){
         this->mul_eq(ten);
      }
      uint32 const cur = static_cast<uint32>( str.at(i) - '0');
      assert( ( cur >= 0U ) && (cur < 10U));
      this->plus_eq(cur);
   }
}

std::string quan::detail::ll_bigint::to_string_base16() const
{
   ll_bigint const sixteen(static_cast<uint32>(16));
   ll_bigint copy= *this;
   std::list<unsigned int> opt;
   for(;;){
      if ( copy.get_num_elements() ==1){
         uint32 val = copy.at(0);
         static const bit_offset_type num_shifts = sizeof(uint32) * CHAR_BIT;
         for ( int i = 0; i < num_shifts; ++i){
            opt.push_front(static_cast<unsigned int> (val % 16));
            val /=16;
         }
         break;
      }else{
         ll_bigint divres1;
         ll_bigint modres1;
         copy.div_mod(sixteen,divres1,modres1);
         assert(modres1.get_num_elements() ==1);
         opt.push_front(static_cast<unsigned int>(modres1.at(0)));
         copy.move(divres1);
      }
   }
   std::string str;
   str.reserve(opt.size());
   bool ld_zero = true;
   for( std::list<unsigned int>::iterator i = opt.begin(), end = opt.end();
         i != end;
            ++i){
      assert( (*i >=0 ) || ( *i <=15) );
      if ( ld_zero && (*i != 0 )) ld_zero = false;
      if (! ld_zero){
         if ( (*i>=0) && (*i<=9)){
            str += static_cast<char>(*i + '0');
         }
         else {
            str+= static_cast<char>( (*i - 10) + 'A' );
         }
      }
   }
   if (ld_zero){
      str = "0";
   }
   return str;
}

std::string quan::detail::ll_bigint::to_string_base2() const
{
   ll_bigint const two(static_cast<uint32>(2));
   ll_bigint copy= *this;
   std::list<unsigned int> opt;
   for(;;){
      if ( copy.get_num_elements() ==1){
         uint32 val = copy.at(0);
         static const bit_offset_type num_shifts = sizeof(uint32) * CHAR_BIT;
         for ( int i = 0; i < num_shifts; ++i){
            opt.push_front(static_cast<unsigned int> (val % 2));
            val /=2;
         }
         break;
      }else{
         ll_bigint divres1;
         ll_bigint modres1;
         copy.div_mod(two,divres1,modres1);
         assert(modres1.get_num_elements() ==1);
         opt.push_front(static_cast<unsigned int>(modres1.at(0)));
         copy.move(divres1);
      }
   }
   std::string str;
   str.reserve(opt.size());
   bool ld_zero = true;
   for( std::list<unsigned int>::iterator i = opt.begin(), end = opt.end();
         i != end;
            ++i){
      assert( (*i ==0 ) || ( *i ==1) );
      if ( ld_zero && (*i != 0 )) ld_zero = false;
      if (! ld_zero){
         str += static_cast<char>(*i + '0');
      }
   }
   if (ld_zero){
      str = "0";
   }
   return str;
}

std::string quan::detail::ll_bigint::to_string() const
{
   ll_bigint const ten(static_cast<uint32>(10));
   ll_bigint copy= *this;
   std::list<unsigned int> opt;
   for(;;){
      if ( copy.get_num_elements() ==1){
         uint32 val = copy.at(0);
         for ( int i = 0; i <= std::numeric_limits<uint32>::digits10; ++i){
            opt.push_front(static_cast<unsigned int> (val % 10));
            val /= 10;
         }
         break;
      }else{
         ll_bigint divres1;
         ll_bigint modres1;
         copy.div_mod(ten,divres1,modres1);
         assert(modres1.get_num_elements() ==1);
         opt.push_front(static_cast<unsigned int>(modres1.at(0)));
         copy.move(divres1);
      }
   }
   std::string str;
   str.reserve(opt.size());
   bool ld_zero = true;
   for( std::list<unsigned int>::iterator i = opt.begin(), end = opt.end();
         i != end;
            ++i){
      assert( (*i >=0 ) && ( *i < 10) );
      if ( ld_zero && (*i != 0 )) ld_zero = false;
      if (! ld_zero){
         str += static_cast<char>(*i + '0');
      }
   }
   if (ld_zero){
      str = "0";
   }
   return str;
}

// only call if get_num_elements > 1 ?
double quan::detail::ll_bigint::to_double() const
{
   offset_type size = this->get_num_elements();
   double v = this->at(size -1);
   static const uint64 mux = static_cast<uint64>(quan::meta::integer_max<uint32>::value) +1;
//   std::cout << "mux = " << mux <<'\n';
   for (int i = size-2; i >= 0; --i){
      v *= mux;
      v+= this->at(i);
   }
   return v;
}


quan::detail::ll_bigint::uint32 & quan::detail::ll_bigint::at( offset_type i)
{
   if (! m_alloc_size){
      assert(i == 0);
      return m_value;
   }
   else{
      assert (  i < m_alloc_size);
      return m_array[i];
   }
}

quan::detail::ll_bigint::uint32 quan::detail::ll_bigint::at( offset_type i)const
{
   if (! m_alloc_size){
      assert(i == 0);
      return m_value;
   }
   else{
      assert (  i < m_alloc_size);
      return m_array[i];
   }
}

void quan::detail::ll_bigint::resize_to_at_least(
quan::detail::ll_bigint::offset_type size)
{
   assert (size > 0);
   if ( ! m_alloc_size){
      if( size != 1){
         uint32* const ta= new uint32[size];
         ta[0] = m_value;
         for ( offset_type i = 1; i < size;++i){
            ta[i] = static_cast<uint32>(0);
         }
         m_array = ta;
         m_alloc_size = size;
      }
   }else{
      if ( m_alloc_size < size){
         uint32* const ta = new uint32[size];
         offset_type i = 0;
         while( i < m_alloc_size){
            ta[i] = m_array[i];
            ++i;
         }
         while( i < (size )){
            ta[i] = static_cast<uint32>(0);
            ++i;
         }
         delete [] m_array;
         m_array = ta;
         m_alloc_size = size;
      }
   }
}

void quan::detail::ll_bigint::compact()
{
   offset_type const used_size = get_num_elements();
   if( used_size == 1){
      if(m_alloc_size){
         uint32 t = m_array[0];
         delete [] m_array;
         m_value = t;
         m_alloc_size = 0;
      }
   }
   else{
      if ( used_size < m_alloc_size){
         uint32* const t = new uint32[used_size];
         for (offset_type i = 0; i < used_size; ++i){
            t[i] = m_array[i];
         }
         delete [] m_array;
         m_array = t;
         m_alloc_size = used_size;
      } else{
         assert( used_size == m_alloc_size);
      }
   }
}

void quan::detail::ll_bigint::integer_shift_right_by_1()
{
   offset_type const size = this->get_num_elements();
   uint32 prevlsb = this->at(size-1) & 1;
   this->at(size-1) >>=1;
   if (size == 1){
      return;
   }
   for (offset_type i = size-2; i >= 0; --i){
      if (prevlsb ==0){
         prevlsb = this->at(i) & 1;
         this->at(i) >>= 1;
      }else{
         prevlsb = this->at(i) & 1;
         this->at(i) = (this->at(i) >> 1) | (1 << (sizeof(uint32)* CHAR_BIT -1));
      }
   }
}

void quan::detail::ll_bigint::shl_eq(uint32 bits_in)
{
   if (bits_in == 0){
      return;
   }
   static const int bit_size = sizeof(uint32) * CHAR_BIT;
   offset_type const shift_bytes = bits_in / bit_size;
   bit_offset_type const shift_bits = bits_in % bit_size;
   offset_type const num_elements = this->get_num_elements();

   // find if shift adds overflow
   uint64 const test
   = static_cast<uint64>(
      this->at(num_elements-1)
   ) << shift_bits;

   offset_type const scratch_size = (quan::asm_::hi_nibble(test) ==0)
      ? num_elements + shift_bytes
      : num_elements + shift_bytes + 1;

   if (scratch_size ==1){
      this->at(0) = static_cast<uint32>(quan::asm_::lo_nibble(test));
      return;
   }

   ll_bigint scratch;
   scratch.resize_to_at_least(scratch_size);
   for (offset_type i = 0, idx = shift_bytes ; i < num_elements ; ++idx,++i){
      uint64 const temp = static_cast<uint64>(this->at(i)) << shift_bits;
      scratch.at(idx) |= static_cast<uint32>(quan::asm_::lo_nibble(temp));
      uint32 const hi = static_cast<uint32>(quan::asm_::hi_nibble(temp));
      if(hi){
         assert( ( idx+1 ) < scratch_size );
         scratch.at(idx+1)= hi;
      }
   }
   this->move(scratch);
}

void quan::detail::ll_bigint::resize_raw_to_abs(offset_type size)
{
   assert(size > 0);
   if( size == 1){
      if (m_alloc_size){
         delete [] m_array;
         m_alloc_size =0;
      }
   }else{
      if (m_alloc_size != size){
         if(m_alloc_size){
            delete [] m_array;
         }
         m_array = new uint32[size];
         m_alloc_size = size;
      }
   }
}


// return 0 if this == rhs
// return 1 if this > rhs
// return -1 if this < rhs
int quan::detail::ll_bigint::compare( quan::detail::ll_bigint const & rhs)const
{
   if(this == &rhs){
      return 0;
   }
   offset_type const lhs_size = this->get_num_elements();
   offset_type const rhs_size = rhs.get_num_elements();

   if ( lhs_size < rhs_size ){
      return -1;
   }
   if(  lhs_size > rhs_size  ){
      return 1;
   }
   // if here we know each has same number of elements
   if ( lhs_size ==1){
      uint32 lhsv = this->at(0);
      uint32 rhsv = rhs.at(0);
      if( lhsv == rhsv) return 0;
      return (lhsv > rhsv)?1:-1;
   }
   offset_type const scratch_size = lhs_size ;
   uint32* const scratch = new uint32[scratch_size];

// copy this to scratch;
// record if all elems same
   bool same_flag = true;
   for (offset_type i =0; i < lhs_size;++i){
      scratch[i] = this->at(i);
      if ( same_flag && ( scratch[i] != rhs.at(i) ) ){
         same_flag=false;
      }
   }
   //if elements are same...not less hence done
   if(same_flag){
      delete [] scratch;
      return 0;
   }
   // sub rhs to scratch with borrow
   for (offset_type i =0; i < rhs_size ; ++i){
      int64 const rhs_element = static_cast<int64>(rhs.at(i));
      int64 temp = static_cast<int64>(scratch[i]);
      if ( temp < rhs_element){
         temp += (static_cast<int64>(1) << sizeof(uint32)* CHAR_BIT);
         offset_type borrow_pos = i+1;
         for(;;){
            // if here request borrow from higher pos than
            // max in lhs hence result negative...done
            if(borrow_pos == scratch_size){
               delete [] scratch;
               return -1;
            }
            uint32 & scratch_borrow_pos = scratch[borrow_pos];
            if(scratch_borrow_pos !=0){
               scratch_borrow_pos -=1;
               break;
            }
            else{
               scratch_borrow_pos = static_cast<uint32>(-1);
               ++borrow_pos;
               continue;
            }
         }
      }
      temp -= rhs_element;
      scratch[i] = static_cast<uint32>(quan::asm_::lo_nibble(temp));
      assert( quan::asm_::hi_nibble(temp) == 0 );
   }
   delete [] scratch;
   return 1;
}

bool quan::detail::ll_bigint::is_equal_to_zero() const
{
   if ( ! m_alloc_size){
      return this->m_value == 0 ;
   }else{
      return  ( this->m_array[0] == 0 ) && ( this->get_num_elements() == 1 );
   }
}

bool quan::detail::ll_bigint::is_equal_to_one() const
{
   if ( ! m_alloc_size){
      return this->m_value == 1 ;
   }else{
      return  ( this->m_array[0] == 1 ) && ( this->get_num_elements() == 1 );
   }
}

bool quan::detail::ll_bigint::is_equal_to( quan::detail::ll_bigint const & rhs)  const
{
   offset_type const lhs_size = this->get_num_elements();
   offset_type const rhs_size = rhs.get_num_elements();

   if ( lhs_size != rhs_size ){
      return false;
   }
   for (offset_type i =0; i < lhs_size;++i){
      if( this->at(i) != rhs.at(i) ){
         return false;
      }
   }
   return true;
}

void quan::detail::ll_bigint::mul_eq(quan::detail::ll_bigint const & rhs)
{
   this->mul(rhs,*this);
}

void quan::detail::ll_bigint::mod_eq(quan::detail::ll_bigint const & rhs)
{
   ll_bigint div;
   this->div_mod(rhs,div,*this);
}

void quan::detail::ll_bigint::div_eq(ll_bigint const & rhs)
{
   ll_bigint mod;
   this->div_mod(rhs,*this,mod);
}

void quan::detail::ll_bigint::div_mod(
quan::detail::ll_bigint const & rhs, 
quan::detail::ll_bigint & div_result, 
quan::detail::ll_bigint & mod_result)const
{
   assert ( ! rhs.is_equal_to_zero());
   offset_type const lhs_size = this->get_num_elements();
   offset_type const rhs_size = rhs.get_num_elements();

   // opt for small
   if( (lhs_size == 1) && (rhs_size == 1)){
      uint32 lhsv = this->at(0);
      uint32 rhsv = rhs.at(0);
      div_result.clear_to_zero();
      mod_result.clear_to_zero();
      div_result.at(0) = static_cast<uint32>( lhsv / rhsv );
      mod_result.at(0) = static_cast<uint32>( lhsv % rhsv );
      return;
   }

   if(this->is_equal_to_zero()){
      div_result.clear_to_zero();
      mod_result.clear_to_zero();
      return;
   }
   int const cmp_val = this->compare(rhs);
   if( cmp_val < 0 ){
      mod_result = *this;
      div_result.clear_to_zero();

      return;
   }
   if( cmp_val == 0 ){
      mod_result.clear_to_zero();
      div_result = ll_bigint(static_cast<uint32>(1));
      return;
   }

   static int const bits_byte = ( sizeof(uint32)* CHAR_BIT );

   int32 const lhs_mask_pos = find_msb(this->at(lhs_size - 1));
   int32 const rhs_mask_pos = find_msb(rhs.at(rhs_size - 1));

   bit_offset_type shift = (lhs_size - rhs_size ) * bits_byte
      + (lhs_mask_pos - rhs_mask_pos);

   offset_type scratch_size = lhs_size - rhs_size +1;
   if ( (lhs_mask_pos - rhs_mask_pos) < 0 ){
      --scratch_size;
   }
   assert (scratch_size > 0);
   ll_bigint scratch_result;
   scratch_result.resize_to_at_least(scratch_size);

   ll_bigint dvsor = rhs;
   dvsor.shl_eq(shift);

   ll_bigint remainder = *this;

   if ( remainder.compare(dvsor) >= 0 ){
      remainder.minus_eq(dvsor);
      offset_type const index = shift / bits_byte;
      bit_offset_type const bit_index =  shift % bits_byte;
      scratch_result.at(index) = 1 << bit_index;
   }

   while(--shift >= 0){
      if(remainder.is_equal_to_zero()){
         break;
      }
      dvsor.integer_shift_right_by_1();
      if ( remainder.compare(dvsor) >=0){
         remainder.minus_eq(dvsor);
         uint32 const index = shift / bits_byte;
         uint32 const  bit_index =  shift % bits_byte;
         scratch_result.at(index) |= 1 << bit_index;
      }
   }
   div_result.move(scratch_result);
   mod_result.move(remainder);
}


void quan::detail::ll_bigint::bitxor(
quan::detail::ll_bigint const & rhs,quan::detail::ll_bigint & result)const
{
   result = *this;
   result.bitxor_eq(rhs);
}


quan::detail::ll_bigint &
quan::detail::ll_bigint::bitxor_eq(ll_bigint const & rhs)
{
   offset_type const lhs_size = this->get_num_elements();
   offset_type const rhs_size = rhs.get_num_elements();
   offset_type result_size = std::max(lhs_size,rhs_size);
   this->resize_to_at_least(result_size);
   for (offset_type i=0; i < result_size;++i){
      this->at(i) ^= rhs.at(i);
   }
   return *this;
}

void quan::detail::ll_bigint::bitor_(
   quan::detail::ll_bigint const & rhs,
   quan::detail::ll_bigint & result
)const
{
  result = *this;
  result.bitor_eq(rhs);
}

quan::detail::ll_bigint& 
quan::detail::ll_bigint::bitor_eq(ll_bigint const & rhs)
{
   offset_type const lhs_size = this->get_num_elements();
   offset_type const rhs_size = rhs.get_num_elements();
   offset_type result_size = std::max(lhs_size,rhs_size);
   this->resize_to_at_least(result_size);
   for (offset_type i=0; i < result_size;++i){
      this->at(i) |= rhs.at(i);
   }
   return *this;
}

void quan::detail::ll_bigint::bitand_(
   quan::detail::ll_bigint const & rhs,
   quan::detail::ll_bigint & result)const
{
   result = *this;
   result.bitand_eq(rhs);
}

quan::detail::ll_bigint& 
quan::detail::ll_bigint::bitand_eq(quan::detail::ll_bigint const & rhs)
{
   offset_type lhs_size = this->get_num_elements();
   offset_type const rhs_size = rhs.get_num_elements();
   offset_type result_size = std::min(lhs_size,rhs_size);

   while(lhs_size > result_size){
      this->at(--lhs_size ) = static_cast<uint32>(0);
   }

   for (offset_type i=0; i < result_size;++i){
      this->at(i) &= rhs.at(i);
   }
   return *this;
}

void quan::detail::ll_bigint::mul(
   quan::detail::ll_bigint const & rhs, 
   quan::detail::ll_bigint & result) const
{
   offset_type const lhs_size = this->get_num_elements();
   offset_type const rhs_size = rhs.get_num_elements();
   // opt for small
   if( (lhs_size == 1) && (rhs_size == 1)){
      uint64 opt_check
      = static_cast<uint64>(this->at(0)) * static_cast<uint64>(rhs.at(0));
      if ( quan::asm_::hi_nibble(opt_check) !=0 ){
         result.resize_to_at_least(2);
         result.at(0) = static_cast<uint32>(quan::asm_::lo_nibble(opt_check));
         result.at(1) = static_cast<uint32>(quan::asm_::hi_nibble(opt_check));
      }else{
         result.at(0) = static_cast<uint32>(quan::asm_::lo_nibble(opt_check));
      }
      return;
   }
   ll_bigint scratch;
   offset_type const scratch_size = lhs_size + rhs_size;

   scratch.resize_to_at_least(scratch_size);
   for (offset_type iL = 0; iL < lhs_size; ++iL){
      uint64 const cur_lhs = this->at(iL);
      for (offset_type iR=0; iR < rhs_size; ++iR){
         offset_type offset = iL + iR;
         uint64 calc = (cur_lhs * rhs.at(iR) );
         uint64 temp0 = quan::asm_::lo_nibble(calc) + scratch.at(offset);
         scratch.at(offset) = static_cast<uint32>(quan::asm_::lo_nibble(temp0));
         temp0 = quan::asm_::hi_nibble(temp0) + quan::asm_::hi_nibble(calc);
         while (temp0){
            ++offset;
            assert (offset < scratch_size);
            uint64 const temp1 = quan::asm_::lo_nibble(temp0)+ scratch.at(offset);
            scratch.at(offset) = static_cast<uint32>(quan::asm_::lo_nibble(temp1));
            temp0 = quan::asm_::hi_nibble(temp0)+ quan::asm_::hi_nibble(temp1);
         }
      }
   }
   result.move(scratch);
}

//  rhs must be less than or equal to this
void quan::detail::ll_bigint::minus(
  quan::detail::ll_bigint const & rhs,
  quan::detail::ll_bigint & result)const
{
   ll_bigint temp = *this;
   temp.minus_eq(rhs);
   result.move(temp);
}

//  rhs must be less than or equal to this
void quan::detail::ll_bigint::minus_eq(quan::detail::ll_bigint const & rhs)
{
   if(this == &rhs){
      this->clear_to_zero();
      return;
   }
   assert( this->compare(rhs) >= 0 );

   offset_type const lhs_size = this->get_num_elements();
   offset_type const rhs_size = rhs.get_num_elements();
   if( (lhs_size == 1) && (rhs_size == 1)){
      this->at(0) -= rhs.at(0);
      return;
   }

   // sub rhs to this with borrow
   for (offset_type i =0; i < rhs_size ; ++i){
      int64 temp = static_cast<int64>(this->at(i));
      if ( temp < static_cast<int64>(rhs.at(i)) ){
         temp += (static_cast<int64>(1) <<  sizeof(uint32)* CHAR_BIT );
         offset_type borrow_pos = i+1;
         for(;;){
            assert(borrow_pos < lhs_size);
            if( this->at(borrow_pos) !=0 ){
               this->at(borrow_pos) -=1;
               break;
            }
            else{
               this->at(borrow_pos) = static_cast<uint32>(-1);
               ++borrow_pos;
               continue;
            }
         }
      }
      temp -= static_cast<int64>( rhs.at(i) );
      this->at(i) = static_cast<uint32>( quan::asm_::lo_nibble(temp) );
      assert( quan::asm_::hi_nibble(temp) == 0 );
   }
}

void quan::detail::ll_bigint::plus(
   quan::detail::ll_bigint::ll_bigint const & rhs,
   quan::detail::ll_bigint::ll_bigint & result)const
{
   ll_bigint temp = *this;
   temp.plus_eq(rhs);
   result.move(temp);
}

void quan::detail::ll_bigint::plus_eq(quan::detail::ll_bigint const & rhs)
{
   if(this == &rhs){
      this->shl_eq(1);
      return;
   }
   offset_type const lhs_size = this->get_num_elements();
   offset_type const rhs_size = rhs.get_num_elements();
   // opt for small
   if( ( lhs_size == 1 ) && ( rhs_size == 1 ) ){
      uint64 opt_check
      = static_cast<uint64>(this->at(0)) + static_cast<uint64>(rhs.at(0));
      if ( quan::asm_::hi_nibble(opt_check) ==0 ){
         this->at(0) = static_cast<uint32>(quan::asm_::lo_nibble(opt_check));
      }
      else{
         this->resize_to_at_least(2);
         this->at(0) = static_cast<uint32>(quan::asm_::lo_nibble(opt_check));
         this->at(1) = static_cast<uint32>(quan::asm_::hi_nibble(opt_check));
      }
      return;
   }

   offset_type const new_size = std::max(lhs_size,rhs_size) + 1;
   resize_to_at_least(new_size);

   for (offset_type i =0; i < rhs_size; ++i){
      uint64 temp = static_cast<uint64>(this->at(i)) + rhs.at(i);
      this->at(i) = static_cast<uint32>(quan::asm_::lo_nibble(temp));
      offset_type carry_pos = i+1;
      while ( quan::asm_::hi_nibble(temp) != 0){
         assert(carry_pos < new_size);
         temp = static_cast<uint64>(this->at(carry_pos)) + 1;
         this->at(carry_pos) = static_cast<uint32>(quan::asm_::lo_nibble(temp));
         ++carry_pos;
      }
   }
}

quan::detail::ll_bigint::offset_type
quan::detail::ll_bigint::get_alloc_size() const
{
   return m_alloc_size;
}


quan::detail::ll_bigint::offset_type
 quan::detail::ll_bigint::get_num_elements()const
{
   if(  m_alloc_size == 0){
      return 1;
   }
   else{
      offset_type result_size = m_alloc_size;
      if ( get_sign() == false)
         while ( ( result_size > 1) && (m_array[result_size-1] == 0) ){
            --result_size;
         }
         return result_size;
      }
      else{
         while ( ( result_size > 1) && (m_array[result_size-1] == -1) ){
            --result_size;
         }
         return result_size;
      }
   }
}

void quan::detail::ll_bigint::clear_to_zero()
{
   if ( m_alloc_size == 0 ){
      m_value = 0;
   }else{
      for(offset_type i =0; i < m_alloc_size;++i){
         m_array[i] =0;
      }
   }
}

quan::detail::ll_bigint::bit_offset_type
quan::detail::ll_bigint::find_msb(uint32 in)
{
   assert(in != 0);
   static int const bits_byte = ( sizeof(uint32)* CHAR_BIT );
   static uint32 const msb_mask = 1 << (bits_byte -1);

   bit_offset_type bit_idx = bits_byte-1;
   while (in ){
      if ( (in & msb_mask) !=0){
         break;
      }
      else{
         in <<= 1;
         --bit_idx;
      }
   }
   return bit_idx;
}



quan::detail::ll_bigint & 
quan::detail::ll_bigint::operator = (ll_bigint const & rhs)
{
   if (this == & rhs){
      return *this;
   }
   offset_type const rhs_size = rhs.get_num_elements();
   this->resize_raw_to_abs(rhs_size);
   for (offset_type i = 0; i != rhs_size ;++i){
      this->at(i) = rhs.at(i);
   }
   return *this;
}

quan::detail::ll_bigint::ll_bigint(std::string const & in)
:m_alloc_size(0),m_value(0)
{
   this->assign_from_string(in);
}

quan::detail::ll_bigint::ll_bigint(const char* const in)
:m_alloc_size(0),m_value(0)
{
   this->assign_from_string(std::string{in});
}

quan::detail::ll_bigint::ll_bigint(quan::detail::ll_bigint const & rhs)
{
   offset_type const rhs_size = rhs.get_num_elements();
   if (rhs_size ==1){
      m_alloc_size =0;
      m_value = rhs.at(0);
   }else{
      m_alloc_size = rhs_size;
      m_array = new uint32 [rhs_size];
      for (offset_type i = 0; i != rhs_size ;++i){
         m_array[i] = rhs.at(i);
      }
   }
}

quan::detail::ll_bigint::~ll_bigint()
{
   if (m_alloc_size){
      delete [] m_array;
   }
}  


void quan::detail::ll_bigint::move(quan::detail::ll_bigint & rhs)
{
   if(this == &rhs) {
      return;
   }
   if(m_alloc_size){
      delete [] m_array;
   }
   if (rhs.m_alloc_size){
      m_alloc_size = rhs.m_alloc_size;
      m_array = rhs.m_array;
      rhs.m_alloc_size =0;
      rhs.at(0) =0;
   }
   else{
      m_alloc_size = 0;
      m_value = rhs.at(0);
      rhs.at(0) = 0;
   }
}


#endif

