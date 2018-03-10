#ifndef ast_primative_hpp
#define ast_primative_hpp

class Number;
class Variable;

class Number : public Node{
	private:
		double value;
	public:
		Number(double _value) : value(_value){};
		~Number(){};
		virtual void translate(std::ostream &dst)const override{
			dst << value;
		};
		virtual void compile(std::ostream &dst)const override{
			dst << value;
		};
};

class Variable : public Node{
	private:
		std::string* id;
	public:
    Variable(std::string* _id) : id(_id){};
		~Variable(){};
		virtual void translate(std::ostream &dst)const override{
			dst << *id;
		};
		virtual void compile(std::ostream &dst)const override{
			dst << *id;
		};
};

#endif
