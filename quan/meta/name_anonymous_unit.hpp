#ifndef QUAN_META_NAME_ANONYMOUS_UNIT_HPP_INCLUDED
#define QUAN_META_NAME_ANONYMOUS_UNIT_HPP_INCLUDED

namespace quan{ namespace meta{

//default to no change
   template <typename StaticUnit>
   struct name_anonymous_quantity{
      typedef StaticUnit type;
   };

}}

#endif
