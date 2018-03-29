#ifndef ast_incrementdecrement_hpp
#define ast_incrementdecrement_hpp

#include "ast.hpp"

class IncrementDecrement;

class IncrementDecrement : public Node{
protected:
    std::string* prefix;
    std::string* sign;
    std::string* id;
public:
    IncrementDecrement(std::string* _prefix, std::string* _sign, std::string* _id) : prefix(_prefix), sign(_sign), id(_id){};
    ~IncrementDecrement(){
        delete prefix;
        delete sign;
        delete id;
    };
    void translate(std::ostream &dst) const override{
        if(*prefix == "pre"){

            if(*sign == "+"){
                if(id != NULL){
                    dst << "++" << *id << std::endl;
                }
            }else if(*sign == "-"){
                if(id != NULL){
                    dst << "--" << *id << std::endl;
                }
            }else{
                dst << "#increment decrement error" << std::endl;
            }

        }else if(*prefix == "post"){
            if(*sign == "+"){
                if(id != NULL){
                    dst << *id << "++" << std::endl;
                }
            }else if(*sign == "-"){
                if(id != NULL){
                    dst << *id << "--" << std::endl;
                }
            }else{
                dst << "#increment decrement error" << std::endl;
            }
        }else{
            dst << "#increment decrement error" << std::endl;
        }
    };
    void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{
        std::vector<unsigned int> temp = cntx.AvailableReg();
        cntx.RegSetUsed(temp[0]);
        if(*prefix == "pre"){

            if(*sign == "+"){
                if(id != NULL){
                    dst << "\tlw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                    dst << "\taddiu\t$" << destloc << ", $" << destloc << ", 1" << std::endl;
                    dst << "\tsw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                    dst << "\tlw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                }
            }else if(*sign == "-"){
                if(id != NULL){
                    dst << "\tlw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                    dst << "\taddiu\t$" << destloc << ", $" << destloc << ", -1" << std::endl;
                    dst << "\tsw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                    dst << "\tlw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                }
            }else{
                dst << "#increment decrement error" << std::endl;
            }

        }else if(*prefix == "post"){
            if(*sign == "+"){
                if(id != NULL){
                    dst << "\tlw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                    dst << "\taddiu\t$" << temp[0] << ", $" << destloc << ", 1" << std::endl;
                    dst << "\tsw\t\t$" << temp[0] << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                }
            }else if(*sign == "-"){
                if(id != NULL){
                    dst << "\tlw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                    dst << "\taddiu\t$" << temp[0] << ", $" << destloc << ", -1" << std::endl;
                    dst << "\tsw\t\t$" << temp[0] << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
                }
            }else{
                dst << "#increment decrement error" << std::endl;
            }
        }else{
            dst << "#increment decrement error" << std::endl;
        }
        cntx.RegSetAvailable(temp[0]);
    };
    unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
