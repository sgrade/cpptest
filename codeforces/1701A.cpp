// A. Grass Field

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int ans = 0;
        
        vector<vector<int>> a(2, vector<int>(2));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> a[i][j];
                if (a[i][j] == 1) {
                    ans = 1;
                }
            }
        }

        if (ans != 0) {
            int cnt = 0;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    if (a[i][j] == 1) ++cnt;
                }
            }
            if (cnt == 4) ans = 2;
        }

        cout << ans << '\n';
    }

    return 0;
}
