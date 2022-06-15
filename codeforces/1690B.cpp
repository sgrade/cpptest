// B. Array Decrements

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a (n), b(n);
        for (int &el: a) cin >> el;
        for (int &el: b) cin >> el;

        bool ans = true;

        int max_d = 0;
        for (int i = 0; i < n; ++i) {
            max_d = max(max_d, a[i] - b[i]);
            if (max_d < 0) {
                ans = false;
                goto ANS;
            }
        }

        int d;
        for (int i = 0; i < n; ++i) {
            d = a[i] - b[i];
            if (d != max_d) {
                if (b[i] == 0) continue;
                ans = false;
                break;
            }
        }

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
