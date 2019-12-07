#ifndef QUAN_META_CUSTOM_DIMENSION_HPP_INCLUDED
#define QUAN_META_CUSTOM_DIMENSION_HPP_INCLUDED

#define QUAN_META_CUSTOM_DIMENSION

#include <type_traits>
#include <quan/meta/type_sequence.hpp>
#include <quan/meta/custom_dimension/base_dimension.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/and.hpp>

namespace quan{ namespace meta{

   template <typename ...D>
   struct dimension{
       typedef dimension type;
       static constexpr uint32_t num_elements = sizeof...(D);
   };

   template <> struct dimension<>{
      typedef dimension type;
      static constexpr uint32_t num_elements = 0;
   };

   template <typename T>
   struct is_dimension : std::false_type{};

   template <typename ...D>
   struct is_dimension<dimension<D...> > : std::true_type{};

   

}}

/*
namespace quan{ namespace impl{

   // 
   template <typename ...D>
      struct is_model_of_impl<
         quan::meta::TypeSequence_,
         quan::meta::dimension<D...> 
      > : std::true_type{};

}} // quan::impl
*/
namespace quan{ namespace meta{
/*
   namespace impl{

       template <typename ... D>
       struct get_num_elements_impl<
            quan::meta::dimension<D...>
       > : std::integral_constant<uint32_t, (sizeof...(D) )>{};

   }
*/
   template <typename T>
   struct push_back<quan::meta::dimension<>,T >{
      typedef quan::meta::dimension<T> type;
   };

   template <typename ... L, typename T>
   struct push_back<quan::meta::dimension<L...>,T >{
      typedef quan::meta::dimension<L...,T> type;
   };

   template <typename Front, typename ... List>
   struct pop_front<quan::meta::dimension<Front,List...> >
   {
      typedef quan::meta::dimension<List...> type;
   };

   template <>
   struct pop_front<quan::meta::dimension<> >
   {
      // could just be empty_list?
      typedef quan::undefined type;
   };

   template <typename...L, typename T>
   struct push_front<quan::meta::dimension<L...> , T>
   {
       typedef quan::meta::dimension<T,L...> type;
   };

   template < typename Front, typename... List> 
   struct front<quan::meta::dimension<Front,List...> >
   {
      typedef Front type;
   };

   template < typename Front> 
   struct front<quan::meta::dimension<Front> >
   {
      typedef Front type;
   };

   template <>
   struct front<quan::meta::dimension<> >
   {
      // could just be empty_list?
      typedef quan::undefined type;
   };

   template < typename Front ,typename... List> 
   struct back< quan::meta::dimension<Front,List...> >
   {
      typedef typename back<quan::meta::dimension<List...> >::type type;
   };

   template < typename Back> 
   struct back< quan::meta::dimension<Back> >
   {
      typedef Back type;
   };

   template <>
   struct back<quan::meta::dimension<> >
   {
      // could just be empty_list?
      typedef quan::undefined type;
   };

}}//quan::meta

/*
namespace quan{ namespace meta{

   template <uint32_t N, typename... List>
   struct at<N,quan::meta::dimension<List...> >{
       typedef quan::meta::dimension<List...> list_type;
       static_assert(N < list_type::length,"index out of range in quan::meta::dimension");
       typedef typename quan::meta::eval_if_c<
            N==0,
            quan::meta::front<list_type>,
            quan::meta::at<N-1,typename quan::meta::pop_front<list_type>::type>
       >::type type; 
   };

   template <uint32_t N>
   struct at<N,quan::meta::dimension<> >{
      typedef quan::undefined type;
   };
   
}}// quan::meta
*/
namespace quan{ namespace meta{ namespace detail{

   // algorthim to extract the base_dimension from the dimension D
   template <typename D, base_dimension_id_t Id, int Size>
   struct get_base_dimension_i;

   // end of dimension D, base_dim not found so return zero size base_dim
   template <typename D, base_dimension_id_t Id>
   struct get_base_dimension_i<D,Id,0> : make_base_dimension_ratio<Id, std::ratio<0,1> >{};

   // not end of dimension D
   // return base_dim recursively
   template <typename D, base_dimension_id_t Id, int Size>
   struct get_base_dimension_i {
   typedef typename D::type dimension;
   typedef typename quan::meta::front<dimension>::type base_dim;
   typedef typename quan::meta::eval_if_c<
      (base_dim::base_dimension_id == Id),
      make_base_dimension_ratio<Id,typename base_dim::ratio>, // reduce
      get_base_dimension_i<quan::meta::pop_front<dimension>,Id,Size - 1>
   >::type type;   
   };

   //ll interface to extract the base_dim with id Id from dimension D
   // base_dim of zero extent signifies not found
   template <typename D, base_dimension_id_t Id>
   struct get_base_dimension : get_base_dimension_i<
      D, Id,D::type::num_elements
   >{};


/*
   find the base dimensions with id in lhs and rhs 
   apply Op and if result not zero add to result dimension
   Op is  Op<base_dimension,base_dimension> -> base_dimension
*/
   template <
      typename LhsD,  
      template <typename, typename> class Op,
      typename RhsD, 
      base_dimension_id_t Id,
      typename ResultD      
   >struct result_push_back_additive_op_dims_base_dims{

       typedef typename Op< 
          typename get_base_dimension<LhsD,Id>::type,
          typename get_base_dimension<RhsD,Id>::type
       >::type result_base_dim;

       typedef typename quan::meta::eval_if_c<
          base_dimension_is_zero<result_base_dim>::value,
          ResultD,
          quan::meta::push_back<ResultD,result_base_dim>
       >::type type;
   };

   // specialise above for addition
   template <
      typename LhsD,    
      typename RhsD, 
      base_dimension_id_t Id,
      typename ResultD
   >
   struct result_push_back_add_dims_base_dims :
   result_push_back_additive_op_dims_base_dims<
      LhsD, add_base_dimension_ratio, RhsD,Id, ResultD
   >{};

   // specialise above for subtraction
   template <
      typename LhsD,    
      typename RhsD, 
      base_dimension_id_t Id,
      typename ResultD
   >
   struct result_push_back_subtract_dims_base_dims :
   result_push_back_additive_op_dims_base_dims<
      LhsD,subtract_base_dimension_ratio, RhsD, Id, ResultD
   >{};

   // ll additive binary ops on dimensions
   // Op is  Op<base_dimension,base_dimension> -> base_dimension
   template < typename LhsD,template<typename,typename> class Op, typename RhsD, base_dimension_id_t I, typename ResultD>
   struct additive_op_dimensions_i{
      typedef typename result_push_back_additive_op_dims_base_dims<LhsD,Op,RhsD,I,ResultD>::type result;
      typedef typename quan::meta::eval_if_c<
         I == base_dimension_id_t::last_element,
         result,
         additive_op_dimensions_i<LhsD,Op,RhsD,static_cast<base_dimension_id_t>(static_cast<uint8_t>(I)+1),result>
      >::type type;
   };
 
   //Op is  Op<base_dimension,base_dimension> -> base_dimension
   template <typename LhsD, template<typename,typename> class Op,typename RhsD>
   struct additive_op_dimensions : additive_op_dimensions_i<LhsD,Op,RhsD,base_dimension_id_t::first_element, dimension<> >{};

   // ll additive ops on dimensions interface
   template <typename LhsD, typename RhsD>
   struct add_dimensions : additive_op_dimensions_i<LhsD,add_base_dimension_ratio, RhsD, base_dimension_id_t::first_element,dimension<> >{};

   template <typename LhsD, typename RhsD>
   struct subtract_dimensions : additive_op_dimensions_i<LhsD,subtract_base_dimension_ratio, RhsD, base_dimension_id_t::first_element,dimension<> >{};

// -- multiplicative ops on dimension----
//  MultiplicativeOp<base_dim, Ratio> -> base_dim

   template <
      typename LhsD,  
      template <typename, typename> class MultiplicativeOp,
      typename Ratio, 
      base_dimension_id_t Id,
      typename ResultD      
   >struct result_push_back_multiplicative_op_dims_base_dims{

       typedef typename MultiplicativeOp< 
          typename get_base_dimension<LhsD,Id>::type,
          typename Ratio::type
       >::type result_base_dim;

       typedef typename quan::meta::eval_if_c<
          base_dimension_is_zero<result_base_dim>::value,
          ResultD,
          quan::meta::push_back<ResultD,result_base_dim>
       >::type type;
   };

   template <
      typename LhsD,    
      typename Ratio, 
      base_dimension_id_t Id,
      typename ResultD
   >
   struct result_push_back_multiply_dims_base_dims :
   result_push_back_multiplicative_op_dims_base_dims<
      LhsD, multiply_base_dimension_ratio, Ratio,Id, ResultD
   >{};

   template <
      typename LhsD,    
      typename Ratio, 
      base_dimension_id_t Id,
      typename ResultD
   >
   struct result_push_back_divide_dims_base_dims :
   result_push_back_multiplicative_op_dims_base_dims<
      LhsD, divide_base_dimension_ratio, Ratio,Id, ResultD
   >{};

     // Op is  Op<base_dimension,base_dimension> -> base_dimension
   template < typename LhsD,template<typename,typename> class Op, typename Ratio, base_dimension_id_t I, typename ResultD>
   struct multiplicative_op_dimensions_i{
      typedef typename result_push_back_multiplicative_op_dims_base_dims<LhsD,Op,Ratio,I,ResultD>::type result;
      typedef typename quan::meta::eval_if_c<
         I == base_dimension_id_t::last_element,
         result,
         multiplicative_op_dimensions_i<LhsD,Op,Ratio,static_cast<base_dimension_id_t>(static_cast<uint8_t>(I)+1),result>
      >::type type;
   };

   template <typename LhsD, template<typename,typename> class Op,typename Ratio>
   struct multiplicative_op_dimensions : additive_op_dimensions_i<LhsD,Op,Ratio,base_dimension_id_t::first_element, dimension<> >{};

   // ll multiplicative ops on dimensions interface
   template <typename LhsD, typename Ratio>
   struct multiply_dimension : multiplicative_op_dimensions_i<LhsD,multiply_base_dimension_ratio, Ratio, base_dimension_id_t::first_element,dimension<> >{};

     // ll multiplicative ops on dimensions interface
   template <typename LhsD, typename Ratio>
   struct divide_dimension : multiplicative_op_dimensions_i<LhsD,divide_base_dimension_ratio, Ratio, base_dimension_id_t::first_element,dimension<> >{};

   // negate dimension

   template <typename D>
   struct negate_dimension : multiply_dimension<D,std::ratio<-1> >{};

  // compare

   template <typename DL, typename DR> 
   struct are_equal_dimensions : std::is_same<typename subtract_dimensions<DL,DR>::type, quan::meta::dimension<> >{}; 
  
   template <typename DL, typename DR> 
   struct are_not_equal_dimensions : quan::meta::not_< are_equal_dimensions<DL,DR> >{};
       
}}} // quan::meta::detail

#endif // QUAN_META_CUSTOM_DIMENSION_HPP_INCLUDED
