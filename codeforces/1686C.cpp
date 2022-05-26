// C. Circular Local MiniMax

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

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) cin >> el;
        sort(a.begin(), a.end());

        bool ans = true;
        vector<int> b;
        
        if (n % 2 != 0) {
            ans = false;
        }

        else {
            
            // Editorial - https://codeforces.com/blog/entry/103198
            int m = n / 2;
            
            for (int i = 1; i < m; ++i) {
                if (a[i] == a[i + m - 1]) {
                    ans = false;
                }
            }

            for (int i = 0, j = m; ans, i < m, j < n; ++i, ++j) {
                b.push_back(a[i]);
                b.push_back(a[j]);
            }
        }

        if (!ans) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            for (int &el: b) {
                cout << el << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
