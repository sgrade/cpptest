// B. Maximize Mex

#include <bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        // Editorial - https://codeforces.com/blog/entry/134873
        vector<int> a(n + 1);
        int tmp;
        for (int i = 1; i <= n; ++i) {
            cin >> tmp;
            if (tmp > n)
                continue;
            ++a[tmp];
        }
        for (int i = 0; i <= n; ++i) {
            if (a[i] == 0) {
                cout << i << endl;
                break;
            }
            if (i + x > n)
                continue;
            a[i + x] += a[i] - 1;
        }
    }

    return 0;
}
