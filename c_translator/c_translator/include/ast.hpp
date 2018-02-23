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
		
		FunctionDec(const std::string *type_in, const std::string *id_in, StatementPtr body_in);
		~FunctionDec();
		
		void print() const override;
}

FunctionDec::FunctionDec(const std::string *type_in, const std::string *id_in, StatementPtr body_in):type(type_in),id(id_in),body(body_in){}
FunctionDec::~FunctionDec(){}

// ---------------------------------EXPRESSION---------------------------------

// ---------------------------------STATEMENT---------------------------------


#endif
