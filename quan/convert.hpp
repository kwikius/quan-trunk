#ifndef QUAN_CONVERT_HPP_INCLUDED
#define QUAN_CONVERT_HPP_INCLUDED


namespace quan{

   namespace detail{

     template < typename Target, typename Src> struct converter;
    
   }
   // when converting to char* must free the result
	template<typename Target, typename Src> inline  Target convert(Src src)
   {
     quan::detail::converter<Target,Src> conv;
      //get conv error if any...S

     return conv(src);
   }

  
}

#endif // QUAN_CONVERT_HPP_INCLUDED
