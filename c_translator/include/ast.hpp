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

typedef const Node *NodePtr;

class Node{
	public:
    ~Node(){}
		virtual void print(std::ostream &dst) const =0;
};

//------------------------------------------------------------------------------------

class Block: public Node{
	protected:
		CompStat* compstat;
		SimpStat* simpstat;
	public:
		Block();
        Block(SimpStat* simpstat_in): simpstat(simpstat_in), compstat(NULL)
        {}
		~Block();
		virtual void print(std::ostream &dst) const;
};

//------------------------------------------------------------------------------------
//
//class Declaration : public Node{
//	protected:
//	public:
//    Declaration(){}
//    ~Declaration(){}
//		virtual void print(std::ostream &dst) const = 0;
//};

//Declaration main purpose is to be a base class for VarDecl and FuncDecl but it's a bit redundant
//------------------------------------------------------------------------------------

class VarDecl : public Node{
	protected:
		std::string* type;
		std::string* id;
		double val;
	public:
		VarDecl(std::string* type_in, std::string* id_in, double val_in) : type(type_in), id(id_in), val(val_in){}
		~VarDecl(){}
    virtual void print(std::ostream &dst) const {
        dst << *id << " = " << val << ";" << std::endl;
    }
};

//------------------------------------------------------------------------------------

class FuncDecl: public Node{
	protected:
		std::string type;
		std::string id;
		NodePtr arg;		//needs fixing later, but atm assume no arg
        NodePtr body;
	public:
		FuncDecl(std::string type_in, std::string id_in, NodePtr arg_in, NodePtr body_in): type(type_in), id(id_in), arg(arg_in), body(body_in){}
    ~FuncDecl(){
        delete arg;
        delete body;
    }
    virtual void print(std::ostream &dst) const{
        dst << "def " << id << "():" << std::endl;
        body->print(dst);
    }
};

//------------------------------------------------------------------------------------


//class Expression : public Node{
//	public:
//    ~Expression(){
//    }
//    virtual void print(std::ostream &dst) const{
//        dst << "--not implemented--" << std::endl;
//    }
//
//};

//------------------------------------------------------------------------------------

class ArithExpr : public Node{
	protected:
    NodePtr left;
    NodePtr right;
		std::string* arith_op;
	public:
		ArithExpr(NodePtr left_in, std::string* arith_op_in, NodePtr right_in) : left(left_in), arith_op(arith_op_in), right(right_in){}
    ~ArithExpr(){
        delete left;
        delete right;
    }
//    std::string getop(){
//        return arith_op;
//    }
    virtual void print(std::ostream &dst) const override{
//        left->print(dst);
//        dst << getop();
//        right->print(dst);
    }
};

//------------------------------------------------------------------------------------

class ComprExpr : public Node{
	protected:
    NodePtr left;
    NodePtr right;
		std::string compr_op;
	public:
		ComprExpr(NodePtr left_in, std::string compr_op_in, NodePtr right_in): left(left_in), compr_op(compr_op_in), right(right_in){}
    ~ComprExpr(){
        delete left;
        delete right;
    }
    std::string getop(){
        return compr_op;
    }
    virtual void print(std::ostream &dst) const{}
    
};
//------------------------------------------------------------------------------------

class NumExpr : public Node{
	protected:
		double val;
	public:
		NumExpr(double val_in) : val(val_in) {}
    ~NumExpr(){}
    void print(std::ostream &dst) const{
        dst << val;
    }
};

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

class Statement : public Node{
	protected:
	public:
    virtual ~Statement(){}
    virtual void print(std::ostream &dst) const = 0;
};

//------------------------------------------------------------------------------------

class StatementSeq : public Statement{
	protected:
		Statement* list;
		Statement* stat;
	public:
    StatementSeq(Statement* list_in, Statement* stat_in) : list(list_in), stat(stat_in){}
    virtual ~StatementSeq(){
        delete list;
        delete stat;
    }

    virtual void print(std::ostream &dst) const{
        stat->print(dst);
        list->print(dst);
    }
};

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

class SimpStat : public Node{
	protected:
	public:
    SimpStat(){}
    ~SimpStat(){}
    virtual void print(std::ostream &dst) const{}
};

//------------------------------------------------------------------------------------

class ReturnStat : public Node{
	protected:
		ArithExpr* expr;
	public:
		ReturnStat(ArithExpr* expr_in): expr(expr_in){}
    ~ReturnStat(){
        delete expr;
    }
    virtual void print(std::ostream &dst) const override{
        dst << "return ";
        expr->print(dst);
    }

};

//------------------------------------------------------------------------------------

class AssignStat : public Node{
	protected:
		std::string id;
		ArithExpr* expr;
	public:
    AssignStat(std::string id_in, ArithExpr* expr_in): id(id_in), expr(expr_in){}
		~AssignStat();
    void print(std::ostream &dst) const override{
        dst << id << " = ";
        expr->print(dst);
    }
};
//A= a+5
//------------------------------------------------------------------------------------

//class AssertStat : public SimpStat{
//
//
//
//
//Need to do assert statement
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//
class CompStat : public Node{
	protected:
	public:
		CompStat();
		~CompStat();
    virtual void print(std::ostream &dst) const override{
        dst << "--not implemented--" << std::endl;
    }
};
//------------------------------------------------------------------------------------

class IfElStat : public Node{
	protected:
	public:
    IfElStat(){}
    ~IfElStat(){}
    virtual void print(std::ostream &dst) const override{}
};

//------------------------------------------------------------------------------------

class ForStat : public Node{
	protected:
	public:
    ForStat(){}
    ~ForStat(){}
    virtual void print(std::ostream &dst) const override{}
};

//------------------------------------------------------------------------------------

class WhileStat : public Node{
	protected:
	public:
		WhileStat();
		~WhileStat();
    virtual void print(std::ostream &dst) const override;
};

//------------------------------------------------------------------------------------


#endif
