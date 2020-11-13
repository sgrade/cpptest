// B. Relatively Prime Pairs

#include <stdio.h>


int main(){

    // Editorial - https://codeforces.com/problemset/problem/1051/B
    unsigned long long l, r;
    scanf("%llu %llu\n", &l, &r);
    puts("YES");
    for (unsigned long long i=l; i<r+1; i+=2){
        printf("%llu %llu\n", i, i+1);
    }

    return 0;
}
