// Several algorithms
// Below is a simple algorithm, which is easy to remember
// There are several faster algorithms here - https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
// A source code is also available there

#include <stdio.h>


unsigned long long fib(unsigned long long n){
    unsigned long long a = 0, b = 1, c;
    if (n == 0) return a;
    for (unsigned long long i = 2; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


int main(){

    int n = 6;
    printf("%llu\n", fib(n));

    return 0;
}
