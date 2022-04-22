// C. Dolce Vita
// NOT FINISHED

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> a;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp > x) continue;
            a.push_back(tmp);
        }

        ll ans = 0;

        n = a.size();
        
        if (n > 0) {

            sort(a.begin(), a.end());

            ll sm = 0;
            int i = 0;

            for (; i < n; ++i) {
                if (sm + a[i] > x) break;
                sm += a[i];
            }

            if (i == n) --i;

            int cnt = i + 1;
            ll rounds = 1;

            while (true) {

                ans += cnt;
                sm += cnt;
                
                while (sm > x) {
                    sm -= a[i] + rounds;
                    --cnt;
                    --i;
                    if (i == 0) break;
                }
                
                if (i == 0) {
                    ans += x - (a[i] + rounds);
                    break;
                }

                if (i < 0) break;

                ++rounds;
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}
