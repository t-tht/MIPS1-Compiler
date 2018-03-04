#ifndef ast_vardec_hpp
#define ast_vardec_hpp

#include<string>
#include<iostream>
#include<ast.hpp>

class VarDec;

class VarDec: public Node{
	private:
		std::string* type;
		std::string* id;
        NodePtr Expr;
	public:
		VarDec(std::string* _type, std::string* _id, NodePtr _Expr): type(_type), id(_id), Expr(_Expr){}
		~VarDec(){
            delete Expr;
		}
		void translate(std::ostream &dst) const{
            dst << *type << " "<< *id << std::endl;
//			if(Expr != NULL){
//				Expr ->translate(dst);
//			}
            
		}
		void print(std::ostream &dst) const {
			dst << "print not implemented yet" <<std::endl;
            dst << *type << " "<< *id << std::endl;
            if(Expr != NULL){
                Expr ->print(dst);
            }
		}
};

#endif