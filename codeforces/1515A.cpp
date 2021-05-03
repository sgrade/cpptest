// A. Phoenix and Gold

#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        set<int> w;
        int tmp;
        int total_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            w.insert(tmp);
            total_sum += tmp;
        }

        bool ans = true;
        vector<int> output;

        if (total_sum == x) {
            ans = false;
        }
        else if (total_sum < x) {
            for (auto &el: w) {
                output.push_back(el);
            }
        }
        else if (total_sum > x) {
            int sum = 0;
            auto it = w.begin();
            while (it != w.end()) {
                sum += *it;
                if (sum == x) {
                    tmp = *it;

                    ++it;
                    output.push_back(*it);
                    sum += *it;

                    output.push_back(tmp);
                }
                else {
                    output.push_back(*it);
                }
                ++it;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
        if (ans) {
            for (auto &el: output) {
                cout << el << ' ';
            }
            cout << endl;
        }

    }

    return 0;
}
