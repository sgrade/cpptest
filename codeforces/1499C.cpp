// C. Minimum Grid Path

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;


using ull = unsigned long long;

int main(){

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int tmp;
        // Perfect solution, not much to change - https://codeforces.com/contest/1499/submission/110341491
        int nx = n;
        int ny = n;
        int min_x = numeric_limits<int>::max();
        int min_y = numeric_limits<int>::max();
        ull cost = 0ULL, ans = numeric_limits<ull>::max();

        for (int i = 1; i < n + 1; ++i) {
            cin >> tmp;
            if (i & 1) {
                min_x = min(min_x, tmp);
                --nx;
            }
            else {
                min_y = min(min_y, tmp);
                --ny;
            }
            cost += tmp;
            if (i > 1) {
                ans = min(ans, cost + 1ULL * nx * min_x + 1ULL * ny * min_y);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
