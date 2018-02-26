#ifndef ast_hpp
#define ast_hpp

#include <string>
#include <iostream>
#include <map>
#include <memory>


#include "ast/ast_compstat.hpp"
#include "ast/ast_declaration.hpp"
#include "ast/ast_expression.hpp"
#include "ast/ast_node.hpp"
#include "ast/ast_simpstat.hpp"

extern const Node* parseAST();

#endif
//class Node;
//class Function;
//class Statement;
//class Number;


//class Node{
//	public:
//		Node();
//		~Node();
//		virtual void print(std::ostream &dst) const =0;
//
//};
//
//
//class Function : public Node{
//	protected:
//		std::string* return_t;
//		std::string* id;
//		Statement* arg;
//		Statement* body;
//	public:
//		Function(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in);
//		~Function();
//		virtual void print(std::ostream &dst) const override;
//};
//
//
//class Statement : public Node{
//	protected:
//		std::string *return_t;
//		double val;
//	public:
//		Statement(double val_in);
//		~Statement();
//		virtual void print(std::ostream &dst) const override;
//};
//
//
//class Number : public Node{
//	protected:
//		double val;
//	public:
//		Number(double val_in);
//		~Number();
//		virtual void print(std::ostream &dst) const override;
//};

