#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include <string>
#include <iostream>
#include "ast_node.hpp"
#include "ast_compstat.hpp"

//------------------------------------------------------------------------------------

class Declaration;
class VarDecl;
class FuncDecl;

//------------------------------------------------------------------------------------

class Declaration : public Node{
	protected:
	public:
		Declaration();
		~Declaration();
		virtual void print(std::ostream &dst) const = 0;
};

//------------------------------------------------------------------------------------

class VarDecl : public Declaration{
	protected:
		std::string* id;
		double val;
	public:
		VarDecl(std::string* id_in, double val_in);
		~VarDecl();
		void print(std::ostream &dst) const override;
};

//------------------------------------------------------------------------------------

class FuncDecl: public Declaration{
	protected:
		std::string *return_t;
		std::string *id;
		Statement* arg_in;
        Statement* bodyl;
	public:
		FuncDecl(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in);
		~FuncDecl():
		void print(std::ostream &dst) const override;
};

//------------------------------------------------------------------------------------

#endif
