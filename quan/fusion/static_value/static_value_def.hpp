#ifndef QUAN_FUSION_STATIC_VALUE_DEF_HPP_INCLUDED
#define QUAN_FUSION_STATIC_VALUE_DEF_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <quan/fusion/static_value/is_static_value.hpp>
#include <quan/concepts/fusion/static_value.hpp>
#include <quan/fusion/meta_rational_to_runtime.hpp>
#include <quan/meta/is_scalar.hpp>
#include <quan/meta/is_runtime_type.hpp>
#include <quan/meta/is_numeric.hpp>

namespace quan{ namespace fusion{

    template <typename RuntimeType,typename StaticNumericValue>
    struct static_value{
        typedef RuntimeType runtime_type;
        typedef StaticNumericValue static_value_type;
        typedef static_value type;
    };

    namespace impl{

        template <typename Runtime, typename Static>
        struct is_static_value_impl< static_value<Runtime,Static> > : std::true_type{};

        template <
            typename RuntimeType,
            typename StaticNumericValue
        >
        struct to_runtime_impl<
            quan::fusion::static_value<RuntimeType, StaticNumericValue>
        >
        {
            typedef quan::fusion::static_value<
                RuntimeType, StaticNumericValue
            > static_value_type;
            typedef RuntimeType type;
            constexpr type operator()(static_value_type ) const
            {
               typedef quan::fusion::impl::to_runtime_impl<StaticNumericValue> f;
               return RuntimeType{f{}( StaticNumericValue{} )};
            }
        };
    }//impl

}} //quan::fusion

namespace quan{ namespace meta{

   namespace impl{

      template <typename Runtime, typename Static>
      struct is_runtime_type_impl<
         quan::fusion::static_value<Runtime,Static>
      > : std::false_type{};

      template <typename Runtime, typename Static>
      struct is_scalar_impl< quan::fusion::static_value<Runtime,Static> > : 
      quan::meta::is_scalar<Runtime>{};
   }

// question why is it not numeric?
//    
//    template <typename R, typename S>
//    struct is_numeric<quan::fusion::static_value<R,S> > : is_numeric<R>{};
}}

#endif
