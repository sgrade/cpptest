// A. Vanya and Cubes

#include <iostream>


int main(){

    int n;
    scanf("%d", &n);

    int cubesOnCurrentLevel=0, cubesTotal=0, i=1;
    for(; i<10001; ++i){
        cubesOnCurrentLevel += i;
        cubesTotal += cubesOnCurrentLevel;
        // printf("lvl: %d, total: %d\n", cubesOnCurrentLevel, cubesTotal);
        if (cubesTotal == n){
            printf("%d", i);
            exit(0);
        }
        if (cubesTotal > n){
            printf("%d", i-1);
            exit(0);
        }
    }

    return 0;
}