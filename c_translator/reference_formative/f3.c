Program[
    FunctionDeclaration[
                        returnType=[ Type[IntType]]
                        name=[Identifier[f]]
                        parameters=[(returnType[[IntType]], Identifier[x])]
                        body= CompoundStatement[
                        
                                                ReturnStatement[ Number[10]]
                        ]
                        
        
        ]




]

Program[
        FunctionDeclaration[
                            returnType=[ Type[IntType]]
                            name=[Identifier[main]]
                            parameters=[(returnType[[IntType]], Identifier[x])]
                            body= CompoundStatement[
                                                    
                                                    ReturnStatement[AddExpr[ left= ReturnFunction[
                                                        name=[Identifier[f]]
                                                        parameters= [Number[11]]
                                                                                                 ],
                                                                            right= Number
                                                                            ]
                                                                                        
                                                                                    ]
                                                    ]
                            
                            
                            ]
        
        
        
        
        ]






int f(int x)
{
    return 10;
}

int main()
{
    return f(11)+7;
}

