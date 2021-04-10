int a[5][5];
/* comment()
// */int b;

int f(int x[][5]){
    if (x[0][0] <= 1){
        return 1;
    }
    return 2;
}

int main(){
    a[5][0] = 1;
    putint(f(f(a)));
    
    return(0);
}