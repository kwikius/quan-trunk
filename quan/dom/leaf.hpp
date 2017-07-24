#ifndef QUAN_DOM_LEAF_HPP_INCLUDED
#define QUAN_DOM_LEAF_HPP_INCLUDED

#include <quan/dom/node.hpp>

/*
   abstract base class for all leaf nodes
*/

namespace quan{ namespace dom{

    template <typename IDType,typename DataType>
    class leaf : public virtual node<IDType>{
      public:
        typedef IDType identifier_type;
        typedef DataType data_type;
        leaf(){}
        virtual ~leaf(){}
        virtual void set_data(data_type const & data)=0;
        virtual data_type get_data()const =0;
        virtual data_type& get_data_ref() =0;
        virtual data_type const & get_data_cref()const=0;
      private :
         leaf(leaf const &)= delete;
         leaf & operator=(leaf const &)=delete;
    };

}}//quan::dom

#endif

