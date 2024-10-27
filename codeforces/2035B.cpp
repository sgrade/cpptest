// B. Everyone Loves Tres
// https://codeforces.com/contest/2035/problem/B

#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        long long n;
        cin >> n;

        if (n == 1 || n == 3) {
            cout << -1 << endl;
            continue;
        }

        // It should be divisible by 2, 3, 11
        // 6 in the end is divisible by 2
        // A number is divisible by 3 when the sum of its digits is a multiple of 3
        // A number is divisible by 11 when the sum of the numbers that occupy the even places 
        // minus the sum of the numbers that occupy the odd places 
        // is equal to 0 or a number which is a multiple of 11.
        
        string ans;
        for (int i = 0; i < n; ++i) {
            ans += '3';
        }

        ans[n - 1] = '6';
        ans[n - 2] = '6';
        if (n % 2 != 0)
            ans[n - 4] = '6';

        cout << ans << endl;
    }

    return 0;
}
