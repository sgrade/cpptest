// A. Panoramix's Prediction

#include <stdio.h>
#include <cmath>

bool isPrime(int x){
    for (int i=sqrt(x); i>1; --i){
        if (x%i == 0) return 0;
    }
    return 1;
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i=n+1; i<m; ++i){
        if (isPrime(i)) {
            printf("NO\n");
            exit(0);
        }
    }
    if (isPrime(m)) printf("YES\n");
    else printf("NO\n");

    return 0;
}