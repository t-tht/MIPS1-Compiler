#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include "ast_node.hpp"

//------------------------------------------------------------------------------------

class Expression;
class ArithExpr;
class ComprExpr;

//------------------------------------------------------------------------------------

class Expression : public Node{
	protected:
		Expression* left;
		Expression* right;
	public:
		Expr();
		~Expr();
		virtual void print(std::ostream &dst) const = 0;
};

//------------------------------------------------------------------------------------

class ArithExpr : public Expression{
	protected:
		std::string arith_op;
	public:
		ArithExpr(Expression* left_in, std::string bin_op_in, Expression* right_in);
		~ArithExpr();
		std::string getop();
		void print(std::ostream &dst) const;
};


//------------------------------------------------------------------------------------

class ComprExpr : public Expression{
	protected:
		std::string compr_op;
	public:
		ComprExpr(Expression* left_in, std::string compr_op_in, Expression* right_in);
		~ComprExpr();
		void print(std::ostream &dst) const;
};

//------------------------------------------------------------------------------------

#endif
