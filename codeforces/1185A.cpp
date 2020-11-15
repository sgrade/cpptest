// A. Ropewalkers

#include <stdio.h>
#include <algorithm>


int main(){

    int lst[3], d;
    scanf("%d %d %d %d\n", &lst[0], &lst[1], &lst[2], &d);

    std::sort(lst, lst+3);

    int left = std::max(0, d - abs(lst[0] - lst[1]));
    int right = std::max(0, d - abs(lst[1] - lst[2]));

    int ans = left + right;
    printf("%d\n", ans);

    return 0;
}
