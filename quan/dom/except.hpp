#ifndef QUAN_DOM_EXCEPT_HPP_INCLUDED
#define QUAN_DOM_EXCEPT_HPP_INCLUDED

#include <stdexcept>
#include <string>

namespace quan{ namespace dom{
   
    struct bad_node : std::invalid_argument{
        explicit bad_node(std::string const & str): std::invalid_argument(str){}
    };
    struct bad_branch_node : std::invalid_argument{
        explicit bad_branch_node(std::string const & str): std::invalid_argument(str){}
    };

    struct element_id_already_exists : std::invalid_argument{
        explicit element_id_already_exists(std::string const & str): std::invalid_argument(str){}
    };

    struct bad_path_string : std::invalid_argument{
        explicit bad_path_string(std::string const & str): std::invalid_argument(str){}
    };

    struct bad_id_string : std::invalid_argument{
        explicit bad_id_string(std::string const & str): std::invalid_argument(str){}
    };

    struct bad_id : std::invalid_argument{
        explicit bad_id(std::string const & str): std::invalid_argument(str){}
    };

    struct not_a_branch_node : std::invalid_argument{
        explicit not_a_branch_node (std::string const & str): std::invalid_argument(str){}
    };

    struct invalid_leaf_node : std::invalid_argument{
        explicit invalid_leaf_node (std::string const & str): std::invalid_argument(str){}
    };

     struct not_a_leaf_node : std::invalid_argument{
        explicit not_a_leaf_node (std::string const & str): std::invalid_argument(str){}
    };

    struct orphaned_node : std::domain_error{
        explicit orphaned_node (std::string const & str): std::domain_error(str){}
    };

    struct empty_id_string : std::invalid_argument{
        explicit empty_id_string (): std::invalid_argument("empty ID string"){}
    };

   /* struct no_leading_dot : std::invalid_argument{
        explicit no_leading_dot (std::string const & str): std::invalid_argument(str){}
    };*/
   
    struct I_am_not_a_branch_node : std::invalid_argument{
        I_am_not_a_branch_node(std::string const & in):
        std::invalid_argument(in){}
    };

}}//quan::dom


#endif

