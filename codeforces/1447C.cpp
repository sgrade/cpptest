// C. Knapsack

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
using ull = unsigned long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        ull W;
        cin >> n >> W;

        vector<pair<int, int>> w(n);
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            w[i] = pair<int, int>(tmp, i);
        }
        sort(begin(w), end(w));

        ull half_W = (W + 2 - 1)  / 2;

        ull sm = 0ULL;
        deque<int> ans;
        int i = n-1;
        while (w[i].first > W) {
            --i;
        }
        for (; i > -1; --i) {
            sm += w[i].first;
            ans.push_back(w[i].second);
            if (half_W <= sm && sm <= W) {
                break;
            }
        }

        if (half_W <= sm && sm <= W) {
            cout << ans.size() << endl;
            for (auto &el: ans) {
                cout << el + 1 << ' ';
            }
            cout << endl;
        }
        else {
            cout << "-1" << endl;
        }

    }

    return 0;
}
