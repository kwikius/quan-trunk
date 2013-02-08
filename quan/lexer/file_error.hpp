#ifndef QUAN_LEXER_FILE_ERROR_HPP_INCLUDED
#define QUAN_LEXER_FILE_ERROR_HPP_INCLUDED

#include <stdexcept>
//#include <quan/lexer/istream.hpp>
#include <string>

namespace quan{ namespace lexer{

  template<typename CharType> struct istream;

// will need to sort wide stream
   template <typename CharType>
   struct file_error : std::runtime_error{
       typedef quan::lexer::istream<CharType> istream_type;
      file_error(
         istream_type const & fin,
         std::string const & text_in
      )
      :  std::runtime_error(text_in),
         pos(fin.get_source_pos()),
         file_name(fin.get_stream_id()),
         last_check_point(fin.get_check_point())
      {}
      ~file_error() throw() {}
      quan::lexer::source_pos pos;
      std::string file_name;
      quan::lexer::check_point last_check_point;

   };

}}

#endif

