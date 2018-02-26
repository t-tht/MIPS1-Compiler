#ifndef ast_simpstat_hpp
#define ast_simpstat_hpp

#include <string>
#include <iostream>
#include "ast_node.hpp"


//------------------------------------------------------------------------------------

class SimpStat;
class ReturnStat;
class AssignStat;
class AssertStat;

//------------------------------------------------------------------------------------

class SimpStat : public Node{
	protected:
	public:
		SimpStat();
		~SimpStat();
		virtual void print(std::ostream &dst) = 0;
};

//------------------------------------------------------------------------------------

class ReturnStat : public SimpStat{
	protected:
		std::string* return_t;
		Expression* expr;
	public:
		ReturnStat(std::string return_t_in, Expression* expr_in);
		~ReturnStat();
		void print(std::ostream &dst) const override;
};

//------------------------------------------------------------------------------------

class AssignStat : public SimpStat{
	protected:
		std::string* id;
		Expression* expr;
	public:
		AssignStat(std::string id_in, Expression* expr_in);
		~AssignStat();
		void print(std::ostream &dst) const override;
};

//------------------------------------------------------------------------------------

class AssertStat : public SimpStat{};

//------------------------------------------------------------------------------------
#endif
