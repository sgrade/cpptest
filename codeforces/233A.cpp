// A. Perfect Permutation

#include <stdio.h>
#include <algorithm>

int main(){

    int n;
    scanf("%d\n", &n);

    if (n%2 != 0){
        printf("-1\n");
    }
    else {
        for (int i=1; i<=n; i+=2){
            printf("%d %d ", i+1, i);
        }
    }

    return 0;
}