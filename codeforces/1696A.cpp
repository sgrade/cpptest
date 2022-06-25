// A. NIT orz!

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

        int n, z;
        cin >> n >> z;
        vector<int> a(n);
        for (int &el: a) cin >> el;

        sort(a.begin(), a.end());

        int ans = a[n - 1];
        
        int x, y, tmpz;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                x = a[i] | z;
                tmpz = a[i] & z;
                y = a[j] | tmpz;
                ans = max({ans, x, y});
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
