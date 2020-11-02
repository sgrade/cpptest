// C. Division
// TLE

#include <iostream>
#include <math.h>
#include <vector>
#include <map>

using namespace std;
using ull = unsigned long long;


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

    int t;
    cin >> t;

    while(t--){

        ull p, q;
        cin >> p >> q;

        ull x = 0;

        if (p < q){
            x = p;
        }

        // x = p
        else if (p % q !=0){
            x = p;
        }

        // x < p
        else {
            
            vector<ull> primesQ = allPrimeFactors(q);
            
            // Idea from solution by ksun48 from https://codeforces.com/contest/1444/standings#
            for (ull el: primesQ){
                ull candidate = p;
                while(candidate % q == 0) candidate /= el;
                x = max(x, candidate);
            }
            
        }

        cout << x << endl;

    }

    return 0;
}
