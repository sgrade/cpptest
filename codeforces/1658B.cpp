// B. Marin and Anti-coprime Permutation

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MOD = 998244353;
    
    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        long long ans = 1;

        if (n % 2 != 0) {
            ans = 0;
        }

        else {
            // Editorial - https://codeforces.com/blog/entry/101302
            for (int i = 2; i <= n / 2; ++i) {
                ans *= 1LL * i * i % MOD;
                ans %= MOD;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
