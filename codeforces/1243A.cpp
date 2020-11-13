// A. Maximum Square

#include <stdio.h>
#include <algorithm>
#include <functional>


int main(){

    int k;
    scanf("%d\n", &k);

    while(k--){

        int n;
        scanf("%d\n", &n);

        int a[n];
        for (int i = 0; i < n; ++i){
            scanf("%d", &(a[i]));
        }
        std::sort(a, a+n, std::greater<int>());

        int ans = 1;
        // Indexing starts from 1
        for (int i = 0; i < n; ++i){
            if (i + 1 == a[i]) {
                ans = i + 1;
                break;
            }
            else if (i + 1 > a[i]) {
                ans = i;
                break;
            }
        }

        printf("%d\n", ans);

    }

    return 0;
}
