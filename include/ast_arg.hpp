#ifndef ast_arg_hpp
#define ast_arg_hpp

#include "ast.hpp"

class Arg;

class Arg : public Node{
protected:
    std::string* type;
    std::string* id;
    double Number;
    NodePtr right;
public:
    Arg(std::string* _type, std::string* _id, NodePtr _right ) : type(_type), id(_id), right(_right){};
    Arg(double _Number ) : Number(_Number){};
    Arg(double _Number, NodePtr _right) : Number(_Number), right(_right){};
    double val;
    NodePtr right;
public:
    ~Arg(){
        delete right;
    };
    void translate(std::ostream &dst) const override{
        if(type != NULL){
            dst<< *type;
        }
        if(id!=NULL){
            dst<< *id;
            
        }
        else{
            dst<< Number;
            
        }
        if(right !=NULL){
            dst<< ",";
            right->translate(dst);
        }
        
    };
    void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
        if(destloc < 8){
            if(id != NULL){
                dst << "\tlw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
            }else{
                dst << "\tli\t\t$" << destloc << ", " << Number << std::endl;
            }
            destloc++;
            if(right != NULL){
                right->compile(dst, cntx, destloc);
            }
        }else if(destloc > 7){
            if(id != NULL){
                dst << "\tlw\t\t$" << 2 << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
            }else{
                dst << "\tli\t\t$" << 2 << ", " << Number << std::endl;
            }
            dst << "\tsw\t\t$" << 2 << ", " << (destloc-8)*4 + 16 << "($sp)" << std::endl;
            destloc++;
            if(right != NULL){
                right->compile(dst, cntx, destloc);
            }
        }
    };

    unsigned int GetContext(InterpretContext &cntx)const override{};
};

#endif
