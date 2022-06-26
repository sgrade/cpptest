// C. Fishingprince Plays With Array

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;


// Ideas for implementation - https://codeforces.com/contest/1696/submission/161736565
vector<pair<int, ll>> tf(const vector<int> &v, const int &m) {
    vector<pair<int, ll>> output;
    int y;
    for (int x: v) {
        y = 1;
        while (x % m == 0) {
            x /= m;
            y *= m;
        }
        if (!output.empty() && x == output.back().first) {
            output.back().second += y;
        }
        else {
            output.emplace_back(x, y);
        }
    }
    return output;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &el: a) cin >> el;
        int k;
        cin >> k;
        vector<int> b(k);
        for (int &el: b) cin >> el;

        bool ans = false;

        // Editorial - https://codeforces.com/blog/entry/103479
        vector<pair<int, ll>> transformed_a = tf(a, m);
        vector<pair<int, ll>> transformed_b = tf(b, m);

        ans = (transformed_a == transformed_b ? true : false);

        cout << (ans ? "Yes\n" : "No\n");
    }

    return 0;
}
