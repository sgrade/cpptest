// A. Snowball

#include <stdio.h>
#include <algorithm>


int main(){

    int w, h, u1, d1, u2, d2;
    scanf("%d %d\n%d %d\n%d %d\n", &w, &h, &u1, &d1, &u2, &d2);

    ++h;
    while(--h){
        w += h;
        if (h == d1) w-= u1;
        if (h == d2) w-= u2;
        w = std::max(0, w);
    }

    printf("%d\n", w);

    return 0;
}
