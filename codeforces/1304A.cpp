// A. Two Rabbits

#include <stdio.h>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int x, y, a, b;
        scanf("%d %d %d %d\n", &x, &y, &a, &b);

        if ( (y-x)%(a+b) == 0 ) printf("%d\n", (y-x)/(a+b));
        else printf("-1\n");

    }

    return 0;
}