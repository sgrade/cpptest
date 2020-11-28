// A. Cupboards

#include <stdio.h>
#include <algorithm>


int main(){

    int n;
    scanf("%d\n", &n);

    int lOpen = 0;
    int rOpen = 0;
    
    for (int i = 0; i < n; ++i){
        int li, ri;
        scanf("%d %d\n", &li, &ri);
        if (li == 1) ++lOpen;
        if (ri == 1) ++rOpen;
    }

    int ans = std::min(lOpen, n - lOpen) + std::min(rOpen, n - rOpen);
    printf("%d\n", ans);

    return 0;
}
