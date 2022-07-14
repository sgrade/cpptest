// B. Almost Ternary Matrix
// NOT finished

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<vector<int>> ans(n, vector<int>(m));
        bool flag1 = true, flag2 = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = flag1 ^ flag2;
                if (j % 2 == 0) flag1 = !flag1;
            }
            flag2 = !flag2;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
