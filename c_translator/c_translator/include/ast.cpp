#include "ast.hpp"

Node::Node(){}

Node::~Node(){}


Function::Function(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in): return_t(return_t_in), id(id_in), arg(arg_in), body(body_in){}

Function::~Function(){}

void Function::print(std::ostream &dst) const{
	dst << "def " << *id << "():" << std::endl;
	body->print(dst);
}

Statement::Statement(double val_in):val(val_in){}

Statement::~Statement(){}

void Statement::print(std::ostream &dst) const{
	dst << "return " << val << std::endl;
}

Number::Number(double val_in) : val(val_in){}

Number::~Number(){}

void Number::print(std::ostream &dst) const{
	dst<<val<<std::endl;
}
