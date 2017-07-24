#ifndef QUAN_DOM_CONTAINER_DATA_HPP_INCLUDED
#define QUAN_DOM_CONTAINER_DATA_HPP_INCLUDED

#include <quan/dom/leaves/data_node.hpp>
#include <quan/dom/container_node.hpp>

namespace quan{ namespace dom{

   template <typename ContainerTag, typename DataType>
   class container_data :
      public container_node<ContainerTag>,
      public data_node<typename ContainerTag::identifier_type,DataType> {
    private:
      typedef typename ContainerTag::identifier_type identifier_type;
      typedef container_data* ptr;
      typedef typename branch<identifier_type>::ptr branch_ptr;
    public:  
      std::string get_type_id() const{ return "container_data";}
      identifier_type const & get_id()const {return container_node<ContainerTag>::get_id();}
      branch_ptr get_parent() const
      {
         return container_node<ContainerTag>::get_parent();
      }
      void set_parent(branch_ptr const & parent_in)
      {
         return container_node<ContainerTag>::set_parent(parent_in);
      }

      std::ostream & output(std::ostream & os) const
      {
         data_node<identifier_type,DataType>::output(os);
         os <<'\n';
         container_node<ContainerTag>::output(os);
         return os;
      }

      container_data(identifier_type const & id_in, DataType const & data_in)
      :   container_node<ContainerTag>(id_in),data_node<identifier_type,DataType>(id_in,data_in)
      {}
    };

}}//quan::dom

#endif

