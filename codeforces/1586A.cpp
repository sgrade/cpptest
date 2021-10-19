// A. Windblume Ode

#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>

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

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a){
            cin >> el;
        }

        unsigned long long sum = accumulate(begin(a), end(a), 0ULL);

        bool sum_is_prime = isPrime(sum);

        int idx_to_exclude = -1;
        if (sum_is_prime) {
            for (int i = 0; i < n; ++i) {
                // Editorial - https://codeforces.com/blog/entry/96072
                if (a[i] % 2 != 0) {
                    idx_to_exclude = i + 1;
                    break;
                }
            }
        }

        cout << (sum_is_prime ? n-1 : n) << endl;
        for (int i = 1; i <= n; ++i) {
            if (i == idx_to_exclude) {
                continue;
            }
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
