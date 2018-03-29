int h(){
    return 20;
}
int g(int x){
    return x;
}
int func(int x, int y, int z){
    return x+y+z;
}
int main(){
    int a = 10;
    return func(g(a),a,20);
}
