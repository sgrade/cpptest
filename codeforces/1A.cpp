// A. Theatre Square

#include <stdio.h>


int main(){

    long long n, m, a;
    scanf("%lld %lld %lld", &n, &m, &a);

    long long nSide, mSide;
    if ((float)n/a >= 1){
        if (n%a>0) nSide = n/a+1;
        else nSide = n/a;
    }
    else nSide = 1;

    if ((float)m/a >= 1){
        if (m%a>0) mSide = m/a+1;
        else mSide = m/a;
    }
    else mSide = 1;
    
    long long output = nSide * mSide;
    printf("%lld\n", output);

    return 0;
}