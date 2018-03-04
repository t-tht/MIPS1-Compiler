#ifndef ast_program_hpp
#define ast_program_hpp

class Program;

class Program : public Node{
	protected:
		NodePtr left;
		NodePtr right;
	public:
		Program(const NodePtr _left, const NodePtr _right) : left(_left), right(_right){};
		~Program(){
			delete left;
			delete right;
		};
		void translate(std::ostream &dst) const override{
			if(left != NULL){
				left->translate(dst);
			}
			if(right != NULL){
				right->translate(dst);
			}
		};
		void print(std::ostream &dst) const override{
			if(left != NULL){
				left->print(dst);
			}else if(right != NULL){
				right->print(dst);
			}
		};
};

#endif