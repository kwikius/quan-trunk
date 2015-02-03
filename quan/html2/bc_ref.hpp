#ifndef QUAN_HTML2_BC_REF_HPP_INCLUDED
#define QUAN_HTML2_BC_REF_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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
