// A. Find Array

#include <iostream>
#include <math.h>
#include <vector>

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


int main() {

    vector<int> dp(1000);
    int i = 0, ai = 2;
    while (i < 1000) {
        dp[i] = ai;
        ++i;
        while (true) {
            ++ai;
            if (isPrime(ai)) {
                break;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << dp[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
