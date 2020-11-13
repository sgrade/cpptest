// B. Digital root

#include <stdio.h>


int main(){

    int n;
    scanf("%d\n", &n);

    while(n--){
        unsigned long long k, x;
        scanf("%llu %llu\n", &k, &x);
        // Editorial - https://codeforces.com/blog/entry/64847
        printf("%llu\n", (k - 1) * 9 + x);
    }

    return 0;
}
