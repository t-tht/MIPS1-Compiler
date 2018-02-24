#include "ast.hpp"

Node::Node(){}

Node::~Node(){}



Function::Function(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in): return_t(return_t_in), id(id_in), arg(arg_in), body(body_in){}

Function::~Function(){}

void Function::print() const{
	std::cout << "def " << *id << "():" << std::endl;
	body->print();
}

Statement::Statement(double val_in):val(val_in){}

Statement::~Statement(){}

void Statement::print() const{
	std::cout << "return " << val << std::endl;
}

Number::Number(double val_in) : val(val_in){}

Number::~Number(){}

void Number::print() const{
	std::cout<<val<<std::endl;
}
