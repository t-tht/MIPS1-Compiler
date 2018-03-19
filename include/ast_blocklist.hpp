#ifndef ast_blocklist_hpp
#define ast_blocklist_hpp

#include "ast.hpp"

class Blocklist;

class Blocklist : public Node{
    private:
    std::vector<NodePtr* > Statements;
	public:
    Blocklist(){};
		~Blocklist(){

		};
    int getcount(std::ostream &dst)const override{
            return Statements.size();
		};
    void Blocklist::incrementcount(NodePtr* Node){
        Blocklist.push_back(Node);
    };
};

#endif
