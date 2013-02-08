
#include <quan/gx/wxwidgets/dlg_symbol_io.hpp>
#include <quan/gx/wxwidgets/to_wxString.hpp>
#include <quan/from_string.hpp>
#include <iostream>
#include <cassert>

#include <quan/out/length.hpp>
#include <quan/out/angle.hpp>
#include <quan/fixed_quantity/io/input.hpp>
#include <quan/angle/input.hpp>
#include <quan/two_d/vect.hpp>
#include <sstream>

using quan::gx::wxwidgets::to_wxString;

//vector
template <typename T , int N>
quan::gx::wxwidgets::dialog_symbol_io<T,N>::dialog_symbol_io(
     wxDialog* parent,
     quan::gx::abc_symbol<T>* sym,
     wxSizer * vsizer  
)
:m_parent(parent),m_symbol(sym)
{  
   std::istringstream istr(sym->text());
   for (std::size_t i = 0; i < N ; ++i){
    std::string str;
    istr >> str ;
    m_static_text[i] = to_wxString(str);
   }
   for (int i = 0; i < N;++i){
      this->create(i,vsizer);
   }
}

//scalar
template <typename T >
quan::gx::wxwidgets::dialog_symbol_io<T,1>::dialog_symbol_io(
      wxDialog* parent,
     quan::gx::abc_symbol<T>* sym,
    wxSizer* vsizer 
)
:m_parent(parent),m_symbol(sym)
{ 
   this->create(vsizer);
}

//scalar
 template <typename T>
 void quan::gx::wxwidgets::dialog_symbol_io<T,1>::create(wxSizer* vsizer)
 {
   m_text_io =
   new wxTextCtrl(
      m_parent,
      wxID_ANY,
      to_wxString(m_symbol->cref()),
      wxDefaultPosition,
      wxDefaultSize
   );

   // owned by parent and will be deleted by parent dialog!
   auto hsizer = new wxBoxSizer(wxHORIZONTAL);
  
   hsizer->Add(
      new wxStaticText(
         m_parent,
         -1,
         to_wxString(m_symbol->text()),
         wxDefaultPosition,
         wxDefaultSize,
         0
      ),
      wxSizerFlags{}.Border(wxALL,10).Align(wxALIGN_CENTER_VERTICAL)
   );
   hsizer->Add(m_text_io,wxSizerFlags{}.Border(wxALL,10));

   vsizer->Add(hsizer);
 }
 
namespace {

   template <typename T>
   T& get_at_vect(quan::two_d::vect<T>& vect, int i)
   {
       switch (i){
         case 0:
         return vect.x;
         case 1:
         return vect.y;
         default:
         assert(false);
         return vect.x; // prevent warnings
       }
   }
   template <typename T>
   T const & get_at_vect(quan::two_d::vect<T> const & vect, int i)
   {
       switch (i){
         case 0:
         return vect.x;
         case 1:
         return vect.y;
         default:
         assert(false);
         return vect.x; // avoid warnings
       }
   }

//   wxString get_axis_string(int i)
//   {
//      switch (i){
//         case 0:
//         return wxT("X");
//         case 1:
//         return wxT("Y");
//         case 2:
//         return wxT("Z");
//         default:
//         assert(false);
//         return wxT(""); // avoid warnings
//       }
//   }
}


  template <typename T, int N>
  void quan::gx::wxwidgets::dialog_symbol_io<T,N>::create( 
      int i, wxSizer* vsizer
  )
 {
   
   m_text_io[i] =
   new wxTextCtrl(
      m_parent,
      wxID_ANY,
      to_wxString(get_at_vect(m_symbol->cref(),i)),
      wxDefaultPosition,
      wxDefaultSize
   );

   // owned by parent and will be deleted by parent dialog!
   auto hsizer = new wxBoxSizer(wxHORIZONTAL);
  
   hsizer->Add(
      new wxStaticText(
         m_parent,
         -1,
         m_static_text[i],
        // get_axis_string(i),
        // to_wxString(m_symbol->name()),
         wxDefaultPosition,
         wxDefaultSize,
         0
      ),
      wxSizerFlags{}.Border(wxALL,10).Align(wxALIGN_CENTER_VERTICAL)
   );
   hsizer->Add(m_text_io[i],wxSizerFlags{}.Border(wxALL,10));
   vsizer->Add(hsizer);
 }

 template <typename T,int N>
 int quan::gx::wxwidgets::dialog_symbol_io<T,N>::write_changes()const
{
   int res = 0;
   for (int i = 0; i < N; ++i){
     auto res1 = write_change_impl(i);
     if ( res1 ==-1){
       return -1;
     }else {
       res |= res1;
     }
   }
   return res;
}
  /*
  returns  
  1 if changed,
  0 if ok but not changed,
  or -1 if failed due usually incorrect text input or range

*/

 template <typename T,int N>
 int quan::gx::wxwidgets::dialog_symbol_io<T,N>::write_change_impl(
   int i )const
{
    typedef typename T::value_type value_type; 
    auto val = value_type{};
    wxString fail_msg;
    try{
      val = quan::from_string<value_type>(std::wstring{m_text_io[i]->GetValue()});
    }
    catch (std::exception & e){
      fail_msg += wxT("cant write \"");
      fail_msg += to_wxString(m_symbol->name());
      fail_msg += wxT(".");
      fail_msg += m_static_text[i];
      fail_msg += wxT(" using \"");
      fail_msg += this->m_text_io[i]->GetValue();
      fail_msg += wxT("\"");
      fail_msg += wxT(", no changes written. ");
      wxMessageBox(fail_msg);
      return -1; // fail no change
    } 

   if (get_at_vect( m_symbol->cref(),i) != val){
      if (val > get_at_vect(m_symbol->max(),i)){
         wxString str = wxT("\"");
         str += to_wxString(m_symbol->name()) ;
         str += wxT(".");
         str += m_static_text[i];
         str +=  wxT("\" : ");
         str += this->m_text_io[i]->GetValue();
         str += wxT(" greater than max allowed(");
         str += to_wxString(get_at_vect(m_symbol->max(),i)) ;
         str += wxT(")");
         str += wxT(", no changes written. ");
         wxMessageBox(str);
         return -1; // fail no change
      } else {
         if (val < get_at_vect(m_symbol->min(),i)){
               wxString str = wxT("\"");
               str += to_wxString(m_symbol->name()) ;
               str += wxT(".");
               str += m_static_text[i];
               str +=  wxT("\" : ");
               str += this->m_text_io[i]->GetValue();
               str += wxT(" less than min allowed(");
               str += to_wxString(get_at_vect(m_symbol->min(),i)) ;
               str += wxT(")");
               str += wxT(", no changes written. ");
               wxMessageBox(str);
               return -1;
         }
         else{
            get_at_vect(m_symbol->ref(),i) = val;
            return 1;  // success and changed
         }
      }
   }else{
      return 0; // success but same value so no update
   }

 return 0;
}

 template <typename T>
 int quan::gx::wxwidgets::dialog_symbol_io<T,1>::write_changes()const
{

    T val = T{};
    wxString fail_msg;
    try{
      val = quan::from_string<T>(std::wstring{m_text_io->GetValue()});
    }
    catch (std::exception & e){
      fail_msg += wxT("cant write \"");
      fail_msg += to_wxString(m_symbol->name());
      fail_msg += wxT(" using \"");
      fail_msg += this->m_text_io->GetValue();
      fail_msg += wxT("\"");
      fail_msg += wxT(", no changes written. ");
      wxMessageBox(fail_msg);
      return -1; // fail no change
    } 

   if ( m_symbol->cref() != val){
      if (val > m_symbol->max()){
         wxString str = wxT("\"");
         str += to_wxString(m_symbol->name()) ;
         str +=  wxT("\" : ");
         str += this->m_text_io->GetValue();
         str += wxT(" greater than max allowed(");
         str += to_wxString(m_symbol->max()) ;
         str += wxT(")");
         str += wxT(", no changes written. ");
         wxMessageBox(str);
         return -1; // fail no change
      } else {
         if (val < m_symbol->min()){
               wxString str = wxT("\"");
               str += to_wxString(m_symbol->name()) ;
               str +=  wxT("\" : ");
               str += this->m_text_io->GetValue();
               str += wxT(" less than min allowed(");
               str += to_wxString(m_symbol->min()) ;
               str += wxT(")");
               str += wxT(", no changes written. ");
               wxMessageBox(str);
               return -1;
         }
         else{
            m_symbol->ref() = val;
            return 1;  // success and changed
         }
      }
   }else{
      return 0; // success but same value so no update
   }

 return 0;
}

template struct quan::gx::wxwidgets::dialog_symbol_io<int>;
template struct quan::gx::wxwidgets::dialog_symbol_io<double>;
template struct quan::gx::wxwidgets::dialog_symbol_io<quan::length::mm>;
template struct quan::gx::wxwidgets::dialog_symbol_io<quan::angle::deg>;
template struct quan::gx::wxwidgets::dialog_symbol_io<quan::two_d::vect<double> >;
template struct quan::gx::wxwidgets::dialog_symbol_io<quan::two_d::vect<quan::length::mm> >;



