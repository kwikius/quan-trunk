#ifndef QUAN_GX_WXWIDGETS_DIALOG_SYMBOL_IO_HPP_INCLUDED
#define QUAN_GX_WXWIDGETS_DIALOG_SYMBOL_IO_HPP_INCLUDED

#include <wx/wx.h>
#include <quan/gx/abc_symbol.hpp>
#include <quan/archetypes/scalar.hpp>
#include <quan/archetypes/vector.hpp>
#include <quan/meta/get_num_elements.hpp>

namespace quan{ namespace gx{ namespace wxwidgets{

/*
    dialog_symbol_io connects  symbol

*/
    template <typename T, int N = quan::meta::get_num_elements<T>::value>
    struct dialog_symbol_io {
      dialog_symbol_io(
         wxDialog* parent, 
         quan::gx::abc_symbol<T>* symbol,
         wxSizer* vsizer 
      );

      int  write_changes( ) const;

     private:
      void create(int n, wxSizer* vsizer);
      int write_change_impl(int i) const;

      wxWindow*                       m_parent;
      quan::gx::abc_symbol<T>*        m_symbol;
      wxTextCtrl*                     m_text_io[N];
      wxString                        m_static_text[N];
     
    };

    template <typename T>
    struct dialog_symbol_io<T,1> {
      dialog_symbol_io(
         wxDialog* parent, 
         quan::gx::abc_symbol<T>* symbol ,
         wxSizer* vsizer
      );
      static const int m_num_elements = 1;
    //  int get_num_elements() const {return 1;}

      int  write_changes() const;
     
     private:
      void create(wxSizer* vsizer);

      wxWindow*                       m_parent;
      quan::gx::abc_symbol<T>*        m_symbol;
      wxTextCtrl*                     m_text_io;

     
    };

}}}


#endif // QUAN_GX_WXWIDGETS_DIALOG_SYM_IO_HPP_INCLUDED
