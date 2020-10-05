// A. Joysticks

#include <stdio.h>
#include <algorithm>


int main(){

    int a1, a2;
    scanf("%d %d\n", &a1, &a2);

    // Smaller is connected to the charger
    if (a1 > a2) std::swap(a1, a2);

    int ans = 0;
    while ((a1 >= 1 && a2 >= 1) && (a1 >= 2 || a2 >=2) ) {
        a1 += 1;
        a2 -= 2;
        ++ans;
        if (a2 <= 1) std::swap(a1, a2);
    }

    printf("%d\n", ans);

    return 0;
}