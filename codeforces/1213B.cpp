// B. Bad Prices

#include <stdio.h>
#include <climits>
#include <algorithm>

int main(){

    int t;
    scanf("%d\n", &t);

    while (t--){

        int n;
        scanf("%d\n", &n);

        int a[n];
        for (int i=0; i<n; ++i) scanf("%d", &(a[i]));
        
        // https://codeforces.com/blog/entry/69464
        int ans = 0;
        int mn = INT_MAX;
        for (int i=n-1; i>=0; --i){
            if (a[i] > mn) ++ans;
            mn = std::min(mn, a[i]);
        }

        printf("%d\n", ans);
    }

    return 0;
}