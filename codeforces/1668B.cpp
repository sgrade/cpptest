// B. Social Distance

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        bool ans = true;

        if (n > m) ans = false;

        else {
            sort(begin(a), end(a));

            int prev = 0;
            ll sm = -a[0];
            for (int i = 0; i < n; ++i) {
                sm += a[i] - prev + 1 + a[i];
                prev = a[i];
            }

            if (sm > m) ans = false;
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
