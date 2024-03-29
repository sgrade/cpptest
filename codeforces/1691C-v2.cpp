// C. Sum of Substrings
// Slightly different implementation than in 1691C.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ones = 0;

        vector<bool> a(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                a[i] = true;
                ++ones;
            }
        }

        long long ans = 1LL * ones * 11;

        if (ones > 0) {

            size_t first, last;

            if (a[n-1]) {
                ans -= 10;
            }
            else {
                last = s.find_last_of('1');
                if (n - (last + 1) <= k) {
                    swap(a[last], a[n - 1]);
                    k -= n - (last + 1);
                    ans -= 10;
                }
            }

            if (a[0]) {
                ans -= 1;
            }
            else {
                first = distance(a.begin(), find(a.begin(), a.end(), true));
                if (first != n-1 && first <= k) {
                    ans -= 1;
                    k -= first;
                }
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}
