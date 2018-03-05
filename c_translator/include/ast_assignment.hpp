#ifndef ast_assignment_hpp
#define ast_assignment_hpp

#include<string>
#include<iostream>
#include<ast.hpp>

class AssignmentStatement;

class AssignmentStatement: public Node{
protected:
    std::string* type;
    std::string* id;
    NodePtr Expr;
public:
    AssignmentStatement(std::string* _type, std::string* _id, NodePtr _Expr): type(_type), id(_id), Expr(_Expr){}
    ~AssignmentStatement(){
    }
    void translate(std::ostream &dst) const{
        if(type != NULL){
            dst << *type;
        }
        dst<< " "<< *id;
        if(Expr != NULL){
            dst << " = ";
            Expr ->translate(dst);
        }
        
    }
    void print(std::ostream &dst) const {
        dst << "print not implemented yet" <<std::endl;
        dst << *type << " "<< *id << std::endl;
        if(Expr != NULL){
            Expr ->print(dst);
        }
    }
};

#endif
