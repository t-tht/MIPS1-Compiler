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
    unsigned int stack_pointer;
    unsigned int frame_point;
    unsigned int frame_size;

    int argument_no;
    int variable_no;
    int param_no;

    bool regs[32];       //free registers, 0 = free; 1 = occupied

    std::unordered_map<std::string, unsigned int> VariableBindings;
    std::unordered_map<std::string, unsigned int> DynamicBindings;
    std::unordered_map<std::string, unsigned int> globalbindings;

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
            exit(1);
        }
    };
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
    };
    InterpretContext(InterpretContext* cntx){
        for(int i= 0; i< 32; i++){
            regs[i]= cntx->regs[i];
        }
        stack_pointer = cntx->stack_pointer;
        frame_point= cntx->frame_point;
        frame_size= cntx-> frame_size;

        argument_no= cntx-> argument_no;
        variable_no= cntx->variable_no;
        param_no= cntx->param_no;
    };

    ~InterpretContext(){};

    void regsetused(unsigned int i){
        regs[i] = 1;
    };

    void addvar(const std::string* name){};

};

#endif
