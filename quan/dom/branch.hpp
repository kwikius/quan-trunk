#ifndef QUAN_DOM_BRANCH_HPP_INCLUDED
#define QUAN_DOM_BRANCH_HPP_INCLUDED

#include <map>

#include <quan/dom/node.hpp>
#include <quan/dom/except.hpp>

/*
   abstract base class for all branch nodes
*/

namespace quan{ namespace dom{

   template <typename IDType> class node;

   template <typename IDType>
   class branch : public  node<IDType>{
    private:
      typedef IDType identifier_type;
      typedef node<identifier_type>* node_ptr;
      typedef std::map<identifier_type,node_ptr> container_type;
    public:
      branch(identifier_type const & id):m_id{id},m_parent{nullptr}{}
      ~branch(){}

      void add_child(node_ptr in )
      {
         if (!in ){
              throw bad_node("bad node in branch add_child");
         }
         auto const child_id = in->get_id();
         if (this->get_child(child_id) != nullptr){
             throw element_id_already_exists(child_id);
         }
         m_container[child_id] = in;
         in->set_parent(this);
      }
      node_ptr get_child(identifier_type const & id)const
      {
         auto iter = m_container.find(id);
         if(iter != m_container.end())
         {
            return iter->second;
         }
         else{
            return  nullptr;
         }
      }
      bool remove_child(identifier_type const & id)
      {
         auto iter = m_container.find(id);
         if(iter != m_container.end()){
            delete iter->second;
            m_container.erase(iter);
            return true;
         }
         else{
            return false;
         }

      }

      std::ostream & output(std::ostream & os)const
       {
            auto iter = m_container.begin();
            while (iter != m_container.end()){
               
               iter->second->output(os);
               //(*iter)->output(os);
                ++iter ;
            }
            return os;
        }

      identifier_type const & get_id()const {return m_id;}
      branch* get_parent() const 
      {
         return m_parent;
      }

      void set_parent(branch* parent_in)
      {
         m_parent = parent_in;
      }
      std::string get_type_id() const { return "branch";}
    private:
      identifier_type m_id;
      branch* m_parent;
      container_type m_container;

      branch & operator = ( branch &) = delete;
      branch(branch const &) = delete;
   };

}}//quan::dom

#endif

