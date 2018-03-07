#ifndef context_hpp
#define context_hpp

#include <string>

struct Context{
		int indentlvl = 0;
}

void insertindent(const Context ilvl, std::ostream &dst)const{
	for(int i = 0; i < ilvl; i++){
		dst << "/t";
	}
}

#define