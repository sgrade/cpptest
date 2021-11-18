// C. Two Arrays

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

        vector<int> a(n), b(n);
        for (auto &el: a) {
            cin >> el;
        }
        for (auto &el: b) {
            cin >> el;
        }

        sort(begin(a), end(a));
        sort(begin(b), end(b));

        bool ans = true;

        int diff;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i] || a[i]+1 == b[i]) {
                continue;
            }
            else {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
