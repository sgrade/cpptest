// All prime factors (divisors) of a number

// Algorithm used in this file
// https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/

// Alternative algorithm (not used in this file)
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


vector<unsigned long long> allPrimeFactors (unsigned long long n){
    vector<unsigned long long> v;
    if (n == 0 || n == 1) return v;

    while(n % 2 == 0){
        v.push_back(2);
        n /= 2;
    }

    for (unsigned long long i=3; i <= sqrtl(n); i += 2){
        while (n % i == 0){
            v.push_back(i);
            n = n/i;
        }
    }
    
    if (n > 2) v.push_back(n);

    return v;

}


int main(){

    unsigned long long n = 60;

    for (auto el: allPrimeFactors(n)){
        cout << el << ' ';
    }
    cout << endl;

    return 0;
}
