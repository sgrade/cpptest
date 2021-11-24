// B. Special Permutation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, a, b;
        cin >> n >> a >> b;

        // Editorial - https://codeforces.com/blog/entry/97164

        vector<int> output;
        output.push_back(a);
        for (int i = n; i > 0; --i) {
            if (i == a || i == b) {
                continue;
            }
            output.push_back(i);
        }
        output.push_back(b);

        int mn, mx;
        mn = *min_element(begin(output), begin(output) + (n + 1) / 2);
        mx = *max_element(begin(output) + (n + 1) / 2, end(output));

        if (a == mn && b == mx) {
            for (auto &el: output) {
                cout << el << ' ';
            }
        }
        else {
            cout << -1;
        }

        cout << endl;

    }

    return 0;
}
