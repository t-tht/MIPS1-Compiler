#ifndef param_var_hpp
#define param_var_hpp

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
		void print(std::ostream &dst) const override{
			dst << *type << " " << *id;
		};
};

#endif