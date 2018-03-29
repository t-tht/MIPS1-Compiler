<<<<<<< HEAD
int ift(int x, int y){
    if(x==y){
        return 0;
    }
    return 1;
=======
int h(){
    return 20;
}
int g(int x){
    return x;
>>>>>>> 06ec702e05564f4a893cfa8cf24713707433174b
}
int func(int x, int y, int z){
    return x+y+z;
}
int main(){
    int a = 10;
    return func(g(a),a,20);
}
