// A. Golden Plate

#include <stdio.h>


int main(){

    int w, h, k;
    scanf("%d %d %d\n", &w, &h, &k);

    int ans = 0;
    
    ++k;
    while(--k){
        ans += 2 * w + 2 * (h - 2);
        w -= 4;
        h -= 4;
    }

    printf("%d\n", ans);

    return 0;
}
