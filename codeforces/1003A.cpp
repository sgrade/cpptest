// A. Polycarp's Pockets

#include <stdio.h>
#include <algorithm>
#include <set>


int main(){

    int n;
    scanf("%d\n", &n);

    int a[n];
    for (int i=0; i<n; ++i){
        scanf("%d", &(a[i]));
    }
    
    int minPockets = 0;
    if (n==1){
        minPockets = 1;
    }
    else {
        std::sort(a, a + n);
        std::set<int> st(a, a+n);

        for (auto e: st){
            int count = std::count(a, a+n, e);
            if (count > minPockets) minPockets = count;
        }
    }

    printf("%d\n", minPockets);

    return 0;
}