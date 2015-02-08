
#include <iostream>
#include <malloc.h>
#include <cstring>
#include <string>

#include <quan/uav/osd/detail/writable_bitmap.hpp>

quan::uav::osd::size_type 
quan::uav::osd::detail::writable_bitmap::get_size() const 
{return m_size;}

uint8_t const * quan::uav::osd::detail::writable_bitmap::get_data() const 
{ return m_data;}

quan::uav::osd::detail::writable_bitmap::~writable_bitmap()
{ if (m_data) { free(m_data); m_data = nullptr;} }

quan::uav::osd::detail::writable_bitmap::writable_bitmap()
: m_size{0,0},m_data{nullptr}{}

quan::uav::osd::detail::writable_bitmap::writable_bitmap(
   quan::uav::osd::size_type const & size_in)
: m_data{nullptr}
{
  set_size(size_in);
}

void quan::uav::osd::detail::writable_bitmap::set_size(
   quan::uav::osd::size_type const & size_in
)
{
   if(m_data) {
      free ( m_data);
   } m_data = nullptr;
   m_size = size_in;
   m_data = (uint8_t*) malloc(get_data_size());
   clear();
} 

quan::uav::osd::detail::writable_bitmap::writable_bitmap(
   writable_bitmap const & in)
: m_data{nullptr}
{
   this->copy_from(in);
}

//quan::uav::osd::detail::writable_bitmap & 
//quan::uav::osd::detail::writable_bitmap::operator =(
//   quan::uav::osd::detail::writable_bitmap const & in
//)
//{
//   if ( this != &in){
//      this->copy_from(in);
//   }
//   return *this;
//}


bool quan::uav::osd::detail::writable_bitmap::copy_from(quan::uav::osd::basic_bitmap const & in)
{
   set_size(in.get_size());
   for ( int32_t y = 0; y < m_size.y; ++y){
      for (int32_t x= 0; x < m_size.x; ++x){
         set_pixel({x,y},in.get_pixel_colour({x,y}));
      }
   }
   return true;
}

bool quan::uav::osd::detail::writable_bitmap::clear()
{
   if (m_data){
      memset(m_data,0xff,get_data_size());
      return true;
   }else{
      return false;
   }
}



void quan::uav::osd::detail::writable_bitmap::set_pixel( 
   quan::two_d::vect<int32_t> const & pos,
   quan::uav::osd::color_type c
)
{
   quan::uav::osd::size_type const size_px = this->get_size();
   if (     (pos.x >= 0 ) 
         && (pos.x < size_px.x) 
         && (pos.y >= 0) 
         && (pos.y < size_px.y)
   ){
      uint32_t constexpr bits_px = get_bits_px();
      uint32_t const y_bit_pos = pos.y * size_px.x * bits_px;
      uint32_t const px_pos = y_bit_pos + pos.x * bits_px;
      uint32_t const byte_pos = px_pos / 8U;
      uint32_t const bit_pos = px_pos % 8U;
      uint8_t const ucol = static_cast<uint8_t>(c);
      uint8_t val = m_data[byte_pos];
      
      for ( uint8_t i = 0; i < 2; ++i){
         uint8_t const bit = (1 << i);
         if (( ucol & bit) == 0){
            val &= ~(bit << bit_pos);
         }else{
            val |= (bit << bit_pos);
         }
      }
      m_data[byte_pos] = val;

   } // no op if out of range
}

 bool quan::uav::osd::detail::writable_bitmap::output_header (
   std::string const & bitmap_typename, 
   std::string const & bitmap_objectname, 
   std::ostream & out
)
{
   out << " struct " << bitmap_typename << " : quan::uav::osd::static_bitmap<" << m_size.x << "," << m_size.y << "> {\n";
   out << "    uint8_t const * get_data()const\n";
   out << "    {\n";
   out << "       return m_data;\n";
   out << "    }\n";
   out << " private:\n";
   out << "    static constexpr uint8_t m_data[" << get_data_size() << "] = {\n      ";
   int count = 0;
   uint8_t const * data = get_data();
   uint32_t const data_size = get_data_size();
   for ( uint32_t i = 0; i < data_size; ++i){
      if ( i !=0){ out << ", ";}
      out << static_cast<int>(data[i]);
      if ( ++count == 4){
         count = 0;
         out <<"\n      ";
      }
   }
   out << "\n      };\n";
   
   out << "   } " << bitmap_objectname << ";\n";
// could do separately
   out << "  constexpr uint8_t " << bitmap_typename  << "::m_data [ " << get_data_size() << "];\n\n";

   return true;
}