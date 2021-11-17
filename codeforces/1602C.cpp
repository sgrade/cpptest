// C. Array Elimination

#include <iostream>
#include <vector>

using namespace std;


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

        vector<bool> ans(n+1, true);

        // Explanation - https://www.youtube.com/watch?v=TkfIa1sFTBU

        vector<int> bits_set_cnt(30);
        
        for (int i = 0; i < 30; ++i) {
            for (auto &el: a) {
                // Checking if i-th bit is set
                if (el & (1 << i)) {
                    ++bits_set_cnt[i];
                }
            }
        }

        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i < 30; ++i) {
                if (bits_set_cnt[i] % k != 0) {
                    ans[k] = false;
                    break;
                }
            }
        }

        for (int i = 1; i < n+1; ++i) {
            if (ans[i]) {
                cout << i << ' ';
            }
        }
        cout << endl;

    }

    return 0;
}
