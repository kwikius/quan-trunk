
#include <fstream>
#include <quan/dom/dom.hpp>
#include <quan_matters/test/simple_test.hpp>
#include <quan/out/length.hpp>
#include <quan/out/angle.hpp>
#include <quan/atomicstring.hpp>

namespace {

   typedef quan::atomicstring<char> node_id_type;
   //typedef std::string node_id_type;

   QUAN_QUANTITY_LITERAL(length,mm)
   QUAN_ANGLE_LITERAL(deg)

   //using quan::dom::add_value;
   using quan::dom::add_value;
   using quan::dom::add_branch;
   using quan::dom::as_leaf_node;
   using quan::dom::get_value;

   using quan::dom::get_value_ref;
   using quan::dom::get_value_cref;

   typedef quan::dom::branch<node_id_type> branch;
   typedef quan::dom::node<node_id_type> node;
   typedef quan::dom::data_node<node_id_type,int> int_leaf;

   auto as_int_leaf = [] (node * b, node_id_type const &  str) { return quan::dom::as_leaf_node<int>(find_direct_child(b,str));};
   auto as_int_leaf_ext = [] (node * b, std::string const &  str) { return quan::dom::as_leaf_node<int>(find_child(b,str));};

   typedef quan::length::mm mm;
   typedef quan::angle::deg deg;

}

/*
schema section {
   aerofoil_file    : string ;
   chord            : mm ;
   y_position       : mm ;
   TE_thickness     : mm ;
   incidence_angle  : deg ;
}

schema wing {
   spline_origin    : mm ;
   sweep_spline     : float[2][] ;
   sections         : section[];
}
 
// the root schema has no name
schema {
   wings            : wing [] ;
}
*/

int aerofoil_example ()
{
   std::ofstream out("output.txt");
   out << "// aerofoil example\n";

   auto wings = new branch{"wings"};
      auto wing0  = add_branch(wings,"[0]");
         add_value<quan::length::mm>(wing0,"spline_origin",0_mm);
         add_value(wing0,"sweep_spline",std::vector<std::vector<mm> >{{0.0_mm,0.0_mm},{850.0_mm,10.0_mm}});
         add_branch(wing0,"sections");
            auto sections0 = add_branch(wing0,"sections","[0]"); 
            add_value(sections0,"aerofoil_file",std::string{"/home/andy/cpp/projects/aerofoil/Sections/selig/mh32.dat"});
            add_value(sections0,"chord",165.0_mm);
            add_value(sections0,"y_position",0.0_mm);
            add_value(sections0,"TE_thickness",0.5_mm);
            add_value(sections0,"incidence_angle",0.0_deg);

   out << "\n\n// ###############################################\n\n";
   wings->output(out);
   out << "\n//###############################################\n\n";

   return EXIT_SUCCESS;
}