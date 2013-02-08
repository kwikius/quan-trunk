#ifndef QUAN_FUN_STD_AT_HPP_INCLUDED
#define QUAN_FUN_STD_AT_HPP_INCLUDED

// impl functors
// to do push_back and at
namespace quan{ namespace fun{namespace impl_detail{

      struct std_at_{
         std_at_(size_t n_in) : n(n_in){}
      size_t n;
         template <typename C>
         typename C::value_type 
         operator()(C & c) const
         {
            return c.at(n);
         }

      };
   }
// interface functions for push_back, at
   inline
   impl_detail::std_at_ std_at( size_t n)
   {
      return impl_detail::std_at_(n);
   };
}}

#endif
