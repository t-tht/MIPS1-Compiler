#ifndef ast_hpp
#define ast_hpp

#include "ast_node.hpp"
#include "ast_funcdec.hpp"
#include "ast_returnstat.hpp"
#include "ast_primative.hpp"
#include "ast_binexpr.hpp"
#include "ast_program.hpp"
#include "ast_funccallexpr.hpp"
#include "ast_param.hpp"
#include "ast_param_var.hpp"
#include "ast_vardec.hpp"
#include "ast_block.hpp"
#include "ast_assignment.hpp"
#include "ast_compexpr.hpp"
#include "ast_ifstatement.hpp"
#include "ast_interpretcontext.hpp"


extern const Node *parseAST();

#endif
