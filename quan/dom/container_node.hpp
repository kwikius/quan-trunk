#ifndef QUAN_DOM_CONTAINER_NODE_HPP_INCLUDED
#define QUAN_DOM_CONTAINER_NODE_HPP_INCLUDED

#include <quan/dom/branch.hpp>
#include <quan/dom/container_tags/get_container_type_id.hpp>

/*
  container node is a branch of some container type
  The container tag represents the container type
*/

namespace quan{ namespace dom{

   template <typename ContainerTag>
   class container_node : public branch<typename ContainerTag::identifier_type>{
      public:
      typedef ContainerTag container_tag;
      typedef typename container_tag::identifier_type identifier_type;
      typedef typename container_tag::container_type container_type;
      typedef branch<identifier_type>* branch_ptr;
      typedef typename container_tag::node_ptr node_ptr;
      typedef std::size_t size_type;
    //  typedef container_node* ptr;

      container_node(identifier_type const & id_in)
      :m_id(id_in){}
      virtual ~container_node(){}

      identifier_type const & get_id()const {return m_id;}
      branch_ptr get_parent() const 
      {
         return m_parent;
      }
      void set_parent(branch_ptr parent_in)
      {
         m_parent = parent_in;
      }
      container_type const & get_container() const{ return m_container;}
      container_type & get_container(){ return m_container;} 

      node_ptr get_child(identifier_type const & id)const
      {
         return container_tag::get_child(this->m_container,id);
      }
      bool remove_child(identifier_type const & id)
      {
            return container_tag::remove_child(this->m_container,id);
      }
      void add_child(node_ptr const & in )
      {
         //add check on id already exist?
         in->set_parent(this->get_parent());
         container_tag::add_child(this->m_container,in);
      }
      std::string get_type_id() const
      {
         return get_container_type_id<typename container_tag::container_type>::apply();
      } 

      std::ostream & output(std::ostream & os) const
      {
         os << "container node : \"";
         container_tag::output(this->m_container,os);
         os << "\"";
         return os;
      }

      size_type size()const
      {
         return container_tag::size(this->m_container);
      }
      bool empty() const
      {
         return container_tag::is_empty(this->m_container);

      }
      private:

      identifier_type m_id;
      branch_ptr m_parent;
      container_type m_container;   
   };

}}//quan::dom

#endif

