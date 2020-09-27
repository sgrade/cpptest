// B - Integer Preference

#include <stdio.h>


int main(){

    long long a, b, c, d;
    scanf("%lld %lld %lld %lld\n", &a, &b, &c, &d);

    if (c>b || d<a) printf("No\n");
    else printf("Yes\n");

    return 0;
}
