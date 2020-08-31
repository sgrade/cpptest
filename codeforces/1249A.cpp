// A. Yet Another Dividing into Teams

#include <stdio.h>
#include <algorithm>

int main(){

    int q;
    scanf("%d\n", &q);

    while(q--){

        int n;
        scanf("%d\n", &n);

        int a[n], tmp;
        for (int i=0; i<n; ++i){
            scanf("%d", &tmp);
            a[i] = tmp;
        }

        if (n == 1)
        {
            printf("1\n");
            // Because we don't scanf here, we cannot put this if above the scan
            // If we do it, next scanf scans the line, which we didn't scan -> wrong answers follow
            continue;
        }

        std::sort(a, a+n);

        int groups = 1;
        // number of groups can be only 1 or 2 (even and odd)
        for (int i=1; i<n; ++i){
            if (a[i] - a[i-1] == 1){
                groups = 2;
                break;
            }
        }

        printf("%d\n", groups);

    }

    return 0;
}