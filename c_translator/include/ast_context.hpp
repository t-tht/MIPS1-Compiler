#ifndef ast_context_hpp
#define ast_context_hpp

#include <string>
#include <sstream>

class Context;

class Context{
private:
	int indentlevel = 0;
public:
	Context(){};
	~Context(){};

	int indentlevelget()const{
		return indentlevel;
	};
	void indentlevelset(int i){
		indentlevel = i;
	};

	std::string indent()const{
		std::stringstream ss;
		for(int i = 0; i < indentlevel; i++){
			ss << "\t";
		}
		return ss.str();
	};
};

#endif
