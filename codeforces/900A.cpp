// A. Find Extra One

#include <stdio.h>


int main(){

    int n;
    scanf("%d", &n);

    int cntPositive = 0;
    int cntNegative = 0;
    int x, y;
    while(n--){
        scanf("%d %d", &x, &y);
        if (x > 0) ++cntPositive;
        else if (x < 0) ++cntNegative;
    }

    if ((cntPositive == 1 || cntPositive == 0) || (cntNegative == 1 || cntNegative == 0)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
