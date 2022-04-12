// B. Subtract Operation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int &el: a) {
            cin >> el;
        }
        sort(begin(a), end(a));

        bool ans = false;

        // Editorial - https://codeforces.com/blog/entry/101211

        int l = 0, r = 0;
        for (; l < n; ++l) {

            // Iteration ideas are from
            // https://codeforces.com/contest/1656/submission/150731872

            while (r < l) ++r;

            for (; r < n - 1; ++r) {
                if (a[r] - a[l] < k) continue;
                break;
            }

            if (a[r] - a[l] == k) {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
