// B. MIN-MEX Cut

#include <iostream>
#include <string>
#include <limits>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int n = size(s);

        int ans = 0;

        // Solved right myself, but got TLE, thus
        // idea for fast implementation is from here - https://codeforces.com/contest/1566/submission/128594107

        int zeroes = 0;
        int leftmost_zero_idx = numeric_limits<int>::max(), rightmost_zero_idx = numeric_limits<int>::min();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++zeroes;
                leftmost_zero_idx = min(leftmost_zero_idx, i);
                rightmost_zero_idx = max(rightmost_zero_idx, i);
            }
        }

        if (zeroes == 0) {
            ans = 0;
        }
        else if (zeroes == (rightmost_zero_idx - leftmost_zero_idx) + 1) {
            ans = 1;
        }
        else {
            ans = 2;
        }

        cout << ans << endl;

    }

    return 0;
}
