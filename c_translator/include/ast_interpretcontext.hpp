#ifndef ast_interpretcontext_hpp
#define ast_interpretcontext_hpp

#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include "ast_global.hpp"

typedef const InterpretContext *InterpretContextPtr;

class InterpretContext;

class InterpretContext{
public:
	unsigned int sp;
	unsigned int frame_size;

	int argno;
	int paramno;

	bool reg[32];	//check if register is free or occupied

	std::unordered_map<std::string, unsigned int> variablebindings;
	//TODO INCLUDE DYNAMIC BINDINGS IF NEEDED
	std::unordered_map<std::string, unsigned int> globalbindings;

	InterpretContext(){
		for(int i = 0; i < 32; i++){
			reg[i] = false;
		}
		sp = 0;
		frame_size = 0;
		argno = 0;
		paramno = 4;
	};
	~InterpretContext(){};

	void regsetfree(){};
	void regsetused(){};

	void addvar(const std::string* name){};




};

#endif
