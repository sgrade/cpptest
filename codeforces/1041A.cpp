// A. Heist

#include <stdio.h>
#include <algorithm>

int main(){

    int n;
    scanf("%d\n", &n);

    int a[n];
    for (int i=0; i<n; ++i){
        scanf("%d", &(a[i]));
    }

    int stolen=0;

    std::sort(a, a+n);

    if (n>1){
        for (int i=1; i<n; ++i){
            stolen += a[i] - a[i-1] - 1;
        }
    }

    printf("%d\n", stolen);

    return 0;
}