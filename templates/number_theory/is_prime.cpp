// Test if a number is prime

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


bool isPrime (unsigned long long n){
    if (n == 0 || n == 1) return false;
    for (unsigned long long i=2; i <= sqrtl(n); ++i){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}


int main(){

    unsigned long long n = 9;

    cout << isPrime(n) << endl;

    return 0;
}
