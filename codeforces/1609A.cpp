// A. Divide and Multiply

#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        ull ans = 0ULL;

        for (int i = 0; i < n; ++i) {
            
            ull x = a[i] * 1ULL;
            ull cur_ans = 0ULL;
            
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }
                int f = a[j];
                while (f % 2 == 0) {
                    x *= 2;
                    f /= 2;
                }
                cur_ans += f;
            }

            cur_ans += x;
            ans = max(cur_ans, ans);
        }

        cout << ans << endl;

    }

    return 0;
}
