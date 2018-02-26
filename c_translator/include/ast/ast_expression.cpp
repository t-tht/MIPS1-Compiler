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

BinExpr::BinExpr(Expression* left_in, std::string bin_op_in, Expression* right_in) : left(left_in), bin_op(bin_op_in), right(right_in){}

BinExpr::~BinExpr(){
	delete left;
	delete right;
}

std::string getop(){
	return bin_op;
}

void BinExpr::print(std::ostream &dst){
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