// Test if a number is prime

#include <iostream>
#include <math.h>

using namespace std;


bool isPrime (int n){
    if (n == 0 || n == 1) return false;
    for (int i=2; i <= sqrtl(n); ++i){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}


int main(){

    int n = 9;

    cout << isPrime(n) << endl;

    return 0;
}
