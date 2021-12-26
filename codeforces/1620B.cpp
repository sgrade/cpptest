// B. Triangles on a Rectangle

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int w, h;
        cin >> w >> h;

        vector<vector<int>> a(4);
        for (auto &v: a) {
            int k;
            cin >> k;
            int tmp;
            for (int i = 0; i < k; ++i) {
                cin >> tmp;
                v.push_back(tmp);
            }
            sort(begin(v), end(v));
        }

        // Solution is based on https://codeforces.com/contest/1620/submission/139762111
        long long ans = 0LL;
        for (int i = 0; i < 4; ++i) {
            ans = max(ans, 1LL * (a[i].back() - a[i][0]) * (i < 2 ? h : w));
        }
        
        cout << ans << endl;
    }


    return 0;
}
