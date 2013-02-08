#ifndef QUAN_BIT_HPP_INCLUDED
#define QUAN_BIT_HPP_INCLUDED

namespace quan{

    template <typename ValueType, typename ValueType1>
    inline constexpr ValueType bit(ValueType1 n) 
   {return static_cast<ValueType>(1) << n;}

}

#endif // QUAN_BIT_HPP_INCLUDED
