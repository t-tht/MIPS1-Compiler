#ifndef param_var_hpp
#define param_var_hpp

class ParamVar;

class ParamVar : public Node{
	protected:
	public:
		~ParamVar(){};
		void translate(std::ostream &dst) const override{
			dst << *type << " " << *id;
		};
		void print(std::ostream &dst) const override{
			dst << *type << " " << *id;
		};
};

#endif