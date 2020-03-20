#ifndef QUAN_OUT_FORMAT_PRINT_HPP_INCLUDED
#define QUAN_OUT_FORMAT_PRINT_HPP_INCLUDED

#include <cassert>
#include <cstring>
#include <iostream>

namespace quan{

   struct format_print{

      format_print(int cell_length,int cell_fp_pos, int num_integer_digits, int num_decimals)
      : m_cell_length{cell_length}
      , m_cell_fp_pos{cell_fp_pos}
      , m_num_integer_digits{num_integer_digits}
      , m_num_decimals{num_decimals}
      , m_rep_length{num_integer_digits + num_decimals + 2}
      , m_start_idx{cell_fp_pos - (num_integer_digits +1)}
      , m_buf {new char[cell_length +1]} 
      {
         assert( cell_fp_pos >= num_integer_digits +1);
         assert(num_integer_digits < 10);
         assert(num_decimals < 10);
         assert(m_rep_length <= m_cell_length);
         
         char format_str[] = "% #.#f";
         format_str[2] = static_cast<char>(m_rep_length + '0');
         format_str[4] = static_cast<char>(m_num_decimals + '0');
         strcpy(m_format_str,format_str);
      }

      ~format_print()
      {
          delete [] m_buf;
      }

      private:
      int m_cell_length;
      int m_cell_fp_pos; 
      int m_num_integer_digits; 
      int m_num_decimals;
      int m_rep_length;
      int m_start_idx;
      char m_format_str[7];
      char * m_buf;
      public:
      void operator()(double const & v,std::ostream & out = std::cout)const
      {
         memset(m_buf,' ',m_cell_length);
         int result = snprintf(m_buf + m_start_idx,m_rep_length+1,m_format_str, v);

         if ( (result > 0) && ( result < (m_rep_length +1)) ) {
            if ( (m_start_idx + result) < m_cell_length){
               m_buf[m_start_idx + result] = ' ';
            }
            out << m_buf ;
         }
      }
      private:
         format_print(format_print &&)= delete;
         format_print(format_print &)= delete;
         format_print(format_print const &)= delete;
         format_print& operator = (format_print const &)= delete;
         format_print& operator = (format_print &)= delete;
         format_print& operator = (format_print &&)= delete;
  };
}


#endif // QUAN_OUT_FORMAT_PRINT_HPP_INCLUDED
