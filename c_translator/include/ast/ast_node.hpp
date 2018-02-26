#ifndef node_hpp
#define node_hpp

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

class Node{
	private:
	public:
		Node(Node* left_in, Node* right_in);
		~Node();
		virtual void print(std::ostream &dst) const =0;
};

//------------------------------------------------------------------------------------

class Block{};

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
		Node* arg_in;
        Block* bodyl;
	public:
		FuncDecl(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in);
		~FuncDecl():
		void print(std::ostream &dst) const override;
};

//------------------------------------------------------------------------------------


class Expression : public Node{
	protected:
		Expression* left;
		Expression* right;
	public:
		Expr();
		~Expr();
		virtual void print(std::ostream &dst) const = 0;
};

//------------------------------------------------------------------------------------

class ArithExpr : public Expression{
	protected:
		std::string arith_op;
	public:
		ArithExpr(Expression* left_in, std::string bin_op_in, Expression* right_in);
		~ArithExpr();
		std::string getop();
		void print(std::ostream &dst) const;
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


class ComprExpr : public Expression{
	protected:
		std::string compr_op;
	public:
		ComprExpr(Expression* left_in, std::string compr_op_in, Expression* right_in);
		~ComprExpr();
		void print(std::ostream &dst) const;
};

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
