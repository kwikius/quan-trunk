#ifndef QUAN_NUM_ELEMENTS_HPP_INCLUDED
#define QUAN_NUM_ELEMENTS_HPP_INCLUDED
 
/*
   part of the quan functiona api

   define quan::num_elements(seq) for your model of sequence
   define IndexType<Seq>
   define end(seq)
*/
 
namespace quan {
 
template <typename Seq> IndexType<Seq> num_elements (Seq const & seq);
}
 
#endif // QUAN_NUM_ELEMENTS_HPP_INCLUDED
 