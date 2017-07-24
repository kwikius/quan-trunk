#ifndef QUAN_DOM_NODE_HPP_INCLUDED
#define QUAN_DOM_NODE_HPP_INCLUDED

#include <iostream>
/*
   abstract base class for all dom nodes
*/

namespace quan{ namespace dom{

    template <typename IDType>
    class branch;
   
    template <typename IDType>
    class node  {
    public:
     
     // typedef node* ptr;
     // typedef branch<IDType> * branch_ptr;
      typedef int flags_type;
      typedef IDType identifier_type;

      enum {of_test = 0, of_create = 1, of_exist = 2};

      node(){}
      virtual ~node(){}

      virtual identifier_type const & get_id()const=0;
      virtual std::string get_type_id() const=0;
      virtual std::ostream & output(std::ostream & os) const =0;
      // node doesnt own parent
      virtual branch<IDType> * get_parent() const=0;
      virtual void set_parent(branch<IDType> * parent_in)=0;
      bool is_head()const 
      {
         return !(get_parent());
      }

     private:
      node & operator = ( node &) = delete;
      node(node const &) = delete;

     };

}}//quan::dom



#endif

