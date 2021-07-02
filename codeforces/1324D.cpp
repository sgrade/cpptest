// D. Pair of Topics

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<vector<int>> ab(n, vector<int>(2));
    for (auto &el: ab) {
        cin >> el[0];
    }
    for (auto &el: ab) {
        cin >> el[1];
    }
    
    // Editorial - https://codeforces.com/blog/entry/74714
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = ab[i][0] - ab[i][1];
    }
    sort(begin(c), end(c));

    long long ans = 0;

    // ci > -cj, which is equal to cj > -ci
    for (int j = 0; j < n; ++j) {
        int negative_cj = -c[j];
        auto it_ci = upper_bound(begin(c), end(c), negative_cj);
        // https://codeforces.com/contest/1324/submission/87424769
        int d = distance(it_ci, begin(c) + j);
        ans += max(0, d);
    }

    cout << ans << endl;

    return 0;
}
