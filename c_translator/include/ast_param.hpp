#ifndef ast_param_hpp
#define	ast_param_hpp

class Param;

class Param : public Node{
	protected:
		std::string* type;
    std::string* ident;
		NodePtr right;
	public:
    Param(std::string* _type, std::string* _ident, NodePtr _right ) : type(_type), ident(_ident), right(_right){};
		~Param(){
			delete right;
		};
		void translate(std::ostream &dst)const override{
            dst<< *type << " " << *ident;
			if(right != NULL){
				dst << ",";
				right->translate(dst);
			}
			
		};
		void print(std::ostream &dst)const override{};
};

#endif
