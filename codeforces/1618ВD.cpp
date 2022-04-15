// D. Array and Operations

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

        vector<int> a(n);
        for (int &el: a) cin >> el;
        sort(a.begin(), a.end(), greater<int>());

        int ans = 0;

        int i, j;
        while (k > 0) {
            i = 0;
            j = i + k;
            if (j >= n) {
                break;
            }
            ans += a[j] / a[i];
            
            a.erase(a.begin() + k);
            a.erase(a.begin());

            --k;
        }

        for (i = 0; i < a.size(); ++i) {
            ans += a[i];
        }

        cout << ans << '\n';
    }


    return 0;
}
