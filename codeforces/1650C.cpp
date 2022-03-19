// C. Weight of the System of Nested Segments

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        // Editorial - https://codeforces.com/blog/entry/100712

        // w, x, i
        vector<vector<int>> w(m, vector<int>(3));
        for (int i = 0; i < m; ++i) {
            cin >> w[i][1] >> w[i][0];
            w[i][2] = i+1;
        }
        sort (begin(w), end(w));

        int total_weight = 0;

        // x, w, i
        vector<vector<int>> x(n * 2, vector<int>(2));
        for (int j = 0; j < n * 2; ++j) {
            x[j][0] = w[j][1];
            x[j][1] = w[j][2];
            total_weight += w[j][0];
        }
        sort(begin(x), end(x));

        cout << total_weight << '\n';

        for (int i = 0; i < n; ++i) {
            cout << x[i][1] << ' ' << x[2*n-1 - i][1] << '\n';
        }
        cout << '\n';
    }

    return 0;
}
