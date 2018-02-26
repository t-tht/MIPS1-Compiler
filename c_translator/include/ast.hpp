#ifndef ast_hpp
#define ast_hpp
#include <string>
#include <iostream>

class Node;

class Block;

class Declaration;
class VarDecl;
class FuncDecl;

class Expression;
class ArithExpr;
class ComprExpr;

class CompStat;
class IfElStat;
class ForStat;
class WhileStat;
class Block;

class SimpStat;
class ReturnStat;
class AssignStat;
class AssertStat;

extern const Node *parseAST();

class Node{
	public:
		Node();
		~Node();
		virtual void print(std::ostream &dst) const =0;
};

//------------------------------------------------------------------------------------

class Block: public Node{
	protected:
		CompStat* compstat;
		SimpStat* simpstat;
	public:
		Block();
    Block(SimpStat* simpstat_in);
		~Block();
		virtual void print(std::ostream &dst) const;
};

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
		std::string* type;
		std::string* id;
		double val;
	public:
		VarDecl(std::string* type_in, std::string* id_in, double val_in);
		~VarDecl();
		virtual void print(std::ostream &dst) const;
};

//------------------------------------------------------------------------------------

class FuncDecl: public Declaration{
	protected:
		std::string type;
		std::string id;
		Node* arg;		//needs fixing later, but atm assume no arg
    Block* body;
	public:
		FuncDecl(std::string type_in, std::string id_in, Node* arg_in, Block* body_in);
		~FuncDecl();
		virtual void print(std::ostream &dst) const;
};

//------------------------------------------------------------------------------------


class Expression : public Node{
	protected:
		Expression* left;
		Expression* right;
	public:
		Expression();
		~Expression();
		virtual void print(std::ostream &dst) const = 0;
};

//------------------------------------------------------------------------------------

class ArithExpr : public Expression{
	protected:
		std::string* arith_op;
	public:
		ArithExpr(Expression* left_in, std::string* bin_op_in, Expression* right_in);
		~ArithExpr();
		std::string getop();
		void print(std::ostream &dst) const;
};

//------------------------------------------------------------------------------------

class ComprExpr : public Expression{
	protected:
		std::string compr_op;
	public:
		ComprExpr(Expression* left_in, std::string compr_op_in, Expression* right_in);
		~ComprExpr();
		std::string getop();
		void print(std::ostream &dst) const;
};
//------------------------------------------------------------------------------------

class NumExpr : public Expression{
	protected:
		double val;
	public:
		NumExpr();
		~NumExpr();
		void print(std::ostream &dst) const;
};

//------------------------------------------------------------------------------------

class Statement : public Node{
	protected:
	public:
		virtual ~Statement();
		virtual void print(std::ostream &dst) const = 0;
};

//------------------------------------------------------------------------------------

class StatementSeq : public Statement{
	protected:
		Statement* list;
		Statement* stat;
	public:
		StatementSeq(Statement* list_in, Statement* stat_in);
		virtual ~StatementSeq();
		virtual void print(std::ostream &dst) const = 0;
};

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
		Expression* expr;
	public:
		ReturnStat(Expression* expr_in);
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



class CompStat : public Node{
	protected:
	public:
		CompStat();
		~CompStat();
		virtual void print(std::ostream &dst) = 0;
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
