#ifndef QUAN_FUN_ROW_SEQUENCE_HPP_INCLUDED
#define QUAN_FUN_ROW_SEQUENCE_HPP_INCLUDED

#include <quan/fun/at_seq.hpp>
#include <quan/fun/access_modifiers.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/matrix_row.hpp>
#include <quan/fun/seq_arg_type.hpp>

namespace quan{namespace fun{

   template<typename Matrix>
   struct row_sequence{
      typedef typename seq_arg_type<Matrix>::type arg_type;
      arg_type m_matrix;
      row_sequence(arg_type m):m_matrix(m){}
      typedef typename quan::meta::if_<
         std::is_const<Matrix>,
         as_const_ref,
         as_ref
      >::type access_type;
   };

   template <typename Matrix>
   struct is_fun_sequence_impl<row_sequence<Matrix> > : std::true_type{};

   template <typename Matrix>
   struct size_seq_impl<row_sequence<Matrix> > : quan::meta::int32<
     (Matrix::rows)
   >{};

   template <int I,typename Matrix, typename F>
   struct at_seq_impl<I,row_sequence<Matrix>,F >{
      
     typedef matrix_row<I,Matrix> type;
             
      //typename at_seq<I,Seq,as_const_ref>::type
      type
      operator()(row_sequence<Matrix> const & seq) const
       {
         //BOOST_STATIC_ASSERT((false));
         /*at_seq<I,Seq, as_const_ref> at_seq_var;*/
         return type(seq.m_matrix);
       }

       type
       operator()(row_sequence<Matrix> & seq) const
       {
       // check if this is used
         return type(seq.m_matrix);
       }
       
   };

   template <typename Matrix>
   row_sequence<const Matrix> row_sequence_fx(Matrix const & m)
   {
      return row_sequence<const Matrix>(m);
   }
   
}}

#endif
