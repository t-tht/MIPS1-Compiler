int recursion(int n){
    if(n==1){
        return 1;
    }
    else{
        return (recursion(n-1)+recursion(n-2));
    }
}
