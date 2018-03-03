#ifndef ast_returnstat_hpp
#define ast_returnstat_hpp

#include<string>
#include<iostream>

class ReturnStat;

class ReturnStat : public Node{
	protected:
		int* num;
	public:
		ReturnStat(int* _num) : num(_num){};
		~ReturnStat(){};
		virtual void translate(std::ostream &dst)const override{
			dst << "return " << *num << std::endl;
		};
		virtual void print(std::ostream &dst)const override{
			dst << "return " << *num << std::endl;
		};
};

#endif