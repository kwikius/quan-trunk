#ifndef QUAN_DOM_GET_CONTAINER_TYPE_ID_HPP_INCLUDED
#define QUAN_DOM_GET_CONTAINER_TYPE_ID_HPP_INCLUDED

#include <list>
#include <vector>
#include <map>

#include <string>

namespace quan{ namespace dom{

   template <typename T>
   struct get_container_type_id;

   template <typename T, typename Allocator>
   struct get_container_type_id<std::list<T,Allocator> > {
       static std::string apply()
       {
            return "std::list";
       }
   };

   template <typename T, typename Allocator>
   struct get_container_type_id<std::vector<T,Allocator> > {
       static std::string apply()
       {
           return "std::vector";
       }
   };

   template <typename K, typename T,typename C,typename A>
   struct get_container_type_id<std::map<K,T,C,A> >{
       static std::string apply()
       {
           return "std::map";
       }
   };

}}

#endif // QUAN_DOM_GET_CONTAINER_TYPE_ID_HPP_INCLUDED
