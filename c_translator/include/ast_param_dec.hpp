#ifndef ast_param_dec_hpp
#define	ast_param_dec_hpp

class ParamDec;

class ParamDec : public Program{
	protected:
		NodePtr left;
		double num;
	public:
		ParamDec(const NodePtr left, double _num) : left(_left) num(_num){};
		~ParamDec(){};
		void translate(std::ostream &dst)const override{
			if(left != NULL){
				left->print(dst);
			}
			dst << ", " << num
		};
		void print(std::ostream &dst)const override{};
};

#endif