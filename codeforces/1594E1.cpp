// E1. Rubik's Cube Coloring (easy version)

#include <iostream>

using namespace std;
using ll = unsigned long long;

const int MOD = 1e9 + 7;


// Source - https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
ll power (const ll &base, const ll &exponent) {

    if (exponent == 0) return 1;
    
    ll ans = power(base, exponent / 2);

    if (exponent % 2 == 0) return ans * ans % MOD;

    return base * ans * ans % MOD;
}


int main() {

    int k;
    cin >> k;

    // Editorial - https://codeforces.com/blog/entry/95525

    ll exp = (1LL << k) - 2;

    ll ans = power(4LL, exp);
    ans *= 6;
    ans %= MOD;

    cout << ans << '\n';

    return 0;
}
