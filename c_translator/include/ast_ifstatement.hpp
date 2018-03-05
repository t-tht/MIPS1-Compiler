#ifndef ast_ifstatement_hpp
#define ast_ifstatement_hpp

class IfStatement;

class IfStatement : public Node{
	protected:
		const NodePtr cond;
		const NodePtr body;
	public:
		IfStatement(const NodePtr _cond, const NodePtr _body) : cond(_cond), body(_body){};
		~IfStatement(){
			delete cond;
			delete body;
		};
		void translate(std::ostream &dst)const override{
			dst << "if(";
			if(cond != NULL){
				cond->translate(dst);
			}
			dst << "):" << std::endl;
			if(body != NULL){
				body->translate(dst);
			}
		};
		void print(std::ostream &dst)const override{};
};

#endif
