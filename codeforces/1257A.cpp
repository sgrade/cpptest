// A. Two Rival Students

#include <stdio.h>
#include <algorithm>


int main(){

    int t;
    scanf("%d\n", &t);

    while (t--){

        int n, x, a, b;
        scanf("%d %d %d %d\n", &n, &x, &a, &b);

        int distance = std::abs(a-b);
        distance += x;

        if (distance > n-1) distance = n-1;

        printf("%d\n", distance);

    }

    return 0;
}