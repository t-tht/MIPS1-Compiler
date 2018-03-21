#ifndef ast_interpretcontext_hpp
#define ast_interpretcontext_hpp

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>

class InterpretContext;

/*
 Convention
 |Name    | Reg# |      Usage          |Preserved on call?
 |$zero   | 0    |the constant value 0 |n.a.
 |$v0-$v1 | 2-3  |values for results   |no
 |$a0-$a3 | 4-7  |arguments            |yes
 |$t0-$t7 | 8-15 |temporaries          |no
 |$s0-$s7 | 16-23|saved                |yes
 |$t8-$t9 | 24-25|more temporaries     |no
 26-27 don't use
 |$gp     | 28   |global pointer       |yes
 |$sp     | 29   |stack pointer        |yes
 |$fp     | 30   |frame pointer        |yes
 |$ra     | 31   |return address       |yes
 */

class InterpretContext{
public:
    unsigned int sp;
    unsigned int scopelevel;
    unsigned int functionlevel;
    unsigned int frame_size;
    unsigned int arg_no;
    unsigned int var_no;
    unsigned int param_no;

    bool regs[32];       //free registers, 0 = free; 1 = occupied

    std::unordered_map<std::string, unsigned int> VariableBindings;
    std::unordered_map<std::string, unsigned int> DynamicBindings;
    std::unordered_map<std::string, unsigned int> globalbindings;
    std::unordered_map<unsigned int, unsigned int> Stack;

    InterpretContext(){
        for(int i = 0; i < 32; i++){
            regs[i] = false;
        }
        for(int i = 0; i < 8; i++){
            regs[i]= true;
        }
        for(int i = 26; i < 32; i++){
            regs[i]= true;
        }
        sp = 0;
        scopelevel = 0;
        functionlevel = 0;
        frame_size = 0;
        arg_no = 0;
        var_no = 0;
        param_no = 0;
    };
    InterpretContext(InterpretContext* cntx){
        for(int i= 0; i< 32; i++){
            regs[i]= cntx->regs[i];
        }
        sp = cntx->sp;
        frame_size= cntx-> frame_size;
        arg_no= cntx-> arg_no;
        var_no= cntx->var_no;
        param_no= cntx->param_no;
    };

    ~InterpretContext(){};

    std::vector<unsigned int> freesavedregs(){        //returns free saved registers (16-23)
        std::vector<unsigned int> temp;
        for(int i = 16; i < 24; i++){
            if(regs[i] == 0){
                temp.push_back(i);
            }
        }
        if(temp.size() != 0){
            return temp;
        }
        else{
            //no free reg
            exit(1);
        }
    };
    std::vector<unsigned int> freetempregs(){       //returns free temp registers (8-15)
        std::vector<unsigned int> temp;
        for(int i = 8; i < 16; i++){
            if(regs[i] == 0){
                temp.push_back(i);
            }
        }
        if(temp.size() != 0){
            return temp;
        }
        else{
            //no free reg
            std::cout << " no free reg" << std::endl;
        }
    };

    unsigned int fpSizeGet(){return frame_size;};
    void fpSizeCalc(){
        frame_size += 1; //frame pointer
        frame_size += 1; //global pointer
        frame_size += 1; //sp
        frame_size += 1; //ra
        frame_size += arg_no;
        frame_size += param_no;
        frame_size += var_no;

        if(frame_size % 2 != 0){
            frame_size++;
        }
        frame_size *= 4;
    };

void AddToStack(unsigned int id){
    Stack.emplace(std::make_pair(id,sp));
    spIncrement();
};
unsigned int FindOnStack(unsigned int id){
    auto search = Stack.find(id);
    if(search != Stack.end()){
        return search->second;
    }
    else{
        return -1;
    }
};

    void spIncrement(){sp += 4;};
    void spSet(int i){sp = i;};
    unsigned int spGet()const{return sp;};
    void scopeIncrement(){scopelevel++;};
    void scopeDecrement(){scopelevel--;};
    unsigned int scopeGet()const{return scopelevel;};
    void functionLevelIncrement(){functionlevel++;}
    void functionLevelDecrement(){functionlevel--;};
    unsigned int functionLevelGet(){return functionlevel;};
    void regsetused(unsigned int i){regs[i] = 1;};

    void addvar(const std::string* name){};

};

#endif
