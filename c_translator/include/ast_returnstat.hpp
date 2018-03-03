#ifndef ast_returnstat_hpp
#define ast_returnstat_hpp

#include<string>
#include<iostream>
#include<ast.hpp>

class ReturnStat;

class ReturnStat : public Node{
	protected:
		double num;
	public:
		ReturnStat(double _num) : num(_num){};
		~ReturnStat(){};
		void translate(std::ostream &dst)const{
			dst << "return " << num << std::endl;
		};
		void print(std::ostream &dst)const{
			dst << "return " << num << std::endl;
		};
};

#endif
