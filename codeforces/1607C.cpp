// C. Minimum Extraction

#include <iostream>
#include <vector>
#include <algorithm>

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
        sort(begin(a), end(a));

        // Editorial - https://codeforces.com/blog/entry/96604

        int ans = a[0];
        for (int i = 1; i < n; ++i) {
            ans = max(ans, a[i] - a[i-1]);
        }

        cout << ans << endl;
    }

    return 0;
}
