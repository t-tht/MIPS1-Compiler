#ifndef "AST_EXPRESSION_HPP"
#define "AST_EXPRESSION_HPP"

#include <string>
#include <iostream>

//------------------------------------------------------------------------------------

class Expression;
class BinExpr;
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

class BinExpr : public Expression{
	protected:
		std::string bin_op;
	public:
		BinExpr(Expression* left_in, std::string bin_op_in, Expression* right_in);
		~BinExpr();
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