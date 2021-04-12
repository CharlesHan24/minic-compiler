int a[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};

void add(int a[]){
    a[0] = a[0] + 1;
    a[1] = a[1] + 1;
    a[2] = a[2] + 1;
}

int main(){
    add(a[1]);
    add(a[4]);
    putarray(25, a);
    return 0;
}