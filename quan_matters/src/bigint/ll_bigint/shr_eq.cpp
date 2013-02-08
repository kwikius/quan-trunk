#include <quan/detail/ll_bigint.hpp>
#include <quan/meta/numbits.hpp>

using quan::detail::ll_bigint;


void ll_bigint::logical_shr_eq(size_type shift)
{
   size_type const wordshift = shift / quan::meta::numbits<uint32>::value;
   difference_type const dL = shift % quan::meta::numbits<uint32>::value;
   difference_type const dH = quan::meta::numbits<uint32>::value - dL;
   size_type const size = this->get_num_elements();
   std::vector<uint32> dest(size,0);
   for ( difference_type i = size -1; i >= 0; --i){
      difference_type const dest_idx = i - wordshift;
      if ( dest_idx >= 0){
         uint32 const hi_src = this->m_rep.at(i) >> dL;
         dest.at(dest_idx) |= hi_src;
         if ( dest_idx > 0){
            uint32 const lo_src = this->m_rep.at(i) << dH;
            dest.at(dest_idx-1) |= lo_src;
         }
      }else{
        break;
      }
   }
   this->m_rep = dest;
}

/*
 same as logical shift for +ve numbers
 but different semantics for negative numbers..

need to test semantics
*/
void ll_bigint::arith_shr_eq(size_type shift)
{
   if ( !this->is_negative()){
      this->logical_shr_eq(shift);
   }else{
      size_type const wordshift = shift / quan::meta::numbits<uint32>::value;
      difference_type const dL = shift % quan::meta::numbits<uint32>::value;
      difference_type const dH = quan::meta::numbits<uint32>::value - dL;
      size_type const size = this->get_num_elements();
      std::vector<uint32> dest(size,~0);
      for ( difference_type i = size -1; i >= 0; --i){
         difference_type const dest_idx = i - wordshift;
         if ( dest_idx >= 0){
            uint32 const hi_src 
             = static_cast<uint32>(static_cast<int32>(this->m_rep.at(i)) >> dL);
            dest.at(dest_idx) &= hi_src;
            if ( dest_idx > 0){
               uint32 const lo_src = this->m_rep.at(i) << dH;
               dest.at(dest_idx-1) &= lo_src;
            }
         }else{
           break;
         }
      }
      this->m_rep = dest;
   }
   this->request_compact(0);
   return;
}

