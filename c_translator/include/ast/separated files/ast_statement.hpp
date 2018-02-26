#ifndef "STATEMENT_HPP"
#define "STATEMENT_HPP"

class Statement;

class Statement{
	protected:
	public:
	Statement();
	~Statement();
	virtual void print(std::ostream &dst) = 0;
};

#endif