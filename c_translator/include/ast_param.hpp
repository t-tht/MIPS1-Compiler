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
<<<<<<< HEAD
		void compile(std::ostream &dst)const override{};
=======
		void print(std::ostream &dst)const override{
			dst<< *type << " " << *ident;
			if(right != NULL){
				dst << ",";
				right->print(dst);
			}
			
		};
>>>>>>> 379cf3f1576e8485ea768c8799a099d6c4a50a20
};

#endif
