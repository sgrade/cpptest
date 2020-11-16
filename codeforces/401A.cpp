// A. Vanya and Cards

#include <stdio.h>
#include <stdlib.h>
#include <numeric>


int main(){

    int n, x;
    scanf("%d %d\n", &n, &x);

    int a[n];
    for (int i=0; i<n; ++i){
        scanf("%d ", &(a[i]));
    }

    int sum = abs(std::accumulate(a, a+n, 0));
    // to ceil: (a + b - 1) / b
    int ans = (sum + x - 1) / x;

    printf("%d\n", ans);

    return 0;
}
