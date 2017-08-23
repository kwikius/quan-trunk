#ifndef QUAN_DOM_DATA_NODE_HPP_INCLUDED
#define QUAN_DOM_DATA_NODE_HPP_INCLUDED

#include <typeinfo>

#include <quan/dom/leaf.hpp>
#include <quan/where.hpp>
#include <quan/concepts/ostreamable.hpp>
#include <quan/concepts/std_container.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/not.hpp>

/*
  a final leaf node holding some data
*/

namespace quan{ namespace dom{

   template <typename IdentifierType,typename DataType>
   class data_node : public leaf<IdentifierType,DataType>{

   public:

      typedef IdentifierType identifier_type;
      typedef DataType data_type;
     // typedef data_node* ptr;
    //  typedef typename node<identifier_type>::ptr node_ptr;
    //  typedef branch<IdentifierType>* branch_ptr;

      data_node(
         identifier_type const & id_in, data_type const & data_in)
      : m_id(id_in), m_data(data_in){}
      virtual ~data_node(){}
      identifier_type const & get_id()const {return m_id;}
      branch<IdentifierType>* get_parent() const
      {
         return m_parent;
      }
      void set_parent(branch<IdentifierType>* parent_in)
      {
         m_parent = parent_in;
      }
      std::ostream & output(std::ostream & os) const
      {
         os << "data node : ";
         do_output(os, this->m_data) ;
         os <<'\n';
         return os;
      }
      void set_data(data_type const & data){ m_data = data;}
      data_type  get_data()const {return m_data;}
      data_type & get_data_ref() {return m_data;}
      data_type const & get_data_cref()const {return m_data;}

      std::string get_type_id() const
      {
         std::string str = "data_node{";
         str += typeid(data_type).name();
         str += '}';
         return str;
      }

      private:
      template <typename V>
      static
      typename quan::where_<
         quan::is_model_of<quan::StdContainer_,V>,
         std::ostream &
      >::type
      do_output(std::ostream & os, V const & v)
      {
         for (typename V::const_iterator iter = v.begin(); iter != v.end() ; ++iter){
            os << '\n'<< *iter;
         }
         return os;
      }

      static std::ostream & do_output( std::ostream & os,
         std::list<std::pair<std::string, std::string> > const & v)
      {
         typedef std::list<std::pair<std::string, std::string> > list;
            for (list::const_iterator iter = v.begin(); iter != v.end() ; ++iter){
            os << '\n';
            os << '(' << iter->first << "," << iter->second << ')';
         }
         return os;
      }

      template <typename V>
      static
      typename quan::where_<
         quan::is_model_of<quan::Ostreamable_,V> ,
         std::ostream &
      >::type
      do_output( std::ostream & os, V const & v)
      {
         os << v;
         return os;
      }

      template <typename V>
      static
      typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<is_model_of<quan::StdContainer_,V> >,
         quan::meta::not_<is_model_of<quan::Ostreamable_,V> >
      >,
      std::ostream &
      >::type
      do_output( std::ostream & os, V const &)
      {
         os << typeid(V).name();
         return os;
      }

      identifier_type m_id;
      branch<IdentifierType>* m_parent;
      data_type m_data;

      data_node (data_node const &);
      data_node & operator = (data_node const &);
    };
}}//quan::dom

#endif

