// B. Pleasant Pairs
// ime limit exceeded on pretest 2

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

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        ull ans = 0ULL;
        int i, j;
        for (ull i_plus_j = 3; i_plus_j <= (n-1) + n; ++i_plus_j) {
            i = 1;
            j = i_plus_j - i;
            while (i < j) {
                if (a[i-1] * a[j-1] == i_plus_j) {
                    ++ans;
                }
                ++i;
                --j;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
