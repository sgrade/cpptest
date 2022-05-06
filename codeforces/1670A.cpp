// A. Prof. Slim

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
        set<int> positives;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > 0) positives.insert(i);
        }

        bool ans = true;

        if (n > 1) {
            int idx;
            for (int i = n - 1; i > 0; --i) {
                if (a[i] < 0) {
                    if (positives.size() > 0) {
                        idx = *positives.begin();
                        if (idx > i) break;
                        a[i] = -a[i];
                        a[idx] = -a[idx];
                        positives.erase(positives.begin());
                    }
                    else {
                        break;
                    }
                }
            }

            for (int i = 1; i < n; ++i) {
                if (a[i-1] > a[i]) {
                    ans = false;
                    break;
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
