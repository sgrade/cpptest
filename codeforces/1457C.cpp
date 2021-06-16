// C. Bouncing Ball

#include <iostream>
#include <string>
#include <limits>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, p, k;
        cin >> n >> p >> k;

        string a;
        getline(cin >> ws, a);

        int x, y;
        cin >> x >> y;

        // Key ideas are based on https://codeforces.com/contest/1457/submission/99928059

        int mn = numeric_limits<int>::max();

        // 1-based indexing - initial shift is 1
        int shift_from_end = 1;

        // deleting leading cells
        for (int i = 0; i < k; ++i) {
            int cnt = 0;
            // from right to left
            for (int j = n-shift_from_end; j > p-2; j -= k) {
                if (a[j] == '0') {
                    ++cnt;
                }
                mn = min(mn, cnt * x + abs(j+1-p) * y);
            }
            ++shift_from_end;
        }

        cout << mn << endl;
    }

    return 0;
}
