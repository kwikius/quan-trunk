
#include <map>
#include <quan/digraph/digraph.hpp>
#include <quan/digraph/create_dot_file.hpp>
#include <quan/digraph/show_nodes.hpp>
#include <quan/digraph/get_root_nodes.hpp>
#include <quan/digraph/df_fwd_searcher.hpp>
#include <quan/digraph/df_back_searcher.hpp>
#include <quan/digraph/digraph_edge_state.hpp>
#include <quan/digraph/has_cycles.hpp>
#include <quan/digraph/cycle_viewer.hpp>

#include <cassert>
#include <quan/atomicstring.hpp>
#include <stdlib.h>

int main()
{
   typedef quan::atomicstring<char> node;
   typedef quan::digraph<node > graph;
   graph g;

   g.insert("S","a");
   g.insert("S","x");
   g.insert("x","b");
   g.insert("b","S");
 
   show_nodes(g,std::cout);

#if(1)
   bool f = create_dot_file("dot.txt",g, "test1");

   if (f){
      int res = system("dot -Tpng -o graph.png dot.txt");
      if ( res == 0){
         std::cout << "graph written successfully\n";
      }else{
      std::cout << "graph writing failed with " << res << "\n";
      }
   }
#endif

    graph::node_set_type  roots = get_root_nodes(g);
    int num_roots = roots.size();
    if ( num_roots ==1){
     std::cout << "root is  "<< *roots.begin() << "\n";
    }else{
       if ( num_roots == 0){
            std::cout << "no root node found\n";
       }
       else {
         std::string str = " multiple roots - {";
         for ( auto i = roots.begin(), begin = i,end = roots.end(); i != end; ++i){
             if ( i != begin){
               str += ", ";
             }
             str += i->to_c_str();
         }
         str += "}";
         std::cout << str <<'\n'; 
       } 
    }
    if ( has_cycles(g)){
       auto nodes = g.get_node_set();
       for ( auto i = nodes.begin(),ei = nodes.end(); i!= ei; ++i){
          quan::cycle_viewer<node> g1(g,*i);
          if( ! g1.g_out.get_node_set().empty()){
            std::cout << "Have cycles\n ";
            quan::create_dot_file("cycles.txt" ,g1.g_out, i->to_c_str());
            system("dot -Tpng -o cycles.png cycles.txt");
            break;
          } 
       }
     }else {
       std::cout << "no cycles\n";
       // make empty dot file
       graph dummy;
       quan::create_dot_file("cycles.txt" ,dummy, "dummy");
       system("dot -Tpng -o cycles.png cycles.txt");
     }
}