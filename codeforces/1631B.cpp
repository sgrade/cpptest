// B. Fun with Even Subarrays

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // Idea from - https://codeforces.com/contest/1631/submission/144175733

        vector<int> a(n+1);
        for (int i = 1; i < n+1; ++i) {
            cin >> a[i];
        }

        int ans = 0;

        int last = a[n];

        int left = n, cnt;

        while (left > 0) {

            while (left > 0 && a[left] == last) {
                --left;
            }

            cnt = n - left;
            cnt = min(cnt, left);

            if (cnt) {
                ++ans;
            }

            left -= cnt;
            cnt = 0;
        }

        cout << ans << '\n';
    }

    return 0;
}
