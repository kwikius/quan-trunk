#ifndef QUAN_THREE_D_VECT_MAKE_DIAGONAL_MATRIX_HPP_INCLUDED
#define QUAN_THREE_D_VECT_MAKE_DIAGONAL_MATRIX_HPP_INCLUDED

#include <type_traits>
#include <quan/three_d/vect.hpp>
#include <quan/basic_matrix/basic_matrix.hpp>

namespace quan{ 

   template <typename T>
   struct diagonal_matrix_view_t;

   namespace impl{

      template <typename T>
      struct is_basic_matrix_impl<quan::diagonal_matrix_view_t<T> > : quan::meta::true_{};
   }//impl

   template <typename T>
   struct diagonal_matrix_view_t<three_d::vect<T> >{

    static_assert(std::is_arithmetic<T>::value,"");

    typedef T value_type;
    typedef diagonal_matrix_view_t type;
    static constexpr int rows = 3;
    static constexpr int cols = 3;

    constexpr diagonal_matrix_view_t(three_d::vect<T> const & v):m_vect{v}{}

#if __cpp_constexpr >= 201304
    constexpr 
#endif
    T at(uint32_t r, uint32_t c) const 
    {
       if ( (r == c) && (c < 3)){
          return m_vect[c];
       }else{
          return 0;
       }
    }

    private:
       three_d::vect<T> const & m_vect;
   };

   namespace three_d{
      template <typename T>
      inline constexpr diagonal_matrix_view_t<quan::three_d::vect<T> >
      make_diagonal_matrix_view(quan::three_d::vect<T> const & v)
      {
         return diagonal_matrix_view_t<quan::three_d::vect<T> >{v};
      }
   }// threee_d

} // quan

#endif // QUAN_THREE_D_VECT_MAKE_DIAGONAL_MATRIX_HPP_INCLUDED
