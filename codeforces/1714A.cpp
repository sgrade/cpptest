// A. Everyone Loves to Sleep

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

        int n, H, M;
        cin >> n >> H >> M;

        int t0 = H * 60 + M;

        int h, m, cur_t, ans = 24 * 60 + 1, cur_ans;

        for (int i = 0; i < n; ++i) {
            cin >> h >> m;
            cur_t = h * 60 + m;
            
            if (cur_t >= t0) {
                cur_ans = cur_t - t0;
            }
            else {
                cur_ans = 24 * 60 - t0 + cur_t;
            }

            ans = min(ans, cur_ans);
        }
        
        cout << ans / 60 << ' ' << ans % 60 << '\n';
    }

    return 0;
}
