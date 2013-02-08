#ifndef QUAN_CONCEPT_CHECK_METAFUNCTION_HPP_INCLUDED
#define QUAN_CONCEPT_CHECK_METAFUNCTION_HPP_INCLUDED

// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{ namespace concept_check{ namespace meta{

   // assert that T is a metafunction
   template <typename T>
   inline
   void function()
   {
       typedef typename T::type type;
   }

}}} //quan::concept_check


#endif
 