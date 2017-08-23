#ifndef QUAN_DOM_STD_SEQUENCE_TAG_HPP_INCLUDED
#define QUAN_DOM_STD_SEQUENCE_TAG_HPP_INCLUDED

namespace quan{ namespace dom{

   template <typename IdentifierType> class node;

   template <typename IdentifierType,typename Sequence>
   struct std_sequence_tag{
      typedef IdentifierType identifier_type;
      typedef node<identifier_type>* node_ptr;
      typedef Sequence container_type;

      static node_ptr
      get_child(container_type const & seq, identifier_type const & id)
      {
         typedef typename container_type::const_iterator iter_type;
         for (iter_type iter = seq.begin(), end = seq.end(); 
               iter != end; 
                  ++iter){
               if( (*iter)->get_id() == id){
                  return *iter;
               }
         }
         return nullptr;
      }

      static bool remove_child(container_type & seq,identifier_type const & id)
      {
         for (typename container_type::iterator iter = seq.begin(), end = seq.end(); 
                  iter != end; 
                     ++iter){
               if( (*iter)->get_id() == id){
                  delete *iter;
                  *iter = nullptr;
                  seq.erase(iter);
                  return true;
               }
         }
         return false;
      }

       static std::ostream & output(container_type const &  seq,std::ostream & os)
       {
            typename container_type::const_iterator iter = seq.begin();
            while (iter != seq.end()){
               (*iter)->output(os);
                ++iter ;
            }
            return os;
        }

       static void add_child(container_type & seq,node_ptr const & in )
       {
            seq.push_back(in);
       }
      
       static bool is_empty(container_type const & seq)
       {
         return seq.empty();
       }

       static typename container_type::size_type size(container_type const & seq)
       {
           return seq.size();
       }
   };


}}//quan::dom

#endif

