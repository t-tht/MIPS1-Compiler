#include "ast_node.hpp"

//------------------------------------------------------------------------------------

Node::Node(){}

Node::~Node(){}

void Node::print(std::ostream &dst){}

//------------------------------------------------------------------------------------

Block::Block();
Block::~Block();
Block::Block(SimpStat* simpstat_in)
: simpstat(simpstat_in), compstat(NULL)
{}


//------------------------------------------------------------------------------------

Declaration::Declaration(){}

Declaration::~Declaration(){}

//------------------------------------------------------------------------------------

VarDecl::VarDecl(std::string* type_in, std::string* id_in, double val_in) : type(type_in), id(id_in_), val(val_in){}

VarDecl::~VarDecl(){}

void VarDecl::print(std::ostream &dst)const{
	dst << *id << " = " << val << ";" << std::endl;
}

//------------------------------------------------------------------------------------

FuncDecl::FuncDecl(std::string* type_in, std::string* id_in, Node* arg_in, Block* body_in): type(type_in), id(id_in), arg(arg_in), body(body_in){}

FuncDecl::~FuncDecl(){
	delete arg_in;
	delete body;
}

void FuncDecl::print(std::ostream &dst)const{
	dst << "def " << *id << "():" << std::endl;
	body->print(dst);
}

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

ArithExpr::ArithExpr(Expression* left_in, std::string arith_op_in, Expression* right_in) : left(left_in), arith_op(arith_op_in), right(right_in){}

ArithExpr::~ArithExpr(){
	delete left;
	delete right;
}

std::string getop(){
	return arith_op;
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

std::string ComprExpr::getop(){
	return compr_op;
}

void ComprExpr::print(std::ostream &dst){}

//------------------------------------------------------------------------------------

Statement::~Statement(){}

void Statement::print(std::ostream &dst){}

//------------------------------------------------------------------------------------

StatementSeq::StatementSeq(Statement* list_in, Statement* stat_in) : list(list_in), stat(stat_in){}

StatementSeq::~StatementSeq(){
	delete list;
	delete stat;
}

void StatementSeq::print(std::ostream &dst){
	stat->print(dst);
	list->print(dst);
}

//------------------------------------------------------------------------------------

SimpStat::SimpStat(){}

SimpStat::~SimpStat(){}

void SimpStat::print()const{}

//------------------------------------------------------------------------------------

ReturnStat::ReturnStat(std::string type_in, Expression* expr_in) : type(type_in), expr(expr_in){}
ReturnStat::~ReturnStat(){
	delete expr;
}
void ReturnStat::print(std::ostream &dst)const{
	dst << "return ";
	expr->print();
}

//------------------------------------------------------------------------------------

AssignStat::AssignStat(){}
AssignStat::~AssignStat(){
	delete expr;
}
void AssignStat::print(std::ostream &dst)const{
	dst << id << " = ";
	expr->print();
}

//------------------------------------------------------------------------------------

AssertStat::AssertStat(){}
AssertStat::~AssertStat(){}
void AssertStat::print(std::ostream &dst)const{}

//------------------------------------------------------------------------------------

CompStat::CompStat(){}

CompStat::~CompStat(){}

void CompStat::print(std::ostream &dst)const{
	dst << "--not implemented--" << std::endl;
}

//------------------------------------------------------------------------------------

IfElStat::IfElStat(){}

IfElStat::~IfElStat(){}

void IfElStat::print(std::ostream &dst)const{}

//------------------------------------------------------------------------------------

ForStat::ForStat(){}

ForStat::~ForStat(){}

void ForStat::print(std::ostream &dst)const{}

//------------------------------------------------------------------------------------

WhileStat::WhileStat(){}

WhileStat::~WhileStat(){}

void WhileStat::print(std::ostream &dst)const{}

//------------------------------------------------------------------------------------

Block::Block(){}
Block::~Block(){}

void Block::print(std::ostream &dst)const{
    
}
