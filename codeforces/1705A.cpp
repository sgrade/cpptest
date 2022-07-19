// A. Mark the Photographer

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> h(2 * n);
        for (int &el: h) cin >> el;

        sort(h.begin(), h.end());

        bool ans = true;

        for (int i = 0; i < n; ++i) {
            if (h[n + i] - h[i] < x) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
