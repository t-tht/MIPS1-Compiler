#include "ast_expression.hpp"

//------------------------------------------------------------------------------------

Expression::Expression(){}

Expression::~Expression(){
	delete left;
	delete right;
}

void Expression::print(std::ostream &dst){
	dst << "--not implemented--" << std::endl;
}

//------------------------------------------------------------------------------------

ArithExpr::ArithExpr(Expression* left_in, std::string bin_op_in, Expression* right_in) : left(left_in), bin_op(bin_op_in), right(right_in){}

ArithExpr::~ArithExpr(){
	delete left;
	delete right;
}

std::string getop(){
	return bin_op;
}

void ArithExpr::print(std::ostream &dst){
	left->print(dst);
	dst << getop();
	right->print(dst);
}

//------------------------------------------------------------------------------------

ComprExpr::ComprExpr(Expression* left_in, std::string compr_op_in, Expression* right_in) : left(left_in), compr_op(compr_op_in), right(right_in){}

ComprExpr::~ComprExpr(){
	delete left;
	delete right;
}

void ComprExpr::print(std::ostream &dst){}

//------------------------------------------------------------------------------------