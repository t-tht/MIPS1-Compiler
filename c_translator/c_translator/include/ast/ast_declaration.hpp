class Declaration : public node{
	protected:
	public:
		Declaration();
		~Declaration();
		virtual void print(std::ostream &dst) const = 0;
};

class VarDec : public Declaration{
	protected:
		std::string* id;
		double val;
	public:
		VarDec(std::string* id_in, double val_in);
		~VarDec();
		void print(std::ostream &dst) const override;
};

class FuncDec: public Declaration{
	protected:
		std::string *return_t;
		std::string *id;
		Statement* arg_in;
		Statement* bodyl
	public:
		FuncDec(std::string *return_t_in, std::string *id_in, Statement* arg_in, Statement* body_in);
		~FuncDec():
		void print(std::ostream &dst) const override;
};
