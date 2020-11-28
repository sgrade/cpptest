// A. Buying A House

#include <stdio.h>


int main(){

    int n, m, k;
    scanf("%d %d %d\n", &n, &m, &k);

    int a[n];
    for (auto &el: a) scanf("%d", &el);

    --n;
    --m;

    int i = 0;
    while(true){
        ++i;
        if (m - i >= 0){
            if (a[m-i] != 0 && a[m-i] <= k)
            break;
        }
        if (m + i <= n){
            if (a[m+i] != 0 && a[m+i] <= k)
            break;
        }
    }

    printf("%d\n", i * 10);

    return 0;
}
