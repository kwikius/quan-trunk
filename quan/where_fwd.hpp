#ifndef QUAN_WHERE_FWD_HPP_INCLUDED
#define QUAN_WHERE_FWD_HPP_INCLUDED

//Copyright Andy Little 2007. All rights reserved

namespace quan{

   template <bool C, typename T= void>
   struct where_c;

   template <typename C, typename T = void>
   struct where_ ;

   template <bool C, typename T>
   struct eval_where_c;

   template <typename C, typename T>
   struct eval_where ;

   template <typename C,typename T = void>
   struct where_not;

   template <typename C,typename T>
   struct eval_where_not;

}

#endif

