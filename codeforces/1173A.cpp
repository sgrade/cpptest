// A. Nauuo and Votes

#include <iostream>

int main(){

    int x, y, z;
    scanf("%d %d %d\n", &x, &y, &z);

    if (x - y > z) printf("+\n");
    else if (y - x > z) printf("-\n");
    else if (y - x == 0 && z == 0) printf("0\n");
    else printf("?\n");

    return 0;
}