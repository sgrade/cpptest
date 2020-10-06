// A. Joysticks

#include <stdio.h>
#include <algorithm>


int main(){

    int a1, a2;
    scanf("%d %d\n", &a1, &a2);

    // Smaller is connected to the charger
    if (a1 > a2) std::swap(a1, a2);

    int ans = 0;

    // Hence, if at the beginning of minute some joystick is charged by 1 percent, it has to be connected to a charger, otherwise the game stops.
    // (a2 >= 2)
    // If some joystick completely discharges (its charge turns to 0), the game also stops.
    // (a1 > 0  && a2 > 0)
    while ((a1 > 0  && a2 > 0) && (a2 >= 2)) {
        a1 += 1;
        a2 -= 2;
        ++ans;
        if (a2 <= 2) std::swap(a1, a2);
    }

    printf("%d\n", ans);

    return 0;
}