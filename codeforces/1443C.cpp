// C. The Delivery Dilemma

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            a[i] = pair<int, int>(tmp, i);
        }
        vector<int> b(n);
        for (auto &el: b) {
            cin >> el;
        }

        sort(begin(a), end(a));

        ull ans = a[n-1].first;
        ull sm = 0ULL, next_a, current_b;
        for (int i = n-1; i > -1; --i) {
            current_b = sm + b[a[i].second];
            if (current_b < ans) {
                sm = current_b;
                next_a = i == 0? 0 : a[i-1].first;
                ans = max(next_a, current_b);
            }
            else {
                break;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
