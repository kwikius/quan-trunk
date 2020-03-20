#ifndef QUAN_DOM_DATA_NODE_HPP_INCLUDED
#define QUAN_DOM_DATA_NODE_HPP_INCLUDED

#include <quan/config.hpp>

#if ! defined QUAN_NO_RTTI
#include <typeinfo>
#endif
#include <iomanip>

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

   inline 
   std::ostream & 
   do_output(std::ostream & os, std::string const & str)
   {
      return os << '"' << str << '"' ;
   }

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
         auto const depth = get_path_depth(this);
            for ( auto i = 0; i < depth; ++i){
               os << "   ";
         }
         os << this->m_id << " = " ;
         do_output(os, this->m_data) ;
         os << " ;\n";
         return os;
      }
      void set_data(data_type const & data){ m_data = data;}
      data_type  get_data()const {return m_data;}
      data_type & get_data_ref() {return m_data;}
      data_type const & get_data_cref()const {return m_data;}

      std::string get_type_id() const
      {
#if defined QUAN_NO_RTTI
        return "data_node; type_id N/A without RTTI";
#else
         std::string str = "data_node{";
         str += typeid(data_type).name();
         str += '}';
         return str;
#endif
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
         
         os << "[ ";
         for (typename V::const_iterator iter = v.begin(); iter != v.end() ; ++iter){
            if (iter != v.begin()){
               os << ", ";
            }
            //os << *iter;
            do_output(os,*iter);
         }
         os << " ]";
         return os;
      }

      template <typename V>
      static
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::Ostreamable_,V>
            ,quan::meta::not_<std::is_same<V,bool> >
            ,quan::meta::not_<std::is_same<V,std::string> >
         >
         ,std::ostream &
      >::type
      do_output( std::ostream & os, V const & v)
      {
         os.unsetf( std::ios::floatfield );
         os.precision(7);
         os.setf( std::ios::fixed, std::ios::floatfield );
         os << std::showpoint <<  v ;
         return os;
      }

      template <typename Str>
      static
      typename quan::where_<
         std::is_same<Str,std::string> ,
         std::ostream &
      >::type
      do_output( std::ostream & os, Str const & str)
      {
         return os << '"' << str << '"' ;
      }

      template <typename V>
      static
      typename quan::where_<
         std::is_same<V,bool> ,
         std::ostream &
      >::type
      do_output( std::ostream & os, V const & v)
      {
         os << std::boolalpha << v ;
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
#if defined QUAN_NO_RTTI
         os << "do_output : typeid N/A without RTTI";
#else
         os << typeid(V).name();
#endif
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


