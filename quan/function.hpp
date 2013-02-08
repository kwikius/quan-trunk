#ifndef QUAN_FUNCTION_HPP_INCLUDED
#define QUAN_FUNCTION_HPP_INCLUDED

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
