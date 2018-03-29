int f(int x)
{
    if(x>1){
        return x*f(x);
    }else{
        return x;
    }
}
