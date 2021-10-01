// A. CQXYM Count Permutations

#include <iostream>

using namespace std;


int main() {

    const int MOD = 1e9 + 7;
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long ans = 1LL;
        // Ans is 1/2 of all permutations ((2*n)! / 2)
        // Check editorial for details - https://codeforces.com/blog/entry/95477
        // The idea to count from 3 (to avoid later dividing by 2) is from here - 
        // https://codeforces.com/contest/1581/status/A?order=BY_CONSUMED_TIME_ASC
        for (int i = 3; i <= 2*n; ++i) {
            ans = ans * i % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}
