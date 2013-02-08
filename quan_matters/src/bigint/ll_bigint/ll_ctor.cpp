#include <quan/detail/ll_bigint.hpp>

using quan::detail::ll_bigint;

ll_bigint::ll_bigint(){ this->m_rep.push_back(0);}
ll_bigint::~ll_bigint(){}


ll_bigint::ll_bigint(ll_bigint const & rhs)
: m_rep(rhs.m_rep)
{
}

ll_bigint & ll_bigint::operator=( ll_bigint const & rhs)
{
  this->m_rep = rhs.m_rep;
  return *this;
}


