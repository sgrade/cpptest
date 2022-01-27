// A. Min Max Swap

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

        int max_a = 0, max_b = 0;

        vector<int> a(n), b(n);
        for (auto &el: a) {
            cin >> el;
        }
        for (auto &el: b) {
            cin >> el;
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] < b[i]) {
                swap(a[i], b[i]);
            }
            max_a = max(max_a, a[i]);
            max_b = max(max_b, b[i]);
        }

        cout << max_a * max_b << '\n';
    }

    return 0;
}
