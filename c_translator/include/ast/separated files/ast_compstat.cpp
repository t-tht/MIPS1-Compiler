#include "compstat.hpp"

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
