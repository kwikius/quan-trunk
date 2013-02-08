#include <quan/detail/ll_bigint.hpp>
#include <quan/meta/numbits.hpp>

using quan::detail::ll_bigint;

// init as default?
template <typename Int>
ll_bigint::ll_bigint(Int in , typename quan::where_<
      std::is_signed<Int>
   >::type* )
{
   size_type size = (sizeof(Int)/sizeof(uint32));
   if ( size == 0 ){
      int32 si = in;
      uint32 elem = static_cast<uint32>(si);
      m_rep.push_back(elem );
     return;
   }
   else{
      static const Int mask = -1;
      for (size_type i = 0; i < size; ++i){
        Int shift = quan::meta::numbits<uint32>::value * i;
        Int v1 = in & (mask << shift);
        Int v2 = v1 >> shift;
        uint32 elem = static_cast<uint32>(v2);
        m_rep.push_back(elem );
      }
      this->request_compact(0);
      return;
    }
}

template quan::detail::ll_bigint::ll_bigint(int,void*);
template quan::detail::ll_bigint::ll_bigint(long,void*);
template quan::detail::ll_bigint::ll_bigint(long long,void*);