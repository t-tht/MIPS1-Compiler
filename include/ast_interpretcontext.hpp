#ifndef ast_interpretcontext_hpp
#define ast_interpretcontext_hpp

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>

class InterpretContext;

class InterpretContext{

public:

    InterpretContext(){
        for(int i = 0; i < 32; i++){
            reg[i] = 0;
        }
        reg[30] = 1;
        sp = 0;
        spOffset = 116;
        scopelevel = 0;
        functionlevel = 0;
        frame_size = 128;
        arg_no = 0;
        var_no = 0;
        param_no = 0;
    };
    InterpretContext(InterpretContext &cntx){
        for(int i = 0; i < 32; i++){
            reg[i] = cntx.reg[i];
        }
    }
    ~InterpretContext(){};

    unsigned int sp;
    unsigned int spOffset;
    unsigned int scopelevel;
    unsigned int functionlevel;
    unsigned int frame_size;
    unsigned int arg_no;
    unsigned int param_no;
    unsigned int var_no;
    bool reg[32];       //free registers, 0 = free; 1 = occupied

    /*printing functions*/
    void PrintReg(std::ostream& dst)const{
        dst << "#Occupied Registers" << std::endl;
        for(int i = 0; i < 32; i++){
            dst << "#" << i << ": ";
            if(reg[i] == 1){
                dst<< "yes" << std::endl;
            }else{
                dst << std::endl;
            }
        }
    }
    /*getter functions*/

    /*setter functions*/
    void RegSetUsed(unsigned int i){
        if(i < 32){
            reg[i] = 1;
        }
    };

    void RegSetAvailable(unsigned int i){
        if(i < 32){
            reg[i] = 0;
        }
    };
    /*incrementing & decrementing functions*/

    std::vector<unsigned int> AvailableDestReg(){  //returns either 2 or 3 for destreg
        std::vector<unsigned int> temp;
        for(int i = 2; i < 4; i++){
            if(!reg[i]){
                temp.push_back(i);
            }
        }
        return temp;
    }

    std::vector<unsigned int> AvailableArgReg(){       //returns free temp registers (8-15)
        std::vector<unsigned int> temp;
        for(int i = 4; i < 8; i++){
            if(reg[i] == 0){
                temp.push_back(i);
            }
        }
        return temp;
    };
    void StackUpdate(){
        if(param_no){
            for(unsigned int i = 4; i < param_no+4; i++){
                RegSetUsed(i);
            }
        }
    }

    std::vector<unsigned int> AvailableTempReg(){       //returns free temp registers (8-15)
        std::vector<unsigned int> temp;
        for(int i = 8; i < 16; i++){
            if(reg[i] == 0){
                temp.push_back(i);
            }
        }
        return temp;
    };

    std::vector<unsigned int> AvailableSavedReg(){        //returns free saved registers (16-23)
        std::vector<unsigned int> temp;
        for(int i = 16; i < 24; i++){
            if(reg[i] == 0){
                temp.push_back(i);
            }
        }
        return temp;
    };


    std::unordered_map<std::string, unsigned int> VariableBindings;
    std::unordered_map<std::string, unsigned int> GlobalBindings;
    std::unordered_map<std::string, unsigned int> Stack;
    std::unordered_map<std::string, unsigned int> PassedArg;

    void AddVariable(std::string id, unsigned int val){
        if(FindVariable(id)){
        }else{
            VariableBindings.emplace(std::make_pair(id,val));
        }
    };

    unsigned int FindVariable(std::string id){    //returns variable value
        auto search = VariableBindings.find(id);
        if(search != VariableBindings.end()){
            return search->second;
        }else{
            return -1;
        }
    };
    void UpdateVariable(std::string id, unsigned int val){
        auto search = VariableBindings.find(id);
        if(search != VariableBindings.end()){
            search->second = val;
        }
    };

    void AddGlobal(std::string id, unsigned int val){
        GlobalBindings.emplace(std::make_pair(id,val));
    };
    unsigned int FindGlobal(std::string id){
        auto search = GlobalBindings.find(id);
        if(search != GlobalBindings.end()){
            return search->second;
        }else{
            return -1;
        }
    };

    void AddToStack(std::string id){
        Stack.emplace(std::make_pair(id,spOffset));
        spOffset -= 4;
    };

    void AddToStack(std::string id, int _offset){
        Stack.emplace(std::make_pair(id,_offset));
    };

    unsigned int FindOnStack(std::string id){
        auto search = Stack.find(id);
        if(search != Stack.end()){
            return search->second;
        }
        else{
            return -1;
        }
    };

    unsigned int fpSizeGet(){return frame_size;};
    // void fpSizeCalc(){frame_size = 128;};
    //void fpReset(){frame_pointer = 0;};

    void spIncrement(){sp += 4;};
    void spDecrement(){sp -= 4;};
    void spSet(int i){sp = i;};

    void ArgNoIncrement(){arg_no++;};
    void ArgNoDecrement(){arg_no--;};
    unsigned int GetArgNo(){return arg_no;};
    void ResetArgNo(){arg_no = 0;};

    void ParamNoIncrement(){param_no++;};
    void ParamNoDecrement(){param_no--;};
    unsigned int GetParamNo(){return param_no;};
    void ResetParamNo(){param_no = 0;};

    void scopeIncrement(){scopelevel++;};
    void scopeDecrement(){scopelevel--;};
    unsigned int scopeGet()const{return scopelevel;};

    void functionLevelIncrement(){functionlevel++;}
    void functionLevelDecrement(){functionlevel--;};
    unsigned int functionLevelGet(){return functionlevel;};

    /*Printing functions*/
    void AllocateStack(std::ostream &dst){
        unsigned int size = frame_size;
        dst << "#allocate stack" << std::endl;
        dst << "\taddiu\t$sp, $sp, -" << size+sp << std::endl;
        dst << "\tsw\t\t$ra, " << size+sp-4 << "($sp)" << std::endl;
        dst << "\tsw\t\t$fp, " << size+sp-8 << "($sp)" << std::endl;
        dst << "\tmove\t$fp, $sp" << std::endl << std::endl;
        spSet(size);
        //fpReset();
    }
    void DeallocateStack(std::ostream &dst){
        dst << "#deallocating stack" << std::endl;
        dst << "\tmove\t$sp, $fp" << std::endl;
        dst << "\tlw\t\t$fp, " << sp-8 << "($sp)" << std::endl;
        dst << "\tlw\t\t$ra, " << sp-4 << "($sp)" << std::endl;
        dst << "\taddiu\t$sp, $sp, " << sp << std::endl;
        //fpReset();
    }

};

#endif
