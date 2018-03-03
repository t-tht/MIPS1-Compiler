#ifndef ast_funcdecl_hpp
#define ast_funcdecl_hpp

class FuncDecl;

class FuncDecl: public Node{
	protected:
		std::string* type;
		std::string* id;
		NodePtr arg;		//needs fixing later, but atm assume no arg
        NodePtr block;
	public:
		FuncDecl(std::string _type, std::string _id, NodePtr _arg, NodePtr _block): type(_type), id(_id), arg(_arg), body(_body){}
		~FuncDecl(){
			delete arg;
			delete block;
		}
		virtual void translate(std::ostream &dst) const override{
			dst << "def " << id << "():" << std::endl;
			arg->translate(dst);
			block->translate(dst);
		}
		virtual void translate(std::ostream &dst) const override{
			dst << "print not implemented yet" <<std::endl;
			arg->print(dst);
			block->print(dst);
		}
};

#endif