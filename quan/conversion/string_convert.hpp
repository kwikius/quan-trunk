#ifndef QUAN_CONVERSION_STRING_CONVERT_HPP_INCLUDED
#define QUAN_CONVERSION_STRING_CONVERT_HPP_INCLUDED


#include <quan/convert.hpp>
#include <climits>
#include <cstdint>

namespace quan{ namespace detail{

	template<int N > struct converter <const char(&)[N],float>
   {
      private:
		 
        static const char array[N];
        int conversion_error;

      public:
        converter():conversion_error{0}{}
        typedef const char(& array_ref) [N];

        typedef const char (array_type) [N];
        array_ref operator()( float in) 
        {
				for ( int i = 0; i < N;++i){
				  array[i] = '\0';
				}
            
        }
   };

   template<int N > typename converter<const char(&)[N],float>::array_type converter<const char(&)[N],float>::array;

}}

#endif // QUAN_CONVERSION_STRING_CONVERT_HPP_INCLUDED
