#include "ast_simpstat.hpp"

//------------------------------------------------------------------------------------

SimpStat::SimpStat(){}

SimpStat::~SimpStat(){}

void SimpStat::print()const{}

//------------------------------------------------------------------------------------

ReturnStat::ReturnStat(){}
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