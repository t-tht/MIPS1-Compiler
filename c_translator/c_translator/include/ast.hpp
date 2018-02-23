#ifndef ast_hpp
#define ast_hpp


extern const Expression *parseAST();


// ---------------------------------NODE---------------------------------

typedef const Node* NodePtr;

class Node
{
public:
    virtual ~Node()
    {}

    //! Tell and expression to print itself to the given stream
    virtual void print(std::ostream &dst) const =0;

	/*
    //! Evaluate the tree using the given mapping of variables to numbers
    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
	*/
};
// ---------------------------------PROGRAM---------------------------------

// ---------------------------------FUNCTION---------------------------------
class FunctionDec : public Node {
	private:
		const std::string *type;
		const std::string *id;
		//int parameter;
		StatementPtr body;
	public:
		
		FunctionDec(const std::string *type, const std::string *id, StatementPtr body);
		~FunctionDec();
		
		void print() const override;
}
FunctionDec::FunctionDec(const std::string *type, const std::string *id, StatementPtr body){}
FunctionDec::~FunctionDec(){}
// ---------------------------------EXPRESSION---------------------------------

// ---------------------------------STATEMENT---------------------------------


#endif
