// B. Stalin Sort

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

        vector<int> a(n);
        for (int& el: a)
            cin >> el;
        
        // Editorial - https://codeforces.com/blog/entry/135558
        int ans = 2000;
        for (int i = 0; i < n; ++i) {
            int len = 0;
            for (int j = i; j < n; ++j)
                len += a[i] >= a[j];
            ans = min(ans, n - len);
        }

        cout << ans << endl;
    }

    return 0;
}
