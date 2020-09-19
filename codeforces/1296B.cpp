// B. Food Buying

#include <stdio.h>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        long long s;
        scanf("%lld\n", &s);

        long long b = s;
        int rem = 0;
        long long tmp;
        while (s > 0){
            tmp = (s+rem)/10;
            rem = (s+rem)%10;

            s = tmp;
            b += tmp;
        }

        printf("%lld\n", b);

    }

    return 0;
}