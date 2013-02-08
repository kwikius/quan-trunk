#ifndef QUAN_AVR_IOSTREAM_HPP_INCLUDED
#define  QUAN_AVR_IOSTREAM_HPP_INCLUDED

 #include <quan/avr/cstddef_dummy.hpp>

 namespace std{

     template<typename T>
	  struct basic_ostream{
        basic_ostream & precision(std::size_t) {return *this;}
	  };

	  template <typename T, typename T1>
	  basic_ostream<T> & operator << (basic_ostream<T> & os, T1 const & x)
	  {
			 return os;

         
	  }

     typedef  basic_ostream<char> ostream;

     extern basic_ostream<char> cout ;
     extern basic_ostream<char> cerr ;

    typedef unsigned long size_t;

}

#endif