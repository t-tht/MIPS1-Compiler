#ifndef ast_assignmentstatement_hpp
#define	ast_assignmentstatement_hpp

class AssignmentStatement;

class AssignmentStatement : public Node{
	protected:
		std::string* type;
		std::string* id;
		const NodePtr Expr;
	public:
		Assignment(std::string* _type, std::string* _id, const NodePtr _Expr) : type(_type), id(_id), Expr(_Expr){};
		~Assignment(){
			delete Expr;
		};
		void translate(std::ostream &dst)const override{
			if(type != NULL){
				dst << *type;
			}
			dst << *id << " = ";
			Expr->translate(dst);
		};
		void print(std::ostream &dst)const override(){
			if(type != NULL){
				dst << *type;
			}
			dst << *id << " = ";
			Expr->translate(dst);
			dst << ";" << std::endl;
		};
};


#endif