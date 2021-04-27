// B. New Theatre Square

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<string> v(n);
        for (auto &el: v) {
            getline(cin >> ws, el);
        }

        int ans = 0;

        if (2 * x <= y) {
            for (int i = 0; i < n; ++i) {
                ans += count(v[i].begin(), v[i].end(), '.') * x;
            }
        }
        else {
            for (int i = 0; i < n; ++i){
                int j = 0;
                for (; j < m-1; ++j) {
                    if (v[i][j] == '.') {
                        if (v[i][j+1] == '.') {
                            ans += min(2 * x, y);
                        }
                        else {
                            ans += x;
                        }
                        ++j;
                    }
                }
                if (j == m-1 && v[i][j] == '.') {
                    ans += x;
                }
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
