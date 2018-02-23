#ifndef ast_hpp
#define ast_hpp

#include <string>
#include <iostream>
#include <map>
#include <memory>

class Node;
class Function;
class Statement;
class Number;


class Node{
	public:
		Node();
		~Node();
		void print(std::ostream &dst) const;

};


class Function : public Node{
	protected:
		std::string* return_t;
		std::string* id;
		Statement* arg;
		Statement* body;
	public:
		Function(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in);
		~Function(); 
		void print() const;	
};


class Statement : public Node{
	protected:
		std::string *return_t;
		double val;
	public:
		Statement(double val_in);
		~Statement();
		void print() const;
};


class Number : public Node{
	protected:
		double val;
	public:
		Number(double val_in);
		~Number();
		void print() const;
};

extern const Node* parseAST();
#endif