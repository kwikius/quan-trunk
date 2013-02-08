#include <quan/detail/ll_bigint.hpp>

using quan::detail::ll_bigint;

void ll_bigint::bitor_eq(ll_bigint const & rhs)
{
   size_type const rhs_size = rhs.get_num_elements();
   size_type const size = std::max(this->get_num_elements() , rhs_size);
   uint32 const mask = (rhs.is_negative())?static_cast<uint32>(~0): 0;
   this->extend(size);
   for (size_type i = 0; i < rhs_size; ++i){
      this->m_rep.at(i) |= rhs.m_rep.at(i);
   }
   for ( size_type i = rhs_size; i < size; ++i){
      this->m_rep.at(i) |= mask;
   }
}