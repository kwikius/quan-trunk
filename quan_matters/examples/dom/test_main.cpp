
/*
dom tests
*/

#include <quan/dom/dom.hpp>
#include <quan_matters/test/simple_test.hpp>
#include <quan/out/length.hpp>
#include <quan/atomicstring.hpp>

int errors = 0;

namespace {

   typedef quan::atomicstring<char> node_id_type;
   //typedef std::string node_id_type;

   QUAN_QUANTITY_LITERAL(length,mm)

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

}

/*
TODO

  simplify leaf it is final leaf<T>
  in data node change memfun get_data to get_value
  eliminate add_value, just replace with add_value
  and rename to add_value?
  So remove diference between direct and indirect children.
  change get_value to get_element_value
  rename data_node to value_node


*/

int test_main()
{
  try {
     std::cout << "DOM Test\n";

     auto root = new branch{"root"};
     QUAN_CHECK(root)
     QUAN_CHECK(root->get_id() == "root");
     QUAN_CHECK(root->get_parent() == nullptr)
     QUAN_CHECK(root->is_head() == true)
     QUAN_CHECK(!find_direct_child(root,"d1"))
     QUAN_CHECK(!find_child(root,"d1"))
     // nodes must be heap based
     // The parent branch owns child nodes
     auto d1 = new int_leaf{"d1",1000};
     root->add_child(d1);

     QUAN_CHECK(d1->get_data() == 1000);
     QUAN_CHECK(d1->get_id() == "d1");

     QUAN_CHECK(find_direct_child(root,"d1"))
     QUAN_CHECK(find_child(root,"d1"))

     QUAN_CHECK(find_direct_child(root,"d1") == find_child(root,"d1"))

     auto d1_alias1 = as_int_leaf(root,"d1");
     QUAN_CHECK(d1_alias1)
     QUAN_CHECK(d1_alias1->get_data() == 1000);

     auto d1_alias2 = as_int_leaf_ext(root,"d1");
     QUAN_CHECK(d1_alias2)
     QUAN_CHECK(d1_alias2->get_data() == 1000);

     auto branch1 = new branch{"branch1"};
     QUAN_CHECK(!find_direct_child(root,"branch1"))
     root->add_child(branch1);
     QUAN_CHECK(find_direct_child(root,"branch1"))
     QUAN_CHECK(find_child(root,"branch1") == branch1);
     QUAN_CHECK(find_direct_child(root,"branch1") == find_child(root,"branch1"))

     auto branch2 = add_branch(root,"branch2");
     QUAN_CHECK(find_direct_child(root,"branch2") != nullptr)
     QUAN_CHECK(find_direct_child(root,"branch2") == branch2)

     auto branch3 = add_branch(branch1,"branch3");
     QUAN_CHECK(branch3);

     QUAN_CHECK(find_child(root,"branch1.branch3") == branch3);

     /*
         ############### N.B when adding quantities with deduced types
         290_mm is an int value_type and 290.0_mm is a float_value type
         as defined in the QUAN_QUANTITY_LITERAL_MACRO
         one could just define a float perhaps
         or define both to float ?
     */
     auto page_width = add_value(branch3,"page_width",290.0_mm);
     // If above is a problem, then can be explicit about type
     // from root
     auto page_height = add_value<quan::length::mm>(root,"branch1.branch3","page_height",210_mm);
     // or direct at branch
     auto page_thickness = add_value<quan::length::mm>(branch3,"page_thickness",1_mm);
     QUAN_CHECK(page_thickness);

     remove_node(branch3,"page_thickness");
     QUAN_CHECK(find_direct_child(branch3,"page_thickness") == nullptr)

     QUAN_CHECK(page_height);

     QUAN_CHECK(page_height->get_data() == 210_mm);

     QUAN_CHECK(page_width->get_data() == 290_mm);

     auto page_width_alias1 = find_child(root,"branch1.branch3.page_width");
     QUAN_CHECK(page_width_alias1)
     QUAN_CHECK(quan::dom::as_leaf_node<quan::length::mm>(page_width_alias1)->get_data() == 290_mm);

     auto page_width_alias2 = dynamic_cast<quan::dom::leaf<node_id_type,quan::length::mm>*>(page_width_alias1);
     QUAN_CHECK(page_width_alias2)

     auto page_width_value = quan::dom::get_value<quan::length::mm>(root,"branch1.branch3.page_width");
     QUAN_CHECK(page_width_value == 290_mm )

     auto const & page_width_value_cref = get_value_cref<quan::length::mm>(root,"branch1.branch3.page_width");
     QUAN_CHECK(page_width_value_cref == 290_mm )

     //NB Must be explicit about reference for auto here
     auto & page_width_value_ref = get_value_ref<quan::length::mm>(root,"branch1.branch3.page_width");
     QUAN_CHECK(page_width_value_ref == 290_mm )

     // now can change the value
     page_width_value_ref = 270_mm;

     QUAN_CHECK(get_value<quan::length::mm>(root,"branch1.branch3.page_width") == 270_mm)
      
     QUAN_CHECK( page_width_value_cref == 270_mm);

     // must use correct literal type  float not int value_type
     set_value(root,"branch1.branch3.page_width",250.0_mm);
     
     QUAN_CHECK( page_width_value_cref == 250_mm)

     quan::length::mm page_width1;
     get_value(root,"branch1.branch3.page_width",page_width1);

     QUAN_CHECK( page_width1 == 250_mm)

     add_value(branch3,"finite",true);

     QUAN_CHECK(get_value<bool>(root,"branch1.branch3.finite")== true)

   // To use a vector best just add it as an element
     quan::dom::add_value(root,"int_vector",std::vector<int>{1,2,3,4,5});

     auto vect = as_leaf_node<std::vector<int> >(find_direct_child(root,"int_vector"));

     QUAN_CHECK(vect);

     vect->get_data_ref().push_back(1011);

     QUAN_CHECK(vect->get_data_cref()[5] == 1011);

     add_branch(root,"branch1.branch3","wing[0]");

     quan::dom::add_value(root,"coord_vector",std::vector<std::vector<float> >{{1,1,1},{2,2,3},{3,4,100},{5,5}});

     std::cout << "\n\n###############################################\n\n";
     root->output(std::cout);
     std::cout << "\n###############################################\n\n";

  }catch(std::exception & e){
     std::cout << "EXCEPTION : \"" << e.what() << "\"\n";
     QUAN_CHECK(false && "Exception" );
  }

  QUAN_EPILOGUE
}