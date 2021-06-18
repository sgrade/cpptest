// C. Challenging Cliffs
// Wrong answer on pretest 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> h(n);
        for (auto &el: h) {
            cin >> el;
        }

        sort(begin(h), end(h));

        vector<int> ans;

        int d = numeric_limits<int>::max();
        int idx1, idx2;

        for (int i = 0; i < n-1; ++i) {
            if (h[i+1] - h[i] < d) {
                idx1 = i;
                idx2 = i+1;
                d = h[i+1] - h[i];
            }
        }
        ans.push_back(h[idx1]);
        int last = h[idx2];
        h.erase(h.begin() + idx1);
        h.erase(h.begin() + idx2 - 1);

        int h_to_place = n - 2;
        int left = 0, right = h.size() - 1;
        while (h_to_place > 0) {

            while (h[left] == *ans.rbegin()) {
                ans.push_back(h[left]);
                --h_to_place;
                ++left;
                continue;
            }

            ans.push_back(h[right]);
            --h_to_place;

            if (left < right) {
                ans.push_back(h[left]);
                --h_to_place;
                --right;
                ++left;
            }
        }

        ans.push_back(last);
        for (auto &el: ans) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
