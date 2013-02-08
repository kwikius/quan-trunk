#ifndef QUAN_CONCEPTS_META_TYPE_SEQUENCE_FOR_EACH_HPP_INCLUDED
#define QUAN_CONCEPTS_META_TYPE_SEQUENCE_FOR_EACH_HPP_INCLUDED

#include <quan/concepts/meta/polymorphic_functor.hpp>
#include <quan/concepts/meta/type_sequence.hpp>
#include <quan/meta/for_each.hpp>
#include <quan/meta/front.hpp>
#include <quan/meta/pop_front.hpp>

/*
   overload quan::meta::for_each for models of TypeSequence
*/

namespace quan{ namespace meta{ namespace impl{

      // for type sequence forward
      template <
         typename Sequence, 
         typename Fun, 
         bool B = (quan::meta::get_num_elements<Sequence>::value > 0),
         typename Where = void
      >
      struct for_each_type_sequence_impl;

      // overload impl for type_sequence
      template <typename Sequence, typename Fun>
      struct for_each_impl<
         Sequence, Fun, 
         typename quan::where_<quan::is_model_of<quan::meta::TypeSequence, Sequence> >::type
       > : for_each_type_sequence_impl<Sequence, Fun> {};

      // all for_each_type_sequence terminate here
      template <typename Sequence, typename Fun>
      struct for_each_type_sequence_impl<Sequence ,Fun ,false ,void>{

          typedef for_each_type_sequence_impl type;

          template <typename T> struct apply{
              typedef void type;
          };
          
          void operator()() const{}
      };
     
      // add versions for various flavours of SimplePolymorphicFunctor
      // the first should cover it
      // this version calls the function with arg as a template arg
      template <typename Sequence, typename Fun>
      struct for_each_type_sequence_impl<Sequence, Fun, true,
         typename quan::where_<quan::is_model_of<quan::meta::PolymorphicFunctor<1,0>,Fun> >::type
      >{
          typedef for_each_type_sequence_impl type;
      
          template <typename T> struct apply{
              typedef void type;
          };

          void operator()() const
          {
               typedef typename quan::meta::front<Sequence>::type front_type;
               Fun(). template operator()<front_type>();
               typedef typename pop_front<Sequence>::type next_sequence;
               quan::meta::impl::for_each_type_sequence_impl<next_sequence,Fun>()();
          }
      };

      // this version calls the arg as a runtime arg
      template <typename Sequence, typename Fun>
      struct for_each_type_sequence_impl<Sequence, Fun, true,
         typename quan::where_<quan::is_model_of<quan::meta::PolymorphicFunctor<1,1>,Fun> >::type
      >{
          typedef for_each_type_sequence_impl type;
      
          template <typename T> struct apply{
              typedef void type;
          };

          void operator()() const
          {
               typedef typename quan::meta::front<Sequence>::type front_type;
               Fun()(front_type{} );
               typedef typename pop_front<Sequence>::type next_sequence;
               quan::meta::impl::for_each_type_sequence_impl<next_sequence,Fun>()();
          }
      };

 }}}//quan::meta::impl

#endif // QUAN_CONCEPTS_META_TYPE_SEQUENCE_FOR_EACH_HPP_INCLUDED
