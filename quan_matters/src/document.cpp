
#include <quan/html2/document.hpp>
#include <quan/html2/head_tag.hpp>
#include <quan/html2/body_or_frameset.hpp>
#include <cassert>

void quan::html2::document::set_head(head_tag* head)
{
  m_head = head;
  m_head->set_document(this);
}
void quan::html2::document::set_body (
  body_or_frameset * body
) 
{ 
 m_body = body;
  m_body->set_document(this);
}

quan::html2::document::document(std::string * title_in, int version_number_in)
:m_head{nullptr}, m_body(nullptr), m_root{nullptr}, m_offset{nullptr}, 
   m_title{title_in}, m_version_number{version_number_in}
{ }

quan::html2::document::~document()
{
   delete m_head;
   delete m_body;
   delete m_root;
   delete m_offset;
   delete m_title;
}

std::ostream & quan::html2::document::output(std::ostream & os)
{
   os << "<html>\n";

      os << "<!-- root   = " << *this->get_root() << " -->\n";
      os << "<!-- offset = " << *this->get_offset() << " -->\n";
      os << "<title>\n";
      os << *m_title << '\n';
      os << "</title>\n";
     
      assert(m_head != nullptr);
      m_head->output(os);
      assert(m_body != nullptr);
      m_body->output(os);

   os << "</html>\n";
   return os;
}

