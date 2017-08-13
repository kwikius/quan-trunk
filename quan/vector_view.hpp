#ifndef QUAN_VECTOR_VIEW_HPP_INCLUDED
#define QUAN_VECTOR_VIEW_HPP_INCLUDED

#include <cstddef>
#include <cassert>
#include <vector>

/*
   a view of a std::vector
*/

namespace quan{

   template <typename StdVector>
   struct vector_view{

      typedef StdVector vector_type;
      typedef typename vector_type::value_type value_type;

      // first is the first index and last is the last index to be included in the view of the container cont
      vector_view( StdVector const & cont,std::size_t first, std::size_t last)
      : m_first{first},m_last{last},m_cont{cont}
      {
         assert(last < m_cont.size());
      }

      std::size_t size() const
      {
         return (m_last - m_first) + 1U;
      }

      value_type const & operator [] (std::size_t n) const
      {
         return m_cont[ m_first + n];
      }

   private :
      std::size_t m_first;
      std::size_t m_last;
      StdVector const & m_cont;
   };

   template <typename StdVector>
   inline vector_view<StdVector> 
   make_vector_view(StdVector const & in, int first , int last)
   {
      return vector_view<StdVector>(in, first, last);
   }

}

#endif // QUAN_VECTOR_VIEW_HPP_INCLUDED
