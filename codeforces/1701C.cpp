// C. Schedule Management

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <limits>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<int> a(m);
        for (int &el: a) cin >> el;

        vector<int> p(n + 1);
        for (int i = 0; i < m; ++i) {
            ++p[a[i]];
        }
        sort(p.begin() + 1, p.end());

        int ans = *p.rbegin();

        int left = 1, right = n;
        int mid;
        int diff;
        while (left < right) {
            mid = p[left] + (p[right] - p[left])/2;
            int free = 0, busy = 0;
            int i = 1;
            for (; i < n + 1; ++i) {
                if (mid <= p[i]) {
                    break;
                }
                free += (mid - p[i] + 2 - 1) / 2;
            }
            for (; i < n + 1; ++i) {
                busy += p[i] - mid;
            }
            if (free < busy) {
                left = mid + 1;
                ans = min(ans, mid);
            }
            else if (free > busy) {
                right = mid - 1;
            }
            else {
                break;
            }
        }
       
        cout << ans << '\n';
    }

    return 0;
}
