#ifndef QUAN_AVR_STRING_DUMMY_HPP_INCLUDED
#define QUAN_AVR_STRING_DUMMY_HPP_INCLUDED

#include <quan/avr/cstddef_dummy.hpp>

namespace std{

   template<typename T>
   struct basic_string{

    std::size_t length() const {return 0;}

    T  operator[] (std::size_t i) const { return T();}

     template<typename T1> T1 widen(T1) const { return T1();}

   };

  typedef std::basic_string<char> string;

}

#endif // QUAN_AVR_STRING_DUMMY_HPP_INCLUDED
