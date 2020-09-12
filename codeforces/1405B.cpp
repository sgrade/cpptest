// B. Array Cancellation

#include <stdio.h>
#include <algorithm>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        // Editorial - https://codeforces.com/blog/entry/82366
        
        long long coins = 0;
        
        long long tmp;
        for (int i=0; i<n; ++i){
            scanf ("%lld", &tmp);
            coins = std::max(0LL, coins + tmp);
        }
        scanf("\n");

        printf("%lld\n", coins);
    }

    return 0;
}
