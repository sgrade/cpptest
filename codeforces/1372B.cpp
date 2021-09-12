// B. Omkar and Last Class of Math

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


vector<int> allPrimeFactors (int n){
    // Source - https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
    
    vector<int> v;
    if (n == 0 || n == 1) return v;

    while(n % 2 == 0){
        v.push_back(2);
        n /= 2;
    }

    for (int i=3; i <= sqrtl(n); i += 2){
        while (n % i == 0){
            v.push_back(i);
            n = n/i;
        }
    }
    
    if (n > 2) v.push_back(n);

    return v;

}

 
int main() {
 
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/79974
        vector<int> factors = allPrimeFactors(n);

        int a = n / factors[0];
        int b = n - a;
        
        cout << a << ' ' << b << endl;
    }
 
    return 0;
}