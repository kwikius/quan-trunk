#ifndef QUAN_HTML2_BC_REF_HPP_INCLUDED
#define QUAN_HTML2_BC_REF_HPP_INCLUDED

#include <quan/html2/body_content.hpp>

namespace quan { namespace html2{

   struct bc_ref : body_content {
   
      bc_ref(body_content* bc_in) : m_bc(bc_in){}
      ~bc_ref(){} // doesnt own the bc
     
      std::ostream & output(std::ostream & os)const
      {
        assert( m_bc);
        
        return m_bc->output(os);
      }

      void set_parent( body_content*  p) { 
        body_content::set_parent(p); m_bc->set_parent(p);
      }
      body_content* get_parent() const{return m_bc->get_parent();}
    
      private:
      body_content* m_bc;
   };
}}


#endif // QUAN_HTML2_BC_REF_HPP_INCLUDED
