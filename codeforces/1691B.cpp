// B. Shoe Shuffling

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

        int n;
        cin >> n;

        vector<int> s(n);
        for (int &el: s) cin >> el;

        int ans = 0;
        vector<int> output(n);

        int l = 0, r = 0;
        while (l < n && r < n) {
            while (s[l] == s[r] && r < n) ++r;
            if (r - l <= 1) {
                ans = -1;
                break;
            }
            output[l] = r;
            int i = l + 1;
            for (; i < r; ++i) output[i] = i;
            l = r;
            r = l;
        }

        if (ans == -1) cout << ans;
        else {
            for (int &el: output) cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}
