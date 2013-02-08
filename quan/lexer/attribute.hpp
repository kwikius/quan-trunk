#ifndef QUAN_LEXER_ATTRIBUTE_HPP_INCLUDED
#define QUAN_LEXER_ATTRIBUTE_HPP_INCLUDED

#include <quan/lexer/filepos.hpp>

namespace quan{ namespace lexer{

   

//   struct attribute {
//      filepos const & get_filepos() const { return m_filepos;}
//      int get_id() const { return m_attribute_id;}
//      virtual ~attribute(){}
//    protected:
//       attribute(int id_in, quan::lexer::filepos fp_in): m_attribute_id{id_in},m_filepos{fp_in}{}
//    private:
//       int m_attribute_id;
//       quan::lexer::filepos m_filepos;
//   };
//
//   struct id_attribute : quan::lexer::attribute {
//      int value;
//      id_attribute(quan::lexer::filepos const & fp, int v) : quan::lexer::attribute{v, fp}, value {v} {}
//   };
//
//   template <typename ValueType,int ID>
//   struct value_attribute : attribute {
//      typedef ValueType value_type;
//      value_type value;
//      value_attribute(filepos const & fp, value_type const & v):attribute{ID,fp},value{v}{}
//   };
//
//   template <typename ValueType>
//   struct ptr_attribute : attribute {
//      typedef ValueType * value_type;
//      value_type value;
//      ptr_attribute(filepos const & fp, value_type p):attribute{-1,fp},value{p}{}
//      ~ptr_attribute(){if(value != nullptr){delete value;}}
//   };
//
//   template <typename ValueType> inline
//   ptr_attribute<ValueType>* make_ptr_attribute(filepos const & fp,ValueType* p)
//   {
//      return new ptr_attribute<ValueType>{fp,p};
//   }
//

}}


#endif // QUAN_LEXER_ATTRIBUTE_HPP_INCLUDED
