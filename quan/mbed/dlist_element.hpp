#ifndef QUAN_MBED_DLIST_ELEMENT_HPP_INCLUDED
#define QUAN_MBED_DLIST_ELEMENT_HPP_INCLUDED

// NOTE: This class uses asserts
// for release define NDEBUG

#include <cassert>
#include <type_traits>
#include <quan/meta/bool.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/bool/false.hpp>
#include <quan/meta/strip_cr.hpp>
#include <quan/where.hpp>

/*
 double linked list element which can be on multiple lists
*/
namespace quan {namespace mbed {

   template <typename T, int N>
   struct dlist_element{

      static constexpr uint32_t dl_list_num_elements = N;
      typedef T element_type;
      dlist_element() :m_prev{nullptr}, m_next{nullptr}
      {
         static_assert(std::is_base_of<dlist_element,T>::value,"T must be derived from dlist_element");
      };
      template <int I>
      T * get_next_dlist_element()const 
      { 
         static_assert(I < N,"subscript out of range");
         return m_next[I];
      }
      template <int I>
      void set_next_dlist_element(T * p) 
      {
         static_assert(I < N,"subscript out of range");
         m_next[I] = p;
      }
      template <int I>
      T * get_prev_dlist_element()const 
      { 
         static_assert(I < N,"subscript out of range");
         return m_prev[I];
      }
      template <int I>
      void set_prev_dlist_element(T * p) { 
         static_assert(I < N,"subscript out of range");
         m_prev[I] = p;
      }

      private:
        T * m_prev[N];
        T * m_next[N];
   };

   namespace impl{
      template <typename T, uint32_t N> 
      struct is_dlist_element_impl : std::is_base_of<dlist_element<T,N>,T>{};
   }

   template <typename T> struct is_dlist_element : impl::is_dlist_element_impl<
      typename quan::meta::strip_cr<T>::type, 
      quan::meta::strip_cr<T>::type::dl_list_num_elements
   >{};


   template <int I,typename T>
   inline
   typename quan::where_<is_dlist_element<T> >::type
   dlist_push_front(T*& list, T * element)
   {
      assert(element != nullptr);

      element-> template set_prev_dlist_element<I>(nullptr);
      element-> template set_next_dlist_element<I>(list);
      if (list){
         assert( list-> template get_prev_dlist_element<I>() == nullptr);
         list-> template set_prev_dlist_element<I>(element);
      }
      list = element;
   }

   // extracts the first element and returns it
   // the iter is updated to the next in the list
   // and the list itself may be updated
   // empty list returns nullptr
   template <int I,typename T>
   inline
   typename quan::where_<is_dlist_element<T>, T* >::type
   dlist_pop_front(T*& list){
      if ( list != nullptr){
        // assert(list != nullptr);
         assert( list-> template get_prev_dlist_element<I>() == nullptr);

         T* front_item = list;
         list = list-> template get_next_dlist_element<I>();
         if( list){
            list-> template set_prev_dlist_element<I>(nullptr);
         }
         front_item-> template set_next_dlist_element<I>(nullptr);
         return front_item;
      }else{
         return nullptr;
      }
   }

   // extracts the element at iter and returns it
   // the iter is updated to the next in the list
   // and the list itself may be updated
   template <int I,typename T>
   inline
   typename quan::where_<is_dlist_element<T>, T* >::type
   dlist_extract(T*& list,T*& iter)
   {
      assert(iter != nullptr);
      assert(list != nullptr);

      T * extracted_element = iter;
      if ( iter == list){  // start of list
         assert(list-> template get_prev_dlist_element<I>() == nullptr);
         list = list-> template get_next_dlist_element<I>();
         if(list){
            list-> template set_prev_dlist_element<I>(nullptr);
         }
         iter = list;
         extracted_element-> template set_next_dlist_element<I>(nullptr);
      }else{
         T * prev = iter-> template get_prev_dlist_element<I>();
         assert(prev);
         T * next = iter-> template get_next_dlist_element<I>();
         prev-> template set_next_dlist_element<I>(next);
         if( next){
            next-> template set_prev_dlist_element<I>(prev);
         }
         iter = next;
         extracted_element-> template set_next_dlist_element<I>(nullptr);
         extracted_element-> template set_prev_dlist_element<I>(nullptr);
      }
      return extracted_element;
   }

} }// quan::embed

#endif // QUAN_MBED_DLIST_ELEMENT_HPP_INCLUDED
