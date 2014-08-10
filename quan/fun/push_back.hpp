#ifndef QUAN_FUN_PUSH_BACK_HPP_INCLUDED
#define QUAN_FUN_PUSH_BACK_HPP_INCLUDED

// use with foreach to load a std container from another
namespace quan{namespace fun{
   namespace impl_detail{
      template <typename Container>
      struct push_back_{
         Container & c;
         push_back_(Container & c_in):c(c_in){}

         template <typename T>
         struct result{
            typedef void type;
         };
         template <typename T>
         typename result<T>::type
         operator()(T const & t)const
         {
            return c.push_back(t);
         }
      };
   }//impl_detail
   // function returns a functor
   // this means you dont need parameters
   // on the functor as you would when using direct
   template <typename Container>
   inline
   impl_detail::push_back_<Container> push_back(Container & c)
   {
      return impl_detail::push_back_<Container>(c);
   }

}}//quan::fun

#endif
