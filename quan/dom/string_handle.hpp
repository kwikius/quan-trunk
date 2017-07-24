#ifndef STRING_HANDLE_HPP_INCLUDED
#define STRING_HANDLE_HPP_INCLUDED

 // Copyright (c) 2005-2006 Andrew Little.  ALL RIGHTS RESERVED.
 // No part of this document may be reproduced or transmitted
 // in any form or by any means without the written permission
 // of the author.

#include <vector>
#include <map>
#include <string>

namespace quan{ namespace dom{

   template <typename CharType>
	class string_handle;

   template <typename CharType>
	class string_handle{
      public:
         typedef CharType char_type;
         typedef std::basic_string<char_type> string_type;
      private:
		//class string_handle_table;
        typedef int handle_type;

		//friend class string_handle_table;
		friend class std::map<string_type,handle_type>;

		handle_type m_handle;

		class string_handle_table {
			friend class string_handle;
			std::vector<string_type> strvect;
         typedef std::map<string_type,handle_type> handle_map_type;
			handle_map_type strmap;
			handle_type freepos;

			handle_type to_string_handle(const string_type& str)
         {
            typedef std::pair<typename handle_map_type::iterator,bool> result_pair_type;
            typedef std::pair<string_type,handle_type> in_pair_type;
            result_pair_type p = strmap.insert(in_pair_type(str,freepos));
	         if (p.second){
		         strvect.push_back(str);
               //should check for max
		         return freepos++;
	         }
	         else {
		         return p.first->second;
            }
         }

			const string_type& to_string(string_handle hs)const
         {
            return strvect[hs.m_handle];
         }
         const char* to_c_str(string_handle hs)const
         {
            return strvect[hs.m_handle].c_str();
         }
			string_handle_table():
         freepos(0)
         {
	         to_string_handle("");
         }
		};
		static string_handle_table table;
	public:

		bool operator()()const{ return m_handle!=0;}
      handle_type get_handle() const { return m_handle;}

      const char* to_c_str() const
      {
         return table.to_c_str(*this);
      }

		string_handle():m_handle(0){}

		string_handle(const string_handle& h_in):m_handle(h_in.m_handle){}

      string_handle(const char_type* p) : m_handle(table.to_string_handle(string_type(p))){}
		string_handle(const string_type& str): m_handle(table.to_string_handle(str)){}

		string_handle& operator=(const string_handle& right){ m_handle = right.m_handle; return *this;}

		string_handle& operator=(const string_type& str){ m_handle=table.to_string_handle(str); return *this;}

      string_handle& operator=(const char_type* p){ m_handle=table.to_string_handle(string_type(p)); return *this;}

		operator const string_type&()const { return table.to_string(*this);}

		operator const char_type* ()const { return (table.to_string(*this)).c_str();}
	};

   template<typename CharType>
	inline	std::ostream& operator<<(std::ostream& os, const string_handle<CharType> & id)
	{
      return os << id.to_c_str();
    }

   template<typename CharType>
	inline bool operator==(const string_handle<CharType>& left,const string_handle<CharType>& right)
	{return left.get_handle() == right.get_handle();}

	template<typename CharType>
	inline bool operator==(const string_handle<CharType>& left,const CharType* right)
	{return left.get_handle() == string_handle<CharType>{right}.get_handle();}

   template<typename CharType>
	inline bool operator==(const CharType* left,const string_handle<CharType>& right)
	{return string_handle<CharType>{left}.get_handle() == right.get_handle();}

   template<typename CharType>
	inline bool operator!=(const string_handle<CharType>& left,const string_handle<CharType>& right)
	{return left.get_handle() != right.get_handle();}

	template<typename CharType>
	inline bool operator!=(const string_handle<CharType>& left,const CharType* right)
	{return left.get_handle() != string_handle<CharType>{right}.get_handle();}

   template<typename CharType>
	inline bool operator!=(const CharType* left,const string_handle<CharType>& right)
	{return string_handle<CharType>{left}.get_handle() != right.get_handle();}

   template<typename CharType>
	inline bool operator<(const string_handle<CharType> & left,const string_handle<CharType>& right)
   {return left.get_handle() < right.get_handle();}

   template<typename CharType>
	inline bool operator<=(const string_handle<CharType> & left,const string_handle<CharType>& right)
   {return left.get_handle() <= right.get_handle();}

   template<typename CharType>
	inline bool operator>=(const string_handle<CharType> & left,const string_handle<CharType>& right)
   {return left.get_handle() >= right.get_handle();}

   template<typename CharType>
	inline bool operator>(const string_handle<CharType> & left,const string_handle<CharType>& right)
   {return left.get_handle() > right.get_handle();}

   template <typename CharType>
   typename quan::dom::string_handle<CharType>::string_handle_table
   quan::dom::string_handle<CharType>::table;

}}//quan::dom

#endif


