#ifndef QUAN_IS_MODEL_OF_FWD_HPP_INCLUDED
#define QUAN_IS_MODEL_OF_FWD_HPP_INCLUDED


namespace quan{

   namespace impl{

      template < typename Concept,typename T,typename Where=void>
      struct is_model_of_impl;
   }

   template <typename Concept,typename T>
   struct is_model_of ;

}


#endif
