#ifndef QUAN_DOM_BRANCH_HPP_INCLUDED
#define QUAN_DOM_BRANCH_HPP_INCLUDED

#include <quan/dom/node.hpp>

/*
   abstract base class for all branch nodes
*/

namespace quan{ namespace dom{

   template <typename IDType> class node;

   template <typename IDType>
   class branch : public virtual node<IDType>{
    private:
      typedef IDType identifier_type;
      typedef node<identifier_type>* node_ptr;
    public:
      branch(){}
      virtual ~branch(){}

      virtual void add_child(node_ptr const & in )=0;
      virtual node_ptr get_child(identifier_type const & id)const=0;
      virtual bool remove_child(identifier_type const & id)=0;
      
    private:
      branch & operator = ( branch &) = delete;
      branch(branch const &) = delete;
   };

}}//quan::dom

#endif

