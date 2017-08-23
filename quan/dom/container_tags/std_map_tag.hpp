#ifndef QUAN_DOM_STD_MAP_TAG_HPP_INCLUDED
#define QUAN_DOM_STD_MAP_TAG_HPP_INCLUDED

#include <quan/dom/container_node.hpp>
#include <quan/dom/container_tags/std_sequence_tag.hpp>
#include <quan/dom/alg/add_branch.hpp>
#include <map>

namespace quan{ namespace dom{

   template <typename IDType>
   struct std_map_tag :
      std_sequence_tag<
         IDType,std::map<IDType,node<IDType>*>
      >
   {

      typedef IDType identifier_type;
      typedef node<identifier_type>* node_ptr;
      typedef std::map<identifier_type,node_ptr> container_type;

      static node_ptr
      get_child(container_type const & seq, identifier_type const & id)
      {
         typename container_type::const_iterator iter = seq.find(id);
         if(iter != seq.end())
         {
            return iter->second;
         }
         else{
            return  nullptr;
         }
      }

      static bool remove_child(container_type & seq,identifier_type const & id)
      {
         typename container_type::iterator iter = seq.find(id);
         if(iter != seq.end())
         {
            delete iter->second;
            seq.erase(iter);
            return true;
         }
         else{
            return false;
         }
      }

       static std::ostream & output(container_type const &  seq,std::ostream & os)
       {
            typename container_type::const_iterator iter = seq.begin();
            while (iter != seq.end()){
               iter->second->output(os);
                ++iter ;
            }
            return os;
        }

       static void add_child(container_type & seq,node_ptr const & in )
       {
            seq[in->get_id()]= in;
       }

       static bool is_empty(container_type const & seq)
       {
         return seq.empty();
       }

       static typename container_type::size_type size(container_type const & seq)
        {
            return seq.size();
        }

   };

   template <
      typename IDType, typename ID1
   >
   inline
   container_node<std_map_tag<IDType> >*
   add_map_branch(node<IDType>* p, ID1 const & id_in)
   {
      return add_branch<std_map_tag<IDType> >(p,id_in);
   }

   template <
   typename IDType, typename ID1, typename T
   >
   inline
   container_data<std_map_tag<IDType>,T>*
   add_map_branch(node<IDType>* p, ID1 const & id_in,T const & t)
   {
      return add_branch<std_map_tag<IDType> >(p,id_in,t);
   }

}}//quan::dom

#endif

