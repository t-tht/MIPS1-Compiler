#ifndef ast_assignment_hpp
#define ast_assignment_hpp

#include "ast.hpp"

class AssignmentStatement;

class AssignmentStatement: public Node{
protected:
    std::string* type;
    std::string* id;
    NodePtr Expr;
public:
    AssignmentStatement(std::string* _type, std::string* _id, NodePtr _Expr): type(_type), id(_id), Expr(_Expr){};
    ~AssignmentStatement(){};
    void translate(std::ostream &dst) const override{
        for(int i=0; i<tab; i++){
            dst<< "\t";
        }
        dst<< *id;
        if(Expr != NULL){
            dst << "=";
            Expr ->translate(dst);
        }
        else{
            dst<<"=0";
        }
        dst<< std::endl;

    };
    void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{
        // dst << "#assignment -- start" << std::endl;
        if(cntx.IsAGlobal(*id)){
            dst << "\tlui\t\t$" << destloc << ", %hi(" << *id << ")" << std::endl;
            cntx.RegSetUsed(destloc);
            std::vector<unsigned int> temp = cntx.AvailableReg();
            cntx.RegSetUsed(temp[0]);
            if(Expr != NULL){
                Expr->compile(dst, cntx, temp[0]);
            }
            cntx.RegSetAvailable(temp[0]);
            dst << "\tsw\t\t$" << temp[0] << ", %lo(" << *id << ")($" << destloc << ")" << std::endl;
            cntx.RegSetAvailable(destloc);
        }else if(cntx.IsAVariable(*id)){
            if(Expr != NULL){
                Expr->compile(dst, cntx, destloc);
            }
            dst << "\tsw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
        }
        // dst << "#assignment -- end" << std::endl;
    };

    unsigned int GetContext(InterpretContext &cntx) const override{
        unsigned int exprv = Expr->GetContext(cntx);
        cntx.UpdateVariable(*id,exprv);
        return 0;
    };
};

#endif
