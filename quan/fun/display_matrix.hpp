#ifndef QUAN_FUN_DISPLAY_MATRIX_HPP_INCLUDED
#define QUAN_FUN_DISPLAY_MATRIX_HPP_INCLUDED

#include <quan/fusion/matrix.hpp>
#include <quan/fun/for_each.hpp>

namespace quan { namespace fun{

   namespace detail{
      // type dependent print formatting functions
      inline void print_format(int v)
      {
         printf("% 5i ?",v);  // int in 6 characters
      }

      template <typename T>
      
      inline 
      typename quan::where_<std::is_floating_point<T> >::type
      print_format(T v)
      {
         printf("% 8.3f",v);  // float in 9 characters
      }

      template <typename T> struct num_chars;

      template <>
      struct num_chars<float>{
         static constexpr int value = 9;
      };

      template <>
      struct num_chars<double>{
         static constexpr int value = 9;
      };

      template <>
      struct num_chars<int>{
         static constexpr int value = 6;
      };

      template <typename T>
      inline void print_sep(char ch)
      {
         for ( int i=0; i < num_chars<T>::value; ++i){
            printf("%c",ch);
         }
      }

      template <typename T, int C>
      inline void print_seps()
      {
          printf("|");
          for ( int i = 0; i < C; ++i){
            if ( (i == 0) || ( i == ( C-1))){
               print_sep<T>('-');
            }else{
               print_sep<T>(' ');
            }
          }
          printf("|\n");
      }

      struct output_format{

         template <typename T>
         struct result{
            typedef void type;
         };

         template <typename T>
         typename result<T>::type
         operator()(T const & v)const
         {
            print_format(v);
            printf(" ");
         }
      };

      template <int N, typename Matrix>
      inline
      typename quan::where_c< 
         (N == (quan::fun::matrix_row_size<Matrix>::value -1))
         ,void
      >::type
      display_matrix_n(Matrix const & m)
      {
         typedef quan::fun::matrix_row<N,const Matrix> last_row;
         printf("|");
         quan::fun::for_each(last_row{m},detail::output_format{});
         printf("|\n");
      }

      template <int N, typename Matrix>
      inline
      typename quan::where_c< 
         (N < (quan::fun::matrix_row_size<Matrix>::value -1))
         ,void
      >::type
      display_matrix_n(Matrix const & m)
      {
         typedef quan::fun::matrix_row<N,const Matrix> row_n;
         printf("|");
         quan::fun::for_each(row_n{m},detail::output_format{});
         printf("|\n");
         display_matrix_n<N+1>(m);
      }

   }  // detail

#if defined __cpp_concepts
   inline void display(quan::fusion::Matrix const & m, const char * text = nullptr)
#else
   template < typename M>
   inline
   typename quan::where_<
      quan::is_model_of<quan::fusion::Matrix_, M>
      ,void
   >::type
   display(M const & m, const char * text = nullptr)
#endif
   {
      typedef typename quan::meta::strip_cr<decltype(m. template at<0,0>())>::type arg_type;
      int constexpr C = quan::fun::matrix_col_size<decltype(m)>::value;  
      if (text != nullptr){
         printf("\n%s\n",text);
      }
      detail::print_seps<arg_type,C>();
      detail::display_matrix_n<0>(m);
      detail::print_seps<arg_type,C>();
   }

}} //quan::fun

#endif // QUAN_FUN_DISPLAY_MATRIX_HPP_INCLUDED
