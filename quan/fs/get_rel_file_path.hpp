
#ifndef QUAN_FS_GET_REL_FILE_PATH_HPP_INCLUDED
#define QUAN_FS_GET_REL_FILE_PATH_HPP_INCLUDED
//#include <quan_matters/src/dom/gen/dom_gen.hpp>
//#include <quan_matters/src/dom/html/html.hpp>


#include <quan/fs/make_path_list.hpp>

namespace quan{ namespace fs{

inline std::string get_rel_file_path(
   std::string const & from,
   std::string const &to
)
{
  // assert(from);
  // assert(to);
   //using quan_matters::dom::node_path;
   typedef std::list<std::string> node_path;
   node_path path_from = make_path_list(from);
   node_path path_to = make_path_list(to);
 //  assert(path_from.size() > 0);
  // assert(path_from.front() == path_to.front());

   node_path::const_iterator from_iter = path_from.begin();
   node_path::const_iterator to_iter = path_to.begin();

   while ( (*from_iter == *to_iter)){
      from_iter = path_from.erase(path_from.begin());
      to_iter = path_to.erase(path_to.begin());
      //check for same file
      if (from_iter == path_from.end()
         && to_iter == path_to.end()){
         //same node/file
         return std::string();
      }else if (from_iter == path_from.end()
         || to_iter == path_to.end()){
         break;
      }
   }
   
   node_path::size_type from_size = path_from.size();
   node_path::size_type to_size = path_to.size();

   std::string str;
   if ((from_size == 1) && (to_size ==1)) {
      //same dir
      str = "./" + std::string(path_to.front());
      return str;
   }
   if ( ! to_size){
      while( from_size){
         str += "../";
         --from_size;
      }
     // str += std::string(to->get_id());
      return str;
   }
   if (! from_size){
      
    //  str += "./";// + std::string(from->get_id());
      while(to_iter != path_to.end()){
         str += "/" + std::string(*to_iter);
         ++to_iter;
      }
      return str;
   }

   while ( from_size > 1){
      str += "../";
      from_size --;
   }
   bool start = true;
   while(to_iter != path_to.end()){
      if( start ){
         start = false;
         str += std::string(*to_iter);
      }else{
         str += "/" + std::string(*to_iter);
      }
      ++to_iter;
   }   
   return str;
}

}}//quan::fs

#endif

