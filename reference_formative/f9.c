int function(int a, int b)
{
    if(a<b){
        a=a-1;
        if(a>b){
            b=b+3;
            if(a==b){
                return a*b;
            }
        }
        return b;
    }
    return 13;
}

int main()
{
    return function(0,0)+function(1,2)+function(4,3)+function(6,7);
}


Program[
FunctionDeclaration[
        CompoundStatement[[block[
                        
                          
                    IfStatement[
                          Assertion= [left=Identifier[a]
                                      Operator= "<"
                                      right= Identifier[b]]
                            
                                ]
                                ]
                    ]]


]

FunctionDeclaration: Statements
        

Block: Declaration
        Statements



If_Statement: