// A. Wonderful Permutation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> p(n);
        for (int &el: p) cin >> el;

        vector<int> a(p.begin(), p.end());
        sort(a.begin(), a.end());

        int ans = 0;

        for (int i = 0; i < k; ++i) {
            if (find(p.begin(), p.begin() + k, a[i]) == p.begin() + k) {
                ++ans;
            }
        }

        cout << ans << '\n';
    }


}