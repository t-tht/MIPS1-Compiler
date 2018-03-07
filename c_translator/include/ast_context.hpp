#ifndef context_hpp
#define context_hpp

#include <string>
#include <sstream>

class Context;

class Context{
private:
	int indentlevel = 0;
public:
	std::string indent()const{
		std::sstream ss;
		for(int i = 0; i < indentlevel; i++){
			ss << "\t";
		}
		return ss.str();
	};
};

#define
