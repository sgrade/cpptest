// A. Little C Loves 3 I

#include <iostream>


int main(){

    int n;
    scanf("%d\n", &n);

    int a=1, b=1, c;
    c = n-2;
    if (c%3 == 0){
        --c;
        ++b;
    }

    printf("%d %d %d\n", a, b, c);

    return 0;
}
