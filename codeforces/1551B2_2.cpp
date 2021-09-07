// B2. Wonderful Coloring - 2

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        // Idea from https://codeforces.com/contest/1551/submission/127991041

        map<int, int> cnt;
        vector<pair<int, int>> indexes;

        int current;
        for (int i = 0; i < n; ++i) {
            cin >> current;
            ++cnt[current];

            if (cnt[current] <= k) {
                indexes.push_back(pair<int, int>(current, i));
            }
        }
        sort(begin(indexes), end(indexes));
        
        int num_of_painted = size(indexes) - size(indexes) % k;

        vector<int> ans(n);
        for (int i = 0; i < num_of_painted; ++i) {
            ans[indexes[i].second] = i % k + 1;
        }

        for (auto &el: ans) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
