// A. Yet Another Two Integers Problem

#include <stdio.h>
#include <algorithm>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int a, b;
        scanf("%d %d\n", &a, &b);

        if (a==b){
            printf("0\n");
            continue;
        }

        int moves = 0;
        moves = (abs(b-a))/10;
        if (abs(b-a) % 10 != 0) moves += 1;
        
        printf("%d\n", moves);

    }

    return 0;
}