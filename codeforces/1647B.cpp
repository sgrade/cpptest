// B. Madoka and the Elegant Gift

#include <iostream>
#include <vector>
#include <string>
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

        vector<vector<int>> v(n, vector<int>(m));
        string s;
        for (auto &row: v) {
            cin >> s;
            for (int j = 0; j < m; ++j) {
                row[j] = s[j] == '0' ? 0 : 1;
            }
        }

        bool ans = true;

        // Editorial - https://codeforces.com/blog/entry/100780
        
        int sm;
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < m-1; ++j) {
                sm = v[i][j] + v[i][j+1] + v[i+1][j] + v[i+1][j+1];
                if (sm == 3) {
                    ans = false;
                    goto ANS;
                }
            }
        }

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
