// A. New Year Candles

#include <stdio.h>


int main(){

    int a, b;
    scanf("%d %d\n", &a, &b);

    int hours=0;
    int wentOut=0;
    while(a>0){
        hours += a;
        wentOut += a;

        a = wentOut / b;
        wentOut %= b;
    }


    printf("%d\n", hours);

    return 0;
}