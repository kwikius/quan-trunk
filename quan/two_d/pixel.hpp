#ifndef QUAN_PIXEL_HPP_INCLUDED
#define QUAN_PIXEL_HPP_INCLUDED

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See <QUAN> for documentation.

namespace quan{
    struct pixel{
    private:
        int m_value;
    public:
        explicit pixel (int value):m_value(value){}
        pixel():m_value(0){}
        pixel& operator =(pixel p)
        {
            m_value = p.m_value;
            return *this;
        }
        pixel& operator +=(pixel p)
        {
            m_value += p.m_value;
            return *this;
        }
        pixel& operator -=(pixel p)
        {
            m_value -= p.m_value;
            return *this;
        }
        pixel& operator *=(int n)
        {
            m_value *= n;
            return *this;
        }
        pixel& operator /=(int n)
        {
            m_value /= n;
            return *this;
        }
        pixel& operator %=(int n)
        {
            m_value %= n;
            return *this;
        }
        pixel& operator++()
        {
            ++m_value;
            return *this;
        }
        pixel operator++(int)
        {
            pixel t =*this;
            ++m_value ;
            return t; 
        }
        pixel& operator --()
        {
            --m_value;
            return *this;
        }
        pixel operator--(int)
        {
            pixel t =*this;
            --m_value ;
            return t; 
        }
        int get_value() const
        {
            return m_value;
        }
        void set_value(int n)
        {
            m_value = n;
        }
    };

    inline pixel operator+(pixel lhs, pixel rhs)
    {
        pixel result =lhs;
        result += rhs;
        return result;
    }
    inline pixel operator-(pixel lhs, pixel rhs)
    {
        pixel result =lhs;
        result -= rhs;
        return result;
    }
    inline pixel operator*(pixel lhs, int rhs)
    {
        pixel result =lhs;
        result *= rhs;
        return result;
    }
    inline pixel operator*(int lhs, pixel rhs)
    {
        pixel result(lhs);
        result *= rhs.get_value();
        return result;
    }
    inline pixel operator/(pixel lhs, int rhs)
    {
        pixel result = lhs;
        result /= rhs;
        return result;
    }
    inline pixel operator%(pixel lhs, int rhs)
    {
        pixel result = lhs;
        result %= rhs;
        return result;
    }

}//quan

#endif
