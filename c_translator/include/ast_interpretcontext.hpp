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
    
    //REGISTER METHODS
    //Declaring Registers
    bool reg[32];

    //Generating free registers
    InterpretContext(){
        for(int i = 0; i < 32; i++){
            reg[i] = false;
        }
        for(int i = 0; i < 8; i++){
            reg[i]= true;
        }
        for(int i = 26; i < 32; i++){
            reg[i]= true;
        }



    };



    //Declaring Binding Map
    std::unordered_map<std::string, unsigned int> VariableBindings;
    std::unordered_map<std::string, unsigned int> DynamicBindings;
    //TODO INCLUDE DYNAMIC BINDINGS IF NEEDED
    //std::unordered_map<std::string, unsigned int> globalbindings

    //Create function to insert a binding on the stack
    //
    InterpretContext(InterpretContext* ctxt){

    }
    ~InterpretContext(){};

    void regsetfree(){};
    void regsetused(){};

    void addvar(const std::string* name){};




};

#endif
