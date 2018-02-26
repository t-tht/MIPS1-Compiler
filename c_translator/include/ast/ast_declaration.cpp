#include "ast_declaration.hpp"

//------------------------------------------------------------------------------------

Declaration::Declaration(){}

Declaration::~Declaration(){}

//------------------------------------------------------------------------------------

VarDec::VarDec(std::string* id_in, double val_in) : id(id_in_), val(val_in){}

VarDec::~VarDec(){}

void VarDec::print(std::ostream &dst)const{
	dst << *id << " = " << val << ";" << std::endl;
}

//------------------------------------------------------------------------------------

FuncDec::FuncDec(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in): return_t(return_t_in), id(id_in), arg(arg_in), body(body_in){}

FuncDec::~FuncDec(){}

void FuncDec::print(std::ostream &dst)const{
	dst << "def " << *id << "():" << std::endl;
	body->print(dst);
}

//------------------------------------------------------------------------------------