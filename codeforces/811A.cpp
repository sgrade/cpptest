// A. Vladik and Courtesy

#include <stdio.h>


int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    bool vladik = true;
    int i = 1;
    while(a > -1 && b > -1){
        if (vladik) a -= i;
        else b -= i;
        ++i;
        vladik = !vladik;
    }

    if (vladik) puts("Valera");
    else puts("Vladik");

    return 0;
}
