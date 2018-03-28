int a = 5;
int func(int i){
    a = 6;
    return a+i;
}

int main(){
    return func(10);
}
