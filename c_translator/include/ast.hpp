#ifndef ast_hpp
#define ast_hpp

#include "ast_node.hpp"
#include "ast_funcdec.hpp"
#include "ast_returnstat.hpp"
#include "ast_primative.hpp"
#include "ast_binexpr.hpp"
#include "ast_program.hpp"


extern const Node *parseAST();

#endif
