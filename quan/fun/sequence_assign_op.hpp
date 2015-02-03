#ifndef QUANTA_OF_VECTOR_SEQUENCE_ASSIGN_OP_HPP_INCLUDED
#define QUANTA_OF_VECTOR_SEQUENCE_ASSIGN_OP_HPP_INCLUDED

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

#include <quan/fun/access_modifiers.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/auto_at_seq.hpp>
#include <quan/fun/are_fun_sequences.hpp>
#include <quan/fun/same_size_seq.hpp>

namespace quan{namespace fun{

    template <int N, typename AssignmentOp>
    struct sequence_assign_op;

    template <typename AssignmentOp>
    struct sequence_assign_op<0,AssignmentOp>{

        template <typename SeqL, typename SeqR>
        struct result{
            typedef typename at_seq<0,SeqL,as_ref>::type type;
        };

        template <typename SeqL, typename SeqR >
        typename result<SeqL, SeqR>::type
        operator()(SeqL & seqL, SeqR const & seqR)const
        {
            at_seq<0,SeqL,as_ref> to;
            at_seq<0,SeqR,as_const_ref> from;
            AssignmentOp op;
            return op(to(seqL),from(seqR));
        }
        template <typename SeqL, typename SeqR >
        typename result<SeqL, SeqR>::type
        operator()(SeqL & seqL, SeqR  & seqR)const
        {
            at_seq<0,SeqL,as_ref> to;
            at_seq<0,SeqR,as_ref> from;
            AssignmentOp op;
            return op(to(seqL),from(seqR));
        }
    };

    template <int N,typename AssignmentOp>
    struct sequence_assign_op{

        template <typename SeqL, typename SeqR>
        struct result{
            
            static_assert(are_fun_sequences<SeqL,SeqR>::value ==true,"error");
            static_assert(same_size_seq<SeqL,SeqR>::value == true , "error");
            
            typedef typename at_seq<N,SeqL,as_ref>::type type;
        };

        template <typename SeqL, typename SeqR>
        typename result<SeqL, SeqR>::type
        operator()(SeqL & seqL, SeqR & seqR)const
        {
            sequence_assign_op<N-1,AssignmentOp> prev;
            prev(seqL,seqR);
            at_seq<N,SeqL,as_ref> to;
            at_seq<N,SeqR,as_ref> from;
            AssignmentOp op;
            return op(to(seqL),from(seqR));       
        }

        template <typename SeqL, typename SeqR>
        typename result<SeqL, SeqR>::type
        operator()(SeqL & seqL, SeqR const & seqR)const
        {
            sequence_assign_op<N-1,AssignmentOp> prev;
            prev(seqL,seqR);
            auto_at_seq<N,SeqL> to;
            at_seq<N,SeqR,as_const_ref> from;
            AssignmentOp op;
            return op(to(seqL),from(seqR));       
        }
    };

}}//quan::fun

#endif
