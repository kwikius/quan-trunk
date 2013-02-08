

#include <cassert>

template <typename Lex>
int quan::lexer::lookahead<Lex>::get()
{
   if ( !m_list.size()){
      append_token();
   }
   else{
   #ifndef QUAN_BOEHM_GC
      delete m_curr_tok;
   #endif
      m_curr_tok = m_list.front();
      m_list.pop_front();
      if(!m_list.size()){
         append_token();
      }
   }
   return m_list.front()->token_id;
}


template <typename Lex>
void quan::lexer::lookahead<Lex>::append_token()
{
#ifdef   QUAN_BOEHM_GC
   token_type * tok = quan::gc_malloc<token_type>();
#else
   token_type * tok = new token_type;
#endif
   m_lexer->yylex(*tok) ;
   m_list.push_back(tok);
}


template <typename Lex>
typename quan::lexer::lookahead<Lex>::token_type*
 quan::lexer::lookahead<Lex>::peek_tok(int n)
{
   assert( n >= 0);
//   if ( n==0){
//      return m_curr_tok;
//   }
   while( m_list.size() < static_cast<std::size_t>(n+1) ){
      append_token();
   }
   typename list_type::iterator iter = m_list.begin();
   for (int p = 0;p<n;++p){
      ++iter;
   }
   assert(iter != m_list.end());
   return *iter;
}

template <typename Lex>
int quan::lexer::lookahead<Lex>::peek(int n)
{
   return peek_tok(n)->token_id;
}

template <typename Lex>
quan::lexer::lookahead<Lex>::lookahead(Lex* lex_in)
:m_lexer(lex_in),m_curr_tok(0)
{
   assert(m_lexer);
}

template <typename Lex>
quan::lexer::lookahead<Lex>::~lookahead()
{
#ifndef QUAN_BOEHM_GC
   if (m_curr_tok){
      delete m_curr_tok;
   }
   while( m_list.size()){
      delete *(m_list.begin());
      m_list.pop_front();
   }
#endif
}

template <typename Lex>
typename quan::lexer::lookahead<Lex>::token_type*
quan::lexer::lookahead<Lex>::get_curr_tok()
{
   assert(m_curr_tok);
   return m_curr_tok;
  
}

template <typename Lex>
typename quan::lexer::lookahead<Lex>::token_type*
quan::lexer::lookahead<Lex>::clone_curr_tok()
{
   assert(m_curr_tok);
 #ifdef QUAN_BOEHM_GC
   return quan::gc_malloc<token_type>(*m_curr_tok);
 #else
   return  new token_type(*m_curr_tok);
 #endif
}

template <typename Lex>
quan::lexer::source_pos
quan::lexer::lookahead<Lex>::get_position()const
{
   assert(m_lexer);
   return m_lexer->get_position();
}

template <typename Lex>
Lex* quan::lexer::lookahead<Lex>::get_lexer() const
{
   return m_lexer;
}
