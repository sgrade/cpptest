// A. Got Any Grapes?

#include <stdio.h>


int main(){

    int x, y, z;
    scanf("%d %d %d\n", &x, &y, &z);

    int a, b, c;
    scanf("%d %d %d\n", &a, &b, &c);

    bool happy;

    a -= x;
    int aPlusB = a+b - y;
    int rest = aPlusB + c - z;

    happy = a<0 ? false : true;
    if (happy){
        happy = aPlusB < 0 ? false : true;
    }
    if (happy){  
        happy = rest < 0 ? false : true;
    }
    

    if (happy) printf("YES\n");
    else printf("NO\n");

    return 0;
}