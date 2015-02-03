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
 along with this program. If not, see http://www.gnu.org/licenses.
*/

#include <quan/database/database.hpp>
#include <quan/database/exception.hpp>
#include <quan/database/detail/string_converter.hpp>

#include <quan/out/length.hpp>
#include <quan/to_string.hpp>
#include <quan/from_string.hpp>
#include <quan/fixed_quantity/io/input.hpp>


int main()
{
try {
      quan::database db("DSN=balcony");

      std::vector<std::string> dest;
      db.get_field("handrail","name",dest);
      for (std::vector<std::string>::const_iterator iter = dest.begin();
            iter != dest.end();++iter){
         std::cout << *iter <<'\n';
      }
 
      db.update_value(
         "handrail","name","HR4","length",
         quan::length::mm(98)
      );

      db.insert_value(
         "handrail","name","HR7","length",
         quan::length::mm(42)
      );

      quan::length::mm xx 
      = db.get_value<quan::length::mm>(
       "handrail","name","HR6","length"
      );
      std::cout << xx <<'\n';
      
   }catch(std::exception & e) {
      std::cout << e.what();
   }
}
