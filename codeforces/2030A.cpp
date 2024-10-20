// A. A Gift From Orangutan

#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        auto p = minmax_element(a.begin(), a.end());
        int mn = *p.first, mx = *p.second;
        int ans = (mx - mn) * (n - 1);
        cout << ans << endl;
    }

    return 0;
}
