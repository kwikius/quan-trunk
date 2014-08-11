#ifndef QUAN_META_SI_UNITS_HPP_INCLUDED1
#define QUAN_META_SI_UNITS_HPP_INCLUDED1
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

/*
   si_unit - utility class for naming coherent si units,
   their names and prefixes

   todo change so that wide facet can show unicode etc
*/
#include <quan/config.hpp>
#include <quan/meta/conversion_factor.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/int32.hpp>

namespace quan{namespace meta{

    struct si_unit{

        template <typename Exponent>
        struct prefix{
            enum{value = false};
           // typedef prefix type;
        };
        typedef conversion_factor<rational<24>,rational<1>,quan::meta::int32<0> >  yotta;
        typedef conversion_factor<rational<21>,rational<1>,quan::meta::int32<0> >  zetta;
        typedef conversion_factor<rational<18>,rational<1>,quan::meta::int32<0> >  exa;
        typedef conversion_factor<rational<15>,rational<1>,quan::meta::int32<0> >  peta;
        typedef conversion_factor<rational<12>,rational<1>,quan::meta::int32<0> >  tera;
        typedef conversion_factor<rational<9>,rational<1>,quan::meta::int32<0> >  giga;
        typedef conversion_factor<rational<6>,rational<1>,quan::meta::int32<0> >  mega;
        typedef conversion_factor<rational<3>,rational<1>,quan::meta::int32<0> >  kilo;
        typedef conversion_factor<rational<2>,rational<1>,quan::meta::int32<0> >  hecto;
        typedef conversion_factor<rational<1>,rational<1>,quan::meta::int32<0> >  deka;
        typedef conversion_factor<rational<0>,rational<1>,quan::meta::int32<0> >  none;
        typedef conversion_factor<rational<-1>,rational<1>,quan::meta::int32<0> >  deci;
        typedef conversion_factor<rational<-2>,rational<1>,quan::meta::int32<0> >  centi;
        typedef conversion_factor<rational<-3>,rational<1>,quan::meta::int32<0> >  milli;
        typedef conversion_factor<rational<-6>,rational<1>,quan::meta::int32<0> >  micro;
        typedef conversion_factor<rational<-9>,rational<1>,quan::meta::int32<0> >  nano;
        typedef conversion_factor<rational<-12>,rational<1>,quan::meta::int32<0> >  pico;
        typedef conversion_factor<rational<-15>,rational<1>,quan::meta::int32<0> >  femto;
        typedef conversion_factor<rational<-18>,rational<1>,quan::meta::int32<0> >  atto;
        typedef conversion_factor<rational<-21>,rational<1>,quan::meta::int32<0> >  zepto;
        typedef conversion_factor<rational<-24>,rational<1>,quan::meta::int32<0> >  yocto;
                           
    };

    template<>
    struct si_unit::prefix<si_unit::yotta>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "yotta";}
        template<typename CharType>
        static const CharType* symbol();
    };

    template<>
    inline
    const char*
    si_unit::prefix<si_unit::yotta>::symbol<char>()
    {
        return "Y";
    }

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::yotta>::symbol<wchar_t>()
    {
        return L"Y";
    }

    template<>
    struct si_unit::prefix<si_unit::zetta>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "zetta";}
        template<typename CharType>
        static const CharType* symbol();
    };

    template<>
    inline
    const char*
    si_unit::prefix<si_unit::zetta>::symbol<char>()
    {
        return "Z";
    }

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::zetta>::symbol<wchar_t>()
    {
        return L"Z";
    }
    
    template<>
    struct si_unit::prefix<si_unit::exa>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "exa";}
        template<typename CharType>
        static const CharType* symbol();
    };

    template<>
    inline
    const char* 
    si_unit::prefix<si_unit::exa>::symbol<char>()
    {
        return "E";
    }

    template<>
    inline
    const wchar_t* 
    si_unit::prefix<si_unit::exa>::symbol<wchar_t>()
    {
        return L"E";
    }

    template<>
    struct si_unit::prefix<si_unit::peta>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "peta";}
        template<typename CharType>
        static const CharType* symbol();
    };

    template<>
    inline
    const char*
    si_unit::prefix<si_unit::peta>::symbol<char>()
    {
        return "P";
    }

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::peta>::symbol<wchar_t>()
    {
        return L"P";
    }

    template<>
    struct si_unit::prefix<si_unit::tera>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "tera";}
        template<typename CharType>
        static const CharType* symbol();
    };

    template<>
    inline
    const char*
    si_unit::prefix<si_unit::tera>::symbol<char>()
    {
        return "T";
    }

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::tera>::symbol<wchar_t>()
    {
        return L"T";
    }

    template<>
    struct si_unit::prefix<si_unit::giga>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "giga";}
        template<typename CharType>
        static const CharType* symbol(); 
    };

    template<>
    inline
    const char* si_unit::prefix<si_unit::giga>::symbol<char>()
    {
        return "G";
    }

    template<>
    inline
    const wchar_t* si_unit::prefix<si_unit::giga>::symbol<wchar_t>()
    {
        return L"G";
    }

    template<>
    struct si_unit::prefix<si_unit::mega>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "mega";}
        template<typename CharType>
        static const CharType* symbol();
    };
    template<>
    inline
    const char* si_unit::prefix<si_unit::mega>::symbol<char>()
    {
        return "M";
    }

    template<>
    inline
    const wchar_t* si_unit::prefix<si_unit::mega>::symbol<wchar_t>()
    {
        return L"M";
    }


    template<>
    struct si_unit::prefix<si_unit::kilo>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "kilo";}
        template<typename CharType>
        static const CharType* symbol();
    };
    template<>
    inline
    const char* si_unit::prefix<si_unit::kilo>::symbol<char>()
    {
        return "k";
    }

    template<>
    inline
    const wchar_t* si_unit::prefix<si_unit::kilo>::symbol<wchar_t>()
    {
        return L"k";
    }
 
    template<>
    struct si_unit::prefix<si_unit::hecto>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "hecto";}
        template<typename CharType>
        static const CharType* symbol();
    };
    template<>
    inline
    const char* si_unit::prefix<si_unit::hecto>::symbol<char>()
    {
        return "h";
    }

    template<>
    inline
    const wchar_t* si_unit::prefix<si_unit::hecto>::symbol<wchar_t>()
    {
        return L"h";
    }
 
    template<>
    struct si_unit::prefix<si_unit::deka>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "deka";}
        template<typename CharType>
        static const CharType* symbol();
    };
    template<>
    inline
    const char* si_unit::prefix<si_unit::deka>::symbol<char>()
    {
        return "da";
    }

    template<>
    inline
    const wchar_t* si_unit::prefix<si_unit::deka>::symbol<wchar_t>()
    {
        return L"da";
    }

    template<>
    struct si_unit::prefix<si_unit::none>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "";}
        template<typename CharType>
        static const CharType* symbol();  
    };
    template<>
    inline
    const char* si_unit::prefix<si_unit::none>::symbol<char>()
    {
        return "";
    }

    template<>
    inline
    const wchar_t* si_unit::prefix<si_unit::none>::symbol<wchar_t>()
    {
        return L"";
    }

    template<>
    struct si_unit::prefix<si_unit::deci>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "deci";}
        template<typename CharType>
        static const CharType* symbol();
    };
    template<>
    inline
    const char* si_unit::prefix<si_unit::deci>::symbol<char>()
    {
        return "d";
    }

    template<>
    inline
    const wchar_t* si_unit::prefix<si_unit::deci>::symbol<wchar_t>()
    {
        return L"d";
    }

    template<>
    struct si_unit::prefix<si_unit::centi>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "centi";}
        template<typename CharType>
        static const CharType* symbol();
    };

    template<>
    inline
    const char* si_unit::prefix<si_unit::centi>::symbol<char>()
    {
        return "c";
    }

    template<>
    inline
    const wchar_t* si_unit::prefix<si_unit::centi>::symbol<wchar_t>()
    {
        return L"c";
    }

    template<>
    struct si_unit::prefix<si_unit::milli>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "milli";}
        template<typename CharType>
        static const CharType* symbol(); 
    };
    template<>
    inline
    const char* si_unit::prefix<si_unit::milli>::symbol<char>()
    {
        return "m";
    }

    template<>
    inline
    const wchar_t* si_unit::prefix<si_unit::milli>::symbol<wchar_t>()
    {
        return L"m";
    }

    template<>
    struct si_unit::prefix<si_unit::micro>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "micro";}
        template<typename CharType>
        static const CharType* symbol();
    };
    template<>
    inline
    const char*
    si_unit::prefix<si_unit::micro>::symbol<char>()
    {
        return "u";
    }

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::micro>::symbol<wchar_t>()
    {
        return L"u";
    }
 
    template<>
    struct si_unit::prefix<si_unit::nano>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "nano";}
        template<typename CharType>
        static const CharType* symbol();
    };
    template<>
    inline
    const char*
    si_unit::prefix<si_unit::nano>::symbol<char>()
    {
        return "n";
    }

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::nano>::symbol<wchar_t>()
    {
        return L"n";
    }

    template<>
    struct si_unit::prefix<si_unit::pico>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "pico";}
        template<typename CharType>
        static const CharType* symbol();
    };

    template<>
    inline
    const char*
    si_unit::prefix<si_unit::pico>::symbol<char>()
    {
        return "p";
    }
    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::pico>::symbol<wchar_t>()
    {
        return L"p";
    }

    template<>
    struct si_unit::prefix<si_unit::femto>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "femto";}
        template<typename CharType>
        static const CharType* symbol();  
    };
    template<>
    inline
    const char*
    si_unit::prefix<si_unit::femto>::symbol<char>()
    {
        return "f";
    }

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::femto>::symbol<wchar_t>()
    {
        return L"f";
    }


    template<>
    struct si_unit::prefix<si_unit::atto>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "atto";}
        template<typename CharType>
        static const CharType* symbol();
    };
    template<>
    inline
    const char*
    si_unit::prefix<si_unit::atto>::symbol<char>()
    {
        return "a";
    }

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::atto>::symbol<wchar_t>()
    {
        return L"a";
    }

    template<>
    struct si_unit::prefix<si_unit::zepto>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "zepto";}
        template<typename CharType>
        static const CharType* symbol();
    }; 
    template<>
    inline
    const char*
    si_unit::prefix<si_unit::zepto>::symbol<char>()
    {
        return "z";
    }

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::zepto>::symbol<wchar_t>()
    {
        return L"z";
    }

    template<>
    struct si_unit::prefix<si_unit::yocto>{
        enum{value = true};
        typedef prefix type;
        static const char* name(){return "yocto";}
        template<typename CharType>
        static const CharType* symbol();
    };
    template<>
    inline
    const char*
    si_unit::prefix<si_unit::yocto>::symbol<char>()
    {
        return "y";
    }  

    template<>
    inline
    const wchar_t*
    si_unit::prefix<si_unit::yocto>::symbol<wchar_t>()
    {
        return L"y";
    }  
}}//quan::meta

#endif
