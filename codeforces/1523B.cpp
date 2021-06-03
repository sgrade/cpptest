// B. Lord of the Values

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<ll> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        // Editorial - https://codeforces.com/blog/entry/91271
        int i;
        vector<vector<ll>> output;
        for (int j = 1; j < n; j += 2) {
            i = j-1;
            for (int m = 0; m < 3; ++m) {
                output.push_back({1, i+1, j+1});
                a[i] += a[j];
                output.push_back({2, i+1, j+1});
                a[j] -= a[j];
            }
        }

        cout << output.size() << endl;
        for (auto &v: output) {
            for (auto &el: v) {
                cout << el << ' ';
            }
            cout << endl;
        }
        
    }

    return 0;
}
