// C. Paprika and Permutation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


inline int check (const int &have, const int &need) {
    if ((have - 1) / 2 >= need) return 1;
    return 0;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/97920
        // Little optimization is based on https://codeforces.com/contest/1617/submission/139503431

        vector<int> a;
        vector<bool> p(n+1);
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp < n + 1) {
                if (!p[tmp]) {
                    p[tmp] = true;
                    continue;
                }
            }
            a.push_back(tmp);
        }

        sort(begin(a), end(a));

        int ans = 0;

        int j = 1;
        for (int i = 0; i < a.size(); ++i) {
            
            while (p[j]) ++j;

            if (check(a[i], j)) {
                ++ans;
                ++j;
            }
            else {
                ans = -1;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
