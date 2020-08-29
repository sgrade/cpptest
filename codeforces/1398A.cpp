// A. Bad Triangle

#include <stdio.h>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        int tmp, arr[n];
        for (int x=0; x<n; ++x){
            scanf("%d", &tmp);
            arr[x] = tmp;
        }
        scanf("\n");

        // Editorial - https://codeforces.com/blog/entry/81506
        if ( (arr[0] + arr[1]) <= arr[n-1])
        {
            printf("1 2 %d\n", n);
        }
        else printf("-1\n");
    }

    return 0;
}