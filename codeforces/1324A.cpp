// A. Yet Another Tetris Problem

#include <stdio.h>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        int a[n];
        for (int i=0; i<n; ++i){
            scanf("%d ", &(a[i]));
        }

        bool ans = true;

        if (n > 1){
            int parity = a[0] % 2;
            for (int i=1; i<n; ++i){
                if (a[i] % 2 != parity) {
                    ans = false;
                    break;
                }
            }
        }

        ans ? puts("YES") : puts("NO");

    }

    return 0;
}
