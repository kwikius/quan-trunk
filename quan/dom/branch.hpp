#ifndef QUAN_DOM_BRANCH_HPP_INCLUDED
#define QUAN_DOM_BRANCH_HPP_INCLUDED

#include <map>

#include <quan/config.hpp>
#if defined QUAN_NO_EXCEPTIONS
#include <cassert>
#endif

#include <quan/dom/node.hpp>
#include <quan/dom/except.hpp>
#include <quan/dom/alg/get_path_depth.hpp>

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
      ~branch()
       {
         auto iter = m_container.begin();
         while (iter != m_container.end()){
            delete iter->second;
            m_container.erase(iter);
             ++iter ;
         }
       }

      void add_child(node_ptr in )
      {
#if defined QUAN_NO_EXCEPTIONS
        assert(( in != nullptr ) && "bad node in branch add_child");
#else
         if (!in ){
              throw bad_node("bad node in branch add_child");
         }
#endif
         auto const child_id = in->get_id();
#if defined QUAN_NO_EXCEPTIONS
         assert ( (this->get_child(child_id) == nullptr) && "element already exists");
#else
         if (this->get_child(child_id) != nullptr){
             throw element_id_already_exists(child_id);
         }
#endif
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
            auto const depth = get_path_depth(this);
            for ( auto i = 0; i < depth; ++i){
               os << "   ";
            }
            os << m_id << " {\n";
            auto iter = m_container.begin();
            while (iter != m_container.end()){
               iter->second->output(os);
                ++iter ;
            }
            for ( auto i = 0; i < depth; ++i){
               os << "   ";
            }
            return os << "}\n";
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

