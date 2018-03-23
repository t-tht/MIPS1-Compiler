#ifndef ast_primative_hpp
#define ast_primative_hpp

#include "ast.hpp"

class Number;
class Variable;

class Number : public Node{
private:
	double value;
public:
	Number(double _value) : value(_value){};
	~Number(){};
	double getval() const{
		return value;
	};
	void translate(std::ostream &dst)const override{
		dst << value;
	};
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
		dst << "\tli\t\t$" << destloc << ", " << value << std::endl;
	};
	unsigned int GetContext(InterpretContext &cntx) const override{return value;};
};

class Variable : public Node{
private:
	std::string* id;
public:
	Variable(std::string* _id) : id(_id){};
	~Variable(){};
	void translate(std::ostream &dst)const override{
		dst << *id;
	};
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{};
	unsigned int GetContext(InterpretContext &cntx) const override{
		return cntx.FindVariable(*id);
	};
};

#endif
