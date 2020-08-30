// A. Rewards

#include <stdio.h>


int main(){

    int a1, a2, a3, b1, b2, b3, n;
    scanf("%d %d %d\n", &a1, &a2, &a3);
    scanf("%d %d %d\n", &b1, &b2, &b3);
    scanf("%d\n", &n);

    int a = a1+a2+a3;
    int b = b1+b2+b3;

    int shLeft = n - a/5 - b/10;
    if (a%5 > 0) shLeft -= 1;
    if (b%10 > 0) shLeft -= 1;

    if (shLeft >= 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}