int a(int x){
    return x + 1;
}
int b(int x){
    return a(x + 1);
}
int main(){
    return b(2)+ a(2);
}
