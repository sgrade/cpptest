// A. Dawid and Bags of Candies

#include <stdio.h>
#include <algorithm>


int main(){

    int a[4];
    for (int i=0; i<4; ++i){
        scanf("%d", &(a[i]));
    }
    
    std::sort(a, a+4);

    if (a[0]+a[3] == a[1]+a[2]) printf("YES\n");
    else if (a[0]+a[1]+a[2] == a[3]) printf("YES\n");
    else printf("NO\n");

    return 0;
}