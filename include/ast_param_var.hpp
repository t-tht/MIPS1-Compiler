#ifndef param_var_hpp
#define param_var_hpp

#include "ast.hpp"

class ParamVar;

class ParamVar : public Node{
	protected:
		std::string* type;
		std::string* id;
	public:
		ParamVar(std::string* _type, std::string* _id) : type(_type), id(_id){};
		~ParamVar(){};
		void translate(std::ostream &dst) const override{
			dst << *type << " " << *id;
		};
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{
			dst << "param var compile function not yet implemented" << std::endl;
		};
		unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
