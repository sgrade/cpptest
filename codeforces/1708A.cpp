// A. Difference Operations

#include <iostream>
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

        bool ans = true;

        // Editorial - https://codeforces.com/blog/entry/104930
        for (int i = 1; i < n; ++i) {
            if (a[i] % a[0] != 0) {
                ans = false;
                break;
            }
        }

        ANS:
        cout << (ans ? "YES\n": "NO\n");
    }
}
