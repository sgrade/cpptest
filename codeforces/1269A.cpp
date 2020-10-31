// A. Equation

#include <iostream>
#include <math.h>
#include <limits>

int isPrime(int x){

    if (x <= 1) return false;
    for (int i=2; i<=sqrt(x); ++i){
        if (x % i == 0) return false;
    }
    return true;

}

int main(){

    int n;
    scanf("%d\n", &n);

    for (int i=4; i < std::numeric_limits<int>::max(); ++i){
        if (!isPrime(i) && !isPrime(n+i)){
            printf("%d %d\n", n+i, i);
            break;
        }
    }

    return 0;
}
