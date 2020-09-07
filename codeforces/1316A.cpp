// A. Grade Allocation

#include <stdio.h>
#include <algorithm>
#include <numeric>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n, m;
        scanf("%d %d\n", &n, &m);

        int a[n];
        for (int i=0; i<n; ++i){
            scanf("%d", &(a[i]));
        }
        std::sort(a, a+n);

        int myScore = a[0];
        int sum = std::accumulate(a, a+n, 0);
        
        if (sum >= m) printf("%d\n", m);
        else printf("%d\n", sum);

    }

    return 0;
}