#ifndef ast_vardec_hpp
#define ast_vardec_hpp

#include<string>
#include<iostream>
#include<ast.hpp>

class VarDec;

class VarDec: public Node{
	protected:
		std::string* type;
		std::string* id;
        NodePtr Expr;
	public:
		VarDec(std::string* _type, std::string* _id, NodePtr _Expr): type(_type), id(_id), Expr(_Expr){}
        ~VarDec(){
		}
		void translate(std::ostream &dst) const override{
            dst << *type << " "<< *id;
			if(Expr != NULL){
				dst << " = ";
				Expr ->translate(dst);
			}
            
		}
<<<<<<< HEAD
		void compile(std::ostream &dst) const {
			dst << "compile not implemented yet" <<std::endl;
=======
		void print(std::ostream &dst) const override{
			dst << "print not implemented yet" <<std::endl;
>>>>>>> 379cf3f1576e8485ea768c8799a099d6c4a50a20
            dst << *type << " "<< *id << std::endl;
            if(Expr != NULL){
                Expr ->compile(dst);
            }
		} 
};

#endif
