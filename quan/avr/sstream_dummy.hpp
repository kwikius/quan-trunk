#ifndef QUAN_AVR_SSTREAM_DUMMY_HPP_INCLUDED
#define QUAN_AVR_SSTREAM_DUMMY_HPP_INCLUDED

#include <quan/avr/string_dummy.hpp>

namespace std{

 template<typename C>
  struct basic_ostringstream{
     std::basic_string<C> const & str() const;
   };

   typedef basic_ostringstream<char> ostringstream;
}

#endif
