#include <quan/detail/ll_bigint.hpp>

#include <iostream>

using quan::detail::ll_bigint;

void ll_bigint::dump_rep()const
{
   for ( difference_type i = this->get_num_elements()-1; i >=0; --i){
     if ( i < static_cast<difference_type>(this->get_num_elements() -1)){
        std::cout << ",";
     }
     std::cout << std::hex << static_cast<size_type>(this->m_rep.at(i));
   }
   std::cout << '\n';
}
