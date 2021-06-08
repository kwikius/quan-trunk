#ifndef QUAN_THREE_D_VECT_MAKE_ROW_MATRIX_VIEW_HPP_INCLUDED
#define QUAN_THREE_D_VECT_MAKE_ROW_MATRIX_VIEW_HPP_INCLUDED

#include <type_traits>
#include <quan/three_d/vect.hpp>
#include <quan/basic_matrix/basic_matrix.hpp>

/*
N.B valueType 
*/

namespace quan{

   template <int R, typename T>
   struct row_matrix_view_t;

   namespace impl{

      template <int R, typename T>
      struct is_basic_matrix_impl<quan::row_matrix_view_t<R,T> > : quan::meta::true_{};
   }//impl

   template <typename T>
   struct row_matrix_view_t<3,three_d::vect<T> >{

      static_assert(std::is_arithmetic<T>::value,"");

    typedef T value_type;
    typedef row_matrix_view_t type;
    static constexpr int rows = 1;
    static constexpr int cols = 3;

    constexpr row_matrix_view_t(three_d::vect<T> const & v):m_vect{v}{}

#if __cpp_constexpr >= 201304
    constexpr 
#endif
    T at(uint32_t r, uint32_t c) const 
    {
       if ( (r == 0) && (c < 3)){
          return m_vect[c];
       }else{
          throw std::runtime_error("invalid matrix indices");
       }
    }

    private:
       three_d::vect<T> const & m_vect;
   };

   namespace three_d{

      template <typename T>
      inline constexpr row_matrix_view_t<3, quan::three_d::vect<T> >
      make_row_matrix_view(quan::three_d::vect<T> const & v)
      {
         return row_matrix_view_t<3, quan::three_d::vect<T> >{v};
      }
   }
} // quan

#endif // QUAN_THREE_D_VECT_MAKE_ROW_MATRIX_VIEW_HPP_INCLUDED
