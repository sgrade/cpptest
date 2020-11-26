// A. Sea Battle

#include <stdio.h>
#include <algorithm>

int main(){

    int w1, h1, w2, h2;
    scanf("%d %d %d %d\n", &w1, &h1, &w2, &h2);

    int ans = 0;
    ans = w1 + h1 * 2 + 2;
    ans += w2 + h2 * 2 + 2;
    ans += std::max(0, w1 - w2);

    printf("%d\n", ans);

    return 0;
}
