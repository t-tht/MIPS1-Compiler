#ifndef "COMPSTAT_HPP"
#define "COMPSTAT_HPP"

#include <string>
#include <iostream>

//------------------------------------------------------------------------------------

class CompStat;
class IfElStat;
class ForStat;
class WhileStat;

//------------------------------------------------------------------------------------

class CompStat : public Node{
	protected:
	public:
		CompStat();
		~CompStat();
		virtual void print(std::ostream &dst) const = 0;
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
		void print(std::ostream &dst) const override
};

//------------------------------------------------------------------------------------

class WhileStat : public CompStat{
	protected:
	public:
		WhileStat();
		~WhileStat();
		void print(std::ostream &dst) const override
};

//------------------------------------------------------------------------------------

#endif