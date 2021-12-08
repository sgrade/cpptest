// B. Pleasant Pairs

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n+1);
        for (int i = 1; i < n+1; ++i) {
            cin >> a[i];
        }

        ull ans = 0ULL;
        int i, j;
        for (i = 1; i < n+1; ++i) {
            // Idea - https://codeforces.com/contest/1541/submission/120648155
            int aj = 1;
            while (true) {
                j = a[i] * aj - i;
                if (j > n) {
                    break;
                }
                if (j > i && a[j] == aj) {
                    ++ans;
                }
                ++aj;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
