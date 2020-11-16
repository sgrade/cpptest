// A. Army

#include <stdio.h>


int main(){

    int n;
    scanf("%d\n", &n);

    int d[n - 1];
    for (int i = 0; i < n - 1; ++i) scanf("%d ", &(d[i]));
    scanf ("\n");

    int a, b;
    scanf("%d %d\n", &a, &b);
    
    // indexing in the array "d" starts from 0
    --a;
    --b;

    int ans = 0;
    for (int i = a; i < b; ++i) ans += d[i];

    printf("%d\n", ans);

    return 0;
}
