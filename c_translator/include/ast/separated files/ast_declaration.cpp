#include "ast_declaration.hpp"

//------------------------------------------------------------------------------------

Declaration::Declaration(){}

Declaration::~Declaration(){}

//------------------------------------------------------------------------------------

VarDecl::VarDecl(std::string* id_in, double val_in) : id(id_in_), val(val_in){}

VarDecl::~VarDecl(){}

void VarDecl::print(std::ostream &dst)const{
	dst << *id << " = " << val << ";" << std::endl;
}

//------------------------------------------------------------------------------------

FuncDecl::FuncDecl(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in): return_t(return_t_in), id(id_in), arg(arg_in), body(body_in){}

FuncDecl::~FuncDecl(){}

void FuncDecl::print(std::ostream &dst)const{
	dst << "def " << *id << "():" << std::endl;
	body->print(dst);
}

//------------------------------------------------------------------------------------