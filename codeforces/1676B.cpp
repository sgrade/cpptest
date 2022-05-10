// B. Equal Candies

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

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        sort(a.begin(), a.end());

        int mn = *a.begin();

        long long ans = 0;

        for (int i = 1; i < n; ++i) {
            ans += a[i] - mn;
        }

        cout << ans << '\n';
    }

    return 0;
}
