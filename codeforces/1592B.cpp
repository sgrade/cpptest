// B. Hemose Shopping

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        vector<int> a_sorted(begin(a), end(a));
        sort(begin(a_sorted), end(a_sorted));

        bool ans = true;

        int d;
        for (int i = 0; i < n; ++i) {
            if (a[i] != a_sorted[i]) {
                d = max(i, n-1-i);
                if (d < x) {
                    ans = false;
                    break;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
