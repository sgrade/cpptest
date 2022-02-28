// B. MEX and Array

#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        long long ans = 0;

        // Idea - https://codeforces.com/contest/1637/submission/146074532
        for (int left = 0; left < n; ++left) {

            for (int right = left; right < n; ++right) {

                for (int i = left; i <= right; ++i) {
                    ans += (a[i] == 0 ? 2 : 1);
                }

            }

        }

        cout << ans << '\n';
    }

    return 0;
}
