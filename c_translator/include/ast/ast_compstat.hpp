#ifndef ast_compstat_hpp
#define ast_compstat_hpp

#include <string>
#include <iostream>
#include "ast_node.hpp"


//------------------------------------------------------------------------------------

class CompStat;
class IfElStat;
class ForStat;
class WhileStat;
class Block;
//------------------------------------------------------------------------------------

class CompStat : public Node{
	protected:
	public:
		CompStat();
		~CompStat();
		virtual void print(std::ostream &dst) const = 0;
};
//------------------------------------------------------------------------------------

class Block : public CompStat{
protected:
public:
    Block();
    ~Block();
    void print(std::ostream &dst) const override;
};
//------------------------------------------------------------------------------------

class IfElStat : public CompStat{
	protected:
	public:
		IfElStat();
		~IfElStat();
		void print(std::ostream &dst) const override;
};

//------------------------------------------------------------------------------------

class ForStat : public CompStat{
	protected:
	public:
		ForStat();
		~ForStat();
    void print(std::ostream &dst) const override;
};

//------------------------------------------------------------------------------------

class WhileStat : public CompStat{
	protected:
	public:
		WhileStat();
		~WhileStat();
    void print(std::ostream &dst) const override;
};

//------------------------------------------------------------------------------------

#endif
