// B. Special Numbers

#include <iostream>
#include <math.h>

using namespace std;

long long MOD = 1e9 + 7;


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        
        long long n, k;
        cin >> n >> k;

        long long ans = 0, power = 1;

        // Explanation - https://www.youtube.com/watch?v=X_kVGgHcfQs

        for (long long i = 0; i < 31; ++i) {
            if (k & (1 << i)) {
                ans = (ans + power) % MOD;
            }
            
            power *= n;
            power %= MOD;
        }
        
        cout << ans << endl;
    }

    return 0;
}
