#ifndef ast_node_hpp
#define ast_node_hpp

#include<string>
#include<iostream>

class Node;

typedef const Node *NodePtr;

class Node{
	public:
		virtual ~Node(){};
		virtual void translate(std::ostream &dst) const =0;
		virtual void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const =0;
};

#endif
