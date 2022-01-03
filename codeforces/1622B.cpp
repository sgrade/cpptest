// B. Berland Music

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        
        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/98453

        vector<vector<int>> p(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            cin >> p[i][1];
            p[i][2] = i;
        }

        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            p[i][0] = s[i] == '0' ? 0 : 1;
        }

        sort(begin(p), end(p));

        vector<int> q(n);
        for (int i = 0; i < n; ++i) {
            q[p[i][2]] = i + 1;
        }

        for (auto &el: q) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}
