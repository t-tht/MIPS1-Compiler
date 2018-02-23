#ifndef ast_hpp
#define ast_hpp
#include <string>
#include <iostream>
#include <map>

#include <memory>
//----------------------------------Declaration-------------------------------------
class Node;

//----------------------------------Node----------------------------------------

typedef const Node* NodePtr;
//https://stackoverflow.com/questions/750178/is-it-a-good-idea-to-typedef-pointers
class Node
{
public:
	virtual Node()
    virtual ~Node()
    {}

    //! Tell and expression to print itself to the given stream
    virtual void print(std::ostream &dst) const =0;
	virtual void construct()
    //! Evaluate the tree using the given mapping of variables to numbers
};
// ---------------------------------PROGRAM---------------------------------

class Function : public Node{
	protected:
	
	std::string* return_t;
	std::string* id;
	Statement* arg;
	Statement* body;
	
	Function(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in);
	~Function();
	
	print();
	
	public:
	
}

Function::Function(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in): return_t(return_t_in), id(id_in), arg(arg_in), body(body_in){}

Function::~Function(){}

Function::print(){
	std::cout << "def " << *id << "():" << std::endl;
	body->print();
}
// #include "ast/ast_expression.hpp"
// #include "ast/ast_primitives.hpp"
// #include "ast/ast_operators.hpp"
// #include "ast/ast_functions.hpp"

class Statement : public Node{
	protected:
	std::string *return_t;
	int val;
	
	Statement(std::string *return_t_in, int val_in);
	~Statement();
	
	print();
	public:
}

Statement::Statement(std::string *return_t_in, int val_in):return_t(return_t_in),val(val_in){}
Statement::~Statement(){}
Statement::print(){
	std::cout << "return " << val << std::endl;
}

extern const Node *parseAST();




#endif