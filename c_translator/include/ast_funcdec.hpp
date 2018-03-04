#ifndef ast_funcdecl_hpp
#define ast_funcdecl_hpp

#include<string>
#include<iostream>

class FuncDecl;

class FuncDecl: public Node{
	protected:
		std::string* type;
		std::string* id;
		NodePtr param;
        NodePtr block;
	public:
		FuncDecl(std::string* _type, std::string* _id, NodePtr _param, NodePtr _block): type(_type), id(_id), param(_param), block(_block){}
		~FuncDecl(){
			delete param;
			delete block;
		}
		void translate(std::ostream &dst) const{
			dst << "def " << *id << "(";
			if(param != NULL){
				param->translate(dst);
			}
			dst << "):" << std::endl;
			block->translate(dst);
		}
		void print(std::ostream &dst) const {
			dst << "print not implemented yet" <<std::endl;
			if(param != NULL){
				param->print(dst);
			}
			block->print(dst);
		}
};

#endif
