// A. Rectangle Arrangement

#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        pair<int, int> p;
        int max_w = 0, max_h = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p.first >> p.second;
            max_w = max(max_w, p.first);
            max_h = max(max_h, p.second);
        }

        int ans = (max_w + max_h) * 2;
        cout << ans << endl;
    }

    return 0;
}
 