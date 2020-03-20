#ifndef QUAN_BASIC_MATRIX_HPP_INCLUDED
#define QUAN_BASIC_MATRIX_HPP_INCLUDED

#include <cstdint>
#include <cstring>
#include <type_traits>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/out/format_print.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/get_value_type.hpp>
#include <quan/meta/bool.hpp>
#include <quan/implicit_cast.hpp>

namespace quan{ 

  namespace impl{

     template <typename T, typename Where = void >
     struct is_basic_matrix_impl : quan::meta::false_{};
 };

 template <typename T>
 struct is_basic_matrix : impl::is_basic_matrix_impl<typename quan::meta::strip_cr<T>::type>{};

 template <typename ... T>
 struct are_basic_matrices : quan::meta::and_<is_basic_matrix<T>... >{};

 template <int R, int C, typename T = double>
 struct basic_matrix{

    typedef T value_type;

    typedef basic_matrix type;
    static constexpr int rows = R;
    static constexpr int cols = C;

    basic_matrix( basic_matrix const & in)  
    {
        std::memcpy(m_array, in.m_array, R * C * sizeof(T));
    }
   
    basic_matrix & operator =( basic_matrix const & in)
    { 
       if ( this != &in){
          std::memcpy(m_array, in.m_array, R * C * sizeof(T));
       }
       return *this;
    }

    template <typename... Args>
    constexpr basic_matrix( Args ... args)
    : m_array{quan::implicit_cast<T>(args)...}
    {
      static_assert(sizeof...(Args) == R * C, "invalid args");
    }


    template <
      typename  M,
      typename = typename quan::where_<
         quan::meta::and_<
           quan::is_basic_matrix<M> 
           ,std::is_convertible<typename quan::meta::get_value_type<M>::type,T>
         >
      >::type
    >
    basic_matrix( M const & m)
    {
      for ( uint32_t r = 0U; r < R; ++r){
         for ( uint32_t c = 0U; c < C; ++c){
            this->at(r,c) = m.at(r,c);
         }
      }
    }

    template < typename  M>
    typename quan::where_<
       quan::meta::and_<
         quan::is_basic_matrix<M> 
         ,std::is_convertible<typename quan::meta::get_value_type<M>::type,T>
       >
      ,basic_matrix&
    >::type
    operator = ( M const & m)
    {
      for ( uint32_t r = 0U; r < R; ++r){
         for ( uint32_t c = 0U; c < C; ++c){
            this->at(r,c) = m.at(r,c);
         }
      }
      return *this;
    }

    T & at(uint32_t r, uint32_t c) &
    {
       return m_array[r * C + c];
    }

    T const & at(uint32_t r, uint32_t c) const &
    {
       return m_array[r * C + c];
    }

    template <
      typename Lhs, typename Rhs,
      typename = typename quan::where_< 
         quan::meta::and_< 
            are_basic_matrices<Lhs,Rhs>
            ,quan::meta::is_valid_binary_op< 
               T , 
               quan::meta::plus,
               typename quan::meta::binary_op<
                  typename quan::meta::get_value_type<Lhs>::type, 
                  quan::meta::times,
                  typename quan::meta::get_value_type<Rhs>::type
               >::type
             >
            ,quan::meta::bool_< ((Lhs::rows == R ) 
               && ( Rhs::cols  == C)
                  && ( Lhs::cols == Rhs::rows)
            )>
         >
      >::type
    >
    basic_matrix(Lhs const & lhs, quan::operator_times, Rhs const & rhs )
    {
      int constexpr M = Lhs::cols;
      for ( uint32_t r = 0U; r < R; ++r){
         for ( uint32_t c = 0U; c < C; ++c){
            T sum = T{};
            for ( uint32_t m = 0U; m < M; ++m){
               sum += lhs.at(r,m) * rhs.at(m,c);
            }
            this->at(r,c) = sum;
         }
      }
    }

    template <
      typename Lhs, typename Rhs,
      typename = typename quan::where_< 
         quan::meta::and_< 
            are_basic_matrices<Lhs,Rhs>
            ,std::is_convertible< 
                typename quan::meta::binary_op<
                   typename quan::meta::get_value_type<Lhs>::type
                   ,quan::meta::plus
                   ,typename quan::meta::get_value_type<Rhs>::type
                >::type
               ,T
             >
            ,quan::meta::bool_< 
               ((Lhs::rows == R ) && (Lhs::cols  == C)
               && (Rhs::rows == R ) && (Rhs::cols == C)
            )>
         >
      >::type
    >
    basic_matrix(Lhs const & lhs, quan::operator_plus, Rhs const & rhs )
    {
      for ( uint32_t r = 0U; r < R; ++r){
         for ( uint32_t c = 0U; c < C; ++c){
            this->at(r,c) = lhs.at(r,c) + rhs.at(r,c);
         }
      }
    }

    template <
      typename Lhs, typename Rhs,
      typename = typename quan::where_< 
         quan::meta::and_< 
            are_basic_matrices<Lhs,Rhs>
            ,std::is_convertible< 
                typename quan::meta::binary_op<
                   typename quan::meta::get_value_type<Lhs>::type
                   ,quan::meta::minus
                   ,typename quan::meta::get_value_type<Rhs>::type
                >::type
               ,T
             >
            ,quan::meta::bool_< 
               ((Lhs::rows == R ) && (Lhs::cols  == C)
               && (Rhs::rows == R ) && (Rhs::cols == C)
            )>
         >
      >::type
    >
    basic_matrix(Lhs const & lhs, quan::operator_minus, Rhs const & rhs )
    {
      for ( uint32_t r = 0U; r < R; ++r){
         for ( uint32_t c = 0U; c < C; ++c){
            this->at(r,c) = lhs.at(r,c) - rhs.at(r,c);
         }
      }
    }

    T  * get_array(){return m_array;}
 
    private:
    T m_array[R * C];
 };

   namespace impl {

      template <int R, int C,typename T>
      struct is_basic_matrix_impl<quan::basic_matrix<R,C,T> > : quan::meta::true_{};
   }// impl

   template <typename Lhs, typename Rhs>
   inline  
   typename quan::where_< 
      quan::meta::and_< 
         are_basic_matrices<Lhs,Rhs>
         ,quan::meta::is_valid_binary_op< 
            typename quan::meta::get_value_type<Lhs>::type, 
            quan::meta::times,
            typename quan::meta::get_value_type<Rhs>::type
          >
         ,quan::meta::bool_< 
            (Lhs::cols == Rhs::rows)
         >
      >
      ,basic_matrix<
         Lhs::rows,
         Rhs::cols,
         typename quan::meta::binary_op<
            typename quan::meta::get_value_type<Lhs>::type, 
            quan::meta::times,
            typename quan::meta::get_value_type<Rhs>::type
         >::type
      >
   >::type
   operator * (Lhs const & lhs,Rhs const & rhs)
   {
      return {lhs, quan::operator_times{},rhs};
   }

   template <typename Lhs, typename Rhs>
   inline
   typename quan::where_< 
      quan::meta::and_< 
         are_basic_matrices<Lhs,Rhs>
         ,quan::meta::is_valid_binary_op<
            typename quan::meta::get_value_type<Lhs>::type
            ,quan::meta::plus
            ,typename quan::meta::get_value_type<Rhs>::type
          >
         ,quan::meta::bool_< 
            ((Lhs::rows == Rhs::rows ) && (Lhs::cols  == Rhs::cols)
         )>
      >
      ,basic_matrix<
         Lhs::rows, Lhs::cols,
         typename quan::meta::binary_op<
            typename quan::meta::get_value_type<Lhs>::type, 
            quan::meta::plus,
            typename quan::meta::get_value_type<Rhs>::type
        >::type
      >
   >::type
   operator + (Lhs const & lhs, Rhs const & rhs)
   {
      return {lhs, quan::operator_plus{},rhs};
   }

   template <typename Lhs, typename Rhs>
   inline
   typename quan::where_< 
      quan::meta::and_< 
         are_basic_matrices<Lhs,Rhs>
         ,quan::meta::is_valid_binary_op<
            typename quan::meta::get_value_type<Lhs>::type
            ,quan::meta::minus
            ,typename quan::meta::get_value_type<Rhs>::type
          >
         ,quan::meta::bool_< 
            ((Lhs::rows == Rhs::rows ) && (Lhs::cols  == Rhs::cols)
         )>
      >
      ,basic_matrix<
         Lhs::rows, Lhs::cols,
         typename quan::meta::binary_op<
            typename quan::meta::get_value_type<Lhs>::type, 
            quan::meta::minus,
            typename quan::meta::get_value_type<Rhs>::type
        >::type
      >
   >::type
   operator - (Lhs const & lhs, Rhs const & rhs)
   {
      return {lhs, quan::operator_minus{},rhs};
   }

   template <typename M>
   typename quan::where_<quan::is_basic_matrix<M> >::type
   display( M const & m, const char * const text, std::ostream & out = std::cout)
   {
      if (text != nullptr){
         out << text <<'\n';
      }
      int cell_length = 10;
      quan::format_print fp{cell_length,5,4,3};
      out << "/ ";
      for ( int32_t i = 0; i < (cell_length ) * M::cols -2; ++i){
         out << " ";
      }
      out << " \\\n";
      for ( int r = 0; r < M::rows; ++r){

         out << '|';
         for ( int c = 0; c < M::cols; ++c){
            fp(m.at(r,c),out);
         }
         out << "|\n";
      }

      out << "\\ ";
      for ( int32_t i = 0; i < (cell_length ) * M::cols -2; ++i){
         out << " ";
      }
      out << " /\n";
   }

   template <typename M>
   typename quan::where_<quan::is_basic_matrix<M> >::type
   output( M const & m, const char * const text, std::ostream & out = std::cout)
   {
      if (text != nullptr){
         out << text ;
      }
      int cell_length = 10;
      quan::format_print fp{cell_length,5,4,3};
      out << "{\n";
//      for ( int32_t i = 0; i < (cell_length ) * M::cols -2; ++i){
//         out << " ";
//      }
   //   out << " \\\n";
      for ( int r = 0; r < M::rows; ++r){
         
         for ( int c = 0; c < M::cols; ++c){
            
            fp(m.at(r,c),out);
            if ( ((c == (M::cols -1)) && ( r== (M::rows -1))) == false){
               out << ", ";
            }
            
         }
         out << "\n";
//        if ( r < (M::rows -1) {
//            out << ",\n";
//        }
      }

    //  out << "\\ ";
//      for ( int32_t i = 0; i < (cell_length ) * M::cols -2; ++i){
//         out << " ";
//      }
      out << "};\n";
   }

   template <
      typename M
      ,typename Where = void 
   >
   struct transpose_view;

   template <typename M>
   struct transpose_view<M,
      typename quan::where_<
         quan::is_basic_matrix<M>
      >::type
   >{
      typedef transpose_view type;
      typedef M src_matrix_type;
      typedef typename src_matrix_type::value_type value_type;
      static constexpr int rows = src_matrix_type::cols ;
      static constexpr int cols = src_matrix_type::rows ;

      transpose_view(src_matrix_type const & in)
      : m_src_matrix{in}
      {
      }

      value_type at(int r, int c) const
      {
         assert( (r < rows) && (c < cols) );
         return m_src_matrix.at(c,r);
      }
      private:
      src_matrix_type const & m_src_matrix;
   };

   namespace impl {

      template <typename M>
      struct is_basic_matrix_impl<
         quan::transpose_view<M>
         ,typename quan::where_<
               quan::is_basic_matrix<M>
         >::type
      > : quan::meta::true_{};
   }// impl

   template <typename M>
   inline
   typename quan::where_<
       quan::is_basic_matrix<M>
      ,transpose_view<M>
   >::type
   make_transpose_view( M const & m)
   {
      return {m};
   }

   template <
      typename M, 
      typename Where = void 
   >
   struct sub_matrix_view;

   template <typename M>
   struct sub_matrix_view<M,
      typename quan::where_<
         quan::meta::and_<
            quan::is_basic_matrix<M>
            ,quan::meta::bool_< (( M::rows > 1 ) && ( M::cols > 1 )) >
         >
      >::type
   >{
      typedef sub_matrix_view type;
      typedef M parent_matrix_type;
      typedef typename parent_matrix_type::value_type value_type;
      static constexpr int rows = parent_matrix_type::rows - 1;
      static constexpr int cols = parent_matrix_type::cols - 1;

      sub_matrix_view(parent_matrix_type const & in, int row, int col)
      : m_parent_matrix{in},m_row{row},m_col{col}
      {
         assert( (row <= rows) && (col <= cols) );
      }

      value_type at(int r, int c) const
      {
         assert( (r < rows) && (c < cols) );
         int const r1 = ( r < m_row) ? r : r + 1 ;
         int const c1 = ( c < m_col) ? c : c + 1 ;
         return m_parent_matrix.at(r1,c1);
      }
     
      private:
      parent_matrix_type const & m_parent_matrix;
      int const m_row;
      int const m_col;
   };

   namespace impl {

      template <typename M>
      struct is_basic_matrix_impl<
         quan::sub_matrix_view<M>
         ,typename quan::where_<
            quan::meta::and_<
               quan::is_basic_matrix<M>
               ,quan::meta::bool_< (( M::rows > 1 ) && ( M::cols > 1 )) >
            >
         >::type
      > : quan::meta::true_{};
   }// impl

   template <typename M>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::is_basic_matrix<M>
         ,quan::meta::bool_< (( M::rows > 1 ) && ( M::cols > 1 )) >
      >
      ,sub_matrix_view<M>
   >::type
   make_sub_matrix_view( M const & m, int r, int c)
   {
      return {m, r,c};
   }

   template <typename M>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::is_basic_matrix<M> 
         ,quan::meta::bool_<(M::rows == M::cols)>
         ,quan::meta::bool_<(M::rows == 1)>
      >
      ,typename quan::meta::get_value_type<M>::type
    >::type
   matrix_determinant( M const & m)
   {
      return m.at(0,0);
   }

    template <typename M>
    inline
    typename quan::where_<
      quan::meta::and_<
         quan::is_basic_matrix<M> 
         ,quan::meta::bool_<(M::rows == M::cols)>
         ,quan::meta::bool_<(M::rows > 1)>
      >
      ,typename quan::meta::get_value_type<M>::type
    >::type
   matrix_determinant( M const & m)
   {
      typedef typename quan::meta::get_value_type<M>::type value_type;

      value_type result = value_type{};
      int sign = 1;
      for ( int c = 0; c < M::cols;++c){
         result += sign * m.at(0,c) * matrix_determinant(make_sub_matrix_view(m,0,c));
         sign = -sign;
      }
      return result;
   }

   template <typename M, typename Where = void>
   struct adjoint_matrix_view;

   template <typename M>
   struct adjoint_matrix_view<
       M
      ,typename quan::where_<
         quan::meta::and_<
            quan::is_basic_matrix<M> 
            ,quan::meta::bool_<( (M::rows == M::cols) && (M::rows > 1) ) >
         >
       >::type
   >{

      typedef adjoint_matrix_view type;
      typedef M src_matrix_type;
      typedef typename src_matrix_type::value_type value_type;
      static constexpr int rows = src_matrix_type::rows;
      static constexpr int cols = src_matrix_type::cols;

      adjoint_matrix_view(src_matrix_type const & in)
      : m_src_matrix{in}
      {
      }

      value_type at(int r, int c) const
      {
         assert( (r < rows) && (c < cols) );
         int const sign = ((r+c)% 2 == 0)? 1: -1;
         return sign * matrix_determinant(make_sub_matrix_view(m_src_matrix,c,r));
      }

      private:
         src_matrix_type const & m_src_matrix;
   };

    namespace impl {

      template <typename M>
      struct is_basic_matrix_impl<
         quan::adjoint_matrix_view<M>
         ,typename quan::where_<
            quan::meta::and_<
               quan::is_basic_matrix<M>
               ,quan::meta::bool_< (( M::cols == M::rows) && (M::rows > 1)) >
            >
         >::type
      > : quan::meta::true_{};

   }// impl

   template <typename M>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::is_basic_matrix<M>
         ,quan::meta::bool_< (( M::cols == M::rows) && (M::rows > 1)) >
      >
     ,adjoint_matrix_view<M>
   >::type
   make_adjoint_matrix_view( M const & m)
   {
      return {m};
   }

   template <typename M, typename Where = void>
   struct inverse_matrix_view;

   template <typename M>
   struct inverse_matrix_view<
       M
      ,typename quan::where_<
         quan::meta::and_<
            quan::is_basic_matrix<M> 
            ,quan::meta::bool_<( (M::rows == M::cols) && (M::rows > 1) ) >
         >
       >::type
   >{

      typedef inverse_matrix_view type;
      typedef M src_matrix_type;
      typedef typename src_matrix_type::value_type value_type;
      static constexpr int rows = src_matrix_type::rows;
      static constexpr int cols = src_matrix_type::cols;

      inverse_matrix_view(src_matrix_type const & in)
      : m_adj{in}, m_determinant{matrix_determinant(in)}
      {
         assert (m_determinant != value_type{});
      }

      value_type at(int r, int c) const
      {
         assert( (r < rows) && (c < cols) );
         return m_adj.at(r,c) / m_determinant;
      }

      private:
         adjoint_matrix_view<M> m_adj;
         value_type m_determinant;
   };

    namespace impl {

      template <typename M>
      struct is_basic_matrix_impl<
         quan::inverse_matrix_view<M>
         ,typename quan::where_<
            quan::meta::and_<
               quan::is_basic_matrix<M>
               ,quan::meta::bool_< (( M::cols == M::rows) && (M::rows > 1)) >
            >
         >::type
      > : quan::meta::true_{};

   }// impl

   template <typename M>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::is_basic_matrix<M>
         ,quan::meta::bool_< (( M::cols == M::rows) && (M::rows > 1)) >
      >
     ,inverse_matrix_view<M>
   >::type
   make_inverse_matrix_view( M const & m)
   {
      return {m};
   }

   template <typename M>
   inline
   typename quan::where_<
      quan::is_basic_matrix<M>
      ,basic_matrix< 
         M::rows, 
         M::cols, 
         typename M::value_type
      >
   >::type
   make_basic_matrix(M const & m)
   {
      return {m};
   }

  
} // quan



#endif // QUAN_BASIC_MATRIX_HPP_INCLUDED
