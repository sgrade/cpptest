// C. Directional Increase

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) {
            cin >> el;
        }

        long long sum = accumulate(a.begin(), a.end(), 0LL);
        
        bool ans = sum == 0 ? true: false;

        // Editorial - https://codeforces.com/blog/entry/103952
        long long tmp = 0;
        int i = 0;
        for (; i < n; ++i) {
            tmp += a[i];
            if (tmp < 0) {
                ans = false;
                break;
            }
            if (tmp == 0) {
                ++i;
                break;
            }
        }
        for (; ans && i < n; ++i) {
            if (a[i] != 0) ans = false;
        }

        cout << (ans ? "Yes\n": "No\n");
    }

    return 0;
}
