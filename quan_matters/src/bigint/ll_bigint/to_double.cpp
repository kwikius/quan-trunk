#include <quan/detail/ll_bigint.hpp>
#include <quan/meta/numbits.hpp>
#include <cmath>

using quan::detail::ll_bigint;

double ll_bigint::to_double() const
{
   ll_bigint absv = *this;
   bool is_neg = (this->is_negative())? absv.negate(), true: false;
  
   double accum = absv.m_rep[0];
   double const mulk = std::pow(2., static_cast<double>(
         quan::meta::numbits<uint32>::value
      )
   );

   double mulp = 1.;

   for ( std::size_t i = 1; i < m_rep.size(); ++i){
      mulp *= mulk;
      accum += absv.m_rep[i] * mulp;
   }
   
   return (is_neg) ? - accum : accum;
}