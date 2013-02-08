#ifndef QUAN_ARE_MODELS_OF_HPP_INCLUDED
#define QUAN_ARE_MODELS_OF_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/meta/and.hpp>

namespace quan{

      template<typename C, typename TL,typename TR>
      struct are_models_of : quan::meta::and_< is_model_of<C,TL>,is_model_of<C,TR> >{};

}

#endif

