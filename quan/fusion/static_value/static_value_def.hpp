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
#include <quan/fusion/to_runtime.hpp>
#include <quan/meta/is_scalar.hpp>

namespace quan{ namespace fusion{

    template <typename RuntimeType,typename StaticNumericValue>
    struct static_value{
        typedef RuntimeType runtime_type;
        typedef StaticNumericValue static_value_type;
        typedef static_value type;

        constexpr static RuntimeType to_runtime()
        {
            typedef quan::fusion::impl::to_runtime_impl<StaticNumericValue> f;
            return RuntimeType{f{}( StaticNumericValue{} )};
        }
    };

    template <typename Runtime, typename Static>
    struct is_static_value< static_value<Runtime,Static> > : std::true_type{};


    namespace impl{
        #if defined __cpp_concepts
        template <quan::fusion::StaticValue V>
        struct to_runtime_impl<V>
        {
            typedef typename V::runtime_type type;
            constexpr type operator()(V v) const
            {
                return V::to_runtime();
            }
        };
        #else
        template <typename RuntimeType,typename StaticNumericValue>
        struct to_runtime_impl<
            quan::fusion::static_value<RuntimeType, StaticNumericValue>
        >
        {
            typedef quan::fusion::static_value<
                RuntimeType, StaticValue
            > static_value_type;
            typedef RuntimeType type;
            constexpr type operator()(static_value_type ) const
            {
                return static_value_type::to_runtime();
            }
        };
        #endif
    }//impl

}} //quan::fusion

namespace quan{ namespace meta{

   template <typename Runtime, typename Static>
   struct is_runtime_type<
      quan::fusion::static_value<Runtime,Static>
   > : std::false_type{};

   template <typename Runtime, typename Static>
   struct is_scalar< quan::fusion::static_value<Runtime,Static> > : 
   is_scalar<Runtime>{};
}}

#endif
