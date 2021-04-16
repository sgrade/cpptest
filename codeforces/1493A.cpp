// A. Anti-knapsack

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> output;

        // Idea - https://codeforces.com/contest/1493/submission/109290286
        for (int i = 1; i < n+1; ++i) {
            if (i != k && (i * 2 >= k || i > k)) {
                output.push_back(i);
            }
        }

        cout << output.size() << endl;
        for (auto &el: output) {
            cout << el << ' ';
        }
        cout << endl;

    }

}
