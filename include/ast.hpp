#ifndef ast_hpp
#define ast_hpp

#include <iostream>
#include <vector>
#include <string>

extern int tab;
extern std::vector<std::string> globalvars;
extern int jump;

#include "ast_interpretcontext.hpp"
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
#include "ast_arg.hpp"
#include "ast_globalvariable.hpp"
#include "ast_whilestatement.hpp"
#include "ast_incrementdecrement.hpp"
#include  "ast_forstatement.hpp"

//TODO: assignment, binexpr ( 2 more todo) , block, comprexpr, funcCallExpr, funcdec (write the proper pointers), if statement not implemented, param_var, param, variable, var dec
//what has been done, program, block, return stat, bin expr 2 signs

extern const Node *parseAST();

#endif
