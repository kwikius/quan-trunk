#ifndef QUAN_VECTOR_VIEW_HPP_INCLUDED
#define QUAN_VECTOR_VIEW_HPP_INCLUDED

#include <cstddef>
#include <cassert>
#include <vector>
#include <quan/size.hpp>
#include <quan/meta/get_value_type.hpp>

/*
   a view of a std::vector, c style array ( or a nested vector_view etc)
*/

namespace quan{

   template <typename Vect>
   struct vector_view{
      typedef typename quan::meta::get_value_type<Vect>::type value_type;
    
      // first is the first index and last is the last index to be included in the view of the container cont
      vector_view(Vect const & cont,std::size_t first, std::size_t last)
      : m_first{first},m_last{last},m_cont{cont}
      {
         assert(last < quan::size(m_cont));
      }

      std::size_t size() const
      {
         return (m_last - m_first) + 1U;
      }

      value_type const & operator [] (std::size_t n) const
      {
         return m_cont[m_first + n];
      }

   private :
      std::size_t m_first;
      std::size_t m_last;
      Vect const & m_cont;
   };

   template <typename Vect>
   inline 
   vector_view<Vect> 
   make_vector_view(Vect const & in,std::size_t  first , std::size_t last)
   {
      return vector_view<Vect>(in, first, last);
   }

}

#endif // QUAN_VECTOR_VIEW_HPP_INCLUDED
