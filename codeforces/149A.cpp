// A. Business trip

#include <stdio.h>
#include <algorithm>
#include <functional>


int main(){

    int k;
    scanf("%d\n", &k);

    int a[12];
    for (int i=0; i<12; ++i){
        scanf("%d", &(a[i]));
    }

    std::sort(a, a+12, std::greater<int>());

    int i=0;
    int months = 0;
    if (k>0){
        for (; i<12; ++i){
            k -= a[i];
            ++months;
            if (k<=0) break;
        }
    }

    if (k>0) months = -1;

    printf("%d\n", months);

    return 0;
}