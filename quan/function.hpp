#ifndef QUAN_FUNCTION_HPP_INCLUDED
#define QUAN_FUNCTION_HPP_INCLUDED
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

namespace quan{ namespace detail{

   template <typename F>
   struct function_abc;

   template<typename R , typename... Args>
   struct function_abc<R(Args...)>
   {
     virtual R apply(Args...)const =0;
     virtual ~function_abc(){};
   };

   template <typename T, typename F>
   struct function_object;

   template <typename F>
   struct free_function;

   template <typename T, typename R , typename... Args>
   struct function_object<T,R(Args...)> : function_abc<R(Args...)> {
      function_object(T ob, R(T::*fn)(Args...) ) : m_ob(ob),m_pf(fn){}
      R apply( Args... args)const
      {
        return (m_ob.*m_pf)(args...);
      }
      ~function_object (){}
   private:
      T  m_ob; // doesnt own the object
      typedef R (T::*fun_ptr)(Args...)const;
      fun_ptr m_pf;
   };

   template < typename R, typename... Args>
   struct free_function<R(Args...)> : function_abc<R(Args...)> {
      free_function( R (*pf)(Args...)): m_pf(pf){}
      R apply( Args... args)const
      {
        return m_pf(args...);
      }
       private:
       R (*m_pf)(Args...);
   };

}}

namespace quan{

   template <typename F>
   struct function;

   template <typename R, typename ... Args>
   struct function<R(Args...)>
   {
       function():m_funpointer{nullptr}{}
       template <typename T>
       function(T ob, R(T::*fn)(Args...) )
       : m_funpointer(new detail::function_object<T,R(Args...)> (ob,fn)){}

       function(R (*fn)(Args...))
       : m_funpointer(new detail::free_function<R(Args...)>(fn)){}

      R operator()(Args... args)
      {
        return m_funpointer->apply(args...);
      }
      ~function(){ delete m_funpointer;}

      private:
      detail::function_abc<R(Args...)>* m_funpointer;

   };
}

#endif // QUAN_FUNCTION_HPP_INCLUDED
