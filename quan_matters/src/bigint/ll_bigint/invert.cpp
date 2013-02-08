#include <quan/detail/ll_bigint.hpp>

using quan::detail::ll_bigint;

void ll_bigint::invert()
{
   size_type const size = this->get_num_elements();
   for ( size_type i = 0; i < size ; ++i)
   {
     this->m_rep.at(i) = ~this->m_rep.at(i);
   }

}


