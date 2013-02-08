
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
