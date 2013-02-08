#ifndef QUAN_AVR_LOCALE_DUMMY_HPP_INCLUDED
#define QUAN_AVR_LOCALE_DUMMY_HPP_INCLUDED


namespace std{

   template<typename C>
   struct ctype{
 
     template <typename T> T& widen(T & in){return in;}

     C widen(C)const{ return C();}

   };

   struct locale{
     locale(){}
   };

   template<class Facet> inline const Facet& use_facet(const locale&){return Facet();}


}//std


#endif // QUAN_AVR_LOCALE_DUMMY_HPP_INCLUDED
